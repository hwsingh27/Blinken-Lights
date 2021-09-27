/**@file: touch.h
 * @brief: two functions have been called
 * namely Touch_Init() and Touch_Scan_Lh();
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

#ifndef TOUCH_H_
#define TOUCH_H_

void Touch_Init();
int Touch_Scan_Lh(void);

#endif /* TOUCH_H_ */
