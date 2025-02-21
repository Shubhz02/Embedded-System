#include<reg51.h>
void delay(void);
void lcd_cmd(unsigned char);
void lcd_data(unsigned char);
void lcd_string(unsigned char *P);

#define dataport P2
sbit rs=P1^1;
sbit rw=P1^2;
sbit en=P1^3;

void main ()
{
lcd_cmd(0x38); //data 
lcd_cmd(0x0C);  //curser off
	                               //lcd_cmd(0x0E);  //curser on
                                // lcd_cmd(0x0F);  // curser blinking 
	
	                              //lcd_cmd(0x08);  //display off (clearing display whitout clear ddram content)
lcd_cmd(0x01);  //clear 
	
	
lcd_cmd(0x80); //line 1st
                               //lcd_cmd(0x86);  //1st line 6 postion
lcd_string("Shubham"); //data

lcd_cmd(0xC0); //line 2nd
                        	     //lcd_cmd(0xC6); //2nd line 6 postion
lcd_string("Shastri"); //data
	
	                            //while (1);   //stop
while(1) //active
	
	lcd_cmd(0x1C); //right shift
                               //lcd_cmd(0x18);   //right shift

}

void lcd_cmd(unsigned char c)
{
dataport=c;
rs=0;
rw=0;
en=1;
delay();
en=0;
}

void lcd_data(unsigned char d)
{
dataport=d;
rs=1;
rw=0;
en=1;
delay();
en=0;
}


void lcd_string(unsigned char *P)
{
  int i;
  for(i=0;P[i]!='\0';i++)
	{
    lcd_data(P[i]);
  }
}
void delay (void)
{
int i,j;
for(i=0;i<100;i++)
{
	for(j=0;j<500;j++)
	{
	}
}
}