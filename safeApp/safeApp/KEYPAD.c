/*
 * KEYPAD.c
 *
 * Created: 4/14/2021 4:51:46 PM
 *  Author: remon
 */ 
#include "KEYPAD.h"
#include "DIO.h"

void KEYPAD_init(){
DIO_set_bit_dir(PORT,0,1);
DIO_set_bit_dir(PORT,1,1);
DIO_set_bit_dir(PORT,2,1);
DIO_set_bit_dir(PORT,3,1);
DIO_set_bit_dir(PORT,4,0);
DIO_set_bit_dir(PORT,5,0);
DIO_set_bit_dir(PORT,6,0);
DIO_set_bit_dir(PORT,7,0);	
DIO_connect_pullup(PORT,4,1);
DIO_connect_pullup(PORT,5,1);
DIO_connect_pullup(PORT,6,1);
DIO_connect_pullup(PORT,7,1);
	
}
char KEYPAD_read(){
	char arr[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}};
	char col,row,x;
	char returnValue= NOTPRESSED;
	for(row=0;row<4;row++){
		DIO_write_bit(PORT,0,1);
		DIO_write_bit(PORT,1,1);
		DIO_write_bit(PORT,2,1);
		DIO_write_bit(PORT,3,1);
		DIO_write_bit(PORT,row,0);
		for(col=0;col<4;col++){
			x=DIO_read_bit(PORT,col+4);
			if(x==0){
				returnValue=arr[row][col];
				break;
			}
		}
		if(x==0){
			break;
		}		
	}
	return returnValue;
}