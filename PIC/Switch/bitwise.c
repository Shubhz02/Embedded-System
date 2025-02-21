#include<P18F4520.h>
void main()
{
TRISC=0X0f;   //   I/P
TRISB=0X00;  //   O/P
PORTB=0X00;

while(1)
{
if((PORTC&0X01)==0)  //switch press 
{
PORTB=0X01;
}
if((PORTC&0X08)==0)
{
PORTB=0X00;
}
}
}

