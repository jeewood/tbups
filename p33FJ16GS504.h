/*-------------------------------------------------------------------------
 * MPLAB-Cxx  dsPIC33FJ16GS504 processor header
 *
 * (c) Copyright 1999-2011 Microchip Technology, All rights reserved
 *-------------------------------------------------------------------------*/

#ifndef __dsPIC33FJ16GS504__
#error "Include file does not match processor setting"
#endif

#ifndef __33FJ16GS504_H
#define __33FJ16GS504_H

extern volatile unsigned int  WREG0 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int  WREG1 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int  WREG2 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int  WREG3 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int  WREG4 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int  WREG5 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int  WREG6 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int  WREG7 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int  WREG8 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int  WREG9 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int  WREG10 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int  WREG11 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int  WREG12 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int  WREG13 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int  WREG14 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int  WREG15 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int  SPLIM __attribute__((__sfr__));
extern volatile unsigned int  ACCAL __attribute__((__sfr__));
extern volatile unsigned int  ACCAH __attribute__((__sfr__));
extern volatile unsigned char ACCAU __attribute__((__sfr__));
extern volatile unsigned int  ACCBL __attribute__((__sfr__));
extern volatile unsigned int  ACCBH __attribute__((__sfr__));
extern volatile unsigned char ACCBU __attribute__((__sfr__));
extern volatile unsigned int  PCL __attribute__((__sfr__));
extern volatile unsigned char PCH __attribute__((__sfr__));
extern volatile unsigned char TBLPAG __attribute__((__sfr__));
extern volatile unsigned char PSVPAG __attribute__((__sfr__));
extern volatile unsigned int  RCOUNT __attribute__((__sfr__));
extern volatile unsigned int  DCOUNT __attribute__((__sfr__));
extern volatile unsigned int  DOSTARTL __attribute__((__sfr__));
extern volatile unsigned int  DOSTARTH __attribute__((__sfr__));
extern volatile unsigned int  DOENDL __attribute__((__sfr__));
extern volatile unsigned int  DOENDH __attribute__((__sfr__));
extern volatile unsigned int  SR __attribute__((__sfr__));
__extension__ typedef struct tagSRBITS {
  union {
    struct {
      unsigned C:1;
      unsigned Z:1;
      unsigned OV:1;
      unsigned N:1;
      unsigned RA:1;
      unsigned IPL:3;
      unsigned DC:1;
      unsigned DA:1;
      unsigned SAB:1;
      unsigned OAB:1;
      unsigned SB:1;
      unsigned SA:1;
      unsigned OB:1;
      unsigned OA:1;
    };
    struct {
      unsigned :5;
      unsigned IPL0:1;
      unsigned IPL1:1;
      unsigned IPL2:1;
    };
  };
} SRBITS;
extern volatile SRBITS SRbits __attribute__((__sfr__));

extern volatile unsigned int  CORCON __attribute__((__sfr__));
__extension__ typedef struct tagCORCONBITS {
  union {
    struct {
      unsigned IF:1;
      unsigned RND:1;
      unsigned PSV:1;
      unsigned IPL3:1;
      unsigned ACCSAT:1;
      unsigned SATDW:1;
      unsigned SATB:1;
      unsigned SATA:1;
      unsigned DL:3;
      unsigned EDT:1;
      unsigned US:1;
    };
    struct {
      unsigned :8;
      unsigned DL0:1;
      unsigned DL1:1;
      unsigned DL2:1;
    };
  };
} CORCONBITS;
extern volatile CORCONBITS CORCONbits __attribute__((__sfr__));

extern volatile unsigned int  MODCON __attribute__((__sfr__));
__extension__ typedef struct tagMODCONBITS {
  union {
    struct {
      unsigned XWM:4;
      unsigned YWM:4;
      unsigned BWM:4;
      unsigned :2;
      unsigned YMODEN:1;
      unsigned XMODEN:1;
    };
    struct {
      unsigned XWM0:1;
      unsigned XWM1:1;
      unsigned XWM2:1;
      unsigned XWM3:1;
      unsigned YWM0:1;
      unsigned YWM1:1;
      unsigned YWM2:1;
      unsigned YWM3:1;
      unsigned BWM0:1;
      unsigned BWM1:1;
      unsigned BWM2:1;
      unsigned BWM3:1;
    };
  };
} MODCONBITS;
extern volatile MODCONBITS MODCONbits __attribute__((__sfr__));

extern volatile unsigned int  XMODSRT __attribute__((__sfr__));
extern volatile unsigned int  XMODEND __attribute__((__sfr__));
extern volatile unsigned int  YMODSRT __attribute__((__sfr__));
extern volatile unsigned int  YMODEND __attribute__((__sfr__));
extern volatile unsigned int  XBREV __attribute__((__sfr__));
__extension__ typedef struct tagXBREVBITS {
  union {
    struct {
      unsigned XB:15;
      unsigned BREN:1;
    };
    struct {
      unsigned XB0:1;
      unsigned XB1:1;
      unsigned XB2:1;
      unsigned XB3:1;
      unsigned XB4:1;
      unsigned XB5:1;
      unsigned XB6:1;
      unsigned XB7:1;
      unsigned XB8:1;
      unsigned XB9:1;
      unsigned XB10:1;
      unsigned XB11:1;
      unsigned XB12:1;
      unsigned XB13:1;
      unsigned XB14:1;
    };
  };
} XBREVBITS;
extern volatile XBREVBITS XBREVbits __attribute__((__sfr__));

extern volatile unsigned int  DISICNT __attribute__((__sfr__));
extern volatile unsigned int  CNEN1 __attribute__((__sfr__));
typedef struct tagCNEN1BITS {
  unsigned CN0IE:1;
  unsigned CN1IE:1;
  unsigned CN2IE:1;
  unsigned CN3IE:1;
  unsigned CN4IE:1;
  unsigned CN5IE:1;
  unsigned CN6IE:1;
  unsigned CN7IE:1;
  unsigned CN8IE:1;
  unsigned CN9IE:1;
  unsigned CN10IE:1;
  unsigned CN11IE:1;
  unsigned CN12IE:1;
  unsigned CN13IE:1;
  unsigned CN14IE:1;
  unsigned CN15IE:1;
} CNEN1BITS;
extern volatile CNEN1BITS CNEN1bits __attribute__((__sfr__));

extern volatile unsigned int  CNEN2 __attribute__((__sfr__));
typedef struct tagCNEN2BITS {
  unsigned CN16IE:1;
  unsigned CN17IE:1;
  unsigned CN18IE:1;
  unsigned CN19IE:1;
  unsigned CN20IE:1;
  unsigned CN21IE:1;
  unsigned CN22IE:1;
  unsigned CN23IE:1;
  unsigned CN24IE:1;
  unsigned CN25IE:1;
  unsigned CN26IE:1;
  unsigned CN27IE:1;
  unsigned CN28IE:1;
  unsigned CN29IE:1;
} CNEN2BITS;
extern volatile CNEN2BITS CNEN2bits __attribute__((__sfr__));

extern volatile unsigned int  CNPU1 __attribute__((__sfr__));
typedef struct tagCNPU1BITS {
  unsigned CN0PUE:1;
  unsigned CN1PUE:1;
  unsigned CN2PUE:1;
  unsigned CN3PUE:1;
  unsigned CN4PUE:1;
  unsigned CN5PUE:1;
  unsigned CN6PUE:1;
  unsigned CN7PUE:1;
  unsigned CN8PUE:1;
  unsigned CN9PUE:1;
  unsigned CN10PUE:1;
  unsigned CN11PUE:1;
  unsigned CN12PUE:1;
  unsigned CN13PUE:1;
  unsigned CN14PUE:1;
  unsigned CN15PUE:1;
} CNPU1BITS;
extern volatile CNPU1BITS CNPU1bits __attribute__((__sfr__));

extern volatile unsigned int  CNPU2 __attribute__((__sfr__));
typedef struct tagCNPU2BITS {
  unsigned CN16PUE:1;
  unsigned CN17PUE:1;
  unsigned CN18PUE:1;
  unsigned CN19PUE:1;
  unsigned CN20PUE:1;
  unsigned CN21PUE:1;
  unsigned CN22PUE:1;
  unsigned CN23PUE:1;
  unsigned CN24PUE:1;
  unsigned CN25PUE:1;
  unsigned CN26PUE:1;
  unsigned CN27PUE:1;
  unsigned CN28PUE:1;
  unsigned CN29PUE:1;
} CNPU2BITS;
extern volatile CNPU2BITS CNPU2bits __attribute__((__sfr__));

extern volatile unsigned int  INTCON1 __attribute__((__sfr__));
typedef struct tagINTCON1BITS {
  unsigned :1;
  unsigned OSCFAIL:1;
  unsigned STKERR:1;
  unsigned ADDRERR:1;
  unsigned MATHERR:1;
  unsigned :1;
  unsigned DIV0ERR:1;
  unsigned SFTACERR:1;
  unsigned COVTE:1;
  unsigned OVBTE:1;
  unsigned OVATE:1;
  unsigned COVBERR:1;
  unsigned COVAERR:1;
  unsigned OVBERR:1;
  unsigned OVAERR:1;
  unsigned NSTDIS:1;
} INTCON1BITS;
extern volatile INTCON1BITS INTCON1bits __attribute__((__sfr__));

extern volatile unsigned int  INTCON2 __attribute__((__sfr__));
typedef struct tagINTCON2BITS {
  unsigned INT0EP:1;
  unsigned INT1EP:1;
  unsigned INT2EP:1;
  unsigned :11;
  unsigned DISI:1;
  unsigned ALTIVT:1;
} INTCON2BITS;
extern volatile INTCON2BITS INTCON2bits __attribute__((__sfr__));

extern volatile unsigned int  IFS0 __attribute__((__sfr__));
typedef struct tagIFS0BITS {
  unsigned INT0IF:1;
  unsigned IC1IF:1;
  unsigned OC1IF:1;
  unsigned T1IF:1;
  unsigned :1;
  unsigned IC2IF:1;
  unsigned OC2IF:1;
  unsigned T2IF:1;
  unsigned T3IF:1;
  unsigned SPI1EIF:1;
  unsigned SPI1IF:1;
  unsigned U1RXIF:1;
  unsigned U1TXIF:1;
  unsigned ADIF:1;
} IFS0BITS;
extern volatile IFS0BITS IFS0bits __attribute__((__sfr__));

extern volatile unsigned int  IFS1 __attribute__((__sfr__));
typedef struct tagIFS1BITS {
  unsigned SI2C1IF:1;
  unsigned MI2C1IF:1;
  unsigned AC1IF:1;
  unsigned CNIF:1;
  unsigned INT1IF:1;
  unsigned :8;
  unsigned INT2IF:1;
} IFS1BITS;
extern volatile IFS1BITS IFS1bits __attribute__((__sfr__));

extern volatile unsigned int  IFS3 __attribute__((__sfr__));
typedef struct tagIFS3BITS {
  unsigned :9;
  unsigned PSEMIF:1;
} IFS3BITS;
extern volatile IFS3BITS IFS3bits __attribute__((__sfr__));

extern volatile unsigned int  IFS4 __attribute__((__sfr__));
typedef struct tagIFS4BITS {
  unsigned :1;
  unsigned U1EIF:1;
} IFS4BITS;
extern volatile IFS4BITS IFS4bits __attribute__((__sfr__));

extern volatile unsigned int  IFS5 __attribute__((__sfr__));
typedef struct tagIFS5BITS {
  unsigned :14;
  unsigned PWM1IF:1;
  unsigned PWM2IF:1;
} IFS5BITS;
extern volatile IFS5BITS IFS5bits __attribute__((__sfr__));

extern volatile unsigned int  IFS6 __attribute__((__sfr__));
typedef struct tagIFS6BITS {
  unsigned PWM3IF:1;
  unsigned PWM4IF:1;
  unsigned :5;
  unsigned AC2IF:1;
  unsigned AC3IF:1;
  unsigned AC4IF:1;
  unsigned :4;
  unsigned ADCP0IF:1;
  unsigned ADCP1IF:1;
} IFS6BITS;
extern volatile IFS6BITS IFS6bits __attribute__((__sfr__));

extern volatile unsigned int  IFS7 __attribute__((__sfr__));
typedef struct tagIFS7BITS {
  unsigned ADCP2IF:1;
  unsigned ADCP3IF:1;
  unsigned ADCP4IF:1;
  unsigned ADCP5IF:1;
  unsigned ADCP6IF:1;
} IFS7BITS;
extern volatile IFS7BITS IFS7bits __attribute__((__sfr__));

extern volatile unsigned int  IEC0 __attribute__((__sfr__));
typedef struct tagIEC0BITS {
  unsigned INT0IE:1;
  unsigned IC1IE:1;
  unsigned OC1IE:1;
  unsigned T1IE:1;
  unsigned :1;
  unsigned IC2IE:1;
  unsigned OC2IE:1;
  unsigned T2IE:1;
  unsigned T3IE:1;
  unsigned SPI1EIE:1;
  unsigned SPI1IE:1;
  unsigned U1RXIE:1;
  unsigned U1TXIE:1;
  unsigned ADIE:1;
} IEC0BITS;
extern volatile IEC0BITS IEC0bits __attribute__((__sfr__));

extern volatile unsigned int  IEC1 __attribute__((__sfr__));
typedef struct tagIEC1BITS {
  unsigned SI2C1IE:1;
  unsigned MI2C1IE:1;
  unsigned AC1IE:1;
  unsigned CNIE:1;
  unsigned INT1IE:1;
  unsigned :8;
  unsigned INT2IE:1;
} IEC1BITS;
extern volatile IEC1BITS IEC1bits __attribute__((__sfr__));

extern volatile unsigned int  IEC3 __attribute__((__sfr__));
typedef struct tagIEC3BITS {
  unsigned :9;
  unsigned PSEMIE:1;
} IEC3BITS;
extern volatile IEC3BITS IEC3bits __attribute__((__sfr__));

extern volatile unsigned int  IEC4 __attribute__((__sfr__));
typedef struct tagIEC4BITS {
  unsigned :1;
  unsigned U1EIE:1;
} IEC4BITS;
extern volatile IEC4BITS IEC4bits __attribute__((__sfr__));

extern volatile unsigned int  IEC5 __attribute__((__sfr__));
typedef struct tagIEC5BITS {
  unsigned :14;
  unsigned PWM1IE:1;
  unsigned PWM2IE:1;
} IEC5BITS;
extern volatile IEC5BITS IEC5bits __attribute__((__sfr__));

extern volatile unsigned int  IEC6 __attribute__((__sfr__));
typedef struct tagIEC6BITS {
  unsigned PWM3IE:1;
  unsigned PWM4IE:1;
  unsigned :5;
  unsigned AC2IE:1;
  unsigned AC3IE:1;
  unsigned AC4IE:1;
  unsigned :4;
  unsigned ADCP0IE:1;
  unsigned ADCP1IE:1;
} IEC6BITS;
extern volatile IEC6BITS IEC6bits __attribute__((__sfr__));

extern volatile unsigned int  IEC7 __attribute__((__sfr__));
typedef struct tagIEC7BITS {
  unsigned ADCP2IE:1;
  unsigned ADCP3IE:1;
  unsigned ADCP4IE:1;
  unsigned ADCP5IE:1;
  unsigned ADCP6IE:1;
} IEC7BITS;
extern volatile IEC7BITS IEC7bits __attribute__((__sfr__));

extern volatile unsigned int  IPC0 __attribute__((__sfr__));
__extension__ typedef struct tagIPC0BITS {
  union {
    struct {
      unsigned INT0IP:3;
      unsigned :1;
      unsigned IC1IP:3;
      unsigned :1;
      unsigned OC1IP:3;
      unsigned :1;
      unsigned T1IP:3;
    };
    struct {
      unsigned INT0IP0:1;
      unsigned INT0IP1:1;
      unsigned INT0IP2:1;
      unsigned :1;
      unsigned IC1IP0:1;
      unsigned IC1IP1:1;
      unsigned IC1IP2:1;
      unsigned :1;
      unsigned OC1IP0:1;
      unsigned OC1IP1:1;
      unsigned OC1IP2:1;
      unsigned :1;
      unsigned T1IP0:1;
      unsigned T1IP1:1;
      unsigned T1IP2:1;
    };
  };
} IPC0BITS;
extern volatile IPC0BITS IPC0bits __attribute__((__sfr__));

extern volatile unsigned int  IPC1 __attribute__((__sfr__));
__extension__ typedef struct tagIPC1BITS {
  union {
    struct {
      unsigned :4;
      unsigned IC2IP:3;
      unsigned :1;
      unsigned OC2IP:3;
      unsigned :1;
      unsigned T2IP:3;
    };
    struct {
      unsigned :4;
      unsigned IC2IP0:1;
      unsigned IC2IP1:1;
      unsigned IC2IP2:1;
      unsigned :1;
      unsigned OC2IP0:1;
      unsigned OC2IP1:1;
      unsigned OC2IP2:1;
      unsigned :1;
      unsigned T2IP0:1;
      unsigned T2IP1:1;
      unsigned T2IP2:1;
    };
  };
} IPC1BITS;
extern volatile IPC1BITS IPC1bits __attribute__((__sfr__));

extern volatile unsigned int  IPC2 __attribute__((__sfr__));
__extension__ typedef struct tagIPC2BITS {
  union {
    struct {
      unsigned T3IP:3;
      unsigned :1;
      unsigned SPI1EIP:3;
      unsigned :1;
      unsigned SPI1IP:3;
      unsigned :1;
      unsigned U1RXIP:3;
    };
    struct {
      unsigned T3IP0:1;
      unsigned T3IP1:1;
      unsigned T3IP2:1;
      unsigned :1;
      unsigned SPI1EIP0:1;
      unsigned SPI1EIP1:1;
      unsigned SPI1EIP2:1;
      unsigned :1;
      unsigned SPI1IP0:1;
      unsigned SPI1IP1:1;
      unsigned SPI1IP2:1;
      unsigned :1;
      unsigned U1RXIP0:1;
      unsigned U1RXIP1:1;
      unsigned U1RXIP2:1;
    };
  };
} IPC2BITS;
extern volatile IPC2BITS IPC2bits __attribute__((__sfr__));

extern volatile unsigned int  IPC3 __attribute__((__sfr__));
__extension__ typedef struct tagIPC3BITS {
  union {
    struct {
      unsigned U1TXIP:3;
      unsigned :1;
      unsigned ADIP:3;
    };
    struct {
      unsigned U1TXIP0:1;
      unsigned U1TXIP1:1;
      unsigned U1TXIP2:1;
      unsigned :1;
      unsigned ADIP0:1;
      unsigned ADIP1:1;
      unsigned ADIP2:1;
    };
  };
} IPC3BITS;
extern volatile IPC3BITS IPC3bits __attribute__((__sfr__));

extern volatile unsigned int  IPC4 __attribute__((__sfr__));
__extension__ typedef struct tagIPC4BITS {
  union {
    struct {
      unsigned SI2C1IP:3;
      unsigned :1;
      unsigned MI2C1IP:3;
      unsigned :1;
      unsigned AC1IP:3;
      unsigned :1;
      unsigned CNIP:3;
    };
    struct {
      unsigned SI2C1IP0:1;
      unsigned SI2C1IP1:1;
      unsigned SI2C1IP2:1;
      unsigned :1;
      unsigned MI2C1IP0:1;
      unsigned MI2C1IP1:1;
      unsigned MI2C1IP2:1;
      unsigned :1;
      unsigned AC1IP0:1;
      unsigned AC1IP1:1;
      unsigned AC1IP2:1;
      unsigned :1;
      unsigned CNIP0:1;
      unsigned CNIP1:1;
      unsigned CNIP2:1;
    };
  };
} IPC4BITS;
extern volatile IPC4BITS IPC4bits __attribute__((__sfr__));

extern volatile unsigned int  IPC5 __attribute__((__sfr__));
__extension__ typedef struct tagIPC5BITS {
  union {
    struct {
      unsigned INT1IP:3;
    };
    struct {
      unsigned INT1IP0:1;
      unsigned INT1IP1:1;
      unsigned INT1IP2:1;
    };
  };
} IPC5BITS;
extern volatile IPC5BITS IPC5bits __attribute__((__sfr__));

extern volatile unsigned int  IPC7 __attribute__((__sfr__));
__extension__ typedef struct tagIPC7BITS {
  union {
    struct {
      unsigned :4;
      unsigned INT2IP:3;
    };
    struct {
      unsigned :4;
      unsigned INT2IP0:1;
      unsigned INT2IP1:1;
      unsigned INT2IP2:1;
    };
  };
} IPC7BITS;
extern volatile IPC7BITS IPC7bits __attribute__((__sfr__));

extern volatile unsigned int  IPC14 __attribute__((__sfr__));
__extension__ typedef struct tagIPC14BITS {
  union {
    struct {
      unsigned :4;
      unsigned PSEMIP:3;
    };
    struct {
      unsigned :4;
      unsigned PSEMIP0:1;
      unsigned PSEMIP1:1;
      unsigned PSEMIP2:1;
    };
  };
} IPC14BITS;
extern volatile IPC14BITS IPC14bits __attribute__((__sfr__));

extern volatile unsigned int  IPC16 __attribute__((__sfr__));
__extension__ typedef struct tagIPC16BITS {
  union {
    struct {
      unsigned :4;
      unsigned U1EIP:3;
    };
    struct {
      unsigned :4;
      unsigned U1EIP0:1;
      unsigned U1EIP1:1;
      unsigned U1EIP2:1;
    };
  };
} IPC16BITS;
extern volatile IPC16BITS IPC16bits __attribute__((__sfr__));

extern volatile unsigned int  IPC23 __attribute__((__sfr__));
__extension__ typedef struct tagIPC23BITS {
  union {
    struct {
      unsigned :8;
      unsigned PWM1IP:3;
      unsigned :1;
      unsigned PWM2IP:3;
    };
    struct {
      unsigned :8;
      unsigned PWM1IP0:1;
      unsigned PWM1IP1:1;
      unsigned PWM1IP2:1;
      unsigned :1;
      unsigned PWM2IP0:1;
      unsigned PWM2IP1:1;
      unsigned PWM2IP2:1;
    };
  };
} IPC23BITS;
extern volatile IPC23BITS IPC23bits __attribute__((__sfr__));

extern volatile unsigned int  IPC24 __attribute__((__sfr__));
__extension__ typedef struct tagIPC24BITS {
  union {
    struct {
      unsigned PWM3IP:3;
      unsigned :1;
      unsigned PWM4IP:3;
    };
    struct {
      unsigned PWM3IP0:1;
      unsigned PWM3IP1:1;
      unsigned PWM3IP2:1;
      unsigned :1;
      unsigned PWM4IP0:1;
      unsigned PWM4IP1:1;
      unsigned PWM4IP2:1;
    };
  };
} IPC24BITS;
extern volatile IPC24BITS IPC24bits __attribute__((__sfr__));

extern volatile unsigned int  IPC25 __attribute__((__sfr__));
__extension__ typedef struct tagIPC25BITS {
  union {
    struct {
      unsigned :12;
      unsigned AC2IP:3;
    };
    struct {
      unsigned :12;
      unsigned AC2IP0:1;
      unsigned AC2IP1:1;
      unsigned AC2IP2:1;
    };
  };
} IPC25BITS;
extern volatile IPC25BITS IPC25bits __attribute__((__sfr__));

extern volatile unsigned int  IPC26 __attribute__((__sfr__));
__extension__ typedef struct tagIPC26BITS {
  union {
    struct {
      unsigned AC3IP:3;
      unsigned :1;
      unsigned AC4IP:3;
    };
    struct {
      unsigned AC3IP0:1;
      unsigned AC3IP1:1;
      unsigned AC3IP2:1;
      unsigned :1;
      unsigned AC4IP0:1;
      unsigned AC4IP1:1;
      unsigned AC4IP2:1;
    };
  };
} IPC26BITS;
extern volatile IPC26BITS IPC26bits __attribute__((__sfr__));

extern volatile unsigned int  IPC27 __attribute__((__sfr__));
__extension__ typedef struct tagIPC27BITS {
  union {
    struct {
      unsigned :8;
      unsigned ADCP0IP:3;
      unsigned :1;
      unsigned ADCP1IP:3;
    };
    struct {
      unsigned :8;
      unsigned ADCP0IP0:1;
      unsigned ADCP0IP1:1;
      unsigned ADCP0IP2:1;
      unsigned :1;
      unsigned ADCP1IP0:1;
      unsigned ADCP1IP1:1;
      unsigned ADCP1IP2:1;
    };
  };
} IPC27BITS;
extern volatile IPC27BITS IPC27bits __attribute__((__sfr__));

extern volatile unsigned int  IPC28 __attribute__((__sfr__));
__extension__ typedef struct tagIPC28BITS {
  union {
    struct {
      unsigned ADCP2IP:3;
      unsigned :1;
      unsigned ADCP3IP:3;
      unsigned :1;
      unsigned ADCP4IP:3;
      unsigned :1;
      unsigned ADCP5IP:3;
    };
    struct {
      unsigned ADCP2IP0:1;
      unsigned ADCP2IP1:1;
      unsigned ADCP2IP2:1;
      unsigned :1;
      unsigned ADCP3IP0:1;
      unsigned ADCP3IP1:1;
      unsigned ADCP3IP2:1;
      unsigned :1;
      unsigned ADCP4IP0:1;
      unsigned ADCP4IP1:1;
      unsigned ADCP4IP2:1;
      unsigned :1;
      unsigned ADCP5IP0:1;
      unsigned ADCP5IP1:1;
      unsigned ADCP5IP2:1;
    };
  };
} IPC28BITS;
extern volatile IPC28BITS IPC28bits __attribute__((__sfr__));

extern volatile unsigned int  IPC29 __attribute__((__sfr__));
typedef struct tagIPC29BITS {
  unsigned ADCP6IP:3;
} IPC29BITS;
extern volatile IPC29BITS IPC29bits __attribute__((__sfr__));

extern volatile unsigned int  INTTREG __attribute__((__sfr__));
__extension__ typedef struct tagINTTREGBITS {
  union {
    struct {
      unsigned VECNUM:7;
      unsigned :1;
      unsigned ILR:4;
    };
    struct {
      unsigned VECNUM0:1;
      unsigned VECNUM1:1;
      unsigned VECNUM2:1;
      unsigned VECNUM3:1;
      unsigned VECNUM4:1;
      unsigned VECNUM5:1;
      unsigned VECNUM6:1;
      unsigned :1;
      unsigned ILR0:1;
      unsigned ILR1:1;
      unsigned ILR2:1;
      unsigned ILR3:1;
    };
  };
} INTTREGBITS;
extern volatile INTTREGBITS INTTREGbits __attribute__((__sfr__));

extern volatile unsigned int  TMR1 __attribute__((__sfr__));
extern volatile unsigned int  PR1 __attribute__((__sfr__));
extern volatile unsigned int  T1CON __attribute__((__sfr__));
__extension__ typedef struct tagT1CONBITS {
  union {
    struct {
      unsigned :1;
      unsigned TCS:1;
      unsigned TSYNC:1;
      unsigned :1;
      unsigned TCKPS:2;
      unsigned TGATE:1;
      unsigned :6;
      unsigned TSIDL:1;
      unsigned :1;
      unsigned TON:1;
    };
    struct {
      unsigned :4;
      unsigned TCKPS0:1;
      unsigned TCKPS1:1;
    };
  };
} T1CONBITS;
extern volatile T1CONBITS T1CONbits __attribute__((__sfr__));

extern volatile unsigned int  TMR2 __attribute__((__sfr__));
extern volatile unsigned int  TMR3HLD __attribute__((__sfr__));
extern volatile unsigned int  TMR3 __attribute__((__sfr__));
extern volatile unsigned int  PR2 __attribute__((__sfr__));
extern volatile unsigned int  PR3 __attribute__((__sfr__));
extern volatile unsigned int  T2CON __attribute__((__sfr__));
__extension__ typedef struct tagT2CONBITS {
  union {
    struct {
      unsigned :1;
      unsigned TCS:1;
      unsigned :1;
      unsigned T32:1;
      unsigned TCKPS:2;
      unsigned TGATE:1;
      unsigned :6;
      unsigned TSIDL:1;
      unsigned :1;
      unsigned TON:1;
    };
    struct {
      unsigned :4;
      unsigned TCKPS0:1;
      unsigned TCKPS1:1;
    };
  };
} T2CONBITS;
extern volatile T2CONBITS T2CONbits __attribute__((__sfr__));

extern volatile unsigned int  T3CON __attribute__((__sfr__));
__extension__ typedef struct tagT3CONBITS {
  union {
    struct {
      unsigned :1;
      unsigned TCS:1;
      unsigned :2;
      unsigned TCKPS:2;
      unsigned TGATE:1;
      unsigned :6;
      unsigned TSIDL:1;
      unsigned :1;
      unsigned TON:1;
    };
    struct {
      unsigned :4;
      unsigned TCKPS0:1;
      unsigned TCKPS1:1;
    };
  };
} T3CONBITS;
extern volatile T3CONBITS T3CONbits __attribute__((__sfr__));


/* Generic structure of entire SFR area for Input Capture modules */
typedef struct tagIC {
        unsigned int icxbuf;
        unsigned int icxcon;
} IC, *PIC;

/* SFR blocks for Input Capture modules */
extern volatile IC IC1 __attribute__((__sfr__));
extern volatile IC IC2 __attribute__((__sfr__));
extern volatile IC IC3 __attribute__((__sfr__));
extern volatile IC IC4 __attribute__((__sfr__));
extern volatile IC IC5 __attribute__((__sfr__));
extern volatile IC IC6 __attribute__((__sfr__));
extern volatile IC IC7 __attribute__((__sfr__));
extern volatile IC IC8 __attribute__((__sfr__));

