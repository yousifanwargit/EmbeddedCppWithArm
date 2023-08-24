#include"STD_TYPES.h"
#include "stm32f10x.h"
#include"gpio.h"
#include"rcc.h"


GPIO_TypeDef * gpio_RegArr[GPIO_PORT_MAX_NUMBER] = {GPIOA, GPIOB, GPIOC};

GPIO_PinConfig::GPIO_PinConfig(){
	
  pinConfigErr  = GPIO_OK;
  pinInitErr    = GPIO_OK;
	
}


GPIO_PinConfig::GPIO_PinConfig(GPIO_PortNumber_t portName, GPIO_PinNumber_t pinNumber, uint8 pinConfigMode, GPIO_PinState_t pinValue) :
	portName(portName), pinNumber(pinNumber), pinConfigMode(pinConfigMode), pinValue(pinValue){
	
	pinConfigErr  = GPIO_OK;
  pinInitErr    = GPIO_OK;

}
	

GPIO_ErrorType_t  GPIO_PinConfig::GPIO_PinConfigIsOk(){
	GPIO_ErrorType_t Local_ReturnErr = GPIO_OK;
	
	if((pinNumber < GPIO_PIN_MAX_NUMBER) && (portName < GPIO_PORT_MAX_NUMBER)){
		/* NOTHING */
	}
	else{

		pinConfigErr  = GPIO_OK;
		Local_ReturnErr = GPIO_OK;
		
	}
	
		return Local_ReturnErr;
}






	





gpio::gpio(GPIO_PortNumber_t Copy_PortName){
	
	gpioErr = GPIO_OK;
	switch(Copy_PortName){
		case RCC_GPIO_PORT_A:
		case RCC_GPIO_PORT_B:
		case RCC_GPIO_PORT_C:
					rcc::RCC_gpioPortInit((RCC_GpioPortName_t)Copy_PortName);
					break;
		default: 
					gpioErr = GPIO_NOK;
					break;
	}

}
GPIO_ErrorType_t gpio::GPIO_PinInit(GPIO_PinConfig* Copy_PinConfigs){
	GPIO_ErrorType_t Local_ReturnErr = GPIO_OK;
	
	if(Copy_PinConfigs->pinNumber < 8){
		gpio_RegArr[Copy_PinConfigs->portName]->CRL &= ~(0b1111 << (Copy_PinConfigs->pinNumber * 4)); 
		gpio_RegArr[Copy_PinConfigs->portName]->CRL |= (Copy_PinConfigs->pinConfigMode << (Copy_PinConfigs->pinNumber * 4)); 
	}
	else if(Copy_PinConfigs->pinNumber < 16){
		gpio_RegArr[Copy_PinConfigs->portName]->CRH &= ~(0b1111 << (((Copy_PinConfigs->pinNumber) - 8 ) * 4)); 
		gpio_RegArr[Copy_PinConfigs->portName]->CRH |= (Copy_PinConfigs->pinConfigMode << (((Copy_PinConfigs->pinNumber) - 8 ) * 4)); 
	}
	else{
		gpioErr = GPIO_NOK;
		Local_ReturnErr = GPIO_NOK;
	}
	return Local_ReturnErr;
}
GPIO_ErrorType_t gpio::GPIO_PinSetVal(GPIO_PinConfig* Copy_PinConfigs, GPIO_PinState_t Copy_PinState){
	GPIO_ErrorType_t Local_ReturnErr = GPIO_OK;
	if(Copy_PinConfigs->pinNumber < GPIO_PIN_MAX_NUMBER){
		if(Copy_PinState == GPIO_PIN_SET){
			gpio_RegArr[Copy_PinConfigs->portName]->ODR |= (Copy_PinState << Copy_PinConfigs->pinNumber); 
		}
		else if(Copy_PinState == GPIO_PIN_RESET){
			gpio_RegArr[Copy_PinConfigs->portName]->ODR &= ~(1 << Copy_PinConfigs->pinNumber); 
		}
		
		//gpio_RegArr[Copy_PinConfigs->portName]->ODR |= (1 << Copy_PinConfigs->pinNumber); 
	}
	else{
		gpioErr = GPIO_NOK;
		Local_ReturnErr = GPIO_NOK;
	}
	return Local_ReturnErr;
	
}
GPIO_PinState_t gpio::GPIO_PinGetValue(GPIO_PinConfig* Copy_PinConfigs){
	
	return GPIO_PIN_SET;
	
}
GPIO_ErrorType_t gpio::GPIO_PinToggleValue(GPIO_PinConfig* Copy_PinConfigs){
	GPIO_ErrorType_t Local_ReturnErr = GPIO_OK;
	if(Copy_PinConfigs->pinNumber < GPIO_PIN_MAX_NUMBER){
		gpio_RegArr[Copy_PinConfigs->portName]->ODR ^= (0x01 << Copy_PinConfigs->pinNumber); 
	}
	else{
		gpioErr = GPIO_NOK;
		Local_ReturnErr = GPIO_NOK;
	}
	return Local_ReturnErr;
	
}