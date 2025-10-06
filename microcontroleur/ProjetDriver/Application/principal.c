#include "stm32f10x.h"
#include "Driver_GPIO.h"

int main ( void )
{
	
		MyGPIO_Init(GPIOC, 6, Out_Ppull);

	//mise du bit 6 à 1 
		MyGPIO_Set(GPIOC, 6);
	
	while (1)
	{
		if ((GPIOC->IDR & (0x01 << 8)) == GPIO_IDR_IDR8) {
			GPIOC->ODR = GPIOC->ODR & (0x20);
		} else {
			GPIOC->ODR |= (0x01 << 6);
		}
	}

}
