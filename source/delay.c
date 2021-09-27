/**@file: delay.c
 * @brief: execution of the delay() function
 * to set the delay according to the
 * requirement.
 *
 * @author: Harshwardhan Singh
 * @date: September 26th 2021
 * @tools: MCUXpresso IDE and FRDM-KL25Z Development Board
 * @Credits: Embedded Systems Fundamentals with
 * Arm Cortex-M based Microcontrollers (Textbook)
 * by Alexander G.Dean and
 * Howdy Pierce's lecture notes
 */

/**
 * @brief: delay function to set the time delay using
 * nested for loops.
 *
 * @param: passing the time in milliseconds (msec) as integer
 * @return: returns NULL (function is used for the time
 * delay and does not return anything)
 */
void delay(int msec)
{
	int i,j;
	for(i=0;i<msec;i++)
	{
		for(j=0;j<1650;j++)
		{
		}
	}
}
