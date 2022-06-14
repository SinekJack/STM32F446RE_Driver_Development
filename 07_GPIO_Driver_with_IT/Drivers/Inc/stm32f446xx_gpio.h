/*
 * stm32f446xx_gpio.h
 *
 *  Created on: Jun 13, 2022
 *      Author: husey
 */

#ifndef INC_STM32F446XX_GPIO_H_
#define INC_STM32F446XX_GPIO_H_

#include "stm32f446xx.h"

/*GPIO Mode Macros*/
#define MODE_INPUT		0
#define MODE_OUTPUT		1
#define MODE_AF			2
#define MODE_ANALOG		3
#define MODE_IT_FT		4
#define MODE_IT_RT		5
#define MODE_IT_FRT		6

/*GPIO OType Macros*/
#define PUSH_PULL		0
#define OPEN_DRAIN		1

/*GPIO Speed Macros*/
#define LOW_SPEED		0
#define MEDIUM_SPEED	1
#define FAST_SPEED		2
#define HIGH_SPEED		3

/*GPIO Pull-Up/Pull-Down Macros*/
#define	NO_PUPD			0
#define PULLUP			1
#define PULLDOWN		2

/*GPIO Alternate Function Macros*/
#define AF0				0
#define AF1				1
#define AF2				2
#define AF3				3
#define AF4				4
#define AF5				5
#define AF6				6
#define AF7				7
#define AF8				8
#define AF9				9
#define AF10			10
#define AF11			11
#define AF12			12
#define AF13			13
#define AF14			14
#define AF15			15

/*GPIO Pin Numbers*/
#define PIN_NO_0		0
#define PIN_NO_1		1
#define PIN_NO_2		2
#define PIN_NO_3		3
#define PIN_NO_4		4
#define PIN_NO_5		5
#define PIN_NO_6		6
#define PIN_NO_7		7
#define PIN_NO_8		8
#define PIN_NO_9		9
#define PIN_NO_10		10
#define PIN_NO_11		11
#define PIN_NO_12		12
#define PIN_NO_13		13
#define PIN_NO_14		14
#define PIN_NO_15		15


/*GPIO Configuration Structure*/
typedef struct
{
	uint8_t pinNumber;
	uint8_t mode;
	uint8_t outputType;
	uint8_t speed;
	uint8_t puPd;
	uint8_t alternateFunc;
}GPIO_Config_t;

/*GPIO Handle Structure*/
typedef struct
{
	GPIO_RegDef_t*  pGPIOx;
	GPIO_Config_t   GPIO_PinConfig;
}GPIO_Handle_t;

void gpio_init(GPIO_Handle_t* GPIOx);
void gpio_DeInit(GPIO_RegDef_t* pGPIOx);
uint8_t readFromInput(GPIO_RegDef_t* pGPIOx,uint8_t pinNo);
void writeToOutput(GPIO_RegDef_t* pGPIOx,uint8_t pinNo,uint8_t SetorReset);
void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);
void GPIO_IRQPriorityConfig(uint8_t IRQNumber,uint32_t IRQPriority);
void GPIO_IRQHandling(uint8_t pinNumber);

#endif /* INC_STM32F446XX_GPIO_H_ */
