/*
 * DIO.c
 *
 * Created: 4/3/2021 10:59:28 AM
 * Author : remon
 */ 


#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>
#include "DIO.h"

int main(void)
{
    /* Replace with your application code */
	DIO_set_port_dir('A',1);
	DIO_set_port_dir('C',0);
    while (1) 
    {
		unsigned char test_port,test_pin;
		DIO_write_port('A',0xff);
		_delay_ms(1000);
		DIO_write_port('A',0x00);
		_delay_ms(1000);
		test_port=DIO_read_port('C');
		if(test_port==2){
			DIO_toggle_bit('A',3);
			_delay_ms(1000);	
		}
		test_pin=DIO_read_bit('C',7);
		if(test_pin==1){
			DIO_toggle_bit('A',1);
			_delay_ms(1000);
		}	

		
    }
}

