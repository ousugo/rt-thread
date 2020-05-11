/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-11-06     SummerGift   first version
 */
 
#include "board.h"

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;  //时钟源为 HSE
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;            //打开 HSE
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;   //HSE 预分频
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;            //打开 HSI
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;          //打开 PLL
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;      //PLL 时钟源选择 HSE
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;          //设置 PLL 倍频系数
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;   //设置系统时钟时钟源为 PLL
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;  //AHB 分频系数为1
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;   //APB1 分频系数为2
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;   //APB2 分频系数为1

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}
