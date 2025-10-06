#include "stm32f10x.h"
#include "Driver_GPIO.h"

int main ( void )
{
	RCC->APB1ENR|=	RCC_APB1ENR_TIM2EN;
	TIM2->ARR = 0;
	TIM2->PSC = 0;
}
