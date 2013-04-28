/*****************************************************************  
** 功能描述: 串行通讯程序，DSP中断收到8个数据后，将收到的8个数据    **
** 以中断发送方式返送回发送方。                                   **
*************************************************************** */   
#include <p33fj16gs504.h>                //ds30f6014头文件   
#include "define.h"
#include "data_struct.h"
#include "i2c.h"

unsigned char rsBuf[68];         // 接收数据数组   
//unsigned char SndBuf[32];            // 发送数据数组   
unsigned char RcvCnt=0;    // 接收数据个数计数   
unsigned char SndCnt=0;       // 发送数据个数计数   
unsigned char SndPosi=0;       // 发送数据个数计数   
unsigned char Rcved;        // ＝1，接收到8个数据   
unsigned int CET = 0;
void Sender();

/*****************************************************************  
** 函数名: Uart_Initial()                                       **
** 功能描述: 232串行通讯初始化子程序，设置中断优先级            **
*************************************************************** */   
void initUart()
{   
	//IPC2bits.U1RXIP=1;          //收中断优先级：1级     
	//IPC3bits.U1TXIP=1;
	
	U1MODEbits.UARTEN = 1;
	//U1MODEbits.UEN = 3;
	//U1MODE=0x8000;              //UART使能，8位数据，无奇偶校验        
	U1MODEbits.PDSEL = 2;			//8位数据位，奇校验
	U1MODEbits.STSEL = 0;			//8位数据位，奇校验
	
	U1STA=0x0000;               //当一个字符被传输到发送移位寄存器（发送缓冲器中   
							//至少还有一个字符）产生中断，当接收到一个字符时，
							//中断标志位置位   
	//U1STAbits.UTXINV = 1;		//发送极性，UxTX空闲为1
	U1BRG=0x102;                 //U1BRG=Fcy/(16*波特率)-1，此处波特率为9600   
	IEC0bits.U1RXIE=1;          //UART1接收和发送中断使能   
	IEC0bits.U1TXIE=1; 
	
	U1STAbits.URXISEL = 0;		// Interrupt after one RX character is received;
	U1STAbits.UTXISEL1 = 0;
	U1STAbits.UTXISEL0 = 1;
	
	RPOR8bits.RP16R = 3;		//RP16=TXD
	RPINR18bits.U1RXR = 29;		//RP29=RXD

	RcvCnt = 0;
	SndCnt = 0;
}   

void UART_DRV(void)
{
	if (CET>500)
	{
		Rcved = 1;
		CET = 0;
	}
	else if (CET>0)
	{
		CET++;
	}
}
	
/* ****************************************************************  
** 函 数 名: __attribute__((__interrupt__)) _U1RXInterrupt()  
** 功能描述: 中断子程序：232接收中断  
*************************************************************** */   
void __attribute__((interrupt, no_auto_psv)) _U1RXInterrupt()  
{   
	IFS0bits.U1RXIF=0;
	unsigned int ch;
	CET = 1;
	while(U1STAbits.URXDA)
	{
		ch = U1RXREG;
		if (RcvCnt>0 && RcvCnt<64)
		{
			rsBuf[RcvCnt++]=ch;
		}
		else if (ch == 0x02)
		{
			rsBuf[RcvCnt++] = ch;
		}
		else
		{
			RcvCnt = 0;
		}
	}
}   
/* ****************************************************************  
** 函 数 名: __attribute__((__interrupt__)) _U1TXInterrupt()  
** 功能描述: 中断子程序：232发送中断  
*************************************************************** */   
void __attribute__((interrupt, no_auto_psv)) _U1TXInterrupt()
{      
    IFS0bits.U1TXIF=0;     
    if(SndPosi>=SndCnt || SndPosi>=64)  //如果发送数据个数大于7   
    {   
		SndCnt=0;                   //发送数据个数清零   
		U1STAbits.UTXEN=0;			//已经发送到最后一个数，发送不使能         
		LED = ~LED;
    }          
    else   
    {   
		//SndPosi++;                   // 否则，发送计数器加1 */    
		U1TXREG=rsBuf[SndPosi++];   
    }   
}

