#include<P18F4520.h>
void main()
{
unsigned int digit[10]={0XE7,0X21,0XCB,0X6B,0X2D,0X6E,0XEE,0X23,0XEF,0X6F};
unsigned int i=0,j=0,k=0,l=0;  //stating 0

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

PORTD=digit[l];  //array l
PORTAbits.RA0=0;
PORTAbits.RA1=0;  
PORTAbits.RA2=1; //3 display active
PORTAbits.RA3=0;

k++;   //counter

if(k>50000)  //counter
{
l++;   //l inc  
k=0;   // k reset 0   
}
if(l==10)  
{
j++;   //j inc  
l=0;   //l reset 
k=0;   //k reset  

if(j==10)  
{
i++;   //i inc  
j=0;   //j reset 
k=0;   //k reset

if(i==10)  
{
i=0;      ///reset
j=0;
l=0;
k=0;

}
}
}
}
}