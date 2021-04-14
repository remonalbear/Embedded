/*
 * task1.c
 *
 * Created: 4/4/2021 12:51:04 AM
 * Author : remon
 */ 

#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>
#include "SEVENSEGMENT.h"
#include "BUTTON.h"

int main(void)
{
    /* Replace with your application code */
	BCD_SEVENSEGMENT_init('C');
	BCD_SEVENSEGMENT_init('D');
	BUTTON_init('A',0);
	unsigned char btn_value;
	int counter=0,first_7segement=0,second_7segement=0;
    while (1) 
    {
			btn_value=BUTTON_read('A',0);
			if(btn_value == 1){
				if(counter==100){
					counter=0;
				}
				first_7segement=counter%10;
				BCD_SEVENSEGMENT_write('C',first_7segement);
				second_7segement=counter/10;
				BCD_SEVENSEGMENT_write('D',second_7segement);
				counter++;
				_delay_ms(250);
			
			}
				
    }
}

