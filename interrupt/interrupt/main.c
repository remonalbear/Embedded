/*
 * interrupt.c
 *
 * Created: 4/8/2021 8:52:39 PM
 * Author : remon
 */ 

#include <avr/io.h>
#define F_CPU 8000000ul
#include <avr/interrupt.h>
#include <util/delay.h>
#include "LED.h"
#include "BUTTON.h"
#include "macros.h"
int main(void)
{
    /* Replace with your application code */
	LED_init('A',0);
	LED_init('A',1);
	LED_init('A',2);
	sei();
	SET_BIT(GICR,INT0);
	SET_BIT(GICR,INT1);
	SET_BIT(GICR,INT2);
	
	SET_BIT(MCUCR,ISC00);
	SET_BIT(MCUCR,ISC01);
	
	SET_BIT(MCUCR,ISC10);
	SET_BIT(MCUCR,ISC11);
	
	SET_BIT(MCUCSR,ISC2);
	
    while (1) 
    {
		LED_off('A',0);
		LED_off('A',1);
		LED_off('A',2);
    }
	
}
ISR(INT0_vect){
	LED_on('A',0);
	_delay_ms(1000);
}

ISR(INT1_vect){
	LED_on('A',1);
	_delay_ms(1000);
}

ISR(INT2_vect){
	LED_on('A',2);
	_delay_ms(1000);
}
