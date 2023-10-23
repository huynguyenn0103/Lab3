/*
 * button1.c
 *
 *  Created on: Oct 23, 2023
 *      Author: HP
 */
#include "button.h"
#define NO_OF_BUTTONS	3
static uint8_t button_flag[NO_OF_BUTTONS];

int button1_flag = 0;


int KeyReg0[3] = {NORMAL_STATE};
int KeyReg1[3] = {NORMAL_STATE};
int KeyReg2[3] = {NORMAL_STATE};

int KeyReg3[3] = {NORMAL_STATE};
int TimerForKeyPress = 200;


void subKeyProcess(int index){
	button_flag[index] = 1;
}

int isButtonPressed(int index){
	if(button_flag[index] == 1){
		button_flag[index] = 0;
		return 1;
	}
	return 0;
}

void getKeyInput(){
	for (int i = 0; i < NO_OF_BUTTONS; i++) {
		KeyReg0[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg2[i];
		if(i == 0){
			KeyReg2[i] = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_Pin);
		}
		else if (i == 1){
			KeyReg2[i] = HAL_GPIO_ReadPin(BUTTON_2_GPIO_Port, BUTTON_2_Pin);
		}
		else {
			KeyReg2[i] = HAL_GPIO_ReadPin(BUTTON_3_GPIO_Port, BUTTON_3_Pin);
		}

		if((KeyReg0[i] == KeyReg1[i]) && (KeyReg1[i] == KeyReg2[i])){
			if(KeyReg3[i] != KeyReg2[i]){
				KeyReg3[i] = KeyReg2[i];
				if(KeyReg2[i] == PRESSED_STATE){
					subKeyProcess(i);
					TimerForKeyPress = 200;
				}
			} else {
				TimerForKeyPress--;
				if(TimerForKeyPress == 0){
					KeyReg3[i] = NORMAL_STATE;
				}

			}
		}
	}

}

