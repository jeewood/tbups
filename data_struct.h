#include <p33fj16gs504.h>  
#ifndef __DATA_STRUCT__
#define __DATA_STRUCT__

extern unsigned int Root(unsigned long Number);

typedef union _INT
{
	unsigned int x;
	struct{
		unsigned char h;
		unsigned char l;
	};	
}INT;

typedef struct
{
	int ACInV;
	int ACInI;
	int InvV;
	int LoadI;
	int BatV;
	int BatI;
	int Factor;
	int Power; //功率
	int LoadRate; //负载率
	int ACInF;
	int InvF;
	int ChargeStatus;
}CValue;

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
}SValue;

extern CValue Value;
extern int sValue[];
//extern SValue sValue;

typedef struct
{
	unsigned b0:1;
	unsigned b1:1;
	unsigned b2:1;
	unsigned b3:1;
	unsigned b4:1;
	unsigned b5:1;
	unsigned b6:1;
	unsigned b7:1;
}Bits;

extern Bits bFlag;
extern Bits ControlBits;

#define mf bFlag.b0
#define invf bFlag.b1
#define invShift bFlag.b2
#define bypassInSwitch bFlag.b3

#endif //__DATA_STRUCT__
