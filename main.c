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




int main(void) {
    /* Replace with your application code */

    setPINB_DIR(BTN_DEC, IN);
    setPINB_DIR(BTN_INC, IN);

    init_LCD4();

    Timer0_OC0_init();
    Timer0_OC0_select_mode(OC0_FPWM_CLEAR);
    init_Timer0(Timer_mode_FPWM, clockSelect_Clk_io_1024);

    _delay_ms(50);
    LCD4_CLEAR();
    LCD4_data_num(OCR0 * 100 / 255.0);
    LCD4_data('%');
    // sei();
    while (1) {


        if (isPressedB(BTN_INC)) {
            OCR0 += 1;
            _delay_ms(200);
            LCD4_CLEAR();
            LCD4_data_num(OCR0 * 100 / 255.0);
            LCD4_data('%');
        }
        if (isPressedB(BTN_DEC)) {
            OCR0 -= 1;
            _delay_ms(200);
            LCD4_CLEAR();
            LCD4_data_num(OCR0 * 100 / 255.0);
            LCD4_data('%');
        }






    }
}
