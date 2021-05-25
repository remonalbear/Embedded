/*
 * timer0_ex2.c
 *
 * Created: 5/16/2021 3:37:17 PM
 * Author : remon
 */ 

#include <avr/io.h>
#define F_CPU 8000000
#include <avr/interrupt.h>
#include <util/delay.h>
#include "TIMER.h"
#include "SEVENSEGMENT.h"
volatile unsigned char counter=0;
volatile unsigned char temp_counter=0;
volatile unsigned char delay=0;
int main(void)
{
    /* Replace with your application code */
	TIMER_init0_CTC_interrupt(80);
	SEVENSEGMENT_init('A');
	DIO_set_bit_dir('B',0,1);
	DIO_set_bit_dir('B',1,1);

    while (1) 
    {
		DIO_write_bit('B',0,1);
		DIO_write_bit('B',1,1);
		
		DIO_write_bit('B',0,0);
		SEVENSEGMENT_write('A', counter/10);
		while(delay==0);
		delay=0;
		DIO_write_bit('B',0,1);
		DIO_write_bit('B',1,1);
		
		DIO_write_bit('B',1,0);
		SEVENSEGMENT_write('A', counter%10);
		while(delay==0);
		delay=0;	
		if (temp_counter>=100){
			temp_counter=0;
			counter++;
		}
		if (counter>99){
		counter=0;
		}
    }
}

ISR(TIMER0_COMP_vect){
	temp_counter++;
	delay+=1;
}