extern volatile unsigned int  IC1BUF __attribute__((__sfr__));
extern volatile unsigned int  IC1CON __attribute__((__sfr__));
__extension__ typedef struct tagIC1CONBITS {
  union {
    struct {
      unsigned ICM:3;
      unsigned ICBNE:1;
      unsigned ICOV:1;
      unsigned ICI:2;
      unsigned ICTMR:1;
      unsigned :5;
      unsigned ICSIDL:1;
    };
    struct {
      unsigned ICM0:1;
      unsigned ICM1:1;
      unsigned ICM2:1;
      unsigned :2;
      unsigned ICI0:1;
      unsigned ICI1:1;
    };
  };
} IC1CONBITS;
extern volatile IC1CONBITS IC1CONbits __attribute__((__sfr__));

extern volatile unsigned int  IC2BUF __attribute__((__sfr__));
extern volatile unsigned int  IC2CON __attribute__((__sfr__));
__extension__ typedef struct tagIC2CONBITS {
  union {
    struct {
      unsigned ICM:3;
      unsigned ICBNE:1;
      unsigned ICOV:1;
      unsigned ICI:2;
      unsigned ICTMR:1;
      unsigned :5;
      unsigned ICSIDL:1;
    };
    struct {
      unsigned ICM0:1;
      unsigned ICM1:1;
      unsigned ICM2:1;
      unsigned :2;
      unsigned ICI0:1;
      unsigned ICI1:1;
    };
  };
} IC2CONBITS;
extern volatile IC2CONBITS IC2CONbits __attribute__((__sfr__));


/* Generic structure of entire SFR area for Output Compare modules */
typedef struct tagOC {
        unsigned int ocxrs;
        unsigned int ocxr;
        unsigned int ocxcon;
} OC, *POC;

/* SFR blocks for Output Compare modules */
extern volatile OC OC1 __attribute__((__sfr__));
extern volatile OC OC2 __attribute__((__sfr__));
extern volatile OC OC3 __attribute__((__sfr__));
extern volatile OC OC4 __attribute__((__sfr__));
extern volatile OC OC5 __attribute__((__sfr__));
extern volatile OC OC6 __attribute__((__sfr__));
extern volatile OC OC7 __attribute__((__sfr__));
extern volatile OC OC8 __attribute__((__sfr__));

extern volatile unsigned int  OC1RS __attribute__((__sfr__));
extern volatile unsigned int  OC1R __attribute__((__sfr__));
extern volatile unsigned int  OC1CON __attribute__((__sfr__));
__extension__ typedef struct tagOC1CONBITS {
  union {
    struct {
      unsigned OCM:3;
      unsigned OCTSEL:1;
      unsigned OCFLT:1;
      unsigned :8;
      unsigned OCSIDL:1;
    };
    struct {
      unsigned OCM0:1;
      unsigned OCM1:1;
      unsigned OCM2:1;
    };
  };
} OC1CONBITS;
extern volatile OC1CONBITS OC1CONbits __attribute__((__sfr__));

extern volatile unsigned int  OC2RS __attribute__((__sfr__));
extern volatile unsigned int  OC2R __attribute__((__sfr__));
extern volatile unsigned int  OC2CON __attribute__((__sfr__));
__extension__ typedef struct tagOC2CONBITS {
  union {
    struct {
      unsigned OCM:3;
      unsigned OCTSEL:1;
      unsigned OCFLT:1;
      unsigned :8;
      unsigned OCSIDL:1;
    };
    struct {
      unsigned OCM0:1;
      unsigned OCM1:1;
      unsigned OCM2:1;
    };
  };
} OC2CONBITS;
extern volatile OC2CONBITS OC2CONbits __attribute__((__sfr__));

extern volatile unsigned int  I2C1RCV __attribute__((__sfr__));
extern volatile unsigned int  I2CRCV __attribute__((__sfr__));
extern volatile unsigned int  I2C1TRN __attribute__((__sfr__));
extern volatile unsigned int  I2CTRN __attribute__((__sfr__));
extern volatile unsigned int  I2C1BRG __attribute__((__sfr__));
extern volatile unsigned int  I2C1CON __attribute__((__sfr__));
typedef struct tagI2C1CONBITS {
  unsigned SEN:1;
  unsigned RSEN:1;
  unsigned PEN:1;
  unsigned RCEN:1;
  unsigned ACKEN:1;
  unsigned ACKDT:1;
  unsigned STREN:1;
  unsigned GCEN:1;
  unsigned SMEN:1;
  unsigned DISSLW:1;
  unsigned A10M:1;
  unsigned IPMIEN:1;
  unsigned SCLREL:1;
  unsigned I2CSIDL:1;
  unsigned :1;
  unsigned I2CEN:1;
} I2C1CONBITS;
extern volatile I2C1CONBITS I2C1CONbits __attribute__((__sfr__));

extern volatile unsigned int  I2CCON __attribute__((__sfr__));
typedef struct tagI2CCONBITS {
  unsigned SEN:1;
  unsigned RSEN:1;
  unsigned PEN:1;
  unsigned RCEN:1;
  unsigned ACKEN:1;
  unsigned ACKDT:1;
  unsigned STREN:1;
  unsigned GCEN:1;
  unsigned SMEN:1;
  unsigned DISSLW:1;
  unsigned A10M:1;
  unsigned IPMIEN:1;
  unsigned SCLREL:1;
  unsigned I2CSIDL:1;
  unsigned :1;
  unsigned I2CEN:1;
} I2CCONBITS;
extern volatile I2CCONBITS I2CCONbits __attribute__((__sfr__));

extern volatile unsigned int  I2C1STAT __attribute__((__sfr__));
typedef struct tagI2C1STATBITS {
  unsigned TBF:1;
  unsigned RBF:1;
  unsigned R_W:1;
  unsigned S:1;
  unsigned P:1;
  unsigned D_A:1;
  unsigned I2COV:1;
  unsigned IWCOL:1;
  unsigned ADD10:1;
  unsigned GCSTAT:1;
  unsigned BCL:1;
  unsigned :3;
  unsigned TRSTAT:1;
  unsigned ACKSTAT:1;
} I2C1STATBITS;
extern volatile I2C1STATBITS I2C1STATbits __attribute__((__sfr__));

extern volatile unsigned int  I2CSTAT __attribute__((__sfr__));
typedef struct tagI2CSTATBITS {
  unsigned TBF:1;
  unsigned RBF:1;
  unsigned R_W:1;
  unsigned S:1;
  unsigned P:1;
  unsigned D_A:1;
  unsigned I2COV:1;
  unsigned IWCOL:1;
  unsigned ADD10:1;
  unsigned GCSTAT:1;
  unsigned BCL:1;
  unsigned :3;
  unsigned TRSTAT:1;
  unsigned ACKSTAT:1;
} I2CSTATBITS;
extern volatile I2CSTATBITS I2CSTATbits __attribute__((__sfr__));

extern volatile unsigned int  I2C1ADD __attribute__((__sfr__));
extern volatile unsigned int  I2CADD __attribute__((__sfr__));
extern volatile unsigned int  I2C1MSK __attribute__((__sfr__));

/* Generic structure of entire SFR area for each UART module */
typedef struct tagUART {
        unsigned int uxmode;
        unsigned int uxsta;
        unsigned int uxtxreg;
        unsigned int uxrxreg;
        unsigned int uxbrg;
} UART, *PUART;

#define UxMODEBITS U1MODEBITS
#define UxSTABITS U1STABITS
#define UxTXREGBITS U1TXREGBITS
#define UxRXREGBITS U1RXREGBITS
#define UxBRGBITS U1BRGBITS

/* SFR blocks for each UART module */
extern volatile UART UART1 __attribute__((__sfr__));
extern volatile UART UART2 __attribute__((__sfr__));

extern volatile unsigned int  U1MODE __attribute__((__sfr__));
__extension__ typedef struct tagU1MODEBITS {
  union {
    struct {
      unsigned STSEL:1;
      unsigned PDSEL:2;
      unsigned BRGH:1;
      unsigned URXINV:1;
      unsigned ABAUD:1;
      unsigned LPBACK:1;
      unsigned WAKE:1;
      unsigned UEN:2;
      unsigned :1;
      unsigned RTSMD:1;
      unsigned IREN:1;
      unsigned USIDL:1;
      unsigned :1;
      unsigned UARTEN:1;
    };
    struct {
      unsigned :1;
      unsigned PDSEL0:1;
      unsigned PDSEL1:1;
      unsigned :5;
      unsigned UEN0:1;
      unsigned UEN1:1;
    };
  };
} U1MODEBITS;
extern volatile U1MODEBITS U1MODEbits __attribute__((__sfr__));

extern volatile unsigned int  U1STA __attribute__((__sfr__));
__extension__ typedef struct tagU1STABITS {
  union {
    struct {
      unsigned URXDA:1;
      unsigned OERR:1;
      unsigned FERR:1;
      unsigned PERR:1;
      unsigned RIDLE:1;
      unsigned ADDEN:1;
      unsigned URXISEL:2;
      unsigned TRMT:1;
      unsigned UTXBF:1;
      unsigned UTXEN:1;
      unsigned UTXBRK:1;
      unsigned :1;
      unsigned UTXISEL0:1;
      unsigned UTXINV:1;
      unsigned UTXISEL1:1;
    };
    struct {
      unsigned :6;
      unsigned URXISEL0:1;
      unsigned URXISEL1:1;
    };
  };
} U1STABITS;
extern volatile U1STABITS U1STAbits __attribute__((__sfr__));

extern volatile unsigned int  U1TXREG __attribute__((__sfr__));
__extension__ typedef struct tagU1TXREGBITS {
  union {
    struct {
      unsigned U1TXREG:9;
    };
    struct {
      unsigned UTXREG0:1;
      unsigned UTXREG1:1;
      unsigned UTXREG2:1;
      unsigned UTXREG3:1;
      unsigned UTXREG4:1;
      unsigned UTXREG5:1;
      unsigned UTXREG6:1;
      unsigned UTXREG7:1;
      unsigned UTXREG8:1;
    };
  };
} U1TXREGBITS;
extern volatile U1TXREGBITS U1TXREGbits __attribute__((__sfr__));

extern volatile unsigned int  U1RXREG __attribute__((__sfr__));
__extension__ typedef struct tagU1RXREGBITS {
  union {
    struct {
      unsigned U1RXREG:9;
    };
    struct {
      unsigned URXREG0:1;
      unsigned URXREG1:1;
      unsigned URXREG2:1;
      unsigned URXREG3:1;
      unsigned URXREG4:1;
      unsigned URXREG5:1;
      unsigned URXREG6:1;
      unsigned URXREG7:1;
      unsigned URXREG8:1;
    };
  };
} U1RXREGBITS;
extern volatile U1RXREGBITS U1RXREGbits __attribute__((__sfr__));

extern volatile unsigned int  U1BRG __attribute__((__sfr__));

/* Generic structure of entire SFR area for each SPI module */
typedef struct tagSPI {
        unsigned int spixstat;
        unsigned int spixcon1;
        unsigned int spixcon2;
        unsigned int unused;
        unsigned int spixbuf;
} SPI, *PSPI;

#define SPIxSTATBITS SPI1STATBITS
#define SPIxCONBITS SPI1CONBITS

/* SFR blocks for each SPI module */
extern volatile SPI SPI1 __attribute__((__sfr__));
extern volatile SPI SPI2 __attribute__((__sfr__));

extern volatile unsigned int  SPI1STAT __attribute__((__sfr__));
typedef struct tagSPI1STATBITS {
  unsigned SPIRBF:1;
  unsigned SPITBF:1;
  unsigned :4;
  unsigned SPIROV:1;
  unsigned :6;
  unsigned SPISIDL:1;
  unsigned :1;
  unsigned SPIEN:1;
} SPI1STATBITS;
extern volatile SPI1STATBITS SPI1STATbits __attribute__((__sfr__));

extern volatile unsigned int  SPI1CON1 __attribute__((__sfr__));
__extension__ typedef struct tagSPI1CON1BITS {
  union {
    struct {
      unsigned PPRE:2;
      unsigned SPRE:3;
      unsigned MSTEN:1;
      unsigned CKP:1;
      unsigned SSEN:1;
      unsigned CKE:1;
      unsigned SMP:1;
      unsigned MODE16:1;
      unsigned DISSDO:1;
      unsigned DISSCK:1;
    };
    struct {
      unsigned PPRE0:1;
      unsigned PPRE1:1;
      unsigned SPRE0:1;
      unsigned SPRE1:1;
      unsigned SPRE2:1;
    };
  };
} SPI1CON1BITS;
extern volatile SPI1CON1BITS SPI1CON1bits __attribute__((__sfr__));

extern volatile unsigned int  SPI1CON2 __attribute__((__sfr__));
typedef struct tagSPI1CON2BITS {
  unsigned :1;
  unsigned FRMDLY:1;
  unsigned :11;
  unsigned FRMPOL:1;
  unsigned SPIFSD:1;
  unsigned FRMEN:1;
} SPI1CON2BITS;
extern volatile SPI1CON2BITS SPI1CON2bits __attribute__((__sfr__));

extern volatile unsigned int  SPI1BUF __attribute__((__sfr__));
extern volatile unsigned int  TRISA __attribute__((__sfr__));
typedef struct tagTRISABITS {
  unsigned TRISA0:1;
  unsigned TRISA1:1;
  unsigned TRISA2:1;
  unsigned TRISA3:1;
  unsigned TRISA4:1;
} TRISABITS;
extern volatile TRISABITS TRISAbits __attribute__((__sfr__));

extern volatile unsigned int  PORTA __attribute__((__sfr__));
typedef struct tagPORTABITS {
  unsigned RA0:1;
  unsigned RA1:1;
  unsigned RA2:1;
  unsigned RA3:1;
  unsigned RA4:1;
} PORTABITS;
extern volatile PORTABITS PORTAbits __attribute__((__sfr__));

extern volatile unsigned int  LATA __attribute__((__sfr__));
typedef struct tagLATABITS {
  unsigned LATA0:1;
  unsigned LATA1:1;
  unsigned LATA2:1;
  unsigned LATA3:1;
  unsigned LATA4:1;
} LATABITS;
extern volatile LATABITS LATAbits __attribute__((__sfr__));

extern volatile unsigned int  ODCA __attribute__((__sfr__));
typedef struct tagODCABITS {
  unsigned ODCA0:1;
  unsigned ODCA1:1;
  unsigned ODCA2:1;
  unsigned ODCA3:1;
  unsigned ODCA4:1;
} ODCABITS;
extern volatile ODCABITS ODCAbits __attribute__((__sfr__));

extern volatile unsigned int  TRISB __attribute__((__sfr__));
typedef struct tagTRISBBITS {
  unsigned TRISB0:1;
  unsigned TRISB1:1;
  unsigned TRISB2:1;
  unsigned TRISB3:1;
  unsigned TRISB4:1;
  unsigned TRISB5:1;
  unsigned TRISB6:1;
  unsigned TRISB7:1;
  unsigned TRISB8:1;
  unsigned TRISB9:1;
  unsigned TRISB10:1;
  unsigned TRISB11:1;
  unsigned TRISB12:1;
  unsigned TRISB13:1;
  unsigned TRISB14:1;
  unsigned TRISB15:1;
} TRISBBITS;
extern volatile TRISBBITS TRISBbits __attribute__((__sfr__));

extern volatile unsigned int  PORTB __attribute__((__sfr__));
typedef struct tagPORTBBITS {
  unsigned RB0:1;
  unsigned RB1:1;
  unsigned RB2:1;
  unsigned RB3:1;
  unsigned RB4:1;
  unsigned RB5:1;
  unsigned RB6:1;
  unsigned RB7:1;
  unsigned RB8:1;
  unsigned RB9:1;
  unsigned RB10:1;
  unsigned RB11:1;
  unsigned RB12:1;
  unsigned RB13:1;
  unsigned RB14:1;
  unsigned RB15:1;
} PORTBBITS;
extern volatile PORTBBITS PORTBbits __attribute__((__sfr__));

extern volatile unsigned int  LATB __attribute__((__sfr__));
typedef struct tagLATBBITS {
  unsigned LATB0:1;
  unsigned LATB1:1;
  unsigned LATB2:1;
  unsigned LATB3:1;
  unsigned LATB4:1;
  unsigned LATB5:1;
  unsigned LATB6:1;
  unsigned LATB7:1;
  unsigned LATB8:1;
  unsigned LATB9:1;
  unsigned LATB10:1;
  unsigned LATB11:1;
  unsigned LATB12:1;
  unsigned LATB13:1;
  unsigned LATB14:1;
  unsigned LATB15:1;
} LATBBITS;
extern volatile LATBBITS LATBbits __attribute__((__sfr__));

extern volatile unsigned int  ODCB __attribute__((__sfr__));
typedef struct tagODCBBITS {
  unsigned ODCB0:1;
  unsigned ODCB1:1;
  unsigned ODCB2:1;
  unsigned ODCB3:1;
  unsigned ODCB4:1;
  unsigned ODCB5:1;
  unsigned ODCB6:1;
  unsigned ODCB7:1;
  unsigned ODCB8:1;
  unsigned ODCB9:1;
  unsigned ODCB10:1;
  unsigned ODCB11:1;
  unsigned ODCB12:1;
  unsigned ODCB13:1;
  unsigned ODCB14:1;
  unsigned ODCB15:1;
} ODCBBITS;
extern volatile ODCBBITS ODCBbits __attribute__((__sfr__));

extern volatile unsigned int  TRISC __attribute__((__sfr__));
typedef struct tagTRISCBITS {
  unsigned TRISC0:1;
  unsigned TRISC1:1;
  unsigned TRISC2:1;
  unsigned TRISC3:1;
  unsigned TRISC4:1;
  unsigned TRISC5:1;
  unsigned TRISC6:1;
  unsigned TRISC7:1;
  unsigned TRISC8:1;
  unsigned TRISC9:1;
  unsigned TRISC10:1;
  unsigned TRISC11:1;
  unsigned TRISC12:1;
  unsigned TRISC13:1;
} TRISCBITS;
extern volatile TRISCBITS TRISCbits __attribute__((__sfr__));

extern volatile unsigned int  PORTC __attribute__((__sfr__));
typedef struct tagPORTCBITS {
  unsigned RC0:1;
  unsigned RC1:1;
  unsigned RC2:1;
  unsigned RC3:1;
  unsigned RC4:1;
  unsigned RC5:1;
  unsigned RC6:1;
  unsigned RC7:1;
  unsigned RC8:1;
  unsigned RC9:1;
  unsigned RC10:1;
  unsigned RC11:1;
  unsigned RC12:1;
  unsigned RC13:1;
} PORTCBITS;
extern volatile PORTCBITS PORTCbits __attribute__((__sfr__));

extern volatile unsigned int  LATC __attribute__((__sfr__));
typedef struct tagLATCBITS {
  unsigned LATC0:1;
  unsigned LATC1:1;
  unsigned LATC2:1;
  unsigned LATC3:1;
  unsigned LATC4:1;
  unsigned LATC5:1;
  unsigned LATC6:1;
  unsigned LATC7:1;
  unsigned LATC8:1;
  unsigned LATC9:1;
  unsigned LATC10:1;
  unsigned LATC11:1;
  unsigned LATC12:1;
  unsigned LATC13:1;
} LATCBITS;
extern volatile LATCBITS LATCbits __attribute__((__sfr__));

extern volatile unsigned int  ODCC __attribute__((__sfr__));
typedef struct tagODCCBITS {
  unsigned ODCC0:1;
  unsigned ODCC1:1;
  unsigned ODCC2:1;
  unsigned ODCC3:1;
  unsigned ODCC4:1;
  unsigned ODCC5:1;
  unsigned ODCC6:1;
  unsigned ODCC7:1;
  unsigned ODCC8:1;
  unsigned ODCC9:1;
  unsigned ODCC10:1;
  unsigned ODCC11:1;
  unsigned ODCC12:1;
  unsigned ODCC13:1;
} ODCCBITS;
extern volatile ODCCBITS ODCCbits __attribute__((__sfr__));

extern volatile unsigned int  ADCON __attribute__((__sfr__));
__extension__ typedef struct tagADCONBITS {
  union {
    struct {
      unsigned ADCS:3;
      unsigned :1;
      unsigned ASYNCSAMP:1;
      unsigned SEQSAMP:1;
      unsigned ORDER:1;
      unsigned EIE:1;
      unsigned FORM:1;
      unsigned :1;
      unsigned GSWTRG:1;
      unsigned :1;
      unsigned SLOWCLK:1;
      unsigned ADSIDL:1;
      unsigned :1;
      unsigned ADON:1;
    };
    struct {
      unsigned ADCS0:1;
      unsigned ADCS1:1;
      unsigned ADCS2:1;
    };
  };
} ADCONBITS;
extern volatile ADCONBITS ADCONbits __attribute__((__sfr__));

extern volatile unsigned int  ADPCFG __attribute__((__sfr__));
typedef struct tagADPCFGBITS {
  unsigned PCFG0:1;
  unsigned PCFG1:1;
  unsigned PCFG2:1;
  unsigned PCFG3:1;
  unsigned PCFG4:1;
  unsigned PCFG5:1;
  unsigned PCFG6:1;
  unsigned PCFG7:1;
  unsigned PCFG8:1;
  unsigned PCFG9:1;
  unsigned PCFG10:1;
  unsigned PCFG11:1;
} ADPCFGBITS;
extern volatile ADPCFGBITS ADPCFGbits __attribute__((__sfr__));

extern volatile unsigned int  ADSTAT __attribute__((__sfr__));
typedef struct tagADSTATBITS {
  unsigned P0RDY:1;
  unsigned P1RDY:1;
  unsigned P2RDY:1;
  unsigned P3RDY:1;
  unsigned P4RDY:1;
  unsigned P5RDY:1;
  unsigned P6RDY:1;
} ADSTATBITS;
extern volatile ADSTATBITS ADSTATbits __attribute__((__sfr__));

extern volatile unsigned int  ADBASE __attribute__((__sfr__));
extern volatile unsigned int  ADCPC0 __attribute__((__sfr__));
__extension__ typedef struct tagADCPC0BITS {
  union {
    struct {
      unsigned TRGSRC0:5;
      unsigned SWTRG0:1;
      unsigned PEND0:1;
      unsigned IRQEN0:1;
      unsigned TRGSRC1:5;
      unsigned SWTRG1:1;
      unsigned PEND1:1;
      unsigned IRQEN1:1;
    };
    struct {
      unsigned TRGSRC00:1;
      unsigned TRGSRC01:1;
      unsigned TRGSRC02:1;
      unsigned TRGSRC03:1;
      unsigned TRGSRC04:1;
      unsigned :3;
      unsigned TRGSRC10:1;
      unsigned TRGSRC11:1;
      unsigned TRGSRC12:1;
      unsigned TRGSRC13:1;
      unsigned TRGSRC14:1;
    };
  };
} ADCPC0BITS;
extern volatile ADCPC0BITS ADCPC0bits __attribute__((__sfr__));

extern volatile unsigned int  ADCPC1 __attribute__((__sfr__));
__extension__ typedef struct tagADCPC1BITS {
  union {
    struct {
      unsigned TRGSRC2:5;
      unsigned SWTRG2:1;
      unsigned PEND2:1;
      unsigned IRQEN2:1;
      unsigned TRGSRC3:5;
      unsigned SWTRG3:1;
      unsigned PEND3:1;
      unsigned IRQEN3:1;
    };
    struct {
      unsigned TRGSRC20:1;
      unsigned TRGSRC21:1;
      unsigned TRGSRC22:1;
      unsigned TRGSRC23:1;
      unsigned TRGSRC24:1;
      unsigned :3;
      unsigned TRGSRC30:1;
      unsigned TRGSRC31:1;
      unsigned TRGSRC32:1;
      unsigned TRGSRC33:1;
      unsigned TRGSRC34:1;
    };
  };
} ADCPC1BITS;
extern volatile ADCPC1BITS ADCPC1bits __attribute__((__sfr__));

extern volatile unsigned int  ADCPC2 __attribute__((__sfr__));
__extension__ typedef struct tagADCPC2BITS {
  union {
    struct {
      unsigned TRGSRC4:5;
      unsigned SWTRG4:1;
      unsigned PEND4:1;
      unsigned IRQEN4:1;
      unsigned TRGSRC5:5;
      unsigned SWTRG5:1;
      unsigned PEND5:1;
      unsigned IRQEN5:1;
    };
    struct {
      unsigned TRGSRC40:1;
      unsigned TRGSRC41:1;
      unsigned TRGSRC42:1;
      unsigned TRGSRC43:1;
      unsigned TRGSRC44:1;
      unsigned :3;
      unsigned TRGSRC50:1;
      unsigned TRGSRC51:1;
      unsigned TRGSRC52:1;
      unsigned TRGSRC53:1;
      unsigned TRGSRC54:1;
    };
  };
} ADCPC2BITS;
extern volatile ADCPC2BITS ADCPC2bits __attribute__((__sfr__));

extern volatile unsigned int  ADCPC3 __attribute__((__sfr__));
__extension__ typedef struct tagADCPC3BITS {
  union {
    struct {
      unsigned TRGSRC6:5;
      unsigned SWTRG6:1;
      unsigned PEND6:1;
      unsigned IRQEN6:1;
    };
    struct {
      unsigned TRGSRC60:1;
      unsigned TRGSRC61:1;
      unsigned TRGSRC62:1;
      unsigned TRGSRC63:1;
      unsigned TRGSRC64:1;
    };
  };
} ADCPC3BITS;
extern volatile ADCPC3BITS ADCPC3bits __attribute__((__sfr__));

extern volatile unsigned int  ADCBUF0 __attribute__((__sfr__));
extern volatile unsigned int  ADCBUF1 __attribute__((__sfr__));
extern volatile unsigned int  ADCBUF2 __attribute__((__sfr__));
extern volatile unsigned int  ADCBUF3 __attribute__((__sfr__));
extern volatile unsigned int  ADCBUF4 __attribute__((__sfr__));
extern volatile unsigned int  ADCBUF5 __attribute__((__sfr__));
extern volatile unsigned int  ADCBUF6 __attribute__((__sfr__));
extern volatile unsigned int  ADCBUF7 __attribute__((__sfr__));
extern volatile unsigned int  ADCBUF8 __attribute__((__sfr__));
extern volatile unsigned int  ADCBUF9 __attribute__((__sfr__));
extern volatile unsigned int  ADCBUF10 __attribute__((__sfr__));
extern volatile unsigned int  ADCBUF11 __attribute__((__sfr__));
extern volatile unsigned int  ADCBUF12 __attribute__((__sfr__));
extern volatile unsigned int  ADCBUF13 __attribute__((__sfr__));
extern volatile unsigned int  PTCON __attribute__((__sfr__));
__extension__ typedef struct tagPTCONBITS {
  union {
    struct {
      unsigned SEVTPS:4;
      unsigned SYNCSRC:2;
      unsigned :1;
      unsigned SYNCEN:1;
      unsigned SYNCOEN:1;
      unsigned SYNCPOL:1;
      unsigned EIPU:1;
      unsigned SEIEN:1;
      unsigned SESTAT:1;
      unsigned PTSIDL:1;
      unsigned :1;
      unsigned PTEN:1;
    };
    struct {
      unsigned SEVTPS0:1;
      unsigned SEVTPS1:1;
      unsigned SEVTPS2:1;
      unsigned SEVTPS3:1;
      unsigned SYNCSRC0:1;
      unsigned SYNCSRC1:1;
    };
  };
} PTCONBITS;
extern volatile PTCONBITS PTCONbits __attribute__((__sfr__));

extern volatile unsigned int  PTCON2 __attribute__((__sfr__));
__extension__ typedef struct tagPTCON2BITS {
  union {
    struct {
      unsigned PCLKDIV:3;
    };
    struct {
      unsigned PCLKDIV0:1;
      unsigned PCLKDIV1:1;
      unsigned PCLKDIV2:1;
    };
  };
} PTCON2BITS;
extern volatile PTCON2BITS PTCON2bits __attribute__((__sfr__));

extern volatile unsigned int  PTPER __attribute__((__sfr__));
extern volatile unsigned int  SEVTCMP __attribute__((__sfr__));
extern volatile unsigned int  MDC __attribute__((__sfr__));
extern volatile unsigned int  PWMCON1 __attribute__((__sfr__));
__extension__ typedef struct tagPWMCON1BITS {
  union {
    struct {
      unsigned IUE:1;
      unsigned XPRES:1;
      unsigned CAM:1;
      unsigned :3;
      unsigned DTC:2;
      unsigned MDCS:1;
      unsigned ITB:1;
      unsigned TRGIEN:1;
      unsigned CLIEN:1;
      unsigned FLTIEN:1;
      unsigned TRGSTAT:1;
      unsigned CLSTAT:1;
      unsigned FLTSTAT:1;
    };
    struct {
      unsigned :6;
      unsigned DTC0:1;
      unsigned DTC1:1;
    };
  };
} PWMCON1BITS;
extern volatile PWMCON1BITS PWMCON1bits __attribute__((__sfr__));

extern volatile unsigned int  IOCON1 __attribute__((__sfr__));
__extension__ typedef struct tagIOCON1BITS {
  union {
    struct {
      unsigned OSYNC:1;
      unsigned SWAP:1;
      unsigned CLDAT:2;
      unsigned FLTDAT:2;
      unsigned OVRDAT:2;
      unsigned OVRENL:1;
      unsigned OVRENH:1;
      unsigned PMOD:2;
      unsigned POLL:1;
      unsigned POLH:1;
      unsigned PENL:1;
      unsigned PENH:1;
    };
    struct {
      unsigned :2;
      unsigned CLDAT0:1;
      unsigned CLDAT1:1;
      unsigned FLTDAT0:1;
      unsigned FLTDAT1:1;
      unsigned OVRDAT0:1;
      unsigned OVRDAT1:1;
      unsigned :2;
      unsigned PMOD0:1;
      unsigned PMOD1:1;
    };
  };
} IOCON1BITS;
extern volatile IOCON1BITS IOCON1bits __attribute__((__sfr__));

