/*
 * keyboard.c
 *
 *  Created on: Nov 6, 2023
 *      Author: Javier Guzmán Olaya
 */

#include "keyboard.h"

/**
 * @brief This functions initialize the functionality of the keypad
 */
void keypad_init(void)
{

	/* Set the rows high to be detected in the columns by rising interrupt */
	ROW_1_GPIO_Port->BSRR = ROW_1_Pin;
	ROW_2_GPIO_Port->BSRR = ROW_2_Pin;
	ROW_3_GPIO_Port->BSRR = ROW_3_Pin;
	ROW_4_GPIO_Port->BSRR = ROW_4_Pin;
}

/**
 * @brief  This function debounces and identify keypad events.
 * @param  column_to_evaluate: the column where the event happened.
 * @retval 0xFF -> invalid key. [0x00 - 0x0F] -> valid key.
 */
uint8_t keypad_handler(uint16_t column_to_evaluate)
{
	uint8_t key_pressed = 0xFF; // Value to return

	/*** Debounce the key press (remove noise in the key) ***/
	static uint32_t last_pressed_tick = 0;
	if (HAL_GetTick() <= (last_pressed_tick + KEY_DEBOUNCE_MS)) {
		// less than KEY_DEBOUNCE_MS since last press. Probably noise
		return key_pressed; // return 0xFF
	}
	last_pressed_tick = HAL_GetTick();

	/*** Check in which column the event happened ***/
	switch (column_to_evaluate) {


	case COLUMN_1_Pin:

		/*= if the event corresponds to column 1, the following logic is used =*/

		/*Activate the first row and deactivate the others*/
		ROW_1_GPIO_Port->BSRR = ROW_1_Pin;
		ROW_2_GPIO_Port->BRR = ROW_2_Pin;
		ROW_3_GPIO_Port->BRR = ROW_3_Pin;
		ROW_4_GPIO_Port->BRR = ROW_4_Pin;

		HAL_Delay(10); // wait for voltage to establish


		/*if column 1 is still high -> column 1 + row 1 = key 1*/
		if (COLUMN_1_GPIO_Port->IDR & COLUMN_1_Pin) {
			key_pressed = 0x01;
			break;

		}

		ROW_1_GPIO_Port->BRR = ROW_1_Pin; 	// turn off row 1
		ROW_2_GPIO_Port->BSRR = ROW_2_Pin; 	// turn on row 2

		HAL_Delay(10); // wait for voltage to establish


		/*if column 1 is still high -> column 1 + row 2 = key 4*/
		if (COLUMN_1_GPIO_Port->IDR & COLUMN_1_Pin) {
			key_pressed = 0x04;
			break;
		}

		ROW_2_GPIO_Port->BRR = ROW_2_Pin; 	// turn off row 2
		ROW_3_GPIO_Port->BSRR = ROW_3_Pin; 	// turn on row 3

		HAL_Delay(10); // wait for voltage to establish


		/* if column 1 is still high -> column 1 + row 3 = key 7*/
		if (COLUMN_1_GPIO_Port->IDR & COLUMN_1_Pin) {
			key_pressed = 0x07;
			break;

		}

		ROW_3_GPIO_Port->BRR = ROW_3_Pin;	// turn off row 3
		ROW_4_GPIO_Port->BSRR = ROW_4_Pin; 	// turn on row 4

		HAL_Delay(10); // wait for voltage to establish


		/*if column 1 is still high -> column 1 + row 4 = key **/
		if (COLUMN_1_GPIO_Port->IDR & COLUMN_1_Pin) {
			key_pressed = 0x0E;
			break;
		}
	  break;

	case COLUMN_2_Pin:

		/*= if the event corresponds to column 2, the following logic is used =*/

		/*Activate the first row and deactivate the others*/
				ROW_1_GPIO_Port->BSRR = ROW_1_Pin;
				ROW_2_GPIO_Port->BRR = ROW_2_Pin;
				ROW_3_GPIO_Port->BRR = ROW_3_Pin;
				ROW_4_GPIO_Port->BRR = ROW_4_Pin;

				HAL_Delay(10); // wait for voltage to establish


				/*if column 2 is still high -> column 2 + row 1 = key 2*/
				if (COLUMN_2_GPIO_Port->IDR & COLUMN_2_Pin) {
					key_pressed = 0x02;
					break;

				}

				ROW_1_GPIO_Port->BRR = ROW_1_Pin; 	// turn off row 1
				ROW_2_GPIO_Port->BSRR = ROW_2_Pin; 	// turn on row 2

				HAL_Delay(10); // wait for voltage to establish


				/*if column 2 is still high -> column 2 + row 2 = key 5*/
				if (COLUMN_2_GPIO_Port->IDR & COLUMN_2_Pin) {
					key_pressed = 0x05;
					break;
				}

				ROW_2_GPIO_Port->BRR = ROW_2_Pin; 	// turn off row 2
				ROW_3_GPIO_Port->BSRR = ROW_3_Pin; 	// turn on row 3

				HAL_Delay(10); // wait for voltage to establish


				/*if column 2 is still high -> column 2 + row 3 = key 8*/
				if (COLUMN_2_GPIO_Port->IDR & COLUMN_2_Pin) {
					key_pressed = 0x08;
					break;

				}

				ROW_3_GPIO_Port->BRR = ROW_3_Pin;	// turn off row 3
				ROW_4_GPIO_Port->BSRR = ROW_4_Pin; 	// turn on row 4

				HAL_Delay(10); // wait for voltage to establish


				/*if column 2 is still high -> column 2 + row 4 = key 0*/
				if (COLUMN_2_GPIO_Port->IDR & COLUMN_2_Pin) {
					key_pressed = 0x00;
					break;
				}

		break;

	case COLUMN_3_Pin:

		/*= if the event corresponds to column 3, the following logic is used =*/

		/*Activate the first row and deactivate the others*/
				ROW_1_GPIO_Port->BSRR = ROW_1_Pin;
				ROW_2_GPIO_Port->BRR = ROW_2_Pin;
				ROW_3_GPIO_Port->BRR = ROW_3_Pin;
				ROW_4_GPIO_Port->BRR = ROW_4_Pin;

				HAL_Delay(10); // wait for voltage to establish


				/* if column 3 is still high -> column 3 + row 1 = key 3*/
				if (COLUMN_3_GPIO_Port->IDR & COLUMN_3_Pin) {
					key_pressed = 0x03;
					break;

				}

				ROW_1_GPIO_Port->BRR = ROW_1_Pin; 	// turn off row 1
				ROW_2_GPIO_Port->BSRR = ROW_2_Pin; 	// turn on row 2

				HAL_Delay(10); // wait for voltage to establish


				/*if column 3 is still high -> column 3 + row 2 = key 6*/
				if (COLUMN_3_GPIO_Port->IDR & COLUMN_3_Pin) {
					key_pressed = 0x06;
					break;
				}

				ROW_2_GPIO_Port->BRR = ROW_2_Pin; 	// turn off row 2
				ROW_3_GPIO_Port->BSRR = ROW_3_Pin; 	// turn on row 3

				HAL_Delay(10); // wait for voltage to establish


				/*if column 3 is still high -> column 3 + row 3 = key 9*/
				if (COLUMN_3_GPIO_Port->IDR & COLUMN_3_Pin) {
					key_pressed = 0x09;
					break;

				}

				ROW_3_GPIO_Port->BRR = ROW_3_Pin;	// turn off row 3
				ROW_4_GPIO_Port->BSRR = ROW_4_Pin; 	// turn on row 4

				HAL_Delay(10); // wait for voltage to establish


				/*if column 3 is still high -> column 3 + row 4 = key #*/
				if (COLUMN_3_GPIO_Port->IDR & COLUMN_3_Pin) {
					key_pressed = 0x23;
					// the value of key_pressed is a random value as the "#"
					// is not a hexadecimal value.
					break;
				}
			  break;

	case COLUMN_4_Pin:

		/*= if the event corresponds to column 4, the following logic is used =*/

		/*Activate the first row and deactivate the others*/
				ROW_1_GPIO_Port->BSRR = ROW_1_Pin;
				ROW_2_GPIO_Port->BRR = ROW_2_Pin;
				ROW_3_GPIO_Port->BRR = ROW_3_Pin;
				ROW_4_GPIO_Port->BRR = ROW_4_Pin;

				HAL_Delay(10); // wait for voltage to establish

				/* if column 4 is still high -> column 1 + row 1 = key A*/
				if (COLUMN_4_GPIO_Port->IDR & COLUMN_4_Pin) {
					key_pressed = 0x0A;
					break;

				}

				ROW_1_GPIO_Port->BRR = ROW_1_Pin; 	// turn off row 1
				ROW_2_GPIO_Port->BSRR = ROW_2_Pin; 	// turn on row 2

				HAL_Delay(10); // wait for voltage to establish


				/*if column 4 is still high -> column 4 + row 2 = key B*/
				if (COLUMN_4_GPIO_Port->IDR & COLUMN_4_Pin) {
					key_pressed = 0x0B;
					break;
				}

				ROW_2_GPIO_Port->BRR = ROW_2_Pin; 	// turn off row 2
				ROW_3_GPIO_Port->BSRR = ROW_3_Pin; 	// turn on row 3

				HAL_Delay(10); // wait for voltage to establish


				/*if column 4 is still high -> column 4 + row 3 = key C*/
				if (COLUMN_4_GPIO_Port->IDR & COLUMN_4_Pin) {
					key_pressed = 0x0C;
					break;

				}

				ROW_3_GPIO_Port->BRR = ROW_3_Pin;	// turn off row 3
				ROW_4_GPIO_Port->BSRR = ROW_4_Pin; 	// turn on row 4

				HAL_Delay(10); // wait for voltage to establish


				/* if column 4 is still high -> column 4 + row 4 = key D*/
				if (COLUMN_4_GPIO_Port->IDR & COLUMN_4_Pin) {
					key_pressed = 0x0D;
					break;
				}
			  break;
	}

	keypad_init(); // set the columns high again
	return key_pressed; // invalid: 0xFF, valid:[0x00-0x0F]
}

