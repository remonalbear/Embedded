/*
 * LedButton.c
 *
 * Created: 4/3/2021 2:38:56 PM
 * Author : remon
 */ 

#include <avr/io.h>
#define F_CPU 8000000ul
#include "DIO.h"
#include "LED.h"
#include "BUTTON.h"
#include <util/delay.h>
int main(void)
{
    /* Replace with your application code */
	for (int i=0;i<8;i++){
	LED_init('A',i);
	}
	BUTTON_init('C',0);
	LED_init('C',1);
	unsigned char flag;
    while (1) 
    {
		for (int i=0;i<8;i++){
			flag=BUTTON_read('C',0);
			if(flag == 0){
				LED_on('C',1);
			}else{
				LED_off('C',1);
			}
			//while(flag!=1);
			LED_on('A',i);
			_delay_ms(1000);
		}
		for (int i=7;i>=0;i--){
			flag=BUTTON_read('C',0);
			if(flag == 0){
				LED_on('C',1);
			}else{
			LED_off('C',1);
		}
			//while(flag!=1);
			LED_off('A',i);
			_delay_ms(1000);
		}
    }
}

