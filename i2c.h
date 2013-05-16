void InitI2C(void);
char i2cWrite(unsigned char addr,unsigned char byte);
char i2cWriteStr(unsigned char addr,unsigned char *buf,unsigned char len);
char i2cRead(unsigned char addr, unsigned char *c);
char i2cReadStr(unsigned char addr,unsigned char *buf,unsigned char len);


