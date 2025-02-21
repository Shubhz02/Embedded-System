#include<reg51.h>
void delay(void);

sbit led1=P2^2;
sbit led2=P2^3;
 
 
 void int0_isr(void) interrupt 0   //pin P3^2
 {
led1=1;
led2=0;
delay();
}



void int1_isr(void) interrupt 2   // pin P3^3
 {
led1=0;
led2=1;
delay();
}



void main()
{
  EA=1; //enable all

	
	 //priority check 
       PX1=1;  // priority INT1 High = 01
	    //PX0=1;  //priority INT0 HIgh = 10
	
	// interrupt INT
	EX0=1;   //INT0 bar enable  
  EX1=1;       //  external interrupt INT1 bar enable
	
	
	//trigering
  IT0=1;  // selecting trigger  -- edge triger 
	IT1=1; // external interrupt  -- edge triger
	
	                            //IT0=0;     // low triger
	                           //IT1=0;     // external intrrupt low level
	
led1=1; 
led2=1;

while(1)
{
led1=0;  
led2=0;
}
}


void delay(void)
{
int i,j;
for(i=0;i<500;i++)
{
for(j=0;j<500;j++)
{}
}
}