void Sender()
{
	U1STAbits.UTXEN=1;				// 使能发送   
	SndPosi = 0;
	U1TXREG=rsBuf[SndPosi++];				//先发送第一个数据   
}

const unsigned int CRC16Table[] =
{
	0x0000, 0xCC01, 0xD801, 0x1400, 0xF001, 0x3C00, 0x2800, 0xE401, 
	0xA001, 0x6C00, 0x7800, 0xB401, 0x5000, 0x9C01, 0x8801, 0x4400
};

unsigned int crc16(unsigned char* buf, unsigned char len)
{
	unsigned int CRC = 0xFFFF;
	unsigned char  i;
	unsigned char ch;
	
	for (i = 0; i < len; i++)
	{
        ch = *buf++;
        CRC = CRC16Table[(ch ^ CRC) & 15] ^ (CRC >> 4);
        CRC = CRC16Table[((ch >> 4) ^ CRC) & 15] ^ (CRC >> 4);
	}
	
	return CRC;
}

unsigned int swap(unsigned int i)
{
	return (i<<8) | (i>>8);
}
	
unsigned char MSFunc3(int addr,int len)
{
	unsigned char i,f=0;
	unsigned int crc;
	
	rsBuf[2] = len*2;
	
	if (addr<12 && addr + len<=12)	
	{
		for(i=0;i<rsBuf[2];i+=2)
		{
			rsBuf[i+3] = (unsigned char)*(((char*)&Value) + addr*2 + i + 1);
			rsBuf[i+4] = (unsigned char)*(((char*)&Value) + addr*2 + i);
		}
		f = 1;
	}
	else if (addr>=0x4000 && addr+len<= 0x4010)
	{
		addr -= 0x4000;
		i2cReadStr(addr*2,&rsBuf[3],rsBuf[2]);
		f = 1;
	}
	
	if (f)
	{
		crc = crc16(rsBuf,rsBuf[2]+3);
		rsBuf[rsBuf[2]+3]=crc;
		rsBuf[rsBuf[2]+4]=crc>>8;		
		return rsBuf[2]+5;
	}
	return 0;
}

unsigned char MSFunc6(int addr,int value)
{
	unsigned int v = swap(value);
	if (addr>=0x4000 && addr<=0x4010)
	{
		addr -= 0x4000;
		i2cWriteStr(addr*2,(unsigned char*)&v,2);
	}
	return RcvCnt;
}	

unsigned char MSFunc16(int addr,int len,unsigned char *buf)
{
	unsigned int crc;
	if (addr>=0x4000 && addr+len<0x4010)
	{
		addr -= 0x4000;
		i2cWriteStr(addr*2,buf,len*2);
		crc = crc16(rsBuf,6);
		rsBuf[6]=crc;
		rsBuf[7]=crc>>8;
		return 8;
	}
	return 0;
}	
void ModbusSlave()
{
	if (1==Rcved)
	{
		Rcved = 0;

		if (crc16(rsBuf,RcvCnt)==0)
		{
			unsigned int Addr,Len;
			Addr = rsBuf[2]<<8;
			Addr |= rsBuf[3];
			Len = rsBuf[4]<<8;
			Len |= rsBuf[5];
			switch(rsBuf[1])
			{
				case 1:case 2: break;
				case 3:case 4: 
					SndCnt = MSFunc3(Addr,Len);
				break;
				case 5:case 6: 
					SndCnt = MSFunc6(Addr,Len);
				break;
				case 15: break;
				case 16: 
					SndCnt = MSFunc16(Addr,Len,&rsBuf[7]);
				break;
			}
		}
		//SndCnt = RcvCnt;
		RcvCnt = 0;
		Sender();
	}
}
		
