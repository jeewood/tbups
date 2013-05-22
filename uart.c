/*****************************************************************  
 ** ¹¦ÄÜÃèÊö: ´®ÐÐÍ¨Ñ¶³ÌÐò£¬DSPÖÐ¶ÏÊÕµ½8¸öÊý¾Ýºó£¬½«ÊÕµ½µÄ8¸öÊý¾Ý    **
 ** ÒÔÖÐ¶Ï·¢ËÍ·½Ê½·µËÍ»Ø·¢ËÍ·½¡£                                   **
 *************************************************************** */
#include <p33fj16gs504.h>                //ds30f6014Í·ÎÄ¼þ   
#include "define.h"
#include "data_struct.h"
#include "i2c.h"

unsigned char rsBuf[68]; // ½ÓÊÕÊý¾ÝÊý×é
//unsigned char SndBuf[32];            // ·¢ËÍÊý¾ÝÊý×é   
unsigned char RcvCnt = 0; // ½ÓÊÕÊý¾Ý¸öÊý¼ÆÊý
unsigned char SndCnt = 0; // ·¢ËÍÊý¾Ý¸öÊý¼ÆÊý
unsigned char SndPosi = 0; // ·¢ËÍÊý¾Ý¸öÊý¼ÆÊý
unsigned char Rcved; // £½1£¬½ÓÊÕµ½8¸öÊý¾Ý
unsigned int CET = 0;
void Sender();

void jmemcpy(unsigned char* s, unsigned char * d, unsigned int ls)
{
    while (ls--) *d++ = *s++;
}

/*****************************************************************  
 ** º¯ÊýÃû: Uart_Initial()                                       **
 ** ¹¦ÄÜÃèÊö: 232´®ÐÐÍ¨Ñ¶³õÊ¼»¯×Ó³ÌÐò£¬ÉèÖÃÖÐ¶ÏÓÅÏÈ¼¶            **
 *************************************************************** */
void initUart()
{

    //IPC2bits.U1RXIP=1;          //ÊÕÖÐ¶ÏÓÅÏÈ¼¶£º1¼¶
    //IPC3bits.U1TXIP=1;

    U1MODEbits.UARTEN = 1;
    //U1MODEbits.UEN = 3;
    //U1MODE=0x8000;              //UARTÊ¹ÄÜ£¬8Î»Êý¾Ý£¬ÎÞÆæÅ¼Ð£Ñé
    U1MODEbits.PDSEL = 2; //8Î»Êý¾ÝÎ»£¬ÆæÐ£Ñé
    U1MODEbits.STSEL = 0; //8Î»Êý¾ÝÎ»£¬ÆæÐ£Ñé

    U1STA = 0x0000; //µ±Ò»¸ö×Ö·û±»´«Êäµ½·¢ËÍÒÆÎ»¼Ä´æÆ÷£¨·¢ËÍ»º³åÆ÷ÖÐ
    //ÖÁÉÙ»¹ÓÐÒ»¸ö×Ö·û£©²úÉúÖÐ¶Ï£¬µ±½ÓÊÕµ½Ò»¸ö×Ö·ûÊ±£¬
    //ÖÐ¶Ï±êÖ¾Î»ÖÃÎ»
    //U1STAbits.UTXINV = 1;		//·¢ËÍ¼«ÐÔ£¬UxTX¿ÕÏÐÎª1
    U1BRG = 0x102; //U1BRG=Fcy/(16*²¨ÌØÂÊ)-1£¬´Ë´¦²¨ÌØÂÊÎª9600
    IEC0bits.U1RXIE = 1; //UART1½ÓÊÕºÍ·¢ËÍÖÐ¶ÏÊ¹ÄÜ
    IEC0bits.U1TXIE = 1;

    U1STAbits.URXISEL = 0; // Interrupt after one RX character is received;
    U1STAbits.UTXISEL1 = 0;
    U1STAbits.UTXISEL0 = 1;

    RPOR8bits.RP16R = 3; //RP16=TXD
    RPINR18bits.U1RXR = 29; //RP29=RXD

    RcvCnt = 0;
    SndCnt = 0;
}

