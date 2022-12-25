/*
 * global.h
 *
 *  Created on: Dec 16, 2022
 *      Author: dell
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"

#define INIT 				0
#define START_COMMAND		1
#define CHECK_COMMAND 		2
#define PRINTING			11
#define END_PRINT 			12
#define MAX_BUFFER_SIZE 	30

extern int status_parser;
extern int status_uart;

extern uint8_t temp;
extern uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t index_buffer;
extern uint8_t buffer_flag;
extern uint8_t start_var;
extern uint8_t printing;
extern uint8_t temp1;
extern uint8_t temp2;
extern uint8_t temp3;
extern uint8_t temp4;

extern uint8_t command_flag;


extern char str[50];
extern uint32_t ADC_value;

#endif /* INC_GLOBAL_H_ */
