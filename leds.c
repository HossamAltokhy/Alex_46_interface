#include "DIO.h"
#include "leds.h"

void initLEDs(void) {
    //    DDRC |= (1<<PC2);
    //    DDRC |= (1<<PC7);
    //    DDRD |= (1<<PD3);
//    setPINC_DIR(LED0, OUT);
//    setPINC_DIR(LED1, OUT);
    setPORTC_DIR_VAL((1<<LED0)|(1<<LED1), OUT);
    setPIND_DIR(LED2, OUT);
}

void LED_ON(int LED_NUM){
    switch(LED_NUM){
        case LED0:
            setPINC(LED0, HIGH);
            break;
        case LED1:
            setPINC(LED1, HIGH);
            break;
        case LED2:
            setPIND(LED2, HIGH);
            break;
    }
}
void LED_OFF(int LED_NUM){
    switch(LED_NUM){
        case LED0:
            setPINC(LED0, LOW);
            break;
        case LED1:
            setPINC(LED1, LOW);
            break;
        case LED2:
            setPIND(LED2, LOW);
            break;
    }
}