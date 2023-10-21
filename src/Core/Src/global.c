/*
 * global.c
 *
 *  Created on: Oct 20, 2023
 *      Author: HP
 */

#include "global.h"

int mode = 1;
int red_automatic_value, yellow_automatic_value, green_automatic_value;
int red_manual_value, yellow_manual_value, green_manual_value;

void LedTimeDurationInit() {
	red_automatic_value = RED_INIT;
	yellow_automatic_value = YELLOW_INIT;
	green_automatic_value = GREEN_INIT;

	red_manual_value = red_automatic_value;
	yellow_manual_value = yellow_automatic_value;
	green_manual_value = green_automatic_value;
}


