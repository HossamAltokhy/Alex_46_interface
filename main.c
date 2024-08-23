/*
 * File:   main.c
 * Author: hossa
 *
 * Created on August 2, 2024, 8:28 PM
 */
#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h>
#include <stdio.h>
#include <util/delay.h>
#include <stdlib.h>
#include "leds.h"
#include "DIO.h"
#include "buttons.h"
#include "output_devices.h"
#include "mkeypad.h"
#include "mLCD4.h"
#include "mINT.h"
#include "mADC.h"


#define clockSelect_Timer_OFF         0
#define clockSelect_Clk_io            1
#define clockSelect_Clk_io_8          2
#define clockSelect_Clk_io_64         3
#define clockSelect_Clk_io_256        4
#define clockSelect_Clk_io_1024       5
#define clockSelect_EXT_CLK_Falling   6
#define clockSelect_EXT_CLK_Rising    7

#define Timer_mode_Normal             0
#define Timer_mode_CTC                1
#define Timer_mode_PWM                2
#define Timer_mode_FPWM               3

#define Timer0_OCR0_val              124

void init_Timer0(char Timer_mode, char clockSelect);
void Timer0_selectMode(char Timer_mode);
void Timer0_selectCLK(char clockSelect);
void Timer0_TOV_INT_Enable();
void Timer0_COMP_INT_Enable();



//ISR(TIMER0_OVF_vect){
//    static int val_sec = 0;
//    static int seconds =0;
//    val_sec++;
//    if(val_sec ==61){
//        seconds++;
//        LCD4_CLEAR();
//        LCD4_data_num(seconds);
//        if(seconds==60){
//            LCD4_data_num(0);
//            seconds =0;
//        }
//        val_sec =0;
//    }
//    
//    
//}

ISR(TIMER0_COMP_vect){
    static int val_sec = 0;
    static int seconds =0;
    val_sec++;
    if(val_sec ==125){
        seconds++;
        LCD4_CLEAR();
        LCD4_data_num(seconds);
        if(seconds==60){
            LCD4_data_num(0);
            seconds =0;
        }
        val_sec =0;
    }
}


int main(void) {
    /* Replace with your application code */

    init_LCD4();
    init_Timer0(Timer_mode_CTC,clockSelect_Clk_io_1024);
        
    sei();
    while (1) {

        
        



    }
}


void init_Timer0(char Timer_mode, char clockSelect) {
    
    // Selecting Timer0 Mode
    Timer0_selectMode(Timer_mode);

    // Selecting Clock 
    Timer0_selectCLK(clockSelect);
}

void Timer0_selectMode(char Timer_mode) {
    switch (Timer_mode) {
        case Timer_mode_Normal:
            TCCR0 &= ~((1 << WGM00) | (1 << WGM01));
            Timer0_TOV_INT_Enable();
            break;
        case Timer_mode_CTC:
            OCR0 = Timer0_OCR0_val;
            TCCR0 &= ~(1<<WGM00);
            TCCR0 |= (1<<WGM01);
            Timer0_COMP_INT_Enable();
            break;
    }
}

void Timer0_selectCLK(char clockSelect) {
    TCCR0 &= ~((1 << CS02) | (1 << CS01) | (1 << CS00));
    TCCR0 |= clockSelect;
}

void Timer0_TOV_INT_Enable(){
    TIMSK |= (1<<TOIE0);
}
void Timer0_COMP_INT_Enable(){
    TIMSK |= (1<<OCIE0);
}