extern volatile unsigned int  FCLCON1 __attribute__((__sfr__));
__extension__ typedef struct tagFCLCON1BITS {
  union {
    struct {
      unsigned FLTMOD:2;
      unsigned FLTPOL:1;
      unsigned FLTSRC:5;
      unsigned CLMOD:1;
      unsigned CLPOL:1;
      unsigned CLSRC:5;
      unsigned IFLTMOD:1;
    };
    struct {
      unsigned FLTMOD0:1;
      unsigned FLTMOD1:1;
      unsigned :1;
      unsigned FLTSRC0:1;
      unsigned FLTSRC1:1;
      unsigned FLTSRC2:1;
      unsigned FLTSRC3:1;
      unsigned FLTSRC4:1;
      unsigned :2;
      unsigned CLSRC0:1;
      unsigned CLSRC1:1;
      unsigned CLSRC2:1;
      unsigned CLSRC3:1;
      unsigned CLSRC4:1;
    };
  };
} FCLCON1BITS;
extern volatile FCLCON1BITS FCLCON1bits __attribute__((__sfr__));

extern volatile unsigned int  PDC1 __attribute__((__sfr__));
extern volatile unsigned int  PHASE1 __attribute__((__sfr__));
extern volatile unsigned int  DTR1 __attribute__((__sfr__));
extern volatile unsigned int  ALTDTR1 __attribute__((__sfr__));
extern volatile unsigned int  SDC1 __attribute__((__sfr__));
extern volatile unsigned int  SPHASE1 __attribute__((__sfr__));
extern volatile unsigned int  TRIG1 __attribute__((__sfr__));
__extension__ typedef struct tagTRIG1BITS {
  union {
    struct {
      unsigned :3;
      unsigned TRGCMP:13;
    };
    struct {
      unsigned :3;
      unsigned TRGCMP0:1;
      unsigned TRGCMP1:1;
      unsigned TRGCMP2:1;
      unsigned TRGCMP3:1;
      unsigned TRGCMP4:1;
      unsigned TRGCMP5:1;
      unsigned TRGCMP6:1;
      unsigned TRGCMP7:1;
      unsigned TRGCMP8:1;
      unsigned TRGCMP9:1;
      unsigned TRGCMP10:1;
      unsigned TRGCMP11:1;
      unsigned TRGCMP12:1;
    };
  };
} TRIG1BITS;
extern volatile TRIG1BITS TRIG1bits __attribute__((__sfr__));

extern volatile unsigned int  TRGCON1 __attribute__((__sfr__));
__extension__ typedef struct tagTRGCON1BITS {
  union {
    struct {
      unsigned TRGSTRT:6;
      unsigned :1;
      unsigned DTM:1;
      unsigned :4;
      unsigned TRGDIV:4;
    };
    struct {
      unsigned TRGSTRT0:1;
      unsigned TRGSTRT1:1;
      unsigned TRGSTRT2:1;
      unsigned TRGSTRT3:1;
      unsigned TRGSTRT4:1;
      unsigned TRGSTRT5:1;
      unsigned :6;
      unsigned TRGDIV0:1;
      unsigned TRGDIV1:1;
      unsigned TRGDIV2:1;
      unsigned TRGDIV3:1;
    };
  };
} TRGCON1BITS;
extern volatile TRGCON1BITS TRGCON1bits __attribute__((__sfr__));

extern volatile unsigned int  STRIG1 __attribute__((__sfr__));
__extension__ typedef struct tagSTRIG1BITS {
  union {
    struct {
      unsigned :3;
      unsigned STRGCMP:13;
    };
    struct {
      unsigned :3;
      unsigned STRGCMP0:1;
      unsigned STRGCMP1:1;
      unsigned STRGCMP2:1;
      unsigned STRGCMP3:1;
      unsigned STRGCMP4:1;
      unsigned STRGCMP5:1;
      unsigned STRGCMP6:1;
      unsigned STRGCMP7:1;
      unsigned STRGCMP8:1;
      unsigned STRGCMP9:1;
      unsigned STRGCMP10:1;
      unsigned STRGCMP11:1;
      unsigned STRGCMP12:1;
    };
  };
} STRIG1BITS;
extern volatile STRIG1BITS STRIG1bits __attribute__((__sfr__));

extern volatile unsigned int  PWMCAP1 __attribute__((__sfr__));
typedef struct tagPWMCAP1BITS {
  unsigned :3;
  unsigned PWMCAP10:1;
  unsigned PWMCAP11:1;
  unsigned PWMCAP12:1;
  unsigned PWMCAP13:1;
  unsigned PWMCAP14:1;
  unsigned PWMCAP15:1;
  unsigned PWMCAP16:1;
  unsigned PWMCAP17:1;
  unsigned PWMCAP18:1;
  unsigned PWMCAP19:1;
  unsigned PWMCAP110:1;
  unsigned PWMCAP111:1;
  unsigned PWMCAP112:1;
} PWMCAP1BITS;
extern volatile PWMCAP1BITS PWMCAP1bits __attribute__((__sfr__));

extern volatile unsigned int  LEBCON1 __attribute__((__sfr__));
__extension__ typedef struct tagLEBCON1BITS {
  union {
    struct {
      unsigned :3;
      unsigned LEB:7;
      unsigned CLLEBEN:1;
      unsigned FLTLEBEN:1;
      unsigned PLF:1;
      unsigned PLR:1;
      unsigned PHF:1;
      unsigned PHR:1;
    };
    struct {
      unsigned :3;
      unsigned LEB0:1;
      unsigned LEB1:1;
      unsigned LEB2:1;
      unsigned LEB3:1;
      unsigned LEB4:1;
      unsigned LEB5:1;
      unsigned LEB6:1;
    };
  };
} LEBCON1BITS;
extern volatile LEBCON1BITS LEBCON1bits __attribute__((__sfr__));

extern volatile unsigned int  PWMCON2 __attribute__((__sfr__));
__extension__ typedef struct tagPWMCON2BITS {
  union {
    struct {
      unsigned IUE:1;
      unsigned XPRES:1;
      unsigned CAM:1;
      unsigned :3;
      unsigned DTC:2;
      unsigned MDCS:1;
      unsigned ITB:1;
      unsigned TRGIEN:1;
      unsigned CLIEN:1;
      unsigned FLTIEN:1;
      unsigned TRGSTAT:1;
      unsigned CLSTAT:1;
      unsigned FLTSTAT:1;
    };
    struct {
      unsigned :6;
      unsigned DTC0:1;
      unsigned DTC1:1;
    };
  };
} PWMCON2BITS;
extern volatile PWMCON2BITS PWMCON2bits __attribute__((__sfr__));

extern volatile unsigned int  IOCON2 __attribute__((__sfr__));
__extension__ typedef struct tagIOCON2BITS {
  union {
    struct {
      unsigned OSYNC:1;
      unsigned SWAP:1;
      unsigned CLDAT:2;
      unsigned FLTDAT:2;
      unsigned OVRDAT:2;
      unsigned OVRENL:1;
      unsigned OVRENH:1;
      unsigned PMOD:2;
      unsigned POLL:1;
      unsigned POLH:1;
      unsigned PENL:1;
      unsigned PENH:1;
    };
    struct {
      unsigned :2;
      unsigned CLDAT0:1;
      unsigned CLDAT1:1;
      unsigned FLTDAT0:1;
      unsigned FLTDAT1:1;
      unsigned OVRDAT0:1;
      unsigned OVRDAT1:1;
      unsigned :2;
      unsigned PMOD0:1;
      unsigned PMOD1:1;
    };
  };
} IOCON2BITS;
extern volatile IOCON2BITS IOCON2bits __attribute__((__sfr__));

extern volatile unsigned int  FCLCON2 __attribute__((__sfr__));
__extension__ typedef struct tagFCLCON2BITS {
  union {
    struct {
      unsigned FLTMOD:2;
      unsigned FLTPOL:1;
      unsigned FLTSRC:5;
      unsigned CLMOD:1;
      unsigned CLPOL:1;
      unsigned CLSRC:5;
      unsigned IFLTMOD:1;
    };
    struct {
      unsigned FLTMOD0:1;
      unsigned FLTMOD1:1;
      unsigned :1;
      unsigned FLTSRC0:1;
      unsigned FLTSRC1:1;
      unsigned FLTSRC2:1;
      unsigned FLTSRC3:1;
      unsigned FLTSRC4:1;
      unsigned :2;
      unsigned CLSRC0:1;
      unsigned CLSRC1:1;
      unsigned CLSRC2:1;
      unsigned CLSRC3:1;
      unsigned CLSRC4:1;
    };
  };
} FCLCON2BITS;
extern volatile FCLCON2BITS FCLCON2bits __attribute__((__sfr__));

extern volatile unsigned int  PDC2 __attribute__((__sfr__));
extern volatile unsigned int  PHASE2 __attribute__((__sfr__));
extern volatile unsigned int  DTR2 __attribute__((__sfr__));
extern volatile unsigned int  ALTDTR2 __attribute__((__sfr__));
extern volatile unsigned int  SDC2 __attribute__((__sfr__));
extern volatile unsigned int  SPHASE2 __attribute__((__sfr__));
extern volatile unsigned int  TRIG2 __attribute__((__sfr__));
__extension__ typedef struct tagTRIG2BITS {
  union {
    struct {
      unsigned :3;
      unsigned TRGCMP:13;
    };
    struct {
      unsigned :3;
      unsigned TRGCMP0:1;
      unsigned TRGCMP1:1;
      unsigned TRGCMP2:1;
      unsigned TRGCMP3:1;
      unsigned TRGCMP4:1;
      unsigned TRGCMP5:1;
      unsigned TRGCMP6:1;
      unsigned TRGCMP7:1;
      unsigned TRGCMP8:1;
      unsigned TRGCMP9:1;
      unsigned TRGCMP10:1;
      unsigned TRGCMP11:1;
      unsigned TRGCMP12:1;
    };
  };
} TRIG2BITS;
extern volatile TRIG2BITS TRIG2bits __attribute__((__sfr__));

extern volatile unsigned int  TRGCON2 __attribute__((__sfr__));
__extension__ typedef struct tagTRGCON2BITS {
  union {
    struct {
      unsigned TRGSTRT:6;
      unsigned :1;
      unsigned DTM:1;
      unsigned :4;
      unsigned TRGDIV:4;
    };
    struct {
      unsigned TRGSTRT0:1;
      unsigned TRGSTRT1:1;
      unsigned TRGSTRT2:1;
      unsigned TRGSTRT3:1;
      unsigned TRGSTRT4:1;
      unsigned TRGSTRT5:1;
      unsigned :6;
      unsigned TRGDIV0:1;
      unsigned TRGDIV1:1;
      unsigned TRGDIV2:1;
      unsigned TRGDIV3:1;
    };
  };
} TRGCON2BITS;
extern volatile TRGCON2BITS TRGCON2bits __attribute__((__sfr__));

extern volatile unsigned int  STRIG2 __attribute__((__sfr__));
__extension__ typedef struct tagSTRIG2BITS {
  union {
    struct {
      unsigned :3;
      unsigned STRGCMP:13;
    };
    struct {
      unsigned :3;
      unsigned STRGCMP0:1;
      unsigned STRGCMP1:1;
      unsigned STRGCMP2:1;
      unsigned STRGCMP3:1;
      unsigned STRGCMP4:1;
      unsigned STRGCMP5:1;
      unsigned STRGCMP6:1;
      unsigned STRGCMP7:1;
      unsigned STRGCMP8:1;
      unsigned STRGCMP9:1;
      unsigned STRGCMP10:1;
      unsigned STRGCMP11:1;
      unsigned STRGCMP12:1;
    };
  };
} STRIG2BITS;
extern volatile STRIG2BITS STRIG2bits __attribute__((__sfr__));

extern volatile unsigned int  PWMCAP2 __attribute__((__sfr__));
extern volatile unsigned int  LEBCON2 __attribute__((__sfr__));
__extension__ typedef struct tagLEBCON2BITS {
  union {
    struct {
      unsigned :3;
      unsigned LEB:7;
      unsigned CLLEBEN:1;
      unsigned FLTLEBEN:1;
      unsigned PLF:1;
      unsigned PLR:1;
      unsigned PHF:1;
      unsigned PHR:1;
    };
    struct {
      unsigned :3;
      unsigned LEB0:1;
      unsigned LEB1:1;
      unsigned LEB2:1;
      unsigned LEB3:1;
      unsigned LEB4:1;
      unsigned LEB5:1;
      unsigned LEB6:1;
    };
  };
} LEBCON2BITS;
extern volatile LEBCON2BITS LEBCON2bits __attribute__((__sfr__));

extern volatile unsigned int  PWMCON3 __attribute__((__sfr__));
__extension__ typedef struct tagPWMCON3BITS {
  union {
    struct {
      unsigned IUE:1;
      unsigned XPRES:1;
      unsigned CAM:1;
      unsigned :3;
      unsigned DTC:2;
      unsigned MDCS:1;
      unsigned ITB:1;
      unsigned TRGIEN:1;
      unsigned CLIEN:1;
      unsigned FLTIEN:1;
      unsigned TRGSTAT:1;
      unsigned CLSTAT:1;
      unsigned FLTSTAT:1;
    };
    struct {
      unsigned :6;
      unsigned DTC0:1;
      unsigned DTC1:1;
    };
  };
} PWMCON3BITS;
extern volatile PWMCON3BITS PWMCON3bits __attribute__((__sfr__));

extern volatile unsigned int  IOCON3 __attribute__((__sfr__));
__extension__ typedef struct tagIOCON3BITS {
  union {
    struct {
      unsigned OSYNC:1;
      unsigned SWAP:1;
      unsigned CLDAT:2;
      unsigned FLTDAT:2;
      unsigned OVRDAT:2;
      unsigned OVRENL:1;
      unsigned OVRENH:1;
      unsigned PMOD:2;
      unsigned POLL:1;
      unsigned POLH:1;
      unsigned PENL:1;
      unsigned PENH:1;
    };
    struct {
      unsigned :2;
      unsigned CLDAT0:1;
      unsigned CLDAT1:1;
      unsigned FLTDAT0:1;
      unsigned FLTDAT1:1;
      unsigned OVRDAT0:1;
      unsigned OVRDAT1:1;
      unsigned :2;
      unsigned PMOD0:1;
      unsigned PMOD1:1;
    };
  };
} IOCON3BITS;
extern volatile IOCON3BITS IOCON3bits __attribute__((__sfr__));

extern volatile unsigned int  FCLCON3 __attribute__((__sfr__));
__extension__ typedef struct tagFCLCON3BITS {
  union {
    struct {
      unsigned FLTMOD:2;
      unsigned FLTPOL:1;
      unsigned FLTSRC:5;
      unsigned CLMOD:1;
      unsigned CLPOL:1;
      unsigned CLSRC:5;
      unsigned IFLTMOD:1;
    };
    struct {
      unsigned FLTMOD0:1;
      unsigned FLTMOD1:1;
      unsigned :1;
      unsigned FLTSRC0:1;
      unsigned FLTSRC1:1;
      unsigned FLTSRC2:1;
      unsigned FLTSRC3:1;
      unsigned FLTSRC4:1;
      unsigned :2;
      unsigned CLSRC0:1;
      unsigned CLSRC1:1;
      unsigned CLSRC2:1;
      unsigned CLSRC3:1;
      unsigned CLSRC4:1;
    };
  };
} FCLCON3BITS;
extern volatile FCLCON3BITS FCLCON3bits __attribute__((__sfr__));

extern volatile unsigned int  PDC3 __attribute__((__sfr__));
extern volatile unsigned int  PHASE3 __attribute__((__sfr__));
extern volatile unsigned int  DTR3 __attribute__((__sfr__));
extern volatile unsigned int  ALTDTR3 __attribute__((__sfr__));
extern volatile unsigned int  SDC3 __attribute__((__sfr__));
extern volatile unsigned int  SPHASE3 __attribute__((__sfr__));
extern volatile unsigned int  TRIG3 __attribute__((__sfr__));
__extension__ typedef struct tagTRIG3BITS {
  union {
    struct {
      unsigned :3;
      unsigned TRGCMP:13;
    };
    struct {
      unsigned :3;
      unsigned TRGCMP0:1;
      unsigned TRGCMP1:1;
      unsigned TRGCMP2:1;
      unsigned TRGCMP3:1;
      unsigned TRGCMP4:1;
      unsigned TRGCMP5:1;
      unsigned TRGCMP6:1;
      unsigned TRGCMP7:1;
      unsigned TRGCMP8:1;
      unsigned TRGCMP9:1;
      unsigned TRGCMP10:1;
      unsigned TRGCMP11:1;
      unsigned TRGCMP12:1;
    };
  };
} TRIG3BITS;
extern volatile TRIG3BITS TRIG3bits __attribute__((__sfr__));

extern volatile unsigned int  TRGCON3 __attribute__((__sfr__));
__extension__ typedef struct tagTRGCON3BITS {
  union {
    struct {
      unsigned TRGSTRT:6;
      unsigned :1;
      unsigned DTM:1;
      unsigned :4;
      unsigned TRGDIV:4;
    };
    struct {
      unsigned TRGSTRT0:1;
      unsigned TRGSTRT1:1;
      unsigned TRGSTRT2:1;
      unsigned TRGSTRT3:1;
      unsigned TRGSTRT4:1;
      unsigned TRGSTRT5:1;
      unsigned :6;
      unsigned TRGDIV0:1;
      unsigned TRGDIV1:1;
      unsigned TRGDIV2:1;
      unsigned TRGDIV3:1;
    };
  };
} TRGCON3BITS;
extern volatile TRGCON3BITS TRGCON3bits __attribute__((__sfr__));

extern volatile unsigned int  STRIG3 __attribute__((__sfr__));
__extension__ typedef struct tagSTRIG3BITS {
  union {
    struct {
      unsigned :3;
      unsigned STRGCMP:13;
    };
    struct {
      unsigned :3;
      unsigned STRGCMP0:1;
      unsigned STRGCMP1:1;
      unsigned STRGCMP2:1;
      unsigned STRGCMP3:1;
      unsigned STRGCMP4:1;
      unsigned STRGCMP5:1;
      unsigned STRGCMP6:1;
      unsigned STRGCMP7:1;
      unsigned STRGCMP8:1;
      unsigned STRGCMP9:1;
      unsigned STRGCMP10:1;
      unsigned STRGCMP11:1;
      unsigned STRGCMP12:1;
    };
  };
} STRIG3BITS;
extern volatile STRIG3BITS STRIG3bits __attribute__((__sfr__));

extern volatile unsigned int  PWMCAP3 __attribute__((__sfr__));
extern volatile unsigned int  LEBCON3 __attribute__((__sfr__));
__extension__ typedef struct tagLEBCON3BITS {
  union {
    struct {
      unsigned :3;
      unsigned LEB:7;
      unsigned CLLEBEN:1;
      unsigned FLTLEBEN:1;
      unsigned PLF:1;
      unsigned PLR:1;
      unsigned PHF:1;
      unsigned PHR:1;
    };
    struct {
      unsigned :3;
      unsigned LEB0:1;
      unsigned LEB1:1;
      unsigned LEB2:1;
      unsigned LEB3:1;
      unsigned LEB4:1;
      unsigned LEB5:1;
      unsigned LEB6:1;
    };
  };
} LEBCON3BITS;
extern volatile LEBCON3BITS LEBCON3bits __attribute__((__sfr__));

extern volatile unsigned int  PWMCON4 __attribute__((__sfr__));
__extension__ typedef struct tagPWMCON4BITS {
  union {
    struct {
      unsigned IUE:1;
      unsigned XPRES:1;
      unsigned CAM:1;
      unsigned :3;
      unsigned DTC:2;
      unsigned MDCS:1;
      unsigned ITB:1;
      unsigned TRGIEN:1;
      unsigned CLIEN:1;
      unsigned FLTIEN:1;
      unsigned TRGSTAT:1;
      unsigned CLSTAT:1;
      unsigned FLTSTAT:1;
    };
    struct {
      unsigned :6;
      unsigned DTC0:1;
      unsigned DTC1:1;
    };
  };
} PWMCON4BITS;
extern volatile PWMCON4BITS PWMCON4bits __attribute__((__sfr__));

extern volatile unsigned int  IOCON4 __attribute__((__sfr__));
__extension__ typedef struct tagIOCON4BITS {
  union {
    struct {
      unsigned OSYNC:1;
      unsigned SWAP:1;
      unsigned CLDAT:2;
      unsigned FLTDAT:2;
      unsigned OVRDAT:2;
      unsigned OVRENL:1;
      unsigned OVRENH:1;
      unsigned PMOD:2;
      unsigned POLL:1;
      unsigned POLH:1;
      unsigned PENL:1;
      unsigned PENH:1;
    };
    struct {
      unsigned :2;
      unsigned CLDAT0:1;
      unsigned CLDAT1:1;
      unsigned FLTDAT0:1;
      unsigned FLTDAT1:1;
      unsigned OVRDAT0:1;
      unsigned OVRDAT1:1;
      unsigned :2;
      unsigned PMOD0:1;
      unsigned PMOD1:1;
    };
  };
} IOCON4BITS;
extern volatile IOCON4BITS IOCON4bits __attribute__((__sfr__));

extern volatile unsigned int  FCLCON4 __attribute__((__sfr__));
__extension__ typedef struct tagFCLCON4BITS {
  union {
    struct {
      unsigned FLTMOD:2;
      unsigned FLTPOL:1;
      unsigned FLTSRC:5;
      unsigned CLMOD:1;
      unsigned CLPOL:1;
      unsigned CLSRC:5;
      unsigned IFLTMOD:1;
    };
    struct {
      unsigned FLTMOD0:1;
      unsigned FLTMOD1:1;
      unsigned :1;
      unsigned FLTSRC0:1;
      unsigned FLTSRC1:1;
      unsigned FLTSRC2:1;
      unsigned FLTSRC3:1;
      unsigned FLTSRC4:1;
      unsigned :2;
      unsigned CLSRC0:1;
      unsigned CLSRC1:1;
      unsigned CLSRC2:1;
      unsigned CLSRC3:1;
      unsigned CLSRC4:1;
    };
  };
} FCLCON4BITS;
extern volatile FCLCON4BITS FCLCON4bits __attribute__((__sfr__));

extern volatile unsigned int  PDC4 __attribute__((__sfr__));
extern volatile unsigned int  PHASE4 __attribute__((__sfr__));
extern volatile unsigned int  DTR4 __attribute__((__sfr__));
extern volatile unsigned int  ALTDTR4 __attribute__((__sfr__));
extern volatile unsigned int  SDC4 __attribute__((__sfr__));
extern volatile unsigned int  SPHASE4 __attribute__((__sfr__));
extern volatile unsigned int  TRIG4 __attribute__((__sfr__));
__extension__ typedef struct tagTRIG4BITS {
  union {
    struct {
      unsigned :3;
      unsigned TRGCMP:13;
    };
    struct {
      unsigned :3;
      unsigned TRGCMP0:1;
      unsigned TRGCMP1:1;
      unsigned TRGCMP2:1;
      unsigned TRGCMP3:1;
      unsigned TRGCMP4:1;
      unsigned TRGCMP5:1;
      unsigned TRGCMP6:1;
      unsigned TRGCMP7:1;
      unsigned TRGCMP8:1;
      unsigned TRGCMP9:1;
      unsigned TRGCMP10:1;
      unsigned TRGCMP11:1;
      unsigned TRGCMP12:1;
    };
  };
} TRIG4BITS;
extern volatile TRIG4BITS TRIG4bits __attribute__((__sfr__));

extern volatile unsigned int  TRGCON4 __attribute__((__sfr__));
__extension__ typedef struct tagTRGCON4BITS {
  union {
    struct {
      unsigned TRGSTRT:6;
      unsigned :1;
      unsigned DTM:1;
      unsigned :4;
      unsigned TRGDIV:4;
    };
    struct {
      unsigned TRGSTRT0:1;
      unsigned TRGSTRT1:1;
      unsigned TRGSTRT2:1;
      unsigned TRGSTRT3:1;
      unsigned TRGSTRT4:1;
      unsigned TRGSTRT5:1;
      unsigned :6;
      unsigned TRGDIV0:1;
      unsigned TRGDIV1:1;
      unsigned TRGDIV2:1;
      unsigned TRGDIV3:1;
    };
  };
} TRGCON4BITS;
extern volatile TRGCON4BITS TRGCON4bits __attribute__((__sfr__));

extern volatile unsigned int  STRIG4 __attribute__((__sfr__));
__extension__ typedef struct tagSTRIG4BITS {
  union {
    struct {
      unsigned :3;
      unsigned STRGCMP:13;
    };
    struct {
      unsigned :3;
      unsigned STRGCMP0:1;
      unsigned STRGCMP1:1;
      unsigned STRGCMP2:1;
      unsigned STRGCMP3:1;
      unsigned STRGCMP4:1;
      unsigned STRGCMP5:1;
      unsigned STRGCMP6:1;
      unsigned STRGCMP7:1;
      unsigned STRGCMP8:1;
      unsigned STRGCMP9:1;
      unsigned STRGCMP10:1;
      unsigned STRGCMP11:1;
      unsigned STRGCMP12:1;
    };
  };
} STRIG4BITS;
extern volatile STRIG4BITS STRIG4bits __attribute__((__sfr__));

extern volatile unsigned int  PWMCAP4 __attribute__((__sfr__));
extern volatile unsigned int  LEBCON4 __attribute__((__sfr__));
__extension__ typedef struct tagLEBCON4BITS {
  union {
    struct {
      unsigned :3;
      unsigned LEB:7;
      unsigned CLLEBEN:1;
      unsigned FLTLEBEN:1;
      unsigned PLF:1;
      unsigned PLR:1;
      unsigned PHF:1;
      unsigned PHR:1;
    };
    struct {
      unsigned :3;
      unsigned LEB0:1;
      unsigned LEB1:1;
      unsigned LEB2:1;
      unsigned LEB3:1;
      unsigned LEB4:1;
      unsigned LEB5:1;
      unsigned LEB6:1;
    };
  };
} LEBCON4BITS;
extern volatile LEBCON4BITS LEBCON4bits __attribute__((__sfr__));

extern volatile unsigned int  CMPCON1 __attribute__((__sfr__));
__extension__ typedef struct tagCMPCON1BITS {
  union {
    struct {
      unsigned RANGE:1;
      unsigned CMPPOL:1;
      unsigned :1;
      unsigned CMPSTAT:1;
      unsigned :1;
      unsigned EXTREF:1;
      unsigned INSEL:2;
      unsigned DACOE:1;
      unsigned :4;
      unsigned CMPSIDL:1;
      unsigned :1;
      unsigned CMPON:1;
    };
    struct {
      unsigned :6;
      unsigned INSEL0:1;
      unsigned INSEL1:1;
    };
  };
} CMPCON1BITS;
extern volatile CMPCON1BITS CMPCON1bits __attribute__((__sfr__));

extern volatile unsigned int  CMPDAC1 __attribute__((__sfr__));
__extension__ typedef struct tagCMPDAC1BITS {
  union {
    struct {
      unsigned CMREF:10;
    };
    struct {
      unsigned CMREF0:1;
      unsigned CMREF1:1;
      unsigned CMREF2:1;
      unsigned CMREF3:1;
      unsigned CMREF4:1;
      unsigned CMREF5:1;
      unsigned CMREF6:1;
      unsigned CMREF7:1;
      unsigned CMREF8:1;
      unsigned CMREF9:1;
    };
  };
} CMPDAC1BITS;
extern volatile CMPDAC1BITS CMPDAC1bits __attribute__((__sfr__));

extern volatile unsigned int  CMPCON2 __attribute__((__sfr__));
__extension__ typedef struct tagCMPCON2BITS {
  union {
    struct {
      unsigned RANGE:1;
      unsigned CMPPOL:1;
      unsigned :1;
      unsigned CMPSTAT:1;
      unsigned :1;
      unsigned EXTREF:1;
      unsigned INSEL:2;
      unsigned DACOE:1;
      unsigned :4;
      unsigned CMPSIDL:1;
      unsigned :1;
      unsigned CMPON:1;
    };
    struct {
      unsigned :6;
      unsigned INSEL0:1;
      unsigned INSEL1:1;
    };
  };
} CMPCON2BITS;
extern volatile CMPCON2BITS CMPCON2bits __attribute__((__sfr__));

extern volatile unsigned int  CMPDAC2 __attribute__((__sfr__));
__extension__ typedef struct tagCMPDAC2BITS {
  union {
    struct {
      unsigned CMREF:10;
    };
    struct {
      unsigned CMREF0:1;
      unsigned CMREF1:1;
      unsigned CMREF2:1;
      unsigned CMREF3:1;
      unsigned CMREF4:1;
      unsigned CMREF5:1;
      unsigned CMREF6:1;
      unsigned CMREF7:1;
      unsigned CMREF8:1;
      unsigned CMREF9:1;
    };
  };
} CMPDAC2BITS;
extern volatile CMPDAC2BITS CMPDAC2bits __attribute__((__sfr__));

extern volatile unsigned int  CMPCON3 __attribute__((__sfr__));
__extension__ typedef struct tagCMPCON3BITS {
  union {
    struct {
      unsigned RANGE:1;
      unsigned CMPPOL:1;
      unsigned :1;
      unsigned CMPSTAT:1;
      unsigned :1;
      unsigned EXTREF:1;
      unsigned INSEL:2;
      unsigned DACOE:1;
      unsigned :4;
      unsigned CMPSIDL:1;
      unsigned :1;
      unsigned CMPON:1;
    };
    struct {
      unsigned :6;
      unsigned INSEL0:1;
      unsigned INSEL1:1;
    };
  };
} CMPCON3BITS;
extern volatile CMPCON3BITS CMPCON3bits __attribute__((__sfr__));

extern volatile unsigned int  CMPDAC3 __attribute__((__sfr__));
__extension__ typedef struct tagCMPDAC3BITS {
  union {
    struct {
      unsigned CMREF:10;
    };
    struct {
      unsigned CMREF0:1;
      unsigned CMREF1:1;
      unsigned CMREF2:1;
      unsigned CMREF3:1;
      unsigned CMREF4:1;
      unsigned CMREF5:1;
      unsigned CMREF6:1;
      unsigned CMREF7:1;
      unsigned CMREF8:1;
      unsigned CMREF9:1;
    };
  };
} CMPDAC3BITS;
extern volatile CMPDAC3BITS CMPDAC3bits __attribute__((__sfr__));

