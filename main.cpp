#include "STD_TYPES.h"
#include "rcc.h"
#include "gpio.h"
#include "led.h"

//rcc rcc_obj;
GPIO_ErrorType_t err;
int main(){
	
	
	
	rcc::RCC_gpioPortInit(RCC_GPIO_PORT_C);
	rcc::RCC_gpioPortInit(RCC_GPIO_PORT_A);
	rcc::RCC_gpioPortInit(RCC_GPIO_PORT_B);
	GPIO_PinConfig  pin0(GPIO_PORTA,GPIO_PIN_1, GPIO_u8OUTPUT_PUSH_PULL_2MHZ, GPIO_PIN_SET);
	GPIO_PinConfig  pin1(GPIO_PORTA,GPIO_PIN_2, GPIO_u8OUTPUT_PUSH_PULL_2MHZ, GPIO_PIN_SET);
	GPIO_PinConfig  pin2(GPIO_PORTA,GPIO_PIN_3, GPIO_u8OUTPUT_PUSH_PULL_2MHZ, GPIO_PIN_SET);
	
	
	led led1(&pin0);
	led led2(&pin1);
	led led3(&pin2);
	
	
	//rcc_obj.RCC_gpioPortInit(RCC_GPIO_PORT_B);
	//rcc_obj.RCC_gpioPortInit(static_cast<RCC_GpioPortName_t>(2));
	/*
	GPIO_PinConfig  pin0( GPIO_PORTA,GPIO_PIN_0, GPIO_u8OUTPUT_PUSH_PULL_2MHZ, GPIO_PIN_SET);
	GPIO_PinConfig pin1(GPIO_PORTA, GPIO_PIN_1, GPIO_u8OUTPUT_PUSH_PULL_2MHZ, GPIO_PIN_RESET);
	GPIO_PinConfig pin2(GPIO_PORTA, GPIO_PIN_2, GPIO_u8OUTPUT_PUSH_PULL_2MHZ, GPIO_PIN_RESET);
	GPIO_PinConfig pin3(GPIO_PORTA, GPIO_PIN_3, GPIO_u8OUTPUT_PUSH_PULL_2MHZ, GPIO_PIN_RESET);
	GPIO_PinConfig pin4(GPIO_PORTA, GPIO_PIN_4, GPIO_u8OUTPUT_PUSH_PULL_2MHZ, GPIO_PIN_RESET);
	GPIO_PinConfig pin5(GPIO_PORTA, GPIO_PIN_5, GPIO_u8OUTPUT_PUSH_PULL_2MHZ, GPIO_PIN_RESET);
	GPIO_PinConfig pin6(GPIO_PORTA, GPIO_PIN_6, GPIO_u8OUTPUT_PUSH_PULL_2MHZ, GPIO_PIN_RESET);
	GPIO_PinConfig pin7(GPIO_PORTA, GPIO_PIN_7, GPIO_u8OUTPUT_PUSH_PULL_2MHZ, GPIO_PIN_RESET);
	GPIO_PinConfig pin8(GPIO_PORTA, GPIO_PIN_8, GPIO_u8OUTPUT_PUSH_PULL_2MHZ, GPIO_PIN_RESET);
	GPIO_PinConfig pin9(GPIO_PORTA, GPIO_PIN_9, GPIO_u8OUTPUT_PUSH_PULL_2MHZ, GPIO_PIN_RESET);
	GPIO_PinConfig pin10(GPIO_PORTA,GPIO_PIN_10, GPIO_u8OUTPUT_PUSH_PULL_2MHZ, GPIO_PIN_RESET);

	gpio pin00(GPIO_PORTA);
	gpio pin01(GPIO_PORTA);
	gpio pin02(GPIO_PORTA);
	gpio pin03(GPIO_PORTA);
	gpio pin04(GPIO_PORTA);
	gpio pin05(GPIO_PORTA);
	gpio pin06(GPIO_PORTA);
	gpio pin07(GPIO_PORTA);
	gpio pin08(GPIO_PORTA);
	gpio pin09(GPIO_PORTA);
 gpio pin100(GPIO_PORTA);
	err = pin00.GPIO_PinInit(&pin0);
	err = pin01.GPIO_PinInit(&pin1);
	err = pin02.GPIO_PinInit(&pin2);
	err = pin03.GPIO_PinInit(&pin3);
	err = pin04.GPIO_PinInit(&pin4);
	err = pin05.GPIO_PinInit(&pin5);
	err = pin06.GPIO_PinInit(&pin6);
	err = pin07.GPIO_PinInit(&pin7);
	err = pin08.GPIO_PinInit(&pin8);
	err = pin09.GPIO_PinInit(&pin9);
err = pin100.GPIO_PinInit(&pin10);
	*/
	
	while(1){
				led1.Led_ON();
				led2.Led_ON();
				led3.Led_ON();

		led1.Led_Toggle();
		led2.Led_Toggle();
		led3.Led_Toggle();
		/*
		err = pin00.GPIO_PinSetVal(&pin0, GPIO_PIN_SET);
		err = pin01.GPIO_PinSetVal(&pin1, GPIO_PIN_SET);
		err = pin02.GPIO_PinSetVal(&pin2, GPIO_PIN_SET);
		err = pin03.GPIO_PinSetVal(&pin3, GPIO_PIN_SET);
		err = pin04.GPIO_PinSetVal(&pin4, GPIO_PIN_SET);
		err = pin05.GPIO_PinSetVal(&pin5, GPIO_PIN_SET);
		err = pin06.GPIO_PinSetVal(&pin6, GPIO_PIN_SET);
		err = pin07.GPIO_PinSetVal(&pin7, GPIO_PIN_SET);
		err = pin08.GPIO_PinSetVal(&pin8, GPIO_PIN_SET);
		err = pin09.GPIO_PinSetVal(&pin9, GPIO_PIN_SET);
	 err = pin100.GPIO_PinSetVal(&pin10, GPIO_PIN_SET);
*/
	
	}

	return 0;
}	