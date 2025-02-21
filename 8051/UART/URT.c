#include<reg51.h>
void delay(void);
void trans(unsigned char);

void main()
{
TMOD=0x20;    //auto reloader
SCON=0x50;   //8bit+start&stop bit
TH1=0xFD;  //baudrate 
TR1=1;
	while(1)
{
trans('A');
delay();
}
}

void trans(unsigned char C)
{
SBUF=C;
while(TI==0);
TI=0;
}

void delay(void)
{
int i,j;
for(i=0;i<500;i++)
{
for(j=0;j<500;j++)
{

}

}

}
