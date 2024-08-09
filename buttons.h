/* 
 * File:   buttons.h
 * Author: hossa
 *
 * Created on August 9, 2024, 6:16 PM
 */

#ifndef BUTTONS_H
#define	BUTTONS_H
#include <avr/io.h>

#define BTN0 PB0
#define BTN1 PD6
#define BTN2 PD2

void initBTNs();

char isPressedA(char pinNUM);
char isPressedB(char pinNUM);
char isPressedC(char pinNUM);
char isPressedD(char pinNUM);

#endif	/* BUTTONS_H */

