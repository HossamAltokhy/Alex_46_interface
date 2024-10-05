/* 
 * File:   leds.h
 * Author: hossa
 *
 * Created on August 3, 2024, 6:45 PM
 */
#include <avr/io.h>

#ifndef LEDS_H
#define	LEDS_H

#define LED0     PC2
#define LED1     PC7
#define LED2     PD3


void initLEDs(void);
void LED_ON(int LED_NUM);
void LED_OFF(int LED_NUM);
void LED_TOG(int LED_NUM);

#endif	/* LEDS_H */

