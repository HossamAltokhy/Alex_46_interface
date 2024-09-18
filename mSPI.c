#include <avr/io.h>
#include "mSPI.h"
#include "DIO.h"


void init_SPI(int mode, int SPI_clock) {
    SPCR |= (mode << MSTR);

    if (mode) {
        setPORTB_DIR_VAL((1 << MOSI) | (1 << SCK) | (1 << SS), OUT);
        SPCR |= SPI_clock;

    } else {
        setPORTB_DIR_VAL((1 << MISO), OUT);
    }

    SPCR |= (1 << SPE);
}

void SPI_send(char data) {
    SPDR = data;
    while (!(SPSR & (1 << SPIF)));
}

char SPI_receive() {
    while (!(SPSR & (1 << SPIF)));
    return SPDR;
}
