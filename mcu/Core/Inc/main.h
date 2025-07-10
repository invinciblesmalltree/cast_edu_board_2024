/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define OLED_RES_Pin GPIO_PIN_13
#define OLED_RES_GPIO_Port GPIOC
#define OLED_DC_Pin GPIO_PIN_14
#define OLED_DC_GPIO_Port GPIOC
#define ENCODER_SW_Pin GPIO_PIN_15
#define ENCODER_SW_GPIO_Port GPIOC
#define LED_R_Pin GPIO_PIN_0
#define LED_R_GPIO_Port GPIOA
#define ENCODER_B_Pin GPIO_PIN_1
#define ENCODER_B_GPIO_Port GPIOA
#define ENCODER_B_EXTI_IRQn EXTI1_IRQn
#define LED_G_Pin GPIO_PIN_2
#define LED_G_GPIO_Port GPIOA
#define LED_B_Pin GPIO_PIN_3
#define LED_B_GPIO_Port GPIOA
#define BZ_Pin GPIO_PIN_6
#define BZ_GPIO_Port GPIOA
#define USER_KEY1_Pin GPIO_PIN_0
#define USER_KEY1_GPIO_Port GPIOB
#define USER_KEY2_Pin GPIO_PIN_1
#define USER_KEY2_GPIO_Port GPIOB
#define KEY_Y0_Pin GPIO_PIN_12
#define KEY_Y0_GPIO_Port GPIOB
#define KEY_Y1_Pin GPIO_PIN_13
#define KEY_Y1_GPIO_Port GPIOB
#define KEY_Y2_Pin GPIO_PIN_14
#define KEY_Y2_GPIO_Port GPIOB
#define KEY_Y3_Pin GPIO_PIN_15
#define KEY_Y3_GPIO_Port GPIOB
#define KEY_X0_Pin GPIO_PIN_8
#define KEY_X0_GPIO_Port GPIOA
#define KEY_X1_Pin GPIO_PIN_9
#define KEY_X1_GPIO_Port GPIOA
#define KEY_X2_Pin GPIO_PIN_10
#define KEY_X2_GPIO_Port GPIOA
#define KEY_X3_Pin GPIO_PIN_11
#define KEY_X3_GPIO_Port GPIOA
#define ENCODER_A_Pin GPIO_PIN_15
#define ENCODER_A_GPIO_Port GPIOA
#define ENCODER_A_EXTI_IRQn EXTI15_10_IRQn

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
