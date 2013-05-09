#include <p33fj16gs504.h>
#include "dsp.h"
#include "pwm.h"
#include "uart.h"
#include "clock.h"
#include "define.h"
#include "StateMachine.h"
#include "i2c.h"

/* Configuration bits */
_FOSCSEL(FNOSC_FRC)
_FOSC(FCKSM_CSECMD & OSCIOFNC_ON & IOL1WAY_OFF)
_FWDT(FWDTEN_OFF)	//Watch Dog timer 
_FPOR(FPWRT_PWR128)// & BOREN_OFF) //by jwz. p33fj16gs504 not found BOREN_OFF
_FICD(ICS_PGD1 & JTAGEN_OFF)

extern int fRMSCalculation;
unsigned int cnt = 0;
extern unsigned long StartUpCnt;
extern int Duty;
unsigned char tx = 0;
//this is 主程序
unsigned long tick = 0,stick = 0;
#define SOUNDDLY 5000
unsigned long bcnt = SOUNDDLY;
void TestDrv()
{

	if (MANCTRL && inv.synced)
	{
		tick ++;
		if (tick>60010)
		{
			tick = 0;
			tx = !tx;
			bypassInSwitch = 1;
		}
	}

	if (inv.synced)
	{
		if (bcnt>0)
		{
			if (bcnt==SOUNDDLY) BEEP = 1;
			bcnt --;
		}
		else
		{
			BEEP = 0;
			bcnt = 0;
		}
	}
	else
	{
		bcnt = SOUNDDLY;
	}
}

int main()
{
	ByPassCnt = 0;	//旁路切换继电器计数器
	
	TRISCbits.TRISC2 = 0; 
	TRISCbits.TRISC7 = 0; 
	
	#ifdef NEWBOARD
	TRISBbits.TRISB3 = 0; 
	TRISBbits.TRISB4 = 0; 
	#else
	TRISCbits.TRISC0 = 0; 
	TRISCbits.TRISC13 = 0; 
	#endif
	TRISCbits.TRISC5 = 0; 
	TRISCbits.TRISC6 = 1; 

	BYPASS = 1;
	SSTART = 1;
	SCR = 0;

	initClock();
	initStateMachineTimer();
	#ifdef NEWBOARD
	initUart();
	#endif
	initADC();
	//InitADC_Common();
	StartADC();
	initPWM();
	StartPWM();
	InitI2C();

	LED = 1;
	StartUpCnt = 1;
	BEEP = 0;
	Duty = 0;	
	//i2cWrite(0,0xA5);
	while(1)
	{
		cnt++;
		if (cnt>10000)
		{
			//tx = sValue.ModbusSA;
			//i2cReadStr(0,(unsigned char*)&sValue,8);
			//if ((sValue.ModbusSA <= 1) && (tx != sValue.ModbusSA)) 
			{
				//bypassInSwitch = 1;
			}
			cnt = 0;
		}
/*		if (tx != MANCTRL)
		{
			tx = MANCTRL;
			bypassInSwitch = 1;
		}
*/		//tx = i2cRead(0);
         ModbusSlave();
         RMS_CALC();
	}
	return 0;
}

