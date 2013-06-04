#include <p33fj16gs504.h>  
#include <libq.h>
#include <dsp.h>
#include "define.h"
#include "data_struct.h"
#include "uart.h"
#include "pwm.h"
#include "beep.h"

int State;
int LEDCnt = 0;
long ByPassCnt = 0;
//市电没电的情况下切过去后,不再切回来
long InrushDly = 0;     //用于冲击电流切旁路后切回逆变时的延时
#define OverLoad() \
{\
    switch(ol.f)\
    {\
        case LOAD_NORMAL:\
            if (isImpulse())\
            {\
                INRUSH();\
                InrushDly = 0;\
                SetRelay(MAINPOWER);\
            }\
            else\
            if (isOverLoad())\
            {\
                OVERLOAD();\
            }\
            else\
            {\
                NORMAL();\
                SYNCED(SetRelay(!wMode));\
            }\
            break;\
        case LOAD_OVERLOAD:\
            if (ol.cnt>1)\
            {\
                if (isImpulse())\
                {\
                    INRUSH();\
                    InrushDly = 0;\
                    SetRelay(MAINPOWER);\
                }\
                if (isOverLoadBack())\
                {\
                    NORMAL();\
                    SYNCED(SetRelay(!wMode));\
                }\
            }\
            if (ol.cnt == 1)\
            {\
                if (isOverLoad())\
                {\
                    SetBeep(ON,0,0);\
                    SetRelay(MAINPOWER);\
                    ol.cnt--;\
                }\
            }\
            break;\
        case LOAD_INRUSH:\
            if (ol.cnt>1)\
            {\
                if (isImpulseBack())\
                {\
                    InrushDly++;\
                    if (InrushDly>20000)\
                    {\
                        NORMAL();\
                        SYNCED(SetRelay(!wMode));\
                        InrushDly = 0;\
                    }\
                }\
                if (isOverLoad() && !isImpulse())\
                {\
                    OVERLOAD();\
                }\
            }\
            if (ol.cnt==1) ol.cnt--;\
        break;\
    }\
}

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

    UART_DRV();

    BeepDrv();

    //故障判定
    if (m.state == NOK)
    {
        //市电故障
    }

    if (isOverLoad())
    {
        //UPS过载
    }

    if (BatV<1500)
    {
        //蓄电池低压
    }

    if (BatV>2300)
    {
        //蓄电池过压
    }

    //过热
    //充电机故障,蓄电池电压低于多少伏,且没有充电电流

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
                        if (InvV < ACInV - 100 && inv.duty < Q15(DUTY_SCALE))
                        {
                            inv.duty++;
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
                    if (InvV<2100 && inv.duty < Q15(DUTY_SCALE))
                    {
                        inv.duty++;
                    }
                    else
                    {
                        ByPassCnt = 0;
                        State = INVERTER_MODE;
                    }
                }
            }
            else
            {
                NORMAL();
            }
        }
        break;
        case INVERTER_MODE:
        {
            if (!StartCtrl)
            {
                NORMAL();
                SetRelay(MAINPOWER);
                inv.duty = 0;
                inv.bsynced = 0;
                inv.synced = 0;
                State = SYSTEM_STARTUP;
            }

            //120% 2分钟  150% 30秒
            OverLoad();

            if (ol.cnt>1) ol.cnt--;
            Power = ol.f;
            //ChargeStatus = wMode;

            //ByPass Drv Begin
            if (bp.inSwitch==1)
            {
                bp.inSwitch = 2;
                if (inv.synced && jabs(ACInV-InvV)<100) 
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
                }
            }
            else if (bp.inSwitch==2)
            {
                bp.inSwitch = 0;
            }
            //ByPass Drv End
            if (m.state == OK)
            {
                if (ACInV > 1650 && ACInV < 2420 && jabs(ACInV - InvV) > 100)
                {
                    m.cycle++;
                    if (m.cycle > 5)
                    {
                        if (InvV < ACInV)
                        {
                            if (inv.duty < Q15(DUTY_SCALE)) inv.duty++;
                        }
                        else if (InvV > ACInV)
                        {
                            if (inv.duty > Q15(0.1))inv.duty--;
                        }
                        m.cycle = 0;
                    }
                }

            }
            else
            {
                 if (InvV < 2160)
                 {
                     if (inv.duty < Q15(DUTY_SCALE) && inv.c == 0) 
                     {
                        inv.duty++;
                        inv.c = 1000;
                     }
                 }
                 else if (InvV > 2240)
                 {
                     if (inv.duty > Q15(0.1) && inv.c == 0)
                     {
                        inv.duty--;
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
            inv.duty = 0;
            m.StartUpCnt++;
            if (m.StartUpCnt > 60000)
            {
                m.StartUpCnt = 0;
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

