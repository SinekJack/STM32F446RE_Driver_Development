/*
 * GPIO_Driver.c
 *
 *  Created on: Jun 13, 2022
 *      Author: husey
 */

#include <stdint.h>
#include "stm32f446xx.h"

void gpio_init(GPIO_Handle_t* pGPIOx)
{
	/*For non-IT*/
	if(pGPIOx->GPIO_PinConfig.mode <= MODE_ANALOG)
	{
		pGPIOx->pGPIOx->MODER &= ~(3 << (2 * pGPIOx->GPIO_PinConfig.pinNumber));
		pGPIOx->pGPIOx->MODER |= (pGPIOx->GPIO_PinConfig.mode << (2 * pGPIOx->GPIO_PinConfig.pinNumber));
	}
	else
	{
		//this part will code later . ( interrupt mode)
		if(pGPIOx->GPIO_PinConfig.mode == MODE_IT_FT )
		{
			//1. configure the FTSR
			EXTI->EXTI_FTSR |= ( 1 << pGPIOx->GPIO_PinConfig.pinNumber);
			//Clear the corresponding RTSR bit
			EXTI->EXTI_RTSR &= ~( 1 << pGPIOx->GPIO_PinConfig.pinNumber);

		}else if (pGPIOx->GPIO_PinConfig.mode == MODE_IT_RT )
		{
			//1 . configure the RTSR
			EXTI->EXTI_RTSR |= ( 1 << pGPIOx->GPIO_PinConfig.pinNumber);
			//Clear the corresponding RTSR bit
			EXTI->EXTI_FTSR &= ~( 1 << pGPIOx->GPIO_PinConfig.pinNumber);

		}else if (pGPIOx->GPIO_PinConfig.mode == MODE_IT_FRT )
		{
			//1. configure both FTSR and RTSR
			EXTI->EXTI_RTSR |= ( 1 << pGPIOx->GPIO_PinConfig.pinNumber);
			//Clear the corresponding RTSR bit
			EXTI->EXTI_FTSR |= ( 1 << pGPIOx->GPIO_PinConfig.pinNumber);
		}

		}
	/*SYSCFG Configuration*/
	uint8_t port = GPIO_BASEADDR_TO_CODE(pGPIOx->pGPIOx);
	uint8_t temp = pGPIOx->GPIO_PinConfig.pinNumber / 4;
	uint8_t temp2 = pGPIOx->GPIO_PinConfig.pinNumber % 4;
	SYSCFG_CLK_EN();
	SYSCFG->EXTICR[temp] = (port << (4 * temp2));

	/*Output Type*/
	pGPIOx->pGPIOx->OTYPER |= pGPIOx->GPIO_PinConfig.outputType << (pGPIOx->GPIO_PinConfig.pinNumber);
	/*Speed Settings*/
	pGPIOx->pGPIOx->SPEED  |= pGPIOx->GPIO_PinConfig.speed << (2 * pGPIOx->GPIO_PinConfig.pinNumber);
	/*Pull up Pull Down Settings*/
	pGPIOx->pGPIOx->PUPD   |= pGPIOx->GPIO_PinConfig.puPd  << (2 * pGPIOx->GPIO_PinConfig.pinNumber);
	/*Alternate Function Configuration*/
	if(pGPIOx->GPIO_PinConfig.mode == MODE_AF)
		{
		/*AF High or AF Low Register?*/
		uint8_t temp  = pGPIOx->GPIO_PinConfig.pinNumber / 8;
		/*Location of pin in alternate func*/
		uint8_t temp2 = pGPIOx->GPIO_PinConfig.pinNumber % 8;

		pGPIOx->pGPIOx->AFR[temp] |= (pGPIOx->GPIO_PinConfig.alternateFunc << (4 * temp2));

		}
}

void gpio_DeInit(GPIO_RegDef_t* pGPIOx)
{
	if(pGPIOx == GPIOA)
	{
		GPIOA_RST();
	}
	if(pGPIOx == GPIOB)
	{
		GPIOB_RST();
	}
	if(pGPIOx == GPIOC)
	{
		GPIOC_RST();
	}
	if(pGPIOx == GPIOD)
	{
		GPIOD_RST();
	}
	if(pGPIOx == GPIOE)
	{
		GPIOE_RST();
	}
	if(pGPIOx == GPIOF)
	{
		GPIOF_RST();
	}
	if(pGPIOx == GPIOG)
	{
		GPIOG_RST();
	}
	if(pGPIOx == GPIOH)
	{
		GPIOH_RST();
	}
}


uint8_t readFromInput(GPIO_RegDef_t* pGPIOx,uint8_t pinNo)
{
	uint8_t value = (uint8_t)((pGPIOx->IDR >> pinNo) & 0x00000001);
	return value;
}

void writeToOutput(GPIO_RegDef_t* pGPIOx,uint8_t pinNo,uint8_t SetorReset)
{
	if(SetorReset)
		pGPIOx->ODR |= (SET << pinNo);
	else
		pGPIOx->ODR &= ~(SET << pinNo);
}

void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi)
{

	if(EnorDi == ENABLE)
	{
		if(IRQNumber <= 31)
		{
			//program ISER0 register
			*NVIC_ISER0 |= ( 1 << IRQNumber );

		}else if(IRQNumber > 31 && IRQNumber < 64 ) //32 to 63
		{
			//program ISER1 register
			*NVIC_ISER1 |= ( 1 << (IRQNumber % 32) );
		}
		else if(IRQNumber >= 64 && IRQNumber < 96 )
		{
			//program ISER2 register //64 to 95
			*NVIC_ISER2 |= ( 1 << (IRQNumber % 64) );
		}
	}else
	{
		if(IRQNumber <= 31)
		{
			//program ICER0 register
			*NVIC_ICER0 |= ( 1 << IRQNumber );
		}else if(IRQNumber > 31 && IRQNumber < 64 )
		{
			//program ICER1 register
			*NVIC_ICER1 |= ( 1 << (IRQNumber % 32) );
		}
		else if(IRQNumber >= 64 && IRQNumber < 96 )
		{
			//program ICER2 register
			*NVIC_ICER2 |= ( 1 << (IRQNumber % 64) );
		}
	}

}


void GPIO_IRQPriorityConfig(uint8_t IRQNumber,uint32_t IRQPriority)
{
	//1. first lets find out the ipr register
	uint8_t iprx = IRQNumber / 4;
	uint8_t iprx_section  = IRQNumber %4 ;

	uint8_t shift_amount = ( 8 * iprx_section) + ( 8 - BITS_FOR_NVIC_PRI) ;

	*(  NVIC_PR_BASE_ADDR + iprx ) |=  ( IRQPriority << shift_amount );

}

/*Clearing Pending Bit(this function will be call by handler)*/
void GPIO_IRQHandling(uint8_t pinNumber)
{
	if(EXTI->EXTI_PR & (1 << pinNumber)) //if PR is equal to 1 than clear it.(clearing is done by sending 1)
	{
		EXTI->EXTI_PR |= (1 << pinNumber);
	}
}
