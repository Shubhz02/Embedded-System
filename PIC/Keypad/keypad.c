#include<P18F4520.h>

void main()
{
TRISB=0X1E;
TRISD=0X00;
TRISA=0X00;

PORTBbits.RB0=0; //LED OFF
INTCON2bits.RBPU=0;  //
ADCON1=0X0F;  //DIGITAL 1111


PORTD=0X00;
PORTA=0X01; //DISPLAY 1

while(1)
{
PORTBbits.RB5=0;  //...1ROW
PORTBbits.RB6=1;
PORTBbits.RB7=1;

if(PORTBbits.RB2==0)  //2ND COL
{
PORTBbits.RB0=1;  //LED ON
PORTD=0XE7;
}
PORTBbits.RB5=1;
PORTBbits.RB6=0;  //....2ND ROW
PORTBbits.RB7=1;

if(PORTBbits.RB3==0)  //3RD COL
{
PORTBbits.RB0=0;  //LED OFF
PORTD=0XEE;
}

}
}
