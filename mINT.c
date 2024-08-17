#include <avr/interrupt.h>
#include "mINT.h"


void INT0_selectMode(char INT_MODE) {
    switch (INT_MODE) {
        case INT_LOW_LEVEL:
            MCUCR &= ~((1 << ISC01) | (1 << ISC00));
            break;
        case INT_ANY_CHANGE:
            MCUCR |= (1 << ISC00);
            MCUCR &= ~(1 << ISC01);
            break;
        case INT_FALLING_EDGE:
            MCUCR |= (1 << ISC01);
            MCUCR &= ~(1 << ISC00);
            break;
        case INT_RISING_EDGE:
            MCUCR |=((1 << ISC01) | (1 << ISC00));
            break;
    }
}


void init_INT0(char MODE){

    //Select Mode
    INT0_selectMode(MODE);
    
    //Enable INT0
    GICR |= (1<<INT0);
    
}

void INT0_disable(){
    GICR &= ~(1<<INT0);
}

void INT1_selectMode(char INT_MODE) {
    switch (INT_MODE) {
        case INT_LOW_LEVEL:
            MCUCR &= ~((1 << ISC11) | (1 << ISC10));
            break;
        case INT_ANY_CHANGE:
            MCUCR |= (1 << ISC10);
            MCUCR &= ~(1 << ISC11);
            break;
        case INT_FALLING_EDGE:
            MCUCR |= (1 << ISC11);
            MCUCR &= ~(1 << ISC10);
            break;
        case INT_RISING_EDGE:
            MCUCR |=((1 << ISC11) | (1 << ISC10));
            break;
    }
}


void init_INT1(char MODE){

    //Select Mode
    INT1_selectMode(MODE);
    
    //Enable INT0
    GICR |= (1<<INT1);
    
}

void INT1_disable(){
    GICR &= ~(1<<INT1);
}


void INT2_selectMode(char INT_Mode){
    switch(INT_Mode){
        case INT_FALLING_EDGE:
            MCUCSR &= ~(1<<ISC2);
            break;
        case INT_RISING_EDGE:
            MCUCSR |= (1<<ISC2);
            break;
    }
}
void init_INT2(char INT_Mode){
    INT2_selectMode(INT_Mode);
    GICR |= (1<<INT2);
}
void INT2_disable(){
    GICR &= ~(1<<INT2);
}
