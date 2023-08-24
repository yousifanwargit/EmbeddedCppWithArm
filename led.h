#ifndef LED_H
#define LED_H



enum LED_ErrorType_t{
	LED_OK,
	LED_NOK,
	LED_DEFAULT_ERROR = 0XFF
};


enum Led_State_t{
	LED_OFF,
	LED_ON
};

enum Led_Pin_Num_t{
	LED_PIN_0 = 0,
	LED_PIN_1,
	LED_PIN_2,
	LED_PIN_3,
	LED_PIN_4,
	LED_PIN_5,
	LED_PIN_6,
	LED_PIN_7,
	LED_PIN_8,
	LED_PIN_9,
	LED_PIN_10,
	LED_PIN_11,
	LED_PIN_12,
	LED_PIN_13,
	LED_PIN_14,
	LED_PIN_15
};


enum Led_Port_Num_t{
	LED_PORT_A = 0,
	LED_PORT_B,
	LED_PORT_C
};

class led_base{
	
	
	public:
		LED_ErrorType_t Error_State;
		Led_State_t state;
		Led_Pin_Num_t pin;
		Led_Port_Num_t port;
		virtual LED_ErrorType_t Led_ON() = 0;
		virtual LED_ErrorType_t Led_OFF() = 0;
		virtual LED_ErrorType_t Led_Toggle() = 0;
		~led_base();
	
	protected:
		led_base() = default;
		led_base(Led_Port_Num_t port, Led_Pin_Num_t pin, Led_State_t state);
	
	
	private:
		
};


class led : public led_base{
	
	
	public:

		led();
		led(GPIO_PinConfig* _pin);
		virtual LED_ErrorType_t Led_ON();
		virtual LED_ErrorType_t Led_OFF();
		virtual LED_ErrorType_t Led_Toggle();
		~led();
	
	protected:
	
	private:
	
		GPIO_PinConfig* led_gpio_pin_config;
		gpio* led_gpio_pin;
	
};


class led_demmer{
	
	
	public:
		

		led_demmer();
		led_demmer(Led_Port_Num_t port, Led_Pin_Num_t pin, Led_State_t state);
		virtual LED_ErrorType_t Led_ON();
		virtual LED_ErrorType_t Led_OFF();
		virtual LED_ErrorType_t Led_Toggle();
		~led_demmer();
	
	protected:
	
	private:
		
		uint8 led_brightness;
	
	
};


#endif