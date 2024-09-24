#include <avr/io.h>
#include "DIO.h"
#include "mTimer.h"

void init_Timer0(char Timer_mode, char clockSelect) {

    // Selecting Timer0 Mode
    Timer0_selectMode(Timer_mode);

    // Selecting Clock 
    Timer0_selectCLK(clockSelect);
}

void Timer0_selectMode(char Timer_mode) {
    switch (Timer_mode) {
        case Timer_mode_Normal:
            TCCR0 &= ~((1 << WGM00) | (1 << WGM01));
            Timer0_TOV_INT_Enable();
            break;
        case Timer_mode_CTC:
            OCR0 = Timer0_OCR0_val;
            TCCR0 &= ~(1 << WGM00);
            TCCR0 |= (1 << WGM01);
            Timer0_COMP_INT_Enable();
            break;
        case Timer_mode_PWM:
            OCR0 = Timer0_OCR0_val;
            TCCR0 &= ~(1 << WGM01);
            TCCR0 |= (1 << WGM00);
            break;
        case Timer_mode_FPWM:
            OCR0 = Timer0_OCR0_val;
            TCCR0 |= (1 << WGM01);
            TCCR0 |= (1 << WGM00);
            break;
    }
}

void Timer0_selectCLK(char clockSelect) {
    TCCR0 &= ~((1 << CS02) | (1 << CS01) | (1 << CS00));
    TCCR0 |= clockSelect;
}

void Timer0_TOV_INT_Enable() {
    TIMSK |= (1 << TOIE0);
}

void Timer0_COMP_INT_Enable() {
    TIMSK |= (1 << OCIE0);
}

void Timer0_OC0_init() {
    setPINB_DIR(OC0, OUT);
}

void Timer0_OC0_select_mode(int OC0_mode) {
    TCCR0 &= ~((1 << COM01) | (1 << COM00));
    TCCR0 |= (OC0_mode << COM00);
}









void init_Timer2(char Timer_mode, char clockSelect) {

    // Selecting Timer0 Mode
    Timer2_selectMode(Timer_mode);

    // Selecting Clock 
    Timer2_selectCLK(clockSelect);
}

void Timer2_selectMode(char Timer_mode) {
    switch (Timer_mode) {
        case Timer_mode_Normal:
            TCCR2 &= ~((1 << WGM20) | (1 << WGM21));
            Timer2_TOV_INT_Enable();
            break;
        case Timer_mode_CTC:
            OCR2 = Timer2_OCR2_val;
            TCCR2 &= ~(1 << WGM20);
            TCCR2 |= (1 << WGM01);
            Timer2_COMP_INT_Enable();
            break;
        case Timer_mode_PWM:
            OCR2 = Timer2_OCR2_val;
            TCCR2 &= ~(1 << WGM21);
            TCCR2 |= (1 << WGM20);
            break;
        case Timer_mode_FPWM:
            OCR2 = Timer2_OCR2_val;
            TCCR2 |= (1 << WGM21);
            TCCR2 |= (1 << WGM20);
            break;
    }
}

void Timer2_selectCLK(char clockSelect) {
    TCCR2 &= ~((1 << CS22) | (1 << CS21) | (1 << CS20));
    TCCR2 |= clockSelect;
}

void Timer2_TOV_INT_Enable() {
    TIMSK |= (1 << TOIE2);
}

void Timer2_COMP_INT_Enable() {
    TIMSK |= (1 << OCIE2);
}

void Timer2_OC2_init() {
    setPIND_DIR(OC2, OUT);
}

void Timer2_OC2_select_mode(int OC2_mode) {
    TCCR2 &= ~((1 << COM21) | (1 << COM20));
    TCCR2 |= (OC2_mode << COM20);
}
