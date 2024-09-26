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
#include "_7SEGMENT.h"

int main(void) {
    init_7SEG();

    int x =0;
    int counter =0;
    while (1) {

        set_7SEG(x);
        
        counter++;
        if(counter == 100){
            x++;
            counter = 0;
        }
        if(x== 100){
            x =0;
        }

    }
}
