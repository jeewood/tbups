#include<p33fj16gs504.h>  
#include<libq.h>
#include<dsp.h>
#include "sineTable_50Hz.h"
#include "define.h"

// Inverter Constants 
#define TriPD 18400
#define TriPDX 23600

#define DC_OFFSET 0x3FF0 //0x43E0		//0x3FF0

long PD3 = TriPD;
long PD2 = TriPD;

int Duty = 0; //Q15(1.0);

INVSTRUCT inv = {0};
MAINSTRUCT m = {0};

CURRSTRUCT mcurr = {0};
CURRSTRUCT ocurr = {0};
CURRSTRUCT dcbus_v = {0};
CURRSTRUCT dcbus_i = {0};

#define iszc(s,v) (((s).cnt>360) && (((s).pv < 0 && ((s).cv>=0)) && ((s).cv-(s).pv>(v))))
#define issz(s,v) (((s).cnt>128) && (((s).pv>0 && ((s).cv <=0)) && ((s).pv-(s).cv>(v))))

inline int jabs(int x)  { return (x < 0) ? (-(x)) : (x); }

#define abs jabs
#define set(v) { m.cv=(v); }

#define clr(v) (v) = 0
#define inc(s) {(s).cnt=((s).cnt+1)%1024;(s).i = ((s).cnt>256)?(s).cnt-512:(s).cnt;}

#define incr(s) ((s)=((s)<20000)?(s)+1:20000)
#define decr(s) ((s)=((s)>17000)?(s)-1:17000)

#define SetPhase3(v) {if (v>17500 && v < 20000) { PHASE3 = v; } }
#define SetPhase2(v) {if (v>17500 && v < 20000) { PHASE2 = v; } }

#define ZCTHV 0

#define CONVERSION_PAIRS 2

/**
 * [ConvPair0Handler description]
 * Inverter output Voltage current gatharing
 */
void ConvPair0Handler(void)
{
    ocurr.cv = (ADCBUF0 << 5) - DC_OFFSET - ocurr.ofs;
    ocurr.cnt ++;
    
    inv.cv = (ADCBUF1 << 5) - DC_OFFSET - inv.ofs;
    inv.cnt++;
    inv.i++;

    //currect part
    if (ocurr.rms_stat == READY_TO_COLLECT_DATA)
    {
        ocurr.sum += mulss(ocurr.cv,ocurr.cv);
        if (ocurr.max < ocurr.cv)    //�����ֵ
        {
            ocurr.max = ocurr.cv;
            ocurr.max_idx = ocurr.cnt;
        }
        if (ocurr.min > ocurr.cv)    //����Сֵ
        {
            ocurr.min = ocurr.cv;
        }
    }

    //voltage part
    if (inv.rms_stat == READY_TO_COLLECT_DATA)
    {
        inv.sum += mulss(inv.cv, inv.cv);
        if (inv.max < inv.cv)    //�����ֵ
        {
            inv.max = inv.cv;
            inv.max_idx = inv.cnt;
        }
        if (inv.min > inv.cv)    //����Сֵ
        {
            inv.min = inv.cv;
        }
    }

    if ((iszc(inv, ZCTHV)) || (inv.cnt > 1000)) 
    {
        ocurr.size = ocurr.cnt;
        ocurr.cnt = 0;

        inv.size = inv.cnt;
        inv.cnt = 0;
        //currect part
        if (ocurr.rms_stat == CALCULATION_DONE)
        {
            ocurr.sum = 0;
            ocurr.max = ocurr.min = 0;
            ocurr.rms_stat = READY_TO_COLLECT_DATA;
        }
        else
        {
            if (ocurr.max + ocurr.min > 10)
            {
                ocurr.ofs += (ocurr.ofs < 1000)?1:0;
            }
            else if (ocurr.max + ocurr.min < -10)
            {
                ocurr.ofs -= (ocurr.ofs > -1000)?1:0;
            }
        }
        //voltage part
        if (inv.rms_stat == CALCULATION_DONE)
        {
            inv.sum = 0;
            inv.max = inv.min = 0;
            inv.rms_stat = READY_TO_COLLECT_DATA;
        }
        else
        {
            if (inv.max + inv.min > 10)
            {
                inv.ofs += (inv.ofs < 1000) ? 1 : 0;
            }
            else if (inv.max + inv.min<-10)
            {
                inv.ofs -= (inv.ofs>-1000) ? 1 : 0;
            }
            inv.rms_stat = READY_TO_CALCULATE;
        }

        //this is only for debug,
        InvF = inv.size;
        if (inv.size > 400 && inv.size < 600)
        {
            inv.cycle ++;
            inv.ocnt = 0;
            if (inv.cycle>20)
            {
                inv.cycle = 0;
                inv.state = OK;
            }
        }
        else
        {
            inv.ocnt++;
            inv.cycle = 0;
            if (inv.ocnt>10)
            {
                inv.ocnt = 0;
                inv.state = NOK;
            }
            inv.ofs = 0;
        }
    }

    if (issz(inv, ZCTHV))
    {
        inv.i = 0;
    }

    inv.pv = inv.cv;

    if ((inv.idx == 0)) //50Hz�л���������
    {
        IOCON2bits.OVRDAT = 2;
    }
    else 
    if (inv.idx == (SINE_TABLE_SIZE>>1))
    {
        IOCON2bits.OVRDAT = 0;
    }

    PDC2 = mulss(SIN(inv.idx), Duty) >> 15;

    inv.idx = (inv.idx + 1) % SINE_TABLE_SIZE;

    ADSTATbits.P0RDY = 0; // Clear the ADSTAT bits
}

