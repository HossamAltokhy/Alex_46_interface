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




#define BUTTON     PB6
#define GREEN_LED  PD0

#define INT_LOW_LEVEL       0
#define INT_ANY_CHANGE      1
#define INT_FALLING_EDGE    2
#define INT_RISING_EDGE     3

void INT0_selectMode(char INT_Mode);
void init_INT0(char MODE);
void INT0_disable();

ISR(INT0_vect){
    PORTD ^= (1<<GREEN_LED);
}

int main(void) {
    /* Replace with your application code */
    setPIND_DIR(GREEN_LED, OUT);
    init_INT0(INT_ANY_CHANGE);
    sei();
    while (1) {

    }
}

void INT0_selectMode(char INT_MODE) {
    switch (INT_MODE) {
        case INT_LOW_LEVEL:
            MCUCR &= ~((1 << ISC01) | (1 << ISC00));
            break;
        case INT_ANY_CHANGE:
            MCUCR |= (1 << ISC00);
            MCUCR &= ~(1 << ISC01);
            break;
        case INT_FALLING_EDGE:
            MCUCR |= (1 << ISC01);
            MCUCR &= ~(1 << ISC00);
            break;
        case INT_RISING_EDGE:
            MCUCR |=((1 << ISC01) | (1 << ISC00));
            break;
    }
}


void init_INT0(char MODE){

    //Select Mode
    INT0_selectMode(MODE);
    
    //Enable INT0
    GICR |= (1<<INT0);
    
}

void INT0_disable(){
    GICR &= ~(1<<INT0);
}