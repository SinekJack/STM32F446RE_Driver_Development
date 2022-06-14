/*
 * stm32f446xx.h
 *
 *  Created on: Jun 13, 2022
 *      Author: husey
 */

#ifndef INC_STM32F446XX_H_
#define INC_STM32F446XX_H_

#include <stdint.h>

/*Memory Base Addresses */
#define SRAM1_BASE_ADDR		0x20000000U
#define SRAM2_BASE_ADDR		0x2001C000U
#define FLASH_BASE_ADDR		0x08000000U

/*Bus base addresses */
#define	APB1_BASE_ADDR		0x40000000U
#define APB2_BASE_ADDR		0x40010000U
#define AHB1_BASE_ADDR		0x40020000U
#define AHB2_BASE_ADDR		0x50000000U
#define	AHB3_BASE_ADDR		0x60000000U

/*Peripherals Base Addresses */
#define TIM2_BASE_ADDR		APB1_BASE_ADDR
#define TIM3_BASE_ADDR		0x40000400U
#define TIM4_BASE_ADDR		0x40000800U
#define TIM5_BASE_ADDR		0x40000C00U
#define TIM6_BASE_ADDR		0x40001000U
#define TIM7_BASE_ADDR		0x40001400U
#define TIM12_BASE_ADDR		0x40001800U
#define TIM13_BASE_ADDR		0x40001C00U
#define TIM14_BASE_ADDR		0x40002000U
#define RTCBKP_BASE_ADDR	0x40002800U
#define WWDG_BASE_ADDR		0x40002C00U
#define IWDG_BASE_ADDR		0x40003000U
#define SPI2_BASE_ADDR		0x40003800U
#define SPI3_BASE_ADDR		0x40003C00U
#define SPDIFRX_BASE_ADDR	0x40004000U
#define USART2_BASE_ADDR	0x40004400U
#define USART3_BASE_ADDR	0x40004800U
#define UART4_BASE_ADDR		0x40004C00U
#define UART5_BASE_ADDR		0x40005000U
#define I2C1_BASE_ADDR		0x40005400U
#define I2C2_BASE_ADDR		0x40005800U
#define I2C3_BASE_ADDR		0x40005C00U
#define CAN1_BASE_ADDR		0x40006400U
#define CAN2_BASE_ADDR		0x40006800U
#define HDMI_BASE_ADDR		0x40006C00U
#define PWR_BASE_ADDR		0x40007000U
#define DAC_BASE_ADDR		0x40007400U
#define TIM1_BASE_ADDR		APB2_BASE_ADDR
#define TIM8_BASE_ADDR		0x40010400U
#define USART1_BASE_ADDR	0x40011000U
#define USART6_BASE_ADDR	0x40011400U
#define ADC_BASE_ADDR		0x40012000U
#define SDMMC_BASE_ADDR		0x40012C00U
#define SPI1_BASE_ADDR		0x40013000U
#define SPI4_BASE_ADDR		0x40013400U
#define SYSCFG_BASE_ADDR	0x40013800U
#define EXTI_BASE_ADDR		0x40013C00U
#define TIM9_BASE_ADDR		0x40014000U
#define TIM10_BASE_ADDR		0x40014400U
#define TIM11_BASE_ADDR		0x40014800U
#define SAI1_BASE_ADDR		0x40015800U
#define SAI2_BASE_ADDR		0x40015C00U
#define GPIOA_BASE_ADDR		AHB1_BASE_ADDR
#define GPIOB_BASE_ADDR		0x40020400U
#define GPIOC_BASE_ADDR		0x40020800U
#define GPIOD_BASE_ADDR		0x40020C00U
#define GPIOE_BASE_ADDR		0x40021000U
#define GPIOF_BASE_ADDR		0x40021400U
#define GPIOG_BASE_ADDR		0x40021800U
#define GPIOH_BASE_ADDR		0x40021C00U
#define CRC_BASE_ADDR		0x40023000U
#define RCC_BASE_ADDR		0x40023800U
#define FLASHIN_BASE_ADDR	0x40023C00U
#define BKPSRAM_BASE_ADDR	0x40024000U
#define DMA1_BASE_ADDR		0x40026000U
#define DMA2_BASE_ADDR		0x40026400U
#define USBHS_BASE_ADDR		0x40040000U
#define USBFS_BASE_ADDR		AHB2_BASE_ADDR
#define DCMI_BASE_ADDR		0x50050000U

