#include "p33fj16gs504.h"
#include "i2c.h"

#define SCL         PORTBbits.RB15      //I2C Clock PORTB pin 15
#define SDA         PORTBbits.RB5       //I2C Data PORTB pin 5
#define SCL_TRIS    TRISBbits.TRISB15   //SDA Tris bit
#define SDA_TRIS    TRISBbits.TRISB5    //SDA Tris bit
#define CONTROLBYTE 0b10100000          // Control byte
#define ACKBIT      0x00                // ACK bit
#define NAKBIT      0x80                // NAK bit

#define NOP() {int i;for(i=0;i<50;i++) Nop();}
#define SDA_LOW(b) SDA_TRIS=0;SDA=0;if(b)NOP()
#define SDA_HIGH(b) SDA_TRIS=1;SDA=1;if(b)NOP()
#define SCL_LOW(b) SCL_TRIS=0;SCL=0;if(b)NOP()
#define SCL_HIGH(b) SCL_TRIS=0;SCL=1;if(b)NOP()
#define SDAR(b) SDA_TRIS=1;ODCBbits.ODCB5=1;if(b)NOP()

//这是I2C
void InitI2C(void)
{
    SCL_LOW(0);
    SDAR(0);
}

//A ^^\______
//L ^^^^\____
void start(void)
{
    //SCL_LOW(0);
    SDA_HIGH(1);                    // Ensure SDA is high (为输入)
    SCL_HIGH(1);                    // Ensure SCL is high
    SDA_LOW(1);                 // Configure SDA as an output,Ensure SDA low
    SCL_LOW(1);
    //SDAR(0);
}

//A ___/^^^^^^
//L _/^^^\____
void stop(void)
{
    SDA_LOW(1);                 // Configure SDA as an output,Ensure SDA low
    SCL_HIGH(1);                    // Pull SCL high
    SDA_HIGH(1);                    // Allow SDA to be pulled high
    SDAR(0);    //release SDA line
}

//A ^^^\___
//L _/^^^\_
char chkack(void)
{
    unsigned char i = 0;
    SCL_LOW(0);
    SDAR(0);                            //release SDA for input, is high
    SCL_HIGH(1);
    i = SDA;
    SCL_LOW(1);
    SDA_HIGH(0);
    return i;
}

//A---_______
//L~~~~~\____
void ack(void)
{
    SDA_LOW(1);
    SCL_HIGH(1);
    SCL_LOW(1);
    //SDA_HIGH(0);
}

//A~~~~~~~~~~
//L~~~\______
void noack(void)
{
    SDA_HIGH(1);
    SCL_HIGH(1);
    SCL_LOW(1);
}
//A -[---]-
//L __/^\__
void write_byte(unsigned char byte)
{
    unsigned char i;
    SCL_LOW(1);
    for (i = 0; i < 8; i++)
    {
        if ((byte << i) & 0x80)
        {
            SDA_HIGH(1);
        }
        else
        {
            SDA_LOW(1);
        }
        SCL_HIGH(1);
        SCL_LOW(1);
    }
}

//A -[--]--[--]--[--]--[--]--[--]--[--]--
//L __/^^\__/^^\__/^^\__/^^\__/^^\__/^^\__
unsigned char read_byte(void)
{
    unsigned char i, k = 0;
    SDAR(0);                    //release SDA for input, is high
    SCL_LOW(1);
    for (i = 0; i < 8; i++)
    {
        SCL_HIGH(1);
        k = (k << 1); //|SDA;
        if (SDA) k = k + 1;
        SCL_LOW(1);
    }
    return k;
}


char i2cWrite(unsigned char addr, unsigned char byte)
{
    start();
    write_byte(0xA0);
    if (chkack()) return 0;
    write_byte(addr);
    if (chkack()) return 0;
    write_byte(byte);
    stop();
    return 1;
}

//Means writing with array
char i2cWriteStr(unsigned char addr, unsigned char *buf, unsigned char len)
{
    unsigned char i;
    start();
    write_byte(0xA0);
    if (chkack()) return 0;
    write_byte(addr);
    if (chkack()) return 0;
    for (i = 0; i < len; i++)
    {
        write_byte(*buf);
        if (chkack()) return 0;
        buf++;
    }
    stop();
    return 1;
}

char i2cRead(unsigned char addr, unsigned char* c)
{
    start();
    write_byte(0xA0);
    if (chkack())return 0;
    write_byte(addr);
    if (chkack()) return 0;
    //stop();
    start();
    write_byte(0xA1);
    if (chkack()) return 0;
    *c = read_byte();
    noack();
    stop();
    return 1;
}

//Means reading with array
char i2cReadStr(unsigned char addr, unsigned char *buf, unsigned char len)
{
    unsigned char i;
    start();
    write_byte(0xA0);
    if (chkack()) return 0;
    write_byte(addr);
    if (chkack()) return 0;
    start();
    write_byte(0xA1);
    if (chkack()) return 0;
    for (i = 0; i < len - 1; i++)
    {
        *buf = read_byte();
        ack();
        buf++;
    }
    *buf = read_byte();
    noack();
    stop();
    return 1;
}



