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



init_ADC();
ADC_select_CH(char CH);
ADC_select_REF(char REF);
ADC_select_FREQ(char FREQ);


int main(void) {
    /* Replace with your application code */

    while (1) {

    }
}
