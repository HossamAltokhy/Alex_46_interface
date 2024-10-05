#define F_CPU 16000000UL

#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <string.h>
#include <stdlib.h>

#include "mUART.h"
#include "DIO.h"

void init_UART(int BaudRate){
    short temp = (F_CPU/16.0/BaudRate)-1;  // Async Mode
    UBRRL = temp;
    UBRRH = temp>>8;
  
    // Enable Tx,Rx
    UCSRB |= (1<<TXEN)|(1<<RXEN);
    
}
void UART_send(char data){
    while(!(UCSRA & (1<<UDRE)));
        UDR = data;   
}

void UART_num(int num){
    char str[11];
    itoa(num, str, 10);
    UART_send_str(str);
}

void UART_send_str(char * str){
    for(int i =0 ; str[i] != '\0';i++){
        UART_send(str[i]);
    }
}

char UART_receive(){
    while(!(UCSRA& (1<<RXC)));
    return UDR;
}
