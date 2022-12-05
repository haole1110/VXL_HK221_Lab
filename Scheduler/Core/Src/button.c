/*
 * button.c
 *
 *  Created on: Nov 4, 2022
 *      Author: Admin
 */


#include "button.h"


int button1_flag = 0;
int button2_flag = 0;
int button3_flag = 0;

int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;
int KeyReg3 = NORMAL_STATE;
int KeyReg4 = NORMAL_STATE;
int KeyReg5 = NORMAL_STATE;
int KeyReg6 = NORMAL_STATE;
int KeyReg7 = NORMAL_STATE;
int KeyReg8 = NORMAL_STATE;
int KeyReg9 = NORMAL_STATE;
int KeyReg10 = NORMAL_STATE;
int KeyReg11 = NORMAL_STATE;

int TimeForKeyPress =  300;
int DoublePress = 0;

int isButton1Pressed(){
	if (button1_flag == 1){
		button1_flag = 0;
		return 1;
	}
	return 0;
}
int isDouble(){
	if (button2_flag == 1){
		button2_flag = 0;
		return 1;
	}
	return 0;
}
int isButton3Pressed(){
	if (button3_flag == 1){
		button3_flag = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess1(){
	button1_flag = 1;
}
void subKeyProcess2(){
	button2_flag = 1;
}
void subKeyProcess3(){
	button3_flag = 1;
}


void getKeyInput1(){
  KeyReg0 = KeyReg1;
  KeyReg1 = KeyReg2;
  KeyReg2 = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_Pin);
  if ((KeyReg0 == KeyReg1) && (KeyReg1 == KeyReg2)){
    if (KeyReg2 != KeyReg3){
      KeyReg3 = KeyReg2;

      if (KeyReg2 == PRESSED_STATE){
    	  subKeyProcess1();
    	  TimeForKeyPress = 300;
      }
    }else{
       TimeForKeyPress --;
        if (TimeForKeyPress == 0){
        	if (KeyReg2 == PRESSED_STATE){
        		subKeyProcess1();
        	}
        	TimeForKeyPress = 300;
        }
    }
  }
}

