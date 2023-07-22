
#include "rcc.h"

rcc rcc_obj;

int main(){
	
	rcc_obj.RCC_gpioPortInit(static_cast<RCC_GpioPortName_t>(2));
	while(1);
	
	return 0;
}	