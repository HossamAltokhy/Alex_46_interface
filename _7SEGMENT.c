#define F_CPU 16000000UL
#include <util/delay.h>

#include "_7SEGMENT.h"
#include <avr/io.h>

void init_7SEG() {
    _7SEGMENT_DIR |= (1 << PA4) | (1 << PA5) | (1 << PA6) | (1 << PA7);
    _7SEGMENT_EN_DIR |= (1 << PB3) | (1 << PB2) | (1 << PB1);

}

void _7SEG_EN1() {

    _7SEGMENT_EN &= ~(1 << EN2);
    _7SEGMENT_EN |= (1 << EN1);

}

void _7SEG_EN2() {
    _7SEGMENT_EN &= ~(1 << EN1);
    _7SEGMENT_EN |= (1 << EN2);
}

void set_7SEG_1(char num) {
    _7SEG_EN1();
    _7SEGMENT &= 0x0F;
    _7SEGMENT |= num << 4;

}

void set_7SEG_2(char num) {
    _7SEG_EN2();
    _7SEGMENT &= 0x0F;
    _7SEGMENT |= num << 4;

}

void set_7SEG(char num) {
    set_7SEG_1(num%10);
    _delay_ms(5);
    set_7SEG_2(num/10);
    _delay_ms(5);
}


