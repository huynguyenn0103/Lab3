/*
 * input_reading.c
 *
 *  Created on: Oct 20, 2023
 *      Author: HP
 */
#include "input_reading.h"

#define NO_OF_BUTTONS					3

#define DURATION_FOR_AUTO_INCREASING	200

#define BUTTON_IS_PRESSED				GPIO_PIN_RESET
#define BUTTON_IS_RELEASED				GPIO_PIN_SET

static GPIO_PinState buttonBuffer[NO_OF_BUTTONS];

static GPIO_PinState debounceButtonBuffer1[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer3[NO_OF_BUTTONS];

static uint8_t flagForButtonPress1s[NO_OF_BUTTONS];
static uint16_t counterForButtonPress1s[NO_OF_BUTTONS];

void init_buffer() {
	for (int i = 0; i < NO_OF_BUTTONS; i++) {
		buttonBuffer[i] = BUTTON_IS_RELEASED;
		debounceButtonBuffer1[i] = BUTTON_IS_RELEASED;
		debounceButtonBuffer2[i] = BUTTON_IS_RELEASED;
		debounceButtonBuffer3[i] = BUTTON_IS_RELEASED;
		flagForButtonPress1s[i] = 0;
		counterForButtonPress1s[i] = 0;
	}
}

void button_reading(void) {
	for (int i = 0; i < NO_OF_BUTTONS; i++) {
		debounceButtonBuffer3[i] = debounceButtonBuffer2[i];
		debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
		if(i == 0){
			debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_Pin);
		}
		else if (i == 1){
			debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(BUTTON_2_GPIO_Port, BUTTON_2_Pin);
		}
		else {
			debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(BUTTON_3_GPIO_Port, BUTTON_3_Pin);
		}

		if (debounceButtonBuffer1[i] == debounceButtonBuffer2[i] && debounceButtonBuffer3[i] == debounceButtonBuffer2[i])
			buttonBuffer[i] = debounceButtonBuffer1[i];

		if (buttonBuffer[i] == BUTTON_IS_PRESSED) {
			if (counterForButtonPress1s[i] < DURATION_FOR_AUTO_INCREASING) {
				counterForButtonPress1s[i]++;
			}
			else {
				flagForButtonPress1s[i] = 1;
			}
		}
		else {
			counterForButtonPress1s[i] = 0;
			flagForButtonPress1s[i] = 0;
		}
	}
}

unsigned char is_button_pressed(unsigned char index) {
	if (index >= NO_OF_BUTTONS) return 0;
	return (buttonBuffer[index] == BUTTON_IS_PRESSED);
}

unsigned char is_button_pressed_1s(unsigned char index) {
	if (index >= NO_OF_BUTTONS) return 0;
	if(flagForButtonPress1s[index] == 1){
		counterForButtonPress1s[index] = 0;
		flagForButtonPress1s[index] = 0;
		return 1;
	}
	return 0;
}


