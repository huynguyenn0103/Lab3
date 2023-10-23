/*
 * timer.h
 *
 *  Created on: Oct 20, 2023
 *      Author: HP
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include "main.h"
#include "input_reading.h"
#include "button.h"

#define TIMER_CYCLE			1

extern int timer0_flag;
extern int timer1_flag;

void setTimer0(int duration);
void setTimer1(int duration);


#endif /* INC_TIMER_H_ */
