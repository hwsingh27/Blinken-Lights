/**@file: led.h
 * @brief: enum color_e has been created to select
 * the color of the LED as well as for turning OFF the
 * LEDs.
 * Two functions have been called namely Led_Init()
 * and Led_Choice()
 *
 * @author: Harshwardhan Singh
 * @date: September 26th 2021
 * @tools: MCUXpresso IDE and FRDM-KL25Z Development Board
 * @Credits: Embedded Systems Fundamentals with
 * Arm Cortex-M based Microcontrollers (Textbook)
 * by Alexander G.Dean
 */

#ifndef LED_H_
#define LED_H_

typedef enum
{
	RED,
	GREEN,
	BLUE,
	WHITE,
	OFF
}color_e;

void Led_Init(void);
void Led_Choice(color_e col);


#endif /* LED_H_ */
