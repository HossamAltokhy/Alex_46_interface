/*
 * File:   main.c
 * Author: hossa
 *
 * Created on August 2, 2024, 8:28 PM
 */
#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>

#include <util/delay.h>

#include "leds.h"
#include "DIO.h"
#include "buttons.h"
#include "output_devices.h"
#include "mkeypad.h"
#include "mLCD4.h"
#include "mINT.h"

#define ADC_STEP 4.887585532746823069403714565

#define CH0     0
#define CH1     1
#define CH2     2
#define CH3     3
#define CH4     4
#define CH5     5
#define CH6     6
#define CH7     7


#define AREF               0  // 00
#define AVCC               1  // 01
#define INTERAL_VOLTAGE    3  // 11


#define ADC_FREQ_DIV128       7

void init_ADC(char CH, char REF, char FREQ);
void ADC_select_CH(char CH);
void ADC_select_REF(char REF);
void ADC_select_FREQ(char FREQ);
void ADC_SC();
void ADC_EN();
void ADC_INT_EN();
//ADC_AUTO_TRIGGERING(char mode);

ISR(ADC_vect) {
    LCD4_CLEAR();
    LCD4_data_num(ADCW * ADC_STEP);


    _delay_ms(50);
    ADC_SC();
}

int main(void) {
    /* Replace with your application code */
    init_LCD4();

    init_ADC(CH0, AREF, ADC_FREQ_DIV128);

    // Enable Global Interrupt
    sei();
    
    _delay_ms(200);
    ADC_SC();
    while (1) {
        

        //waiting for Flag
        // Pooling
        //while (!(ADCSRA & (1 << ADIF)));

    }
}

void init_ADC(char CH, char REF, char FREQ) {
    // Select Channel
    ADC_select_CH(CH);
    // Select VREF
    ADC_select_REF(REF);
    // Select FREQ
    ADC_select_FREQ(FREQ);

    // Enable Interrupt If needed
    ADC_INT_EN();

    // Enable ADC Pripheral
    ADC_EN();
}

void ADC_select_CH(char CH) {
    //ADMUX
    ADMUX &= ~((1 << MUX2) | (1 << MUX1) | (1 << MUX0));
    ADMUX |= CH;
}

void ADC_select_REF(char REF) {
    ADMUX &= ~((1 << REFS1) | (1 << REFS0));
    ADMUX |= (REF << 6);
}

void ADC_select_FREQ(char FREQ) {
    //ADCSRA
    ADCSRA &= ~((1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0));
    ADCSRA |= FREQ;
}

void ADC_SC() {
    ADCSRA |= (1 << ADSC);
}

void ADC_EN() {
    ADCSRA |= (1 << ADEN);
}

void ADC_INT_EN() {
    ADCSRA |= (1 << ADIE);
}