//===================================================================
/********************************************************************
UART Implementation for dsPIC33FJ16GS504........ 

Dear all.... I am trying to executing the UART module of dspic33fj16gs504. But its not working... The code is as bellow...Please revert back.
 Thanks in advance.
 ================================================== ==============================
 
Code:#include "p33FJ16GS504.h"

// Configuration Bit Settings
_FOSCSEL(FNOSC_FRCPLL)
_FOSC(OSCIOFNC_OFF & POSCMD_NONE)

#define CLOCK_FREQ 40000000 // Assuming 5.00MHz and X8 PLL
#define BAUD 19200

void U1_Putch(unsigned char Data)
{
	while (U1STAbits.UTXBF);
	while(1)
	U1TXREG = Data;
}

void setup_uart(void)
{
 	U1MODE = 0x0000;
 	U1STA = 0x0000;

 	U1BRG = ((CLOCK_FREQ/16)/BAUD) - 1;	// set baudrate to BAUD rate

 	IEC0bits.U1RXIE = 1;

 	U1MODEbits.UARTEN=1;		// UART1 is enabled
 	U1STAbits.UTXEN = 1;           // Initiate transmission
} 

void main()
{
	TRISBbits.TRISB1=1;				// Used for Rx as input
	TRISBbits.TRISB2=0;				// Used for Tx as output

	// Remmappable INPUT PIN configuration for UART1
	RPINR18bits.U1RXR=1;			// PORT PIN NO. 32, This pin is for Rx	
	// Remmappable OUTPUT PIN configuration for UART1
	RPOR1bits.RP2R=0x000011;		// PORT PIN NO. 33, This pin is for Tx
	
	setup_uart();
	U1_Putch('A');	
	while(1);
}

void __attribute__((__interrupt__)) _U1TXInterrupt(void)
{
	IFS0bits.U1TXIF = 0;	// clear interrupt flag
}

void __attribute__((__interrupt__)) _U1RXInterrupt(void)
{
	IFS0bits.U1RXIF = 0;	// clear interrupt flag
}================================================== ==============================
 Last edited by bigdogguru; 14-03-12 at 17:12. 
Re: UART Implementation for dsPIC33FJ16GS504........

Here is the correct code:
 Code:#include "p33FJ16GS504.h"

// Configuration Bit Settings
_FOSCSEL(FNOSC_FRCPLL)
_FOSC(OSCIOFNC_OFF & POSCMD_NONE)

#define FCY 20000000
//40MHz clock is set up as FRC = 7.37MHz, M=44, N1=2, N2=4
//Thus FCY = 40/2 = 20MHz
#define BAUD 19200

void U1_Putch(unsigned char Data)
{
while (U1STAbits.UTXBF);
U1TXREG = Data;
}

void setup_uart(void)
{
AD1PCFGL = 0x1FFF; //Disable ADC

U1MODE = 0x0000;
U1STA = 0x0000;

U1BRG = ((FCY/16)/BAUD) - 1; // set baudrate to BAUD rate

IEC0bits.U1RXIE = 1;

U1MODEbits.UARTEN=1; // UART1 is enabled
U1STAbits.UTXEN = 1; // Initiate transmission
}

void setup_clock(void){
	CLKDIVbits.PLLPOST = 1; //N2 = 4;
	CLKDIVbits.PLLPRE = 0; //N1 = 2;
	PLLFBD = 42; //M = 44
//Value of Fin is 7.37MHz
//M=44, N1=2 and N2=4 gives ~40MHz

while(OSCCONbits.LOCK!=1) {};  // Wait for PLL to lock
}

void main()
{
unsigned int i;
setup_clock();

//Not needed:
//TRISBbits.TRISB1=1; // Used for Rx as input
//TRISBbits.TRISB2=0; // Used for Tx as output

// Remmappable INPUT PIN configuration for UART1
RPINR18bits.U1RXR=1; // RB1 This pin is for Rx
// Remmappable OUTPUT PIN configuration for UART1
RPOR1bits.RP2R=3; // RB2 This pin is for Tx

setup_uart();

for (i=0;i<40000;i++); //Wait for some time

U1_Putch('A');

while(1);

}

void __attribute__((__interrupt__)) _U1TXInterrupt(void)
{
IFS0bits.U1TXIF = 0; // clear interrupt flag
}

void __attribute__((__interrupt__)) _U1RXInterrupt(void)
{
IFS0bits.U1RXIF = 0; // clear interrupt flag
}There are errors in your code.
 
Code:_FOSCSEL(FNOSC_FRCPLL)
_FOSC(OSCIOFNC_OFF & POSCMD_NONE)
#define CLOCK_FREQ 40000000 // Assuming 5.00MHz and X8 PLL
#define BAUD 19200

U1BRG = ((CLOCK_FREQ/16)/BAUD) - 1; // set baudrate to BAUD rate You can't assume 5.00MHz clock. The default frequency of the internal oscillator is 7.37MHz. So, you have to configure it for 40MHz, keeping in mind the 7.37MHz. I've done that through the setup_clock() sub-routine/procedure.
 FCY = FOSC/2. So, if you have 40MHz clock, FCY = 20MHz. You have to use this value when calculating the value for the required baud rate.
 Code:void setup_clock(void){
	CLKDIVbits.PLLPOST = 1; //N2 = 4;
	CLKDIVbits.PLLPRE = 0; //N1 = 2;
	PLLFBD = 42; //M = 44
//Value of Fin is 7.37MHz
//M=44, N1=2 and N2=4 gives ~40MHz

while(OSCCONbits.LOCK!=1) {};  // Wait for PLL to lock
} Code:RPOR1bits.RP2R=0x000011; // PORT PIN NO. 33, This pin is for Tx This means that RP2R is assigned a value of 17, but you need to assign 3:
 Code: RPOR1bits.RP2R=3; // RB2 This pin is for Tx Code:TRISBbits.TRISB1=1; // Used for Rx as input
TRISBbits.TRISB2=0; // Used for Tx as outputThe above 2 lines aren't required, as, when you use the UART module, the TRIS settings are overriden.
 
You need to disable the ADC multiplexed pins from their analogue circuitry to use them as digital pins. I've done this by completely setting all ADC multiplexed pins as digital:
 Code:AD1PCFGL = 0x1FFF; //Disable ADCI think you can understand the rest.
 
Hope this helps.
 Tahmid.
 
***********************************************************************************/

