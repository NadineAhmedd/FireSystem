#include"Dc_motor.h"

#include "ADC.h"

void DcMotor_Init(void)
{
	/* set pins of dc motor as output pins */
	GPIO_setupPinDirection(DcMotor_PORT_ID, DcMotor_PIN1_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(DcMotor_PORT_ID, DcMotor_PIN2_ID, PIN_OUTPUT);
	/*stop motor at first*/
	GPIO_writePin(DcMotor_PORT_ID, DcMotor_PIN1_ID, LOGIC_LOW);
	GPIO_writePin(DcMotor_PORT_ID, DcMotor_PIN2_ID, LOGIC_LOW);
}

void DcMotor_Rotate(DcMotorState state)
{
	/* Choose state for DC-motor */
	if(state == stop)
	{
		GPIO_writePin(DcMotor_PORT_ID, DcMotor_PIN1_ID, LOGIC_LOW);
		GPIO_writePin(DcMotor_PORT_ID, DcMotor_PIN2_ID, LOGIC_LOW);
	}
	else if (state == Clockwise)
	{
		GPIO_writePin(DcMotor_PORT_ID, DcMotor_PIN1_ID, LOGIC_HIGH);
		GPIO_writePin(DcMotor_PORT_ID, DcMotor_PIN2_ID, LOGIC_LOW);
	}
	else if (state==AntiClockwise)
	{
		GPIO_writePin(DcMotor_PORT_ID, DcMotor_PIN1_ID, LOGIC_LOW);
		GPIO_writePin(DcMotor_PORT_ID, DcMotor_PIN2_ID, LOGIC_HIGH);
	}
}