extern volatile unsigned int  CMPCON4 __attribute__((__sfr__));
__extension__ typedef struct tagCMPCON4BITS {
  union {
    struct {
      unsigned RANGE:1;
      unsigned CMPPOL:1;
      unsigned :1;
      unsigned CMPSTAT:1;
      unsigned :1;
      unsigned EXTREF:1;
      unsigned INSEL:2;
      unsigned DACOE:1;
      unsigned :4;
      unsigned CMPSIDL:1;
      unsigned :1;
      unsigned CMPON:1;
    };
    struct {
      unsigned :6;
      unsigned INSEL0:1;
      unsigned INSEL1:1;
    };
  };
} CMPCON4BITS;
extern volatile CMPCON4BITS CMPCON4bits __attribute__((__sfr__));

extern volatile unsigned int  CMPDAC4 __attribute__((__sfr__));
__extension__ typedef struct tagCMPDAC4BITS {
  union {
    struct {
      unsigned CMREF:10;
    };
    struct {
      unsigned CMREF0:1;
      unsigned CMREF1:1;
      unsigned CMREF2:1;
      unsigned CMREF3:1;
      unsigned CMREF4:1;
      unsigned CMREF5:1;
      unsigned CMREF6:1;
      unsigned CMREF7:1;
      unsigned CMREF8:1;
      unsigned CMREF9:1;
    };
  };
} CMPDAC4BITS;
extern volatile CMPDAC4BITS CMPDAC4bits __attribute__((__sfr__));

extern volatile unsigned int  RPINR0 __attribute__((__sfr__));
__extension__ typedef struct tagRPINR0BITS {
  union {
    struct {
      unsigned :8;
      unsigned INT1R:6;
    };
    struct {
      unsigned :8;
      unsigned INT1R0:1;
      unsigned INT1R1:1;
      unsigned INT1R2:1;
      unsigned INT1R3:1;
      unsigned INT1R4:1;
      unsigned INT1R5:1;
    };
  };
} RPINR0BITS;
extern volatile RPINR0BITS RPINR0bits __attribute__((__sfr__));

extern volatile unsigned int  RPINR1 __attribute__((__sfr__));
__extension__ typedef struct tagRPINR1BITS {
  union {
    struct {
      unsigned INT2R:6;
    };
    struct {
      unsigned INT2R0:1;
      unsigned INT2R1:1;
      unsigned INT2R2:1;
      unsigned INT2R3:1;
      unsigned INT2R4:1;
      unsigned INT2R5:1;
    };
  };
} RPINR1BITS;
extern volatile RPINR1BITS RPINR1bits __attribute__((__sfr__));

extern volatile unsigned int  RPINR2 __attribute__((__sfr__));
__extension__ typedef struct tagRPINR2BITS {
  union {
    struct {
      unsigned :8;
      unsigned T1CKR:6;
    };
    struct {
      unsigned :8;
      unsigned T1CKR0:1;
      unsigned T1CKR1:1;
      unsigned T1CKR2:1;
      unsigned T1CKR3:1;
      unsigned T1CKR4:1;
      unsigned T1CKR5:1;
    };
  };
} RPINR2BITS;
extern volatile RPINR2BITS RPINR2bits __attribute__((__sfr__));

extern volatile unsigned int  RPINR3 __attribute__((__sfr__));
__extension__ typedef struct tagRPINR3BITS {
  union {
    struct {
      unsigned T2CKR:6;
      unsigned :2;
      unsigned T3CKR:6;
    };
    struct {
      unsigned T2CKR0:1;
      unsigned T2CKR1:1;
      unsigned T2CKR2:1;
      unsigned T2CKR3:1;
      unsigned T2CKR4:1;
      unsigned T2CKR5:1;
      unsigned :2;
      unsigned T3CKR0:1;
      unsigned T3CKR1:1;
      unsigned T3CKR2:1;
      unsigned T3CKR3:1;
      unsigned T3CKR4:1;
      unsigned T3CKR5:1;
    };
  };
} RPINR3BITS;
extern volatile RPINR3BITS RPINR3bits __attribute__((__sfr__));

extern volatile unsigned int  RPINR7 __attribute__((__sfr__));
__extension__ typedef struct tagRPINR7BITS {
  union {
    struct {
      unsigned IC1R:6;
      unsigned :2;
      unsigned IC2R:6;
    };
    struct {
      unsigned IC1R0:1;
      unsigned IC1R1:1;
      unsigned IC1R2:1;
      unsigned IC1R3:1;
      unsigned IC1R4:1;
      unsigned IC1R5:1;
      unsigned :2;
      unsigned IC2R0:1;
      unsigned IC2R1:1;
      unsigned IC2R2:1;
      unsigned IC2R3:1;
      unsigned IC2R4:1;
      unsigned IC2R5:1;
    };
  };
} RPINR7BITS;
extern volatile RPINR7BITS RPINR7bits __attribute__((__sfr__));

extern volatile unsigned int  RPINR11 __attribute__((__sfr__));
__extension__ typedef struct tagRPINR11BITS {
  union {
    struct {
      unsigned OCFAR:6;
    };
    struct {
      unsigned OCFAR0:1;
      unsigned OCFAR1:1;
      unsigned OCFAR2:1;
      unsigned OCFAR3:1;
      unsigned OCFAR4:1;
      unsigned OCFAR5:1;
    };
  };
} RPINR11BITS;
extern volatile RPINR11BITS RPINR11bits __attribute__((__sfr__));

extern volatile unsigned int  RPINR18 __attribute__((__sfr__));
__extension__ typedef struct tagRPINR18BITS {
  union {
    struct {
      unsigned U1RXR:6;
      unsigned :2;
      unsigned U1CTSR:6;
    };
    struct {
      unsigned U1RXR0:1;
      unsigned U1RXR1:1;
      unsigned U1RXR2:1;
      unsigned U1RXR3:1;
      unsigned U1RXR4:1;
      unsigned U1RXR5:1;
      unsigned :2;
      unsigned U1CTSR0:1;
      unsigned U1CTSR1:1;
      unsigned U1CTSR2:1;
      unsigned U1CTSR3:1;
      unsigned U1CTSR4:1;
      unsigned U1CTSR5:1;
    };
  };
} RPINR18BITS;
extern volatile RPINR18BITS RPINR18bits __attribute__((__sfr__));

extern volatile unsigned int  RPINR20 __attribute__((__sfr__));
__extension__ typedef struct tagRPINR20BITS {
  union {
    struct {
      unsigned SDI1R:6;
      unsigned :2;
      unsigned SCK1R:6;
    };
    struct {
      unsigned SDI1R0:1;
      unsigned SDI1R1:1;
      unsigned SDI1R2:1;
      unsigned SDI1R3:1;
      unsigned SDI1R4:1;
      unsigned SDI1R5:1;
      unsigned :2;
      unsigned SCK1R0:1;
      unsigned SCK1R1:1;
      unsigned SCK1R2:1;
      unsigned SCK1R3:1;
      unsigned SCK1R4:1;
      unsigned SCK1R5:1;
    };
  };
} RPINR20BITS;
extern volatile RPINR20BITS RPINR20bits __attribute__((__sfr__));

extern volatile unsigned int  RPINR21 __attribute__((__sfr__));
__extension__ typedef struct tagRPINR21BITS {
  union {
    struct {
      unsigned SS1R:6;
    };
    struct {
      unsigned SS1R0:1;
      unsigned SS1R1:1;
      unsigned SS1R2:1;
      unsigned SS1R3:1;
      unsigned SS1R4:1;
      unsigned SS1R5:1;
    };
  };
} RPINR21BITS;
extern volatile RPINR21BITS RPINR21bits __attribute__((__sfr__));

extern volatile unsigned int  RPINR29 __attribute__((__sfr__));
__extension__ typedef struct tagRPINR29BITS {
  union {
    struct {
      unsigned :8;
      unsigned FLT1R:6;
    };
    struct {
      unsigned :8;
      unsigned FLT1R0:1;
      unsigned FLT1R1:1;
      unsigned FLT1R2:1;
      unsigned FLT1R3:1;
      unsigned FLT1R4:1;
      unsigned FLT1R5:1;
    };
  };
} RPINR29BITS;
extern volatile RPINR29BITS RPINR29bits __attribute__((__sfr__));

extern volatile unsigned int  RPINR30 __attribute__((__sfr__));
__extension__ typedef struct tagRPINR30BITS {
  union {
    struct {
      unsigned FLT2R:6;
      unsigned :2;
      unsigned FLT3R:6;
    };
    struct {
      unsigned FLT2R0:1;
      unsigned FLT2R1:1;
      unsigned FLT2R2:1;
      unsigned FLT2R3:1;
      unsigned FLT2R4:1;
      unsigned FLT2R5:1;
      unsigned :2;
      unsigned FLT3R0:1;
      unsigned FLT3R1:1;
      unsigned FLT3R2:1;
      unsigned FLT3R3:1;
      unsigned FLT3R4:1;
      unsigned FLT3R5:1;
    };
  };
} RPINR30BITS;
extern volatile RPINR30BITS RPINR30bits __attribute__((__sfr__));

extern volatile unsigned int  RPINR31 __attribute__((__sfr__));
__extension__ typedef struct tagRPINR31BITS {
  union {
    struct {
      unsigned FLT4R:6;
      unsigned :2;
      unsigned FLT5R:6;
    };
    struct {
      unsigned FLT4R0:1;
      unsigned FLT4R1:1;
      unsigned FLT4R2:1;
      unsigned FLT4R3:1;
      unsigned FLT4R4:1;
      unsigned FLT4R5:1;
      unsigned :2;
      unsigned FLT5R0:1;
      unsigned FLT5R1:1;
      unsigned FLT5R2:1;
      unsigned FLT5R3:1;
      unsigned FLT5R4:1;
      unsigned FLT5R5:1;
    };
  };
} RPINR31BITS;
extern volatile RPINR31BITS RPINR31bits __attribute__((__sfr__));

extern volatile unsigned int  RPINR32 __attribute__((__sfr__));
__extension__ typedef struct tagRPINR32BITS {
  union {
    struct {
      unsigned FLT6R:6;
      unsigned :2;
      unsigned FLT7R:6;
    };
    struct {
      unsigned FLT6R0:1;
      unsigned FLT6R1:1;
      unsigned FLT6R2:1;
      unsigned FLT6R3:1;
      unsigned FLT6R4:1;
      unsigned FLT6R5:1;
      unsigned :2;
      unsigned FLT7R0:1;
      unsigned FLT7R1:1;
      unsigned FLT7R2:1;
      unsigned FLT7R3:1;
      unsigned FLT7R4:1;
      unsigned FLT7R5:1;
    };
  };
} RPINR32BITS;
extern volatile RPINR32BITS RPINR32bits __attribute__((__sfr__));

extern volatile unsigned int  RPINR33 __attribute__((__sfr__));
__extension__ typedef struct tagRPINR33BITS {
  union {
    struct {
      unsigned FLT8R:6;
      unsigned :2;
      unsigned SYNCI1R:6;
    };
    struct {
      unsigned FLT8R0:1;
      unsigned FLT8R1:1;
      unsigned FLT8R2:1;
      unsigned FLT8R3:1;
      unsigned FLT8R4:1;
      unsigned FLT8R5:1;
      unsigned :2;
      unsigned SYNCI1R0:1;
      unsigned SYNCI1R1:1;
      unsigned SYNCI1R2:1;
      unsigned SYNCI1R3:1;
      unsigned SYNCI1R4:1;
      unsigned SYNCI1R5:1;
    };
  };
} RPINR33BITS;
extern volatile RPINR33BITS RPINR33bits __attribute__((__sfr__));

extern volatile unsigned int  RPINR34 __attribute__((__sfr__));
__extension__ typedef struct tagRPINR34BITS {
  union {
    struct {
      unsigned SYNCI2R:6;
    };
    struct {
      unsigned SYNCI2R0:1;
      unsigned SYNCI2R1:1;
      unsigned SYNCI2R2:1;
      unsigned SYNCI2R3:1;
      unsigned SYNCI2R4:1;
      unsigned SYNCI2R5:1;
    };
  };
} RPINR34BITS;
extern volatile RPINR34BITS RPINR34bits __attribute__((__sfr__));

extern volatile unsigned int  RPOR0 __attribute__((__sfr__));
__extension__ typedef struct tagRPOR0BITS {
  union {
    struct {
      unsigned RP0R:6;
      unsigned :2;
      unsigned RP1R:6;
    };
    struct {
      unsigned RP0R0:1;
      unsigned RP0R1:1;
      unsigned RP0R2:1;
      unsigned RP0R3:1;
      unsigned RP0R4:1;
      unsigned RP0R5:1;
      unsigned :2;
      unsigned RP1R0:1;
      unsigned RP1R1:1;
      unsigned RP1R2:1;
      unsigned RP1R3:1;
      unsigned RP1R4:1;
      unsigned RP1R5:1;
    };
  };
} RPOR0BITS;
extern volatile RPOR0BITS RPOR0bits __attribute__((__sfr__));

extern volatile unsigned int  RPOR1 __attribute__((__sfr__));
__extension__ typedef struct tagRPOR1BITS {
  union {
    struct {
      unsigned RP2R:6;
      unsigned :2;
      unsigned RP3R:6;
    };
    struct {
      unsigned RP2R0:1;
      unsigned RP2R1:1;
      unsigned RP2R2:1;
      unsigned RP2R3:1;
      unsigned RP2R4:1;
      unsigned RP2R5:1;
      unsigned :2;
      unsigned RP3R0:1;
      unsigned RP3R1:1;
      unsigned RP3R2:1;
      unsigned RP3R3:1;
      unsigned RP3R4:1;
      unsigned RP3R5:1;
    };
  };
} RPOR1BITS;
extern volatile RPOR1BITS RPOR1bits __attribute__((__sfr__));

extern volatile unsigned int  RPOR2 __attribute__((__sfr__));
__extension__ typedef struct tagRPOR2BITS {
  union {
    struct {
      unsigned RP4R:6;
      unsigned :2;
      unsigned RP5R:6;
    };
    struct {
      unsigned RP4R0:1;
      unsigned RP4R1:1;
      unsigned RP4R2:1;
      unsigned RP4R3:1;
      unsigned RP4R4:1;
      unsigned RP4R5:1;
      unsigned :2;
      unsigned RP5R0:1;
      unsigned RP5R1:1;
      unsigned RP5R2:1;
      unsigned RP5R3:1;
      unsigned RP5R4:1;
      unsigned RP5R5:1;
    };
  };
} RPOR2BITS;
extern volatile RPOR2BITS RPOR2bits __attribute__((__sfr__));

extern volatile unsigned int  RPOR3 __attribute__((__sfr__));
__extension__ typedef struct tagRPOR3BITS {
  union {
    struct {
      unsigned RP6R:6;
      unsigned :2;
      unsigned RP7R:6;
    };
    struct {
      unsigned RP6R0:1;
      unsigned RP6R1:1;
      unsigned RP6R2:1;
      unsigned RP6R3:1;
      unsigned RP6R4:1;
      unsigned RP6R5:1;
      unsigned :2;
      unsigned RP7R0:1;
      unsigned RP7R1:1;
      unsigned RP7R2:1;
      unsigned RP7R3:1;
      unsigned RP7R4:1;
      unsigned RP7R5:1;
    };
  };
} RPOR3BITS;
extern volatile RPOR3BITS RPOR3bits __attribute__((__sfr__));

extern volatile unsigned int  RPOR4 __attribute__((__sfr__));
__extension__ typedef struct tagRPOR4BITS {
  union {
    struct {
      unsigned RP8R:6;
      unsigned :2;
      unsigned RP9R:6;
    };
    struct {
      unsigned RP8R0:1;
      unsigned RP8R1:1;
      unsigned RP8R2:1;
      unsigned RP8R3:1;
      unsigned RP8R4:1;
      unsigned RP8R5:1;
      unsigned :2;
      unsigned RP9R0:1;
      unsigned RP9R1:1;
      unsigned RP9R2:1;
      unsigned RP9R3:1;
      unsigned RP9R4:1;
      unsigned RP9R5:1;
    };
  };
} RPOR4BITS;
extern volatile RPOR4BITS RPOR4bits __attribute__((__sfr__));

extern volatile unsigned int  RPOR5 __attribute__((__sfr__));
__extension__ typedef struct tagRPOR5BITS {
  union {
    struct {
      unsigned RP10R:6;
      unsigned :2;
      unsigned RP11R:6;
    };
    struct {
      unsigned RP10R0:1;
      unsigned RP10R1:1;
      unsigned RP10R2:1;
      unsigned RP10R3:1;
      unsigned RP10R4:1;
      unsigned RP10R5:1;
      unsigned :2;
      unsigned RP11R0:1;
      unsigned RP11R1:1;
      unsigned RP11R2:1;
      unsigned RP11R3:1;
      unsigned RP11R4:1;
      unsigned RP11R5:1;
    };
  };
} RPOR5BITS;
extern volatile RPOR5BITS RPOR5bits __attribute__((__sfr__));

extern volatile unsigned int  RPOR6 __attribute__((__sfr__));
__extension__ typedef struct tagRPOR6BITS {
  union {
    struct {
      unsigned RP12R:6;
      unsigned :2;
      unsigned RP13R:6;
    };
    struct {
      unsigned RP12R0:1;
      unsigned RP12R1:1;
      unsigned RP12R2:1;
      unsigned RP12R3:1;
      unsigned RP12R4:1;
      unsigned RP12R5:1;
      unsigned :2;
      unsigned RP13R0:1;
      unsigned RP13R1:1;
      unsigned RP13R2:1;
      unsigned RP13R3:1;
      unsigned RP13R4:1;
      unsigned RP13R5:1;
    };
  };
} RPOR6BITS;
extern volatile RPOR6BITS RPOR6bits __attribute__((__sfr__));

extern volatile unsigned int  RPOR7 __attribute__((__sfr__));
__extension__ typedef struct tagRPOR7BITS {
  union {
    struct {
      unsigned RP14R:6;
      unsigned :2;
      unsigned RP15R:6;
    };
    struct {
      unsigned RP14R0:1;
      unsigned RP14R1:1;
      unsigned RP14R2:1;
      unsigned RP14R3:1;
      unsigned RP14R4:1;
      unsigned RP14R5:1;
      unsigned :2;
      unsigned RP15R0:1;
      unsigned RP15R1:1;
      unsigned RP15R2:1;
      unsigned RP15R3:1;
      unsigned RP15R4:1;
      unsigned RP15R5:1;
    };
  };
} RPOR7BITS;
extern volatile RPOR7BITS RPOR7bits __attribute__((__sfr__));

extern volatile unsigned int  RPOR8 __attribute__((__sfr__));
__extension__ typedef struct tagRPOR8BITS {
  union {
    struct {
      unsigned RP16R:6;
      unsigned :2;
      unsigned RP17R:6;
    };
    struct {
      unsigned RP16R0:1;
      unsigned RP16R1:1;
      unsigned RP16R2:1;
      unsigned RP16R3:1;
      unsigned RP16R4:1;
      unsigned RP16R5:1;
      unsigned :2;
      unsigned RP17R0:1;
      unsigned RP17R1:1;
      unsigned RP17R2:1;
      unsigned RP17R3:1;
      unsigned RP17R4:1;
      unsigned RP17R5:1;
    };
  };
} RPOR8BITS;
extern volatile RPOR8BITS RPOR8bits __attribute__((__sfr__));

extern volatile unsigned int  RPOR9 __attribute__((__sfr__));
__extension__ typedef struct tagRPOR9BITS {
  union {
    struct {
      unsigned RP18R:6;
      unsigned :2;
      unsigned RP19R:6;
    };
    struct {
      unsigned RP18R0:1;
      unsigned RP18R1:1;
      unsigned RP18R2:1;
      unsigned RP18R3:1;
      unsigned RP18R4:1;
      unsigned RP18R5:1;
      unsigned :2;
      unsigned RP19R0:1;
      unsigned RP19R1:1;
      unsigned RP19R2:1;
      unsigned RP19R3:1;
      unsigned RP19R4:1;
      unsigned RP19R5:1;
    };
  };
} RPOR9BITS;
extern volatile RPOR9BITS RPOR9bits __attribute__((__sfr__));

extern volatile unsigned int  RPOR10 __attribute__((__sfr__));
__extension__ typedef struct tagRPOR10BITS {
  union {
    struct {
      unsigned RP20R:6;
      unsigned :2;
      unsigned RP21R:6;
    };
    struct {
      unsigned RP20R0:1;
      unsigned RP20R1:1;
      unsigned RP20R2:1;
      unsigned RP20R3:1;
      unsigned RP20R4:1;
      unsigned RP20R5:1;
      unsigned :2;
      unsigned RP21R0:1;
      unsigned RP21R1:1;
      unsigned RP21R2:1;
      unsigned RP21R3:1;
      unsigned RP21R4:1;
      unsigned RP21R5:1;
    };
  };
} RPOR10BITS;
extern volatile RPOR10BITS RPOR10bits __attribute__((__sfr__));

extern volatile unsigned int  RPOR11 __attribute__((__sfr__));
__extension__ typedef struct tagRPOR11BITS {
  union {
    struct {
      unsigned RP22R:6;
      unsigned :2;
      unsigned RP23R:6;
    };
    struct {
      unsigned RP22R0:1;
      unsigned RP22R1:1;
      unsigned RP22R2:1;
      unsigned RP22R3:1;
      unsigned RP22R4:1;
      unsigned RP22R5:1;
      unsigned :2;
      unsigned RP23R0:1;
      unsigned RP23R1:1;
      unsigned RP23R2:1;
      unsigned RP23R3:1;
      unsigned RP23R4:1;
      unsigned RP23R5:1;
    };
  };
} RPOR11BITS;
extern volatile RPOR11BITS RPOR11bits __attribute__((__sfr__));

extern volatile unsigned int  RPOR12 __attribute__((__sfr__));
__extension__ typedef struct tagRPOR12BITS {
  union {
    struct {
      unsigned RP24R:6;
      unsigned :2;
      unsigned RP25R:6;
    };
    struct {
      unsigned RP24R0:1;
      unsigned RP24R1:1;
      unsigned RP24R2:1;
      unsigned RP24R3:1;
      unsigned RP24R4:1;
      unsigned RP24R5:1;
      unsigned :2;
      unsigned RP25R0:1;
      unsigned RP25R1:1;
      unsigned RP25R2:1;
      unsigned RP25R3:1;
      unsigned RP25R4:1;
      unsigned RP25R5:1;
    };
  };
} RPOR12BITS;
extern volatile RPOR12BITS RPOR12bits __attribute__((__sfr__));

extern volatile unsigned int  RPOR13 __attribute__((__sfr__));
__extension__ typedef struct tagRPOR13BITS {
  union {
    struct {
      unsigned RP26R:6;
      unsigned :2;
      unsigned RP27R:6;
    };
    struct {
      unsigned RP26R0:1;
      unsigned RP26R1:1;
      unsigned RP26R2:1;
      unsigned RP26R3:1;
      unsigned RP26R4:1;
      unsigned RP26R5:1;
      unsigned :2;
      unsigned RP27R0:1;
      unsigned RP27R1:1;
      unsigned RP27R2:1;
      unsigned RP27R3:1;
      unsigned RP27R4:1;
      unsigned RP27R5:1;
    };
  };
} RPOR13BITS;
extern volatile RPOR13BITS RPOR13bits __attribute__((__sfr__));

extern volatile unsigned int  RPOR14 __attribute__((__sfr__));
__extension__ typedef struct tagRPOR14BITS {
  union {
    struct {
      unsigned RP28R:6;
      unsigned :2;
      unsigned RP29R:6;
    };
    struct {
      unsigned RP28R0:1;
      unsigned RP28R1:1;
      unsigned RP28R2:1;
      unsigned RP28R3:1;
      unsigned RP28R4:1;
      unsigned RP28R5:1;
      unsigned :2;
      unsigned RP29R0:1;
      unsigned RP29R1:1;
      unsigned RP29R2:1;
      unsigned RP29R3:1;
      unsigned RP29R4:1;
      unsigned RP29R5:1;
    };
  };
} RPOR14BITS;
extern volatile RPOR14BITS RPOR14bits __attribute__((__sfr__));

extern volatile unsigned int  RPOR16 __attribute__((__sfr__));
__extension__ typedef struct tagRPOR16BITS {
  union {
    struct {
      unsigned RP32R:6;
      unsigned :2;
      unsigned RP33R:6;
    };
    struct {
      unsigned RP32R0:1;
      unsigned RP32R1:1;
      unsigned RP32R2:1;
      unsigned RP32R3:1;
      unsigned RP32R4:1;
      unsigned RP32R5:1;
      unsigned :2;
      unsigned RP33R0:1;
      unsigned RP33R1:1;
      unsigned RP33R2:1;
      unsigned RP33R3:1;
      unsigned RP33R4:1;
      unsigned RP33R5:1;
    };
  };
} RPOR16BITS;
extern volatile RPOR16BITS RPOR16bits __attribute__((__sfr__));

extern volatile unsigned int  RPOR17 __attribute__((__sfr__));
__extension__ typedef struct tagRPOR17BITS {
  union {
    struct {
      unsigned RP34R:6;
      unsigned :2;
      unsigned RP35R:6;
    };
    struct {
      unsigned RP34R0:1;
      unsigned RP34R1:1;
      unsigned RP34R2:1;
      unsigned RP34R3:1;
      unsigned RP34R4:1;
      unsigned RP34R5:1;
      unsigned :2;
      unsigned RP35R0:1;
      unsigned RP35R1:1;
      unsigned RP35R2:1;
      unsigned RP35R3:1;
      unsigned RP35R4:1;
      unsigned RP35R5:1;
    };
  };
} RPOR17BITS;
extern volatile RPOR17BITS RPOR17bits __attribute__((__sfr__));

extern volatile unsigned int  RCON __attribute__((__sfr__));
typedef struct tagRCONBITS {
  unsigned POR:1;
  unsigned BOR:1;
  unsigned IDLE:1;
  unsigned SLEEP:1;
  unsigned WDTO:1;
  unsigned SWDTEN:1;
  unsigned SWR:1;
  unsigned EXTR:1;
  unsigned VREGS:1;
  unsigned CM:1;
  unsigned :4;
  unsigned IOPUWR:1;
  unsigned TRAPR:1;
} RCONBITS;
extern volatile RCONBITS RCONbits __attribute__((__sfr__));

extern volatile unsigned int  OSCCON __attribute__((__sfr__));
__extension__ typedef struct tagOSCCONBITS {
  union {
    struct {
      unsigned OSWEN:1;
      unsigned :2;
      unsigned CF:1;
      unsigned :1;
      unsigned LOCK:1;
      unsigned IOLOCK:1;
      unsigned CLKLOCK:1;
      unsigned NOSC:3;
      unsigned :1;
      unsigned COSC:3;
    };
    struct {
      unsigned :8;
      unsigned NOSC0:1;
      unsigned NOSC1:1;
      unsigned NOSC2:1;
      unsigned :1;
      unsigned COSC0:1;
      unsigned COSC1:1;
      unsigned COSC2:1;
    };
  };
} OSCCONBITS;
extern volatile OSCCONBITS OSCCONbits __attribute__((__sfr__));

extern volatile unsigned char OSCCONL __attribute__((__sfr__));
extern volatile unsigned char OSCCONH __attribute__((__sfr__));
extern volatile unsigned int  CLKDIV __attribute__((__sfr__));
__extension__ typedef struct tagCLKDIVBITS {
  union {
    struct {
      unsigned PLLPRE:5;
      unsigned :1;
      unsigned PLLPOST:2;
      unsigned FRCDIV:3;
      unsigned DOZEN:1;
      unsigned DOZE:3;
      unsigned ROI:1;
    };
    struct {
      unsigned PLLPRE0:1;
      unsigned PLLPRE1:1;
      unsigned PLLPRE2:1;
      unsigned PLLPRE3:1;
      unsigned PLLPRE4:1;
      unsigned :1;
      unsigned PLLPOST0:1;
      unsigned PLLPOST1:1;
      unsigned FRCDIV0:1;
      unsigned FRCDIV1:1;
      unsigned FRCDIV2:1;
      unsigned :1;
      unsigned DOZE0:1;
      unsigned DOZE1:1;
      unsigned DOZE2:1;
    };
  };
} CLKDIVBITS;
extern volatile CLKDIVBITS CLKDIVbits __attribute__((__sfr__));

extern volatile unsigned int  PLLFBD __attribute__((__sfr__));
__extension__ typedef struct tagPLLFBDBITS {
  union {
    struct {
      unsigned PLLDIV:9;
    };
    struct {
      unsigned PLLDIV0:1;
      unsigned PLLDIV1:1;
      unsigned PLLDIV2:1;
      unsigned PLLDIV3:1;
      unsigned PLLDIV4:1;
      unsigned PLLDIV5:1;
      unsigned PLLDIV6:1;
      unsigned PLLDIV7:1;
      unsigned PLLDIV8:1;
    };
  };
} PLLFBDBITS;
extern volatile PLLFBDBITS PLLFBDbits __attribute__((__sfr__));

extern volatile unsigned int  OSCTUN __attribute__((__sfr__));
__extension__ typedef struct tagOSCTUNBITS {
  union {
    struct {
      unsigned TUN:6;
    };
    struct {
      unsigned TUN0:1;
      unsigned TUN1:1;
      unsigned TUN2:1;
      unsigned TUN3:1;
      unsigned TUN4:1;
      unsigned TUN5:1;
    };
  };
} OSCTUNBITS;
extern volatile OSCTUNBITS OSCTUNbits __attribute__((__sfr__));

extern volatile unsigned int  LFSR __attribute__((__sfr__));
extern volatile unsigned int  REFOCON __attribute__((__sfr__));
__extension__ typedef struct tagREFOCONBITS {
  union {
    struct {
      unsigned :8;
      unsigned RODIV:4;
      unsigned ROSEL:1;
      unsigned ROSIDL:1;
      unsigned :1;
      unsigned ROON:1;
    };
    struct {
      unsigned :8;
      unsigned RODIV0:1;
      unsigned RODIV1:1;
      unsigned RODIV2:1;
      unsigned RODIV3:1;
      unsigned :1;
      unsigned ROSSLP:1;
    };
  };
} REFOCONBITS;
extern volatile REFOCONBITS REFOCONbits __attribute__((__sfr__));