/**
 * [ConvPair1Handler description]
 * AC input voltage current gathering
 */
int err, perr = 0;

void ConvPair1Handler(void)
{
    mcurr.cv = (ADCBUF3 << 5) - DC_OFFSET - mcurr.ofs;
    mcurr.cnt ++;

    m.cv = (ADCBUF2 << 5) - DC_OFFSET - m.ofs;
    m.cnt++;
    m.i++;

    //currect part
    if (mcurr.rms_stat == READY_TO_COLLECT_DATA)
    {
        mcurr.sum += mulss(mcurr.cv,mcurr.cv);
        if (mcurr.max < mcurr.cv)    //�����ֵ
        {
            mcurr.max = mcurr.cv;
            mcurr.max_idx = mcurr.cnt;
        }
        if (mcurr.min > mcurr.cv)    //����Сֵ
        {
            mcurr.min = mcurr.cv;
        }
    }

    //voltage part
    if (m.rms_stat == READY_TO_COLLECT_DATA)
    {
        m.sum += mulss(m.cv, m.cv);
        if (m.max < m.cv)    //�����ֵ
        {
            m.max = m.cv;
            m.max_idx = m.cnt;
        }
        if (m.min > m.cv)    //����Сֵ
        {
            m.min = m.cv;
        }
    }

    if (issz(m, ZCTHV))
    {
        m.i = 0;
    }

    if ((iszc(m, ZCTHV)) || (m.cnt > 1000)) 
    {
        mcurr.size = mcurr.cnt;
        mcurr.cnt = 0;

        m.size = m.cnt;
        m.cnt = 0;

        //currect part
        if (mcurr.rms_stat == CALCULATION_DONE)
        {
            mcurr.sum = 0;
            mcurr.max = mcurr.min = 0;
            mcurr.rms_stat = READY_TO_COLLECT_DATA;
        }
        else
        {
            if (mcurr.max + mcurr.min > 10)
            {
                mcurr.ofs += (mcurr.ofs < 1000)?1:0;
            }
            else if (mcurr.max + mcurr.min < -10)
            {
                mcurr.ofs -= (mcurr.ofs > -1000)?1:0;
            }
        }
        //voltage part
        if (m.rms_stat == CALCULATION_DONE)
        {
            m.sum = 0;
            m.max = m.min = 0;
            m.rms_stat = READY_TO_COLLECT_DATA;
        }
        else if (m.cnt < 1000)
        {
            if (m.max + m.min > 10)
            {
                m.ofs += (m.ofs < 1000) ? 1 : 0;
            }
            else if (m.max + m.min<-10)
            {
                m.ofs -= (m.ofs>-1000) ? 1 : 0;
            }

            m.rms_stat = READY_TO_CALCULATE;
        }

        if (m.size >= 1000 || ACInV < 1000) 
        {
            m.ocnt++;
            if (m.ocnt > 5)
            {
                m.state = NOK;
                m.ocnt = 0;
                m.ofs = 0;
            }
        }
        else
        {
            switch (m.state)
            {
                case NOK:
                {
                    m.icnt++; 
                    if (m.icnt > 10 && ACInV > 1000)
                    {
                        m.state = ADJ;
                        m.icnt = 0;
                    }
                    break;
                }
                case ADJ:
                {
                    if (m.size > 511)
                    {
                        incr(PD3); 
                    }
                    else if (m.size < 511)
                    {
                        decr(PD3); 
                    }
                    else
                    {
                        m.cycle++;
                        if (m.cycle > 20)
                        {
                            m.state = OK;
                            m.cycle = 0;
                        }
                    }
                    SetPhase3(PD3);
                    break;
                }
                case OK:
                {
                    if (m.size > 511) 
                    {
                        incr(PD3);
                        SetPhase3(PD3)
                    }
                    else if (m.size < 511)
                    {
                        decr(PD3);
                        SetPhase3(PD3)
                    }

                    if ((inv.state == OK))  //���״̬����
                    {
                        if (jabs(PD3 - PD2) < 50)   //Ƶ��ͬ������
                        {
                            err = (inv.i - m.i);
                            if (jabs(err) > 0)
                            {
                                if (err > 128) err = 128;
                                if (err < -128) err = -128;

                                PD2 += (err >> 0) - (perr >> 0);

                                if (err > 2)
                                {
                                    incr(PD2);
                                }
                                else if (err < -2)
                                {
                                    decr(PD2);
                                }
                                perr = err;
                            }
                            if (jabs(err) < 2)
                            {
                                inv.cycle++;
                                if (inv.cycle > 50)
                                {
                                    inv.synced = 1;
                                    inv.cycle = 0;
                                }
                                inv.ocnt = 0;
                            }
                            else if (jabs(err) > 10)
                            {
                                inv.ocnt++;
                                inv.cycle = 0;
                                if (inv.ocnt > 100)
                                {
                                    inv.synced = 0;
                                    inv.ocnt = 0;
                                }
                            }
                        }
                        else if (PD2 < PD3)
                        {
                            incr(PD2);
                        }
                        else if (PD2 > PD3)
                        {
                            decr(PD2);
                        }

                        SetPhase2(PD2);
                    }
                    break;
                }
            }
        }

        Power = PD3;
        Factor = PD2;

        ChargeStatus = inv.ofs;

        ACInF = m.size;

    }

    m.pv = m.cv;

    //_SWTRG5 = 1;

    ADSTATbits.P1RDY = 0; // Clear the ADSTAT bits
}

