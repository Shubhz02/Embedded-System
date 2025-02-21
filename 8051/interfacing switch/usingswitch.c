#include<reg51.h>
sbit led=P1^1;
sbit sw2=P1^3;
sbit sw=P0^1;

void main()
{
led=1; 	
while(1)
{
if(sw==0)
{
	led=0;
}
else if(sw2==0)
{
	led=1;
}
}
}