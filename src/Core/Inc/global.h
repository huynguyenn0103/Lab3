/*
 * global.h
 *
 *  Created on: Oct 20, 2023
 *      Author: HP
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define RED_INIT		30
#define YELLOW_INIT		5
#define GREEN_INIT		25

void LedTimeDurationInit();
extern int mode;
extern int red_automatic_value, yellow_automatic_value, green_automatic_value;
extern int red_manual_value, yellow_manual_value, green_manual_value;


#endif /* INC_GLOBAL_H_ */
