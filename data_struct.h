#include <p33fj16gs504.h>
#ifndef __DATA_STRUCT__
#define __DATA_STRUCT__

extern unsigned int Root(unsigned long Number);
extern void Adj_Init();

typedef union _INT
{
    unsigned int x;
    struct
    {
        unsigned char l;
        unsigned char h;
    };
} INT;
/*
typedef struct
{
    int ACInV;              //0
    int ACInI;              //1
    int InvV;               //2
    int LoadI;              //3
    int BatV;               //4
    int BatI;               //5
    int Factor;             //6
    int Power;              //7功率
    int LoadRate;           //8负载率
    int ACInF;              //9
    int InvF;               //10
    int ChargeStatus;       //11
} CValue;

typedef struct
{
    unsigned int ModbusSA;
    unsigned int wMode;
    unsigned int sMode;
    unsigned int BKLtime;
    unsigned int BaudRate;
    unsigned int DataBits;
    unsigned int StopBits;
    unsigned int OddEven;
    unsigned int StartCtrl;
    unsigned int ByPassCtrl;
} SValue;
*/

extern INT Value[];
#define ACInV       	Value[0].x
#define ACInI       	Value[1].x
#define InvV        	Value[2].x
#define LoadI       	Value[3].x
#define BatV        	Value[4].x
#define BatI        	Value[5].x
#define Factor      	Value[6].x
#define Power       	Value[7].x
#define LoadRate        Value[8].x
#define ACInF           Value[9].x
#define InvF            Value[10].x
#define ChargeStatus    Value[11].x

extern INT sValue[];
#define ModbusSA         sValue[0].l
#define wMode            sValue[1].x
#define sMode            sValue[2].x
#define BKLtime          sValue[3].x
#define Password         sValue[4].x
#define BaudRate         sValue[5].x
#define DataBits         sValue[6].x
#define StopBits         sValue[7].x
#define OddEven          sValue[8].x
#define StartCtrl        sValue[9].x
#define ByPassCtrl       sValue[10].x
 
#define Adj_ACInV        sValue[11].x
#define Adj_ACInI        sValue[12].x
#define Adj_InvV         sValue[13].x
#define Adj_LoadI        sValue[14].x
#define Adj_BatV         sValue[15].x
#define Adj_BatI         sValue[16].x
#define Adj_Factor       sValue[17].x
#define Adj_Power        sValue[18].x
#define Adj_LoadRate     sValue[19].x
#define Adj_ACInF        sValue[20].x
#define Adj_InvF         sValue[21].x
#define Adj_ChargeStatus sValue[22].x

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

#define mf bFlag.b0
#define invf bFlag.b1
#define invShift bFlag.b2
#define bypassInSwitch bFlag.b3

#endif //__DATA_STRUCT__
