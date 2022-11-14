 /*
 * global.c
 *
 *  Created on: Oct 28, 2022
 *      Author: Admin
 */


#include "global.h"

int status = 0;
int temp = 0;
int index_7seg = 0;
int traffic_count[3] = {5,2,3};
int count[3] = {5,2,3};
int clock_buffer[4] = {0, 0, 0, 0};

void display7segment(int num){
	if (num == 0){
		HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, RESET);
		HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, RESET);
		HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, RESET);
		HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, RESET);
		HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, RESET);
		HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, RESET);
		HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, SET);
	}
	if (num == 1){
			HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, SET);
			HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, RESET);
			HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, RESET);
			HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, SET);
			HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, SET);
			HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, SET);
			HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, SET);
		}
	if (num == 2){
			HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, RESET);
			HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, RESET);
			HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, SET);
			HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, RESET);
			HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, RESET);
			HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, SET);
			HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, RESET);
		}
	if (num == 3){
			HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, RESET);
			HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, RESET);
			HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, RESET);
			HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, RESET);
			HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, SET);
			HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, SET);
			HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, RESET);
		}
	if (num == 4){
			HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, SET);
			HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, RESET);
			HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, RESET);
			HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, SET);
			HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, SET);
			HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, RESET);
			HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, RESET);
		}
	if (num == 5){
			HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, RESET);
			HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, SET);
			HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, RESET);
			HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, RESET);
			HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, SET);
			HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, RESET);
			HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, RESET);
		}
	if (num == 6){
			HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, RESET);
			HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, SET);
			HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, RESET);
			HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, RESET);
			HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, RESET);
			HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, RESET);
			HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, RESET);
		}
	if (num == 7){
			HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, RESET);
			HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, RESET);
			HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, RESET);
			HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, SET);
			HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, SET);
			HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, SET);
			HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, SET);
		}
	if (num == 8){
			HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, RESET);
			HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, RESET);
			HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, RESET);
			HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, RESET);
			HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, RESET);
			HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, RESET);
			HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, RESET);
		}
	if (num == 9){
			HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, RESET);
			HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, RESET);
			HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, RESET);
			HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, RESET);
			HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, SET);
			HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, RESET);
			HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, RESET);
		}
}

void update7SEG(int index){
 switch (index){
 	 case 0:
 		 // Display the first 7 SEG with led_buffer [0]
 		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
 		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
 		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
 		HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, RESET);
 		display7segment(clock_buffer[0]);
 		break;
 	 case 1:
 		 // Display the second 7 SEG with led_buffer [1]
 		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
 		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
 		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
 		HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, RESET);
 		display7segment(clock_buffer[1]);
 		break;
 	 case 2:
		 // Display the first 7 SEG with led_buffer [2]
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, RESET);
		display7segment(clock_buffer[2]);
		break;
 	 case 3:
		 // Display the first 7 SEG with led_buffer [3]
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
		HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, SET);
		display7segment(clock_buffer[3]);
		break;
 	default:
 		 break;
 }
}
void decrease_1sec(){
	count[0]--;
	count[1]--;
	clock_buffer[0] = count[1]/10;
	clock_buffer[1] = count[1]%10;
	clock_buffer[2] = count[0]/10;
	clock_buffer[3] = count[0]%10;
	setTimer4(1000);
}
