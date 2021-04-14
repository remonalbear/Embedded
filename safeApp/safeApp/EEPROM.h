/*
 * EEPROM.h
 *
 * Created: 4/11/2021 7:04:51 PM
 *  Author: remon
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

void EEPROM_write(unsigned short adress,unsigned char data);
unsigned char EEPROM_read(unsigned short adress);
void EEPROM_enable_interrupt();





#endif /* EEPROM_H_ */