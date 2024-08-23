/* 
 * File:   mkeypad.h
 * Author: hossa
 *
 * Created on August 9, 2024, 8:24 PM
 */

#ifndef MKEYPAD_H
#define	MKEYPAD_H

#define Keypad_PORT_DIR    DDRD
#define Keypad_PORT        PORTD

void init_keypad();
char readKey();

char getKey();

#endif	/* MKEYPAD_H */

