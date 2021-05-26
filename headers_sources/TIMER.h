/*
 * TIMER.h
 *
 * Created: 5/16/2021 2:29:07 PM
 *  Author: remon
 */ 


#ifndef TIMER_H_
#define TIMER_H_

void TIMER_init0_CTC_interrupt(unsigned char value);
void TIMER_init0_nonPWM(unsigned char value);
void TIMER_init0_PWM(unsigned char value);




#endif /* TIMER_H_ */