/*
#include "p33FJ16GS504.h"

// Configuration Bit Settings
_FOSCSEL(FNOSC_FRCPLL)
_FOSC(OSCIOFNC_OFF & POSCMD_NONE)

#define FCY 20000000
//40MHz clock is set up as FRC = 7.37MHz, M=44, N1=2, N2=4
//Thus FCY = 40/2 = 20MHz
#define BAUD 19200

void U1_Putch(unsigned char Data)
{
while (U1STAbits.UTXBF);
U1TXREG = Data;
}

void setup_uart(void)
{
AD1PCFGL = 0x1FFF; //Disable ADC

U1MODE = 0x0000;
U1STA = 0x0000;

U1BRG = ((FCY/16)/BAUD) - 1; // set baudrate to BAUD rate

IEC0bits.U1RXIE = 1;

U1MODEbits.UARTEN=1; // UART1 is enabled
U1STAbits.UTXEN = 1; // Initiate transmission
}

void setup_clock(void){
	CLKDIVbits.PLLPOST = 1; //N2 = 4;
	CLKDIVbits.PLLPRE = 0; //N1 = 2;
	PLLFBD = 42; //M = 44
//Value of Fin is 7.37MHz
//M=44, N1=2 and N2=4 gives ~40MHz

while(OSCCONbits.LOCK!=1) {};  // Wait for PLL to lock
}

void main()
{
unsigned int i;
setup_clock();

//Not needed:
//TRISBbits.TRISB1=1; // Used for Rx as input
//TRISBbits.TRISB2=0; // Used for Tx as output

// Remmappable INPUT PIN configuration for UART1
RPINR18bits.U1RXR=1; // RB1 This pin is for Rx
// Remmappable OUTPUT PIN configuration for UART1
RPOR1bits.RP2R=3; // RB2 This pin is for Tx

setup_uart();

for (i=0;i<40000;i++); //Wait for some time

U1_Putch('A');

while(1);

}

void __attribute__((__interrupt__)) _U1TXInterrupt(void)
{
IFS0bits.U1TXIF = 0; // clear interrupt flag
}

void __attribute__((__interrupt__)) _U1RXInterrupt(void)
{
IFS0bits.U1RXIF = 0; // clear interrupt flag
}
*/

