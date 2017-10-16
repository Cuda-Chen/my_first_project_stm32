/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"

void delay(int counter)
{
	int i;
	for(i = 0; i < counter * 10000; i++) {}
}

int main(void)
{
	GPIO_InitTypeDef gpio;

	     RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	    GPIO_StructInit(&gpio);
	    gpio.GPIO_Pin = GPIO_Pin_5;
	    gpio.GPIO_Mode = GPIO_Mode_OUT;
	    GPIO_Init(GPIOA, &gpio);

	    GPIO_SetBits(GPIOA, GPIO_Pin_5);

	for(;;)
		{
		GPIO_SetBits(GPIOA, GPIO_Pin_5); // LED ON
		        delay(1000);
		        GPIO_ResetBits(GPIOA, GPIO_Pin_5); // LED OFF
		        delay(1000);
		}
}
