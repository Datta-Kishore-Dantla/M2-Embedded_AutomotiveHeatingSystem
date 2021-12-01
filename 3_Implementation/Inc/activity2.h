
#ifndef __ACTIVITY_2_H__
#define __ACTIVITY_2_H__

/**
 * Include files
  * @file activity2.h
 * @author Dantla Datta Kishore 40020713
 * @version 0.1
 * @date 2021-12-01
 */ 

#include <util/delay.h>
#include <avr/io.h>

/**
 * Function Definitions
 */

void InitADC();
uint16_t ReadADC(uint8_t ch);
uint16_t activity2_GetADC(void);

#endif /* __ACTIVITY_2_H__ */
