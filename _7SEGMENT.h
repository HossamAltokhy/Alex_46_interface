/* 
 * File:   _7SEGMENT.h
 * Author: hossa
 *
 * Created on September 21, 2024, 8:22 PM
 */

#ifndef _7SEGMENT_H
#define	_7SEGMENT_H

#define _7SEGMENT_DIR   DDRA
#define _7SEGMENT       PORTA

#define _7SEGMENT_EN_DIR   DDRB
#define _7SEGMENT_EN       PORTB
#define EN1        PB1
#define EN2        PB2





void init_7SEG();

void _7SEG_EN1();

void _7SEG_EN2();

void set_7SEG_1(char num);

void set_7SEG_2(char num);

void set_7SEG(char num);


#endif	/* _7SEGMENT_H */

