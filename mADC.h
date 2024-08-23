/* 
 * File:   mADC.h
 * Author: hossa
 *
 * Created on August 23, 2024, 8:57 PM
 */

#ifndef MADC_H
#define	MADC_H


#define ADC_STEP 4.887585532746823069403714565

#define CH0     0
#define CH1     1
#define CH2     2
#define CH3     3
#define CH4     4
#define CH5     5
#define CH6     6
#define CH7     7

#define CH2_CH1 0x12 //10010


#define AREF               0  // 00
#define AVCC               1  // 01
#define INTERAL_VOLTAGE    3  // 11


#define ADC_FREQ_DIV128       7

void init_ADC(char CH, char REF, char FREQ);
void ADC_select_CH(char CH);
void ADC_select_REF(char REF);
void ADC_select_FREQ(char FREQ);
void ADC_SC();
void ADC_EN();
void ADC_INT_EN();
//ADC_AUTO_TRIGGERING(char mode);

#endif	/* MADC_H */

