/* 
 * File:   EEPROM_SPI.h
 * Author: hossa
 *
 * Created on September 20, 2024, 6:35 PM
 */

#ifndef EEPROM_SPI_H
#define	EEPROM_SPI_H


void EEPROM_SPI_WRITE_BYTE(char address, char data);
void EEPROM_SPI_WRITE_ARRAY(char address, char* pData, char array_sz);
void EEPROM_SPI_READ_ARRAY(char address, char* pData, char array_sz);
char EEPROM_SPI_READ_BYTE(char address);
void EEPROM_SPI_WRITE_ENABLE();
char EEPROM_READ_STATUS_REGISTER();
void EEPROM_ENABLE();
void EEPROM_DISABLE();


#endif	/* EEPROM_SPI_H */

