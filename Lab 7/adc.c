/*
 * adc.c
 *
 *  Created on: Oct 8, 2020
 *      Author: cspainho
 */
#include "adc.h"
#include <inc/tm4c123gh6pm.h>
#include <stdint.h>
#include <stdbool.h>
#include "driverlib/interrupt.h"


void adc_init(void){
    SYSCTL_RCGCADC_R = 0x1;
    SYSCTL_RCGCGPIO_R = 0b10;
    GPIO_PORTB_AFSEL_R |= 0x10;
   // GPIO_PORTB_AHB_ADCCTL_R &= 0x10;
    GPIO_PORTB_DEN_R &= 0xEF;
   // GPIO_PORTB_DEN_R |= 0b00010000;
    GPIO_PORTB_AMSEL_R |= 0b00010000;
    GPIO_PORTB_DIR_R &= 0xEF;
    GPIO_PORTB_ADCCTL_R = 0x0;
}

void sample_init(void){
    ADC0_ACTSS_R &= 0x7;
    ADC0_EMUX_R &= 0x0FFF;
    //ADC0_EMUX_R |= 0xF000;
    ADC0_SSMUX3_R = 0xA;
    ADC0_SSCTL3_R = 0x6;
    ADC0_ACTSS_R |= 0x8;
}

int adc_read(void){
    ADC0_PSSI_R |= 0x8;
    while((ADC0_RIS_R &= 0x8) != 0x8){
    }
    int c = ADC0_SSFIFO3_R & 0xFFF;
    ADC0_ISC_R |= 0x8;
    return c;
}



