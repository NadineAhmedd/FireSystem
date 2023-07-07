#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"
#include"gpio.h"

/*******************************************************************************
 *                              Function Prototypes                            *
 *******************************************************************************/
#define DcMotor_PORT_ID PORTB_ID
#define DcMotor_PIN1_ID PIN5_ID
#define DcMotor_PIN2_ID PIN6_ID


typedef enum {
	stop,Clockwise,AntiClockwise
}DcMotorState;


void DcMotor_Init(void);

void DcMotor_Rotate(DcMotorState state);


#endif /* DC_MOTOR_H_ */
