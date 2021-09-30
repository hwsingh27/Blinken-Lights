/**@file: led.c
 * @brief: two functions have been implemented
 * namely Led_Init() and Led_Choice() to set the
 * pin configurations for red, green and blue LED
 * and for switching ON and OFF the LED respectively.
 * Defined macros for pin configuration.
 *
 * @author: Harshwardhan Singh
 * @date: September 26th 2021
 * @tools: MCUXpresso IDE and FRDM-KL25Z Development Board
 * @Credits: Embedded Systems FUndamentals with
 * Arm Cortex-M based Microcontrollers (Textbook)
 * by Alexander G.Dean and
 * Howdy Pierce's lecture notes
 */

#include <stdio.h>
#include "common.h"

#define PORT_PCR_MUX_PIN (8)
#define RED_LED_PIN (18)
#define GREEN_LED_PIN (19)
#define BLUE_LED_PIN (1)

/**
 * @brief: function includes commands to set
 * the clock to PORT-B and PORT-D. Includes commands
 * to make three pins GPIO and set LED bits to outputs.
 *
 * @param: NULL
 * @return: returns NULL as the function is used to
 * configure LED pins
 */
void Led_Init(void)
{
	SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTD_MASK;

	PORTB->PCR[RED_LED_PIN] &= ~PORT_PCR_MUX_MASK;
	PORTB->PCR[RED_LED_PIN] |= (1 << PORT_PCR_MUX_PIN);

	GPIOB->PDDR |= (1 << RED_LED_PIN);
	GPIOB->PSOR |= (1 << RED_LED_PIN);

	PORTB->PCR[GREEN_LED_PIN] &= ~PORT_PCR_MUX_MASK;
	PORTB->PCR[GREEN_LED_PIN] |= (1 << PORT_PCR_MUX_PIN);

	GPIOB->PDDR |= (1 << GREEN_LED_PIN);
	GPIOB->PSOR |= (1 << GREEN_LED_PIN);

	PORTD->PCR[BLUE_LED_PIN] &= ~PORT_PCR_MUX_MASK;
	PORTD->PCR[BLUE_LED_PIN] |= (1 << PORT_PCR_MUX_PIN);

	GPIOD->PDDR |= (1 << BLUE_LED_PIN);
	GPIOD->PSOR |= (1 << BLUE_LED_PIN);
}

/**
 * @brief: function is used to turn ON and OFF the LED
 * PCOR is for turning ON LED and PSOR turns OFF the LED.
 *
 * @param: enum color_e is passed to select the color
 * of LEDs accordingly and for turning OFF the LEDs
 * @return: returns NULL as the function is used to
 * unable and disable red, green and blue LEDs.
 */
void Led_Choice(color_e col)
{
	switch(col)
	{
	case RED:
		GPIOB->PCOR |= (1 << RED_LED_PIN); // turning on RED LED
		GPIOB->PSOR |= (1 << GREEN_LED_PIN); // turning off GREEN LED
		GPIOD->PSOR |= (1 << BLUE_LED_PIN); // turning off BLUE LED
		break;
	case GREEN:
		GPIOB->PCOR |= (1 << GREEN_LED_PIN); // turning on GREEN LED
		GPIOB->PSOR |= (1 << RED_LED_PIN); // turning off RED LED
		GPIOD->PSOR |= (1 << BLUE_LED_PIN); // turning off BLUE LED
		break;
	case BLUE:
		GPIOD->PCOR |= (1 << BLUE_LED_PIN); // turning on BLUE LED
		GPIOB->PSOR |= (1 << RED_LED_PIN); // turning off RED LED
		GPIOB->PSOR |= (1 << GREEN_LED_PIN); // turning off GREEN LED
		break;
	case WHITE:
		GPIOB->PCOR |= (1 << RED_LED_PIN); // turning on RED LED
		GPIOB->PCOR |= (1 << GREEN_LED_PIN); // turning on GREEN LED
		GPIOD->PCOR |= (1 << BLUE_LED_PIN); // turning on BLUE LED
		break;
	case OFF:
		GPIOB->PSOR |= (1 << RED_LED_PIN); // turning off RED LED
		GPIOB->PSOR |= (1 << GREEN_LED_PIN); // turning off GREEN LED
		GPIOD->PSOR |= (1 << BLUE_LED_PIN); // turning off BLUE LED
		break;
	}
}