void ConvPair5Handler(void)
{
    BatI = (ADCBUF10);
    BatV = (ADCBUF11);

    ADSTATbits.P5RDY = 0; // Clear the ADSTAT bits
}

void (*jumpTable[CONVERSION_PAIRS * 2 - 1])(void);

void initADC(void)
{
    // Common ADC configuration 
    ADCONbits.ADON = 0;
                                    // ADON �� A/D ����ģʽλ
                                    // 1 = A/D ת����ģ���ڹ���
                                    // 0 = A/D ת�����ر�    
    ADCONbits.ADSIDL = 0;
                                    // ADSIDL��  �ڿ���ģʽ��ֹͣλ
                                    // 1 = �������������ģʽʱ��ģ��ֹͣ����
                                    // 0 = �ڿ���ģʽ��ģ���������    
    ADCONbits.SLOWCLK = 1; 
                                    // SLOWCLK����Ƶʱ�ӷ�Ƶ��ʹ��λ
                                    // 1 =  ʹ����Ե�ƵADC����ʱ�ӵ�ʱ�ӷ�Ƶ�ȡ�
                                    //      �˷�Ƶ���ṩ�ͷ�Ƶ�������ڽ���������ʱ���»��
                                    //      �ٶ�����ADC������
                                    // 0 =  ʹ����Ը�ƵADC����ʱ�ӵ�ʱ�ӷ�Ƶ�ȡ�
                                    //      �˷�Ƶ���ṩ�߷�Ƶ�ȡ�     
    ADCONbits.FORM = 0;             
                                    // FORM �����������ʽλ
                                    // 1 = С����DOUT =  dddd dddd dd00 0000��
                                    // 0 = ������DOUT = 0000 00dd dddd dddd��   
    ADCONbits.EIE = 1;              // Disable Early Interrupt ,�˴�����AD�ж�,ʹ��ͨ��PWM�������ж�
                                    // EIE����ǰ�ж�����λ
                                    // 1 = �ڵ�һ��ת����ɺ�����ж�
                                    // 0 = �ڵڶ���ת����ɺ�����ж�    
    ADCONbits.ORDER = 0;            
                                    // ORDER��ת��˳��λ
                                    // 1 = ��ת��������ŵ�ģ�����룬Ȼ��ת��ż����ŵ�����
                                    // 0 = ��ת��ż����ŵ�ģ�����룬Ȼ��ת��������ŵ����� 
    ADCONbits.SEQSAMP = 0;          
                                    // SEQSAMP ��˳�����ʹ��λ
                                    // 1 = ���ORDER =0���ڵڶ���ת����ʼʱ�Թ��ò���/ ���֣�S&H��
                                    // ��·���в��������ORDER =  1�����ڵ�һ��ת����ʼʱ�Թ���S&H
                                    // ��·���в�����
                                    // 0 = ���������ת�������й���S&H������æ״̬�����ڲ���ר��
                                    // S&H��ͬʱ�Թ���S&H���в�����
                                    // ����ڲ���ר��S&Hʱ����S&H����æ״̬��������ת�����ڿ�ʼʱ
                                    // �Թ���S&H���в�����  
    ADCONbits.ASYNCSAMP = 1;
                                    // ASYNCSAMP���첽ר��S&H����ʹ��λ
                                    // 1 = ר��S&H�ڲ��ϲ�����һ����⵽�������弴��ֹ������ 
                                    // 0 = ����⵽�����¼�ʱר��S&H��ʼ��������������ADCʱ��������
                                    // ��ɲ������̡�  
    ADCONbits.ADCS = 5;             // Clock Divider is set up for Fadc/6 
                                    // TAD=41.66ns
                                    // For simultaneus sampling total conversion time for one pair is 0.625us 
                                    // ADCS < 2:0>��A/D ת��ʱ�ӷ�Ƶֵѡ��λ
                                    // ���SLOWCLK = 0��ADCʱ�ӷ�Ƶֵ���£�
                                    // 111  = FADC/7 
                                    // 110  = FADC/6.5 
                                    // 101  = FADC/6 
                                    // 100  = FADC/5.5 
                                    // 011  = FADC/5 ��Ĭ�ϣ�
                                    // 010  = FADC/4.5 
                                    // 001  = FADC/4 
                                    // 000  = FADC/3.5 
                                    // ���SLOWCLK = 1��ADCʱ�ӷ�Ƶֵ���£�
                                    // 111  = FADC/8
                                    // 110  = FADC/7
                                    // 101  = FADC/6
                                    // 100  = FADC/5
                                    // 011  = FADC/4 ��Ĭ�ϣ�
                                    // 010  = FADC/3
                                    // 001  = FADC/2
                                    // 000  = FADC/1    
    ADSTAT = 0;                     // Clear the ADSTAT register 
                                    // ADSTAT ��A/D ״̬�Ĵ���
                                    // bit 15-7 δʵ�֣���Ϊ0
                                    // bit 6 P6RDY�������6 ת�����ݾ���λ
                                    // �������������ݾ���ʱ��λ����1����д��0 ʱ��λ�����㡣
                                    // bit 5 P5RDY�������5 ת�����ݾ���λ
                                    // �������������ݾ���ʱ��λ����1����д��0 ʱ��λ�����㡣
                                    // bit 4 P4RDY�������4 ת�����ݾ���λ
                                    // �������������ݾ���ʱ��λ����1����д��0 ʱ��λ�����㡣
                                    // bit 3 P3RDY�������3 ת�����ݾ���λ
                                    // �������������ݾ���ʱ��λ����1����д��0 ʱ��λ�����㡣
                                    // bit 2 P2RDY�������2 ת�����ݾ���λ
                                    // �������������ݾ���ʱ��λ����1����д��0 ʱ��λ�����㡣
                                    // bit 1 P1RDY��  �����1 ת�����ݾ���λ
                                    // �������������ݾ���ʱ��λ����1����д��0 ʱ��λ�����㡣
                                    // bit 0 P0RDY��  �����0 ת�����ݾ���λ
                                    // �������������ݾ���ʱ��λ����1����д��0 ʱ��λ�����㡣


    IPC3bits.ADIP = 1;
    IFS0bits.ADIF = 0;
    IEC0bits.ADIE = 1;

    // ADPCFG��A/D �˿����üĴ���   ADC configuration for Full-Bridge Inverter 
    _PCFG0 = 0;           // AN0 ������ 
    _PCFG1 = 0;           // AN1 ����ѹ

    _TRGSRC0 = 5;         // AN0 and AN1 ��PWM2����
                                    // TRGSRC0 < 4:0>������0 ����Դѡ��λ
                                    // Ϊģ��ͨ��AN1 ��AN0 ��ת��ѡ�񴥷�Դ��
                                    // 00000  = ��ʹ��ת��
                                    // 00001  = ѡ������������
                                    // 00010  = ѡ��ȫ���������
                                    // 00011  = ѡ��PWM �����¼�����
                                    // 00100  = ѡ��PWM ������1 ������
                                    // 00101  = ѡ��PWM ������2 ������
                                    // 00110  = ѡ��PWM ������3 ������
                                    // 00111  = ѡ��PWM ������4 ������
                                    // 01000  = ����
                                    // 01100  = Timer1 ����ƥ��
                                    // 01101  = ����
                                    // 01110  = ѡ��PWM ������1 ��������
                                    // 01111  = ѡ��PWM ������2 ��������
                                    // 10000  = ѡ��PWM ������3 ��������
                                    // 10001  = ѡ��PWM ������4 ��������
                                    // 10010  = ����
                                    // 10110  = ����
                                    // 10111  = PWM ������1 ����ADC����
                                    // 11000  = PWM ������2 ����ADC����
                                    // 11001  = PWM ������3 ����ADC����
                                    // 11010  = PWM ������4 ����ADC����
                                    // 11011  = ����
                                    // 11111  = Timer2 ����ƥ��     
    _IRQEN0 = 1;          // Global ADC interrupt not requested 
                                    // IRQEN0 ��  �ж���������0 λ
                                    // 1 = ��ͨ��AN1 ��AN0 �������ת�����ʱ��������ж�����
                                    // 0 = �������ж�����
    //IPC27bits.ADCP0IP = 7;        // Set ADC Interrupt Priority 
    //IFS6bits.ADCP0IF = 0;         // Clear AD Interrupt Flag 
    //IEC6bits.ADCP0IE = 1;         // Enable the ADC Interrupt at start. 
    //End of ADC configuration for ACInput 

    _PCFG2 = 0;           // AN2 ���뽻����ѹ
    _PCFG3 = 0;           // AN3 ���뽻������

    _TRGSRC1 = 6;         // AN0 and AN1 triggered by PWM3 
    _IRQEN1 = 1;          // Global ADC interrupt not requested 
    //IPC27bits.ADCP1IP = 7;        // Set ADC Interrupt Priority 
    //IFS6bits.ADCP1IF = 0;         // Clear AD Interrupt Flag 
    //IEC6bits.ADCP1IE = 1;         // Enable the ADC Interrupt at start. 


    //ĸ��/��ص�ѹ   ĸ�ߵ���    
    _PCFG10 = 0;                    //ADPCFGbits.PCFG10 = 0; // AN10 DC_Curr ĸ�ߵ���
    _PCFG11 = 0;                    //ADPCFGbits.PCFG11 = 0; // AN11 BUS_V ĸ�ߵ�ѹ(��ص�ѹ?)

    _TRGSRC5 = 1;                   // AN10 and AN11 triggered by PWM3 ��������
    //_IRQEN5 = 1;                    // Global ADC interrupt not requested 

    _ADCP5IP = 7;
    _ADCP5IF = 0;
    _ADCP5IE = 1;

    jumpTable[0] = &ConvPair0Handler;
    jumpTable[2] = &ConvPair1Handler;
    //jumpTable[10] = &ConvPair5Handler;
    
    ADBASE = (int)(&jumpTable[0]);
        
    // End of ADC configuration for AC Mains sensing 

}


