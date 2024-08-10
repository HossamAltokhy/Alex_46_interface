/* 
 * File:   mLCD.h
 * Author: hossa
 *
 * Created on August 10, 2024, 5:28 PM
 */

#ifndef MLCD_H
#define	MLCD_H

#include <avr/io.h>

#include "DIO.h"

#define LCD_DATA_DIR    DDRC
#define LCD_DATA        PORTC

#define LCD_CONTROL     PORTD
#define LCD_CONTROL_DIR DDRD

#define RS       PD0    
#define RW       PD1
#define EN       PD2

// LCD Codes
#define CLEAR       0x01
#define MODE_8BITs  0x38
#define MODE_4BITs  0x28
#define RETURN_HOME 0x02
#define Cursor_OFF_DISPLAY_ON 0x0C
#define ENTRY_MODE  0x06


void init_LCD();
void LCD_EN();
void LCD_cmd(char);
void LCD_data(char);
void LCD_data_str(char*);
void LCD_data_num(int num);
void LCD_CLEAR();
#endif	/* MLCD_H */

