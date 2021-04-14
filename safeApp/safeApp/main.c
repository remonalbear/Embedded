/*
 * safeApp.c
 *
 * Created: 4/14/2021 6:07:23 PM
 * Author : remon
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#define STATUS_ADDRES 0x20
#define EEPROM_ADDRES1 0x21
#define EEPROM_ADDRES2 0x22
#define EEPROM_ADDRES3 0x23
#define EEPROM_ADDRES4 0x24
#define MAX_TRIES 2 
#include "LCD.h"
#include "KEYPAD.h"
#include "EEPROM.h"

int main(void)
{
	char value;
	char flag=0;
	char tries=MAX_TRIES;
	LCD_init();
	KEYPAD_init();
	LCD_send_string("welcome");
	_delay_ms(1000);
	LCD_clear();
	
    if(EEPROM_read(STATUS_ADDRES)==NOTPRESSED){
	LCD_send_string("Enter Pass:");
	for (int i=0;i<4;i++)
	{
	do{
		value=KEYPAD_read();
	}while(value==NOTPRESSED);
	LCD_send_char(value);
	_delay_ms(500);
	LCD_move_cursor(1,12+i);
	LCD_send_char('*');
	_delay_ms(500);	
	EEPROM_write(EEPROM_ADDRES1+i,value);
	}
	EEPROM_write(STATUS_ADDRES,0x00);
	}
	
	char arr[4]={NOTPRESSED,NOTPRESSED,NOTPRESSED,NOTPRESSED};
    while (flag == 0) 
    {
		LCD_clear();
		LCD_send_string("check pass:");
		for(int i=0;i<4;i++){
			do 
			{
				arr[i]=KEYPAD_read();
			} while (arr[i]==NOTPRESSED);
			
			LCD_send_char(arr[i]);
			_delay_ms(500);
			LCD_move_cursor(1,12+i);
			LCD_send_char('*');
			_delay_ms(500);
		}
		if(EEPROM_read(EEPROM_ADDRES1)==arr[0] && EEPROM_read(EEPROM_ADDRES2)==arr[1] && EEPROM_read(EEPROM_ADDRES3)==arr[2] && EEPROM_read(EEPROM_ADDRES4)==arr[3]){
		LCD_clear();
		LCD_send_string("right pass");
		LCD_move_cursor(2,1);
		LCD_send_string("safe is opened");
		flag=1;	
			
		}else
		{
			tries=tries-1;
			if (tries>0)
			{
				LCD_clear();
				LCD_send_string("wrong pass");
				_delay_ms(1000);
				LCD_clear();
				LCD_send_string("# tries left:");
				LCD_send_char(tries+48);
				_delay_ms(1000);
			}
			else{
				LCD_clear();
				LCD_send_string("wrong pass");
				LCD_move_cursor(2,1);
				LCD_send_string("safe is closed");
				flag=1;
			}
			
		}
	}
}

