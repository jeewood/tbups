#include "data_struct.h"
#include <dsp.h>

#define PHASESHIFT

#define mulss(s,d) (__builtin_mulss((int)(s),(int)(d)))
#define mulsu(s,d) (__builtin_mulsu((int)(s),(unsigned int)(d)))
#define muluu(s,d) (__builtin_muluu((unsigned int)(s),(unsigned int)(d)))
#define divss(n,d) (__builtin_divsd((long)(n), (int)(d)))
#define divud(n,d) (__builtin_divud((unsigned long)(n), (unsigned int)(d)))

/* AC Mains State definitions */

#define NOT_READY_TO_SWITCH 0
#define READY_TO_SWITCH 1

#define CURRENT_LIMIT_CLEARED 0
#define CURRENT_LIMIT_ACTIVE 1

/* RMS Calculation constants */
#define READY_TO_COLLECT_DATA 3
#define READY_TO_CALCULATE 1
#define CALCULATION_DONE 2
#define RMS_NOT_READY 0


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
    int max;
    
    int max_idx;

    int min;
    int cnt;
    int size;
    int ofs;

    int V;
    int icnt;
    int ocnt;
    int err;
    int i;
    int f;
    char rms_stat;
    unsigned char cycle;
    char state;
    unsigned long long sum;
}MAINSTRUCT;

extern MAINSTRUCT m;

typedef struct _invs
{
    int idx;
    int cv;
    int pv;
    int max;

    int max_idx;

    int min;
    int size;
    int ofs;

    int V;
    int cnt;
    int i;
    int f;

    char rms_stat;
    char state;
    unsigned char cycle;
    unsigned char c;
    int ocnt;
    char synced;
    unsigned long long sum;
}INVSTRUCT;

extern INVSTRUCT inv;

typedef struct _curr
{
    int cv;
    int pv;
    
    int V;
    int size;
    int cnt;
    int max;

    int max_idx;
    int rms_stat;

    int min;
    int ofs;
    
    unsigned long long sum;
}CURRSTRUCT;

extern CURRSTRUCT mcurr;
extern CURRSTRUCT ocurr;

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
#define MANCTRL PORTCbits.RC6



