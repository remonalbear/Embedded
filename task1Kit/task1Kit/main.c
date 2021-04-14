/*
 * task1Kit.c
 *
 * Created: 4/4/2021 12:07:51 PM
 * Author : remon
 */ 

#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>
#include <avr/interrupt.h>
#include "KIT_SEVENSEGMENT.h"
#include "BUTTON.h"
#include "INTERRUPT.h"
#include "macros.h"
int counter=0;
int main(void)
{
	
	KIT_SEVENSEGMENT_init(); //initialize the pins used for the 7 segments to be output pins
	BUTTON_init('A',0); // initialize button in port A pin 0
	BUTTON_init('D',2); // initialize button in port D pin 2 to be Interrupt button
	GLOBAL_interrupt_enable();// enable global Interrupt  
	EXTERNAL_INT0_init(4); //enable external interrupt 0 with failing edge trigger
	counter=0; //restart the counter

	unsigned char btn_value;//reading of button
	int tens_counter=0,ones_counter=0; // counters
	while (1) 
    {	
		btn_value=BUTTON_read('A',0); //read button
		if(btn_value == 1){ //check if it is presses
			if(counter == 100){ // check the edge condition
				counter=0; //reset the counter
			}
			_delay_ms(200); // delay to avoid multiple trigger
			counter++; // increment counter
			
		}
		ones_counter=counter%10; // the low digit counter
		tens_counter=counter/10; //the high digit counter
		KIT_SEVENSEGMENT_on(4); // enable the fourth segment
		KIT_SEVENSEGMENT_write(4,ones_counter); // writing the low digit 
		_delay_ms(2); 
		KIT_SEVENSEGMENT_off(4);// disable the fourth segment
		KIT_SEVENSEGMENT_on(3);// enable the third segment
		KIT_SEVENSEGMENT_write(3,tens_counter);// writing the high digit 
		_delay_ms(2);
		KIT_SEVENSEGMENT_off(3);// disable the third segment
	
    }
}

ISR(INT0_vect){
	if(counter == 100){ // check the edge condition
		counter=0; //reset the counter
	}else{
	counter++;	
	}
	
}
