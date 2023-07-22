#ifndef RCC_H
#define RCC_H

#include "stm32f10x.h"

enum RCC_GpioPortName_t{
	RCC_GPIO_PORT_A,
	RCC_GPIO_PORT_B,
	RCC_GPIO_PORT_C
};


enum RCC_ErrorType_t{
	RCC_OK,
	RCC_NOK,
	RCC_DEFAULT_ERROR = 0XFF
};

class rcc 
{
	
	public:
		RCC_ErrorType_t rcc_ERR;
		rcc();
		RCC_ErrorType_t RCC_gpioPortInit(RCC_GpioPortName_t copy_gpioPortName);
	
	
	private:
		
	
	
	
	
};


#endif