#define __vo				volatile
/*Gpio Register Structure*/
typedef struct
{
	__vo uint32_t MODER;
	__vo uint32_t OTYPER;
	__vo uint32_t SPEED;
	__vo uint32_t PUPD;
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSRR;
	__vo uint32_t LCKR;
	__vo uint32_t AFR[2];
}GPIO_RegDef_t;

/*RCC Register Structure*/
typedef struct
{
	__vo uint32_t CR;
	__vo uint32_t PLL_CFGR;
	__vo uint32_t CFGR;
	__vo uint32_t CIR;
	__vo uint32_t AHB1RSTR;
	__vo uint32_t AHB2RSTR;
	__vo uint32_t AHB3RSTR;
	uint32_t RESERVED;
	__vo uint32_t APB1RSTR;
	__vo uint32_t APB2RSTR;
	uint32_t RESERVED2[2];
	__vo uint32_t AHB1ENR;
	__vo uint32_t AHB2ENR;
	__vo uint32_t AHB3ENR;
	uint32_t RESERVED3;
	__vo uint32_t APB1ENR;
	__vo uint32_t APB2ENR;
	uint32_t RESERVED4[2];
	__vo uint32_t AHB1LPENR;
	__vo uint32_t AHB2LPENR;
	__vo uint32_t AHB3LPENR;
	uint32_t RESERVED5;
	__vo uint32_t APB1LPENR;
	__vo uint32_t APB2LPENR;
	uint32_t RESERVED6[2];
	__vo uint32_t BDCR;
	__vo uint32_t CSR;
	uint32_t RESERVED7[2];
	__vo uint32_t SSCGR;
	__vo uint32_t PLLI2SCFGR;
	__vo uint32_t PLLSAICFGR;
	__vo uint32_t DCKCFGR;
	__vo uint32_t CKGATEENR;
	__vo uint32_t DCKCFGR2;
}RCC_RegDef_t;

/*EXTI Register Definition Structure*/
typedef struct
{
	__vo uint32_t EXTI_IMR;
	__vo uint32_t EXTI_EMR;
	__vo uint32_t EXTI_RTSR;
	__vo uint32_t EXTI_FTSR;
	__vo uint32_t EXTI_SWIER;
	__vo uint32_t EXTI_PR;
}EXTI_Regdef_t;

/*SYSCFG Register Definition Structure*/
typedef struct
{
	__vo uint32_t MEMRMP;
	__vo uint32_t PMC;
	__vo uint32_t EXTICR[4];
	__vo uint32_t CMPCR;
	__vo uint32_t CFGR;
}SYSCFG_Regdef_t;

/*
 * ARM Cortex Mx Processor NVIC ISERx register Addresses
 */

#define NVIC_ISER0          ( (__vo uint32_t*)0xE000E100 )
#define NVIC_ISER1          ( (__vo uint32_t*)0xE000E104 )
#define NVIC_ISER2          ( (__vo uint32_t*)0xE000E108 )
#define NVIC_ISER3          ( (__vo uint32_t*)0xE000E10c )

/*
 * ARM Cortex Mx Processor NVIC ICERx register Addresses
 */
#define NVIC_ICER0 			((__vo uint32_t*)0XE000E180)
#define NVIC_ICER1			((__vo uint32_t*)0XE000E184)
#define NVIC_ICER2  		((__vo uint32_t*)0XE000E188)
#define NVIC_ICER3			((__vo uint32_t*)0XE000E18C)

/*
 * ARM Cortex Mx Processor Priority Register Address Calculation
 */
#define NVIC_PR_BASE_ADDR 	((__vo uint32_t*)0xE000E400)

/*PORT,RCC,EXTI etc definitions */
#define RCC				((RCC_RegDef_t*)RCC_BASE_ADDR)
#define GPIOA   		((GPIO_RegDef_t*)GPIOA_BASE_ADDR)
#define GPIOB   		((GPIO_RegDef_t*)GPIOB_BASE_ADDR)
#define GPIOC   		((GPIO_RegDef_t*)GPIOC_BASE_ADDR)
#define GPIOD   		((GPIO_RegDef_t*)GPIOD_BASE_ADDR)
#define GPIOE   		((GPIO_RegDef_t*)GPIOE_BASE_ADDR)
#define GPIOF   		((GPIO_RegDef_t*)GPIOF_BASE_ADDR)
#define GPIOG   		((GPIO_RegDef_t*)GPIOG_BASE_ADDR)
#define GPIOH   		((GPIO_RegDef_t*)GPIOH_BASE_ADDR)
#define EXTI			((EXTI_Regdef_t*)EXTI_BASE_ADDR)
#define SYSCFG			((SYSCFG_Regdef_t*)SYSCFG_BASE_ADDR)


