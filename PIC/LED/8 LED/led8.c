#include<P18F4520.h>
void delay(int);
void main()
{
int i;
TRISB=0X00;   //direction output
PORTB=0X00;  //port selection   ===led o/p
while(1)
{
for(i=0;i<8;i++)
{
PORTB=3<<i;
delay(1000);
i++;
}
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