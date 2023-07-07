#ifndef ADC_H_
#define ADC_H_
/**********************************************
 * if it based on polling design define mode->>polling
 * if it based on interrupt define mode->>interrupt
 */
#define polling
/*****************************************/
#define ADC_MAXIMUM 1023
#define ADC_REF_VOLT 5
/************/
#include"std_types.h"

/********************/

enum voltReff{
	AREF,VCC,RESERVED,INTERNAL
}voltage;
/*******************/

typedef struct{
 enum voltReff ref_volt;
 uint8 prescaler;
}ADC_ConfigType;


void ADC_init(const ADC_ConfigType * Config_Ptr);
uint16 ADC_readChannel(uint8 channal);
/********************
 * to select division factor
 ********************/

#define PS128 128 //Division factor 128
#define PS64  64  //Division factor 64
#define PS32  32  //Division factor 32
#define PS16  16  //Division factor 16
#define PS8   8  //Division factor 8
#define PS4   4  //Division factor 4
#define PS2   2  //Division factor 2


#endif
