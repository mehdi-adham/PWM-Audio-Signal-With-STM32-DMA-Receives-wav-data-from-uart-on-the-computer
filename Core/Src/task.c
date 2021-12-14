/**
 ******************************************************************************
 * @file    task.h
 * @created 11/02/1398 9:01:22 AM
 * @author  Mehdi Adham
 * @brief   This file contains all the functions Event
 ******************************************************************************
 */

#include "main.h"
#include "task.h"
#include "Melody.h"

extern uint8_t get_data;
extern UART_HandleTypeDef huart1;
extern TIM_HandleTypeDef htim3;
extern DMA_HandleTypeDef hdma_tim4_ch1;
extern unsigned char rawData[];
uint16_t sampleCount = 0;
uint32_t cnt = 1;

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){
	if(huart -> Instance == USART1){
		//    HAL_UART_Transmit_IT(&huart1, (uint8_t *)0x00, 1);
	}
	UNUSED(huart);
}


extern uint8_t Wave[2][4096];
extern volatile uint8_t fp;
extern int ccc;
extern volatile uint8_t uartReciev_flag;


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){

	if(huart -> Instance == USART2){
	}

	if(huart ->Instance == USART1){
		//HAL_UART_Receive_IT(&huart1 ,rawData,15000);
		//HAL_UART_Receive_DMA(&huart1, rawData, 15000);
		//HAL_DMA_Start_IT(&hdma_tim4_ch1, (uint32_t)rawData, (uint32_t) &(TIM2->CCR1), 15000);
		// HAL_DMA_Start_IT(&hdma_tim4_ch1, ((uint32_t)rawData + 512), (uint32_t) &(TIM1->CCR1), 15000);
		//cnt = 16000;

		//HAL_UART_Receive_DMA(&huart1, &Wave, 4096);
		uartReciev_flag=1;
	}


	UNUSED(huart);
}

void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
{
	if(huart ->Instance == USART1){

	}
	UNUSED(huart);

}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){

	if(htim -> Instance == TIM4){

/*if(sampleCount<15000  && cnt>=15000){

			TIM2->CCR1 = (rawData[sampleCount++]);

			//TIM2->CCR2 = ((rawData[sampleCount++]*3/4));
		}

		if(sampleCount>=15000){
			sampleCount = cnt = 0;
		}*/

	}

	UNUSED(htim);
}



/*
void DMA_IRQHandler(DMA_HandleTypeDef *hdma){

}*/
