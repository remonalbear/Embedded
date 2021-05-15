/*
 * ADC.c
 *
 * Created: 5/15/2021 6:14:37 PM
 *  Author: remon
 */ 
#include <avr/io.h>
#include "macros.h"
void ADC_init(unsigned char pin){
	ADMUX =pin; //choose adc pin
	SET_BIT(ADMUX,REFS0); // configure VREF
	CLR_BIT(ADMUX,REFS1);
	CLR_BIT(ADMUX,ADLAR); // configure data representation
	SET_BIT(ADCSRA,ADEN); //enable adc 
	//adjust clock
	SET_BIT(ADCSRA,ADPS2);
	SET_BIT(ADCSRA,ADPS1);
	CLR_BIT(ADCSRA,ADPS0);
}
unsigned short ADC_read(void){
	unsigned short data=0;
	
	SET_BIT(ADCSRA,ADSC);
	while(!READ_BIT(ADCSRA,ADIF));
	SET_BIT(ADCSRA,ADIF);
	data=ADCL;
	data |= (ADCH<<8);
	return data;
}