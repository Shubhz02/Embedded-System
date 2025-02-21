#include<P18F4520.h>
void lcd_init(void);
void lcd_cmd(unsigned char);
void lcd_data(unsigned char);
void delay_ms(int);


void main()
{
lcd_init();

lcd_data('H');
lcd_data('E');
lcd_data('L');
lcd_data('L');
lcd_data('O');

while(1)
{
lcd_cmd(0X1c);  //shift
delay_ms(60);
}

}

void lcd_init(void)
{
TRISD=0X00;
TRISC=0X00;

delay_ms(15);

lcd_cmd(0X30);
delay_ms(5);

lcd_cmd(0X30);
delay_ms(2);

lcd_cmd(0X30);  //5*7 lots pixel
delay_ms(3);

lcd_cmd(0X38);  //8bit 2 line
lcd_cmd(0X01);  //clear
lcd_cmd(0X06);  //entry mode
lcd_cmd(0X80);  //1st line
//lcd_cmd(0XC5);  //2nd line 5th position start
lcd_cmd(0X0C); //display on curser off
lcd_cmd(0X0F);  //curser blink
//lcd_cmd(0X0E);   //curser on
//lcd_cmd(0X1C);   //right shift

}

void lcd_cmd(unsigned char c)
{
PORTD=c;

PORTCbits.RC1=0;   //rs  command =0
PORTCbits.RC0=0;   //rw  write=0
PORTCbits.RC2=1;  //en
delay_ms(4);
PORTCbits.RC2=0;
}

void lcd_data(unsigned char d)
{
PORTD=d;

PORTCbits.RC1=1;   //rs  data=1
PORTCbits.RC0=0;   //rw  write=0
PORTCbits.RC2=1;  //en
delay_ms(4);
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

