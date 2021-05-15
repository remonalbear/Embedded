/*
 * adc.c
 *
 * Created: 5/15/2021 6:13:25 PM
 * Author : remon
 */ 

#include <avr/io.h>
#define  F_CPU 8000000
#include "ADC.h"
#include "LED.h"

int main(void)
{
    /* Replace with your application code */
    ADC_init(1);
	int i;
	for (i =0 ; i<8; i++){
	LED_init('D',i);
	}
	while (1) 
    {
		PORTD=ADC_read();
    }
}

