/* 
 * File:   output_devices.h
 * Author: hossa
 *
 * Created on August 9, 2024, 7:58 PM
 */

#ifndef OUTPUT_DEVICES_H
#define	OUTPUT_DEVICES_H

#define  BUZZER  PA3
#define  RELAY   PA2


void init_relay();
void relay_on();
void relay_off();

void init_buzzer();
void buzzer_on();
void buzzer_off();
#endif	/* OUTPUT_DEVICES_H */

