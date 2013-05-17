/*****************************************************************  
 ** ��������: ����ͨѶ����DSP�ж��յ�8�����ݺ󣬽��յ���8������    **
 ** ���жϷ��ͷ�ʽ���ͻط��ͷ���                                   **
 *************************************************************** */
#include <p33fj16gs504.h>                //ds30f6014ͷ�ļ�   
#include "define.h"
#include "data_struct.h"
#include "i2c.h"

unsigned char rsBuf[68]; // ������������
//unsigned char SndBuf[32];            // ������������   
unsigned char RcvCnt = 0; // �������ݸ�������
unsigned char SndCnt = 0; // �������ݸ�������
unsigned char SndPosi = 0; // �������ݸ�������
unsigned char Rcved; // ��1�����յ�8������
unsigned int CET = 0;
void Sender();

void jmemcpy(unsigned char* s, unsigned char * d, unsigned int ls)
{
    while (ls--) *d++ = *s++;
}

/*****************************************************************  
 ** ������: Uart_Initial()                                       **
 ** ��������: 232����ͨѶ��ʼ���ӳ��������ж����ȼ�            **
 *************************************************************** */
void initUart()
{

    //IPC2bits.U1RXIP=1;          //���ж����ȼ���1��
    //IPC3bits.U1TXIP=1;

    U1MODEbits.UARTEN = 1;
    //U1MODEbits.UEN = 3;
    //U1MODE=0x8000;              //UARTʹ�ܣ�8λ���ݣ�����żУ��
    U1MODEbits.PDSEL = 2; //8λ����λ����У��
    U1MODEbits.STSEL = 0; //8λ����λ����У��

    U1STA = 0x0000; //��һ���ַ������䵽������λ�Ĵ��������ͻ�������
    //���ٻ���һ���ַ��������жϣ������յ�һ���ַ�ʱ��
    //�жϱ�־λ��λ
    //U1STAbits.UTXINV = 1;		//���ͼ��ԣ�UxTX����Ϊ1
    U1BRG = 0x102; //U1BRG=Fcy/(16*������)-1���˴�������Ϊ9600
    IEC0bits.U1RXIE = 1; //UART1���պͷ����ж�ʹ��
    IEC0bits.U1TXIE = 1;

    U1STAbits.URXISEL = 0; // Interrupt after one RX character is received;
    U1STAbits.UTXISEL1 = 0;
    U1STAbits.UTXISEL0 = 1;

    RPOR8bits.RP16R = 3; //RP16=TXD
    RPINR18bits.U1RXR = 29; //RP29=RXD

    RcvCnt = 0;
    SndCnt = 0;
}

/*
uart drivers
*/
void UART_DRV(void)
{
    if (CET > 500)
    {
        Rcved = 1;
        CET = 0;
    }
    else if (CET > 0)
    {
        CET++;
    }
}

/* ****************************************************************  
 ** �� �� ��: __attribute__((__interrupt__)) _U1RXInterrupt()
 ** ��������: �ж��ӳ���232�����ж�
 *************************************************************** */
