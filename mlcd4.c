#define F_CPU 16000000UL

#include <avr/io.h>

#include <util/delay.h>
#include <stdlib.h>
#include "DIO.h"
#include "mLCD4.h"

void init_LCD4() {
    //DIO
    setPORTA_DIR_VAL(0xF0, OUT);
    setPINB_DIR(RS,OUT);
    setPINB_DIR(RW,OUT);
    setPINB_DIR(EN,OUT);
    
    _delay_ms(20);
// LCD setup()
    setPINB(RW, LOW); // Write MODE
    // return HOME
    
    LCD4_cmd(RETURN_HOME);
    // set MODE
    LCD4_cmd(MODE_4BITs);
    // set cursor & display mode
    LCD4_cmd(Cursor_OFF_DISPLAY_ON);
    
    // CLEAR
    LCD4_cmd(CLEAR);
    //LCD4_cmd(ENTRY_MODE);
}

void LCD4_cmd(char command) {
    // set Register Select Pin(RS) to Zero
    LCD_CONTROL &= ~(1 << RS);
    LCD_DATA = (LCD_DATA&0x0F)|(command&0xF0);
    LCD4_EN();
    LCD_DATA = (LCD_DATA&0x0F)|(command<<4);
    LCD4_EN();
    _delay_ms(20);

}

void LCD4_data(char data) {
    // set Register Select Pin(RS) to Zero
    LCD_CONTROL |= (1 << RS);
    LCD_DATA = (LCD_DATA&0x0F)|(data&0xF0);
    LCD4_EN();
    LCD_DATA = (LCD_DATA&0x0F)|(data<<4);
    LCD4_EN();
    _delay_ms(20);
}

void LCD4_EN() {
    LCD_CONTROL |= (1 << EN);
    _delay_ms(5);
    LCD_CONTROL &= ~(1 << EN);
}

void LCD4_data_str(char* str ){
    for(int i =0 ;str[i]!='\0';i++){
        LCD4_data(str[i]);
    }
}

void LCD4_data_num(int num){
    char str[11];
    itoa(num, str,10);
    LCD4_data_str(str);
}

void LCD4_CLEAR(){
    LCD_CONTROL &= ~(1 << RS);
    LCD_DATA = (LCD_DATA&0x0F)|(CLEAR&0xF0);
    LCD4_EN();
    LCD_DATA = (LCD_DATA&0x0F)|(CLEAR<<4);
    
    LCD4_EN();
    _delay_ms(5);
}

void LCD4_MOVE_LEFT(char steps){
    for(int  i = 0; i < steps; i++){
        LCD4_cmd(MOVE_LEFT);   
    }
}
void LCD4_MOVE_RIGHT(char steps){
        for(int  i = 0; i < steps; i++){
        LCD4_cmd(MOVE_RIGHT);   
    }
}

void LCD4_GOTO(char row, char column){
    LCD4_cmd(0x80|column|(row<<6));
}