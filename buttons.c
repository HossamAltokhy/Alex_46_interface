#include <avr/io.h>
#include "DIO.h"

#include "buttons.h"

void initBTNs(){
    
    setPINB_DIR(BTN0, IN);
    setPIND_DIR(BTN1, IN);
    setPIND_DIR(BTN2, IN);
    
}
char isPressedA(char pinNUM){
    return readPINA(pinNUM);
}
char isPressedB(char pinNUM){
    return readPINB(pinNUM);
}
char isPressedC(char pinNUM){
    return readPINC(pinNUM);
}
char isPressedD(char pinNUM){
    return readPIND(pinNUM);
}
