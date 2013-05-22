#include "define.h"

#include <dsp.h>
#include "beep.h"

//CValue Value={0};
INT Value[12];
//INT Vadj[12];
//SValue sValue = 0;
INT sValue[24];

OVERLOAD ol = {0};
BP_STRUCT bp = {0};

Bits bFlag = {0};
Bits ControlBits = {0};

unsigned int beep_cnt;
BEEPSTRUCT bpd = {0};
void SetBeep(char stat, unsigned int ontime,unsigned int offtime)
{
    if (stat != bpd.stat)
    {
        bpd.stat = stat;
        bpd.ontime = ontime;
        bpd.offtime = offtime;

        if (bpd.stat) 
        {
            BEEP = 1;
            bpd.cnt = bpd.ontime;
        }
        else
        {
            BEEP = 0;
            bpd.cnt = 0;
        }
    }
}

void BeepDrv()
{
    if (bpd.cnt) bpd.cnt--;

    if (bpd.cnt == 1)
    {
        if (bpd.stat==LOOP) 
        {
            BEEP = ~BEEP;
            if (BEEP)
            {
                bpd.cnt = bpd.ontime;
            }
            else
            {
                bpd.cnt = bpd.offtime;
            }
        }
        else
        {
            BEEP = 0;
            bpd.cnt = 0;
        }
    }
}

void Adj_Init()
{
    Adj_ACInV      = Q15(1.0);
    Adj_ACInI      = Q15(1.0);
    Adj_InvV       = Q15(1.0);
    Adj_LoadI      = Q15(1.0);
    Adj_BatV       = Q15(1.0);
    Adj_BatI       = Q15(1.0);
    Adj_Factor     = Q15(1.0);
    Adj_Power      = Q15(1.0);
    Adj_LoadRate   = Q15(1.0);
    Adj_ACInF      = Q15(1.0);
    Adj_InvF       = Q15(1.0);
    Adj_ChargeStatus    = Q15(1.0);
}

unsigned int Root(unsigned long Number)
{
    unsigned int i;
    unsigned long SquareRoot;
    if (Number == 0)
    {
        return 0;
    }
    if (Number <= 4194304)
    {
        SquareRoot = (Number >> 10) + 63;
    }
    else if (Number <= 134217728)
    {
        SquareRoot = (Number >> 12) + 255;
    }
    else
    {
        SquareRoot = (Number >> 14) + 1023;
    }
    for (i = 0; i < 5; i++)
    {
        SquareRoot = (SquareRoot + Number / SquareRoot) >> 1;
    }
    return ((unsigned int) SquareRoot);
}

