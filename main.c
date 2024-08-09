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






int main(void) {
    /* Replace with your application code */


    initLEDs();

    DDRA = 0xFF;
    init_keypad();
    while (1) {

        
       PORTA =  readKey();
//       _delay_ms(20);

    }
}
