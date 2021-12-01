#ifndef __ACTIVITY_1_H__
#define __ACTIVITY_1_H__

/**
 * @file activity1.h
 * @author Dantla Datta Kishore 40020713
 * @version 0.1
 * @date 2021-12-01
 * Macro Definitions

 */

#define F_CPU 16000000UL 	/**< Clock Frequency of MCU is 16 MHz */
#define LED_PORT (PORTD)    /**< LED Port Number */
#define LED_PIN  (PORTD2)   /**< LED Pin number  */
#define BUTTON_SENSOR  (PORTD0)   /**< Port for Button Sensor  */
#define TEMP_SENSOR  (PORTD1)   /**< Port for Temperature Sensor   */

/**
 * Include files
 */ 

#include <util/delay.h>
#include <avr/io.h>

/**
 * Function Definitions
 */

void peripheral_init(void);
void TurnLED_ON();
void TurnLED_OFF();
int activity1_LED(void);

#endif /* __ACTIVITY_1_H__ */
