#include"STD_TYPES.h"
#include"gpio.h"
#include "rcc.h"
#include "led.h"


led_base::led_base(Led_Port_Num_t port, Led_Pin_Num_t pin, Led_State_t state) : port(port), pin(pin), state(state) {
		Error_State = LED_OK;
}

led::led() : led_base(LED_PORT_C, LED_PIN_13, LED_ON){
	//led_gpio_pin_config(GPIO_PORTC, GPIO_PIN_13, GPIO_u8OUTPUT_PUSH_PULL_2MHZ, GPIO_PIN_RESET);
	led_gpio_pin_config->pinNumber = GPIO_PIN_13;
	led_gpio_pin_config->portName = GPIO_PORTC;
	led_gpio_pin_config->pinConfigMode = GPIO_u8OUTPUT_PUSH_PULL_2MHZ;
	led_gpio_pin_config->pinValue = GPIO_PIN_RESET;
	led_gpio_pin->GPIO_PinInit(led_gpio_pin_config);
}



led::led(GPIO_PinConfig* _pin) : led_base(static_cast<Led_Port_Num_t>(_pin->portName), static_cast<Led_Pin_Num_t>(_pin->pinNumber), static_cast<Led_State_t>(_pin->pinValue)) {
	led_gpio_pin_config = _pin;
	led_gpio_pin->GPIO_PinInit(led_gpio_pin_config);
}
LED_ErrorType_t led::Led_ON(){
	LED_ErrorType_t ret = LED_OK; 
	if((port > 2) || (pin > 15)){
		ret = LED_NOK; 
	}
	else{
		led_gpio_pin->GPIO_PinSetVal(led_gpio_pin_config, static_cast<GPIO_PinState_t>(GPIO_PIN_SET));
	}
return ret;
}
LED_ErrorType_t led::Led_OFF(){
	LED_ErrorType_t ret = LED_OK; 
	if((port > 2) || (pin > 15)){
		ret = LED_NOK; 
	}
	else{
		led_gpio_pin->GPIO_PinSetVal(led_gpio_pin_config, static_cast<GPIO_PinState_t>(GPIO_PIN_RESET));
	}
return ret;
}
LED_ErrorType_t led::Led_Toggle(){
	LED_ErrorType_t ret = LED_OK; 
	if((port > 2) || (pin > 15)){
		ret = LED_NOK; 
	}
	else{
		led_gpio_pin->GPIO_PinToggleValue(led_gpio_pin_config);
	}
return ret;
}
