/* 
 * File:   DIO.h
 * Author: hossa
 *
 * Created on August 3, 2024, 6:51 PM
 */

#ifndef DIO_H
#define	DIO_H


#define OUT      1
#define IN       0

#define HIGH     1
#define LOW      0

#define ON       1
#define OFF      0

void setPORTA_DIR_VAL(int val, int state);
void setPORTB_DIR_VAL(int val, int state);
void setPORTC_DIR_VAL(int val, int state);
void setPORTD_DIR_VAL(int val, int state);

void setPINA_DIR(int pinNum, int state);
void setPINB_DIR(int pinNum, int state);
void setPINC_DIR(int pinNum, int state);
void setPIND_DIR(int pinNum, int state);

void setPINA(int pinNUM, int status);
void setPINB(int pinNUM, int status);
void setPINC(int pinNUM, int status);
void setPIND(int pinNUM, int status);

void setPORTA_VAL(int val);
void setPORTB_VAL(int val);
void setPORTC_VAL(int val);
void setPORTD_VAL(int val);

char readPORTA();
char readPORTB();
char readPORTC();
char readPORTD();

char readPINA(int pinNUM);
char readPINB(int pinNUM);
char readPINC(int pinNUM);
char readPIND(int pinNUM);

#endif	/* DIO_H */

