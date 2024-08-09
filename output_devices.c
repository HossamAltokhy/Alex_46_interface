#include <avr/io.h>
#include "DIO.h"
#include "output_devices.h"



void init_relay(){
    setPINA_DIR(RELAY, OUT);
}
void relay_on(){
    setPINA(RELAY, HIGH);
}
void relay_off(){
    setPINA(RELAY, LOW);
}

void init_buzzer(){
    setPINA_DIR(BUZZER, OUT);
}
void buzzer_on(){
    setPINA(BUZZER, HIGH);
}
void buzzer_off(){
        setPINA(BUZZER, LOW);

}