void StartADC(void)
{
    ADCONbits.ADON = 1;   // Enable the ADC module early because ADC settling time is about 2us 
}


void initPWM(void)
{
    // PWM setup for Full-Bridge Inverter section 
    PWMCON1bits.ITB     = 1;    // ITB ������ʱ��ģʽλ
                                // 1 = PHASEx/SPHASEx �Ĵ���Ϊ��PWM �������ṩʱ������
                                // 0 = PTPER �Ĵ���Ϊ��PWM �������ṩʱ��
    PWMCON1bits.DTC     = 0;    // DTC < 1:0>����������λ
                                // 00 = �����������ģʽʩ��������
                                // 01 = �����������ģʽʩ�Ӹ�����
                                // 10 = ��ֹ��������
                                // 11 = ����
    PWMCON1bits.CAM     = 1;    // CAM
                                // 1 = ʹ�����Ķ���ģʽ
                                // 0 = ��ֹ���Ķ���ģʽ        
    IOCON1bits.PENH     = 1;    // PENH:PWMH �����������Ȩλ
                                // 1 = ��PWM ģ�����PWMxH ����
                                // 0 = ��GPIOģ�����PWMxH ����
    IOCON1bits.PENL     = 1;    // PENL��PWML �����������Ȩλ
                                // 1 = ��PWM ģ�����PWMxL ����
                                // 0 = ��GPIOģ�����PWMxL ����

    IOCON1bits.PMOD     = 0;    // PMOD < 1:0>��PWM I/O����ģʽλ
                                // 00 = PWM I/O ���ŶԴ��ڻ������ģʽ
                                // 01 = PWM I/O ���ŶԴ����������ģʽ
                                // 10 = PWM I/O ���ŶԴ����������ģʽ
                                // 11 = PWM I/O ���ŶԴ�����������PWM ���ģʽ     
    IOCON1bits.OVRDAT   = 0;  // OVRDAT < 1:0>��ʹ�ܸ�дʱPWMxH ��PWMxL ���ŵ�����λ
                                // ���OVERENH = 1����OVRDAT < 1> ΪPWMxH �ṩ���ݡ�
                                // ���OVERENL =  1����OVRDAT < 0> ΪPWMxL �ṩ���ݡ�    
    IOCON1bits.OVRENH   = 1;    // OVRENH��    PWMxH ���Ÿ�дʹ��λ
                                // 1 = OVRDAT < 1> ΪPWMxH �����ṩ�������
                                // 0 =  ��PWM ������ΪPWMxH �����ṩ����
    IOCON1bits.OVRENL   = 1;  // OVRENL��   PWMxL ���Ÿ�дʹ��λ
                                // 1 = OVRDAT < 0> ΪPWMxL �����ṩ�������
                                // 0 = ��PWM ������ΪPWMxL �����ṩ����
                                
    ALTDTR1             = 0;                    //ALTDTRx < 13:0>��PWMx ������Ԫ���޷���14λ����ֵλ
    PHASE1              = TriPDX;       // PHASEx < 15:0>����PWM�������� PWM����ֵ�����ʱ������λ
    PDC1                = TriPDX>>1;    // PDCx < 15:0> ��PWM ������x ռ�ձ�ֵλ
    TRIG1               = TriPDX>>1;    // TRGCMP < 15:3>������������ֵλ
                                // ����PWM �����ڱ���ʱ��ʱ���˼Ĵ��������Ƚ�ֵ��
                                // ���Դ���ADCģ�顣
    STRIG1              = 256;    //STRGCMP < 15:3>����������������ֵλ
                                //������PWM �����ڱ���ʱ��ʱ���˼Ĵ��������Ƚ�ֵ��
                                //���Դ���ADCģ�顣

    TRGCON1bits.DTM     = 1;    // DTM��˫������ģʽλ
                                // 1 = ���������¼����������¼�һ�����PWM �����źš�
                                // 0 = ���������¼���ͬ�������¼�һ�����PWM �����źš�
                                // ���ǲ�������������PWM �����źš�
    TRGCON1bits.TRGDIV  = 1;    // TRGDIV < 3:0>�������ź������Ƶ��λ
                                // 0000 = ÿ�������¼����һ�δ����ź�
                                // 0001 = ÿ2 �������¼����һ�δ����ź�
                                // 0010 = ÿ3 �������¼����һ�δ����ź�
                                // 0011 = ÿ4 �������¼����һ�δ����ź�
                                // 0100 = ÿ5 �������¼����һ�δ����ź�
                                // 0101 = ÿ6 �������¼����һ�δ����ź�
                                // 0110 = ÿ7 �������¼����һ�δ����ź�
                                // 0111 = ÿ8 �������¼����һ�δ����ź�
                                // 1000 = ÿ9 �������¼����һ�δ����ź�
                                // 1001 = ÿ10�������¼����һ�δ����ź�
                                // 1010 = ÿ11�������¼����һ�δ����ź�
                                // 1011 = ÿ12�������¼����һ�δ����ź�
                                // 1100 = ÿ13�������¼����һ�δ����ź�
                                // 1101 = ÿ14�������¼����һ�δ����ź�
                                // 1110 = ÿ15�������¼����һ�δ����ź�
                                // 1111 = ÿ16�������¼����һ�δ����ź�
    TRGCON1bits.TRGSTRT = 0;    // TRGSTRT < 5:0>�����������Ƶ������ʹ��ѡ��λ
                                // 000000 = ��ģ��ʹ�ܺ�ȴ�0 ��PWM ���ڲ�����һ�������¼�
                                // 000001 = ��ģ��ʹ�ܺ�ȴ�1 ��PWM ���ڲ�����һ�������¼�
                                // 000010 = ��ģ��ʹ�ܺ�ȴ�1 ��PWM ���ڲ�����һ�������¼�
    FCLCON1             = 0x0003;       // FLTMOD < 1:0> ��PWM ������x �Ĺ���ģʽλ
                                // 00 = ��ѡ����Դǿ��PWMxH ��PWMxL ����ΪFLTDAT ֵ������ģʽ��
                                // 01 = ��ѡ����Դǿ��PWMxH ��PWMxL ����ΪFLTDAT ֵ������ģʽ��
                                // 10 = ����
                                // 11 = ��ֹ��������                    
                                
    //-------------------------------------------------------------------------
    PWMCON2bits.ITB     = 1;    
    PWMCON2bits.DTC     = 0;    
    PWMCON2bits.CAM     = 1;

    IOCON2bits.PENH     = 1;                    
    IOCON2bits.PENL     = 1;                  

    IOCON2bits.POLH     = 1;
    IOCON2bits.POLL     = 1;

    IOCON2bits.PMOD     = 0;
    IOCON2bits.OVRDAT   = 0;
    IOCON2bits.OSYNC    = 1;
    IOCON2bits.OVRENH   = 1;
    IOCON2bits.OVRENL   = 1;

    ALTDTR2             = 0;
    PHASE2              = TriPD;
    PDC2                = TriPD>>1;
    TRIG2               = 8;//TriPD>>1;
    STRIG2              = 256;

    TRGCON2bits.DTM     = 0;                    
    TRGCON2bits.TRGDIV  = 1;
    TRGCON2bits.TRGSTRT = 0;

    FCLCON2             = 0x0003;

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    PWMCON3bits.ITB     = 1;    
    PWMCON3bits.DTC     = 0;    
    PWMCON3bits.CAM     = 1;

    IOCON3bits.PENH     = 0;                    
    IOCON3bits.PENL     = 0;                  

    IOCON3bits.POLH     = 1;
    IOCON3bits.POLL     = 1;
    
    ALTDTR3             = 0;
    PHASE3              = TriPD;
    PDC3                = TriPD>>1;
    TRIG3               = 8;
    STRIG3              = TriPD>>2;

    TRGCON3bits.DTM     = 0;                    
    TRGCON3bits.TRGDIV  = 1;
    TRGCON3bits.TRGSTRT = 0;

    FCLCON3             = 0x0003;       
}


