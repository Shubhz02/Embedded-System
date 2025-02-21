#include<reg51.h>
sbit led=P1^1;
sbit ir2=P1^3;
sbit ir=P0^1;

void main()
{
led=1; 	
while(1)
{
if(ir==1)
{
	led=1;
}
else if(ir2==1)
{
	led=0;
}
}
}