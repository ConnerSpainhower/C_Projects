

/**
 * main.c
 */

#include "adc.h"
#include "lcd.h"
#include "timer.h"
#include "resetSimulation.h"


int main(void)
{
   //resetSimulationBoard();
    lcd_init();
    timer_init();
    adc_init();
    sample_init();
    while(1){
        lcd_printf("%d", adc_read());
    }
}