extern volatile unsigned int  ACLKCON __attribute__((__sfr__));
__extension__ typedef struct tagACLKCONBITS {
  union {
    struct {
      unsigned :6;
      unsigned FRCSEL:1;
      unsigned ASRCSEL:1;
      unsigned APSTSCLR:3;
      unsigned :2;
      unsigned SELACLK:1;
      unsigned APLLCK:1;
      unsigned ENAPLL:1;
    };
    struct {
      unsigned :8;
      unsigned APSTSCLR0:1;
      unsigned APSTSCLR1:1;
      unsigned APSTSCLR2:1;
    };
  };
} ACLKCONBITS;
extern volatile ACLKCONBITS ACLKCONbits __attribute__((__sfr__));

extern volatile unsigned int  NVMCON __attribute__((__sfr__));
__extension__ typedef struct tagNVMCONBITS {
  union {
    struct {
      unsigned NVMOP:4;
      unsigned :2;
      unsigned ERASE:1;
      unsigned :6;
      unsigned WRERR:1;
      unsigned WREN:1;
      unsigned WR:1;
    };
    struct {
      unsigned NVMOP0:1;
      unsigned NVMOP1:1;
      unsigned NVMOP2:1;
      unsigned NVMOP3:1;
    };
  };
} NVMCONBITS;
extern volatile NVMCONBITS NVMCONbits __attribute__((__sfr__));

extern volatile unsigned int  NVMKEY __attribute__((__sfr__));
extern volatile unsigned int  PMD1 __attribute__((__sfr__));
typedef struct tagPMD1BITS {
  unsigned ADCMD:1;
  unsigned :2;
  unsigned SPI1MD:1;
  unsigned :1;
  unsigned U1MD:1;
  unsigned :1;
  unsigned I2C1MD:1;
  unsigned :1;
  unsigned PWMMD:1;
  unsigned :1;
  unsigned T1MD:1;
  unsigned T2MD:1;
  unsigned T3MD:1;
} PMD1BITS;
extern volatile PMD1BITS PMD1bits __attribute__((__sfr__));

extern volatile unsigned int  PMD2 __attribute__((__sfr__));
typedef struct tagPMD2BITS {
  unsigned OC1MD:1;
  unsigned OC2MD:1;
  unsigned :6;
  unsigned IC1MD:1;
  unsigned IC2MD:1;
} PMD2BITS;
extern volatile PMD2BITS PMD2bits __attribute__((__sfr__));

extern volatile unsigned int  PMD3 __attribute__((__sfr__));
typedef struct tagPMD3BITS {
  unsigned :10;
  unsigned CMPMD:1;
} PMD3BITS;
extern volatile PMD3BITS PMD3bits __attribute__((__sfr__));

extern volatile unsigned int  PMD4 __attribute__((__sfr__));
typedef struct tagPMD4BITS {
  unsigned :3;
  unsigned REFOMD:1;
} PMD4BITS;
extern volatile PMD4BITS PMD4bits __attribute__((__sfr__));

extern volatile unsigned int  PMD6 __attribute__((__sfr__));
typedef struct tagPMD6BITS {
  unsigned :8;
  unsigned PWM1MD:1;
  unsigned PWM2MD:1;
  unsigned PWM3MD:1;
  unsigned PWM4MD:1;
} PMD6BITS;
extern volatile PMD6BITS PMD6bits __attribute__((__sfr__));

extern volatile unsigned int  PMD7 __attribute__((__sfr__));
typedef struct tagPMD7BITS {
  unsigned :8;
  unsigned CMP1MD:1;
  unsigned CMP2MD:1;
  unsigned CMP3MD:1;
  unsigned CMP4MD:1;
} PMD7BITS;
extern volatile PMD7BITS PMD7bits __attribute__((__sfr__));



/* ---------------------------------------------------------- */
/* Defines for unique SFR bit names                           */
/* ---------------------------------------------------------- */

/* SR */
#define _C SRbits.C
#define _Z SRbits.Z
#define _OV SRbits.OV
#define _N SRbits.N
#define _RA SRbits.RA
#define _IPL SRbits.IPL
#define _DC SRbits.DC
#define _DA SRbits.DA
#define _SAB SRbits.SAB
#define _OAB SRbits.OAB
#define _SB SRbits.SB
#define _SA SRbits.SA
#define _OB SRbits.OB
#define _OA SRbits.OA
#define _IPL0 SRbits.IPL0
#define _IPL1 SRbits.IPL1
#define _IPL2 SRbits.IPL2

/* CORCON */
#define _IF CORCONbits.IF
#define _RND CORCONbits.RND
#define _PSV CORCONbits.PSV
#define _IPL3 CORCONbits.IPL3
#define _ACCSAT CORCONbits.ACCSAT
#define _SATDW CORCONbits.SATDW
#define _SATB CORCONbits.SATB
#define _SATA CORCONbits.SATA
#define _DL CORCONbits.DL
#define _EDT CORCONbits.EDT
#define _US CORCONbits.US
#define _DL0 CORCONbits.DL0
#define _DL1 CORCONbits.DL1
#define _DL2 CORCONbits.DL2

/* MODCON */
#define _XWM MODCONbits.XWM
#define _YWM MODCONbits.YWM
#define _BWM MODCONbits.BWM
#define _YMODEN MODCONbits.YMODEN
#define _XMODEN MODCONbits.XMODEN
#define _XWM0 MODCONbits.XWM0
#define _XWM1 MODCONbits.XWM1
#define _XWM2 MODCONbits.XWM2
#define _XWM3 MODCONbits.XWM3
#define _YWM0 MODCONbits.YWM0
#define _YWM1 MODCONbits.YWM1
#define _YWM2 MODCONbits.YWM2
#define _YWM3 MODCONbits.YWM3
#define _BWM0 MODCONbits.BWM0
#define _BWM1 MODCONbits.BWM1
#define _BWM2 MODCONbits.BWM2
#define _BWM3 MODCONbits.BWM3

/* XBREV */
#define _XB XBREVbits.XB
#define _BREN XBREVbits.BREN
#define _XB0 XBREVbits.XB0
#define _XB1 XBREVbits.XB1
#define _XB2 XBREVbits.XB2
#define _XB3 XBREVbits.XB3
#define _XB4 XBREVbits.XB4
#define _XB5 XBREVbits.XB5
#define _XB6 XBREVbits.XB6
#define _XB7 XBREVbits.XB7
#define _XB8 XBREVbits.XB8
#define _XB9 XBREVbits.XB9
#define _XB10 XBREVbits.XB10
#define _XB11 XBREVbits.XB11
#define _XB12 XBREVbits.XB12
#define _XB13 XBREVbits.XB13
#define _XB14 XBREVbits.XB14

/* CNEN1 */
#define _CN0IE CNEN1bits.CN0IE
#define _CN1IE CNEN1bits.CN1IE
#define _CN2IE CNEN1bits.CN2IE
#define _CN3IE CNEN1bits.CN3IE
#define _CN4IE CNEN1bits.CN4IE
#define _CN5IE CNEN1bits.CN5IE
#define _CN6IE CNEN1bits.CN6IE
#define _CN7IE CNEN1bits.CN7IE
#define _CN8IE CNEN1bits.CN8IE
#define _CN9IE CNEN1bits.CN9IE
#define _CN10IE CNEN1bits.CN10IE
#define _CN11IE CNEN1bits.CN11IE
#define _CN12IE CNEN1bits.CN12IE
#define _CN13IE CNEN1bits.CN13IE
#define _CN14IE CNEN1bits.CN14IE
#define _CN15IE CNEN1bits.CN15IE

/* CNEN2 */
#define _CN16IE CNEN2bits.CN16IE
#define _CN17IE CNEN2bits.CN17IE
#define _CN18IE CNEN2bits.CN18IE
#define _CN19IE CNEN2bits.CN19IE
#define _CN20IE CNEN2bits.CN20IE
#define _CN21IE CNEN2bits.CN21IE
#define _CN22IE CNEN2bits.CN22IE
#define _CN23IE CNEN2bits.CN23IE
#define _CN24IE CNEN2bits.CN24IE
#define _CN25IE CNEN2bits.CN25IE
#define _CN26IE CNEN2bits.CN26IE
#define _CN27IE CNEN2bits.CN27IE
#define _CN28IE CNEN2bits.CN28IE
#define _CN29IE CNEN2bits.CN29IE

/* CNPU1 */
#define _CN0PUE CNPU1bits.CN0PUE
#define _CN1PUE CNPU1bits.CN1PUE
#define _CN2PUE CNPU1bits.CN2PUE
#define _CN3PUE CNPU1bits.CN3PUE
#define _CN4PUE CNPU1bits.CN4PUE
#define _CN5PUE CNPU1bits.CN5PUE
#define _CN6PUE CNPU1bits.CN6PUE
#define _CN7PUE CNPU1bits.CN7PUE
#define _CN8PUE CNPU1bits.CN8PUE
#define _CN9PUE CNPU1bits.CN9PUE
#define _CN10PUE CNPU1bits.CN10PUE
#define _CN11PUE CNPU1bits.CN11PUE
#define _CN12PUE CNPU1bits.CN12PUE
#define _CN13PUE CNPU1bits.CN13PUE
#define _CN14PUE CNPU1bits.CN14PUE
#define _CN15PUE CNPU1bits.CN15PUE

/* CNPU2 */
#define _CN16PUE CNPU2bits.CN16PUE
#define _CN17PUE CNPU2bits.CN17PUE
#define _CN18PUE CNPU2bits.CN18PUE
#define _CN19PUE CNPU2bits.CN19PUE
#define _CN20PUE CNPU2bits.CN20PUE
#define _CN21PUE CNPU2bits.CN21PUE
#define _CN22PUE CNPU2bits.CN22PUE
#define _CN23PUE CNPU2bits.CN23PUE
#define _CN24PUE CNPU2bits.CN24PUE
#define _CN25PUE CNPU2bits.CN25PUE
#define _CN26PUE CNPU2bits.CN26PUE
#define _CN27PUE CNPU2bits.CN27PUE
#define _CN28PUE CNPU2bits.CN28PUE
#define _CN29PUE CNPU2bits.CN29PUE

/* INTCON1 */
#define _OSCFAIL INTCON1bits.OSCFAIL
#define _STKERR INTCON1bits.STKERR
#define _ADDRERR INTCON1bits.ADDRERR
#define _MATHERR INTCON1bits.MATHERR
#define _DIV0ERR INTCON1bits.DIV0ERR
#define _SFTACERR INTCON1bits.SFTACERR
#define _COVTE INTCON1bits.COVTE
#define _OVBTE INTCON1bits.OVBTE
#define _OVATE INTCON1bits.OVATE
#define _COVBERR INTCON1bits.COVBERR
#define _COVAERR INTCON1bits.COVAERR
#define _OVBERR INTCON1bits.OVBERR
#define _OVAERR INTCON1bits.OVAERR
#define _NSTDIS INTCON1bits.NSTDIS

/* INTCON2 */
#define _INT0EP INTCON2bits.INT0EP
#define _INT1EP INTCON2bits.INT1EP
#define _INT2EP INTCON2bits.INT2EP
#define _DISI INTCON2bits.DISI
#define _ALTIVT INTCON2bits.ALTIVT

/* IFS0 */
#define _INT0IF IFS0bits.INT0IF
#define _IC1IF IFS0bits.IC1IF
#define _OC1IF IFS0bits.OC1IF
#define _T1IF IFS0bits.T1IF
#define _IC2IF IFS0bits.IC2IF
#define _OC2IF IFS0bits.OC2IF
#define _T2IF IFS0bits.T2IF
#define _T3IF IFS0bits.T3IF
#define _SPI1EIF IFS0bits.SPI1EIF
#define _SPI1IF IFS0bits.SPI1IF
#define _U1RXIF IFS0bits.U1RXIF
#define _U1TXIF IFS0bits.U1TXIF
#define _ADIF IFS0bits.ADIF

/* IFS1 */
#define _SI2C1IF IFS1bits.SI2C1IF
#define _MI2C1IF IFS1bits.MI2C1IF
#define _AC1IF IFS1bits.AC1IF
#define _CNIF IFS1bits.CNIF
#define _INT1IF IFS1bits.INT1IF
#define _INT2IF IFS1bits.INT2IF

/* IFS3 */
#define _PSEMIF IFS3bits.PSEMIF

/* IFS4 */
#define _U1EIF IFS4bits.U1EIF

/* IFS5 */
#define _PWM1IF IFS5bits.PWM1IF
#define _PWM2IF IFS5bits.PWM2IF

/* IFS6 */
#define _PWM3IF IFS6bits.PWM3IF
#define _PWM4IF IFS6bits.PWM4IF
#define _AC2IF IFS6bits.AC2IF
#define _AC3IF IFS6bits.AC3IF
#define _AC4IF IFS6bits.AC4IF
#define _ADCP0IF IFS6bits.ADCP0IF
#define _ADCP1IF IFS6bits.ADCP1IF

/* IFS7 */
#define _ADCP2IF IFS7bits.ADCP2IF
#define _ADCP3IF IFS7bits.ADCP3IF
#define _ADCP4IF IFS7bits.ADCP4IF
#define _ADCP5IF IFS7bits.ADCP5IF
#define _ADCP6IF IFS7bits.ADCP6IF

/* IEC0 */
#define _INT0IE IEC0bits.INT0IE
#define _IC1IE IEC0bits.IC1IE
#define _OC1IE IEC0bits.OC1IE
#define _T1IE IEC0bits.T1IE
#define _IC2IE IEC0bits.IC2IE
#define _OC2IE IEC0bits.OC2IE
#define _T2IE IEC0bits.T2IE
#define _T3IE IEC0bits.T3IE
#define _SPI1EIE IEC0bits.SPI1EIE
#define _SPI1IE IEC0bits.SPI1IE
#define _U1RXIE IEC0bits.U1RXIE
#define _U1TXIE IEC0bits.U1TXIE
#define _ADIE IEC0bits.ADIE

/* IEC1 */
#define _SI2C1IE IEC1bits.SI2C1IE
#define _MI2C1IE IEC1bits.MI2C1IE
#define _AC1IE IEC1bits.AC1IE
#define _CNIE IEC1bits.CNIE
#define _INT1IE IEC1bits.INT1IE
#define _INT2IE IEC1bits.INT2IE

/* IEC3 */
#define _PSEMIE IEC3bits.PSEMIE

/* IEC4 */
#define _U1EIE IEC4bits.U1EIE

/* IEC5 */
#define _PWM1IE IEC5bits.PWM1IE
#define _PWM2IE IEC5bits.PWM2IE

/* IEC6 */
#define _PWM3IE IEC6bits.PWM3IE
#define _PWM4IE IEC6bits.PWM4IE
#define _AC2IE IEC6bits.AC2IE
#define _AC3IE IEC6bits.AC3IE
#define _AC4IE IEC6bits.AC4IE
#define _ADCP0IE IEC6bits.ADCP0IE
#define _ADCP1IE IEC6bits.ADCP1IE

/* IEC7 */
#define _ADCP2IE IEC7bits.ADCP2IE
#define _ADCP3IE IEC7bits.ADCP3IE
#define _ADCP4IE IEC7bits.ADCP4IE
#define _ADCP5IE IEC7bits.ADCP5IE
#define _ADCP6IE IEC7bits.ADCP6IE

/* IPC0 */
#define _INT0IP IPC0bits.INT0IP
#define _IC1IP IPC0bits.IC1IP
#define _OC1IP IPC0bits.OC1IP
#define _T1IP IPC0bits.T1IP
#define _INT0IP0 IPC0bits.INT0IP0
#define _INT0IP1 IPC0bits.INT0IP1
#define _INT0IP2 IPC0bits.INT0IP2
#define _IC1IP0 IPC0bits.IC1IP0
#define _IC1IP1 IPC0bits.IC1IP1
#define _IC1IP2 IPC0bits.IC1IP2
#define _OC1IP0 IPC0bits.OC1IP0
#define _OC1IP1 IPC0bits.OC1IP1
#define _OC1IP2 IPC0bits.OC1IP2
#define _T1IP0 IPC0bits.T1IP0
#define _T1IP1 IPC0bits.T1IP1
#define _T1IP2 IPC0bits.T1IP2

/* IPC1 */
#define _IC2IP IPC1bits.IC2IP
#define _OC2IP IPC1bits.OC2IP
#define _T2IP IPC1bits.T2IP
#define _IC2IP0 IPC1bits.IC2IP0
#define _IC2IP1 IPC1bits.IC2IP1
#define _IC2IP2 IPC1bits.IC2IP2
#define _OC2IP0 IPC1bits.OC2IP0
#define _OC2IP1 IPC1bits.OC2IP1
#define _OC2IP2 IPC1bits.OC2IP2
#define _T2IP0 IPC1bits.T2IP0
#define _T2IP1 IPC1bits.T2IP1
#define _T2IP2 IPC1bits.T2IP2

/* IPC2 */
#define _T3IP IPC2bits.T3IP
#define _SPI1EIP IPC2bits.SPI1EIP
#define _SPI1IP IPC2bits.SPI1IP
#define _U1RXIP IPC2bits.U1RXIP
#define _T3IP0 IPC2bits.T3IP0
#define _T3IP1 IPC2bits.T3IP1
#define _T3IP2 IPC2bits.T3IP2
#define _SPI1EIP0 IPC2bits.SPI1EIP0
#define _SPI1EIP1 IPC2bits.SPI1EIP1
#define _SPI1EIP2 IPC2bits.SPI1EIP2
#define _SPI1IP0 IPC2bits.SPI1IP0
#define _SPI1IP1 IPC2bits.SPI1IP1
#define _SPI1IP2 IPC2bits.SPI1IP2
#define _U1RXIP0 IPC2bits.U1RXIP0
#define _U1RXIP1 IPC2bits.U1RXIP1
#define _U1RXIP2 IPC2bits.U1RXIP2

/* IPC3 */
#define _U1TXIP IPC3bits.U1TXIP
#define _ADIP IPC3bits.ADIP
#define _U1TXIP0 IPC3bits.U1TXIP0
#define _U1TXIP1 IPC3bits.U1TXIP1
#define _U1TXIP2 IPC3bits.U1TXIP2
#define _ADIP0 IPC3bits.ADIP0
#define _ADIP1 IPC3bits.ADIP1
#define _ADIP2 IPC3bits.ADIP2

/* IPC4 */
#define _SI2C1IP IPC4bits.SI2C1IP
#define _MI2C1IP IPC4bits.MI2C1IP
#define _AC1IP IPC4bits.AC1IP
#define _CNIP IPC4bits.CNIP
#define _SI2C1IP0 IPC4bits.SI2C1IP0
#define _SI2C1IP1 IPC4bits.SI2C1IP1
#define _SI2C1IP2 IPC4bits.SI2C1IP2
#define _MI2C1IP0 IPC4bits.MI2C1IP0
#define _MI2C1IP1 IPC4bits.MI2C1IP1
#define _MI2C1IP2 IPC4bits.MI2C1IP2
#define _AC1IP0 IPC4bits.AC1IP0
#define _AC1IP1 IPC4bits.AC1IP1
#define _AC1IP2 IPC4bits.AC1IP2
#define _CNIP0 IPC4bits.CNIP0
#define _CNIP1 IPC4bits.CNIP1
#define _CNIP2 IPC4bits.CNIP2

/* IPC5 */
#define _INT1IP IPC5bits.INT1IP
#define _INT1IP0 IPC5bits.INT1IP0
#define _INT1IP1 IPC5bits.INT1IP1
#define _INT1IP2 IPC5bits.INT1IP2

/* IPC7 */
#define _INT2IP IPC7bits.INT2IP
#define _INT2IP0 IPC7bits.INT2IP0
#define _INT2IP1 IPC7bits.INT2IP1
#define _INT2IP2 IPC7bits.INT2IP2

/* IPC14 */
#define _PSEMIP IPC14bits.PSEMIP
#define _PSEMIP0 IPC14bits.PSEMIP0
#define _PSEMIP1 IPC14bits.PSEMIP1
#define _PSEMIP2 IPC14bits.PSEMIP2

/* IPC16 */
#define _U1EIP IPC16bits.U1EIP
#define _U1EIP0 IPC16bits.U1EIP0
#define _U1EIP1 IPC16bits.U1EIP1
#define _U1EIP2 IPC16bits.U1EIP2

/* IPC23 */
#define _PWM1IP IPC23bits.PWM1IP
#define _PWM2IP IPC23bits.PWM2IP
#define _PWM1IP0 IPC23bits.PWM1IP0
#define _PWM1IP1 IPC23bits.PWM1IP1
#define _PWM1IP2 IPC23bits.PWM1IP2
#define _PWM2IP0 IPC23bits.PWM2IP0
#define _PWM2IP1 IPC23bits.PWM2IP1
#define _PWM2IP2 IPC23bits.PWM2IP2

/* IPC24 */
#define _PWM3IP IPC24bits.PWM3IP
#define _PWM4IP IPC24bits.PWM4IP
#define _PWM3IP0 IPC24bits.PWM3IP0
#define _PWM3IP1 IPC24bits.PWM3IP1
#define _PWM3IP2 IPC24bits.PWM3IP2
#define _PWM4IP0 IPC24bits.PWM4IP0
#define _PWM4IP1 IPC24bits.PWM4IP1
#define _PWM4IP2 IPC24bits.PWM4IP2

/* IPC25 */
#define _AC2IP IPC25bits.AC2IP
#define _AC2IP0 IPC25bits.AC2IP0
#define _AC2IP1 IPC25bits.AC2IP1
#define _AC2IP2 IPC25bits.AC2IP2

/* IPC26 */
#define _AC3IP IPC26bits.AC3IP
#define _AC4IP IPC26bits.AC4IP
#define _AC3IP0 IPC26bits.AC3IP0
#define _AC3IP1 IPC26bits.AC3IP1
#define _AC3IP2 IPC26bits.AC3IP2
#define _AC4IP0 IPC26bits.AC4IP0
#define _AC4IP1 IPC26bits.AC4IP1
#define _AC4IP2 IPC26bits.AC4IP2

/* IPC27 */
#define _ADCP0IP IPC27bits.ADCP0IP
#define _ADCP1IP IPC27bits.ADCP1IP
#define _ADCP0IP0 IPC27bits.ADCP0IP0
#define _ADCP0IP1 IPC27bits.ADCP0IP1
#define _ADCP0IP2 IPC27bits.ADCP0IP2
#define _ADCP1IP0 IPC27bits.ADCP1IP0
#define _ADCP1IP1 IPC27bits.ADCP1IP1
#define _ADCP1IP2 IPC27bits.ADCP1IP2

/* IPC28 */
#define _ADCP2IP IPC28bits.ADCP2IP
#define _ADCP3IP IPC28bits.ADCP3IP
#define _ADCP4IP IPC28bits.ADCP4IP
#define _ADCP5IP IPC28bits.ADCP5IP
#define _ADCP2IP0 IPC28bits.ADCP2IP0
#define _ADCP2IP1 IPC28bits.ADCP2IP1
#define _ADCP2IP2 IPC28bits.ADCP2IP2
#define _ADCP3IP0 IPC28bits.ADCP3IP0
#define _ADCP3IP1 IPC28bits.ADCP3IP1
#define _ADCP3IP2 IPC28bits.ADCP3IP2
#define _ADCP4IP0 IPC28bits.ADCP4IP0
#define _ADCP4IP1 IPC28bits.ADCP4IP1
#define _ADCP4IP2 IPC28bits.ADCP4IP2
#define _ADCP5IP0 IPC28bits.ADCP5IP0
#define _ADCP5IP1 IPC28bits.ADCP5IP1
#define _ADCP5IP2 IPC28bits.ADCP5IP2

/* IPC29 */
#define _ADCP6IP IPC29bits.ADCP6IP

/* INTTREG */
#define _VECNUM INTTREGbits.VECNUM
#define _ILR INTTREGbits.ILR
#define _VECNUM0 INTTREGbits.VECNUM0
#define _VECNUM1 INTTREGbits.VECNUM1
#define _VECNUM2 INTTREGbits.VECNUM2
#define _VECNUM3 INTTREGbits.VECNUM3
#define _VECNUM4 INTTREGbits.VECNUM4
#define _VECNUM5 INTTREGbits.VECNUM5
#define _VECNUM6 INTTREGbits.VECNUM6
#define _ILR0 INTTREGbits.ILR0
#define _ILR1 INTTREGbits.ILR1
#define _ILR2 INTTREGbits.ILR2
#define _ILR3 INTTREGbits.ILR3

/* T1CON */
#define _TCS T1CONbits.TCS
#define _TSYNC T1CONbits.TSYNC
#define _TCKPS T1CONbits.TCKPS
#define _TGATE T1CONbits.TGATE
#define _TSIDL T1CONbits.TSIDL
#define _TON T1CONbits.TON
#define _TCKPS0 T1CONbits.TCKPS0
#define _TCKPS1 T1CONbits.TCKPS1

/* T2CON */
/* Bitname _TCS cannot be defined because it is used by more than one SFR */
#define _T32 T2CONbits.T32
/* Bitname _TCKPS cannot be defined because it is used by more than one SFR */
/* Bitname _TGATE cannot be defined because it is used by more than one SFR */
/* Bitname _TSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _TON cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS0 cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS1 cannot be defined because it is used by more than one SFR */

/* T3CON */
/* Bitname _TCS cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS cannot be defined because it is used by more than one SFR */
/* Bitname _TGATE cannot be defined because it is used by more than one SFR */
/* Bitname _TSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _TON cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS0 cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS1 cannot be defined because it is used by more than one SFR */

/* IC1CON */
#define _ICM IC1CONbits.ICM
#define _ICBNE IC1CONbits.ICBNE
#define _ICOV IC1CONbits.ICOV
#define _ICI IC1CONbits.ICI
#define _ICTMR IC1CONbits.ICTMR
#define _ICSIDL IC1CONbits.ICSIDL
#define _ICM0 IC1CONbits.ICM0
#define _ICM1 IC1CONbits.ICM1
#define _ICM2 IC1CONbits.ICM2
#define _ICI0 IC1CONbits.ICI0
#define _ICI1 IC1CONbits.ICI1

/* IC2CON */
/* Bitname _ICM cannot be defined because it is used by more than one SFR */
/* Bitname _ICBNE cannot be defined because it is used by more than one SFR */
/* Bitname _ICOV cannot be defined because it is used by more than one SFR */
/* Bitname _ICI cannot be defined because it is used by more than one SFR */
/* Bitname _ICTMR cannot be defined because it is used by more than one SFR */
/* Bitname _ICSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _ICM0 cannot be defined because it is used by more than one SFR */
/* Bitname _ICM1 cannot be defined because it is used by more than one SFR */
/* Bitname _ICM2 cannot be defined because it is used by more than one SFR */
/* Bitname _ICI0 cannot be defined because it is used by more than one SFR */
/* Bitname _ICI1 cannot be defined because it is used by more than one SFR */

/* OC1CON */
#define _OCM OC1CONbits.OCM
#define _OCTSEL OC1CONbits.OCTSEL
#define _OCFLT OC1CONbits.OCFLT
#define _OCSIDL OC1CONbits.OCSIDL
#define _OCM0 OC1CONbits.OCM0
#define _OCM1 OC1CONbits.OCM1
#define _OCM2 OC1CONbits.OCM2

/* OC2CON */
/* Bitname _OCM cannot be defined because it is used by more than one SFR */
/* Bitname _OCTSEL cannot be defined because it is used by more than one SFR */
/* Bitname _OCFLT cannot be defined because it is used by more than one SFR */
/* Bitname _OCSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _OCM0 cannot be defined because it is used by more than one SFR */
/* Bitname _OCM1 cannot be defined because it is used by more than one SFR */
/* Bitname _OCM2 cannot be defined because it is used by more than one SFR */

/* I2C1CON */
#define _SEN I2C1CONbits.SEN
#define _RSEN I2C1CONbits.RSEN
#define _PEN I2C1CONbits.PEN
#define _RCEN I2C1CONbits.RCEN
#define _ACKEN I2C1CONbits.ACKEN
#define _ACKDT I2C1CONbits.ACKDT
#define _STREN I2C1CONbits.STREN
#define _GCEN I2C1CONbits.GCEN
#define _SMEN I2C1CONbits.SMEN
#define _DISSLW I2C1CONbits.DISSLW
#define _A10M I2C1CONbits.A10M
#define _IPMIEN I2C1CONbits.IPMIEN
#define _SCLREL I2C1CONbits.SCLREL
#define _I2CSIDL I2C1CONbits.I2CSIDL
#define _I2CEN I2C1CONbits.I2CEN

/* I2C1STAT */
#define _TBF I2C1STATbits.TBF
#define _RBF I2C1STATbits.RBF
#define _R_W I2C1STATbits.R_W
#define _S I2C1STATbits.S
#define _P I2C1STATbits.P
#define _D_A I2C1STATbits.D_A
#define _I2COV I2C1STATbits.I2COV
#define _IWCOL I2C1STATbits.IWCOL
#define _ADD10 I2C1STATbits.ADD10
#define _GCSTAT I2C1STATbits.GCSTAT
#define _BCL I2C1STATbits.BCL
#define _TRSTAT I2C1STATbits.TRSTAT
#define _ACKSTAT I2C1STATbits.ACKSTAT

/* U1MODE */
#define _STSEL U1MODEbits.STSEL
#define _PDSEL U1MODEbits.PDSEL
#define _BRGH U1MODEbits.BRGH
#define _URXINV U1MODEbits.URXINV
#define _ABAUD U1MODEbits.ABAUD
#define _LPBACK U1MODEbits.LPBACK
#define _WAKE U1MODEbits.WAKE
#define _UEN U1MODEbits.UEN
#define _RTSMD U1MODEbits.RTSMD
#define _IREN U1MODEbits.IREN
#define _USIDL U1MODEbits.USIDL
#define _UARTEN U1MODEbits.UARTEN
#define _PDSEL0 U1MODEbits.PDSEL0
#define _PDSEL1 U1MODEbits.PDSEL1
#define _UEN0 U1MODEbits.UEN0
#define _UEN1 U1MODEbits.UEN1