void StartPWM(void)
{
    PTCONbits.PTEN = 1; // Enable PWM module Turn ON PWM outputs to enable inverter output
    IOCON1bits.OVRENH = 0;
    IOCON1bits.OVRENL = 0;
    //IOCON2bits.OVRENH = 0;
    IOCON2bits.OVRENL = 0;

}

void __attribute__((interrupt, no_auto_psv)) _ADCP5Interrupt(void)
{
    //BEEP = ~BEEP;
    BatI = (ADCBUF10);
    BatV = (ADCBUF11);

    ADSTATbits.P5RDY = 0; // Clear the ADSTAT bits
    _ADCP5IF = 0; // Clear ADC Pair 0 Interrupt Flag
}

/* Example code for ADC ISR*/
void __attribute__((interrupt, no_auto_psv)) _ADCInterrupt(void)
{
    IFS0bits.ADIF = 0; // Clear ADC Pair 0 Interrupt Flag
    ((void (*)()) *((int *) ADBASE))(); // Call the corresponding handler
}

int tmpi;

void RMS_CALC()
{
    //load current part
    if (ocurr.rms_stat == READY_TO_CALCULATE)
    {
        ocurr.sum /= ocurr.size;
        tmpi = Root(ocurr.sum);
        ocurr.V = (
                (mulss(ocurr.V, Q15(0.8)) >> 15)
                +
                (mulss(tmpi, Q15(0.2)) >> 15)
                );
        ocurr.sum = 0;
        LoadI = mulss(ocurr.V, Adj_LoadI) >> 14; //30844
        ocurr.rms_stat = CALCULATION_DONE;
    }

    //inverter voltage part
    if (inv.rms_stat == READY_TO_CALCULATE)
    {
        inv.sum /= inv.size;
        tmpi = Root(inv.sum);
        inv.V = (
                (mulss(inv.V, Q15(0.8)) >> 15)
                +
                (mulss(tmpi, Q15(0.2)) >> 15)
                );
        inv.sum = 0;
        InvV = mulss(inv.V, Adj_InvV) >> 14; //30844
        inv.rms_stat = CALCULATION_DONE;
    }

    //main current part
    if (mcurr.rms_stat == READY_TO_CALCULATE)
    {
        mcurr.sum /= mcurr.size;
        tmpi = Root(mcurr.sum);
        mcurr.V = (
                (mulss(mcurr.V, Q15(0.8)) >> 15)
                +
                (mulss(tmpi, Q15(0.2)) >> 15)
                );
        mcurr.sum = 0;
        ACInI = mulss(mcurr.V, Adj_ACInI) >> 14; //30844
        mcurr.rms_stat = CALCULATION_DONE;
    }

    //main voltage part
    if (m.rms_stat == READY_TO_CALCULATE)
    {
        m.sum /= m.size;
        tmpi = Root(m.sum);
        m.V = (
                (mulss(m.V, Q15(0.8)) >> 15)
                +
                (mulss(tmpi, Q15(0.2)) >> 15)
                );
        m.sum = 0;
        ACInV = mulss(m.V, Adj_ACInV) >> 15; //60225
        m.rms_stat = CALCULATION_DONE;
    }
}

