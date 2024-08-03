
#include <avr/io.h>
#include "DIO.h"
/**
 * 
 * @param pinNum pin number
 * @param state (IN , OUT) options
 * @return void
 */
void setPINC_DIR(int pinNum, int state) {
    switch (state) {
        case IN:
            DDRC &= ~(1<<pinNum);
            break;
        case OUT:
            DDRC |= (1<<pinNum);
            break;
        default:
            break;
    }
}

/**
 * 
 * @param pinNum
 * @param state
 * @return 
 */
void setPINA_DIR(int pinNum, int state) {
    switch (state) {
        case IN:
            DDRA &= ~(1<<pinNum);
            break;
        case OUT:
            DDRA |= (1<<pinNum);
            break;
        default:
            break;
    }
}
void setPIND_DIR(int pinNum, int state) {
    switch (state) {
        case IN:
            DDRD &= ~(1<<pinNum);
            break;
        case OUT:
            DDRD |= (1<<pinNum);
            break;
        default:
            break;
    }
}


void setPINC(int pinNUM, int status){
    switch(status){
        case HIGH:
            PORTC |= (1<<pinNUM);
            break;
        case LOW:
            PORTC &= ~(1<<pinNUM);
            break;
    }
}

void setPIND(int pinNUM, int status){
    switch(status){
        case HIGH:
            PORTD |= (1<<pinNUM);
            break;
        case LOW:
            PORTD &= ~(1<<pinNUM);
            break;
    }
}