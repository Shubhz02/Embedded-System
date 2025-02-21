#include<P18F4520.h>
void delay(void);
void main()
{
TRISD=0X00; 
TRISA=0X00;

PORTD=0X00;
//PORTA=0X03;
while(1)
{
int disp[11]={0XE7,0X21,0XCB,0X6B,0X2D,0X6E,0XEE,0X23,0XEF,0X6F,0X10};
int i;
//for(i=0;i<11;i++)
//{
PORTA=0x01;
PORTD=disp[9];
delay();
PORTA=0x02;
PORTD=disp[8];
delay();
//}
}
}
void delay(void)
{
int i,j;
for(i=0;i<3;i++)
{
for(j=0;j<498;j++)
{}
}
}