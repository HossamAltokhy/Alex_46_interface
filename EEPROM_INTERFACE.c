
#include <avr/io.h>

void EEPROM_WRITE(int address, char data) {

    // Check if EEPROM is ready
    while (EECR & (1 << EEWE));

    // set Data
    EEDR = data;
    // set Address
    EEAR = address;

    // Set Master Write enable
    EECR |= (1 << EEMWE);

    // Set Write Enable
    EECR |= (1 << EEWE);
}

char EEPROM_READ(int address) {
    // Check if EEPROM is ready
    while (EECR & (1 << EEWE));
    // set Address
    EEAR = address;
    // Set Read Enable
    EECR |= (1 << EERE);

    return EEDR;
}

