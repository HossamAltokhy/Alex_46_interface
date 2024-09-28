/* 
 * File:   EEPROM_TWI.h
 * Author: hossa
 *
 * Created on September 21, 2024, 6:06 PM
 */

#ifndef EEPROM_TWI_H
#define	EEPROM_TWI_H

#define EEPROM_ADDRESS_R    0xA1   // 10100001
#define EEPROM_ADDRESS_W    0xA0   // 10100000

char EEPROM_TWI_WRITE(int address, char data);
char EEPROM_TWI_READ(int address);



#endif	/* EEPROM_TWI_H */