/* U1STA */
#define _URXDA U1STAbits.URXDA
#define _OERR U1STAbits.OERR
#define _FERR U1STAbits.FERR
#define _PERR U1STAbits.PERR
#define _RIDLE U1STAbits.RIDLE
#define _ADDEN U1STAbits.ADDEN
#define _URXISEL U1STAbits.URXISEL
#define _TRMT U1STAbits.TRMT
#define _UTXBF U1STAbits.UTXBF
#define _UTXEN U1STAbits.UTXEN
#define _UTXBRK U1STAbits.UTXBRK
#define _UTXISEL0 U1STAbits.UTXISEL0
#define _UTXINV U1STAbits.UTXINV
#define _UTXISEL1 U1STAbits.UTXISEL1
#define _URXISEL0 U1STAbits.URXISEL0
#define _URXISEL1 U1STAbits.URXISEL1

/* U1TXREG */
#define _U1TXREG U1TXREGbits.U1TXREG
#define _UTXREG0 U1TXREGbits.UTXREG0
#define _UTXREG1 U1TXREGbits.UTXREG1
#define _UTXREG2 U1TXREGbits.UTXREG2
#define _UTXREG3 U1TXREGbits.UTXREG3
#define _UTXREG4 U1TXREGbits.UTXREG4
#define _UTXREG5 U1TXREGbits.UTXREG5
#define _UTXREG6 U1TXREGbits.UTXREG6
#define _UTXREG7 U1TXREGbits.UTXREG7
#define _UTXREG8 U1TXREGbits.UTXREG8

/* U1RXREG */
#define _U1RXREG U1RXREGbits.U1RXREG
#define _URXREG0 U1RXREGbits.URXREG0
#define _URXREG1 U1RXREGbits.URXREG1
#define _URXREG2 U1RXREGbits.URXREG2
#define _URXREG3 U1RXREGbits.URXREG3
#define _URXREG4 U1RXREGbits.URXREG4
#define _URXREG5 U1RXREGbits.URXREG5
#define _URXREG6 U1RXREGbits.URXREG6
#define _URXREG7 U1RXREGbits.URXREG7
#define _URXREG8 U1RXREGbits.URXREG8

/* SPI1STAT */
#define _SPIRBF SPI1STATbits.SPIRBF
#define _SPITBF SPI1STATbits.SPITBF
#define _SPIROV SPI1STATbits.SPIROV
#define _SPISIDL SPI1STATbits.SPISIDL
#define _SPIEN SPI1STATbits.SPIEN

/* SPI1CON1 */
#define _PPRE SPI1CON1bits.PPRE
#define _SPRE SPI1CON1bits.SPRE
#define _MSTEN SPI1CON1bits.MSTEN
#define _CKP SPI1CON1bits.CKP
#define _SSEN SPI1CON1bits.SSEN
#define _CKE SPI1CON1bits.CKE
#define _SMP SPI1CON1bits.SMP
#define _MODE16 SPI1CON1bits.MODE16
#define _DISSDO SPI1CON1bits.DISSDO
#define _DISSCK SPI1CON1bits.DISSCK
#define _PPRE0 SPI1CON1bits.PPRE0
#define _PPRE1 SPI1CON1bits.PPRE1
#define _SPRE0 SPI1CON1bits.SPRE0
#define _SPRE1 SPI1CON1bits.SPRE1
#define _SPRE2 SPI1CON1bits.SPRE2

/* SPI1CON2 */
#define _FRMDLY SPI1CON2bits.FRMDLY
#define _FRMPOL SPI1CON2bits.FRMPOL
#define _SPIFSD SPI1CON2bits.SPIFSD
#define _FRMEN SPI1CON2bits.FRMEN

/* TRISA */
#define _TRISA0 TRISAbits.TRISA0
#define _TRISA1 TRISAbits.TRISA1
#define _TRISA2 TRISAbits.TRISA2
#define _TRISA3 TRISAbits.TRISA3
#define _TRISA4 TRISAbits.TRISA4

/* PORTA */
#define _RA0 PORTAbits.RA0
#define _RA1 PORTAbits.RA1
#define _RA2 PORTAbits.RA2
#define _RA3 PORTAbits.RA3
#define _RA4 PORTAbits.RA4

/* LATA */
#define _LATA0 LATAbits.LATA0
#define _LATA1 LATAbits.LATA1
#define _LATA2 LATAbits.LATA2
#define _LATA3 LATAbits.LATA3
#define _LATA4 LATAbits.LATA4

/* ODCA */
#define _ODCA0 ODCAbits.ODCA0
#define _ODCA1 ODCAbits.ODCA1
#define _ODCA2 ODCAbits.ODCA2
#define _ODCA3 ODCAbits.ODCA3
#define _ODCA4 ODCAbits.ODCA4

/* TRISB */
#define _TRISB0 TRISBbits.TRISB0
#define _TRISB1 TRISBbits.TRISB1
#define _TRISB2 TRISBbits.TRISB2
#define _TRISB3 TRISBbits.TRISB3
#define _TRISB4 TRISBbits.TRISB4
#define _TRISB5 TRISBbits.TRISB5
#define _TRISB6 TRISBbits.TRISB6
#define _TRISB7 TRISBbits.TRISB7
#define _TRISB8 TRISBbits.TRISB8
#define _TRISB9 TRISBbits.TRISB9
#define _TRISB10 TRISBbits.TRISB10
#define _TRISB11 TRISBbits.TRISB11
#define _TRISB12 TRISBbits.TRISB12
#define _TRISB13 TRISBbits.TRISB13
#define _TRISB14 TRISBbits.TRISB14
#define _TRISB15 TRISBbits.TRISB15

/* PORTB */
#define _RB0 PORTBbits.RB0
#define _RB1 PORTBbits.RB1
#define _RB2 PORTBbits.RB2
#define _RB3 PORTBbits.RB3
#define _RB4 PORTBbits.RB4
#define _RB5 PORTBbits.RB5
#define _RB6 PORTBbits.RB6
#define _RB7 PORTBbits.RB7
#define _RB8 PORTBbits.RB8
#define _RB9 PORTBbits.RB9
#define _RB10 PORTBbits.RB10
#define _RB11 PORTBbits.RB11
#define _RB12 PORTBbits.RB12
#define _RB13 PORTBbits.RB13
#define _RB14 PORTBbits.RB14
#define _RB15 PORTBbits.RB15

/* LATB */
#define _LATB0 LATBbits.LATB0
#define _LATB1 LATBbits.LATB1
#define _LATB2 LATBbits.LATB2
#define _LATB3 LATBbits.LATB3
#define _LATB4 LATBbits.LATB4
#define _LATB5 LATBbits.LATB5
#define _LATB6 LATBbits.LATB6
#define _LATB7 LATBbits.LATB7
#define _LATB8 LATBbits.LATB8
#define _LATB9 LATBbits.LATB9
#define _LATB10 LATBbits.LATB10
#define _LATB11 LATBbits.LATB11
#define _LATB12 LATBbits.LATB12
#define _LATB13 LATBbits.LATB13
#define _LATB14 LATBbits.LATB14
#define _LATB15 LATBbits.LATB15

/* ODCB */
#define _ODCB0 ODCBbits.ODCB0
#define _ODCB1 ODCBbits.ODCB1
#define _ODCB2 ODCBbits.ODCB2
#define _ODCB3 ODCBbits.ODCB3
#define _ODCB4 ODCBbits.ODCB4
#define _ODCB5 ODCBbits.ODCB5
#define _ODCB6 ODCBbits.ODCB6
#define _ODCB7 ODCBbits.ODCB7
#define _ODCB8 ODCBbits.ODCB8
#define _ODCB9 ODCBbits.ODCB9
#define _ODCB10 ODCBbits.ODCB10
#define _ODCB11 ODCBbits.ODCB11
#define _ODCB12 ODCBbits.ODCB12
#define _ODCB13 ODCBbits.ODCB13
#define _ODCB14 ODCBbits.ODCB14
#define _ODCB15 ODCBbits.ODCB15

/* TRISC */
#define _TRISC0 TRISCbits.TRISC0
#define _TRISC1 TRISCbits.TRISC1
#define _TRISC2 TRISCbits.TRISC2
#define _TRISC3 TRISCbits.TRISC3
#define _TRISC4 TRISCbits.TRISC4
#define _TRISC5 TRISCbits.TRISC5
#define _TRISC6 TRISCbits.TRISC6
#define _TRISC7 TRISCbits.TRISC7
#define _TRISC8 TRISCbits.TRISC8
#define _TRISC9 TRISCbits.TRISC9
#define _TRISC10 TRISCbits.TRISC10
#define _TRISC11 TRISCbits.TRISC11
#define _TRISC12 TRISCbits.TRISC12
#define _TRISC13 TRISCbits.TRISC13

/* PORTC */
#define _RC0 PORTCbits.RC0
#define _RC1 PORTCbits.RC1
#define _RC2 PORTCbits.RC2
#define _RC3 PORTCbits.RC3
#define _RC4 PORTCbits.RC4
#define _RC5 PORTCbits.RC5
#define _RC6 PORTCbits.RC6
#define _RC7 PORTCbits.RC7
#define _RC8 PORTCbits.RC8
#define _RC9 PORTCbits.RC9
#define _RC10 PORTCbits.RC10
#define _RC11 PORTCbits.RC11
#define _RC12 PORTCbits.RC12
#define _RC13 PORTCbits.RC13

/* LATC */
#define _LATC0 LATCbits.LATC0
#define _LATC1 LATCbits.LATC1
#define _LATC2 LATCbits.LATC2
#define _LATC3 LATCbits.LATC3
#define _LATC4 LATCbits.LATC4
#define _LATC5 LATCbits.LATC5
#define _LATC6 LATCbits.LATC6
#define _LATC7 LATCbits.LATC7
#define _LATC8 LATCbits.LATC8
#define _LATC9 LATCbits.LATC9
#define _LATC10 LATCbits.LATC10
#define _LATC11 LATCbits.LATC11
#define _LATC12 LATCbits.LATC12
#define _LATC13 LATCbits.LATC13

/* ODCC */
#define _ODCC0 ODCCbits.ODCC0
#define _ODCC1 ODCCbits.ODCC1
#define _ODCC2 ODCCbits.ODCC2
#define _ODCC3 ODCCbits.ODCC3
#define _ODCC4 ODCCbits.ODCC4
#define _ODCC5 ODCCbits.ODCC5
#define _ODCC6 ODCCbits.ODCC6
#define _ODCC7 ODCCbits.ODCC7
#define _ODCC8 ODCCbits.ODCC8
#define _ODCC9 ODCCbits.ODCC9
#define _ODCC10 ODCCbits.ODCC10
#define _ODCC11 ODCCbits.ODCC11
#define _ODCC12 ODCCbits.ODCC12
#define _ODCC13 ODCCbits.ODCC13

/* ADCON */
#define _ADCS ADCONbits.ADCS
#define _ASYNCSAMP ADCONbits.ASYNCSAMP
#define _SEQSAMP ADCONbits.SEQSAMP
#define _ORDER ADCONbits.ORDER
#define _EIE ADCONbits.EIE
#define _FORM ADCONbits.FORM
#define _GSWTRG ADCONbits.GSWTRG
#define _SLOWCLK ADCONbits.SLOWCLK
#define _ADSIDL ADCONbits.ADSIDL
#define _ADON ADCONbits.ADON
#define _ADCS0 ADCONbits.ADCS0
#define _ADCS1 ADCONbits.ADCS1
#define _ADCS2 ADCONbits.ADCS2

/* ADPCFG */
#define _PCFG0 ADPCFGbits.PCFG0
#define _PCFG1 ADPCFGbits.PCFG1
#define _PCFG2 ADPCFGbits.PCFG2
#define _PCFG3 ADPCFGbits.PCFG3
#define _PCFG4 ADPCFGbits.PCFG4
#define _PCFG5 ADPCFGbits.PCFG5
#define _PCFG6 ADPCFGbits.PCFG6
#define _PCFG7 ADPCFGbits.PCFG7
#define _PCFG8 ADPCFGbits.PCFG8
#define _PCFG9 ADPCFGbits.PCFG9
#define _PCFG10 ADPCFGbits.PCFG10
#define _PCFG11 ADPCFGbits.PCFG11

/* ADSTAT */
#define _P0RDY ADSTATbits.P0RDY
#define _P1RDY ADSTATbits.P1RDY
#define _P2RDY ADSTATbits.P2RDY
#define _P3RDY ADSTATbits.P3RDY
#define _P4RDY ADSTATbits.P4RDY
#define _P5RDY ADSTATbits.P5RDY
#define _P6RDY ADSTATbits.P6RDY

/* ADCPC0 */
#define _TRGSRC0 ADCPC0bits.TRGSRC0
#define _SWTRG0 ADCPC0bits.SWTRG0
#define _PEND0 ADCPC0bits.PEND0
#define _IRQEN0 ADCPC0bits.IRQEN0
#define _TRGSRC1 ADCPC0bits.TRGSRC1
#define _SWTRG1 ADCPC0bits.SWTRG1
#define _PEND1 ADCPC0bits.PEND1
#define _IRQEN1 ADCPC0bits.IRQEN1
#define _TRGSRC00 ADCPC0bits.TRGSRC00
#define _TRGSRC01 ADCPC0bits.TRGSRC01
#define _TRGSRC02 ADCPC0bits.TRGSRC02
#define _TRGSRC03 ADCPC0bits.TRGSRC03
#define _TRGSRC04 ADCPC0bits.TRGSRC04
#define _TRGSRC10 ADCPC0bits.TRGSRC10
#define _TRGSRC11 ADCPC0bits.TRGSRC11
#define _TRGSRC12 ADCPC0bits.TRGSRC12
#define _TRGSRC13 ADCPC0bits.TRGSRC13
#define _TRGSRC14 ADCPC0bits.TRGSRC14

/* ADCPC1 */
#define _TRGSRC2 ADCPC1bits.TRGSRC2
#define _SWTRG2 ADCPC1bits.SWTRG2
#define _PEND2 ADCPC1bits.PEND2
#define _IRQEN2 ADCPC1bits.IRQEN2
#define _TRGSRC3 ADCPC1bits.TRGSRC3
#define _SWTRG3 ADCPC1bits.SWTRG3
#define _PEND3 ADCPC1bits.PEND3
#define _IRQEN3 ADCPC1bits.IRQEN3
#define _TRGSRC20 ADCPC1bits.TRGSRC20
#define _TRGSRC21 ADCPC1bits.TRGSRC21
#define _TRGSRC22 ADCPC1bits.TRGSRC22
#define _TRGSRC23 ADCPC1bits.TRGSRC23
#define _TRGSRC24 ADCPC1bits.TRGSRC24
#define _TRGSRC30 ADCPC1bits.TRGSRC30
#define _TRGSRC31 ADCPC1bits.TRGSRC31
#define _TRGSRC32 ADCPC1bits.TRGSRC32
#define _TRGSRC33 ADCPC1bits.TRGSRC33
#define _TRGSRC34 ADCPC1bits.TRGSRC34

/* ADCPC2 */
#define _TRGSRC4 ADCPC2bits.TRGSRC4
#define _SWTRG4 ADCPC2bits.SWTRG4
#define _PEND4 ADCPC2bits.PEND4
#define _IRQEN4 ADCPC2bits.IRQEN4
#define _TRGSRC5 ADCPC2bits.TRGSRC5
#define _SWTRG5 ADCPC2bits.SWTRG5
#define _PEND5 ADCPC2bits.PEND5
#define _IRQEN5 ADCPC2bits.IRQEN5
#define _TRGSRC40 ADCPC2bits.TRGSRC40
#define _TRGSRC41 ADCPC2bits.TRGSRC41
#define _TRGSRC42 ADCPC2bits.TRGSRC42
#define _TRGSRC43 ADCPC2bits.TRGSRC43
#define _TRGSRC44 ADCPC2bits.TRGSRC44
#define _TRGSRC50 ADCPC2bits.TRGSRC50
#define _TRGSRC51 ADCPC2bits.TRGSRC51
#define _TRGSRC52 ADCPC2bits.TRGSRC52
#define _TRGSRC53 ADCPC2bits.TRGSRC53
#define _TRGSRC54 ADCPC2bits.TRGSRC54

/* ADCPC3 */
#define _TRGSRC6 ADCPC3bits.TRGSRC6
#define _SWTRG6 ADCPC3bits.SWTRG6
#define _PEND6 ADCPC3bits.PEND6
#define _IRQEN6 ADCPC3bits.IRQEN6
#define _TRGSRC60 ADCPC3bits.TRGSRC60
#define _TRGSRC61 ADCPC3bits.TRGSRC61
#define _TRGSRC62 ADCPC3bits.TRGSRC62
#define _TRGSRC63 ADCPC3bits.TRGSRC63
#define _TRGSRC64 ADCPC3bits.TRGSRC64

/* PTCON */
#define _SEVTPS PTCONbits.SEVTPS
#define _SYNCSRC PTCONbits.SYNCSRC
#define _SYNCEN PTCONbits.SYNCEN
#define _SYNCOEN PTCONbits.SYNCOEN
#define _SYNCPOL PTCONbits.SYNCPOL
#define _EIPU PTCONbits.EIPU
#define _SEIEN PTCONbits.SEIEN
#define _SESTAT PTCONbits.SESTAT
#define _PTSIDL PTCONbits.PTSIDL
#define _PTEN PTCONbits.PTEN
#define _SEVTPS0 PTCONbits.SEVTPS0
#define _SEVTPS1 PTCONbits.SEVTPS1
#define _SEVTPS2 PTCONbits.SEVTPS2
#define _SEVTPS3 PTCONbits.SEVTPS3
#define _SYNCSRC0 PTCONbits.SYNCSRC0
#define _SYNCSRC1 PTCONbits.SYNCSRC1

/* PTCON2 */
#define _PCLKDIV PTCON2bits.PCLKDIV
#define _PCLKDIV0 PTCON2bits.PCLKDIV0
#define _PCLKDIV1 PTCON2bits.PCLKDIV1
#define _PCLKDIV2 PTCON2bits.PCLKDIV2

/* PWMCON1 */
/* Bitname _IUE cannot be defined because it is used by more than one SFR */
/* Bitname _XPRES cannot be defined because it is used by more than one SFR */
/* Bitname _CAM cannot be defined because it is used by more than one SFR */
/* Bitname _DTC cannot be defined because it is used by more than one SFR */
/* Bitname _MDCS cannot be defined because it is used by more than one SFR */
/* Bitname _ITB cannot be defined because it is used by more than one SFR */
/* Bitname _TRGIEN cannot be defined because it is used by more than one SFR */
/* Bitname _CLIEN cannot be defined because it is used by more than one SFR */
/* Bitname _FLTIEN cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _CLSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _DTC0 cannot be defined because it is used by more than one SFR */
/* Bitname _DTC1 cannot be defined because it is used by more than one SFR */

/* IOCON1 */
/* Bitname _OSYNC cannot be defined because it is used by more than one SFR */
/* Bitname _SWAP cannot be defined because it is used by more than one SFR */
/* Bitname _CLDAT cannot be defined because it is used by more than one SFR */
/* Bitname _FLTDAT cannot be defined because it is used by more than one SFR */
/* Bitname _OVRDAT cannot be defined because it is used by more than one SFR */
/* Bitname _OVRENL cannot be defined because it is used by more than one SFR */
/* Bitname _OVRENH cannot be defined because it is used by more than one SFR */
/* Bitname _PMOD cannot be defined because it is used by more than one SFR */
/* Bitname _POLL cannot be defined because it is used by more than one SFR */
/* Bitname _POLH cannot be defined because it is used by more than one SFR */
/* Bitname _PENL cannot be defined because it is used by more than one SFR */
/* Bitname _PENH cannot be defined because it is used by more than one SFR */
/* Bitname _CLDAT0 cannot be defined because it is used by more than one SFR */
/* Bitname _CLDAT1 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTDAT0 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTDAT1 cannot be defined because it is used by more than one SFR */
/* Bitname _OVRDAT0 cannot be defined because it is used by more than one SFR */
/* Bitname _OVRDAT1 cannot be defined because it is used by more than one SFR */
/* Bitname _PMOD0 cannot be defined because it is used by more than one SFR */
/* Bitname _PMOD1 cannot be defined because it is used by more than one SFR */

/* FCLCON1 */
/* Bitname _FLTMOD cannot be defined because it is used by more than one SFR */
/* Bitname _FLTPOL cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSRC cannot be defined because it is used by more than one SFR */
/* Bitname _CLMOD cannot be defined because it is used by more than one SFR */
/* Bitname _CLPOL cannot be defined because it is used by more than one SFR */
/* Bitname _CLSRC cannot be defined because it is used by more than one SFR */
/* Bitname _IFLTMOD cannot be defined because it is used by more than one SFR */
/* Bitname _FLTMOD0 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTMOD1 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSRC0 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSRC1 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSRC2 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSRC3 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSRC4 cannot be defined because it is used by more than one SFR */
/* Bitname _CLSRC0 cannot be defined because it is used by more than one SFR */
/* Bitname _CLSRC1 cannot be defined because it is used by more than one SFR */
/* Bitname _CLSRC2 cannot be defined because it is used by more than one SFR */
/* Bitname _CLSRC3 cannot be defined because it is used by more than one SFR */
/* Bitname _CLSRC4 cannot be defined because it is used by more than one SFR */

/* TRIG1 */
/* Bitname _TRGCMP cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP0 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP1 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP2 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP3 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP4 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP5 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP6 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP7 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP8 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP9 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP10 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP11 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP12 cannot be defined because it is used by more than one SFR */

/* TRGCON1 */
/* Bitname _TRGSTRT cannot be defined because it is used by more than one SFR */
/* Bitname _DTM cannot be defined because it is used by more than one SFR */
/* Bitname _TRGDIV cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTRT0 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTRT1 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTRT2 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTRT3 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTRT4 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTRT5 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGDIV0 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGDIV1 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGDIV2 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGDIV3 cannot be defined because it is used by more than one SFR */

/* STRIG1 */
/* Bitname _STRGCMP cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP0 cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP1 cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP2 cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP3 cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP4 cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP5 cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP6 cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP7 cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP8 cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP9 cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP10 cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP11 cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP12 cannot be defined because it is used by more than one SFR */

/* PWMCAP1 */
#define _PWMCAP10 PWMCAP1bits.PWMCAP10
#define _PWMCAP11 PWMCAP1bits.PWMCAP11
#define _PWMCAP12 PWMCAP1bits.PWMCAP12
#define _PWMCAP13 PWMCAP1bits.PWMCAP13
#define _PWMCAP14 PWMCAP1bits.PWMCAP14
#define _PWMCAP15 PWMCAP1bits.PWMCAP15
#define _PWMCAP16 PWMCAP1bits.PWMCAP16
#define _PWMCAP17 PWMCAP1bits.PWMCAP17
#define _PWMCAP18 PWMCAP1bits.PWMCAP18
#define _PWMCAP19 PWMCAP1bits.PWMCAP19
#define _PWMCAP110 PWMCAP1bits.PWMCAP110
#define _PWMCAP111 PWMCAP1bits.PWMCAP111
#define _PWMCAP112 PWMCAP1bits.PWMCAP112

/* LEBCON1 */
/* Bitname _LEB cannot be defined because it is used by more than one SFR */
/* Bitname _CLLEBEN cannot be defined because it is used by more than one SFR */
/* Bitname _FLTLEBEN cannot be defined because it is used by more than one SFR */
/* Bitname _PLF cannot be defined because it is used by more than one SFR */
/* Bitname _PLR cannot be defined because it is used by more than one SFR */
/* Bitname _PHF cannot be defined because it is used by more than one SFR */
/* Bitname _PHR cannot be defined because it is used by more than one SFR */
/* Bitname _LEB0 cannot be defined because it is used by more than one SFR */
/* Bitname _LEB1 cannot be defined because it is used by more than one SFR */
/* Bitname _LEB2 cannot be defined because it is used by more than one SFR */
/* Bitname _LEB3 cannot be defined because it is used by more than one SFR */
/* Bitname _LEB4 cannot be defined because it is used by more than one SFR */
/* Bitname _LEB5 cannot be defined because it is used by more than one SFR */
/* Bitname _LEB6 cannot be defined because it is used by more than one SFR */

/* PWMCON2 */
/* Bitname _IUE cannot be defined because it is used by more than one SFR */
/* Bitname _XPRES cannot be defined because it is used by more than one SFR */
/* Bitname _CAM cannot be defined because it is used by more than one SFR */
/* Bitname _DTC cannot be defined because it is used by more than one SFR */
/* Bitname _MDCS cannot be defined because it is used by more than one SFR */
/* Bitname _ITB cannot be defined because it is used by more than one SFR */
/* Bitname _TRGIEN cannot be defined because it is used by more than one SFR */
/* Bitname _CLIEN cannot be defined because it is used by more than one SFR */
/* Bitname _FLTIEN cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _CLSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _DTC0 cannot be defined because it is used by more than one SFR */
/* Bitname _DTC1 cannot be defined because it is used by more than one SFR */

/* IOCON2 */
/* Bitname _OSYNC cannot be defined because it is used by more than one SFR */
/* Bitname _SWAP cannot be defined because it is used by more than one SFR */
/* Bitname _CLDAT cannot be defined because it is used by more than one SFR */
/* Bitname _FLTDAT cannot be defined because it is used by more than one SFR */
/* Bitname _OVRDAT cannot be defined because it is used by more than one SFR */
/* Bitname _OVRENL cannot be defined because it is used by more than one SFR */
/* Bitname _OVRENH cannot be defined because it is used by more than one SFR */
/* Bitname _PMOD cannot be defined because it is used by more than one SFR */
/* Bitname _POLL cannot be defined because it is used by more than one SFR */
/* Bitname _POLH cannot be defined because it is used by more than one SFR */
/* Bitname _PENL cannot be defined because it is used by more than one SFR */
/* Bitname _PENH cannot be defined because it is used by more than one SFR */
/* Bitname _CLDAT0 cannot be defined because it is used by more than one SFR */
/* Bitname _CLDAT1 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTDAT0 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTDAT1 cannot be defined because it is used by more than one SFR */
/* Bitname _OVRDAT0 cannot be defined because it is used by more than one SFR */
/* Bitname _OVRDAT1 cannot be defined because it is used by more than one SFR */
/* Bitname _PMOD0 cannot be defined because it is used by more than one SFR */
/* Bitname _PMOD1 cannot be defined because it is used by more than one SFR */

/* FCLCON2 */
/* Bitname _FLTMOD cannot be defined because it is used by more than one SFR */
/* Bitname _FLTPOL cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSRC cannot be defined because it is used by more than one SFR */
/* Bitname _CLMOD cannot be defined because it is used by more than one SFR */
/* Bitname _CLPOL cannot be defined because it is used by more than one SFR */
/* Bitname _CLSRC cannot be defined because it is used by more than one SFR */
/* Bitname _IFLTMOD cannot be defined because it is used by more than one SFR */
/* Bitname _FLTMOD0 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTMOD1 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSRC0 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSRC1 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSRC2 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSRC3 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSRC4 cannot be defined because it is used by more than one SFR */
/* Bitname _CLSRC0 cannot be defined because it is used by more than one SFR */
/* Bitname _CLSRC1 cannot be defined because it is used by more than one SFR */
/* Bitname _CLSRC2 cannot be defined because it is used by more than one SFR */
/* Bitname _CLSRC3 cannot be defined because it is used by more than one SFR */
/* Bitname _CLSRC4 cannot be defined because it is used by more than one SFR */

/* TRIG2 */
/* Bitname _TRGCMP cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP0 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP1 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP2 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP3 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP4 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP5 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP6 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP7 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP8 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP9 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP10 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP11 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP12 cannot be defined because it is used by more than one SFR */

/* TRGCON2 */
/* Bitname _TRGSTRT cannot be defined because it is used by more than one SFR */
/* Bitname _DTM cannot be defined because it is used by more than one SFR */
/* Bitname _TRGDIV cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTRT0 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTRT1 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTRT2 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTRT3 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTRT4 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTRT5 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGDIV0 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGDIV1 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGDIV2 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGDIV3 cannot be defined because it is used by more than one SFR */

/* STRIG2 */
/* Bitname _STRGCMP cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP0 cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP1 cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP2 cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP3 cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP4 cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP5 cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP6 cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP7 cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP8 cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP9 cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP10 cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP11 cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP12 cannot be defined because it is used by more than one SFR */

/* LEBCON2 */
/* Bitname _LEB cannot be defined because it is used by more than one SFR */
/* Bitname _CLLEBEN cannot be defined because it is used by more than one SFR */
/* Bitname _FLTLEBEN cannot be defined because it is used by more than one SFR */
/* Bitname _PLF cannot be defined because it is used by more than one SFR */
/* Bitname _PLR cannot be defined because it is used by more than one SFR */
/* Bitname _PHF cannot be defined because it is used by more than one SFR */
/* Bitname _PHR cannot be defined because it is used by more than one SFR */
/* Bitname _LEB0 cannot be defined because it is used by more than one SFR */
/* Bitname _LEB1 cannot be defined because it is used by more than one SFR */
/* Bitname _LEB2 cannot be defined because it is used by more than one SFR */
/* Bitname _LEB3 cannot be defined because it is used by more than one SFR */
/* Bitname _LEB4 cannot be defined because it is used by more than one SFR */
/* Bitname _LEB5 cannot be defined because it is used by more than one SFR */
/* Bitname _LEB6 cannot be defined because it is used by more than one SFR */

/* PWMCON3 */
/* Bitname _IUE cannot be defined because it is used by more than one SFR */
/* Bitname _XPRES cannot be defined because it is used by more than one SFR */
/* Bitname _CAM cannot be defined because it is used by more than one SFR */
/* Bitname _DTC cannot be defined because it is used by more than one SFR */
/* Bitname _MDCS cannot be defined because it is used by more than one SFR */
/* Bitname _ITB cannot be defined because it is used by more than one SFR */
/* Bitname _TRGIEN cannot be defined because it is used by more than one SFR */
/* Bitname _CLIEN cannot be defined because it is used by more than one SFR */
/* Bitname _FLTIEN cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _CLSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _DTC0 cannot be defined because it is used by more than one SFR */
/* Bitname _DTC1 cannot be defined because it is used by more than one SFR */

