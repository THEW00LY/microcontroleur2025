#include "Driver_GPIO.h"


void MyGPIO_Init(GPIO_TypeDef *GPIO, int pin, int conf){
	//On lance le clock mettre le if pour les clock
	if (GPIO == GPIOA){
		RCC->APB2ENR |= 	RCC_APB2ENR_IOPAEN;
	}
	if (GPIO == GPIOB){
		RCC->APB2ENR |= 	RCC_APB2ENR_IOPBEN;
	}
	if (GPIO == GPIOC){
		RCC->APB2ENR |= 	RCC_APB2ENR_IOPCEN;
	}
	if (GPIO == GPIOD){
		RCC->APB2ENR |= 	RCC_APB2ENR_IOPDEN;
	}
	if (GPIO == GPIOE){
		RCC->APB2ENR |= 	RCC_APB2ENR_IOPEEN;
	}
	
	
	//configuration du pin, verif CRL et CRH
	if (pin < 8)  {
		GPIO->CRL = GPIO->CRL &~ (0xF<<(4*pin));
		GPIO->CRL = GPIO->CRL | (conf<<(4*pin));
	}
	else 
	{
		GPIO->CRH = GPIO->CRH &~ (0xF<<(4*pin));
		GPIO->CRH = GPIO->CRH | (conf<<(4*pin));
	}
};
int MyGPIO_Read(GPIO_TypeDef *GPIO, int GPIO_Pin) {
	return GPIO->ODR = (0x01 << GPIO_Pin);
};
void MyGPIO_Set(GPIO_TypeDef *GPIO, int GPIO_Pin){
	GPIO->ODR |= (0x01 << GPIO_Pin);
};
void MyGPIO_Reset(GPIO_TypeDef *GPIO, int GPIO_Pin){
	GPIO->ODR = (0x00 << GPIO_Pin);
};
void MyGPIO_Toggle(GPIO_TypeDef *GPIO, int GPIO_Pin){
	//voir diff ODR / IDR ???
	if (MyGPIO_Read(GPIO, GPIO_Pin) == 1) {
		GPIO->ODR &= ~(0x1 << GPIO_Pin);
	} else{
		GPIO->ODR |= (0x01 << GPIO_Pin); 
	}
};
