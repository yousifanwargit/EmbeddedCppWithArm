#ifndef GPIO_H
#define GPIO_H



#define GPIO_u8INPUT_ANALOG             0b0000
#define GPIO_u8INPUT_FLOATING           0b0100
#define GPIO_u8INPUT_PULL_UP_DOWN       0b1000

#define GPIO_u8OUTPUT_PUSH_PULL_2MHZ    0b0010
#define GPIO_u8OUTPUT_PUSH_PULL_10MHZ   0b0001
#define GPIO_u8OUTPUT_PUSH_PULL_50MHZ   0b0011

#define GPIO_u8OUTPUT_OPEN_DRAIN_2MHZ   0b0110
#define GPIO_u8OUTPUT_OPEN_DRAIN_10MHZ  0b0101
#define GPIO_u8OUTPUT_OPEN_DRAIN_50MHZ  0b0111


#define GPIO_u8OUT_AF_PP_2MHZ           0b1010
#define GPIO_u8OUT_AF_PP_10MHZ          0b1001
#define GPIO_u8OUT_AF_PP_50MHZ          0b1011

#define GPIO_u8OUT_AF_OD_2MHZ           0b1110
#define GPIO_u8OUT_AF_OD_10MHZ          0b1101
#define GPIO_u8OUT_AF_OD_50MHZ          0b1111




enum GPIO_ErrorType_t{
	
	GPIO_OK,
	GPIO_NOK
};


enum GPIO_PortNumber_t{
	
	GPIO_PORTA,
	GPIO_PORTB,
	GPIO_PORTC,
	GPIO_PORT_MAX_NUMBER
};

enum GPIO_PinNumber_t{
	
	GPIO_PIN_0,
	GPIO_PIN_1,
	GPIO_PIN_2,
	GPIO_PIN_3,
	GPIO_PIN_4,
	GPIO_PIN_5,
	GPIO_PIN_6,
	GPIO_PIN_7,
	GPIO_PIN_8,
	GPIO_PIN_9,
	GPIO_PIN_10,
	GPIO_PIN_11,
	GPIO_PIN_12,
	GPIO_PIN_13,
	GPIO_PIN_14,
	GPIO_PIN_15,
	GPIO_PIN_MAX_NUMBER
};


enum GPIO_PinState_t{
	
	GPIO_PIN_RESET,
	GPIO_PIN_SET
};



class GPIO_PinConfig {
	private:
		
	
	public:
		GPIO_PinConfig();
		GPIO_PinConfig(GPIO_PortNumber_t portName, GPIO_PinNumber_t pinNumber, uint8 pinConfigMode, GPIO_PinState_t   pinValue);
		GPIO_ErrorType_t  GPIO_PinConfigIsOk();
		GPIO_ErrorType_t  pinConfigErr;
		GPIO_ErrorType_t  pinInitErr;
		GPIO_PortNumber_t portName;
		GPIO_PinNumber_t  pinNumber;
		uint8             pinConfigMode;
		GPIO_PinState_t   pinValue;
	
};


class gpio {
	private:
		
	
	public:
		gpio() = default;
		gpio(GPIO_PortNumber_t Copy_PortName);
		GPIO_ErrorType_t gpioErr;
		GPIO_ErrorType_t GPIO_PinInit(GPIO_PinConfig* Copy_PinConfigs);
		GPIO_ErrorType_t GPIO_PinSetVal(GPIO_PinConfig* Copy_PinConfigs, GPIO_PinState_t Copy_PinState);
		GPIO_PinState_t GPIO_PinGetValue(GPIO_PinConfig* Copy_PinConfigs);
		GPIO_ErrorType_t GPIO_PinToggleValue(GPIO_PinConfig* Copy_PinConfigs);
	
	
};


#endif