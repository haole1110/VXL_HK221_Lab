/*
 * fsm_manual.c
 *
 *  Created on: Oct 30, 2022
 *      Author: Admin
 */

#include "fsm_manual.h"

void fsm_manual_run(){
	switch (status){
	case MODE_1:
		HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, RESET);
		HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, RESET);
		HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, RESET);
		HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, RESET);
		HAL_GPIO_WritePin(YELLOW_2_GPIO_Port, YELLOW_2_Pin, RESET);
		HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, RESET);
		 if (timer3_flag == 1){ //Turn on index_led-th 7SEG
			  if (index_7seg >= 4) {
					index_7seg = 0;
					clock_buffer[0] = 0;
					update7SEG(index_7seg++);
			  } else {
				  	clock_buffer[1] = 1;
					update7SEG(index_7seg++);
					clock_buffer[2] = 0;
					clock_buffer[3] = 0;
				}
			  setTimer3(250);
		  }

		if (isButton1Pressed() == 1){
			status = MODE_2;
		}
		if (isButton3Pressed() == 1){
			status = RED_GREEN;
			count[0] = traffic_count[0];
			count[1] = traffic_count[2];
			decrease_1sec();
			setTimer2(traffic_count[2]*1000);
		}
		break;
	case MODE_2:
		HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, SET);
		HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, SET);
		HAL_GPIO_WritePin(YELLOW_2_GPIO_Port, YELLOW_2_Pin, SET);
		HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, SET);
		if (timer3_flag == 1){ //Turn on index_led-th 7SEG
			  if (index_7seg >= 4) {
					index_7seg = 0;
					clock_buffer[0] = 0;
					update7SEG(index_7seg++);
			  } else {
					clock_buffer[1] = 2;
					clock_buffer[2] = traffic_count[0]/10;
					clock_buffer[3] = traffic_count[0]%10;
					update7SEG(index_7seg++);
				}
			  setTimer3(250);
		  }

		if (timer1_flag == 1){
			HAL_GPIO_TogglePin(RED_1_GPIO_Port, RED_1_Pin);
			HAL_GPIO_TogglePin(RED_2_GPIO_Port, RED_2_Pin);
			setTimer1(500);
		}

		if (isButton1Pressed() == 1){
			status = MODE_3;
		}
		if (isButton2Pressed() == 1){
			temp = traffic_count[0];
			temp++;
			if (temp>=100) temp = 0;
			clock_buffer[2] = temp/10;
			clock_buffer[3] = temp%10;
			status = INCR_RED;
		}
		break;
	case MODE_3:
		HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, SET);
		HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, SET);
		HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, SET);
		HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, SET);
		if (timer3_flag == 1){ //Turn on index_led-th 7SEG
			  if (index_7seg >= 4) {
					index_7seg = 0;
					clock_buffer[0] = 0;
					update7SEG(index_7seg++);
			  } else {
					clock_buffer[1] = 3;
					clock_buffer[2] = traffic_count[1]/10;
					clock_buffer[3] = traffic_count[1]%10;
					update7SEG(index_7seg++);
				}
			  setTimer3(250);
		  }

		if (timer1_flag == 1){
			HAL_GPIO_TogglePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin);
			HAL_GPIO_TogglePin(YELLOW_2_GPIO_Port, YELLOW_2_Pin);
			setTimer1(500);
		}

		if (isButton1Pressed() == 1){
			status = MODE_4;
		}
		if (isButton2Pressed() == 1){
			temp = traffic_count[1];
			temp++;
			if (temp>=100) temp = 0;
			clock_buffer[2] = temp/10;
			clock_buffer[3] = temp%10;
			status = INCR_YELLOW;
		}
		break;
	case MODE_4:
		HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, SET);
		HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, SET);
		HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, SET);
		HAL_GPIO_WritePin(YELLOW_2_GPIO_Port, YELLOW_2_Pin, SET);
		if (timer3_flag == 1){ //Turn on index_led-th 7SEG
			  if (index_7seg >= 4) {
					index_7seg = 0;
					clock_buffer[0] = 0;
					update7SEG(index_7seg++);
			  } else {
					clock_buffer[1] = 4;
					clock_buffer[2] = traffic_count[2]/10;
					clock_buffer[3] = traffic_count[2]%10;
					update7SEG(index_7seg++);
				}
			  setTimer3(250);
		  }

		if (timer1_flag == 1){
			HAL_GPIO_TogglePin(GREEN_1_GPIO_Port, GREEN_1_Pin);
			HAL_GPIO_TogglePin(GREEN_2_GPIO_Port, GREEN_2_Pin);
			setTimer1(500);
		}

		if (isButton1Pressed() == 1){
			status = MODE_1;
			isButton3Pressed();
		}
		if (isButton2Pressed() == 1){
			temp = traffic_count[2];
			temp++;
			if (temp>=100) temp = 0;
			clock_buffer[2] = temp/10;
			clock_buffer[3] = temp%10;
			status = INCR_GREEN;
		}
		break;
	case INCR_RED:
		HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, SET);
		HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, SET);
		HAL_GPIO_WritePin(YELLOW_2_GPIO_Port, YELLOW_2_Pin, SET);
		HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, SET);
		if (timer3_flag == 1){ //Turn on index_led-th 7SEG
			  if (index_7seg >= 4) {
					index_7seg = 0;
					clock_buffer[0] = 0;
					update7SEG(index_7seg++);
			  } else {
					clock_buffer[1] = 2;
					update7SEG(index_7seg++);
				}
			  setTimer3(250);
		  }

		if (timer1_flag == 1){
			HAL_GPIO_TogglePin(RED_1_GPIO_Port, RED_1_Pin);
			HAL_GPIO_TogglePin(RED_2_GPIO_Port, RED_2_Pin);
			setTimer1(500);
		}

		if (isButton1Pressed() == 1){
			status = MODE_3;
		}
		if (isButton2Pressed() == 1){
			temp++;
			if (temp>=100) temp = 0;
			clock_buffer[2] = temp/10;
			clock_buffer[3] = temp%10;
			status = INCR_RED;
		}
		if (isButton3Pressed() == 1){
			status = MODE_2;
			if (temp > traffic_count[1]){
				traffic_count[0] = temp;
				traffic_count[2] = traffic_count[0] - traffic_count[1];
			}
		}
		break;
	case INCR_YELLOW:
		HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, SET);
		HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, SET);
		HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, SET);
		HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, SET);
		if (timer3_flag == 1){ //Turn on index_led-th 7SEG
			  if (index_7seg >= 4) {
					index_7seg = 0;
					clock_buffer[0] = 0;
					update7SEG(index_7seg++);
			  } else {
					clock_buffer[1] = 3;
					update7SEG(index_7seg++);
				}
			  setTimer3(250);
		  }

		if (timer1_flag == 1){
			HAL_GPIO_TogglePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin);
			HAL_GPIO_TogglePin(YELLOW_2_GPIO_Port, YELLOW_2_Pin);
			setTimer1(500);
		}

		if (isButton1Pressed() == 1){
			status = MODE_4;
		}
		if (isButton2Pressed() == 1){
			temp++;
			if (temp>=100) temp = 0;
			clock_buffer[2] = temp/10;
			clock_buffer[3] = temp%10;
			status = INCR_YELLOW;
		}
		if (isButton3Pressed() == 1){
			status = MODE_3;
			if (temp <= 5){
				traffic_count[1] = temp;
				traffic_count[0] = traffic_count[1] + traffic_count[2];
			}
		}
		break;
	case INCR_GREEN:
		HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, SET);
		HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, SET);
		HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, SET);
		HAL_GPIO_WritePin(YELLOW_2_GPIO_Port, YELLOW_2_Pin, SET);
		if (timer3_flag == 1){ //Turn on index_led-th 7SEG
			  if (index_7seg >= 4) {
					index_7seg = 0;
					clock_buffer[0] = 0;
					update7SEG(index_7seg++);
			  } else {
					clock_buffer[1] = 4;
					update7SEG(index_7seg++);
				}
			  setTimer3(250);
		  }

		if (timer1_flag == 1){
			HAL_GPIO_TogglePin(GREEN_1_GPIO_Port, GREEN_1_Pin);
			HAL_GPIO_TogglePin(GREEN_2_GPIO_Port, GREEN_2_Pin);
			setTimer1(500);
		}

		if (isButton1Pressed() == 1){
			status = MODE_1;
		}
		if (isButton2Pressed() == 1){
			temp++;
			if (temp>=100) temp = 0;
			clock_buffer[2] = temp/10;
			clock_buffer[3] = temp%10;
			status = INCR_GREEN;
		}
		if (isButton3Pressed() == 1){
			status = MODE_4;
			if (temp + traffic_count[1] <= 99){
				traffic_count[2] = temp;
				traffic_count[0] = traffic_count[1] + traffic_count[2];
			}
		}
		break;
	default:
		break;
	}
}
