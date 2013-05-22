#include <p33fj16gs504.h>
#ifndef __DATA_STRUCT__
#define __DATA_STRUCT__

extern unsigned int Root(unsigned long Number);
extern void Adj_Init();

typedef union _INT
{
    int x;
    struct
    {
        unsigned char l;
        unsigned char h;
    };
} INT;


#define OVERLOAD_NORMAL 0
#define OVERLOAD120 1
#define OVERLOAD150 2
typedef struct _overload
{
    unsigned long cnt;  //计时器
    char f;
    int curr;           //120过载电流
    int ol_curr;        //120过载电流限值
    int s_curr;         //150冲击电流限值
    int cycle;
}OVERLOAD;

typedef struct _bypass
{
    unsigned long cnt;
    char r;
    char inSwitch;
}BP_STRUCT;

extern INT Value[];
#define ACInV       	 Value[0].x
#define ACInI       	 Value[1].x
#define InvV        	 Value[2].x
#define LoadI       	 Value[3].x
#define BatV        	 Value[4].x
#define BatI        	 Value[5].x
#define Factor      	 Value[6].x
#define Power       	 Value[7].x
#define LoadRate         Value[8].x
#define ACInF            Value[9].x
#define InvF             Value[10].x
#define ChargeStatus     Value[11].x

extern INT sValue[];
#define Adj_ACInV        sValue[0].x
#define Adj_ACInI        sValue[1].x
#define Adj_InvV         sValue[2].x
#define Adj_LoadI        sValue[3].x
#define Adj_BatV         sValue[4].x
#define Adj_BatI         sValue[5].x
#define Adj_Factor       sValue[6].x
#define Adj_Power        sValue[7].x
#define Adj_LoadRate     sValue[8].x
#define Adj_ACInF        sValue[9].x
#define Adj_InvF         sValue[10].x
#define Adj_ChargeStatus sValue[11].x

#define ModbusSA         sValue[12].x
#define wMode            sValue[13].x
#define sMode            sValue[14].x
#define BKLtime          sValue[15].x
#define Password         sValue[16].x
#define BaudRate         sValue[17].x
#define DataBits         sValue[18].x
#define StopBits         sValue[19].x
#define OddEven          sValue[20].x
#define StartCtrl        sValue[21].x
#define ByPassCtrl       sValue[22].x
#define RatedCurr        sValue[23].x

typedef struct
{
    unsigned b0: 1;
    unsigned b1: 1;
    unsigned b2: 1;
    unsigned b3: 1;
    unsigned b4: 1;
    unsigned b5: 1;
    unsigned b6: 1;
    unsigned b7: 1;
} Bits;

extern Bits bFlag;
extern Bits ControlBits;
extern OVERLOAD ol;
extern BP_STRUCT bp;

#define SetRelay(b)	{ bp.r = b; bp.inSwitch = 1; }

#define mf bFlag.b0
#define invf bFlag.b1
#define invShift bFlag.b2
#define bypassInSwitch bFlag.b3

#endif //__DATA_STRUCT__
