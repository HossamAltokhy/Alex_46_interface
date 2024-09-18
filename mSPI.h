/* 
 * File:   mSPI.h
 * Author: hossa
 *
 * Created on September 14, 2024, 8:12 PM
 */

#ifndef MSPI_H
#define	MSPI_H

#include <avr/io.h>

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


#endif	/* MSPI_H */

