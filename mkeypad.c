#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include "leds.h"
#include "DIO.h"
#include "mkeypad.h"

void init_keypad() {
    Keypad_PORT_DIR = 0x07;
    Keypad_PORT |= 0x07;
}

char readKey() {
Keypad_PORT |= 0x07;
    while (1) {

        if (readPORTA() & 0x10) {
            // there is num is clicked
            Keypad_PORT &= 0xF8;
            Keypad_PORT |= (1 << 2);
            _delay_us(1000);
            if (readPORTA() & 0x10) {
                Keypad_PORT &= 0xF8;
                Keypad_PORT |= 0x07;
                _delay_us(1000);
                return '1';
            } else {
                Keypad_PORT &= 0xF8;
                Keypad_PORT |= (1 << 1);
                _delay_us(500);
                if (readPORTA() & 0x10) {
                    Keypad_PORT &= 0xF8;
                    Keypad_PORT |= 0x07;
                    _delay_us(500);
                    return '2';
                } else {
                    Keypad_PORT &= 0xF8;
                    Keypad_PORT |= 0x07;
                    _delay_us(500);
                    return '3';
                }
            }


        } else if (readPORTA() & 0x20) {
            // there is num is clicked

            Keypad_PORT &= 0xF8;
            Keypad_PORT |= (1 << 2);
            _delay_us(500);
            if (readPORTA() & 0x20) {
                Keypad_PORT &= 0xF8;
                Keypad_PORT |= 0x07;
                _delay_us(500);
                return '4';
            } else {
                Keypad_PORT &= 0xF8;
                Keypad_PORT |= (1 << 1);
                _delay_us(500);
                if (readPORTA() & 0x20) {
                    Keypad_PORT &= 0xF8;
                    Keypad_PORT |= 0x07;
                    _delay_us(500);
                    return '5';
                } else {
                    Keypad_PORT &= 0xF8;
                    Keypad_PORT |= 0x07;
                    _delay_us(500);
                    return '6';
                }
            }


        } else if (readPORTA() & 0x40) {
            // there is num is clicked

            Keypad_PORT &= 0xF8;
            Keypad_PORT |= (1 << 2);
            _delay_us(500);
            if (readPORTA() & 0x40) {
                Keypad_PORT &= 0xF8;
                Keypad_PORT |= 0x07;
                _delay_us(500);
                return '7';
            } else {
                Keypad_PORT &= 0xF8;
                Keypad_PORT |= (1 << 1);
                _delay_us(500);
                if (readPORTA() & 0x40) {
                    Keypad_PORT &= 0xF8;
                    Keypad_PORT |= 0x07;
                    _delay_us(500);
                    return '8';
                } else {
                    Keypad_PORT &= 0xF8;
                    Keypad_PORT |= 0x07;
                    _delay_us(500);
                    return '9';
                }
            }


        } else if (readPORTA() & 0x80) {
            // there is num is clicked

            Keypad_PORT &= 0xF8;
            Keypad_PORT |= (1 << 2);
            _delay_us(500);
            if (readPORTA() & 0x80) {
                Keypad_PORT &= 0xF8;
                Keypad_PORT |= 0x07;
                _delay_us(500);
                return '*';
            } else {
                Keypad_PORT &= 0xF8;
                Keypad_PORT |= (1 << 1);
                _delay_us(500);
                if (readPORTA() & 0x80) {
                    Keypad_PORT &= 0xF8;
                    Keypad_PORT |= 0x07;
                    _delay_us(500);
                    return '0';
                } else {
                    Keypad_PORT &= 0xF8;
                    Keypad_PORT |= 0x07;
                    _delay_us(500);
                    return '#';
                }
            }


        }
    }

    return '.';
}

char getKey() {

    Keypad_PORT |= 0x07;
    while (1) {
        if (readPORTA() & 0xF0) {
            Keypad_PORT &= 0xF8;
            Keypad_PORT |= (1 << 0);
            _delay_ms(5);
            if (readPORTA() & 0x10) {
                _delay_us(500);
                return '3';
            } else if (readPORTA() & 0x20) {
                _delay_us(500);
                return '6';
            } else if (readPORTA() & 0x40) {
                _delay_us(500);
                return '9';
            } else if (readPORTA() & 0x80) {
                _delay_us(500);
                return '#';
            } else {
                //Do nothing
                Keypad_PORT &= 0xF8;
                Keypad_PORT |= (1 << 1);
                _delay_ms(5);
                if (readPORTA() & 0x10) {
                    _delay_us(500);
                    return '2';
                } else if (readPORTA() & 0x20) {
                    _delay_us(500);
                    return '5';
                } else if (readPORTA() & 0x40) {
                    _delay_us(500);
                    return '8';
                } else if (readPORTA() & 0x80) {
                    _delay_us(500);
                    return '0';
                } else {
                    //Do nothing
                    Keypad_PORT &= 0xF8;
                    Keypad_PORT |= (1 << 2);
                    _delay_ms(5);
                    if (readPORTA() & 0x10) {
                        _delay_us(500);
                        return '1';
                    } else if (readPORTA() & 0x20) {
                        _delay_us(500);
                        return '4';
                    } else if (readPORTA() & 0x40) {
                        _delay_us(500);
                        return '7';
                    } else if (readPORTA() & 0x80) {
                        _delay_us(500);
                        return '*';
                    } else {

                    }
                }
            }




        }
        _delay_ms(20);
        Keypad_PORT |= 0x07;
    }

    return '.';
}