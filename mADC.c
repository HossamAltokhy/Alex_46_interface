#include <avr/io.h>
#include "mADC.h"

void init_ADC(char CH, char REF, char FREQ) {
    // Select Channel
    ADC_select_CH(CH);
    // Select VREF
    ADC_select_REF(REF);
    // Select FREQ
    ADC_select_FREQ(FREQ);

    // Enable Interrupt If needed
    ADC_INT_EN();

    //ATE
    ADC_AUTO_TRIGGERING(mode_ATE_TIMER0_OVF);
    // Enable ADC Pripheral
    ADC_EN();
}

void ADC_select_CH(char CH) {
    //ADMUX
    ADMUX &= ~((1 << MUX4) | (1 << MUX3) | (1 << MUX2) | (1 << MUX1) | (1 << MUX0));
    ADMUX |= CH;
}

void ADC_select_REF(char REF) {
    ADMUX &= ~((1 << REFS1) | (1 << REFS0));
    ADMUX |= (REF << 6);
}

void ADC_select_FREQ(char FREQ) {
    //ADCSRA
    ADCSRA &= ~((1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0));
    ADCSRA |= FREQ;
}

void ADC_SC() {
    ADCSRA |= (1 << ADSC);
}

void ADC_EN() {
    ADCSRA |= (1 << ADEN);
}

void ADC_INT_EN() {
    ADCSRA |= (1 << ADIE);
}

void ADC_ATE_EN() {
    ADCSRA |= (1 << ADATE);
}

void ADC_AUTO_TRIGGERING(char mode) {
    switch (mode) {
        case mode_ATE_TIMER0_OVF:
            SFIOR |= (mode_ATE_TIMER0_OVF << ADTS0);
            break;
    }

    ADC_ATE_EN();
}
