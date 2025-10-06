#include "Driver_GPIO.h"


void MyGPIO_Init(GPIO_TypeDef *GPIO, int pin, int conf){
	//On lance le clock mettre le if pour les clock
	RCC->APB2ENR |= 	(0x01 << 2) | (0x01 << 3) | (0x01 << 4);
	
	
	
	//configuration du pin, verif CRL et CRH

	GPIOC->CRL = GPIO->CRL &~ (0xF<<(4*pin));
	GPIOC->CRL = GPIO->CRL | (conf<<(4*pin));
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
	if (MyGPIO_Read(GPIO, GPIO_Pin) == 1) {
		GPIO->ODR &= ~(0x1 << GPIO_Pin);
	} else{
		GPIO->ODR |= (0x01 << GPIO_Pin); 
	}
};
