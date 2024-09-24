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
#include "mUART.h"
#include "mSPI.h"

int main(void) {
    initBTNs();
    Timer2_OC2_select_mode(OC2_FPWM_SET);
    Timer2_OC2_init();
    init_Timer2(Timer_mode_FPWM, clockSelect_Clk_io_1024);

    init_LCD4();


    while (1) {

        //        if(isPressedB(BTN0)){
        //            OCR2 += 10;
        //            _delay_ms(100);
        //        }
        //        if(isPressedD(BTN2)){
        //            OCR2 -= 10;
        //            _delay_ms(100);
        //        }

        for (; OCR2 < 250; OCR2 += 10) {
//            LCD4_CLEAR();
//            LCD4_data_num(OCR2);
            _delay_ms(20);
        }
        for (; OCR2 > 0; OCR2 -= 10) {
//            LCD4_CLEAR();
//            LCD4_data_num(OCR2);
            _delay_ms(20);
        }


    }
}
