/*
 * input_reading.h
 *
 *  Created on: Oct 20, 2023
 *      Author: HP
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_


#include "main.h"
#include "timer.h"

void init_buffer();
void button_reading(void);
unsigned char is_button_pressed(unsigned char index);
unsigned char is_button_pressed_1s(unsigned char index);

#endif /* INC_INPUT_READING_H_ */
