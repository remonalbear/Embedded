/*
 * keyBad.c
 *
 * Created: 4/14/2021 4:37:19 PM
 * Author : remon
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "LCD.h"
#include "KEYPAD.h"
int main(void)
{
    LCD_init();
	KEYPAD_init();
	char ch;
    while (1) 
    {
		ch=KEYPAD_read();
		if(ch!=NOTPRESSED){
			if (ch =='A')
			{
				LCD_clear();
			}
			else
			{
				LCD_send_char(ch);	
			}
		_delay_ms(250);	
		}
		else{
			
		}
		
	}
return 0 ; 
}