/* IOCON3 */
/* Bitname _OSYNC cannot be defined because it is used by more than one SFR */
/* Bitname _SWAP cannot be defined because it is used by more than one SFR */
/* Bitname _CLDAT cannot be defined because it is used by more than one SFR */
/* Bitname _FLTDAT cannot be defined because it is used by more than one SFR */
/* Bitname _OVRDAT cannot be defined because it is used by more than one SFR */
/* Bitname _OVRENL cannot be defined because it is used by more than one SFR */
/* Bitname _OVRENH cannot be defined because it is used by more than one SFR */
/* Bitname _PMOD cannot be defined because it is used by more than one SFR */
/* Bitname _POLL cannot be defined because it is used by more than one SFR */
/* Bitname _POLH cannot be defined because it is used by more than one SFR */
/* Bitname _PENL cannot be defined because it is used by more than one SFR */
/* Bitname _PENH cannot be defined because it is used by more than one SFR */
/* Bitname _CLDAT0 cannot be defined because it is used by more than one SFR */
/* Bitname _CLDAT1 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTDAT0 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTDAT1 cannot be defined because it is used by more than one SFR */
/* Bitname _OVRDAT0 cannot be defined because it is used by more than one SFR */
/* Bitname _OVRDAT1 cannot be defined because it is used by more than one SFR */
/* Bitname _PMOD0 cannot be defined because it is used by more than one SFR */
/* Bitname _PMOD1 cannot be defined because it is used by more than one SFR */

/* FCLCON3 */
/* Bitname _FLTMOD cannot be defined because it is used by more than one SFR */
/* Bitname _FLTPOL cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSRC cannot be defined because it is used by more than one SFR */
/* Bitname _CLMOD cannot be defined because it is used by more than one SFR */
/* Bitname _CLPOL cannot be defined because it is used by more than one SFR */
/* Bitname _CLSRC cannot be defined because it is used by more than one SFR */
/* Bitname _IFLTMOD cannot be defined because it is used by more than one SFR */
/* Bitname _FLTMOD0 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTMOD1 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSRC0 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSRC1 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSRC2 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSRC3 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSRC4 cannot be defined because it is used by more than one SFR */
/* Bitname _CLSRC0 cannot be defined because it is used by more than one SFR */
/* Bitname _CLSRC1 cannot be defined because it is used by more than one SFR */
/* Bitname _CLSRC2 cannot be defined because it is used by more than one SFR */
/* Bitname _CLSRC3 cannot be defined because it is used by more than one SFR */
/* Bitname _CLSRC4 cannot be defined because it is used by more than one SFR */

/* TRIG3 */
/* Bitname _TRGCMP cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP0 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP1 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP2 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP3 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP4 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP5 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP6 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP7 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP8 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP9 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP10 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP11 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP12 cannot be defined because it is used by more than one SFR */

/* TRGCON3 */
/* Bitname _TRGSTRT cannot be defined because it is used by more than one SFR */
/* Bitname _DTM cannot be defined because it is used by more than one SFR */
/* Bitname _TRGDIV cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTRT0 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTRT1 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTRT2 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTRT3 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTRT4 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTRT5 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGDIV0 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGDIV1 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGDIV2 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGDIV3 cannot be defined because it is used by more than one SFR */

/* STRIG3 */
/* Bitname _STRGCMP cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP0 cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP1 cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP2 cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP3 cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP4 cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP5 cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP6 cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP7 cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP8 cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP9 cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP10 cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP11 cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP12 cannot be defined because it is used by more than one SFR */

/* LEBCON3 */
/* Bitname _LEB cannot be defined because it is used by more than one SFR */
/* Bitname _CLLEBEN cannot be defined because it is used by more than one SFR */
/* Bitname _FLTLEBEN cannot be defined because it is used by more than one SFR */
/* Bitname _PLF cannot be defined because it is used by more than one SFR */
/* Bitname _PLR cannot be defined because it is used by more than one SFR */
/* Bitname _PHF cannot be defined because it is used by more than one SFR */
/* Bitname _PHR cannot be defined because it is used by more than one SFR */
/* Bitname _LEB0 cannot be defined because it is used by more than one SFR */
/* Bitname _LEB1 cannot be defined because it is used by more than one SFR */
/* Bitname _LEB2 cannot be defined because it is used by more than one SFR */
/* Bitname _LEB3 cannot be defined because it is used by more than one SFR */
/* Bitname _LEB4 cannot be defined because it is used by more than one SFR */
/* Bitname _LEB5 cannot be defined because it is used by more than one SFR */
/* Bitname _LEB6 cannot be defined because it is used by more than one SFR */

/* PWMCON4 */
/* Bitname _IUE cannot be defined because it is used by more than one SFR */
/* Bitname _XPRES cannot be defined because it is used by more than one SFR */
/* Bitname _CAM cannot be defined because it is used by more than one SFR */
/* Bitname _DTC cannot be defined because it is used by more than one SFR */
/* Bitname _MDCS cannot be defined because it is used by more than one SFR */
/* Bitname _ITB cannot be defined because it is used by more than one SFR */
/* Bitname _TRGIEN cannot be defined because it is used by more than one SFR */
/* Bitname _CLIEN cannot be defined because it is used by more than one SFR */
/* Bitname _FLTIEN cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _CLSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _DTC0 cannot be defined because it is used by more than one SFR */
/* Bitname _DTC1 cannot be defined because it is used by more than one SFR */

/* IOCON4 */
/* Bitname _OSYNC cannot be defined because it is used by more than one SFR */
/* Bitname _SWAP cannot be defined because it is used by more than one SFR */
/* Bitname _CLDAT cannot be defined because it is used by more than one SFR */
/* Bitname _FLTDAT cannot be defined because it is used by more than one SFR */
/* Bitname _OVRDAT cannot be defined because it is used by more than one SFR */
/* Bitname _OVRENL cannot be defined because it is used by more than one SFR */
/* Bitname _OVRENH cannot be defined because it is used by more than one SFR */
/* Bitname _PMOD cannot be defined because it is used by more than one SFR */
/* Bitname _POLL cannot be defined because it is used by more than one SFR */
/* Bitname _POLH cannot be defined because it is used by more than one SFR */
/* Bitname _PENL cannot be defined because it is used by more than one SFR */
/* Bitname _PENH cannot be defined because it is used by more than one SFR */
/* Bitname _CLDAT0 cannot be defined because it is used by more than one SFR */
/* Bitname _CLDAT1 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTDAT0 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTDAT1 cannot be defined because it is used by more than one SFR */
/* Bitname _OVRDAT0 cannot be defined because it is used by more than one SFR */
/* Bitname _OVRDAT1 cannot be defined because it is used by more than one SFR */
/* Bitname _PMOD0 cannot be defined because it is used by more than one SFR */
/* Bitname _PMOD1 cannot be defined because it is used by more than one SFR */

/* FCLCON4 */
/* Bitname _FLTMOD cannot be defined because it is used by more than one SFR */
/* Bitname _FLTPOL cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSRC cannot be defined because it is used by more than one SFR */
/* Bitname _CLMOD cannot be defined because it is used by more than one SFR */
/* Bitname _CLPOL cannot be defined because it is used by more than one SFR */
/* Bitname _CLSRC cannot be defined because it is used by more than one SFR */
/* Bitname _IFLTMOD cannot be defined because it is used by more than one SFR */
/* Bitname _FLTMOD0 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTMOD1 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSRC0 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSRC1 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSRC2 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSRC3 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSRC4 cannot be defined because it is used by more than one SFR */
/* Bitname _CLSRC0 cannot be defined because it is used by more than one SFR */
/* Bitname _CLSRC1 cannot be defined because it is used by more than one SFR */
/* Bitname _CLSRC2 cannot be defined because it is used by more than one SFR */
/* Bitname _CLSRC3 cannot be defined because it is used by more than one SFR */
/* Bitname _CLSRC4 cannot be defined because it is used by more than one SFR */

/* TRIG4 */
/* Bitname _TRGCMP cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP0 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP1 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP2 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP3 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP4 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP5 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP6 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP7 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP8 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP9 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP10 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP11 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGCMP12 cannot be defined because it is used by more than one SFR */

/* TRGCON4 */
/* Bitname _TRGSTRT cannot be defined because it is used by more than one SFR */
/* Bitname _DTM cannot be defined because it is used by more than one SFR */
/* Bitname _TRGDIV cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTRT0 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTRT1 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTRT2 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTRT3 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTRT4 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTRT5 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGDIV0 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGDIV1 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGDIV2 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGDIV3 cannot be defined because it is used by more than one SFR */

/* STRIG4 */
/* Bitname _STRGCMP cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP0 cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP1 cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP2 cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP3 cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP4 cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP5 cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP6 cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP7 cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP8 cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP9 cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP10 cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP11 cannot be defined because it is used by more than one SFR */
/* Bitname _STRGCMP12 cannot be defined because it is used by more than one SFR */

/* LEBCON4 */
/* Bitname _LEB cannot be defined because it is used by more than one SFR */
/* Bitname _CLLEBEN cannot be defined because it is used by more than one SFR */
/* Bitname _FLTLEBEN cannot be defined because it is used by more than one SFR */
/* Bitname _PLF cannot be defined because it is used by more than one SFR */
/* Bitname _PLR cannot be defined because it is used by more than one SFR */
/* Bitname _PHF cannot be defined because it is used by more than one SFR */
/* Bitname _PHR cannot be defined because it is used by more than one SFR */
/* Bitname _LEB0 cannot be defined because it is used by more than one SFR */
/* Bitname _LEB1 cannot be defined because it is used by more than one SFR */
/* Bitname _LEB2 cannot be defined because it is used by more than one SFR */
/* Bitname _LEB3 cannot be defined because it is used by more than one SFR */
/* Bitname _LEB4 cannot be defined because it is used by more than one SFR */
/* Bitname _LEB5 cannot be defined because it is used by more than one SFR */
/* Bitname _LEB6 cannot be defined because it is used by more than one SFR */

/* CMPCON1 */
/* Bitname _RANGE cannot be defined because it is used by more than one SFR */
/* Bitname _CMPPOL cannot be defined because it is used by more than one SFR */
/* Bitname _CMPSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _EXTREF cannot be defined because it is used by more than one SFR */
/* Bitname _INSEL cannot be defined because it is used by more than one SFR */
/* Bitname _DACOE cannot be defined because it is used by more than one SFR */
/* Bitname _CMPSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _CMPON cannot be defined because it is used by more than one SFR */
/* Bitname _INSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _INSEL1 cannot be defined because it is used by more than one SFR */

/* CMPDAC1 */
/* Bitname _CMREF cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF0 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF1 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF2 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF3 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF4 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF5 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF6 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF7 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF8 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF9 cannot be defined because it is used by more than one SFR */

/* CMPCON2 */
/* Bitname _RANGE cannot be defined because it is used by more than one SFR */
/* Bitname _CMPPOL cannot be defined because it is used by more than one SFR */
/* Bitname _CMPSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _EXTREF cannot be defined because it is used by more than one SFR */
/* Bitname _INSEL cannot be defined because it is used by more than one SFR */
/* Bitname _DACOE cannot be defined because it is used by more than one SFR */
/* Bitname _CMPSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _CMPON cannot be defined because it is used by more than one SFR */
/* Bitname _INSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _INSEL1 cannot be defined because it is used by more than one SFR */

/* CMPDAC2 */
/* Bitname _CMREF cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF0 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF1 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF2 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF3 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF4 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF5 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF6 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF7 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF8 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF9 cannot be defined because it is used by more than one SFR */

/* CMPCON3 */
/* Bitname _RANGE cannot be defined because it is used by more than one SFR */
/* Bitname _CMPPOL cannot be defined because it is used by more than one SFR */
/* Bitname _CMPSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _EXTREF cannot be defined because it is used by more than one SFR */
/* Bitname _INSEL cannot be defined because it is used by more than one SFR */
/* Bitname _DACOE cannot be defined because it is used by more than one SFR */
/* Bitname _CMPSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _CMPON cannot be defined because it is used by more than one SFR */
/* Bitname _INSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _INSEL1 cannot be defined because it is used by more than one SFR */

/* CMPDAC3 */
/* Bitname _CMREF cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF0 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF1 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF2 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF3 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF4 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF5 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF6 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF7 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF8 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF9 cannot be defined because it is used by more than one SFR */

/* CMPCON4 */
/* Bitname _RANGE cannot be defined because it is used by more than one SFR */
/* Bitname _CMPPOL cannot be defined because it is used by more than one SFR */
/* Bitname _CMPSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _EXTREF cannot be defined because it is used by more than one SFR */
/* Bitname _INSEL cannot be defined because it is used by more than one SFR */
/* Bitname _DACOE cannot be defined because it is used by more than one SFR */
/* Bitname _CMPSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _CMPON cannot be defined because it is used by more than one SFR */
/* Bitname _INSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _INSEL1 cannot be defined because it is used by more than one SFR */

/* CMPDAC4 */
/* Bitname _CMREF cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF0 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF1 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF2 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF3 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF4 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF5 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF6 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF7 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF8 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF9 cannot be defined because it is used by more than one SFR */

/* RPINR0 */
#define _INT1R RPINR0bits.INT1R
#define _INT1R0 RPINR0bits.INT1R0
#define _INT1R1 RPINR0bits.INT1R1
#define _INT1R2 RPINR0bits.INT1R2
#define _INT1R3 RPINR0bits.INT1R3
#define _INT1R4 RPINR0bits.INT1R4
#define _INT1R5 RPINR0bits.INT1R5

/* RPINR1 */
#define _INT2R RPINR1bits.INT2R
#define _INT2R0 RPINR1bits.INT2R0
#define _INT2R1 RPINR1bits.INT2R1
#define _INT2R2 RPINR1bits.INT2R2
#define _INT2R3 RPINR1bits.INT2R3
#define _INT2R4 RPINR1bits.INT2R4
#define _INT2R5 RPINR1bits.INT2R5

/* RPINR2 */
#define _T1CKR RPINR2bits.T1CKR
#define _T1CKR0 RPINR2bits.T1CKR0
#define _T1CKR1 RPINR2bits.T1CKR1
#define _T1CKR2 RPINR2bits.T1CKR2
#define _T1CKR3 RPINR2bits.T1CKR3
#define _T1CKR4 RPINR2bits.T1CKR4
#define _T1CKR5 RPINR2bits.T1CKR5

/* RPINR3 */
#define _T2CKR RPINR3bits.T2CKR
#define _T3CKR RPINR3bits.T3CKR
#define _T2CKR0 RPINR3bits.T2CKR0
#define _T2CKR1 RPINR3bits.T2CKR1
#define _T2CKR2 RPINR3bits.T2CKR2
#define _T2CKR3 RPINR3bits.T2CKR3
#define _T2CKR4 RPINR3bits.T2CKR4
#define _T2CKR5 RPINR3bits.T2CKR5
#define _T3CKR0 RPINR3bits.T3CKR0
#define _T3CKR1 RPINR3bits.T3CKR1
#define _T3CKR2 RPINR3bits.T3CKR2
#define _T3CKR3 RPINR3bits.T3CKR3
#define _T3CKR4 RPINR3bits.T3CKR4
#define _T3CKR5 RPINR3bits.T3CKR5

/* RPINR7 */
#define _IC1R RPINR7bits.IC1R
#define _IC2R RPINR7bits.IC2R
#define _IC1R0 RPINR7bits.IC1R0
#define _IC1R1 RPINR7bits.IC1R1
#define _IC1R2 RPINR7bits.IC1R2
#define _IC1R3 RPINR7bits.IC1R3
#define _IC1R4 RPINR7bits.IC1R4
#define _IC1R5 RPINR7bits.IC1R5
#define _IC2R0 RPINR7bits.IC2R0
#define _IC2R1 RPINR7bits.IC2R1
#define _IC2R2 RPINR7bits.IC2R2
#define _IC2R3 RPINR7bits.IC2R3
#define _IC2R4 RPINR7bits.IC2R4
#define _IC2R5 RPINR7bits.IC2R5

/* RPINR11 */
#define _OCFAR RPINR11bits.OCFAR
#define _OCFAR0 RPINR11bits.OCFAR0
#define _OCFAR1 RPINR11bits.OCFAR1
#define _OCFAR2 RPINR11bits.OCFAR2
#define _OCFAR3 RPINR11bits.OCFAR3
#define _OCFAR4 RPINR11bits.OCFAR4
#define _OCFAR5 RPINR11bits.OCFAR5

/* RPINR18 */
#define _U1RXR RPINR18bits.U1RXR
#define _U1CTSR RPINR18bits.U1CTSR
#define _U1RXR0 RPINR18bits.U1RXR0
#define _U1RXR1 RPINR18bits.U1RXR1
#define _U1RXR2 RPINR18bits.U1RXR2
#define _U1RXR3 RPINR18bits.U1RXR3
#define _U1RXR4 RPINR18bits.U1RXR4
#define _U1RXR5 RPINR18bits.U1RXR5
#define _U1CTSR0 RPINR18bits.U1CTSR0
#define _U1CTSR1 RPINR18bits.U1CTSR1
#define _U1CTSR2 RPINR18bits.U1CTSR2
#define _U1CTSR3 RPINR18bits.U1CTSR3
#define _U1CTSR4 RPINR18bits.U1CTSR4
#define _U1CTSR5 RPINR18bits.U1CTSR5

/* RPINR20 */
#define _SDI1R RPINR20bits.SDI1R
#define _SCK1R RPINR20bits.SCK1R
#define _SDI1R0 RPINR20bits.SDI1R0
#define _SDI1R1 RPINR20bits.SDI1R1
#define _SDI1R2 RPINR20bits.SDI1R2
#define _SDI1R3 RPINR20bits.SDI1R3
#define _SDI1R4 RPINR20bits.SDI1R4
#define _SDI1R5 RPINR20bits.SDI1R5
#define _SCK1R0 RPINR20bits.SCK1R0
#define _SCK1R1 RPINR20bits.SCK1R1
#define _SCK1R2 RPINR20bits.SCK1R2
#define _SCK1R3 RPINR20bits.SCK1R3
#define _SCK1R4 RPINR20bits.SCK1R4
#define _SCK1R5 RPINR20bits.SCK1R5

/* RPINR21 */
#define _SS1R RPINR21bits.SS1R
#define _SS1R0 RPINR21bits.SS1R0
#define _SS1R1 RPINR21bits.SS1R1
#define _SS1R2 RPINR21bits.SS1R2
#define _SS1R3 RPINR21bits.SS1R3
#define _SS1R4 RPINR21bits.SS1R4
#define _SS1R5 RPINR21bits.SS1R5

/* RPINR29 */
#define _FLT1R RPINR29bits.FLT1R
#define _FLT1R0 RPINR29bits.FLT1R0
#define _FLT1R1 RPINR29bits.FLT1R1
#define _FLT1R2 RPINR29bits.FLT1R2
#define _FLT1R3 RPINR29bits.FLT1R3
#define _FLT1R4 RPINR29bits.FLT1R4
#define _FLT1R5 RPINR29bits.FLT1R5

/* RPINR30 */
#define _FLT2R RPINR30bits.FLT2R
#define _FLT3R RPINR30bits.FLT3R
#define _FLT2R0 RPINR30bits.FLT2R0
#define _FLT2R1 RPINR30bits.FLT2R1
#define _FLT2R2 RPINR30bits.FLT2R2
#define _FLT2R3 RPINR30bits.FLT2R3
#define _FLT2R4 RPINR30bits.FLT2R4
#define _FLT2R5 RPINR30bits.FLT2R5
#define _FLT3R0 RPINR30bits.FLT3R0
#define _FLT3R1 RPINR30bits.FLT3R1
#define _FLT3R2 RPINR30bits.FLT3R2
#define _FLT3R3 RPINR30bits.FLT3R3
#define _FLT3R4 RPINR30bits.FLT3R4
#define _FLT3R5 RPINR30bits.FLT3R5

/* RPINR31 */
#define _FLT4R RPINR31bits.FLT4R
#define _FLT5R RPINR31bits.FLT5R
#define _FLT4R0 RPINR31bits.FLT4R0
#define _FLT4R1 RPINR31bits.FLT4R1
#define _FLT4R2 RPINR31bits.FLT4R2
#define _FLT4R3 RPINR31bits.FLT4R3
#define _FLT4R4 RPINR31bits.FLT4R4
#define _FLT4R5 RPINR31bits.FLT4R5
#define _FLT5R0 RPINR31bits.FLT5R0
#define _FLT5R1 RPINR31bits.FLT5R1
#define _FLT5R2 RPINR31bits.FLT5R2
#define _FLT5R3 RPINR31bits.FLT5R3
#define _FLT5R4 RPINR31bits.FLT5R4
#define _FLT5R5 RPINR31bits.FLT5R5

/* RPINR32 */
#define _FLT6R RPINR32bits.FLT6R
#define _FLT7R RPINR32bits.FLT7R
#define _FLT6R0 RPINR32bits.FLT6R0
#define _FLT6R1 RPINR32bits.FLT6R1
#define _FLT6R2 RPINR32bits.FLT6R2
#define _FLT6R3 RPINR32bits.FLT6R3
#define _FLT6R4 RPINR32bits.FLT6R4
#define _FLT6R5 RPINR32bits.FLT6R5
#define _FLT7R0 RPINR32bits.FLT7R0
#define _FLT7R1 RPINR32bits.FLT7R1
#define _FLT7R2 RPINR32bits.FLT7R2
#define _FLT7R3 RPINR32bits.FLT7R3
#define _FLT7R4 RPINR32bits.FLT7R4
#define _FLT7R5 RPINR32bits.FLT7R5

/* RPINR33 */
#define _FLT8R RPINR33bits.FLT8R
#define _SYNCI1R RPINR33bits.SYNCI1R
#define _FLT8R0 RPINR33bits.FLT8R0
#define _FLT8R1 RPINR33bits.FLT8R1
#define _FLT8R2 RPINR33bits.FLT8R2
#define _FLT8R3 RPINR33bits.FLT8R3
#define _FLT8R4 RPINR33bits.FLT8R4
#define _FLT8R5 RPINR33bits.FLT8R5
#define _SYNCI1R0 RPINR33bits.SYNCI1R0
#define _SYNCI1R1 RPINR33bits.SYNCI1R1
#define _SYNCI1R2 RPINR33bits.SYNCI1R2
#define _SYNCI1R3 RPINR33bits.SYNCI1R3
#define _SYNCI1R4 RPINR33bits.SYNCI1R4
#define _SYNCI1R5 RPINR33bits.SYNCI1R5

/* RPINR34 */
#define _SYNCI2R RPINR34bits.SYNCI2R
#define _SYNCI2R0 RPINR34bits.SYNCI2R0
#define _SYNCI2R1 RPINR34bits.SYNCI2R1
#define _SYNCI2R2 RPINR34bits.SYNCI2R2
#define _SYNCI2R3 RPINR34bits.SYNCI2R3
#define _SYNCI2R4 RPINR34bits.SYNCI2R4
#define _SYNCI2R5 RPINR34bits.SYNCI2R5

/* RPOR0 */
#define _RP0R RPOR0bits.RP0R
#define _RP1R RPOR0bits.RP1R
#define _RP0R0 RPOR0bits.RP0R0
#define _RP0R1 RPOR0bits.RP0R1
#define _RP0R2 RPOR0bits.RP0R2
#define _RP0R3 RPOR0bits.RP0R3
#define _RP0R4 RPOR0bits.RP0R4
#define _RP0R5 RPOR0bits.RP0R5
#define _RP1R0 RPOR0bits.RP1R0
#define _RP1R1 RPOR0bits.RP1R1
#define _RP1R2 RPOR0bits.RP1R2
#define _RP1R3 RPOR0bits.RP1R3
#define _RP1R4 RPOR0bits.RP1R4
#define _RP1R5 RPOR0bits.RP1R5

/* RPOR1 */
#define _RP2R RPOR1bits.RP2R
#define _RP3R RPOR1bits.RP3R
#define _RP2R0 RPOR1bits.RP2R0
#define _RP2R1 RPOR1bits.RP2R1
#define _RP2R2 RPOR1bits.RP2R2
#define _RP2R3 RPOR1bits.RP2R3
#define _RP2R4 RPOR1bits.RP2R4
#define _RP2R5 RPOR1bits.RP2R5
#define _RP3R0 RPOR1bits.RP3R0
#define _RP3R1 RPOR1bits.RP3R1
#define _RP3R2 RPOR1bits.RP3R2
#define _RP3R3 RPOR1bits.RP3R3
#define _RP3R4 RPOR1bits.RP3R4
#define _RP3R5 RPOR1bits.RP3R5

/* RPOR2 */
#define _RP4R RPOR2bits.RP4R
#define _RP5R RPOR2bits.RP5R
#define _RP4R0 RPOR2bits.RP4R0
#define _RP4R1 RPOR2bits.RP4R1
#define _RP4R2 RPOR2bits.RP4R2
#define _RP4R3 RPOR2bits.RP4R3
#define _RP4R4 RPOR2bits.RP4R4
#define _RP4R5 RPOR2bits.RP4R5
#define _RP5R0 RPOR2bits.RP5R0
#define _RP5R1 RPOR2bits.RP5R1
#define _RP5R2 RPOR2bits.RP5R2
#define _RP5R3 RPOR2bits.RP5R3
#define _RP5R4 RPOR2bits.RP5R4
#define _RP5R5 RPOR2bits.RP5R5

/* RPOR3 */
#define _RP6R RPOR3bits.RP6R
#define _RP7R RPOR3bits.RP7R
#define _RP6R0 RPOR3bits.RP6R0
#define _RP6R1 RPOR3bits.RP6R1
#define _RP6R2 RPOR3bits.RP6R2
#define _RP6R3 RPOR3bits.RP6R3
#define _RP6R4 RPOR3bits.RP6R4
#define _RP6R5 RPOR3bits.RP6R5
#define _RP7R0 RPOR3bits.RP7R0
#define _RP7R1 RPOR3bits.RP7R1
#define _RP7R2 RPOR3bits.RP7R2
#define _RP7R3 RPOR3bits.RP7R3
#define _RP7R4 RPOR3bits.RP7R4
#define _RP7R5 RPOR3bits.RP7R5

/* RPOR4 */
#define _RP8R RPOR4bits.RP8R
#define _RP9R RPOR4bits.RP9R
#define _RP8R0 RPOR4bits.RP8R0
#define _RP8R1 RPOR4bits.RP8R1
#define _RP8R2 RPOR4bits.RP8R2
#define _RP8R3 RPOR4bits.RP8R3
#define _RP8R4 RPOR4bits.RP8R4
#define _RP8R5 RPOR4bits.RP8R5
#define _RP9R0 RPOR4bits.RP9R0
#define _RP9R1 RPOR4bits.RP9R1
#define _RP9R2 RPOR4bits.RP9R2
#define _RP9R3 RPOR4bits.RP9R3
#define _RP9R4 RPOR4bits.RP9R4
#define _RP9R5 RPOR4bits.RP9R5

/* RPOR5 */
#define _RP10R RPOR5bits.RP10R
#define _RP11R RPOR5bits.RP11R
#define _RP10R0 RPOR5bits.RP10R0
#define _RP10R1 RPOR5bits.RP10R1
#define _RP10R2 RPOR5bits.RP10R2
#define _RP10R3 RPOR5bits.RP10R3
#define _RP10R4 RPOR5bits.RP10R4
#define _RP10R5 RPOR5bits.RP10R5
#define _RP11R0 RPOR5bits.RP11R0
#define _RP11R1 RPOR5bits.RP11R1
#define _RP11R2 RPOR5bits.RP11R2
#define _RP11R3 RPOR5bits.RP11R3
#define _RP11R4 RPOR5bits.RP11R4
#define _RP11R5 RPOR5bits.RP11R5

/* RPOR6 */
#define _RP12R RPOR6bits.RP12R
#define _RP13R RPOR6bits.RP13R
#define _RP12R0 RPOR6bits.RP12R0
#define _RP12R1 RPOR6bits.RP12R1
#define _RP12R2 RPOR6bits.RP12R2
#define _RP12R3 RPOR6bits.RP12R3
#define _RP12R4 RPOR6bits.RP12R4
#define _RP12R5 RPOR6bits.RP12R5
#define _RP13R0 RPOR6bits.RP13R0
#define _RP13R1 RPOR6bits.RP13R1
#define _RP13R2 RPOR6bits.RP13R2
#define _RP13R3 RPOR6bits.RP13R3
#define _RP13R4 RPOR6bits.RP13R4
#define _RP13R5 RPOR6bits.RP13R5

/* RPOR7 */
#define _RP14R RPOR7bits.RP14R
#define _RP15R RPOR7bits.RP15R
#define _RP14R0 RPOR7bits.RP14R0
#define _RP14R1 RPOR7bits.RP14R1
#define _RP14R2 RPOR7bits.RP14R2
#define _RP14R3 RPOR7bits.RP14R3
#define _RP14R4 RPOR7bits.RP14R4
#define _RP14R5 RPOR7bits.RP14R5
#define _RP15R0 RPOR7bits.RP15R0
#define _RP15R1 RPOR7bits.RP15R1
#define _RP15R2 RPOR7bits.RP15R2
#define _RP15R3 RPOR7bits.RP15R3
#define _RP15R4 RPOR7bits.RP15R4
#define _RP15R5 RPOR7bits.RP15R5

/* RPOR8 */
#define _RP16R RPOR8bits.RP16R
#define _RP17R RPOR8bits.RP17R
#define _RP16R0 RPOR8bits.RP16R0
#define _RP16R1 RPOR8bits.RP16R1
#define _RP16R2 RPOR8bits.RP16R2
#define _RP16R3 RPOR8bits.RP16R3
#define _RP16R4 RPOR8bits.RP16R4
#define _RP16R5 RPOR8bits.RP16R5
#define _RP17R0 RPOR8bits.RP17R0
#define _RP17R1 RPOR8bits.RP17R1
#define _RP17R2 RPOR8bits.RP17R2
#define _RP17R3 RPOR8bits.RP17R3
#define _RP17R4 RPOR8bits.RP17R4
#define _RP17R5 RPOR8bits.RP17R5

