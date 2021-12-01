#ifndef __ACTIVITY_3_H__
#define __ACTIVITY_3_H__

/**
 * @file activity3.h
 * @author Dantla Datta Kishore 40020713
 * @version 0.1
 * @date 2021-12-01
 * Macro Definitions
 */

#define PWM_20_PERCENT (205) /**< Output PWM for 20% duty cycle */
#define PWM_40_PERCENT (410) /**< Output PWM for 40% duty cycle */
#define PWM_70_PERCENT (717) /**< Output PWM for 70% duty cycle */
#define PWM_95_PERCENT (973) /**< Output PWM for 95% duty cycle */

/**
 * Include files
 */ 

#include <util/delay.h>
#include <avr/io.h>

/**
 * Function Definitions
 */

void InitTimer();
void activity3_PWM(uint16_t temp);

#endif /* __ACTIVITY_3_H__ */
