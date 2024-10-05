/*
 * File:   main.c
 * Author: hossa
 *
 * Created on October 5, 2024, 10:35 AM
 */

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


#include "FreeRTOS/include/FreeRTOS.h"
#include "FreeRTOS/include/FreeRTOSConfig.h"
#include "FreeRTOS/include/task.h"
#include "drivers/include/mUART.h"

#include "FreeRTOS/include/queue.h"
#include "drivers/include/mADC.h"


TaskHandle_t Task1Handler = NULL;
TaskHandle_t Task2Handler = NULL;


char arr1[] = "Task1\r";
char arr2[] = "Task2\r";

QueueHandle_t QueueHandler = NULL;

void function1(void *ptr) {
    int data = 0;
    while (1) {

        ADC_SC();
        ADC_wait();
        data = ADC_read() * ADC_step;
        xQueueSendToFront(QueueHandler,(void *) &data, 2);

    }
    vTaskDelete(NULL);
}

void function2(void *ptr) {

    int receivedData = 0;
    while (1) {
        xQueueReceive(QueueHandler, (void*)&receivedData, 2);
        UART_send_num(receivedData);
        
        UART_send('\r');
    }
    vTaskDelete(NULL);
}



int main(void) {
    /* Replace with your application code */
    init_ADC(ADC_CH_0, ADC_Vref_AREF, ADC_PS_128);
    init_UART(9600);
    _delay_ms(50);
    
    QueueHandler = xQueueCreate(3, sizeof(int));
            
    xTaskCreate(function1, "task1", 200, NULL, 1, &Task1Handler);
    xTaskCreate(function2, "task2", 200, NULL, 1, &Task2Handler);



    vTaskStartScheduler();
    while (1) {
    }

    return 0;
}
