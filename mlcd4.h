/* 
 * File:   mlcd4.h
 * Author: hossa
 *
 * Created on August 10, 2024, 7:48 PM
 */

#ifndef MLCD4_H
#define	MLCD4_H

#include <avr/io.h>

#include "DIO.h"

#define LCD_DATA_DIR    DDRA
#define LCD_DATA        PORTA

#define LCD_CONTROL     PORTB
#define LCD_CONTROL_DIR DDRB

#define RS       PB1    
#define RW       PB2
#define EN       PB3

// LCD Codes
#define CLEAR       0x01
#define MODE_8BITs  0x38
#define MODE_4BITs  0x28
#define RETURN_HOME 0x02
#define Cursor_OFF_DISPLAY_ON 0x0C
#define ENTRY_MODE  0x06
#define MOVE_RIGHT  0x14
#define MOVE_LEFT   0x10


void init_LCD4();
void LCD4_EN();
void LCD4_cmd(char);
void LCD4_data(char);
void LCD4_data_str(char*);
void LCD4_data_num(int num);
void LCD4_CLEAR();
void LCD4_MOVE_LEFT(char steps);
void LCD4_MOVE_RIGHT(char steps);
#endif	/* MLCD_H */

