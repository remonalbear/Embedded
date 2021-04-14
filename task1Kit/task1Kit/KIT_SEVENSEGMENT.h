/*
 * KIT_SEVENSEGMENT.h
 *
 * Created: 4/4/2021 12:51:14 PM
 *  Author: remon
 */ 


#ifndef KIT_SEVENSEGMENT_H_
#define KIT_SEVENSEGMENT_H_

void KIT_SEVENSEGMENT_init(void);
void KIT_SEVENSEGMENT_write(unsigned char segment_number,unsigned char value);
void KIT_SEVENSEGMENT_off(unsigned char segment_number);
void KIT_SEVENSEGMENT_on(unsigned char segment_number);



#endif /* KIT_SEVENSEGMENT_H_ */