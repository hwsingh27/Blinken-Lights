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
 * @brief: function is used to set the
 * clock for TSI and set the configurations
 * for TSI
 *
 * @param: NULL
 * @return: returns NULL
 */
void Touch_Init()
{
	SIM->SCGC5 |= SIM_SCGC5_TSI_MASK;

	TSI0->GENCS = TSI_GENCS_MODE(0u) |
			TSI_GENCS_REFCHRG(0u) |
			TSI_GENCS_DVOLT(0u) |
			TSI_GENCS_EXTCHRG(0u) |
			TSI_GENCS_PS(0u) |
			TSI_GENCS_NSCN (31u) |
			TSI_GENCS_TSIEN_MASK |
			TSI_GENCS_EOSF_MASK;
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
	unsigned int scan=0;
	TSI0->DATA = TSI_DATA_TSICH(10u);
	TSI0->DATA |= TSI_DATA_SWTS_MASK;
	while(!(TSI0->GENCS & TSI_GENCS_EOSF_MASK));
	scan = TSI0->DATA & 0xFFFF;
	TSI0->GENCS |= TSI_GENCS_EOSF_MASK;
	return scan;
}
