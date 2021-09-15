/*
 * button.c
 *
 *  Created on: Jul 18, 2016
 *      Author: Eric Middleton, Zhao Zhang, Chad Nelson, & Zachary Glanz.
 *
 *  @edit: Lindsey Sleeth and Sam Stifter on 02/04/2019
 *  @edit: Phillip Jone 05/30/2019: Mearged Spring 2019 version with Fall 2018
 */
 


//The buttons are on PORTE 3:0
// GPIO_PORTE_DATA_R -- Name of the memory mapped register for GPIO Port E, 
// which is connected to the push buttons
#include "button.h"


/**
 * Initialize PORTE and configure bits 0-3 to be used as inputs for the buttons.
 */
void button_init() {
	static uint8_t initialized = 0;

	//Check if already initialized
	if(initialized){
		return;
	}

	// delete warning after implementing 
	
	// Reading: To initialize and configure GPIO PORTE, visit pg. 656 in the 
	// Tiva datasheet.
	
	// Follow steps in 10.3 for initialization and configuration. Some steps 
	// have been outlined below.
	
	// Ignore all other steps in initialization and configuration that are not 
	// listed below. You will learn more about additional steps in a later lab.

	// 1) Turn on PORTE system clock, do not modify other clock enables
	SYSCTL_RCGCGPIO_R |= 0b010000;

	// 2) Set the buttons as inputs, do not modify other PORTE wires
	GPIO_PORTE_DIR_R &= 0xFFF0;
	
	// 3) Enable digital functionality for button inputs, 
	//    do not modify other PORTE enables
	GPIO_PORTE_DEN_R |= 0x000F;

	
	initialized = 1;
}



/**
 * Returns the position of the leftmost button being pushed.
 * @return the position of the leftmost button being pushed. 4 is the leftmost button, 1 is the rightmost button.  0 indicates no button being pressed
 */
uint8_t button_getButton() {

    uint8_t mask = 8;
    uint8_t button = GPIO_PORTE_DATA_R;
    button = ~button;
    uint8_t buttonReturn;
    for(buttonReturn=4;buttonReturn>0; buttonReturn--) {
        if((button & mask)) {
            return buttonReturn;
        }
        mask = mask >> 1;
    }
	
	// INSERT CODE HERE!
	
	return 0; // EDIT ME
}





