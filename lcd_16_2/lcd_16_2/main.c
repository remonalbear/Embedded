/*
 * lcd_16_2.c
 *
 * Created: 4/13/2021 6:30:52 PM
 * Author : remon
 */ 


#define F_CPU 8000000UL
#include <util/delay.h>
#include "LCD.h"
#include "INTERRUPT.h"
#include "LCD.h"
#include "BUTTON.h"
int counter=0;
int main(void)
{
    BUTTON_init('D',0);
	BUTTON_init('D',2);
	LED_init('D',1);
	LED_on('D',1);
	_delay_ms(500);
	char cursor=11;
	unsigned char btn;
	LCD_init();
	LCD_send_string("counter = ");
	while (1) 
    {
	btn=BUTTON_read('D',0);
	if(btn==1){
		LED_on('D',1);
		if(counter<99){
			counter++;
		}
		else
		{
			counter=0;
		}
		_delay_ms(250);	
	}
	else{
		LED_off('D',1);
	}
	LCD_move_cursor(1,cursor+1);
	LCD_send_char(48+(counter%10));
	LCD_move_cursor(1,cursor);
	LCD_send_char(48+(counter/10));

	
    }
}

