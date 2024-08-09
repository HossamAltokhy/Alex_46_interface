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






int main(void) {
    /* Replace with your application code */


    initLEDs();
    initBTNs();
    while (1) {

        
        LED_ON(LED0);
        _delay_ms(5000);
        LED_OFF(LED0);
        _delay_ms(5000);

    }
}
