/*
 * SEVENSEGMENT.h
 *
 * Created: 4/3/2021 6:00:32 PM
 *  Author: remon
 */ 


#ifndef SEVENSEGMENT_H_
#define SEVENSEGMENT_H_

void SEVENSEGMENT_init(unsigned char port );
void SEVENSEGMENT_write(unsigned char port ,unsigned char number);
void BCD_SEVENSEGMENT_init(unsigned char port );
void BCD_SEVENSEGMENT_write(unsigned char port ,unsigned char number);


#endif /* SEVENSEGMENT_H_ */