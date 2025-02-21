#include<P18F4520.h>
void delay(int);
void main()
{
TRISB=0X00;   //direction
PORTB=0X00;  //port selection
while(1)
{
PORTBbits.RB0=1;
delay(1000);
PORTBbits.RB3=1;
delay(1000);
}
}
void delay(int t)
{
int i,j;
for(i=0;i<t;i++)
{for(j=0;j<498;j++)
{}
}
}