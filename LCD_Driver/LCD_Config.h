
#include <p33fj16gs504.h> 

#define Dis_X_MAX		128-1
#define Dis_Y_MAX		64-1

//Define the MCU Register
#define LCD_Pin_Init TRISCbits.TRISC3 = 0;TRISCbits.TRISC6 = 0;TRISCbits.TRISC5 = 0; TRISCbits.TRISC4 = 0

#define SPI_CS  LATCbits.LATC3
#define SPI_SDA LATCbits.LATC6
#define SPI_SCK LATCbits.LATC5
#define SPI_RES LATCbits.LATC4
/*
sbit SPI_CS = P1^0;				//定义CS接在P1.0端口
sbit SPI_SDA = P1^1;			//定义SDA接在P1.1端口
sbit SPI_SCK = P1^2;			//定义SCK接在P1.2端口
sbit SPI_RES = P1^3;			//定义RESET接P1.3端口
*/

#define KEY_Pin_Init TRISCbits.TRISC8 = 1;TRISBbits.TRISB8 = 1;TRISBbits.TRISB15 = 1; TRISBbits.TRISB5 = 1

#define KEY_ESC PORTCbits.RC8
#define KEY_ENTER PORTBbits.RB8
#define KEY_UP PORTBbits.RB15
#define KEY_DOWN PORTBbits.RB5
