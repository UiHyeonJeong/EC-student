// Distributed for LAB: GPIO

#include "stm32f4xx.h"
#include "stm32f411xe.h"
#include "ecGPIO.h"

//Initializes GPIO pins with default setting and Enables GPIO Cloc
void GPIO_init(GPIO_TypeDef *Port, int pin, int mode){     
   
	if (Port == GPIOA)
		RCC_GPIOA_enable();
	
	if (Port == GPIOB)
		RCC_GPIOB_enable();
		
	if (Port == GPIOC)
		RCC_GPIOC_enable();
	
	if (Port == GPIOD)
		RCC_GPIOD_enable();
	
	if (Port == GPIOE)
		RCC_GPIOE_enable();
				
	if (Port == GPIOH)
		RCC_GPIOH_enable();

	// You can make a more general function of
	// void RCC_GPIO_enable(GPIO_TypeDef *Port); 

	GPIO_mode(Port, pin, mode);
	// The rest are default values
}


// GPIO Mode          : Input(00), Output(01), AlterFunc(10), Analog(11, reset)
void GPIO_mode(GPIO_TypeDef *Port, int pin, int mode){
   Port->MODER &= ~(3UL<<(2*pin));     
   Port->MODER |= mode<<(2*pin);    
}

//Read data from input data register
int  GPIO_read(GPIO_TypeDef *Port, int pin){
	unsigned int btval=0;
	btval=(Port->IDR) & (1UL <<pin); //Read bit value of Button
	return btval;
}

//Write (Output data from ODR to pin)
void GPIO_write(GPIO_TypeDef *Port, int pin, int Output){
if(Output==1)
 Port->ODR |= (1UL << pin);	
else
	Port->ODR &= ~(1UL << pin);	
}


 //GPIO Output Type Register  
void GPIO_otype(GPIO_TypeDef* Port, int pin, int type){
	if(type==0)
	Port->OTYPER &= ~(type<<pin); // type:push-pull 
	else
	Port->OTYPER |= (type<<pin);   	// type:drain 
}

 // GPIO Pull-Up/Pull-Down Register 
void GPIO_pudr(GPIO_TypeDef* Port, int pin, int pudr){
		Port->PUPDR &= ~(3UL<<(2*pin)); //clear
		Port->PUPDR  |= pudr<<(2*pin); 		 
}

 // GPIO input Speed Register 
void GPIO_ospeed(GPIO_TypeDef* Port, int pin, int speed){
			Port->OSPEEDR &= ~(3UL<<(2*pin)); //clear
		  Port->OSPEEDR |=  speed<<(2*LED_PIN);  
}