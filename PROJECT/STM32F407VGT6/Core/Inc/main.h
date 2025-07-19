/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
#define motorA_IN1_Pin GPIO_PIN_2
#define motorA_IN1_GPIO_Port GPIOE
#define motorA_IN2_Pin GPIO_PIN_3
#define motorA_IN2_GPIO_Port GPIOE
#define motorB_IN1_Pin GPIO_PIN_4
#define motorB_IN1_GPIO_Port GPIOE
#define motorB_IN2_Pin GPIO_PIN_5
#define motorB_IN2_GPIO_Port GPIOE
#define KEY1_Pin GPIO_PIN_0
#define KEY1_GPIO_Port GPIOC
#define KEY2_Pin GPIO_PIN_1
#define KEY2_GPIO_Port GPIOC
#define BUZZ_Pin GPIO_PIN_2
#define BUZZ_GPIO_Port GPIOC
#define MOTOR4_PWM_Pin GPIO_PIN_0
#define MOTOR4_PWM_GPIO_Port GPIOA
#define MOTOR3_PWM_Pin GPIO_PIN_1
#define MOTOR3_PWM_GPIO_Port GPIOA
#define MOTOR2_PWM_Pin GPIO_PIN_2
#define MOTOR2_PWM_GPIO_Port GPIOA
#define MOTOR1_PWM_Pin GPIO_PIN_3
#define MOTOR1_PWM_GPIO_Port GPIOA
#define ENCODERB_1_Pin GPIO_PIN_6
#define ENCODERB_1_GPIO_Port GPIOA
#define ENCODERB_2_Pin GPIO_PIN_7
#define ENCODERB_2_GPIO_Port GPIOA
#define OUT1_Pin GPIO_PIN_7
#define OUT1_GPIO_Port GPIOE
#define OUT2_Pin GPIO_PIN_8
#define OUT2_GPIO_Port GPIOE
#define OUT3_Pin GPIO_PIN_10
#define OUT3_GPIO_Port GPIOE
#define OUT4_Pin GPIO_PIN_11
#define OUT4_GPIO_Port GPIOE
#define OUT5_Pin GPIO_PIN_12
#define OUT5_GPIO_Port GPIOE
#define OUT6_Pin GPIO_PIN_13
#define OUT6_GPIO_Port GPIOE
#define OUT7_Pin GPIO_PIN_14
#define OUT7_GPIO_Port GPIOE
#define OUT8_Pin GPIO_PIN_15
#define OUT8_GPIO_Port GPIOE
#define SERVO_PWM2_Pin GPIO_PIN_14
#define SERVO_PWM2_GPIO_Port GPIOB
#define SERVO_PWM1_Pin GPIO_PIN_15
#define SERVO_PWM1_GPIO_Port GPIOB
#define ENCODERA_1_Pin GPIO_PIN_12
#define ENCODERA_1_GPIO_Port GPIOD
#define ENCODERA_2_Pin GPIO_PIN_13
#define ENCODERA_2_GPIO_Port GPIOD
#define TTL_TX_Pin GPIO_PIN_9
#define TTL_TX_GPIO_Port GPIOA
#define TTL_RX_Pin GPIO_PIN_10
#define TTL_RX_GPIO_Port GPIOA
#define HS100_TX_Pin GPIO_PIN_10
#define HS100_TX_GPIO_Port GPIOC
#define Hs100_RX_Pin GPIO_PIN_11
#define Hs100_RX_GPIO_Port GPIOC
#define HC06_RX_Pin GPIO_PIN_12
#define HC06_RX_GPIO_Port GPIOC
#define HC06_TX_Pin GPIO_PIN_2
#define HC06_TX_GPIO_Port GPIOD
#define JY62_TX_Pin GPIO_PIN_5
#define JY62_TX_GPIO_Port GPIOD
#define JY62_RX_Pin GPIO_PIN_6
#define JY62_RX_GPIO_Port GPIOD
#define OLED_SCL_Pin GPIO_PIN_6
#define OLED_SCL_GPIO_Port GPIOB
#define OLED_SDA_Pin GPIO_PIN_7
#define OLED_SDA_GPIO_Port GPIOB
#define motorD_IN2_Pin GPIO_PIN_8
#define motorD_IN2_GPIO_Port GPIOB
#define motorD_IN1_Pin GPIO_PIN_9
#define motorD_IN1_GPIO_Port GPIOB
#define motorC_IN2_Pin GPIO_PIN_0
#define motorC_IN2_GPIO_Port GPIOE
#define motorC_IN1_Pin GPIO_PIN_1
#define motorC_IN1_GPIO_Port GPIOE

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
