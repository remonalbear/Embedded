#include <avr/io.h>
#include "DIO.h"
#include "macros.h"

void DIO_set_bit_dir(unsigned char port,unsigned char bit , unsigned char dir){
	switch(port){
		case 'A':
			if (dir==1){
				SET_BIT(DDRA,bit);
			}
			else{
				CLR_BIT(DDRA,bit);
			}
			break;
		case 'B':
			if (dir==1){
				SET_BIT(DDRB,bit);
			}
			else{
				CLR_BIT(DDRB,bit);
			}
			break;
		case 'C':
			if (dir==1){
				SET_BIT(DDRC,bit);
			}
			else{
				CLR_BIT(DDRC,bit);
			}
			break;
		case 'D':
			if (dir==1){
				SET_BIT(DDRD,bit);
			}
			else{
				CLR_BIT(DDRD,bit);
			}
			break;
	}
}
unsigned char DIO_read_bit(unsigned char port,unsigned char bit){
	unsigned char value;
	switch(port){
		case 'A':
			value=READ_BIT(PINA,bit);
		break;
		case 'B':
			value=READ_BIT(PINB,bit);
		break;
		case 'C':
		value=READ_BIT(PINC,bit);
		break;
		case 'D':
		value=READ_BIT(PIND,bit);
		break;	
	}
	return value;
}
void DIO_write_bit(unsigned char port,unsigned char bit , unsigned char value){
	switch(port){
		case 'A':
			if (value==1){
				SET_BIT(PORTA,bit);
			}
			else{
				CLR_BIT(PORTA,bit);
			}
		break;
		case 'B':
			if (value==1){
				SET_BIT(PORTB,bit);
			}
			else{
				CLR_BIT(PORTB,bit);
			}			
		break;
		case 'C':
			if (value==1){
				SET_BIT(PORTC,bit);
			}
			else{
				CLR_BIT(PORTC,bit);
			}
		break;
		case 'D':
			if (value==1){
				SET_BIT(PORTD,bit);
			}
			else{
				CLR_BIT(PORTD,bit);
			}
		break;	
	}
}
void DIO_toggle_bit(unsigned char port,unsigned char bit){
		switch(port){
			case 'A':
				TOG_BIT(PORTA,bit);
			break;
			case 'B':
				TOG_BIT(PORTB,bit);
			break;
			case 'C':
				TOG_BIT(PORTC,bit);
			break;
			case 'D':
				TOG_BIT(PORTD,bit);
			break;
	}
}
void DIO_set_port_dir(unsigned char port , unsigned char dir){
	switch(port){
		case 'A':
		if (dir==1){
			DDRA=0xff;
		}
		else{
			DDRA=0x00;
		}
		break;
		case 'B':
		if (dir==1){
			DDRB=0xff;
		}
		else{
			DDRB=0x00;
		}
		break;
		case 'C':
		if (dir==1){
			DDRC=0xff;
		}
		else{
			DDRC=0x00;
		}
		break;
		case 'D':
		if (dir==1){
			DDRD=0xff;
		}
		else{
			DDRD=0x00;
		}
		break;
	}
}
void DIO_write_port(unsigned char port, unsigned char value){
	switch(port){
		case 'A':
			PORTA=value;
			break;
		case 'B':
			PORTB=value;
			break;
		case 'C':
			PORTC=value;
			break;
		case 'D':
			PORTD=value;
			break;	
	}
}
unsigned char DIO_read_port(unsigned char port){
		unsigned char value;
		switch(port){
			case 'A':
				value=PINA;;
			case 'B':
				value=PINB;
			case 'C':
				value=PINC;
			break;
			case 'D':
				value=PIND;
			break;
}
	return value;
}

void DIO_connect_pullup(unsigned char port,unsigned char bit,unsigned char connect){
	switch(port){
		case 'A':
		if (connect==1){
			SET_BIT(PORTA,bit);
		}
		else{
			CLR_BIT(PORTA,bit);
		}
		break;
		case 'B':
		if (connect==1){
			SET_BIT(PORTB,bit);
		}
		else{
			CLR_BIT(PORTB,bit);
		}
		break;
		case 'C':
		if (connect==1){
			SET_BIT(PORTC,bit);
		}
		else{
			CLR_BIT(PORTC,bit);
		}
		break;
		case 'D':
		if (connect==1){
			SET_BIT(PORTD,bit);
		}
		else{
			CLR_BIT(PORTD,bit);
		}
		break;
	}
}

void DIO_write_low_nibble(unsigned char port,unsigned char value){
	value&=0x0f;
	switch(port){
		case'A':
			PORTA&=0xf0;
			PORTA|=value;	
		break;
		case'B':
			PORTB &=0xf0;
			PORTB |=value;
		break;
		case'C':
			PORTC&=0xf0;
			PORTC|=value;
		break;
		case'D':
			PORTD&=0xf0;
			PORTD|=value;
		break;		
	}	
}

void DIO_write_high_nibble(unsigned char port,unsigned char value){
	value<<=4;
	switch(port){
		case'A':
			PORTA&=0x0f;
			PORTA|=value;
		break;
		case'B':
			PORTB &=0x0f;
			PORTB |=value;
		break;
		case'C':
			PORTC&=0x0f;
			PORTC|=value;
		break;
		case'D':
			PORTD&=0x0f;
			PORTD|=value;
		break;
	}
}

void DIO_and_port(unsigned char port , unsigned char value){
	switch(port){
	case 'A':
		PORTA&=value;
	break;
		
	case 'B':
		PORTB&=value;
	break;
	
	case 'C':
		PORTC&=value;
	break;
	
	case 'D':
		PORTD&=value;
	break;	
		
		
	}
}
void DIO_or_port(unsigned char port , unsigned char value){
	switch(port){
		case 'A':
		PORTA|=value;
		break;
		
		case 'B':
		PORTB|=value;
		break;
		
		case 'C':
		PORTC|=value;
		break;
		
		case 'D':
		PORTD|=value;
		break;
		
	}
}

