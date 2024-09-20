#include <avr/io.h>
#include "mSPI.h"
#include "DIO.h"
#include "EEPROM_SPI.h"


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

