#include<P18F4520.h>
void main()
{
 unsigned int digit[10]={0XE7,0X21,0XCB,0X6B,0X2D,0X6E,0XEE,0X23,0XEF,0X6F};
 unsigned int i=9,j=9,k=0;  //stating 99

TRISD=0X00; //op dirn D
TRISA=0X00; //op dirn A


while(1)
{

PORTD=digit[i];  //array i
PORTAbits.RA0=1;   // 1 display active
PORTAbits.RA1=0;
PORTAbits.RA2=0;
PORTAbits.RA3=0;

PORTD=digit[j];  //array j
PORTAbits.RA0=0;
PORTAbits.RA1=1;  //2 display active
PORTAbits.RA2=0;
PORTAbits.RA3=0;

k++;   //counter

if(k>50000)  //counter
{
j--;   //j decr   
k=0;   // k reset 0   
}
if(j==-1)   // 8 
{
i--;   //i decr  
j=9;   //j reset 
k=0;   //k reset  

if(i==-1)  
{
i=9;      ///reset
j=9;
k=0;

}
}
}
}
