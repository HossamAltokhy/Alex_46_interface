#define F_CPU 16000000UL

#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>

#include "mUART.h"
#include "DIO.h"

void init_UART(int BaudRate){
//    short temp = (F_CPU/16.0/BaudRate)-1;  // Async Mode
    short temp = (F_CPU/2.0/BaudRate)-1;     // Sync Mode
    UBRRL = temp;
    UBRRH = temp>>8;
    // Set MODE to Sync Master Mode
    UCSRC |= (1<<URSEL)|(1<<UMSEL)|(1<<USBS);
    // Set DDRB for XCK
    setPINB_DIR(PB0, OUT);
    _delay_ms(5);
    // Enable Tx,Rx
    UCSRB |= (1<<TXEN);//|(1<<RXEN);
    
}
void UART_send(char data){
    while(!(UCSRA & (1<<UDRE)));
        UDR = data;   
}

char UART_receive(){
    while(!(UCSRA& (1<<RXC)));
    return UDR;
}
