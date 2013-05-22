#include <p33fj16gs504.h>  
#include <libq.h>
#include <dsp.h>
#include "define.h"
#include "data_struct.h"
#include "uart.h"
#include "pwm.h"
#include "beep.h"

int State;
extern int Duty;
extern unsigned char tx;
int LEDCnt = 0;

unsigned long StartUpCnt = 0;
extern unsigned char InvMode;

long ByPassCnt = 0, ScrCnt = 0;
int sCntx = 0;
extern void TestDrv();
extern unsigned long bcnt;

void initStateMachineTimer(void)
{
    T2CONbits.TCKPS = 0; /* Prescaler of 1:1 */
    PR2 = 4000; /* (100us / 25ns) = 4000 */
    IPC1bits.T2IP = 4; /* Set up Timer interrupt priority */
    IEC0bits.T2IE = 1; /* Enable Timer2 interrupt */

    T2CONbits.TON = 1; /* Enable State machine timer */
    State = STATE_UNKNOWN;
}

void __attribute__((__interrupt__, no_auto_psv)) _T2Interrupt()
{
    if (LEDCnt > 3000)
    {
        LEDCnt = 0;
        LED = ~LED;
        _SWTRG5 = 1;
    }
    LEDCnt++;

    m.f += mf;
    inv.f += invf;

    TestDrv();

    UART_DRV();

    BeepDrv();

    switch (State)
    {
        case SYSTEM_STARTUP:
        {
            inv.synced = 0;
            if (StartCtrl)
            {
                if (m.state == OK)
                {
                    if (ACInV > 1000)
                    {
                        if (InvV < ACInV - 100 && Duty < Q15(DUTY_SCALE))
                        {
                            Duty++;
                            ByPassCnt = 0;
                        }
                        else
                        {
                            ByPassCnt++;
                            if (ByPassCnt > 30000)
                            {
                                ByPassCnt = 0;
                                State = INVERTER_MODE;
                            }
                        }
                    }
                }
                else
                {
                    if (InvV<2100 && Duty < Q15(DUTY_SCALE))
                    {
                        Duty++;
                    }
                    else
                    {
                        ByPassCnt = 0;
                        State = INVERTER_MODE;
                    }
                }
            }
        }
        break;
        case INVERTER_MODE:
        {
            if (!StartCtrl)
            {
                State = SYSTEM_STARTUP;
                BYPASS = 1;
                SCR = 0;
                Duty = 0;
                ol.f = OVERLOAD_NORMAL;
                SetBeep(OFF,0,0);
            }

            //120% 2·ÖÖÓ  150% 30Ãë
            switch(ol.f)
            {
	            case OVERLOAD_NORMAL:
	            {
		            if (LoadI>ol.s_curr)
		            {
			            ol.cycle++;
			            if (ol.cycle>5)
			            {
				            ol.f = OVERLOAD150;
				            ol.cnt = 150000;
				            SetBeep(ON,0,0);
				            SetRelay(OFF);
				            ol.cycle = 0;
			            }
		            }
		            else if (LoadI>ol.ol_curr)
		            {
			         	ol.cycle++;
			         	if (ol.cycle>5)
			         	{
				         	ol.f = OVERLOAD120;
				         	ol.cnt = 300000;
				         	SetBeep(LOOP,3000,3000);
				         	SetRelay(ON);
				         	ol.cycle = 0;
			         	}
		            }
		            else
		            {
			            ol.cycle = 0;
		            }
		            break;
	            }
	            case OVERLOAD150:
	            {
		            if (ol.cnt>0)
		            {
			            if (LoadI<RatedCurr)
			            {
				            ol.cycle++;
				            if(ol.cycle>5)
				            {
					            SetRelay(ON);
					            SetBeep(OFF,0,0);
					            ol.cnt = 0;
					        }
			            }
			            else if (LoadI>ol.ol_curr && LoadI<ol.s_curr)
			            {
				         	ol.cycle++;
				         	if (ol.cycle>5)
				         	{
					         	ol.f = OVERLOAD120;
					         	ol.cnt = 300000;
					         	SetBeep(LOOP,3000,3000);
					         	SetRelay(ON);
					         	ol.cycle = 0;
				         	}
			            }
			            else
			            {
				            ol.cycle = 0;
			            }
		            }
		            break;
	            }
	            case OVERLOAD120:
	            {
		            if (ol.cnt>1)
		            {
			            if (LoadI>ol.s_curr)
			            {
				            ol.cycle++;
				            if (ol.cycle>5)
				            {
					            ol.f = OVERLOAD150;
					            ol.cnt = 150000;
					            SetRelay(OFF);
					            SetBeep(ON,0,0);
					        } 
			            }
			            else
			            if (LoadI<ol.ol_curr)
			            {
				            ol.cycle++;
				            if (ol.cycle>5)
				            {
					         	ol.f = OVERLOAD_NORMAL;
					         	ol.cnt = 0;
					         	SetBeep(OFF,0,0);
					         	SetRelay(ON);
					         	ol.cycle = 0;
				            }
			            }
		            }
		            else if (ol.cnt==1)
		            {
			            if (LoadI>ol.ol_curr)
			            {
				            if (BYPASS)
				            {
			            		SetBeep(ON,0,0);
			            		SetRelay(OFF);
				            }
			            }
			            else if (!BYPASS)
			            {
		            		SetBeep(OFF,0,0);
		            		SetRelay(ON);
			            }
		            }
		            break;
	            }
            }
           
            if (ol.cnt) ol.cnt--;
			Power = ol.f;
			ChargeStatus = ol.cnt;

            //ByPass Drv Begin
            if (bp.inSwitch)
            {
                bp.inSwitch = 0;
                if (inv.synced)
                {
                    SCR = 1;
                    bp.cnt = 600;
                }
                else
                {
                    SCR = 0;
                    BYPASS = !bp.r;
                    bp.cnt = 0;
                }
            }

            if (bp.cnt)
            {
                bp.cnt--;
                if (bp.cnt == 580)
                {
                    BYPASS = !bp.r;
                }
                if (bp.cnt==1)
                {
                    SCR = 0;
                    bp.cnt = 0;
                }
            }
            //ByPass Drv End
            if (m.state == OK)
            {
                if (ACInV > 1000 && ACInV < 2350 && jabs(ACInV - InvV) > 50)
                {
                    sCntx++;
                    if (sCntx > 5)
                    {
                        if (InvV < ACInV)
                        {
                            if (Duty < Q15(DUTY_SCALE)) Duty++;
                        }
                        else if (InvV > ACInV)
                        {
                            if (Duty > Q15(0.1))Duty--;
                        }
                        sCntx = 0;
                    }
                }

            }
            else
            {
                 if (InvV < 2160)
                 {
                     if (Duty < Q15(DUTY_SCALE) && inv.c == 0) 
                     {
                     	Duty++;
                     	inv.c = 1000;
                     }
                 }
                 else if (InvV > 2240)
                 {
                     if (Duty > Q15(0.1) && inv.c == 0)
                     {
                     	Duty--;
                     	inv.c = 1000;
                     }
                 }
                 if (inv.c) inv.c --;
	        }
        }
        break;
        case SYSTEM_ERROR:
        {

        }
        break;
        case STATE_UNKNOWN:
        {
            Duty = 0;
            StartUpCnt++;
            if (StartUpCnt > 60000)
            {
                StartUpCnt = 0;
                if (m.state == OK || (m.state == NOK))
                {
                    SSTART = 0;
                    State = SYSTEM_STARTUP;
                }
            }

        }
        break;
    }

    TMR2 = 0;
    IFS0bits.T2IF = 0; /* Clear Interrupt Flag */
}

