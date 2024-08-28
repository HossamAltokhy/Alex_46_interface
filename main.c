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
#include "mTimer.h"

ISR(TIMER0_OVF_vect){
    
}

ISR(ADC_vect){
    LCD4_CLEAR();
    LCD4_data_num(ADCW * ADC_STEP);
    _delay_ms(5000);
}

int main() {

    init_LCD4();
    _delay_ms(50);
    LCD4_data('A');
    init_ADC(CH1, AVCC, ADC_FREQ_DIV128);
    _delay_ms(50);
    TCNT0 = 250;
    init_Timer0(Timer_mode_Normal, clockSelect_EXT_CLK_Rising);

    sei();
    
//    ADC_SC();
    while (1) {

        
        LCD4_CLEAR();
        LCD4_data_num(TCNT0);

    }
}
