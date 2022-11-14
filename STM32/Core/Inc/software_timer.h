/*
 * software_timer.h
 *
 *  Created on: Oct 30, 2022
 *      Author: Admin
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer1_flag; //Blinky
extern int timer2_flag; // Auto
extern int timer3_flag; //7seg
extern int timer4_flag; //sec

void setTimer1(int duration);
void timerRun();

void setTimer2(int duration);

void setTimer3(int duration);

void setTimer4(int duration);

#endif /* INC_SOFTWARE_TIMER_H_ */
