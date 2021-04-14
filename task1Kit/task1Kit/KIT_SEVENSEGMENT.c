/*
 * KIT_SEVENSEGMENT.c
 *
 * Created: 4/4/2021 12:50:55 PM
 *  Author: remon
 */ 
#include "KIT_SEVENSEGMENT.h"
#include "DIO.h"
void KIT_SEVENSEGMENT_init(void){
	    DIO_set_bit_dir('B',0,1);
	    DIO_set_bit_dir('B',1,1);
	    DIO_set_bit_dir('B',2,1);
	    DIO_set_bit_dir('B',4,1);
	    DIO_set_bit_dir('B',5,1);
	    DIO_set_bit_dir('B',6,1);
	    DIO_set_bit_dir('A',2,1);
	    DIO_set_bit_dir('A',3,1);
}
void KIT_SEVENSEGMENT_write(unsigned char segment_number,unsigned char number){
	DIO_and_port('B',0xe8);
	int arr[]={0x00,0x01,0x02,0x03,0x04,0x05,
				0x06,0x07,0x10,0x11};
	switch(segment_number){
		case 1:
		DIO_write_bit('A',3,1);
		DIO_or_port('B',arr[number]);
		break;
		
		case 2:
		DIO_write_bit('A',2,1);
		DIO_or_port('B',arr[number]);
		break;
		
		case 3:
		DIO_write_bit('B',5,1);
		DIO_or_port('B',arr[number]);
		break;
		
		case 4:
		DIO_write_bit('B',6,1);
		DIO_or_port('B',arr[number]);
		break;
	}
}

void KIT_SEVENSEGMENT_off(unsigned char segment_number){
	switch(segment_number){
		case 1:
		DIO_write_bit('A',3,0);
		break;
		
		case 2:
		DIO_write_bit('A',2,0);
		break;
		
		case 3:
		DIO_write_bit('B',5,0);
		break;
		
		case 4:
		DIO_write_bit('B',6,0);
		break;
	}
}

void KIT_SEVENSEGMENT_on(unsigned char segment_number){
	switch(segment_number){
		case 1:
		DIO_write_bit('A',3,1);
		break;
		
		case 2:
		DIO_write_bit('A',2,1);
		break;
		
		case 3:
		DIO_write_bit('B',5,1);
		break;
		
		case 4:
		DIO_write_bit('B',6,1);
		break;
	}
}