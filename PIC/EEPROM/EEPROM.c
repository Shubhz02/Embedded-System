#include<P18F4520.h>
void EEPROM_write(unsigned char,unsigned char);

void main()
{
EEPROM_write(0X30,'S');
while(1);
}
void  EEPROM_write(unsigned char adr,unsigned char data)
{
EECON1bits.EEPGD=0; //acess data EEPROM 
EECON1bits.WREN=1;  //allow write to flash
EEADR=adr;
EEDATA=data;

INTCONbits.GIE=0; //interrupt disable
EECON2=0X55;
EECON2=0XAA;

EECON1bits.WR=1; //write

while(EECON1bits.WR==1);
EECON1bits.WREN=0; //inhibits write cycle to flash
INTCONbits.GIE=1; // intrrupt enable

}