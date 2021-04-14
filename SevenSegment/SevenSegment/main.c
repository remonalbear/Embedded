/*
 * SevenSegment.c
 *
 * Created: 4/3/2021 6:00:09 PM
 * Author : remon
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include "SEVENSEGMENT.h"
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
	SEVENSEGMENT_init('C');
	BCD_SEVENSEGMENT_init('D');
	BUTTON_init('A',0);
	unsigned char btn;
	int i=0;
    while (1) 
    {
		btn = BUTTON_read('A',0);
		
		if(btn == 1){
			if (i==10)
			{
				i=0;
			}
			SEVENSEGMENT_write('C',i);
			BCD_SEVENSEGMENT_write('D',i);
			_delay_ms(250);
			i++;
		}

	}
	return 0;
}

