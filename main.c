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


#define MyAddress     0x07



char Data[5] = {2, 3, 4, 5, 6};

int main(void) {
    /* Replace with your application code */

    init_LCD4();
    init_TWI(MyAddress, 18);

    setPORTA_DIR_VAL(0xFF, OUT);
    _delay_ms(200);
    EEPROM_TWI_WRITE(0x05, 9);

    _delay_ms(2000);
    char data = EEPROM_TWI_READ(0x05);
    _delay_ms(500);
    LCD4_data_num(data);

    _delay_ms(200);
    while (1) {


    }
}
