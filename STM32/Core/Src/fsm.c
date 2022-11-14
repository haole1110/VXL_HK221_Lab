/*
 * fsm.c
 *
 *  Created on: Oct 28, 2022
 *      Author: Admin
 */
#include "fsm.h"

void fsm_auto_run(){
	switch(status){
	case INIT:
		HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, SET);
		HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, SET);
		HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, SET);
		HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, SET);
		HAL_GPIO_WritePin(YELLOW_2_GPIO_Port, YELLOW_2_Pin, SET);
		HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, SET);

		status = MODE_1;
		setTimer3(250);
		break;
	case RED_GREEN:
		HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, RESET);
		HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, SET);
		HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, SET);
		HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, SET);
		HAL_GPIO_WritePin(YELLOW_2_GPIO_Port, YELLOW_2_Pin, SET);
		HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, RESET);
		if (timer4_flag == 1){
			decrease_1sec();
		}
		if (timer3_flag == 1){ //Turn on index_led-th 7SEG
			  if (index_7seg >= 4) {
					index_7seg = 0;
					update7SEG(index_7seg++);
			  } else {
					update7SEG(index_7seg++);
				}
			  setTimer3(250);
		  }
		if (timer2_flag == 1){
			status = RED_YELLOW;
			count[0] = traffic_count[0] - traffic_count[2];
			count[1] = traffic_count[1];
			decrease_1sec();
			setTimer2(traffic_count[1]*1000);
		}
		if (isButton1Pressed() == 1){
			status = MODE_2;
			HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, SET);
			HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, SET);
		}
		break;
	case RED_YELLOW:
		HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, RESET);
		HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, SET);
		HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, SET);
		HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, SET);
		HAL_GPIO_WritePin(YELLOW_2_GPIO_Port, YELLOW_2_Pin, RESET);
		HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, SET);
		if (timer4_flag == 1){
			decrease_1sec();
		}
		if (timer3_flag == 1){ //Turn on index_led-th 7SEG
			  if (index_7seg >= 4) {
					index_7seg = 0;
					update7SEG(index_7seg++);
			  } else {
					update7SEG(index_7seg++);
				}
			  setTimer3(250);
		  }
		if (timer2_flag == 1){
			status = GREEN_RED;
			count[0] = traffic_count[2];
			count[1] = traffic_count[0];
			decrease_1sec();
			setTimer2(traffic_count[2]*1000);
		}
		if (isButton1Pressed() == 1){
			status = MODE_2;
			HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, SET);
			HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, SET);
		}
		break;
	case GREEN_RED:
		HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, SET);
		HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, SET);
		HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, RESET);
		HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, RESET);
		HAL_GPIO_WritePin(YELLOW_2_GPIO_Port, YELLOW_2_Pin, SET);
		HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, SET);
		if (timer4_flag == 1){
			decrease_1sec();
		}
		if (timer3_flag == 1){ //Turn on index_led-th 7SEG
			  if (index_7seg >= 4) {
					index_7seg = 0;
					update7SEG(index_7seg++);
			  } else {
					update7SEG(index_7seg++);
				}
			  setTimer3(250);
		  }
		if (timer2_flag == 1){
			status = YELLOW_RED;
			count[1] = traffic_count[0] - traffic_count[2];
			count[0] = traffic_count[1];
			decrease_1sec();
			setTimer2(traffic_count[1]*1000);
		}
		if (isButton1Pressed() == 1){
			status = MODE_2;
			HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, SET);
			HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, SET);
		}
		break;
	case YELLOW_RED:
		HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, SET);
		HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, RESET);
		HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, SET);
		HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, RESET);
		HAL_GPIO_WritePin(YELLOW_2_GPIO_Port, YELLOW_2_Pin, SET);
		HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, SET);
		if (timer4_flag == 1){
			decrease_1sec();
		}
		if (timer3_flag == 1){ //Turn on index_led-th 7SEG
			  if (index_7seg >= 4) {
					index_7seg = 0;
					update7SEG(index_7seg++);
			  } else {
					update7SEG(index_7seg++);
				}
			  setTimer3(250);
		  }
		if (timer2_flag == 1){
			status = RED_GREEN;
			count[0] = traffic_count[0];
			count[1] = traffic_count[2];
			decrease_1sec();
			setTimer2(traffic_count[2]*1000);
		}
		if (isButton1Pressed() == 1){
			status = MODE_2;
			HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, SET);
			HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, SET);
		}

		break;
	default:
		break;
	}
}
