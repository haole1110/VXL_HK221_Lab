/*
 * global.h
 *
 *  Created on: Oct 28, 2022
 *      Author: Admin
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"
#include "main.h"

#define INIT			0
#define RED_GREEN		1
#define RED_YELLOW		2
#define GREEN_RED		3
#define YELLOW_RED		4

#define MODE_1			11
#define MODE_2			12
#define MODE_3			13
#define MODE_4			14

#define INCR_RED 		21
#define INCR_YELLOW 	22
#define INCR_GREEN 		23

extern int status;
extern int clock_buffer[4];
extern int index_7seg;
extern int traffic_count[3];
extern int count[3];
extern int temp;


void display7segment(int num);
void update7SEG(int index);
void decrease_1sec();

#endif /* INC_GLOBAL_H_ */
