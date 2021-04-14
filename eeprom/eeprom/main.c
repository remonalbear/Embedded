/*
 * eeprom.c
 *
 * Created: 4/11/2021 7:03:22 PM
 * Author : remon
 */ 

#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>
#include <avr/interrupt.h>
#include "EEPROM.h"
#include "LED.h"
#include "macros.h"
int main(void)
{
    /* Replace with your application code */
	
	EEPROM_enable_interrupt();
	LED_init('A',0);
	sei();
	EEPROM_write(0x0030,0x50);	
    while (1) 
    {
		LED_off('A',0);
    }
}

ISR(EE_RDY_vect){
	LED_on('A',0);
	_delay_ms(2000);
	CLR_BIT(EECR,EERIE);
}
