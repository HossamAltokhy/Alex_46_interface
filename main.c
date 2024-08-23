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


ISR(ADC_vect) {
    LCD4_CLEAR();
    LCD4_data_num(ADCW * ADC_STEP);
    
    _delay_ms(500);
   
    ADC_SC();
}


char *pmessage;
int main(void) {
    /* Replace with your application code */
    //init_keypad();
    
    init_LCD4();

    init_ADC(CH2_CH1, AREF, ADC_FREQ_DIV128);

    // Enable Global Interrupt
    sei();

    _delay_ms(200);
    ADC_SC();
    while (1) {

//        for (int i = 0; i < 8; i++) {
//            ADC_select_CH(i);
//            ADC_SC();
//            while (!(ADCSRA & (1 << ADIF)));
//            LCD4_CLEAR();
////            sprintf(pmessage, "temp %d = ", i);
//            memcpy(pmessage, "temp = ", 8);
//            LCD4_data_str(pmessage);
//            LCD4_data_num(ADCW * ADC_STEP);
//            _delay_ms(500);
//        }



    }
}
