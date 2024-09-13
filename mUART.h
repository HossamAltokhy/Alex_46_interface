/* 
 * File:   mUART.h
 * Author: hossa
 *
 * Created on September 7, 2024, 5:19 PM
 */

#ifndef MUART_H
#define	MUART_H


#define UART_BAUD_9600  9600

void init_UART(int BaudRate);
void UART_send(char data);
char UART_receive();

#endif	/* MUART_H */

