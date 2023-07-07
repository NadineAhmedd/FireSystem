#include"Buzzer.h"

void Buzzer_LED(void)
{
	/* set pins of Buzzer and LED as output pins */
	GPIO_setupPinDirection(Buzzer_PORT_ID, Buzzer_PIN3_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LED_PORT_ID, LED_PIN4_ID, PIN_OUTPUT);
	/*stop Buzzer and LED at first*/
	GPIO_writePin(Buzzer_PORT_ID, Buzzer_PIN3_ID, LOGIC_LOW);
	GPIO_writePin(LED_PORT_ID, LED_PIN4_ID, LOGIC_LOW);
}
void RUN (void){
	GPIO_writePin(Buzzer_PORT_ID, Buzzer_PIN3_ID, LOGIC_HIGH);
	GPIO_writePin(LED_PORT_ID, LED_PIN4_ID, LOGIC_HIGH);
}
void STOP (void){
	GPIO_writePin(Buzzer_PORT_ID, Buzzer_PIN3_ID, LOGIC_LOW);
	GPIO_writePin(LED_PORT_ID, LED_PIN4_ID, LOGIC_LOW);
}
