/* 
 * File:   mTimer.h
 * Author: hossa
 *
 * Created on August 24, 2024, 8:12 PM
 */

#ifndef MTIMER_H
#define	MTIMER_H

#include <avr/io.h>

#define OC0     PB3
#define OC2     PD7

#define BTN_INC PB6
#define BTN_DEC PB7

#define OC0_Disable 0
#define OC0_CTC_TOGGLE  1
#define OC0_CTC_CLEAR   2
#define OC0_CTC_SET     3  

#define OC2_Disable 0
#define OC2_CTC_TOGGLE  1
#define OC2_CTC_CLEAR   2
#define OC2_CTC_SET     3  



#define OC0_PWM_CLEAR_UP  2
#define OC0_PWM_SET_UP    3

#define OC0_FPWM_CLEAR  2
#define OC0_FPWM_SET    3


#define OC2_PWM_CLEAR_UP  2
#define OC2_PWM_SET_UP    3

#define OC2_FPWM_CLEAR  2
#define OC2_FPWM_SET    3

#define clockSelect_Timer_OFF         0
#define clockSelect_Clk_io            1
#define clockSelect_Clk_io_8          2
#define clockSelect_Clk_io_64         3
#define clockSelect_Clk_io_256        4
#define clockSelect_Clk_io_1024       5
#define clockSelect_EXT_CLK_Falling   6
#define clockSelect_EXT_CLK_Rising    7

#define Timer_mode_Normal             0
#define Timer_mode_CTC                1
#define Timer_mode_PWM                2
#define Timer_mode_FPWM               3

#define Timer0_OCR0_val              254
#define Timer2_OCR2_val              10

void init_Timer0(char Timer_mode, char clockSelect);
void Timer0_selectMode(char Timer_mode);
void Timer0_selectCLK(char clockSelect);
void Timer0_TOV_INT_Enable();
void Timer0_COMP_INT_Enable();
void Timer0_OC0_init();
void Timer0_OC0_select_mode(int OC0_mode);

void init_Timer2(char Timer_mode, char clockSelect);
void Timer2_selectMode(char Timer_mode);
void Timer2_selectCLK(char clockSelect);
void Timer2_TOV_INT_Enable();
void Timer2_COMP_INT_Enable();
void Timer2_OC2_init();
void Timer2_OC2_select_mode(int OC2_mode);


#endif	/* MTIMER_H */

