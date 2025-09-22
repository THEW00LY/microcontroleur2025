#include "stm32f10x.h"

int main ( void )
{
	
	RCC->APB2ENR |= (0x01 << 2) | (0x01 << 3) | (0x01 << 4) ;
	
	//configuration de PC6
	GPIOC->CRL = GPIOC->CRL &~ (0xD<<(4*6+1));
	GPIOC->CRL = GPIOC->CRL | (0x1<<(4*6+1));
	

	//mise du bit 6 à 1 
	GPIOC->ODR |= (0x01 << 6);
	
	while (1)
	{
		if ((GPIOC->IDR & (0x01 << 8)) == GPIO_IDR_IDR8) {
			GPIOC->ODR = GPIOC->ODR & (0x20);
		} else {
			GPIOC->ODR |= (0x01 << 6);
		}
	}

}
