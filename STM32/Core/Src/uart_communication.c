/*
 * uart_communication.c
 *
 *  Created on: Dec 13, 2022
 *      Author: dell
 */
#include "uart_communication.h"

void uart_communiation_fsm(ADC_HandleTypeDef hadc1, UART_HandleTypeDef huart2) {
	switch (status_uart){
	case INIT:
		if (command_flag){
			switch (start_var){
			case 26:
				temp1 = 27;
				temp2 = 28;
				temp3 = 29;
				temp4 = 0;
				break;
			case 27:
				temp1 = 28;
				temp2 = 20;
				temp3 = 0;
				temp4 = 1;
				break;
			case 28:
				temp1 = 29;
				temp2 = 0;
				temp3 = 1;
				temp4 = 2;
				break;
			case 29:
				temp1 = 0;
				temp2 = 1;
				temp3 = 2;
				temp4 = 3;
				break;
			default:
				temp1 = start_var + 1;
				temp2 = start_var + 2;
				temp3 = start_var + 3;
				temp4 = start_var + 4;
				break;
			}
			if (buffer[temp1] == 'R' && buffer[temp2] == 'S' && buffer[temp3] == 'T' && buffer[temp4] == '#'){
				HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "\r\n"), 1000);
				timer2_flag = 1;
				timer2_counter = 0;
				status_uart = PRINTING;
			}
			if (buffer[(temp1)] == 'O' && buffer[(temp2)] == 'K' && buffer[(temp3)] == '#'){
				status_uart = END_PRINT;
			}
			command_flag = 0;
		} else {
			if (printing){
				status_uart = PRINTING;
			}
		}
		break;
	case PRINTING:
		HAL_ADC_Start(&hadc1);
		ADC_value = HAL_ADC_GetValue(&hadc1);
		HAL_ADC_Stop(&hadc1);
		if (timer2_flag){
			HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "!ADC = %d#\r\n", ADC_value), 1000);
			setTimer2(3000);
		}
		printing = 1;
		status_uart = INIT;
		break;
	case END_PRINT:
		timer2_flag = 1;
		timer2_counter = 0;
		printing = 0;
		status_uart = INIT;
	}
}



