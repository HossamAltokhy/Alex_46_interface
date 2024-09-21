#include <avr/io.h>
#include "mTWI.h"
#include "EEPROM_TWI.h"

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

