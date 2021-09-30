/**
 * @file: Blink_LED_A3.c
 * @brief: three functions have been implemented
 * including the main() function namely
 * Touch_Change_Color_On() and Touch_Change_Color_Off()
 *
 * @author: Harshwardhan Singh
 * @date: September 26th 2021
 * @tools: MCUXpresso IDE and FRDM-KL25Z Development Board
 * @Credits: Embedded Systems Fundamentals with
 * Arm Cortex-M based Microcontrollers (Textbook)
 * by Alexander G.Dean and
 * Howdy Pierce's lecture notes
 */

#include <stdio.h>
#include "common.h"
#include "touch.h"
#include "led.h"
#include "log.h"
#include "delay.h"

uint32_t touch_val = 0;
color_e color = WHITE;

/**
 * @brief: function is used to change the
 * color of the LED according to the value extracted
 * from the capacitive sensor and poll the sensor
 * every 100 milliseconds (msec) when the LED
 * is in ON state.
 *
 * @param: NULL
 * @return: returns NULL
 */
void Touch_Change_Color_On()
{
	touch_val = Touch_Scan_Lh();
	if(touch_val>=650 && touch_val<=850)
	{
		LOG("SLIDER VALUE %d",touch_val);
		color = RED; // color changes to RED
		LOG("\nCHANGE LED TO RED\n");
	}
	else if(touch_val>850 && touch_val<=1300)
	{
		LOG("SLIDER VALUE %d",touch_val);
		color = GREEN; // color changes to GREEN
		LOG("\nCHANGE LED TO GREEN\n");
	}
	else if(touch_val>1300)
	{
		LOG("SLIDER VALUE %d",touch_val);
		color = BLUE; // color changes to BLUE
		LOG("\nCHANGE LED TO BLUE\n");
	}
	Led_Choice(color); //turns on the respective LED
	delay(100);
}

/**
 * @brief: function is used to change the
 * color of the LED according to the value extracted
 * from the capacitive sensor and poll the sensor
 * every 100 milliseconds (msec) when the LED
 * is in OFF state.
 *
 * @param: NULL
 * @return: returns NULL
 */
void Touch_Change_Color_Off()
{
	touch_val = Touch_Scan_Lh();
	if(touch_val>=650 && touch_val<=850)
	{
		LOG("SLIDER VALUE %d",touch_val);
		color = RED;
		LOG("\nCHANGE LED TO RED\n");
	}
	else if(touch_val>850 && touch_val<=1300)
	{
		LOG("SLIDER VALUE %d",touch_val);
		color = GREEN;
		LOG("\nCHANGE LED TO GREEN\n");
	}
	else if(touch_val>1300)
	{
		LOG("SLIDER VALUE %d",touch_val);
		color = BLUE;
		LOG("\nCHANGE LED TO BLUE\n");
	}
	delay(100);
}

/**
 * @brief: main() function executes the
 * complete LED blinking sequence along
 * with the implementation of touch
 * capacitive sensor for controlling the
 * LED change sequence.
 *
 * @param: NULL
 * @return: executes the program and result
 * can be seen on the development board
 * after building and uploading the program
 * on the board.
 */
int main(void)
{
	Touch_Init();
	Led_Init();

	Led_Choice(RED); // turns on RED LED for 500msec
	delay(500);
	Led_Choice(OFF); // turns off RED LED for 100msec
	delay(100);

	Led_Choice(GREEN); // turns on GREEN LED for 500msec
	delay(500);
	Led_Choice(OFF); // turns off GREEN LED for 100msec
	delay(100);

	Led_Choice(BLUE); // turns on BLUE LED for 500msec
	delay(500);
	Led_Choice(OFF); // turns off BLUE LED for 100msec
	delay(100);

	Led_Choice(WHITE); // turns on WHITE LED for 100msec
	delay(100);
	Led_Choice(OFF); // turns off WHITE LED for 100msec
	delay(100);

	Led_Choice(WHITE); // turns on WHITE LED for 100msec
	delay(100);
	Led_Choice(OFF); // turns off WHITE LED for 100msec
	delay(100);

	while(1)
	{
		LOG("START TIMER 500\n");
		for(int i=0; i<5; i++) // turns on the LED for 500msec
		{
			Touch_Change_Color_On();
		}

		Led_Choice(OFF);
		for(int i=0; i<5; i++) // turns off the LED for 500msec
		{
			Touch_Change_Color_Off();
		}

		LOG("START TIMER 1000\n");
		for(int i=0; i<10; i++) // turns on the LED for 1000msec
		{
			Touch_Change_Color_On();
		}

		Led_Choice(OFF);
		for(int i=0; i<5; i++) // turns off the LED for 500msec
		{
			Touch_Change_Color_Off();
		}

		LOG("START TIMER 2000\n");
		for(int i=0; i<20; i++) // turns on the LED for 2000msec
		{
			Touch_Change_Color_On();
		}

		Led_Choice(OFF);
		for(int i=0; i<5; i++) // turns off the LED for 500msec
		{
			Touch_Change_Color_Off();
		}

		LOG("START TIMER 3000\n"); // turns on the LED for 3000msec
		for(int i=0; i<30; i++)
		{
			Touch_Change_Color_On();
		}

		Led_Choice(OFF);
		for(int i=0; i<5; i++) // turns off the LED for 500msec
		{
			Touch_Change_Color_Off();
		}
	}
		return 0;
}
