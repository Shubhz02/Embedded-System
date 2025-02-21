#include<P18F4520.h>
void lcd_init(void);
void lcd_cmd(unsigned char);
void lcd_cmd1(unsigned char);
void lcd_data(unsigned char);
void delay_ms(int);
void lcd_string(unsigned char *P);

void main()
{
unsigned char str1[10]="hello";
unsigned char str2[10]="shubham";

lcd_init();
lcd_cmd(0X80);
lcd_string(str1);
 lcd_cmd(0XC0);
lcd_string(str2);

//lcd_data('H');
//lcd_data('i');

while(1)
{lcd_cmd(0X18);  //moving left
//lcd_cmd(0X1C);     //moving right
delay_ms(60);

}

}

void lcd_init(void)
{
TRISC=0X00;
TRISD=0X0F;
delay_ms(15);

lcd_cmd1(0X30);
delay_ms(15);
lcd_cmd1(0X30);
delay_ms(2);
lcd_cmd1(0X30);
delay_ms(4);

lcd_cmd1(0X20);

lcd_cmd(0X28);  //4bit
lcd_cmd(0X06);
lcd_cmd(0X01);
lcd_cmd(0X80);
lcd_cmd(0X0C);

}
void lcd_cmd(unsigned char c)
{
unsigned char c1=c;

PORTCbits.RC1=0;
PORTCbits.RC0=0;
PORTCbits.RC2=1;

PORTD=(0XF0 & c1);
delay_ms(5);
PORTCbits.RC2=0;
PORTCbits.RC2=1; //en
c=(0X0F & c);
c=c<<4;
PORTD=c;
PORTCbits.RC2=0;

}

void lcd_data(unsigned char d)
{
unsigned char d1=d;

PORTCbits.RC1=1;
PORTCbits.RC0=0;
PORTCbits.RC2=1;

PORTD=(0XF0 & d1);
delay_ms(5);
PORTCbits.RC2=0;
PORTCbits.RC2=1; //en
d=(0X0F & d);
d=d<<4;
PORTD=d;
PORTCbits.RC2=0;

}

void lcd_cmd1(unsigned char e)
{
PORTD=e;
PORTCbits.RC1=0;
PORTCbits.RC0=0;
PORTCbits.RC2=1;
delay_ms(5);
PORTCbits.RC2=0;
}

void delay_ms(int t)
{
int i,j;
for(i=0;i<t;i++)
{
for(j=0;j<498;j++)
{
}
}
}
void lcd_string(unsigned char *P)
{
int i;
for(i=0;P[i]!='\0';i++)
{
lcd_data(P[i]);
}
}