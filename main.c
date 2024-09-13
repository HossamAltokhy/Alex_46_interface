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

#define SPI_MASTER     1
#define SPI_SLAVE      0

#define SPI_CLOCK_4    0
#define SPI_CLOCK_16   1
#define SPI_CLOCK_64   2
#define SPI_CLOCK_128  3

#define MOSI    PB5
#define MISO    PB6
#define SCK     PB7
#define SS      PB4



void init_SPI(int mode, int SPI_clock);
void SPI_send(char data);
char SPI_receive();
char x = 0x01;
int main(void) {
    /* Replace with your application code */
   
    init_SPI(SPI_MASTER, SPI_CLOCK_128);
    

    
    while (1) {
        SPI_send(x++);
        _delay_ms(1000);
    }
}


void init_SPI(int mode, int SPI_clock){
    SPCR |= (mode<<MSTR);
    
    if(mode){
        setPORTB_DIR_VAL((1<<MOSI)|(1<<SCK)|(1<<SS), OUT);
    }
    else{
        setPORTB_DIR_VAL((1<<MISO), OUT);
    }
    SPCR |= SPI_clock;
    
    SPCR |= (1<<SPE);
}

void SPI_send(char data){
    SPDR = data;
    while(!(SPSR & (1<<SPIF)));
}

char SPI_receive(){
    while(!(SPSR & (1<<SPIF)));
    return SPDR;
}