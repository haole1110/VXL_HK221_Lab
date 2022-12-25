/*
 * command_parser.c
 *
 *  Created on: Dec 13, 2022
 *      Author: dell
 */
#include "command_parser.h"


void command_parser_fsm() {
	switch(status_parser){
	case INIT:
		if (temp == '!'){
			command_flag = 0;
			status_parser = CHECK_COMMAND;
			if (index_buffer == 0){
				start_var = 29;
			} else {
				start_var = index_buffer-1;
			}
		}
		break;
	case CHECK_COMMAND:
		if (temp == '#'){
			command_flag = 1;
			status_parser = INIT;
		}
		if (temp == '!') {
			if (index_buffer == 0){
				start_var = 29;
			} else {
				start_var = index_buffer-1;
			}
		}
		break;
	default:
		break;
	}
}
