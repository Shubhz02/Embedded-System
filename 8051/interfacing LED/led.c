#include<reg51.h>

sbit led1= P1^2;
sbit led2= P0^3;
void delay(void);
void main()
{
led1=1;
led2=1;
while(1)
{
led1=1;
	led2=0;
	delay();
led1=0;
	led2=1;
	delay();
}
}
void delay(void)
{
int i,j;
for(i=0;i<100;i++)
{
for(j=0;j<500;j++)
{
}
}
}