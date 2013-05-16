#include <p33fj16gs504.h>  
#include <libq.h>
#include <dsp.h>
#include "define.h"
#include "data_struct.h"
#include "uart.h"
#include "pwm.h"

int State;
extern int Duty;
extern unsigned char tx;
int LEDCnt = 0;

unsigned long StartUpCnt = 0;
extern unsigned char InvMode;

long ByPassCnt = 0, ScrCnt = 0;
int sCntx = 0;
extern void TestDrv();

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
    }
    LEDCnt++;

    m.f += mf;
    inv.f += invf;

    TestDrv();

    UART_DRV();

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
                        if (InvV < ACInV - 100)
                        {
                            if (Duty < Q15(DUTY_SCALE)) Duty++;
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
                    LED = ~LED;
                }
                else
                {
                    if (Duty < Q15(DUTY_SCALE))
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
                SCR = 1;
                Duty = 0;
            }
            
            if (m.state == OK)
            {
                //#ifndef TEST
                if (ACInV > 1000 && jabs(ACInV - InvV) > 50)
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
                    }
                }
                //#endif
                if (inv.synced)
                {
                    if (bypassInSwitch)
                    {
                        SCR = 1;
                        ScrCnt = 600;
                        bypassInSwitch = 0;
                    }
                    else if (ScrCnt == 580)
                    {
                        BYPASS = !tx;
                    }

                    if ((ScrCnt--) == 1)
                    {
                        SCR = 0;
                        ScrCnt = 0;
                    }
                }
            }
        }
        break;
        case BATTERY_CHARGER_MODE:
        {
            if (m.state == OK)
            {

            }
            else if (m.state == NOK)
            {

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

