/*
 * LCD.h
 *
 * Created: 4/13/2021 6:42:22 PM
 *  Author: remon
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "DIO.h"
#define EIGH_BITS_MODE
#define CLR_SCREEN 0x01
#define CURSOR_ON_DISPLAN_ON 0x0e
#define RETURN_HOME 0x02
#define ENTRY_MODE 0x06
#define MAIN_PORT 'C'
#define CONTROL_PORT 'B'
#define EN 0
#define RS 1
#define RW 2 
#if defined EIGH_BITS_MODE
#define EIGHT_BITS 0x38
#elif defined FOUR_BITS_MODE 
#define FOUR_BITS 0x28
#endif


void LCD_init();
static void LCD_send_falling_edge();
void LCD_send_cmd(char cmd);
void LCD_send_char(char data);
void LCD_send_string(char * data);
void LCD_clear();
void LCD_move_cursor(char row,char col);

#endif /* LCD_H_ */