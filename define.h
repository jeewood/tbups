#include "data_struct.h"

#define PHASESHIFT

#define mulss(s,d) (__builtin_mulss((int)(s),(int)(d)))
#define mulsu(s,d) (__builtin_mulsu((int)(s),(unsigned int)(d)))
#define muluu(s,d) (__builtin_muluu((unsigned int)(s),(unsigned int)(d)))
#define divss(n,d) (__builtin_divsd((long)n, (int) d))

/* AC Mains State definitions */

#define NOT_READY_TO_SWITCH 0
#define READY_TO_SWITCH 1

#define SINE_11_25_DEGREES (2507 >> OUTPUT_VOLTAGE_SETTING)
#define SINE_22_5_DEGREES (5086 >> OUTPUT_VOLTAGE_SETTING)
#define SINE_33_75_DEGREES (7470 >> OUTPUT_VOLTAGE_SETTING)
#define SINE_45_DEGREES (9566 >> OUTPUT_VOLTAGE_SETTING)
#define SINE_56_25_DEGREES (11295 >> OUTPUT_VOLTAGE_SETTING)
#define SINE_67_5_DEGREES (12589 >> OUTPUT_VOLTAGE_SETTING)
#define SINE_78_75_DEGREES (13400 >> OUTPUT_VOLTAGE_SETTING)

#define INVERTER_CURRENT_MAX_PEAK 6000

#define CURRENT_LIMIT_CLEARED 0
#define CURRENT_LIMIT_ACTIVE 1

#define DRIVER_FAULT_CLEARED 0
#define DRIVER_FAULT_ACTIVE 1

/* RMS Calculation constants */
#define RMS_BUFFER_SIZE  SINE_TABLE_SIZE>>1
#define READY_TO_COLLECT_DATA 0
#define READY_TO_CALCULATE 1
#define CALCULATION_DONE 2
#define RMS_NOT_READY 3


/* System State definitions */
#define SYSTEM_STARTUP 0
#define BATTERY_CHARGER_MODE 1
#define INVERTER_MODE 2
#define SYSTEM_ERROR 3
#define STATE_UNKNOWN 4

#define UNKNOWN_QUADRANT 0
#define FIRST_QUADRANT 1
#define SECOND_QUADRANT 2
#define THIRD_QUADRANT 3
#define FOURTH_QUADRANT 4

#define MAINS_FREQUENCY_ERROR 9

extern volatile int mainsVref[];
extern int voltageRMSBuffer[];

#define NOK 0
#define ADJ 1
#define HVD 2
#define SYNC 3
#define OK 4

#define MAINSIZE 200
typedef struct _mains
{
	int cv;
	int pv;
	int maxv;
	int minv;
	int cnt;
	int size;
	int ofs;
		
	//int vs[MAINSIZE];
	int V;
	int icnt;
	int ocnt;
	int err;
	int i;
	int f;
	unsigned char cycle;
	char state;

}MAINSTRUCT;

extern MAINSTRUCT m;

typedef struct _invs
{
	int idx;
	int cv;
	int pv;
	int maxv;
	int minv;
	int size;
	int ofs;
	//int vs[MAINSIZE];
	int V;
	int cnt;
	int i;
	int f;
	char state;
	unsigned char cycle;
	unsigned char c;
	int ocnt;
	char synced;
}INVSTRUCT;

extern INVSTRUCT inv;

extern char ADJEN;
extern long ByPassCnt;
#define DUTY_SCALE 0.99

#define LED LATCbits.LATC7
#define BEEP LATCbits.LATC2

#define NEWBOARD
#ifdef NEWBOARD
	#define BYPASS LATBbits.LATB3
	#define SSTART LATBbits.LATB4
#else
	#define BYPASS LATCbits.LATC0
	#define SSTART LATCbits.LATC13
#endif

#define SCR LATCbits.LATC5



