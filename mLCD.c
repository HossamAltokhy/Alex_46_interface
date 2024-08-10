#define F_CPU 16000000UL

#include <avr/io.h>

#include <util/delay.h>
#include <stdlib.h>
#include "DIO.h"
#include "mLCD.h"

void init_LCD() {
    //DIO
    setPORTC_DIR_VAL(0xFF, OUT);
    setPIND_DIR(RS,OUT);
    setPIND_DIR(RW,OUT);
    setPIND_DIR(EN,OUT);
    
    _delay_ms(20);
// LCD setup()
    setPIND(RW, LOW); // Write MODE
    // return HOME
    
    LCD_cmd(RETURN_HOME);
    // set MODE
    LCD_cmd(MODE_8BITs);
    // set cursor & display mode
    LCD_cmd(Cursor_OFF_DISPLAY_ON);
    
    // CLEAR
    LCD_cmd(CLEAR);
    LCD_cmd(ENTRY_MODE);
}

void LCD_cmd(char command) {
    // set Register Select Pin(RS) to Zero
    LCD_CONTROL &= ~(1 << RS);
    LCD_DATA = command;
    LCD_EN();
    _delay_ms(20);

}

void LCD_data(char data) {
    // set Register Select Pin(RS) to Zero
    LCD_CONTROL |= (1 << RS);
    LCD_DATA = data;
    LCD_EN();
    _delay_ms(20);
}

void LCD_EN() {
    LCD_CONTROL |= (1 << EN);
    _delay_ms(5);
    LCD_CONTROL &= ~(1 << EN);
}

void LCD_data_str(char* str ){
    for(int i =0 ;str[i]!='\0';i++){
        LCD_data(str[i]);
    }
}

void LCD_data_num(int num){
    char str[11];
    itoa(num, str,10);
    LCD_data_str(str);
}

void LCD_CLEAR(){
    LCD_CONTROL &= ~(1 << RS);
    LCD_DATA = CLEAR;
    LCD_EN();
    _delay_ms(5);
}