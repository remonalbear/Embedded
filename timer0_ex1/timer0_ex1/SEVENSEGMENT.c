/*
 * SEVENSEGMENT.c
 *
 * Created: 4/3/2021 6:00:50 PM
 *  Author: remon
 */ 

#include "DIO.h"
void SEVENSEGMENT_init(unsigned char port ){
	DIO_set_port_dir(port,1);
}
void SEVENSEGMENT_write(unsigned char port ,unsigned char number){
	unsigned char arr[]={ 0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x47,0x7f,0x6f};
	DIO_write_port(port,arr[number]);

}

void BCD_SEVENSEGMENT_init(unsigned char port ){
	for (int i=0;i<4;i++){
		DIO_set_bit_dir(port,i,1);	
	}
	
}
void BCD_SEVENSEGMENT_write(unsigned char port ,unsigned char number){
	DIO_write_low_nibble(port,number);
}