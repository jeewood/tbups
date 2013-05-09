#include <p33fj16gs504.h>

void initClock(void)
{
    /* Configure Oscillator to operate the device at 40 MIPS
       Fosc= Fin*M/(N1*N2), Fcy=Fosc/2
       Fosc= 7.37*(43)/(2*2)=80Mhz for Fosc, Fcy = 40Mhz */

    /* Configure PLL prescaler, PLL postscaler, PLL divisor */
    /* When using FRC or 7.37MHz crystal */
    PLLFBD = 41;                            /* M = PLLFBD + 2 */
    CLKDIVbits.PLLPOST = 0;                 /* N1 = 2 */
    CLKDIVbits.PLLPRE = 0;                  /* N2 = 2 */

    /* Change oscillator to FRC + PLL */
    __builtin_write_OSCCONH(0x01);          /* New Oscillator FRC w/ PLL */
    __builtin_write_OSCCONL(0x01);          /* Enable Clock Switch */

    while (OSCCONbits.COSC != 0b001);        /* Wait for new Oscillator to
                                               become FRC w/ PLL */
    while (OSCCONbits.LOCK != 1);           /* Wait for Pll to Lock */

    /* Now setup the ADC and PWM clock for 120MHz
       ((FRC * 16) / APSTSCLR ) = (7.37 * 16) / 1 = ~ 120MHz*/

    ACLKCONbits.FRCSEL = 1;                 /* FRC provides input for
                                               Auxiliary PLL (x16) */
    ACLKCONbits.SELACLK = 1;                /* Auxiliary Ocillator provides
                                               clock source for PWM & ADC */
    ACLKCONbits.APSTSCLR = 7;               /* Divide Auxiliary clock by 1 */
    ACLKCONbits.ENAPLL = 1;                 /* Enable Auxiliary PLL */

    while (ACLKCONbits.APLLCK != 1);        /* Wait for Aux. PLL to Lock */


}

