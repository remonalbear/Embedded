/*
 * temperature_sensor.c
 *
 * Created: 5/15/2021 8:36:14 PM
 * Author : remon
 */ 

#include <avr/io.h>
#define F_CPU 8000000
#include "ADC.h"
#include "LCD.h"

int main(void)
{
    /* Replace with your application code */
	LCD_init();
	ADC_init(0);
	unsigned short data=0;
	LCD_send_string("Temp=");
    while (1) 
    {
		data=(ADC_read() * .5);
		if(data<10)
		{
			LCD_move_cursor(1,6);
			LCD_send_char(0x30);
			LCD_send_char((data%10)+48);
			LCD_send_char(0xDF);
			LCD_send_char(0x43);
		}
		else if( data<100)
		{
			LCD_move_cursor(1,6);
			LCD_send_char((data/10)+48);
			LCD_send_char((data%10)+48);
			LCD_send_char(0XDF);
			LCD_send_char(0X43);
		}
		else
		{

		}

    }
}