/*
uart drivers
*/
void UART_DRV(void)
{
    if (CET > 500)
    {
        Rcved = 1;
        CET = 0;
    }
    else if (CET > 0)
    {
        CET++;
    }
}

/* ****************************************************************  
 ** º¯ Êý Ãû: __attribute__((__interrupt__)) _U1RXInterrupt()
 ** ¹¦ÄÜÃèÊö: ÖÐ¶Ï×Ó³ÌÐò£º232½ÓÊÕÖÐ¶Ï
 *************************************************************** */
void __attribute__((interrupt, no_auto_psv)) _U1RXInterrupt()
{
    IFS0bits.U1RXIF = 0;
    unsigned int ch;
    CET = 1;
    while (U1STAbits.URXDA)
    {
        ch = U1RXREG;
        if (RcvCnt > 0 && RcvCnt < 64)
        {
            rsBuf[RcvCnt++] = ch;
        }
        else if (ch == ModbusSA || ch == 2)
        {
            rsBuf[RcvCnt++] = ch;
        }
        else
        {
            RcvCnt = 0;
        }
    }
}

/* ****************************************************************  
 ** º¯ Êý Ãû: __attribute__((__interrupt__)) _U1TXInterrupt()
 ** ¹¦ÄÜÃèÊö: ÖÐ¶Ï×Ó³ÌÐò£º232·¢ËÍÖÐ¶Ï
 *************************************************************** */
void __attribute__((interrupt, no_auto_psv)) _U1TXInterrupt()
{
    IFS0bits.U1TXIF = 0;
    if (SndPosi >= SndCnt || SndPosi >= 64) //Èç¹û·¢ËÍÊý¾Ý¸öÊý´óÓÚ7
    {
        SndCnt = 0; //·¢ËÍÊý¾Ý¸öÊýÇåÁã
        U1STAbits.UTXEN = 0; //ÒÑ¾­·¢ËÍµ½×îºóÒ»¸öÊý£¬·¢ËÍ²»Ê¹ÄÜ
        LED = ~LED;
    }
    else
    {
        //SndPosi++;                   // ·ñÔò£¬·¢ËÍ¼ÆÊýÆ÷¼Ó1 */
        U1TXREG = rsBuf[SndPosi++];
    }
}

void Sender()
{
    if (SndCnt)
    {
        U1STAbits.UTXEN = 1; // Ê¹ÄÜ·¢ËÍ
        SndPosi = 0;
        U1TXREG = rsBuf[SndPosi++]; //ÏÈ·¢ËÍµÚÒ»¸öÊý¾Ý
    }
}

const unsigned int CRC16Table[] =
{
    0x0000, 0xCC01, 0xD801, 0x1400, 0xF001, 0x3C00, 0x2800, 0xE401,
    0xA001, 0x6C00, 0x7800, 0xB401, 0x5000, 0x9C01, 0x8801, 0x4400
};

unsigned int crc16(unsigned char* buf, unsigned char len)
{
    unsigned int CRC = 0xFFFF;
    unsigned char i;
    unsigned char ch;

    for (i = 0; i < len; i++)
    {
        ch = *buf++;
        CRC = CRC16Table[(ch ^ CRC) & 15] ^ (CRC >> 4);
        CRC = CRC16Table[((ch >> 4) ^ CRC) & 15] ^ (CRC >> 4);
    }

    return CRC;
}

unsigned int swap(unsigned int i)
{
    return (i << 8) | (i >> 8);
}

unsigned int MakeInt(unsigned char h, unsigned char l)
{
    unsigned int ti = h;
    return (ti << 8 | l);
}

/*
modbus slave function 1
*/
unsigned char MSFunc1(int addr, int len)
{
    if (addr < 8 && addr + len <= 8)
    {
        rsBuf[2] = 1;
        rsBuf[3] = (((*(unsigned char*) &ControlBits) << addr) & (unsigned char) (0xFF << (8 - len)));
        return 4;
    }
    return 0;
}

