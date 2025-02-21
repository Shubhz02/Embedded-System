#include<reg51.h>

sbit led1= P0^1;
sbit led2= P0^2;
//void delay(void);
void delay(int);
void main()
{
led1=1;  //led 0ff
led2=1;  //led off
while(1)
{
led1=1; //off
	led2=0;  //on2
	//delay();
	delay(1000);
	
led1=0; //on1
	led2=1;  //off
	//delay();
	delay(10);
}
}
  //void delay(void)  ///// .........................................50 MSEC
  //{
  // TMOD=0X01;   
//	TH0=0X4B;
	//TL0=0XFD;
	//TR0=1;   //RUN  START
	//	while (TF0==0);  //NOT OVERFLOW
  // TR0=0;   // STOP
	//TF0=0;  //NOT OVERFLOW FOR NEXT DELAY
//}

  ///void delay(void)   /// ..........................................1 sec
 //{
 //int i;
//for(i=0;i<1000;i++)
//{TMOD=0X01;
//TH0=0XFC;
//TL0=0X66;
//TR0=1;
//while(TF0==0);
//TR0=0;
//TF0=0;
 //}}
 
 
 void delay(int t)
 {
int i;
for(i=0;i<t;i++)
	 {
TMOD=0X01;  
TH0=0XFC;
TL0=0X66;
TR0=1;    //start
while(TF0==0); //eqaual not overflow
TR0=0;  //stop
TF0=0;  //reset overflow
}
}
