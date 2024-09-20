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
// SLA address   // 0000101
#define SLA_W         0x0A

#define SLA_R         0x0B

#define ERROR    -1

void init_TWI(char TWI_Address, char TWI_CLOCK);
void TWI_M_Transmit(char SLA, char data);
char TWI_M_Receive(char SLA);

void TWI_M_Transmit_buf(char SLA, char* pData);
char* TWI_M_Receive_buf(char SLA);

void TWI_S_Transmit(char data);
char TWI_S_Receive();
char* TWI_S_Receieve_buf();


char Data[16];
char receivedData[16];

/// 
void EEPROM_SPI_WRITE_BYTE(char address, char data);
void EEPROM_SPI_WRITE_ARRAY(char address, char* pData, char array_sz);
void EEPROM_SPI_READ_ARRAY(char address, char* pData, char array_sz);
char EEPROM_SPI_READ_BYTE(char address);
void EEPROM_SPI_WRITE_ENABLE();
char EEPROM_READ_STATUS_REGISTER();
void EEPROM_ENABLE();
void EEPROM_DISABLE();

int main(void) {
    /* Replace with your application code */

    init_LCD4();
    setPORTA_DIR_VAL(0xFF, OUT);
    init_SPI(SPI_MASTER, SPI_CLOCK_128);
    _delay_ms(50);
    EEPROM_DISABLE();
    _delay_ms(100);



    while (1) {

        Data[0] = 'A';
        Data[1] = 'B';
        Data[2] = 'C';


        _delay_ms(200);
        EEPROM_SPI_WRITE_ENABLE();

        _delay_ms(200);

        EEPROM_SPI_WRITE_ARRAY(0x07, Data, 3);
        _delay_ms(50);
        EEPROM_SPI_READ_ARRAY(0x07, receivedData, 3);
        LCD4_data_str(receivedData);
    }
}

void EEPROM_SPI_READ_ARRAY(char address, char* pData, char array_sz) {
    EEPROM_ENABLE();
    SPI_send(0x03);
    SPI_send(address);
    for(int i=0; i<array_sz; i++){
       SPI_send(0x00);
       *(pData+i)= SPDR;
    }
    
    EEPROM_DISABLE();
    
}

void EEPROM_SPI_WRITE_ARRAY(char address, char* pData, char array_sz) {
    EEPROM_ENABLE();
    SPI_send(0x02);
    SPI_send(address);
    for (int i = 0; i < array_sz; i++) {
        SPI_send(*(pData + i));
    }

    EEPROM_DISABLE();
}

void EEPROM_SPI_WRITE_BYTE(char address, char data) {
    EEPROM_ENABLE();
    SPI_send(0x02);
    SPI_send(address);
    SPI_send(data);
    EEPROM_DISABLE();
}

char EEPROM_SPI_READ_BYTE(char address) {
    EEPROM_ENABLE();
    SPI_send(0x03);
    SPI_send(address);
    SPI_send(0x00);
    EEPROM_DISABLE();
    return SPDR;
}

void EEPROM_SPI_WRITE_ENABLE() {
    EEPROM_ENABLE();
    SPI_send(0x06);
    EEPROM_DISABLE();
}

char EEPROM_READ_STATUS_REGISTER() {
    EEPROM_ENABLE();
    SPI_send(0x05);
    SPI_send(0x00);
    EEPROM_DISABLE();
    return SPDR;
}

void EEPROM_ENABLE() {
    setPINB(SS, LOW);
}

void EEPROM_DISABLE() {
    setPINB(SS, HIGH);
}

void init_TWI(char TWI_Address, char TWI_CLOCK) {
    TWAR = TWI_Address;
    TWBR = 18; // To generate 100KHz while TWPS bits are Zeros.
}

void TWI_M_Transmit(char SLA, char data) {
    char statusCode = 0;
    // Start Condition 
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    statusCode = TWSR & 0xF8;
    if (statusCode != 0x08) {
        return ERROR;
    }

    TWDR = SLA;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    statusCode = TWSR & 0xF8;
    if (statusCode != 0x18 && statusCode != 0x20) {
        return ERROR;
    }

    TWDR = data;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    statusCode = TWSR & 0xF8;
    if (statusCode != 0x28 && statusCode != 0x30) {
        return ERROR;
    }

    TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);


}

char TWI_S_Receive() {
    char statusCode = 0;
    // Ready to receive my Address.
    TWCR = (1 << TWINT) | (1 << TWEA) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    statusCode = TWSR & 0xF8;
    if (statusCode != 0x60 && statusCode != 0x70) {
        return ERROR;
    }
    // Ready to receive Data.
    TWCR = (1 << TWINT) | (1 << TWEA) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    statusCode = TWSR & 0xF8;
    if (statusCode != 0x80 && statusCode != 0x90) {
        return ERROR;
    }
    return TWDR;
}