/* RPOR9 */
#define _RP18R RPOR9bits.RP18R
#define _RP19R RPOR9bits.RP19R
#define _RP18R0 RPOR9bits.RP18R0
#define _RP18R1 RPOR9bits.RP18R1
#define _RP18R2 RPOR9bits.RP18R2
#define _RP18R3 RPOR9bits.RP18R3
#define _RP18R4 RPOR9bits.RP18R4
#define _RP18R5 RPOR9bits.RP18R5
#define _RP19R0 RPOR9bits.RP19R0
#define _RP19R1 RPOR9bits.RP19R1
#define _RP19R2 RPOR9bits.RP19R2
#define _RP19R3 RPOR9bits.RP19R3
#define _RP19R4 RPOR9bits.RP19R4
#define _RP19R5 RPOR9bits.RP19R5

/* RPOR10 */
#define _RP20R RPOR10bits.RP20R
#define _RP21R RPOR10bits.RP21R
#define _RP20R0 RPOR10bits.RP20R0
#define _RP20R1 RPOR10bits.RP20R1
#define _RP20R2 RPOR10bits.RP20R2
#define _RP20R3 RPOR10bits.RP20R3
#define _RP20R4 RPOR10bits.RP20R4
#define _RP20R5 RPOR10bits.RP20R5
#define _RP21R0 RPOR10bits.RP21R0
#define _RP21R1 RPOR10bits.RP21R1
#define _RP21R2 RPOR10bits.RP21R2
#define _RP21R3 RPOR10bits.RP21R3
#define _RP21R4 RPOR10bits.RP21R4
#define _RP21R5 RPOR10bits.RP21R5

/* RPOR11 */
#define _RP22R RPOR11bits.RP22R
#define _RP23R RPOR11bits.RP23R
#define _RP22R0 RPOR11bits.RP22R0
#define _RP22R1 RPOR11bits.RP22R1
#define _RP22R2 RPOR11bits.RP22R2
#define _RP22R3 RPOR11bits.RP22R3
#define _RP22R4 RPOR11bits.RP22R4
#define _RP22R5 RPOR11bits.RP22R5
#define _RP23R0 RPOR11bits.RP23R0
#define _RP23R1 RPOR11bits.RP23R1
#define _RP23R2 RPOR11bits.RP23R2
#define _RP23R3 RPOR11bits.RP23R3
#define _RP23R4 RPOR11bits.RP23R4
#define _RP23R5 RPOR11bits.RP23R5

/* RPOR12 */
#define _RP24R RPOR12bits.RP24R
#define _RP25R RPOR12bits.RP25R
#define _RP24R0 RPOR12bits.RP24R0
#define _RP24R1 RPOR12bits.RP24R1
#define _RP24R2 RPOR12bits.RP24R2
#define _RP24R3 RPOR12bits.RP24R3
#define _RP24R4 RPOR12bits.RP24R4
#define _RP24R5 RPOR12bits.RP24R5
#define _RP25R0 RPOR12bits.RP25R0
#define _RP25R1 RPOR12bits.RP25R1
#define _RP25R2 RPOR12bits.RP25R2
#define _RP25R3 RPOR12bits.RP25R3
#define _RP25R4 RPOR12bits.RP25R4
#define _RP25R5 RPOR12bits.RP25R5

/* RPOR13 */
#define _RP26R RPOR13bits.RP26R
#define _RP27R RPOR13bits.RP27R
#define _RP26R0 RPOR13bits.RP26R0
#define _RP26R1 RPOR13bits.RP26R1
#define _RP26R2 RPOR13bits.RP26R2
#define _RP26R3 RPOR13bits.RP26R3
#define _RP26R4 RPOR13bits.RP26R4
#define _RP26R5 RPOR13bits.RP26R5
#define _RP27R0 RPOR13bits.RP27R0
#define _RP27R1 RPOR13bits.RP27R1
#define _RP27R2 RPOR13bits.RP27R2
#define _RP27R3 RPOR13bits.RP27R3
#define _RP27R4 RPOR13bits.RP27R4
#define _RP27R5 RPOR13bits.RP27R5

/* RPOR14 */
#define _RP28R RPOR14bits.RP28R
#define _RP29R RPOR14bits.RP29R
#define _RP28R0 RPOR14bits.RP28R0
#define _RP28R1 RPOR14bits.RP28R1
#define _RP28R2 RPOR14bits.RP28R2
#define _RP28R3 RPOR14bits.RP28R3
#define _RP28R4 RPOR14bits.RP28R4
#define _RP28R5 RPOR14bits.RP28R5
#define _RP29R0 RPOR14bits.RP29R0
#define _RP29R1 RPOR14bits.RP29R1
#define _RP29R2 RPOR14bits.RP29R2
#define _RP29R3 RPOR14bits.RP29R3
#define _RP29R4 RPOR14bits.RP29R4
#define _RP29R5 RPOR14bits.RP29R5

/* RPOR16 */
#define _RP32R RPOR16bits.RP32R
#define _RP33R RPOR16bits.RP33R
#define _RP32R0 RPOR16bits.RP32R0
#define _RP32R1 RPOR16bits.RP32R1
#define _RP32R2 RPOR16bits.RP32R2
#define _RP32R3 RPOR16bits.RP32R3
#define _RP32R4 RPOR16bits.RP32R4
#define _RP32R5 RPOR16bits.RP32R5
#define _RP33R0 RPOR16bits.RP33R0
#define _RP33R1 RPOR16bits.RP33R1
#define _RP33R2 RPOR16bits.RP33R2
#define _RP33R3 RPOR16bits.RP33R3
#define _RP33R4 RPOR16bits.RP33R4
#define _RP33R5 RPOR16bits.RP33R5

/* RPOR17 */
#define _RP34R RPOR17bits.RP34R
#define _RP35R RPOR17bits.RP35R
#define _RP34R0 RPOR17bits.RP34R0
#define _RP34R1 RPOR17bits.RP34R1
#define _RP34R2 RPOR17bits.RP34R2
#define _RP34R3 RPOR17bits.RP34R3
#define _RP34R4 RPOR17bits.RP34R4
#define _RP34R5 RPOR17bits.RP34R5
#define _RP35R0 RPOR17bits.RP35R0
#define _RP35R1 RPOR17bits.RP35R1
#define _RP35R2 RPOR17bits.RP35R2
#define _RP35R3 RPOR17bits.RP35R3
#define _RP35R4 RPOR17bits.RP35R4
#define _RP35R5 RPOR17bits.RP35R5

/* RCON */
#define _POR RCONbits.POR
#define _BOR RCONbits.BOR
#define _IDLE RCONbits.IDLE
#define _SLEEP RCONbits.SLEEP
#define _WDTO RCONbits.WDTO
#define _SWDTEN RCONbits.SWDTEN
#define _SWR RCONbits.SWR
#define _EXTR RCONbits.EXTR
#define _VREGS RCONbits.VREGS
#define _CM RCONbits.CM
#define _IOPUWR RCONbits.IOPUWR
#define _TRAPR RCONbits.TRAPR

/* OSCCON */
#define _OSWEN OSCCONbits.OSWEN
#define _CF OSCCONbits.CF
#define _LOCK OSCCONbits.LOCK
#define _IOLOCK OSCCONbits.IOLOCK
#define _CLKLOCK OSCCONbits.CLKLOCK
#define _NOSC OSCCONbits.NOSC
#define _COSC OSCCONbits.COSC
#define _NOSC0 OSCCONbits.NOSC0
#define _NOSC1 OSCCONbits.NOSC1
#define _NOSC2 OSCCONbits.NOSC2
#define _COSC0 OSCCONbits.COSC0
#define _COSC1 OSCCONbits.COSC1
#define _COSC2 OSCCONbits.COSC2

/* CLKDIV */
#define _PLLPRE CLKDIVbits.PLLPRE
#define _PLLPOST CLKDIVbits.PLLPOST
#define _FRCDIV CLKDIVbits.FRCDIV
#define _DOZEN CLKDIVbits.DOZEN
#define _DOZE CLKDIVbits.DOZE
#define _ROI CLKDIVbits.ROI
#define _PLLPRE0 CLKDIVbits.PLLPRE0
#define _PLLPRE1 CLKDIVbits.PLLPRE1
#define _PLLPRE2 CLKDIVbits.PLLPRE2
#define _PLLPRE3 CLKDIVbits.PLLPRE3
#define _PLLPRE4 CLKDIVbits.PLLPRE4
#define _PLLPOST0 CLKDIVbits.PLLPOST0
#define _PLLPOST1 CLKDIVbits.PLLPOST1
#define _FRCDIV0 CLKDIVbits.FRCDIV0
#define _FRCDIV1 CLKDIVbits.FRCDIV1
#define _FRCDIV2 CLKDIVbits.FRCDIV2
#define _DOZE0 CLKDIVbits.DOZE0
#define _DOZE1 CLKDIVbits.DOZE1
#define _DOZE2 CLKDIVbits.DOZE2

/* PLLFBD */
#define _PLLDIV PLLFBDbits.PLLDIV
#define _PLLDIV0 PLLFBDbits.PLLDIV0
#define _PLLDIV1 PLLFBDbits.PLLDIV1
#define _PLLDIV2 PLLFBDbits.PLLDIV2
#define _PLLDIV3 PLLFBDbits.PLLDIV3
#define _PLLDIV4 PLLFBDbits.PLLDIV4
#define _PLLDIV5 PLLFBDbits.PLLDIV5
#define _PLLDIV6 PLLFBDbits.PLLDIV6
#define _PLLDIV7 PLLFBDbits.PLLDIV7
#define _PLLDIV8 PLLFBDbits.PLLDIV8

/* OSCTUN */
#define _TUN OSCTUNbits.TUN
#define _TUN0 OSCTUNbits.TUN0
#define _TUN1 OSCTUNbits.TUN1
#define _TUN2 OSCTUNbits.TUN2
#define _TUN3 OSCTUNbits.TUN3
#define _TUN4 OSCTUNbits.TUN4
#define _TUN5 OSCTUNbits.TUN5

/* REFOCON */
#define _RODIV REFOCONbits.RODIV
#define _ROSEL REFOCONbits.ROSEL
#define _ROSIDL REFOCONbits.ROSIDL
#define _ROON REFOCONbits.ROON
#define _RODIV0 REFOCONbits.RODIV0
#define _RODIV1 REFOCONbits.RODIV1
#define _RODIV2 REFOCONbits.RODIV2
#define _RODIV3 REFOCONbits.RODIV3
#define _ROSSLP REFOCONbits.ROSSLP

/* ACLKCON */
#define _FRCSEL ACLKCONbits.FRCSEL
#define _ASRCSEL ACLKCONbits.ASRCSEL
#define _APSTSCLR ACLKCONbits.APSTSCLR
#define _SELACLK ACLKCONbits.SELACLK
#define _APLLCK ACLKCONbits.APLLCK
#define _ENAPLL ACLKCONbits.ENAPLL
#define _APSTSCLR0 ACLKCONbits.APSTSCLR0
#define _APSTSCLR1 ACLKCONbits.APSTSCLR1
#define _APSTSCLR2 ACLKCONbits.APSTSCLR2

/* NVMCON */
#define _NVMOP NVMCONbits.NVMOP
#define _ERASE NVMCONbits.ERASE
#define _WRERR NVMCONbits.WRERR
#define _WREN NVMCONbits.WREN
#define _WR NVMCONbits.WR
#define _NVMOP0 NVMCONbits.NVMOP0
#define _NVMOP1 NVMCONbits.NVMOP1
#define _NVMOP2 NVMCONbits.NVMOP2
#define _NVMOP3 NVMCONbits.NVMOP3

/* PMD1 */
#define _ADCMD PMD1bits.ADCMD
#define _SPI1MD PMD1bits.SPI1MD
#define _U1MD PMD1bits.U1MD
#define _I2C1MD PMD1bits.I2C1MD
#define _PWMMD PMD1bits.PWMMD
#define _T1MD PMD1bits.T1MD
#define _T2MD PMD1bits.T2MD
#define _T3MD PMD1bits.T3MD

/* PMD2 */
#define _OC1MD PMD2bits.OC1MD
#define _OC2MD PMD2bits.OC2MD
#define _IC1MD PMD2bits.IC1MD
#define _IC2MD PMD2bits.IC2MD

/* PMD3 */
#define _CMPMD PMD3bits.CMPMD

/* PMD4 */
#define _REFOMD PMD4bits.REFOMD

/* PMD6 */
#define _PWM1MD PMD6bits.PWM1MD
#define _PWM2MD PMD6bits.PWM2MD
#define _PWM3MD PMD6bits.PWM3MD
#define _PWM4MD PMD6bits.PWM4MD

/* PMD7 */
#define _CMP1MD PMD7bits.CMP1MD
#define _CMP2MD PMD7bits.CMP2MD
#define _CMP3MD PMD7bits.CMP3MD
#define _CMP4MD PMD7bits.CMP4MD


/* ---------------------------------------------------------- */
/* Some useful macros for inline assembler instructions       */
/* ---------------------------------------------------------- */

#define Nop()    __builtin_nop()
#define ClrWdt() {__asm__ volatile ("clrwdt");}
#define Sleep()  {__asm__ volatile ("pwrsav #0");}
#define Idle()   {__asm__ volatile ("pwrsav #1");}

/*----------------------------------------------------------- */
/* Some useful macros for allocating data memory              */
/*----------------------------------------------------------- */

/* The following macros require an argument N that specifies  */
/* alignment. N must a power of two, minimum value = 2.       */
/* For example, to declare an uninitialized array in X memory */
/* that is aligned to a 32 byte address:                      */
/*                                                            */
/* int _XBSS(32) xbuf[16];                                    */
/*                                                            */
#define _XBSS(N)    __attribute__((space(xmemory),far,aligned(N)))
#define _XDATA(N)   __attribute__((space(xmemory),far,aligned(N)))
#define _YBSS(N)    __attribute__((space(ymemory),far,aligned(N)))
#define _YDATA(N)   __attribute__((space(ymemory),far,aligned(N)))

/* The following macros do not require an argument. They can  */
/* be used to locate a variable in persistent data memory or  */
/* in near data memory. For example, to declare two variables */
/* that retain their values across a device reset:            */
/*                                                            */
/* int _PERSISTENT var1,var2;                                 */
/*                                                            */
#define _PERSISTENT __attribute__((persistent))
#define _NEAR       __attribute__((near))

/* ---------------------------------------------------------- */
/* Some useful macros for declaring functions                 */
/* ---------------------------------------------------------- */

/* The following macros can be used to declare interrupt      */
/* service routines (ISRs). For example, to declare an ISR    */
/* for the timer1 interrupt:                                  */
/*                                                            */
/* void _ISR _T1Interrupt(void);                              */
/*                                                            */
/* To declare an ISR for the SPI1 interrupt with fast         */
/* context save:                                              */
/*                                                            */
/* void _ISRFAST _SPI1Interrupt(void);                        */
/*                                                            */
/* Note: ISRs will be installed into the interrupt vector     */
/* tables automatically if the reserved names listed in the   */
/* MPLAB C30 Compiler User's Guide (DS51284) are used.        */
/*                                                            */
#define _ISR __attribute__((interrupt))
#define _ISRFAST __attribute__((interrupt, shadow))

/* ---------------------------------------------------------- */
/* Some useful macros for changing the CPU IPL                */
/* ---------------------------------------------------------- */

/* The following macros can be used to modify the current CPU */
/* IPL. The definition of the macro may vary from device to   */
/* device.                                                    */
/*                                                            */
/* To safely set the CPU IPL, use SET_CPU_IPL(ipl); the       */
/* valid range of ipl is 0-7, it may be any expression.       */
/*                                                            */
/* SET_CPU_IPL(7);                                            */
/*                                                            */
/* To preserve the current IPL and save it use                */
/* SET_AND_SAVE_CPU_IPL(save_to, ipl); the valid range of ipl */
/* is 0-7 and may be any expression, save_to should denote    */
/* some temporary storage.                                    */
/*                                                            */
/* int old_ipl;                                               */
/*                                                            */
/* SET_AND_SAVE_CPU_IPL(old_ipl, 7);                          */
/*                                                            */
/* The IPL can be restored with RESTORE_CPU_IPL(saved_to)     */
/*                                                            */
/* RESTORE_CPU_IPL(old_ipl);                                  */

#define SET_CPU_IPL(ipl) {       \
  int DISI_save;                 \
                                 \
  DISI_save = DISICNT;           \
  asm volatile ("disi #0x3FFF"); \
  SRbits.IPL = ipl;              \
  DISICNT = DISI_save; } (void) 0;

#define SET_AND_SAVE_CPU_IPL(save_to, ipl) { \
  save_to = SRbits.IPL; \
  SET_CPU_IPL(ipl); } (void) 0;

#define RESTORE_CPU_IPL(saved_to) SET_CPU_IPL(saved_to)



/* -------------------------------------------------------- */
/* Macros for setting device configuration registers        */
/* -------------------------------------------------------- */

/* Register FBS (0xf80000)                               */

extern __attribute__((space(prog))) int _FBS;
#define _FBS(x) __attribute__((section("__FBS.sec"),space(prog))) int _FBS = (x);

/*
** Only one invocation of FBS should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set FBS.
** Multiple options may be combined, as shown:
**
** _FBS( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   Boot Segment Write Protect:
**     BWRP_WRPROTECT_ON    Boot Segment is write protected
**     BWRP_WRPROTECT_OFF   Boot Segment may be written
**
**   Boot Segment Program Flash Code Protection:
**     BSS_HIGH_LARGE_BOOT_CODEHigh Security, Large-sized Boot Flash
**     BSS_LARGE_FLASH_HIGH High Security, Large-sized Boot Flash
**     BSS_HIGH_MEDIUM_BOOT_CODEHigh Security, Medium-sized Boot Flash
**     BSS_MEDIUM_FLASH_HIGHHigh Security, Medium-sized Boot Flash
**     BSS_HIGH_SMALL_BOOT_CODEHigh Security, Small-sized Boot Flash
**     BSS_SMALL_FLASH_HIGH High Security, Small-sized Boot Flash
**     BSS_STRD_LARGE_BOOT_CODEStandard Security, Large-sized Boot Flash
**     BSS_LARGE_FLASH_STD  Standard Security, Large-sized Boot Flash
**     BSS_STRD_MEDIUM_BOOT_CODEStandard Security, Medium-sized Boot Flash
**     BSS_MEDIUM_FLASH_STD Standard Security, Medium-sized Boot Flash
**     BSS_STRD_SMALL_BOOT_CODEStandard Security, Small-sized Boot Flash
**     BSS_SMALL_FLASH_STD  Standard Security, Small-sized Boot Flash
**     BSS_NO_BOOT_CODE     No Boot Segment
**     BSS_NO_FLASH         No Boot Segment Program Memory
**
*/

#define BWRP_WRPROTECT_ON    0xFFFE
#define BWRP_WRPROTECT_OFF   0xFFFF

#define BSS_HIGH_LARGE_BOOT_CODE 0xFFF1
#define BSS_LARGE_FLASH_HIGH 0xFFF1
#define BSS_HIGH_MEDIUM_BOOT_CODE 0xFFF3
#define BSS_MEDIUM_FLASH_HIGH 0xFFF3
#define BSS_HIGH_SMALL_BOOT_CODE 0xFFF5
#define BSS_SMALL_FLASH_HIGH 0xFFF5
#define BSS_STRD_LARGE_BOOT_CODE 0xFFF9
#define BSS_LARGE_FLASH_STD  0xFFF9
#define BSS_STRD_MEDIUM_BOOT_CODE 0xFFFB
#define BSS_MEDIUM_FLASH_STD 0xFFFB
#define BSS_STRD_SMALL_BOOT_CODE 0xFFFD
#define BSS_SMALL_FLASH_STD  0xFFFD
#define BSS_NO_BOOT_CODE     0xFFFF
#define BSS_NO_FLASH         0xFFFF

/* Register FGS (0xf80004)                               */

extern __attribute__((space(prog))) int _FGS;
#define _FGS(x) __attribute__((section("__FGS.sec"),space(prog))) int _FGS = (x);

/*
** Only one invocation of FGS should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set FGS.
** Multiple options may be combined, as shown:
**
** _FGS( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   General Code Segment Write Protect:
**     GWRP_ON              General Segment is write protected
**     GWRP_OFF             General Segment may be written
**
**   General Segment Code Protection:
**     GSS_HIGH             High Security Code Protection Enabled
**     GSS_STD              Standard Security Code Protection Enabled
**     GCP_ON               Standard Security Code Protection Enabled
**     GSS_OFF              User program memory is not code-protected
**     GCP_OFF              User program memory is not code-protected
**
*/

#define GWRP_ON              0xFFFE
#define GWRP_OFF             0xFFFF

#define GSS_HIGH             0xFFFB
#define GSS_STD              0xFFFD
#define GCP_ON               0xFFFD
#define GSS_OFF              0xFFFF
#define GCP_OFF              0xFFFF

/* Register FOSCSEL (0xf80006)                               */

extern __attribute__((space(prog))) int _FOSCSEL;
#define _FOSCSEL(x) __attribute__((section("__FOSCSEL.sec"),space(prog))) int _FOSCSEL = (x);

/*
** Only one invocation of FOSCSEL should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set FOSCSEL.
** Multiple options may be combined, as shown:
**
** _FOSCSEL( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   Oscillator Source Selection:
**     FNOSC_FRC            Internal Fast RC (FRC) oscillator
**     FNOSC_FRCPLL         Internal Fast RC (FRC) with PLL
**     FNOSC_PRI            Primary Oscillator (XT, HS, EC)
**     FNOSC_PRIPLL         Primary Oscillator (XT, HS, EC) with PLL
**     FNOSC_SOSC           Secondary Oscillator (SOSC)
**     FNOSC_LPRC           Low Power RC oscillator (LPRC)
**     FNOSC_FRCDIV16       Internal Fast RC (FRC) with divide by 16
**     FNOSC_FRCDIVN        Internal Fast RC (FRC) oscillator with postscaler
**
**   Internal External Switch Over Mode:
**     IESO_OFF             Start up device with user-selected oscillator source
**     IESO_ON              Start up device with FRC, then automatically switch to user-selected oscillator source
**
*/

#define FNOSC_FRC            0xFFF8
#define FNOSC_FRCPLL         0xFFF9
#define FNOSC_PRI            0xFFFA
#define FNOSC_PRIPLL         0xFFFB
#define FNOSC_SOSC           0xFFFC
#define FNOSC_LPRC           0xFFFD
#define FNOSC_FRCDIV16       0xFFFE
#define FNOSC_FRCDIVN        0xFFFF

#define IESO_OFF             0xFF7F
#define IESO_ON              0xFFFF

/* Register FOSC (0xf80008)                               */

extern __attribute__((space(prog))) int _FOSC;
#define _FOSC(x) __attribute__((section("__FOSC.sec"),space(prog))) int _FOSC = (x);

/*
** Only one invocation of FOSC should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set FOSC.
** Multiple options may be combined, as shown:
**
** _FOSC( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   Primary Oscillator Source:
**     POSCMD_EC            EC (External Clock) Mode
**     POSCMD_XT            XT Crystal Oscillator Mode
**     POSCMD_HS            HS Crystal Oscillator Mode
**     POSCMD_NONE          Primary oscillator disabled
**
**   OSC2 Pin Function:
**     OSCIOFNC_ON          OSC2 is general purpose digital I/O pin
**     OSCIOFNC_OFF         OSC2 is clock output
**
**   Peripheral Pin Select Configuration:
**     IOL1WAY_OFF          Allow multiple reconfigurations
**     IOL1WAY_ON           Allow only one reconfiguration
**
**   Clock Switching and Monitor:
**     FCKSM_CSECME         Clock switching and Fail-Safe Clock Monitor are enabled
**     FCKSM_CSECMD         Clock switching is enabled, Fail-Safe Clock Monitor is Disabled
**     FCKSM_CSDCMD         Clock switching and Fail-Safe Clock Monitor are disabled, Mon Disabled
**
*/

#define POSCMD_EC            0xFFFC
#define POSCMD_XT            0xFFFD
#define POSCMD_HS            0xFFFE
#define POSCMD_NONE          0xFFFF

#define OSCIOFNC_ON          0xFFFB
#define OSCIOFNC_OFF         0xFFFF

#define IOL1WAY_OFF          0xFFDF
#define IOL1WAY_ON           0xFFFF

#define FCKSM_CSECME         0xFF3F
#define FCKSM_CSECMD         0xFF7F
#define FCKSM_CSDCMD         0xFFBF

/* Register FWDT (0xf8000a)                               */

extern __attribute__((space(prog))) int _FWDT;
#define _FWDT(x) __attribute__((section("__FWDT.sec"),space(prog))) int _FWDT = (x);

/*
** Only one invocation of FWDT should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set FWDT.
** Multiple options may be combined, as shown:
**
** _FWDT( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   Watchdog Timer Postscaler:
**     WDTPOST_PS1          1:1
**     WDTPOST_PS2          1:2
**     WDTPOST_PS4          1:4
**     WDTPOST_PS8          1:8
**     WDTPOST_PS16         1:16
**     WDTPOST_PS32         1:32
**     WDTPOST_PS64         1:64
**     WDTPOST_PS128        1:128
**     WDTPOST_PS256        1:256
**     WDTPOST_PS512        1:512
**     WDTPOST_PS1024       1:1,024
**     WDTPOST_PS2048       1:2,048
**     WDTPOST_PS4096       1:4,096
**     WDTPOST_PS8192       1:8,192
**     WDTPOST_PS16384      1:16,384
**     WDTPOST_PS32768      1:32,768
**
**   WDT Prescaler:
**     WDTPRE_PR32          1:32
**     WDTPRE_PR128         1:128
**
**   Watchdog Timer Window:
**     WINDIS_ON            Watchdog Timer in Window mode
**     WINDIS_OFF           Watchdog Timer in Non-Window mode
**
**   Watchdog Timer Enable:
**     FWDTEN_OFF           Watchdog timer enabled/disabled by user software
**     FWDTEN_ON            Watchdog timer always enabled
**
*/

#define WDTPOST_PS1          0xFFF0
#define WDTPOST_PS2          0xFFF1
#define WDTPOST_PS4          0xFFF2
#define WDTPOST_PS8          0xFFF3
#define WDTPOST_PS16         0xFFF4
#define WDTPOST_PS32         0xFFF5
#define WDTPOST_PS64         0xFFF6
#define WDTPOST_PS128        0xFFF7
#define WDTPOST_PS256        0xFFF8
#define WDTPOST_PS512        0xFFF9
#define WDTPOST_PS1024       0xFFFA
#define WDTPOST_PS2048       0xFFFB
#define WDTPOST_PS4096       0xFFFC
#define WDTPOST_PS8192       0xFFFD
#define WDTPOST_PS16384      0xFFFE
#define WDTPOST_PS32768      0xFFFF

#define WDTPRE_PR32          0xFFEF
#define WDTPRE_PR128         0xFFFF

#define WINDIS_ON            0xFFBF
#define WINDIS_OFF           0xFFFF

#define FWDTEN_OFF           0xFF7F
#define FWDTEN_ON            0xFFFF

/* Register FPOR (0xf8000c)                               */

extern __attribute__((space(prog))) int _FPOR;
#define _FPOR(x) __attribute__((section("__FPOR.sec"),space(prog))) int _FPOR = (x);

/*
** Only one invocation of FPOR should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set FPOR.
** Multiple options may be combined, as shown:
**
** _FPOR( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   POR Timer Value:
**     FPWRT_PWR1           Disabled
**     FPWRT_PWR2           2ms
**     FPWRT_PWR4           4ms
**     FPWRT_PWR8           8ms
**     FPWRT_PWR16          16ms
**     FPWRT_PWR32          32ms
**     FPWRT_PWR64          64ms
**     FPWRT_PWR128         128ms
**
*/

#define FPWRT_PWR1           0xFFF8
#define FPWRT_PWR2           0xFFF9
#define FPWRT_PWR4           0xFFFA
#define FPWRT_PWR8           0xFFFB
#define FPWRT_PWR16          0xFFFC
#define FPWRT_PWR32          0xFFFD
#define FPWRT_PWR64          0xFFFE
#define FPWRT_PWR128         0xFFFF

/* Register FICD (0xf8000e)                               */

extern __attribute__((space(prog))) int _FICD;
#define _FICD(x) __attribute__((section("__FICD.sec"),space(prog))) int _FICD = (x);

/*
** Only one invocation of FICD should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set FICD.
** Multiple options may be combined, as shown:
**
** _FICD( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   Comm Channel Select:
**     ICS_NONE             Reserved, do not use
**     ICS_PGD3             Communicate on PGC3/EMUC3 and PGD3/EMUD3
**     ICS_PGD2             Communicate on PGC2/EMUC2 and PGD2/EMUD2
**     ICS_PGD1             Communicate on PGC1/EMUC1 and PGD1/EMUD1
**
**   JTAG Port Enable:
**     JTAGEN_OFF           JTAG is disabled
**     JTAGEN_ON            JTAG is enabled
**
*/

#define ICS_NONE             0xFFFC
#define ICS_PGD3             0xFFFD
#define ICS_PGD2             0xFFFE
#define ICS_PGD1             0xFFFF

#define JTAGEN_OFF           0xFFDF
#define JTAGEN_ON            0xFFFF

/* Register FUID0 (0xf80010)                               */

extern __attribute__((space(prog))) int _FUID0;
#define _FUID0(x) __attribute__((section("__FUID0.sec"),space(prog))) int _FUID0 = (x);

/*
** Only one invocation of FUID0 should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set FUID0.
** Multiple options may be combined, as shown:
**
** _FUID0( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   :
**
*/


/* Register FUID1 (0xf80012)                               */

extern __attribute__((space(prog))) int _FUID1;
#define _FUID1(x) __attribute__((section("__FUID1.sec"),space(prog))) int _FUID1 = (x);

/*
** Only one invocation of FUID1 should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set FUID1.
** Multiple options may be combined, as shown:
**
** _FUID1( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   :
**
*/



#endif
