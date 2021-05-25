/*
 * timer0_pwm.c
 *
 * Created: 5/18/2021 12:35:43 AM
 * Author : remon
 */ 

#include <avr/io.h>
#define F_CPU 8000000
#include "TIMER.h"

int main(void)
{
    /* Replace with your application code */
	TIMER_init0_PWM(64);
    while (1) 
    {
    }
}

