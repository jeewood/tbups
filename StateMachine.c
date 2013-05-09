#include <p33fj16gs504.h>  
#include <libq.h>
#include <dsp.h>
#include "define.h"
#include "uart.h"
#include "pwm.h"

int State;
extern int Duty;

int LEDCnt = 0;

void initStateMachineTimer(void)
{
    T2CONbits.TCKPS = 0;        /* Prescaler of 1:1 */
    PR2 = 4000;                 /* (100us / 25ns) = 4000 */ 
    IPC1bits.T2IP = 4;          /* Set up Timer interrupt priority */
    IEC0bits.T2IE = 1;          /* Enable Timer2 interrupt */
    
    T2CONbits.TON = 1;                      /* Enable State machine timer */
    State = STATE_UNKNOWN;
}

unsigned long StartUpCnt = 0;
extern unsigned char InvMode;

long ByPassCnt = 0,ScrCnt = 0;
int sCntx = 0;
void __attribute__((__interrupt__, no_auto_psv)) _T2Interrupt()
{
	if (LEDCnt>3000)
	{
		LEDCnt = 0;
		LED = ~LED;
	}
	LEDCnt++;	
	
	m.f+=mf;
	inv.f+=invf;
	
	UART_DRV();
			
	switch(State)
	{
	case SYSTEM_STARTUP:
	{
		inv.synced = 0;
		if (m.state == OK)
		{
			if (Value.ACInV>2000)
			{
				if (Value.InvV<Value.ACInV-100)
				{
						if (Duty<Q15(DUTY_SCALE)) Duty++;
						ByPassCnt = 0;
				}
				else
				{
					ByPassCnt++;
					if (ByPassCnt>30000)
					{
						ByPassCnt = 0;
						State = INVERTER_MODE;
						//BEEP = 0;
					}	
				}
			}
			LED = ~LED;
		}
		else
		{
			if (Duty<Q15(DUTY_SCALE))
			{
				Duty ++;//= Q15(0.0001);
			}
			else
			{
				ByPassCnt = 0;
				State = INVERTER_MODE;
			}
		}
	}
	break;
	case INVERTER_MODE:
	{
		if (m.state == OK)
		{
			//#ifndef TEST
			if (Value.ACInV > 1000 && jabs(Value.ACInV-Value.InvV)>50)
			{
				sCntx++;
				if (sCntx>5)
				{
					if (Value.InvV<Value.ACInV)
					{
						if (Duty < Q15(DUTY_SCALE))	Duty ++;
					}
					else if (Value.InvV>Value.ACInV)
					{
						if (Duty > Q15(0.1))Duty --;
					}
				}
			}
			//#endif
			
			if (inv.synced)
			{
				if (bypassInSwitch)
				{
					SCR = 1;
					ScrCnt = 80;
					bypassInSwitch = 0;
				}
	
				if (ScrCnt==60)
				{
					if (sValue.ModbusSA==1)
					{
						BYPASS = 0;	
					}
					else if (sValue.ModbusSA == 0)
					{
						BYPASS = 1;
					}					
				}

				if ((ScrCnt--)==1)
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
		if (StartUpCnt>60000)
		{
			StartUpCnt = 0;
			if (m.state == OK || (m.state == NOK))
			{
				SSTART = 0;
				//BYPASS = 0;
				//SCR = 0;
				State = SYSTEM_STARTUP;
			}
		}
	}
	break;
	
	}
	
	if (m.state == OK)
	{
		Value.Mode.h = 1;
	}
	else
	{
		Value.Mode.h = 0;
	}
				
	TMR2 = 0;
	IFS0bits.T2IF = 0;                      /* Clear Interrupt Flag */
}

