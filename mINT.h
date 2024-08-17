/* 
 * File:   mINT.h
 * Author: hossa
 *
 * Created on August 17, 2024, 8:29 PM
 */

#ifndef MINT_H
#define	MINT_H

#define INT_LOW_LEVEL       0
#define INT_ANY_CHANGE      1
#define INT_FALLING_EDGE    2
#define INT_RISING_EDGE     3

void INT0_selectMode(char INT_Mode);
void init_INT0(char MODE);
void INT0_disable();

void INT1_selectMode(char INT_Mode);
void init_INT1(char MODE);
void INT1_disable();

void INT2_selectMode(char INT_Mode);
void init_INT2(char INT_Mode);
void INT2_disable();
#endif	/* MINT_H */

