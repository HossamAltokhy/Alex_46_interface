/* 
 * File:   mTWI.h
 * Author: hossa
 *
 * Created on September 21, 2024, 6:05 PM
 */

#ifndef MTWI_H
#define	MTWI_H


// SLA address   // 0000101
#define SLA_W         0x0A

#define SLA_R         0x0B

#define ERROR    -1



void init_TWI(char TWI_Address, char TWI_CLOCK);
char TWI_M_Transmit(char SLA, char data);
char TWI_M_Receive(char SLA);

char TWI_M_Transmit_buf(char SLA, char* pData, char array_sz);
char* TWI_M_Receive_buf(char SLA, char array_sz);

char TWI_S_Transmit(char data);
char TWI_S_Receive();
char* TWI_S_Receieve_buf();

#endif	/* MTWI_H */