void __attribute__((interrupt, no_auto_psv)) _U1RXInterrupt()
{
    IFS0bits.U1RXIF = 0;
    unsigned int ch;
    CET = 1;
    while (U1STAbits.URXDA)
    {
        ch = U1RXREG;
        if (RcvCnt > 0 && RcvCnt < 64)
        {
            rsBuf[RcvCnt++] = ch;
        }
        else if (ch == ModbusSA || ch == 2)
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
 ** �� �� ��: __attribute__((__interrupt__)) _U1TXInterrupt()
 ** ��������: �ж��ӳ���232�����ж�
 *************************************************************** */
void __attribute__((interrupt, no_auto_psv)) _U1TXInterrupt()
{
    IFS0bits.U1TXIF = 0;
    if (SndPosi >= SndCnt || SndPosi >= 64) //����������ݸ�������7
    {
        SndCnt = 0; //�������ݸ�������
        U1STAbits.UTXEN = 0; //�Ѿ����͵����һ���������Ͳ�ʹ��
        LED = ~LED;
    }
    else
    {
        //SndPosi++;                   // ���򣬷��ͼ�������1 */
        U1TXREG = rsBuf[SndPosi++];
    }
}

void Sender()
{
    if (SndCnt)
    {
        U1STAbits.UTXEN = 1; // ʹ�ܷ���
        SndPosi = 0;
        U1TXREG = rsBuf[SndPosi++]; //�ȷ��͵�һ������
    }
}

const unsigned int CRC16Table[] =
{
    0x0000, 0xCC01, 0xD801, 0x1400, 0xF001, 0x3C00, 0x2800, 0xE401,
    0xA001, 0x6C00, 0x7800, 0xB401, 0x5000, 0x9C01, 0x8801, 0x4400
};

unsigned int crc16(unsigned char* buf, unsigned char len)
{
    unsigned int CRC = 0xFFFF;
    unsigned char i;
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
    return (i << 8) | (i >> 8);
}

unsigned int MakeInt(unsigned char h, unsigned char l)
{
    unsigned int ti = h;
    return (ti << 8 | l);
}

/*
modbus slave function 1
*/
unsigned char MSFunc1(int addr, int len)
{
    if (addr < 8 && addr + len <= 8)
    {
        rsBuf[2] = 1;
        rsBuf[3] = (((*(unsigned char*) &ControlBits) << addr) & (unsigned char) (0xFF << (8 - len)));
        return 4;
    }
    return 0;
}

/*
modbus slave function 5
*/
unsigned char MSFunc5(int addr, int len)
{
    if (addr < 8)
    {
        if (len)
        {
            *(unsigned char*) &ControlBits |= (1 << (addr));
        }
        else
        {
            *(unsigned char*) &ControlBits &= ~(1 << (addr));
        }
        return 6;
    }
    return 0;
}

/*
modbus slave function 3
*/
unsigned char MSFunc3(int addr, int len)
{
    unsigned char i;

    rsBuf[2] = len * 2;

    if (addr < 14 && addr + len <= 14)
    {
        for (i = 0; i < rsBuf[2]; i += 2)
        {
            rsBuf[i + 3] = Value[i / 2 + addr].h;
            rsBuf[i + 4] = Value[i / 2 + addr].l;
        }
        return rsBuf[2] + 3;
    }
    else if (addr >= 0x4000 && addr + len <= 0x4022)
    {
        addr -= 0x4000;
        addr %= 0x23;
        if (!i2cReadStr(addr * 2, (unsigned char*) sValue, 44)) return 0;
        for (i = 0; i < rsBuf[2]; i += 2)
        {
            rsBuf[i + 3] = sValue[i / 2 + addr].h;
            rsBuf[i + 4] = sValue[i / 2 + addr].l;
        }
        return rsBuf[2] + 3;
    }
    return 0;
}

/*
modbus slave function 6
*/
unsigned char MSFunc6(int addr, int value)
{
    unsigned long t; unsigned int ti;
    if (addr >= 0x4000 && addr <= 0x4010)
    {
        addr -= 0x4000;
        sValue[addr].x = value;
        if (i2cWriteStr(addr * 2, (unsigned char*) &sValue[addr], 2))
            return 6;
    }
    else if (addr>= 0  && addr<= 12)
    {
        t = value;

        ti = divud((t<<15),Value[addr].x);
        sValue[11+addr].x = muluu(ti,sValue[11+addr].x)>>15;

        i2cWriteStr((11+addr)*2,(unsigned char*)&sValue[11+addr], 2);
        return 6;
    }
    return 0;
}

/*
modbus slave function 0x10
*/
unsigned char MSFunc16(int addr, int len)
{
    unsigned char i;
    if (addr >= 0x4000 && addr + len < 0x4010)
    {
        addr -= 0x4000;
        for (i = 0; i < rsBuf[6]; i += 2)
        {
            sValue[addr + i / 2].h = rsBuf[i + 7];
            sValue[addr + i / 2].l = rsBuf[i + 8];
        }
        if (i2cWriteStr(addr * 2, (unsigned char*) &sValue[0], 16))
            return 6;
    }
    return 0;
}

/*
modbus slave main function
*/
void ModbusSlave()
{
    INT crc;
    if (1 == Rcved)
    {
        Rcved = 0;

        if (crc16(rsBuf, RcvCnt) == 0)
        {
            INT Addr, Len;
            Addr.h = rsBuf[2];
            Addr.l = rsBuf[3];
            Len.h = rsBuf[4];
            Len.l = rsBuf[5];
            switch (rsBuf[1])
            {
                case 1:case 2:
                    SndCnt = MSFunc1(Addr.x, Len.x);
                    break;
                case 3:case 4:
                    SndCnt = MSFunc3(Addr.x, Len.x);
                    break;
                case 5:
                    SndCnt = MSFunc5(Addr.x, Len.x);
                    break;
                case 6:
                    SndCnt = MSFunc6(Addr.x, Len.x);
                    break;
                case 15: break;
                case 16:
                    SndCnt = MSFunc16(Addr.x, Len.x);
                    break;
            }
        }

        if (SndCnt)
        {
            crc.x = crc16(rsBuf, SndCnt);
            rsBuf[SndCnt++] = crc.l;
            rsBuf[SndCnt++] = crc.h;
        }

        RcvCnt = 0;
        Sender();
    }
}
