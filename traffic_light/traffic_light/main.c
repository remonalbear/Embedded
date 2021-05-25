/*
 * traffic_light.c
 *
 * Created: 5/16/2021 5:10:15 PM
 * Author : remon
 */ 

#include <avr/io.h>
#define F_CPU 8000000
#include "LCD.h"
#include "LED.h"
#include "TIMER.h"
#include <avr/interrupt.h>
volatile unsigned char counter=0;
int main(void)
{
    /* Replace with your application code */
	TIMER_init0_CTC_interrupt(80);
	LCD_init();
	LED_init('D',0);
	LED_init('D',1);
	LED_init('D',2);

    while (1) 
    {
		unsigned char red_count=5;
		unsigned char green_count=8;
		unsigned char yellow_count=2;
		LED_off('D',0);
		LED_off('D',1);
		LED_off('D',2);
		
		LCD_clear();
		LCD_send_string("green:");
		LCD_move_cursor(1,8);
		LCD_send_char(green_count+48);	
		while(green_count>0){
			LED_on('D',0);		
			if(counter>=100){
				counter=0;
				green_count--;
				LCD_move_cursor(1,8);
				LCD_send_char(green_count+48);
			}	
		}
		LED_off('D',0);
		
		LCD_clear();
		LCD_send_string("yellow:");
		LCD_move_cursor(1,9);
		LCD_send_char(yellow_count+48);		
		while(yellow_count>0){
			LED_on('D',1);
			if(counter>=100){
				counter=0;
				yellow_count--;
				LCD_move_cursor(1,9);
				LCD_send_char(yellow_count+48);
			}
		}
		LED_off('D',1);
		
		LCD_clear();
		LCD_send_string("red:");
		LCD_move_cursor(1,5);
		LCD_send_char(red_count+48);
		while(red_count>0){
			LED_on('D',2);
			if(counter>=100){
				counter=0;
				red_count--;
				LCD_move_cursor(1,5);
				LCD_send_char(red_count+48);
			}
		}
		LED_off('D',2);
		
		
    }
}

ISR(TIMER0_COMP_vect){
	counter++;
}