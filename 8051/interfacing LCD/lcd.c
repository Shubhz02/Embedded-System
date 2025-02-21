#include<reg51.h>
void trans(unsigned char);
void delay(void);
void main();
{
	TMOD= 0x20;
	SCON=0x50;
	TH1= 0xFD;
	TE1=1;
	while(1)
	{
		trans('A');
		delay();
	}
}
void trans(unsigned char c);
{
	SBUF=c;
	while(TI==0);
	TI=0;
}
void delay()
{
	int i,j;
	for(i=0;i<500;i++)
	for(j=0;j<500;j++);
}

{
	for(j=0;j<500;j++)
	{
	}
}
}