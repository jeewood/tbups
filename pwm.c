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
        if (ocurr.max < ocurr.cv)    //求最大值
        {
            ocurr.max = ocurr.cv;
            ocurr.max_idx = ocurr.cnt;
        }
        if (ocurr.min > ocurr.cv)    //求最小值
        {
            ocurr.min = ocurr.cv;
        }
    }

    //voltage part
    if (inv.rms_stat == READY_TO_COLLECT_DATA)
    {
        inv.sum += mulss(inv.cv, inv.cv);
        if (inv.max < inv.cv)    //求最大值
        {
            inv.max = inv.cv;
            inv.max_idx = inv.cnt;
        }
        if (inv.min > inv.cv)    //求最小值
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

    if ((inv.idx == 0)) //50Hz切换方波产生
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
        if (mcurr.max < mcurr.cv)    //求最大值
        {
            mcurr.max = mcurr.cv;
            mcurr.max_idx = mcurr.cnt;
        }
        if (mcurr.min > mcurr.cv)    //求最小值
        {
            mcurr.min = mcurr.cv;
        }
    }

    //voltage part
    if (m.rms_stat == READY_TO_COLLECT_DATA)
    {
        m.sum += mulss(m.cv, m.cv);
        if (m.max < m.cv)    //求最大值
        {
            m.max = m.cv;
            m.max_idx = m.cnt;
        }
        if (m.min > m.cv)    //求最小值
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

                    if ((inv.state == OK))  //逆变状态正常
                    {
                        if (jabs(PD3 - PD2) < 50)   //频率同步处理
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
                                    // ADON ： A/D 工作模式位
                                    // 1 = A/D 转换器模块在工作
                                    // 0 = A/D 转换器关闭    
    ADCONbits.ADSIDL = 0;
                                    // ADSIDL：  在空闲模式下停止位
                                    // 1 = 当器件进入空闲模式时，模块停止工作
                                    // 0 = 在空闲模式下模块继续工作    
    ADCONbits.SLOWCLK = 1; 
                                    // SLOWCLK：低频时钟分频比使能位
                                    // 1 =  使用针对低频ADC输入时钟的时钟分频比。
                                    //      此分频比提供低分频比用来在较慢的输入时钟下获得
                                    //      速度最快的ADC操作。
                                    // 0 =  使用针对高频ADC输入时钟的时钟分频比。
                                    //      此分频比提供高分频比。     
    ADCONbits.FORM = 0;             
                                    // FORM ：数据输出格式位
                                    // 1 = 小数（DOUT =  dddd dddd dd00 0000）
                                    // 0 = 整数（DOUT = 0000 00dd dddd dddd）   
    ADCONbits.EIE = 1;              // Disable Early Interrupt ,此处禁用AD中断,使其通过PWM来触发中断
                                    // EIE：提前中断允许位
                                    // 1 = 在第一次转换完成后产生中断
                                    // 0 = 在第二次转换完成后产生中断    
    ADCONbits.ORDER = 0;            
                                    // ORDER：转换顺序位
                                    // 1 = 先转换奇数编号的模拟输入，然后转换偶数编号的输入
                                    // 0 = 先转换偶数编号的模拟输入，然后转换奇数编号的输入 
    ADCONbits.SEQSAMP = 0;          
                                    // SEQSAMP ：顺序采样使能位
                                    // 1 = 如果ORDER =0，在第二次转换开始时对共用采样/ 保持（S&H）
                                    // 电路进行采样。如果ORDER =  1，则在第一次转换开始时对共用S&H
                                    // 电路进行采样。
                                    // 0 = 如果在现有转换过程中共用S&H不处于忙状态，则在采样专用
                                    // S&H的同时对共用S&H进行采样。
                                    // 如果在采样专用S&H时共用S&H处于忙状态，则在新转换周期开始时
                                    // 对共用S&H进行采样。  
    ADCONbits.ASYNCSAMP = 1;
                                    // ASYNCSAMP：异步专用S&H采样使能位
                                    // 1 = 专用S&H在不断采样，一经检测到触发脉冲即终止采样。 
                                    // 0 = 当检测到触发事件时专用S&H开始采样，并在两个ADC时钟周期内
                                    // 完成采样过程。  
    ADCONbits.ADCS = 5;             // Clock Divider is set up for Fadc/6 
                                    // TAD=41.66ns
                                    // For simultaneus sampling total conversion time for one pair is 0.625us 
                                    // ADCS < 2:0>：A/D 转换时钟分频值选择位
                                    // 如果SLOWCLK = 0，ADC时钟分频值如下：
                                    // 111  = FADC/7 
                                    // 110  = FADC/6.5 
                                    // 101  = FADC/6 
                                    // 100  = FADC/5.5 
                                    // 011  = FADC/5 （默认）
                                    // 010  = FADC/4.5 
                                    // 001  = FADC/4 
                                    // 000  = FADC/3.5 
                                    // 如果SLOWCLK = 1，ADC时钟分频值如下：
                                    // 111  = FADC/8
                                    // 110  = FADC/7
                                    // 101  = FADC/6
                                    // 100  = FADC/5
                                    // 011  = FADC/4 （默认）
                                    // 010  = FADC/3
                                    // 001  = FADC/2
                                    // 000  = FADC/1    
    ADSTAT = 0;                     // Clear the ADSTAT register 
                                    // ADSTAT ：A/D 状态寄存器
                                    // bit 15-7 未实现：读为0
                                    // bit 6 P6RDY：输入对6 转换数据就绪位
                                    // 当缓冲区中数据就绪时此位被置1，当写入0 时此位被清零。
                                    // bit 5 P5RDY：输入对5 转换数据就绪位
                                    // 当缓冲区中数据就绪时此位被置1，当写入0 时此位被清零。
                                    // bit 4 P4RDY：输入对4 转换数据就绪位
                                    // 当缓冲区中数据就绪时此位被置1，当写入0 时此位被清零。
                                    // bit 3 P3RDY：输入对3 转换数据就绪位
                                    // 当缓冲区中数据就绪时此位被置1，当写入0 时此位被清零。
                                    // bit 2 P2RDY：输入对2 转换数据就绪位
                                    // 当缓冲区中数据就绪时此位被置1，当写入0 时此位被清零。
                                    // bit 1 P1RDY：  输入对1 转换数据就绪位
                                    // 当缓冲区中数据就绪时此位被置1，当写入0 时此位被清零。
                                    // bit 0 P0RDY：  输入对0 转换数据就绪位
                                    // 当缓冲区中数据就绪时此位被置1，当写入0 时此位被清零。


    IPC3bits.ADIP = 1;
    IFS0bits.ADIF = 0;
    IEC0bits.ADIE = 1;

    // ADPCFG：A/D 端口配置寄存器   ADC configuration for Full-Bridge Inverter 
    _PCFG0 = 0;           // AN0 逆变电流 
    _PCFG1 = 0;           // AN1 逆变电压

    _TRGSRC0 = 5;         // AN0 and AN1 被PWM2触发
                                    // TRGSRC0 < 4:0>：触发0 触发源选择位
                                    // 为模拟通道AN1 和AN0 的转换选择触发源。
                                    // 00000  = 不使能转换
                                    // 00001  = 选择独立软件触发
                                    // 00010  = 选择全局软件触发
                                    // 00011  = 选择PWM 特殊事件触发
                                    // 00100  = 选择PWM 发生器1 主触发
                                    // 00101  = 选择PWM 发生器2 主触发
                                    // 00110  = 选择PWM 发生器3 主触发
                                    // 00111  = 选择PWM 发生器4 主触发
                                    // 01000  = 保留
                                    // 01100  = Timer1 周期匹配
                                    // 01101  = 保留
                                    // 01110  = 选择PWM 发生器1 辅助触发
                                    // 01111  = 选择PWM 发生器2 辅助触发
                                    // 10000  = 选择PWM 发生器3 辅助触发
                                    // 10001  = 选择PWM 发生器4 辅助触发
                                    // 10010  = 保留
                                    // 10110  = 保留
                                    // 10111  = PWM 发生器1 限流ADC触发
                                    // 11000  = PWM 发生器2 限流ADC触发
                                    // 11001  = PWM 发生器3 限流ADC触发
                                    // 11010  = PWM 发生器4 限流ADC触发
                                    // 11011  = 保留
                                    // 11111  = Timer2 周期匹配     
    _IRQEN0 = 1;          // Global ADC interrupt not requested 
                                    // IRQEN0 ：  中断请求允许0 位
                                    // 1 = 当通道AN1 和AN0 上请求的转换完成时允许产生中断请求
                                    // 0 = 不产生中断请求
    //IPC27bits.ADCP0IP = 7;        // Set ADC Interrupt Priority 
    //IFS6bits.ADCP0IF = 0;         // Clear AD Interrupt Flag 
    //IEC6bits.ADCP0IE = 1;         // Enable the ADC Interrupt at start. 
    //End of ADC configuration for ACInput 

    _PCFG2 = 0;           // AN2 输入交流电压
    _PCFG3 = 0;           // AN3 输入交流电流

    _TRGSRC1 = 6;         // AN0 and AN1 triggered by PWM3 
    _IRQEN1 = 1;          // Global ADC interrupt not requested 
    //IPC27bits.ADCP1IP = 7;        // Set ADC Interrupt Priority 
    //IFS6bits.ADCP1IF = 0;         // Clear AD Interrupt Flag 
    //IEC6bits.ADCP1IE = 1;         // Enable the ADC Interrupt at start. 


    //母线/电池电压   母线电流    
    _PCFG10 = 0;                    //ADPCFGbits.PCFG10 = 0; // AN10 DC_Curr 母线电流
    _PCFG11 = 0;                    //ADPCFGbits.PCFG11 = 0; // AN11 BUS_V 母线电压(电池电压?)

    _TRGSRC5 = 1;                   // AN10 and AN11 triggered by PWM3 辅助触发
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
    PWMCON1bits.ITB     = 1;    // ITB ：独立时基模式位
                                // 1 = PHASEx/SPHASEx 寄存器为此PWM 发生器提供时基周期
                                // 0 = PTPER 寄存器为此PWM 发生器提供时序
    PWMCON1bits.DTC     = 0;    // DTC < 1:0>：死区控制位
                                // 00 = 对于所有输出模式施加正死区
                                // 01 = 对于所有输出模式施加负死区
                                // 10 = 禁止死区功能
                                // 11 = 保留
    PWMCON1bits.CAM     = 1;    // CAM
                                // 1 = 使能中心对齐模式
                                // 0 = 禁止中心对齐模式        
    IOCON1bits.PENH     = 1;    // PENH:PWMH 输出引脚所有权位
                                // 1 = 由PWM 模块控制PWMxH 引脚
                                // 0 = 由GPIO模块控制PWMxH 引脚
    IOCON1bits.PENL     = 1;    // PENL：PWML 输出引脚所有权位
                                // 1 = 由PWM 模块控制PWMxL 引脚
                                // 0 = 由GPIO模块控制PWMxL 引脚

    IOCON1bits.PMOD     = 0;    // PMOD < 1:0>：PWM I/O引脚模式位
                                // 00 = PWM I/O 引脚对处于互补输出模式
                                // 01 = PWM I/O 引脚对处于冗余输出模式
                                // 10 = PWM I/O 引脚对处于推挽输出模式
                                // 11 = PWM I/O 引脚对处于真正独立PWM 输出模式     
    IOCON1bits.OVRDAT   = 0;  // OVRDAT < 1:0>：使能改写时PWMxH 和PWMxL 引脚的数据位
                                // 如果OVERENH = 1，则OVRDAT < 1> 为PWMxH 提供数据。
                                // 如果OVERENL =  1，则OVRDAT < 0> 为PWMxL 提供数据。    
    IOCON1bits.OVRENH   = 1;    // OVRENH：    PWMxH 引脚改写使能位
                                // 1 = OVRDAT < 1> 为PWMxH 引脚提供输出数据
                                // 0 =  由PWM 发生器为PWMxH 引脚提供数据
    IOCON1bits.OVRENL   = 1;  // OVRENL：   PWMxL 引脚改写使能位
                                // 1 = OVRDAT < 0> 为PWMxL 引脚提供输出数据
                                // 0 = 由PWM 发生器为PWMxL 引脚提供数据
                                
    ALTDTR1             = 0;                    //ALTDTRx < 13:0>：PWMx 死区单元的无符号14位死区值位
    PHASE1              = TriPDX;       // PHASEx < 15:0>：此PWM发生器的 PWM相移值或独立时基周期位
    PDC1                = TriPDX>>1;    // PDCx < 15:0> ：PWM 发生器x 占空比值位
    TRIG1               = TriPDX>>1;    // TRGCMP < 15:3>：触发器控制值位
                                // 当主PWM 工作在本地时基时，此寄存器包含比较值，
                                // 可以触发ADC模块。
    STRIG1              = 256;    //STRGCMP < 15:3>：辅助触发器控制值位
                                //当辅助PWM 工作在本地时基时，此寄存器包含比较值，
                                //可以触发ADC模块。

    TRGCON1bits.DTM     = 1;    // DTM：双触发器模式位
                                // 1 = 辅助触发事件和主触发事件一起产生PWM 触发信号。
                                // 0 = 辅助触发事件不同主触发事件一起产生PWM 触发信号。
                                // 而是产生两个独立的PWM 触发信号。
    TRGCON1bits.TRGDIV  = 1;    // TRGDIV < 3:0>：触发信号输出分频比位
                                // 0000 = 每个触发事件输出一次触发信号
                                // 0001 = 每2 个触发事件输出一次触发信号
                                // 0010 = 每3 个触发事件输出一次触发信号
                                // 0011 = 每4 个触发事件输出一次触发信号
                                // 0100 = 每5 个触发事件输出一次触发信号
                                // 0101 = 每6 个触发事件输出一次触发信号
                                // 0110 = 每7 个触发事件输出一次触发信号
                                // 0111 = 每8 个触发事件输出一次触发信号
                                // 1000 = 每9 个触发事件输出一次触发信号
                                // 1001 = 每10个触发事件输出一次触发信号
                                // 1010 = 每11个触发事件输出一次触发信号
                                // 1011 = 每12个触发事件输出一次触发信号
                                // 1100 = 每13个触发事件输出一次触发信号
                                // 1101 = 每14个触发事件输出一次触发信号
                                // 1110 = 每15个触发事件输出一次触发信号
                                // 1111 = 每16个触发事件输出一次触发信号
    TRGCON1bits.TRGSTRT = 0;    // TRGSTRT < 5:0>：触发器后分频比启动使能选择位
                                // 000000 = 在模块使能后等待0 个PWM 周期产生第一个触发事件
                                // 000001 = 在模块使能后等待1 个PWM 周期产生第一个触发事件
                                // 000010 = 在模块使能后等待1 个PWM 周期产生第一个触发事件
    FCLCON1             = 0x0003;       // FLTMOD < 1:0> ：PWM 发生器x 的故障模式位
                                // 00 = 所选故障源强制PWMxH 和PWMxL 引脚为FLTDAT 值（锁定模式）
                                // 01 = 所选故障源强制PWMxH 和PWMxL 引脚为FLTDAT 值（周期模式）
                                // 10 = 保留
                                // 11 = 禁止故障输入                    
                                
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

