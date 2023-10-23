/*
 * input_processing.c
 *
 *  Created on: Oct 20, 2023
 *      Author: HP
 */

#include "input_processing.h"

enum ButtonState{BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_PRESSED_MORE_THAN_1_SECOND};
enum ButtonState buttonState[3] = {BUTTON_RELEASED};

static void increaseManualValue() {
	switch (mode) {
		case 2:
			red_manual_value++;
			if (red_manual_value > 99) red_manual_value = 0;
			break;
		case 3:
			yellow_manual_value++;
			if (yellow_manual_value > 99) yellow_manual_value = 0;
			break;
		case 4:
			green_manual_value++;
			if (green_manual_value > 99) green_manual_value = 0;
			break;
		default:
			break;
	}
}

static void setAutomaticDurationValue() {
	if(mode == 2){
		red_automatic_value = red_manual_value;
	}
	else if (mode == 3){
		yellow_automatic_value = yellow_manual_value;
	}
	else if (mode == 4){
		green_automatic_value = green_manual_value;
	}
}
void fsm_test(){
		if(isButtonPressed(0)){
			mode++;
			if (mode > 4) {
				mode = 1;
				resetCountValue();
			}
		}
		if(isButtonPressed(1)){
			increaseManualValue();
		}
		if(isButtonPressed(2)){
			setAutomaticDurationValue();
		}
}

//void fsm_for_input_processing() {
//	switch (buttonState[0]) {
//		case BUTTON_RELEASED:
//			if (is_button_pressed(0)) {
//				buttonState[0] = BUTTON_PRESSED;
//				mode++;
//				if (mode > 4) {
//					mode = 1;
//					resetCountValue();
//				}
//			}
//			break;
//		case BUTTON_PRESSED:
//			if (!is_button_pressed(0)) {
//				buttonState[0] = BUTTON_RELEASED;
//			}
//			break;
//		default:
//			break;
//	}
//
//	switch (buttonState[1]) {
//		case BUTTON_RELEASED:
//			if (is_button_pressed(1)) {
//				buttonState[1] = BUTTON_PRESSED;
//				increaseManualValue();
//			}
//			break;
//		case BUTTON_PRESSED:
//			if (!is_button_pressed(1)) {
//				buttonState[1] = BUTTON_RELEASED;
//			}
//			if (is_button_pressed_1s(1)) {
//				buttonState[1] = BUTTON_PRESSED_MORE_THAN_1_SECOND;
//				increaseManualValue();
//			}
//			break;
//		case BUTTON_PRESSED_MORE_THAN_1_SECOND:
//			if (!is_button_pressed(1)) {
//				buttonState[1] = BUTTON_RELEASED;
//			}
//
//			if(is_button_pressed_1s(1)) {
//				increaseManualValue();
//			}
//			break;
//		default:
//			break;
//	}
//
//	switch (buttonState[2]) {
//		case BUTTON_RELEASED:
//			if (is_button_pressed(2)) {
//				buttonState[2] = BUTTON_PRESSED;
//				setAutomaticDurationValue();
//			}
//			break;
//		case BUTTON_PRESSED:
//			if (!is_button_pressed(2)) {
//				buttonState[2] = BUTTON_RELEASED;
//			}
//			break;
//		default:
//			break;
//	}
//}





