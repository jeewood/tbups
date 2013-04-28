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
unsigned long DisCnt = 0;
extern unsigned long StartUpCnt;
extern int Duty;
unsigned char tx = 0;
//this is 主程序

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

	BYPASS = 1;
	SSTART = 1;
	SCR = 1;

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

	Duty = 0;	
	//i2cWrite(0,0xA5);
	while(1)
	{
		//tx = i2cRead(0);
         ModbusSlave();
         RMS_CALC();
	}
	return 0;
}

