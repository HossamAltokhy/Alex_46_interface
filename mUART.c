#define F_CPU 16000000UL
#include "mUART.h"

#include <avr/interrupt.h>
#include <avr/io.h>

void init_UART(int BaudRate){
    short temp = (F_CPU/16.0/BaudRate)-1;
    UBRRL = temp;
    UBRRH = temp>>8;
    
    // Enable Tx,Rx
    UCSRB |= (1<<TXEN)|(1<<RXEN);
    
}
void UART_send(char data){
    while(!(UCSRA & (1<<UDRE)));
        UDR = data;   
}

char UART_receive(){
    while(!(UCSRA& (1<<RXC)));
    return UDR;
}
