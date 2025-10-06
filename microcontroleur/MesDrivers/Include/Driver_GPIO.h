#ifndef MYGPIO_H
#define MYGPIO_H
#include "stm32f10x.h"

#define In_Floating	0x04
#define In_PullDown	0x08
#define In_PullUp	0x08
#define In_Analog	0x0
#define Out_Ppull	0x02
#define Out_OD	0x06
#define AltOut_Ppull	0x0A
#define AltOut_OD	0x0E

void MyGPIO_Init(GPIO_TypeDef *GPIO, int pin, int conf);
int MyGPIO_Read(GPIO_TypeDef *GPIO, int GPIO_Pin);
void MyGPIO_Set(GPIO_TypeDef *GPIO, int GPIO_Pin);
void MyGPIO_Reset(GPIO_TypeDef *GPIO, int GPIO_Pin);
void MyGPIO_Toggle(GPIO_TypeDef *GPIO, int GPIO_Pin);

#endif


/*
General purpose output
push pull 0010 0x2
open drain 0110 0x6
Alt
push pull 1010 0xA
open drain 1110 0xE

input
0000 0x0
0100 0x4
1000 0x8
*/