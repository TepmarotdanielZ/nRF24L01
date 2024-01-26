/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
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
#include "adc.h"
#include "dma.h"
#include "spi.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

		#include "NRF24L01.h"


/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

	/* nRF24l01 */

		uint8_t Rxaddr[5] = {'S','T','E','A','M'};
		uint8_t TxData[8] = {0};


		/* ADC */

			int ADC_Read[2] = {0};
			int Button1 = 0;
			int Joystick_x = 0;
			int Joystick_y = 0;
			int Omega = 0;
			int State_button = 0;
			int Switch = 0;
			int i, j;
			long last_time = 0, current_time = 0;;

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

		/* MAP JOYSTICK */

			double map(double x, double in_min, double in_max, double out_min, double out_max) {
			  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
			}



			/* SEND DATE nRF24l01_Master TO RECIEVER (TX TO RX) */

				void nRF24l01_Master(){
					  TxData[0] = i;
					  TxData[1] = j;
					  TxData[2] = 0;
					  TxData[3] = 5;
					  TxData[4] = 6;
					  TxData[5] = 7;
					  TxData[6] = 8;
					  TxData[7] = 10;


					  /* NRF24_Transmit(data, size) */

							NRF24_Transmit(TxData, 8);
							HAL_Delay(5);
				}


		/* MAP JOYSTICK */

			void Joystick() {
				  if (ADC_Read[0] >= 0 && ADC_Read[0] <= 120){
					  Joystick_x = map(ADC_Read[0], 0, 120, 0, 90);
				  }
				  if (ADC_Read[0] >= 130 && ADC_Read[0] <= 255){
					  Joystick_x = map(ADC_Read[0], 130, 255, 90, 180);
				  }
				  if (ADC_Read[0] > 120 && ADC_Read[0] < 130){
					  Joystick_x = 90;
				  }

				  if (ADC_Read[1] >= 0 && ADC_Read[1] <= 120){
					  Joystick_y = map(ADC_Read[1], 0, 120, 0, 90);
				  }
				  if (ADC_Read[1] >= 130 && ADC_Read[1] <= 255){
					  Joystick_y = map(ADC_Read[1], 130, 255, 90, 180);
				  }
				  if (ADC_Read[1] > 120 && ADC_Read[1] < 130){
					  Joystick_y = 90;
				  }

				  if (Switch == 0){
					  Joystick_y = Joystick_y;
					  Omega = 128;
				  }
				  else {
					  Omega = Joystick_y;
					  Joystick_y = 128;
				  }
			}



/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

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
  MX_DMA_Init();
  MX_ADC1_Init();
  MX_SPI1_Init();
  /* USER CODE BEGIN 2 */

	  /* nRF24L01 */

		  NRF24_Init();
		  NRF24_TxMode(Rxaddr, 112, 8);

	  /* ADC JOYSTICK */

	  	  HAL_ADC_Start_DMA(&hadc1, &ADC_Read, 2);


	  	  HAL_Delay(50);


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

	  	  /* BUTTON SWITCH FROM JOYSTICK */


			  Button1 = HAL_GPIO_ReadPin(Button1_GPIO_Port, Button1_Pin);

			  if (Button1 == 0 && State_button == 0){
				  State_button = 1;
				  last_time = HAL_GetTick();
			  }
			  if (Button1 == 1 && State_button == 1){
				  State_button = 0;
				  current_time = HAL_GetTick();
			  }
			  if (current_time - last_time > 100){
				  last_time = current_time;
				  Switch = !Switch;
			  }
			  Joystick();

	     /* SEND DATA ANGLE SERVO */

			 /* SERVO 1 */

				/* COUNT SERVO 1 : i++ */

					  if(Joystick_x > 90 ){
						  current_time=HAL_GetTick();
						  if (current_time - last_time > 1){
								i++;
							  if (i>180) i=180;
								  last_time = current_time;
								}
					  }

				 /* COUNT SERVO 1: i-- */

					  if(Joystick_x < 90 ){
					  	  current_time=HAL_GetTick();
						  if (current_time - last_time > 1){
						      	 i--;
						      if (i<0) i = 0;
						      	  last_time = current_time;
							  }
					 }


			/* SERVO 2 */

				/* COUNT SERVO 2: i++ */

					  if(Joystick_y > 90 ){
						  current_time=HAL_GetTick();
						  if (current_time - last_time > 1){
							  	 j++;
							  if (i>180) i=180;
								 last_time = current_time;
						  	  }
					}

				/* COUNT SERVO 2: i-- */

					  if(Joystick_y < 90 ){
						  current_time=HAL_GetTick();
						  if (current_time - last_time > 1){
								j--;
							if (i<0) i = 0;
								last_time = current_time;
						  	  }
					}




		  /* DATA MASTER */

			 nRF24l01_Master();

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

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

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
