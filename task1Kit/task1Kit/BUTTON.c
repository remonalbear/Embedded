/*
 * BUTTON.c
 *
 * Created: 4/3/2021 3:01:57 PM
 *  Author: remon
 */ 
#include "DIO.h"

void BUTTON_init(unsigned char port , unsigned char pin){
	DIO_set_bit_dir(port,pin,0);
}
unsigned char BUTTON_read(unsigned char port , unsigned char pin){
	unsigned char value;
	value=DIO_read_bit(port,pin);
	return value;
}