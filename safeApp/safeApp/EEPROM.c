/*
 * EEPROM.c
 *
 * Created: 4/11/2021 7:04:36 PM
 *  Author: remon
 */ 

#include <avr/io.h>
#include "macros.h"


void EEPROM_write(unsigned short adress,unsigned char data){
	// writing the adress to low and high registers
	EEARL=(char)adress;
	EEARH=(char)adress>>8;
	// write the data to the data register
	EEDR=data;
	//set master write enable bit and write enable bit  
	SET_BIT(EECR,EEMWE);
	SET_BIT(EECR,EEWE);
	// loop until write enable bit to be cleared
	while(READ_BIT(EECR,EEWE)==1);
}
unsigned char EEPROM_read(unsigned short adress){
	// writing the adress to low and high registers
	EEARL=(char)adress;
	EEARH=(char)adress>>8;	
	// set read enable bit  
	SET_BIT(EECR,EERE);
	
	return EEDR;
}
void EEPROM_enable_interrupt(){
	SET_BIT(EECR,EERIE);
}
