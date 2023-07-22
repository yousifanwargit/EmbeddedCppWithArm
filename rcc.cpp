

#include "rcc.h"

RCC_TypeDef* RCC_MemoryMapBase = ((RCC_TypeDef *) RCC_BASE);


rcc::rcc(){
	
	rcc_ERR = RCC_OK;
		
}


RCC_ErrorType_t rcc::RCC_gpioPortInit(RCC_GpioPortName_t copy_gpioPortName){
	
	RCC_ErrorType_t err_return = RCC_DEFAULT_ERROR;
	switch(copy_gpioPortName){
		
		case RCC_GPIO_PORT_A:
													RCC_MemoryMapBase->APB2ENR |= RCC_APB2ENR_IOPAEN;
													
													break;
		case RCC_GPIO_PORT_B:
													RCC_MemoryMapBase->APB2ENR |= RCC_APB2ENR_IOPBEN;
													
													break;
		case RCC_GPIO_PORT_C:
													RCC_MemoryMapBase->APB2ENR |= RCC_APB2ENR_IOPCEN;
													
													break;
		default :
													rcc_ERR = RCC_NOK;
													break;

	}
	return err_return;
}


