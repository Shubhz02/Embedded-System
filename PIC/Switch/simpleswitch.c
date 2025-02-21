#include<P18F4520.h>

void main()
{
TRISC=0x01;   //direction of switch is input
TRISB=0x00;  // direction of led is output
PORTB=0x00;  //INITIALIZE OFF

while(1)
{
if((PORTC&0x01)==0)
{
PORTB=0x01;
}
else
{
PORTB=0x00;
}
}
}