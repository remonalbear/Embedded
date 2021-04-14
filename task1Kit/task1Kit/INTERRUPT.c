/*
 * INTERRUPT.c
 *
 * Created: 4/8/2021 10:33:04 PM
 *  Author: remon
 */ 

#include <avr/interrupt.h>
#include "INTERRUPT.h"
#include "DIO.h"
#include "macros.h"

void EXTERNAL_INT0_init(unsigned char options){
	SET_BIT(GICR,INT0);
	switch(options){
		case 1://low level trigger
			CLR_BIT(MCUCR,ISC00);
			CLR_BIT(MCUCR,ISC01);
			break;
		
		case 2:// logical change trigger
			SET_BIT(MCUCR,ISC00);
			CLR_BIT(MCUCR,ISC01);
			break;
		
		case 3:// failing edge trigger
			CLR_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
		case 4 :
			SET_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;	
		default:// raising edge trigger
			CLR_BIT(MCUCR,ISC00);
			CLR_BIT(MCUCR,ISC01);
					
			break;
	}
	
}
void EXTERNAL_INT1_init(unsigned char options){
	SET_BIT(GICR,INT1);
	switch(options){
		case 1: //low level trigger
			CLR_BIT(MCUCR,ISC10);
			CLR_BIT(MCUCR,ISC11);
			break;
		
		case 2: // logical change trigger
			SET_BIT(MCUCR,ISC10);
			CLR_BIT(MCUCR,ISC11);
			break;

		case 3: // failing edge trigger
			CLR_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
			break;		

		case 4: // raising edge trigger
			SET_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
			break;
		default:
			CLR_BIT(MCUCR,ISC10);
			CLR_BIT(MCUCR,ISC11);		
		break;
	}
}
void EXTERNAL_INT2_init(unsigned char options){
	SET_BIT(GICR,INT2);
	switch(options){
		case 1: // failing edge trigger
			CLR_BIT(MCUCSR,ISC2);
			break;

		case 2: // raising edge trigger
			SET_BIT(MCUCSR,ISC2);
			break;
		default:
			CLR_BIT(MCUCSR,ISC2);
			break;
	}
}
void GLOBAL_interrupt_enable(void){
	sei();
}
void GLOBAL_interrupt_disable(void){
	cli();
}