typedef struct _beep
{
	unsigned int cnt;
    unsigned int ontime;
    unsigned int offtime;
    unsigned char stat;
}BEEPSTRUCT;

extern unsigned int beep_cnt;
extern BEEPSTRUCT bpd;
#define LOOP 2
#define ON 1
#define OFF 0

extern void SetBeep(char stat, unsigned int ontime, unsigned offtime);
extern void BeepDrv();

