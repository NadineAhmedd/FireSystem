#include "lcd.h"
#include"Buzzer.h"
#include "UART.h"
#include "avr/io.h"

int main(void)
{
	Buzzer_LED();
	LCD_init();
	UART_init(9600);
	uint8 temp=0,past_Temp=0;
	while(1){
		temp = recieve ();
		if(temp!=past_Temp)
		{
			if(temp<60)
			{
				LCD_clearScreen();
				LCD_displayStringRowColumn(0,3,"FAN IS OFF");
				LCD_displayStringRowColumn(1,3,"Temp = ");
				LCD_intgerToString(temp);
				LCD_displayCharacter(0xDF);
				LCD_displayCharacter('C');
				STOP();
			}

			else if (temp==60)
			{
				LCD_clearScreen();
				LCD_displayStringRowColumn(0,2,"7are2aaaaaaaa");
				/*buzzer and LED*/
				RUN();
			}

			else
			{
				LCD_clearScreen();
				LCD_displayStringRowColumn(0,3,"FAN IS ON");
				LCD_displayStringRowColumn(1,2,"7are2aaaaaaaa");
				/*buzzer and LED*/
				RUN();
			}

		}
		past_Temp=temp;

	}
}
