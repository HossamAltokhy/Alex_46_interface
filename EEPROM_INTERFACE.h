/* 
 * File:   EEPROM_INTERFACE.h
 * Author: hossa
 *
 * Created on September 21, 2024, 8:21 PM
 */

#ifndef EEPROM_INTERFACE_H
#define	EEPROM_INTERFACE_H

void EEPROM_WRITE(int address, char data);
char EEPROM_READ(int address);

#endif	/* EEPROM_INTERFACE_H */

