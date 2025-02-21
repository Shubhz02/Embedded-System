#include<reg51.h>
void delay (void);
int pass[4];
int ori[4]={5,6,7,8};


sbit led=P0^1; // for led
sbit led2=P0^2; // for led

sbit r0=P2^0;  //port P2
sbit r1=P2^1;
sbit r2=P2^2;
sbit r3=P2^3;
sbit c0=P2^4;
sbit c1=P2^5;
sbit c2=P2^6;
sbit c3=P2^7;

void main()
{
	int i;
led= 1;  // led off
	led2=1;
while(1)
{
	i=0;
	while(i<4)
	{
r0=0;    //row 0............................
r1=r2=r3=1;
if(c0==0)  // col 0
{
pass[i]=1;
	i++;
	delay();
}
if(c1==0)  // col 1
{
pass[i]=2;
		i++;
	delay();
}

if(c2==0)  // col 2 
{
pass[i]=3;
		i++;
	delay();
}

r1=0;    //row 1.......................
r0=r2=r3=1;
if(c0==0)  // col 0
{
pass[i]=4;
	i++;
	delay();
}
if(c1==0)  // col 1
{
pass[i]=5;
	i++;
	delay();
}

if(c2==0)  // col 2 
{
pass[i]=6;
	i++;
	delay();
}
r2=0;    //row 2.......................
r0=r1=r3=1;
if(c0==0)  // col 0
{
pass[i]=7;
	i++;
	delay();
}
if(c1==0)  // col 1
{
pass[i]=8;
	i++;
	delay();
}

if(c2==0)  // col 2 
{
pass[i]=9;
	i++;
	delay();
}
r3=0;    //row 3.......................
r0=r2=r1=1;
if(c1==0)  // col 0
{
pass[i]=0;
	i++;
	delay();
} 

} //........................................................................ while loop closed

if((pass[0]=ori[0])&&(pass[1]=ori[1])&&(pass[2]=ori[2])&&(pass[3]=ori[3]))
	
{
led =0;
	led2=1;
	
}
else
{
led =1;
	led2=0;
}


}
}


void delay(void)
{
int i,j;
for(i=0;i<100;i++)
{for(j=0;j<500;j++)
{}
}
}