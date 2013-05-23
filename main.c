#include <p33fj16gs504.h>
#include "dsp.h"
#include "pwm.h"
#include "uart.h"
#include "clock.h"
#include "define.h"
#include "StateMachine.h"
#include "i2c.h"
#include "beep.h"

/* Configuration bits */
_FOSCSEL(FNOSC_FRC)
_FOSC(FCKSM_CSECMD & OSCIOFNC_ON & IOL1WAY_OFF)
_FWDT(FWDTEN_OFF) //Watch Dog timer
_FPOR(FPWRT_PWR128)// & BOREN_OFF) //by jwz. p33fj16gs504 not found BOREN_OFF
_FICD(ICS_PGD1 & JTAGEN_OFF)

extern int fRMSCalculation;
unsigned int cnt = 0;
extern unsigned long StartUpCnt;
extern int Duty;
unsigned char tx = 0;

unsigned long tick = 0, stick = 0;
#define SOUNDDLY 3000
unsigned long bcnt = SOUNDDLY;
int ByPassCtrlBak;
char syncedbak = 0;
unsigned long SyncedCnt = 100000;

void TestDrv()
{
	//旁路自动切换(实验用)
	/*
	if (inv.synced)
	{
	    if (MANCTRL)
	    {
	        tick++;
	        if (tick > 60010)
	        {
	            tick = 0;
	            SetByPass(tx=!tx);
	        }
	    }
	    else		
	    if (ByPassCtrlBak!=ByPassCtrl) //手动旁路切换
	    {
	        SetByPass(0);
	        ByPassCtrlBak = ByPassCtrl;
	    }
	    else	
		if (wMode==0 && BYPASS)
		{
			if (jabs(InvV-ACInV)<100)
			{
				SetByPass(0);			
			}
		}	    
	}

    if ((inv.synced !=syncedbak))
    {
        if (inv.synced)
        {
            SyncedCnt--;
            if (SyncedCnt == 0)
            {
                syncedbak = inv.synced;
                if (!isOverLoad())
                {
                    OLNORMAL();
                }
            }
        }
    }
    else
    {
        SyncedCnt = 100000;
    }
    */    
}

int main()
{

    ByPassCnt = 0; 

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
    initPWM();
    StartPWM();
    StartADC();

    InitI2C();

    LED = 1;
    StartUpCnt = 1;
    BEEP = 0;
    Duty = 0;
    //i2cWrite(0,0xA5);
    i2cReadStr(0, (unsigned char*)&sValue, 48);
    if (Password==-2)
    {
        Adj_Init();
        i2cReadStr(22,(unsigned char*)&sValue[12],24);
    }
    
    ol.ol_curr = mulss(RatedCurr,19661)>>14;    //120%过载
    ol.s_curr = mulss(RatedCurr,32767)>>14;     //150%冲击电流

    StartCtrl = sMode;
    ByPassCtrlBak = !ByPassCtrl;

    while (1)
    {
        ModbusSlave();
        RMS_CALC();
    }
    return 0;
}

