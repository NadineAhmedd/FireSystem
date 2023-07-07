#include "ADC.h"
#include "DC_motor.h"
#include "sensor.h"
#include "UART.h"

int main(void)
{

	DcMotor_Init();
	DcMotor_Rotate(stop);
	ADC_ConfigType ADC;
	ADC.prescaler=PS128;
	ADC.ref_volt=INTERNAL;
	ADC_init(&ADC);
	uint8 temp=0,past_Temp=0;
	while(1){
		temp = LM35_getTemp(&ADC);

		if(temp!=past_Temp)
		{
			transmit(temp, past_Temp);
			if(temp<60)
			{

				DcMotor_Rotate(stop);

			}

			else if (temp==60)
			{

				DcMotor_Rotate(Clockwise);

			}

			else
			{

				DcMotor_Rotate(AntiClockwise);

			}


		}
		past_Temp=temp;

	}
}
