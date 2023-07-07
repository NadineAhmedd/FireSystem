#ifndef Buzzer_H_
#define Buzzer_H_

#include "std_types.h"
#include"gpio.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define Buzzer_PORT_ID      PORTB_ID
#define LED_PORT_ID         PORTB_ID
#define Buzzer_PIN3_ID      PIN1_ID
#define LED_PIN4_ID         PIN0_ID
void Buzzer_LED(void);
void RUN (void);
void STOP(void);

#endif /* Buzzer_H_ */
