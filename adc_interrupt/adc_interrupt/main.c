/*
 * adc_interrupt.c
 *
 * Created: 5/15/2021 9:23:20 PM
 * Author : remon
 */ 

#include <avr/io.h>
#define F_CPU 8000000
#include "ADC.h"
#include "LED.h"
#include <avr/interrupt.h>
#include <util/delay.h>
#include "macros.h"
int main(void)
{
    /* Replace with your application code */
	ADC_init(0);
	LED_init('D',0);
	LED_init('D',1);
	sei();
	SET_BIT(ADCSRA,ADIE);
    while (1) 
    {
	SET_BIT(ADCSRA,ADSC);
	_delay_ms(1);
	DIO_write_port('D',2);
	_delay_ms(1000);	
    }
}

ISR(ADC_vect){
	DIO_write_port('D',1);
	_delay_ms(1000);
}