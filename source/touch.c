/**@file: touch.c
 * @brief: two functions have been implemented
 * namely Touch_Init() and Touch_Scan_Lh()
 * to set the clock and configure TSI.
 * Function is used to scan the value from the
 * touch sensor.
 *
 * @author: Harshwardhan Singh
 * @date: September 26th 2021
 * @tools: MCUXpresso IDE and FRDM-KL25Z Development Board
 * @Credits: Embedded Systems Fundamentals with
 * Arm Cortex-M based Microcontrollers (Textbook)
 * by Alexander G.Dean and GitHub repo
 * @Link: https://github.com/alexander-g-dean/ESF/tree/
 * master/NXP/Misc/Touch%20Sense/TSI/src
 */

#include "common.h"

/**
 * name of the function
 * @brief: function is used to set the
 * clock for TSI and set the configurations
 * for TSI
 *
 * @param: NULL
 * @return: returns NULL
 */
void Touch_Init(void)
{
	SIM->SCGC5 |= SIM_SCGC5_TSI_MASK;

	TSI0->GENCS = TSI_GENCS_MODE(0u) | //operating in non-noise mode
			TSI_GENCS_REFCHRG(0u) | //reference oscillator charge and discharge value 500nA
			TSI_GENCS_DVOLT(0u) | // oscillator voltage rails set to default
			TSI_GENCS_EXTCHRG(0u) | // electrode oscillator charge and discharge value 500nA
			TSI_GENCS_PS(0u) | // frequency clock divided by one
			TSI_GENCS_NSCN (31u) | // scanning the electrode 32 times
			TSI_GENCS_TSIEN_MASK | //enabling the TSI module
			TSI_GENCS_EOSF_MASK; // writing one to clear the end of scan flag
}

/**
 * @brief: function is used to extract the value
 * form the touch capacitive sensor and stores
 * the value in scan variable.
 *
 * @param: NULL
 * @return: returns the touch sensor value
 * through scan variable.
 */
int Touch_Scan_Lh(void)
{
	unsigned int scan=0; // initializing the value of scan as '0'
	TSI0->DATA = TSI_DATA_TSICH(10u); // selecting channel 10
	TSI0->DATA |= TSI_DATA_SWTS_MASK; // software trigger to start the scan
	while(!(TSI0->GENCS & TSI_GENCS_EOSF_MASK)); //waiting for the scan to complete 32 times
	scan = TSI0->DATA & 0xFFFF; // macro for extracting the count from data register
	TSI0->GENCS |= TSI_GENCS_EOSF_MASK; // writing one to clear the end of the flag
	return scan;
}
