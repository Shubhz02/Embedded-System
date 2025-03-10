
  //Keypad interfacing with LPC2148(ARM7)
 

#include <lpc214x.h>
#include <stdint.h>

char keypad[4][4] = {{'1', '2', '3', '+'}, 
                     {'4', '5', '6', '-'}, 
                     {'7', '8', '9', '*'}, 
                     {'.', '0', '=', '/'}};

										 
void delay_ms(uint16_t j)
{
    uint16_t x,i;
	for(i=0;i<j;i++)
	{
    for(x=0; x<6000; x++);    /* loop to generate 1 milisecond delay with Cclk = 60MHz */
	}
}
void delay_us(uint16_t j)
{
    uint16_t x,i;
	for(i=0;i<j;i++)
	{
    for(x=0; x<6; x++);    /* loop to generate 1 milisecond delay with Cclk = 60MHz */
	}
}

void UART0_init(void)
{
	PINSEL0 = PINSEL0 | 0x00000005;	/* Enable UART0 Rx0 and Tx0 pins of UART0 */
	U0LCR = 0x83;	/* DLAB = 1, 1 stop bit, 8-bit character length */
	U0DLM = 0x00;	/* For baud rate of 9600 with Pclk = 15MHz */
	U0DLL = 0x61;	/* We get these values of U0DLL and U0DLM from formula */
	U0LCR = 0x03; /* DLAB = 0 */
}

void UART0_TxChar(char ch) /* A function to send a byte on UART0 */
{
	U0THR = ch;
	while( (U0LSR & 0x40) == 0 );	/* Wait till THRE bit becomes 1 which tells that transmission is completed */
}

void UART0_SendString(char* str) /* A function to send string on UART0 */
{
	uint8_t i = 0;
	while( str[i] != '\0' )
	{
		UART0_TxChar(str[i]);
		i++;
	}
}

unsigned char UART0_RxChar(void) /* A function to receive a byte on UART0 */
{
	while( (U0LSR & 0x01) == 0);	/* Wait till RDR bit becomes 1 which tells that receiver contains valid data */
		return U0RBR;
}


int main (void)
{
	/* P0.15-P0.12-->Rows(R3-R0)  P0.11-P0.8-->Columns(C3-C0)  */
	UART0_init();
	IO0DIR = 0x0000F000;
	delay_ms(5);
	int32_t col,row;
    while(1)
    {
		IO0PIN = (IO0PIN & 0xFFFF00FF) | 0x00000F00;
		delay_ms(5);
		while ((IO0PIN & 0x0000FF00) == 0x00000F00 )
		{

		}
		
		if( (IO0PIN & 0x00000F00) != 0x00000F00 )
		{
			delay_ms(50);
			if( (IO0PIN & 0x00000F00) != 0x00000F00 )
			{
				delay_ms(30);
				col = IO0PIN & 0x00000F00;
				
				while (1)
				{
					IO0PIN = (IO0PIN & 0xFFFF00FF) | 0x0000EF00;
					delay_ms(5);
					col = IO0PIN & 0x00000F00;
					delay_ms(1);
					
					if ((IO0PIN & 0x00000F00) != 0x00000F00 )
					{
						row = 0;
						break;
					}
					
					IO0PIN = (IO0PIN & 0xFFFF00FF) | 0x0000DF00;
					delay_ms(5);
					col = IO0PIN & 0x00000F00;
					delay_ms(1);
					if ( (IO0PIN & 0x00000F00) != 0x00000F00 )
					{
						row = 1;
						break;
					}
					
					IO0PIN = (IO0PIN & 0xFFFF00FF) | 0x0000BF00;
					delay_ms(5);
					col = IO0PIN & 0x00000F00;
					delay_ms(1);
					if ( (IO0PIN & 0x00000F00) != 0x00000F00 )
					{
						row = 2;
						break;
					}
					
					IO0PIN = (IO0PIN & 0xFFFF00FF) | 0x00007F00;
					delay_ms(5);
					col = IO0PIN & 0x00000F00;
					delay_ms(1);
					if ( (IO0PIN & 0x00000F00) != 0x00000F00 )
					{
						row = 3;
						break;
					}
					break;
				}
				char key;
				if ( col == 0x00000E00)
				{
					key = keypad[row][0];
				}
				
				else if ( col == 0x00000D00)
				{
					key = keypad[row][1];
				}
				
				else if ( col == 0x00000B00)
				{
					key = keypad[row][2];
				}
				
				else if ( col == 0x00000700)
				{
					key = keypad[row][3];
				}
				
				else continue;			
				UART0_SendString("Key pressed : ");
				UART0_TxChar(key);
				UART0_SendString("\r\n");
			}  				 
       }
   }
}
 