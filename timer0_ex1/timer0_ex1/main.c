/*
 * timer0_ex1.c
 *
 * Created: 5/16/2021 2:27:39 PM
 * Author : remon
 */ 

#include <avr/io.h>
#define F_CPU 8000000
#include <avr/interrupt.h>
#include "TIMER.h"
#include "LED.h"
volatile unsigned char counter1=0;
volatile unsigned char counter2=0;
volatile unsigned short counter3=0;

int main(void)
{
    /* Replace with your application code */
	TIMER_init0_CTC_interrupt(80);
	TIMER_init_nonPWM(64);
	LED_init('A',0);
	LED_init('A',1);
	LED_init('A',2);
	SEVENSEGMENT_init('D');
	DIO_set_bit_dir('C',0,1);
	DIO_set_bit_dir('C',1,1);
	DIO_write_bit('C',0,1);
	SEVENSEGMENT_write('D',6);
    while (1) 
    {
		if(counter1>=100){
		LED_toggle('A',0);
		counter1=0;
		}
		if(counter2>=200){
			LED_toggle('A',1);
			counter2=0;
		}
		if(counter3>=300){
			LED_toggle('A',2);
			counter3=0;
		}
    }
}


ISR(TIMER0_COMP_vect){
	counter1++;
	counter2++;
	counter3++;
}
