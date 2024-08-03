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
/**
 * 
 * @param pinNum pin number
 * @param state (IN , OUT) options
 * @return void
 */
void setPINC_DIR(int pinNum, int state) ;

/**
 * 
 * @param pinNum
 * @param state
 * @return 
 */
void setPINA_DIR(int pinNum, int state);
void setPIND_DIR(int pinNum, int state);

void setPINC(int pinNUM, int status);
void setPIND(int pinNUM, int status);
#endif	/* DIO_H */

