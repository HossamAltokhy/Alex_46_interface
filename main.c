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

#define EEPROM_ADDRESS_R    0xA1   // 10100001
#define EEPROM_ADDRESS_W    0xA0   // 10100000

void init_TWI(char TWI_Address, char TWI_CLOCK);
void TWI_M_Transmit(char SLA, char data);
char TWI_M_Receive(char SLA);

void TWI_M_Transmit_buf(char SLA, char* pData, char array_sz);
char* TWI_M_Receive_buf(char SLA, char array_sz);

void TWI_S_Transmit(char data);
char TWI_S_Receive();
char* TWI_S_Receieve_buf();



void EEPROM_TWI_WRITE(int address, char data);
char EEPROM_TWI_READ(int address);



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

void EEPROM_TWI_WRITE(int address, char data) {
    char statusCode = 0;
    // Start Condition
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    statusCode = TWSR & 0xF8;
    if (statusCode != 0x08) {
        return ERROR;
    }
    // EEPROM Address
    TWDR = EEPROM_ADDRESS_W; // 1010000
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    statusCode = TWSR & 0xF8;
    if (statusCode != 0x18) {
        return ERROR;
    }
    // MEMORY LOCATION ADDRESS 16 bits
    TWDR = address;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    statusCode = TWSR & 0xF8;
    if (statusCode != 0x28) {
        return ERROR;
    }
    // DATA
    TWDR = data;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    statusCode = TWSR & 0xF8;
    if (statusCode != 0x28) {
        return ERROR;
    }
    // STOP Condition
    TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
}

char EEPROM_TWI_READ(int address) {
    char statusCode = 0;
    // Start Condition
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    statusCode = TWSR & 0xF8;
    if (statusCode != 0x08) {
        return ERROR;
    }
    // EEPROM Address
    TWDR = EEPROM_ADDRESS_W; // 1010000
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    statusCode = TWSR & 0xF8;
    if (statusCode != 0x18) {
        return ERROR;
    }
    // MEMORY LOCATION ADDRESS 16 bits
    TWDR = address;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    statusCode = TWSR & 0xF8;
    if (statusCode != 0x28) {
        return ERROR;
    }
    // Repeated Address
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    statusCode = TWSR & 0xF8;
    if (statusCode != 0x10) {
        return ERROR;
    }
    // EEPROM Address
    TWDR = EEPROM_ADDRESS_R; // 1010000
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    statusCode = TWSR & 0xF8;
    if (statusCode != 0x40) {
        return ERROR;
    }

    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
    while (!(TWCR & (1 << TWINT)));
    statusCode = TWSR & 0xF8;
    if (statusCode != 0x50) {
        return 7;
    }
    char data = TWDR;

    TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);

    return data;

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

void TWI_M_Transmit_buf(char SLA, char* pData, char array_sz) {
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

    for (int i = 0; i < array_sz; i++) {
        TWDR = *(pData + i);
        TWCR = (1 << TWINT) | (1 << TWEN);
        while (!(TWCR & (1 << TWINT)));
        statusCode = TWSR & 0xF8;
        if (statusCode != 0x28) {
            return ERROR;
        }
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

char TWI_M_Receive(char SLA) {
    char data = 0;
    char statusCode = 0;
    // Start Condition 
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    statusCode = TWSR & 0xF8;
    if (statusCode != 0x08) {
        return ERROR;
    }
    // SLA + R 
    TWDR = SLA;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    statusCode = TWSR & 0xF8;
    if (statusCode != 0x40) {
        return ERROR;
    }
    // Get ACK ready 
    TWCR = (1 << TWINT) | (1 << TWEA) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    statusCode = TWSR & 0xF8;
    if (statusCode != 0x50) {
        return ERROR;
    }
    data = TWDR;
    TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);

    return data;
}

void TWI_S_Transmit(char data) {
    char statusCode = 0;
    // Ready to receive my Address.
    TWCR = (1 << TWINT) | (1 << TWEA) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    statusCode = TWSR & 0xF8;
    if (statusCode != 0xA8) {
        return ERROR;
    }

    // SLAVE transmits data
    TWDR = data;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    statusCode = TWSR & 0xF8;
    if (statusCode != 0xB8) {
        return ERROR;
    }

}

void TWI_S_Receive_buf(char *pData, char array_sz) {
    char statusCode = 0;
    // Ready to receive my Address.
    TWCR = (1 << TWINT) | (1 << TWEA) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    statusCode = TWSR & 0xF8;
    if (statusCode != 0x60 && statusCode != 0x70) {
        return ERROR;
    }

    for (int i = 0; i < array_sz; i++) {
        // Ready to receive Data.
        TWCR = (1 << TWINT) | (1 << TWEA) | (1 << TWEN);
        while (!(TWCR & (1 << TWINT)));
        statusCode = TWSR & 0xF8;
        if (statusCode != 0x80 && statusCode != 0x90) {
            return ERROR;
        }
        *(pData + i) = TWDR;
    }



}