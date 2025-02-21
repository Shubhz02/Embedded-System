#include<P18F4520.h>
void main()
{
TRISD=0X00;  //O/P DIRENTN
TRISA=0X00;  //O/P DIRECTN

while(1)
{
PORTD=0X21;          //1 DISPLAY
PORTAbits.RA0=1;     //R0 ACTIVE
PORTAbits.RA1=0;
PORTAbits.RA2=0;
PORTAbits.RA3=0;

PORTD=0XCB;          //2 DISPLAY
PORTAbits.RA0=0;
PORTAbits.RA1=1;     //R1  ACTIVE
PORTAbits.RA2=0;
PORTAbits.RA3=0;
}
}