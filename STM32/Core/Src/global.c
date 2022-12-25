/*
 * global.c
 *
 *  Created on: Dec 16, 2022
 *      Author: dell
 */
#include "global.h"

int status_parser = INIT;
int status_uart = INIT;

uint8_t temp = 0;
uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;
uint8_t start_var = 0;
uint8_t printing = 0;
uint8_t temp1 = 0;
uint8_t temp2 = 0;
uint8_t temp3 = 0;
uint8_t temp4 = 0;

char str[50];
uint32_t ADC_value = 0;

uint8_t command_flag = 0;




