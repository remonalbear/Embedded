/*
 * LED.c
 *
 * Created: 4/3/2021 2:40:36 PM
 *  Author: remon
 */
#include "DIO.h" 

void LED_init(unsigned char port , unsigned char pin){
	DIO_set_bit_dir(port,pin,1);
}
void LED_on(unsigned char port , unsigned char pin){
	DIO_write_bit(port,pin,1);
}
void LED_off(unsigned char port , unsigned char pin){
	DIO_write_bit(port,pin,0);
}
void LED_toggle(unsigned char port , unsigned char pin){
	DIO_toggle_bit(port,pin);
}