/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void display7segment(int num);
void display7segment1(int num);
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  int temp = 0; /*For 2 traffic lights with red led first*/
  int temp1 = 0; /*For 2 traffic lights with green led first*/
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

	/*Traffic light with red led first*/
	  if (temp < 5) {
	  		  HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, RESET);
	  	 	  HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
	  	 	  HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
	  	  }
	  	  else if (temp < 8){
	  		  HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
	  		  HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, RESET);
	  		  HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
	  	  }
	  	  else {
	  		  HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
	  	 	  HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
	  	 	  HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, RESET);
	  	  }
	  	switch (temp){
	  	/*Countdown for red led 4s to 0s*/
	  	case 0:
	  		display7segment(4);
	  		break;
	  	case 1:
	  		  		display7segment(3);
	  		  		break;
	  	case 2:
	  		 		display7segment(2);
	  		  		break;
	  	case 3:
	  		  		display7segment(1);
	  		  		break;
	  	case 4:
	  		  		display7segment(0);
	  		  		break;
	  	/*Countdown for green led 2s to 0s*/
	  	case 5:
	  		  		display7segment(2);
	  		  		break;
	  	case 6:
	  		  		  		display7segment(1);
	  		  		  		break;
	  	case 7:
	  		  		  		display7segment(0);
	  		  		  		break;
	  	/*Countdown for yellow led 1s to 0s*/
	  	case 8:
	  		  		  		display7segment(1);
	  		  		  		break;
	  	case 9:
	  		  		  		display7segment(0);
	  		  		  		break;
	  	}
	  	  temp++;
	  	  if (temp >= 10) temp = 0;
	  	/*Traffic light with green led first*/
	  	if (temp1 < 3) {
	  			  HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, SET);
	  		 	  HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, RESET);
	  		 	  HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, SET);
	  		  }
	  		  else if (temp1 < 5){
	  			  HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, SET);
	  			  HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, SET);
	  			  HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, RESET);
	  		  }
	  		  else {
	  			  HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, RESET);
	  		 	  HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_Pin, SET);
	  		 	  HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, SET);
	  		  }
	  	switch (temp1){
	  			/*Countdown for green led 2s to 0s*/
	  		  	case 0:
	  		  		display7segment1(2);
	  		  		break;
	  		  	case 1:
	  		  		  		display7segment1(1);
	  		  		  		break;
	  		  	case 2:
	  		  		 		display7segment1(0);
	  		  		  		break;
	  		  	/*Countdown for yellow led 1s to 0s*/
	  		  	case 3:
	  		  		  		display7segment1(1);
	  		  		  		break;
	  		  	case 4:
	  		  		  		display7segment1(0);
	  		  		  		break;
	  		  	/*Countdown for red led 4s to 0s*/
	  		  	case 5:
	  		  		  		display7segment1(4);
	  		  		  		break;
	  		  	case 6:
	  		  		  		  		display7segment1(3);
	  		  		  		  		break;
	  		  	case 7:
	  		  		  		  		display7segment1(2);
	  		  		  		  		break;
	  		  	case 8:
	  		  		  		  		display7segment1(1);
	  		  		  		  		break;
	  		  	case 9:
	  		  		  		  		display7segment1(0);
	  		  		  		  		break;
	  		  	}
	  		  temp1++;
	  		  if (temp1 >= 10) temp1 = 0;
	  	  HAL_Delay(1000);
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_RED_Pin|LED_YELLOW_Pin|LED_GREEN_Pin|LED_RED_2_Pin
                          |LED_YELLOW_2_Pin|LED_GREEN_2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, a_Pin|b_Pin|c_Pin|d1_Pin
                          |e1_Pin|f1_Pin|g1_Pin|d_Pin
                          |e_Pin|f_Pin|g_Pin|a1_Pin
                          |b1_Pin|c1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_RED_Pin LED_YELLOW_Pin LED_GREEN_Pin LED_RED_2_Pin
                           LED_YELLOW_2_Pin LED_GREEN_2_Pin */
  GPIO_InitStruct.Pin = LED_RED_Pin|LED_YELLOW_Pin|LED_GREEN_Pin|LED_RED_2_Pin
                          |LED_YELLOW_2_Pin|LED_GREEN_2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : a_Pin b_Pin c_Pin d1_Pin
                           e1_Pin f1_Pin g1_Pin d_Pin
                           e_Pin f_Pin g_Pin a1_Pin
                           b1_Pin c1_Pin */
  GPIO_InitStruct.Pin = a_Pin|b_Pin|c_Pin|d1_Pin
                          |e1_Pin|f1_Pin|g1_Pin|d_Pin
                          |e_Pin|f_Pin|g_Pin|a1_Pin
                          |b1_Pin|c1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
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
void display7segment1(int num){
	if (num == 0){
		HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, RESET);
		HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, RESET);
		HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, RESET);
		HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, RESET);
		HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, RESET);
		HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, RESET);
		HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, SET);
	}
	if (num == 1){
			HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, SET);
			HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, RESET);
			HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, RESET);
			HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, SET);
			HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, SET);
			HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, SET);
			HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, SET);
		}
	if (num == 2){
			HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, RESET);
			HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, RESET);
			HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, SET);
			HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, RESET);
			HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, RESET);
			HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, SET);
			HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, RESET);
		}
	if (num == 3){
			HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, RESET);
			HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, RESET);
			HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, RESET);
			HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, RESET);
			HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, SET);
			HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, SET);
			HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, RESET);
		}
	if (num == 4){
			HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, SET);
			HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, RESET);
			HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, RESET);
			HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, SET);
			HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, SET);
			HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, RESET);
			HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, RESET);
		}
	if (num == 5){
			HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, RESET);
			HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, SET);
			HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, RESET);
			HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, RESET);
			HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, SET);
			HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, RESET);
			HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, RESET);
		}
	if (num == 6){
			HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, RESET);
			HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, SET);
			HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, RESET);
			HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, RESET);
			HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, RESET);
			HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, RESET);
			HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, RESET);
		}
	if (num == 7){
			HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, RESET);
			HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, RESET);
			HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, RESET);
			HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, SET);
			HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, SET);
			HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, SET);
			HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, SET);
		}
	if (num == 8){
			HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, RESET);
			HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, RESET);
			HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, RESET);
			HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, RESET);
			HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, RESET);
			HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, RESET);
			HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, RESET);
		}
	if (num == 9){
			HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, RESET);
			HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, RESET);
			HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, RESET);
			HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, RESET);
			HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, SET);
			HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, RESET);
			HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, RESET);
		}
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
