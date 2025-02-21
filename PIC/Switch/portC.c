#include<P18f4520.h>
void delay(int);

void main()
{
TRISC=0x00;
PORTC=0x00;

while(1)
{
PORTC=0x01;
delay(1000);
}
}

void delay(int t)
{
int i,j;
for(i=0;i<t;i++)
{
for(j=0;j<498;j++)
{}
}
}