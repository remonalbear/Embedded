/*
 * INTERRUPT.h
 *
 * Created: 4/8/2021 10:33:25 PM
 *  Author: remon
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

void EXTERNAL_INT0_init(unsigned char options);
void EXTERNAL_INT1_init(unsigned char options);
void EXTERNAL_INT2_init(unsigned char options);
void GLOBAL_interrupt_enable(void);
void GLOBAL_interrupt_disable(void);



#endif /* INTERRUPT_H_ */