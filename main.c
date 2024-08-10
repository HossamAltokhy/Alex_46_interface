/*
 * File:   main.c
 * Author: hossa
 *
 * Created on August 2, 2024, 8:28 PM
 */
#define F_CPU 16000000UL

#include <avr/io.h>

#include <util/delay.h>

#include "leds.h"
#include "DIO.h"
#include "buttons.h"
#include "output_devices.h"
#include "mkeypad.h"
#include "mLCD4.h"




char message[] = "Hello";

int main(void) {
    /* Replace with your application code */
    
    init_keypad();
    _delay_ms(5);
    
    init_LCD4();
    _delay_ms(50);
    
    LCD4_GOTO(0,4);
    while (1) {

        LCD4_data(getKey());
        
        _delay_ms(500);
        
    }
}
