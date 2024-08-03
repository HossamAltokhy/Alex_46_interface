/*
 * File:   main.c
 * Author: hossa
 *
 * Created on August 2, 2024, 8:28 PM
 */


#include <avr/io.h>
#include "leds.h"






int main(void) {
    /* Replace with your application code */


    initLEDs();
    LED_ON(LED0);
    while (1) {



    }
}
