/*
 * keyboard.h
 *
 *  Created on: Nov 6, 2023
 *      Author: Javier Guzmán Olaya
 */

#ifndef INC_KEYBOARD_H_
#define INC_KEYBOARD_H_


/*We include the necessary external libraries*/
#include "stdio.h"
#include <stdint.h>
#include <stm32l4xx_hal.h>

/*== Pin configuration for rows ==*/


/*Pin configuration for the first row*/
#ifndef ROW_1_GPIO_Port
#define ROW_1_GPIO_Port      GPIOA
#endif

#ifndef ROW_1_Pin
#define ROW_1_Pin       GPIO_PIN_10
#endif

/*Pin configuration for the second row*/
#ifndef ROW_2_GPIO_Port
#define ROW_2_GPIO_Port      GPIOB
#endif

#ifndef ROW_2_Pin
#define ROW_2_Pin       GPIO_PIN_3
#endif

/*Pin configuration for the third row*/
#ifndef ROW_3_GPIO_Port
#define ROW_3_GPIO_Port      GPIOB
#endif

#ifndef ROW_3_Pin
#define ROW_3_Pin       GPIO_PIN_5
#endif

/*Pin configuration for the fourth row*/
#ifndef ROW_4_GPIO_Port
#define ROW_4_GPIO_Port      GPIOB
#endif

#ifndef ROW_4_Pin
#define ROW_4_Pin       GPIO_PIN_4
#endif

/*== Pin configuration for columns ==*/

/*Pin configuration for the first column*/
#ifndef COLUMN_1_GPIO_Port
#define COLUMN_1_GPIO_Port      GPIOB
#endif

#ifndef COLUMN_1_Pin
#define COLUMN_1_Pin       GPIO_PIN_10
#endif

/*Pin configuration for the second column*/
#ifndef COLUMN_2_GPIO_Port
#define COLUMN_2_GPIO_Port      GPIOA
#endif

#ifndef COLUMN_2_Pin
#define COLUMN_2_Pin       GPIO_PIN_8
#endif

/*Pin configuration for the third column*/
#ifndef COLUMN_3_GPIO_Port
#define COLUMN_3_GPIO_Port     GPIOA
#endif

#ifndef COLUMN_3_Pin
#define COLUMN_3_Pin       GPIO_PIN_9
#endif

/*Pin configuration for the fourth column*/
#ifndef COLUMN_4_GPIO_Port
#define COLUMN_4_GPIO_Port    GPIOC
#endif

#ifndef COLUMN_4_Pin
#define COLUMN_4_Pin      GPIO_PIN_7
#endif

/*= Defined minimum time required for last press =*/
#ifndef KEY_DEBOUNCE_MS
#define KEY_DEBOUNCE_MS 300
#endif


/*= Method to initialize the keyboard hexadecimal =*/
void keypad_init(void);
uint8_t keypad_handler(uint16_t column_to_evaluate);

#endif /* INC_KEYBOARD_H_ */
