/*
 * KEYPAD.h
 *
 * Created: 4/14/2021 4:52:25 PM
 *  Author: remon
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#define PORT 'D'
#define NOTPRESSED 0xff
void KEYPAD_init();
char KEYPAD_read();




#endif /* KEYPAD_H_ */