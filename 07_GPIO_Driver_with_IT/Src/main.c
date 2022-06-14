/*Button -> PC13
 *Led    -> PA5
 */


#include <stdint.h>
#include <string.h>
#include "stm32f446xx.h"

#define BTN_PIN_NO		13
#define LED_PIN_NO		5

void delay(void);

int main(void)
{
    GPIO_Handle_t Btn,Led;
    /*saving variables from garbage values*/
    memset(&Btn,0,sizeof(Btn));
    memset(&Led,0,sizeof(Led));

    Btn.pGPIOx = GPIOC;
    Btn.GPIO_PinConfig.mode      = MODE_IT_FT;
    Btn.GPIO_PinConfig.pinNumber = PIN_NO_13;
    Btn.GPIO_PinConfig.speed     = FAST_SPEED;

    GPIOC_CLK_EN();
    gpio_init(&Btn);

    Led.pGPIOx 				     = GPIOA;
    Led.GPIO_PinConfig.mode      = MODE_OUTPUT;
    Led.GPIO_PinConfig.pinNumber = PIN_NO_5;
    Led.GPIO_PinConfig.speed     = LOW_SPEED;

    GPIOA_CLK_EN();
    gpio_init(&Led);

    writeToOutput(GPIOA, PIN_NO_5, RESET);
    GPIO_IRQPriorityConfig(IRQ_EXTI15_10, 11);
    GPIO_IRQInterruptConfig(IRQ_EXTI15_10, ENABLE);

    while(1);

}

void EXTI15_10_IRQHandler(void)
{
	GPIO_IRQHandling(BTN_PIN_NO);
	writeToOutput(GPIOA, LED_PIN_NO, SET);
	delay();
	writeToOutput(GPIOA, LED_PIN_NO, RESET);
	delay();
}

void delay(void)
{
	for(int i = 0; i < 500000; i++);
}
