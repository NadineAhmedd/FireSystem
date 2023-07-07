 #include<avr/io.h>
#include"common_macros.h"
#include"ADC.h"
/****************************************************************************************************************/
/*
 * FUNCTION DIFINTION
 */
/****************************************************************************************************************/
void ADC_init(const ADC_ConfigType * Config_Ptr)
{
	/*SELECT VOLT REFF*/
if(Config_Ptr->ref_volt==AREF)
{
	ADMUX&=(0X3F);
}
else if(Config_Ptr->ref_volt==VCC)
{
	ADMUX&=(0X3F);
	ADMUX|=(1<<REFS0);
}
else if(Config_Ptr->ref_volt==RESERVED)
{
	ADMUX&=(0X3F);
	ADMUX|=(1<<REFS1);
}
else if(Config_Ptr->ref_volt==INTERNAL)
{
	ADMUX&=(0X3F);
	ADMUX|=(1<<REFS1)|(1<<REFS0);
}
   /* SELECT PRESCALER*/
if(Config_Ptr->prescaler==PS128)
{
	ADCSRA&=~(0X07);
	ADCSRA|=(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);
}
else if(Config_Ptr->prescaler==PS64)
{
	ADCSRA&=~(0X07);
	ADCSRA|=(1<<ADPS1)|(1<<ADPS2);
}
else if(Config_Ptr->prescaler==PS32)
{
	ADCSRA&=~(0X07);
	ADCSRA|=(1<<ADPS0)|(1<<ADPS2);
}
else if(Config_Ptr->prescaler==PS16)
{
	ADCSRA&=~(0X07);
	ADCSRA|=(1<<ADPS2);
}
else if(Config_Ptr->prescaler==PS8)
{
	ADCSRA&=~(0X07);
	ADCSRA|=(1<<ADPS0)|(1<<ADPS1);
}
else if(Config_Ptr->prescaler==PS4)
{
	ADCSRA&=~(0X07);
	ADCSRA|=(1<<ADPS1);
}
else if(Config_Ptr->prescaler==PS2)
{
	ADCSRA&=~(0X07);
	ADCSRA|=(1<<ADPS0);
}
#ifdef inturrept
ADCSRA|=(1<<ADIE);//enable interrupt mode
SFIOR|=(1<<7);//enable global interrupt
#endif
ADCSRA |= (1<<ADEN);//enable ADC

}

uint16 ADC_readChannel(uint8 channal)
{
	channal&=(0x1f);
	ADMUX|=channal;
	SET_BIT(ADCSRA,ADSC);
#ifdef polling
	while(BIT_IS_CLEAR(ADCSRA,ADIF));
	SET_BIT(ADCSRA,ADIF);
#endif
	return ADC;
}
