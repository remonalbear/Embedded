/*
 * LED.h
 *
 * Created: 4/3/2021 2:40:23 PM
 *  Author: remon
 */ 


#ifndef LED_H_
#define LED_H_

void LED_init(unsigned char port , unsigned char pin);
void LED_on(unsigned char port , unsigned char pin);
void LED_off(unsigned char port , unsigned char pin);
void LED_toggle(unsigned char port , unsigned char pin);



#endif /* LED_H_ */