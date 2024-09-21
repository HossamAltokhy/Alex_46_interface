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




void init_7SEG();

int main(void) {
    /* Replace with your application code */

    // 0x0000  // 0000000000 //0 
    // 0x03FF  // 1111111111 //1023 

    //EEPROM_WRITE(0x0007, 0x05);

    init_7SEG();
    //    char display = EEPROM_READ(0x0007);
    int x =0;
    int counter = 0;
    while (1) {


        set_7SEG(x);
        counter++;
        
        if(counter == 200){
            counter = 0;
            x++;
        }


    }
}
