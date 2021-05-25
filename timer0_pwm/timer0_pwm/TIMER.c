/*
 * TIMER.c
 *
 * Created: 5/16/2021 2:28:55 PM
 *  Author: remon
 */ 
#include "macros.h"
#include <avr/io.h>
#include <avr/interrupt.h>

void TIMER_init0_CTC_interrupt(unsigned char value){
	//select mode
	SET_BIT(TCCR0,WGM01);
	CLR_BIT(TCCR0,WGM00);
	//enable global interrupt
	sei();
	//define clock(prescaler)
	SET_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);
	//compare value
	OCR0=value;
	//enable compare interrupt
	SET_BIT(TIMSK,OCIE0);
}

void TIMER_init0_nonPWM(unsigned char value){
	SET_BIT(DDRB,3);
	//select mode
	SET_BIT(TCCR0,WGM01);
	CLR_BIT(TCCR0,WGM00);
	//compare value
	OCR0=value;
	//define clock(pre scalar)
	SET_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);
	//toggle OC0
	SET_BIT(TCCR0,COM00);
	CLR_BIT(TCCR0,COM01);
}

void TIMER_init0_PWM(unsigned char value){
	SET_BIT(DDRB,3);
	//select mode
	SET_BIT(TCCR0,WGM01);
	SET_BIT(TCCR0,WGM00);
	//compare value
	OCR0=value;
	//define clock(pre scalar)
	SET_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);
	//set OC0 on compare match ,clear at bottom (inverting mode)
	//SET_BIT(TCCR0,COM00);
	//SET_BIT(TCCR0,COM01);
	//clear OC0 on compare match ,set at bottom (non-inverting mode)
	SET_BIT(TCCR0,COM01);
}