/*Clock enable macros*/
#define GPIOA_CLK_EN()	(RCC->AHB1ENR |= (1 << 0))
#define GPIOB_CLK_EN()	(RCC->AHB1ENR |= (1 << 1))
#define GPIOC_CLK_EN()	(RCC->AHB1ENR |= (1 << 2))
#define GPIOD_CLK_EN()	(RCC->AHB1ENR |= (1 << 3))
#define GPIOE_CLK_EN()	(RCC->AHB1ENR |= (1 << 4))
#define GPIOF_CLK_EN()	(RCC->AHB1ENR |= (1 << 5))
#define GPIOG_CLK_EN()	(RCC->AHB1ENR |= (1 << 6))
#define GPIOH_CLK_EN()	(RCC->AHB1ENR |= (1 << 7))

/*Clock Disable Macros*/
#define GPIOA_CLK_DIS()	(RCC->AHB1ENR &= ~(1 << 0))
#define GPIOB_CLK_DIS()	(RCC->AHB1ENR &= ~(1 << 1))
#define GPIOC_CLK_DIS()	(RCC->AHB1ENR &= ~(1 << 2))
#define GPIOD_CLK_DIS()	(RCC->AHB1ENR &= ~(1 << 3))
#define GPIOE_CLK_DIS()	(RCC->AHB1ENR &= ~(1 << 4))
#define GPIOF_CLK_DIS()	(RCC->AHB1ENR &= ~(1 << 5))
#define GPIOG_CLK_DIS()	(RCC->AHB1ENR &= ~(1 << 6))
#define GPIOH_CLK_DIS()	(RCC->AHB1ENR &= ~(1 << 7))

/*Port reset macros*/
#define GPIOA_RST()		do{ RCC->AHB1RSTR |= (1 << 0); RCC->AHB1RSTR &= ~(1 << 0);}while(0)
#define GPIOB_RST()		do{ RCC->AHB1RSTR |= (1 << 1); RCC->AHB1RSTR &= ~(1 << 1);}while(0)
#define GPIOC_RST()		do{ RCC->AHB1RSTR |= (1 << 2); RCC->AHB1RSTR &= ~(1 << 2);}while(0)
#define GPIOD_RST()		do{ RCC->AHB1RSTR |= (1 << 3); RCC->AHB1RSTR &= ~(1 << 3);}while(0)
#define GPIOE_RST()		do{ RCC->AHB1RSTR |= (1 << 4); RCC->AHB1RSTR &= ~(1 << 4);}while(0)
#define GPIOF_RST()		do{ RCC->AHB1RSTR |= (1 << 5); RCC->AHB1RSTR &= ~(1 << 5);}while(0)
#define GPIOG_RST()		do{ RCC->AHB1RSTR |= (1 << 6); RCC->AHB1RSTR &= ~(1 << 6);}while(0)
#define GPIOH_RST()		do{ RCC->AHB1RSTR |= (1 << 7); RCC->AHB1RSTR &= ~(1 << 7);}while(0)

/*SYSCFG CLK Enable/Disable Macro */
#define SYSCFG_CLK_EN()	(RCC->APB2ENR |= (1 << 14))
#define SYSCFG_CLK_DIS()	(RCC->APB2ENR &= ~(1 << 14))

/*IRQ Macros*/
#define IRQ_EXTI0			6
#define IRQ_EXTI1			7
#define IRQ_EXTI2			8
#define IRQ_EXTI3			9
#define IRQ_EXTI9_5			23
#define IRQ_EXTI15_10		40

/*Some Generic Macros*/
#define ENABLE				1
#define DISABLE				0
#define SET					ENABLE
#define RESET				DISABLE

#define BITS_FOR_NVIC_PRI	4

#define GPIO_BASEADDR_TO_CODE(x)      ( (x == GPIOA)?0:\
										(x == GPIOB)?1:\
										(x == GPIOC)?2:\
										(x == GPIOD)?3:\
								        (x == GPIOE)?4:\
								        (x == GPIOF)?5:\
								        (x == GPIOG)?6:\
								        (x == GPIOH)?7:0)

#include "stm32f446xx_gpio.h"


#endif /* INC_STM32F446XX_H_ */
