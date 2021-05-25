/*
 * LCD.c
 *
 * Created: 4/13/2021 6:42:33 PM
 *  Author: remon
 */ 

#include "LCD.h"
#define F_CPU 8000000UL
#include <util/delay.h>

void LCD_init(){
	_delay_ms(200);
	#if defined EIGH_BITS_MODE
	DIO_set_port_dir(MAIN_PORT,1);
	DIO_set_bit_dir(CONTROL_PORT,EN,1);
	DIO_set_bit_dir(CONTROL_PORT,RW,1);
	DIO_set_bit_dir(CONTROL_PORT,RS,1);
	DIO_write_bit(CONTROL_PORT,RW,0);
	LCD_send_cmd(EIGHT_BITS);
	_delay_ms(1);
	LCD_send_cmd(CURSOR_ON_DISPLAN_ON);
	_delay_ms(1);
	LCD_send_cmd(CLR_SCREEN);
	_delay_ms(10);
	LCD_send_cmd(ENTRY_MODE);
	_delay_ms(1);
	#elif defined FOUR_BITS_MODE
	DIO_set_bit_dir(MAIN_PORT,0,1);
	DIO_set_bit_dir(MAIN_PORT,1,1);
	DIO_set_bit_dir(MAIN_PORT,2,1);
	DIO_set_bit_dir(MAIN_PORT,3,1);
	DIO_set_bit_dir(CONTROL_PORT,EN,1);
	DIO_set_bit_dir(CONTROL_PORT,RW,1);
	DIO_set_bit_dir(CONTROL_PORT,RS,1);
	DIO_write_bit(CONTROL_PORT,RW,0);
	LCD_send_cmd(RETURN_HOME);
	_delay_ms(10);
	LCD_send_cmd(FOUR_BITS);
	_delay_ms(1);
	LCD_send_cmd(CURSOR_ON_DISPLAN_ON);
	_delay_ms(1);
	LCD_send_cmd(CLR_SCREEN);
	_delay_ms(10);
	LCD_send_cmd(ENTRY_MODE);
	_delay_ms(1);
	#endif
}
static void LCD_send_falling_edge(){
	DIO_write_bit(CONTROL_PORT,EN,1);
	_delay_ms(2);
	DIO_write_bit(CONTROL_PORT,EN,0);
	_delay_ms(2);
}
void LCD_send_cmd(char cmd){
	#if defined EIGH_BITS_MODE
	DIO_write_port(MAIN_PORT,cmd);
	DIO_write_bit(CONTROL_PORT,RS,0);
	LCD_send_falling_edge();
	#elif defined FOUR_BITS_MODE
	DIO_write_low_nibble(MAIN_PORT,cmd>>4);
	DIO_write_bit(CONTROL_PORT,RS,0);
	LCD_send_falling_edge();
	DIO_write_low_nibble(MAIN_PORT,cmd);
	DIO_write_bit(CONTROL_PORT,RS,0);
	LCD_send_falling_edge();
	#endif
}
void LCD_send_char(char data){
	#if defined EIGH_BITS_MODE
	DIO_write_port(MAIN_PORT,data);
	DIO_write_bit(CONTROL_PORT,RS,1);
	LCD_send_falling_edge();
	#elif defined FOUR_BITS_MODE
	DIO_write_low_nibble(MAIN_PORT,data>>4);
	DIO_write_bit(CONTROL_PORT,RS,1);
	LCD_send_falling_edge();
	DIO_write_low_nibble(MAIN_PORT,data);
	DIO_write_bit(CONTROL_PORT,RS,1);
	LCD_send_falling_edge();
	#endif
	
}

void LCD_send_string(char* data){
	while((*data) != '\0'){
		LCD_send_char(*data);
		data++;
	}
}
void LCD_clear(){
	LCD_send_cmd(CLR_SCREEN);
	_delay_ms(10);
}
void LCD_move_cursor(char row,char col){
		char data ;
		if(row>2||row<1||col>16||col<1)
		{
			data=0x80;
		}
		else if(row==1)
		{
			data=0x80+col-1 ;
		}
		else if (row==2)
		{
			data=0xc0+col-1;
		}
		LCD_send_cmd(data);
		_delay_ms(1);
}