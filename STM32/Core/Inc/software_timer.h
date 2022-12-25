/*
 * software_timer.h
 *
 *  Created on: Oct 30, 2022
 *      Author: Admin
 */
#include "main.h"

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer1_flag; //Blinky
extern int timer2_flag; //Delay 3s to print again
extern int timer2_counter;
extern int timer3_flag;
extern int timer4_flag;

void setTimer1(int duration);
void timerRun();

void setTimer2(int duration);

void setTimer3(int duration);

void setTimer4(int duration);

#endif /* INC_SOFTWARE_TIMER_H_ */
