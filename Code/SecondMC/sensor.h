#ifndef LM35_H_
#define LM35_H_


#include "ADC.h"
#include "std_types.h"



#define SENSOR_CHANNEL_ID   0
#define SENSOR_MAX_VOLT    1.5
#define SENSOR_MAX_TEMP    150


uint8 LM35_getTemp(ADC_ConfigType* ptr);


#endif /* LM35_H_ */