/*
modbus slave function 5
*/
unsigned char MSFunc5(int addr, int len)
{
    if (addr < 8)
    {
        if (len)
        {
            *(unsigned char*) &ControlBits |= (1 << (addr));
        }
        else
        {
            *(unsigned char*) &ControlBits &= ~(1 << (addr));
        }
        return 6;
    }
    return 0;
}

/*
modbus slave function 3
*/
unsigned char MSFunc3(int addr, int len)
{
    unsigned char i;

    rsBuf[2] = len * 2;

    if (addr < 14 && addr + len <= 14)
    {
        for (i = 0; i < rsBuf[2]; i += 2)
        {
            rsBuf[i + 3] = Value[i / 2 + addr].h;
            rsBuf[i + 4] = Value[i / 2 + addr].l;
        }
        return rsBuf[2] + 3;
    }
    else if (addr >= 0x4000 && addr + len <= 0x4020)
    {
        addr -= 0x4000;
        addr %= 0x23;
        if (!i2cReadStr(addr * 2, (unsigned char*) sValue, 44)) return 0;
        for (i = 0; i < rsBuf[2]; i += 2)
        {
            rsBuf[i + 3] = sValue[i / 2 + addr].h;
            rsBuf[i + 4] = sValue[i / 2 + addr].l;
        }
        return rsBuf[2] + 3;
    }
    return 0;
}

/*
modbus slave function 6
*/
unsigned char MSFunc6(int addr, int value)
{
    unsigned long t; unsigned int ti;
    if (addr>= 0x4000)
    {
        addr -= 0x4000;
        if (addr < 12)
        {
            t = value;
            if (Value[addr].x)
            {
                ti = divud((t<<15),Value[addr].x);
                sValue[addr].x = muluu(ti,sValue[addr].x)>>15;
            }
        }
        else if (addr < 24)
        {
            sValue[addr].x = value;
        }
        //i2cWrite((addr)*2,(unsigned char*)&sValue[addr]);
        i2cWriteStr((addr)*2,(unsigned char*)&sValue[addr].x, 2);
        return 6;
    }
    return 0;
}

/*
modbus slave function 0x10
*/
unsigned char MSFunc16(int addr, int len)
{
    unsigned char i;
    if (addr >= 0x4000 && addr + len < 0x4020)
    {
        addr -= 0x4000;
        for (i = 0; i < rsBuf[6]; i += 2)
        {
            sValue[addr + i / 2].h = rsBuf[i + 7];
            sValue[addr + i / 2].l = rsBuf[i + 8];
        }
        if (i2cWriteStr(addr * 2, (unsigned char*) &sValue, rsBuf[6]))
            return 6;
    }
    return 0;
}

/*
modbus slave main function
*/
void ModbusSlave()
{
    INT crc;
    if (1 == Rcved)
    {
        Rcved = 0;

        if (crc16(rsBuf, RcvCnt) == 0)
        {
            INT Addr, Len;
            Addr.h = rsBuf[2];
            Addr.l = rsBuf[3];
            Len.h = rsBuf[4];
            Len.l = rsBuf[5];
            switch (rsBuf[1])
            {
                case 1:case 2:
                    SndCnt = MSFunc1(Addr.x, Len.x);
                    break;
                case 3:case 4:
                    SndCnt = MSFunc3(Addr.x, Len.x);
                    break;
                case 5:
                    SndCnt = MSFunc5(Addr.x, Len.x);
                    break;
                case 6:
                    SndCnt = MSFunc6(Addr.x, Len.x);
                    break;
                case 15: break;
                case 16:
                    SndCnt = MSFunc16(Addr.x, Len.x);
                    break;
            }
        }

        if (SndCnt)
        {
            crc.x = crc16(rsBuf, SndCnt);
            rsBuf[SndCnt++] = crc.l;
            rsBuf[SndCnt++] = crc.h;
        }

        RcvCnt = 0;
        Sender();
    }
}
