#include "sensor.h"
#include "ADC.h"

uint8 LM35_getTemp(ADC_ConfigType* ptr)
{
uint8 temp_value = 0;
uint16 adc_value = 0;
/* Read ADC channel where the temperature sensor is connected */
adc_value = ADC_readChannel(SENSOR_CHANNEL_ID);
/* Calculate the temperature from the ADC */
if (ptr->ref_volt==INTERNAL)
temp_value = (uint8)(((float)adc_value*SENSOR_MAX_TEMP*2.56)/(ADC_MAXIMUM*SENSOR_MAX_VOLT));
else if (ptr->ref_volt==AREF)
temp_value = (uint8)(((uint32)adc_value*SENSOR_MAX_TEMP*5)/(ADC_MAXIMUM*SENSOR_MAX_VOLT));
else if (ptr->ref_volt==VCC)
temp_value = (uint8)(((uint32)adc_value*SENSOR_MAX_TEMP*ADC_REF_VOLT)/(ADC_MAXIMUM*SENSOR_MAX_VOLT));
return temp_value;
}
