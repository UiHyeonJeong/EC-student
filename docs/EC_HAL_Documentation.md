---
description: EC_HAL API
---

# Embedded Controller HAL

Written by:  UI-Hyeon Jeong



Program: 		C/C++

IDE/Compiler: Keil uVision 5

OS: 					WIn10

MCU:  				STM32F411RE, Nucleo-64





## GPIO Digital In/Out 

### Header File

 `#include "ecGPIO.h"`



```c++
// Distributed for LAB: GPIO

#include "stm32f411xe.h"
#include "ecRCC.h"

#ifndef __ECGPIO_H
#define __ECGPIO_H

#define INPUT  0x00
#define OUTPUT 0x01
#define AF     0x02
#define ANALOG 0x03

#define HIGH 1
#define LOW  0

#define LED_PIN 	5
#define BUTTON_PIN 13

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */
	 
void GPIO_init(GPIO_TypeDef *Port, int pin, int mode);
void GPIO_write(GPIO_TypeDef *Port, int pin, int Output);
int  GPIO_read(GPIO_TypeDef *Port, int pin);
void GPIO_mode(GPIO_TypeDef* Port, int pin, int mode);
void GPIO_ospeed(GPIO_TypeDef* Port, int pin, int speed);
void GPIO_otype(GPIO_TypeDef* Port, int pin, int type);
void GPIO_pudr(GPIO_TypeDef* Port, int pin, int pudr);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif


```




### GPIO_init\(\)

Initializes GPIO pins with default setting and Enables GPIO Clock. Mode: In/Out/AF/Analog

```c++
void GPIO_init(GPIO_TypeDef *Port, int pin, int mode);
```

**Parameters**

* **Port:**  Port Number,  GPIOA~GPIOH

* **pin**:  pin number (int) 0~15

* **mode**:   INPUT (0), OUTPUT (1),  AF(02), ANALOG (03)

  

**Example code**

```c++
GPIO_init(GPIOA, 5, OUTPUT); //GPIO_init(GPIOA, 13, 1);
GPIO_init(GPIOC, 13, INPUT); //GPIO_init(GPIOC, 13, 0);
```



### GPIO_mode\(\)

Configures  GPIO pin modes: In/Out/AF/Analog

```c++
void GPIO_init(GPIO_TypeDef *Port, int pin, int mode);
```

**Parameters**

* **Port:**  Port Number,  GPIOA~GPIOH

* **pin**:  pin number (int) 0~15

* **mode**:   INPUT (0), OUTPUT (1),  AF(02), ANALOG (03)

  

**Example code**

```c++
GPIO_mode(GPIOA, 5, OUTPUT); //GPIO_mode(GPIOA, 5, 1);
```



### GPIO_read\(\)

Configures  GPIO pin to read data from input data register

```c++
void GPIO_pupdr(GPIO_TypeDef *Port, int pin);
```

**Parameters**

* **Port:**  Port Number,  GPIOA~GPIOH

* **pin**:  pin number (int) 0~15

  

**Example code**

```c++
GPIO_read(GPIOC, 13); //13: button pin #
```





### GPIO_write\(\)

Configures  GPIO pin output(Output data from ODR to pin): 0(Low)/ 1(High)

```c++
void GPIO_write(GPIO_TypeDef *Port, int pin, int output);
```

**Parameters**

* **Port:**  Port Number,  GPIOA~GPIOH

* **pin**:  pin number (int) 0~15

* **output**:   Low (0), HIgh (1)

  

**Example code**

```c++
 GPIO_write(GPIOA, 5, HIGH); //GPIO_write(GPIOA, 5, 1); (5:led pin #)
```





### GPIO_otype\(\)

Configures Output types

```c++
void GPIO_pupdr(GPIO_TypeDef *Port, int pin, int type);
```

**Parameters**

* **Port:**  Port Number,  GPIOA~GPIOH

* **pin**:  pin number (int) 0~15

* **type**:   Output push-pull(reset state) (0),  Output open-drain (1)

  

**Example code**

```c++
GPIO_pupdr(GPIOA, 5, 0); //0:push-pull
```





### GPIO_pudr\(\)

Configures pull-up/pull-down resistors (No PUPD/PU/PD/Reserved)

```c++
void GPIO_pudr(GPIO_TypeDef *Port, int pin, int pudr);
```

**Parameters**

* **Port:**  Port Number,  GPIOA~GPIOH

* **pin**:  pin number (int) 0~15

* **pudr**:   No Pullup Pulldown (0),  Pullup (1),  Pulldown(02), Reserved (03)

  

**Example code**

```c++
GPIO_pupdr(GPIOA, 5, 0); //0:No PUPD
```





### GPIO_ospeed\(\)

Configures  speed (Low/Medium/Fast/High)

```c++
void GPIO_ospeed(GPIO_TypeDef *Port, int pin, int speed);
```

**Parameters**

* **Port:**  Port Number,  GPIOA~GPIOH

* **pin**:  pin number (int) 0~15

* **speed**:   Low speed (0), Medium speed(1),  Fast speed(02), High speed(03)

  

**Example code**

```c++
GPIO_ospeed(GPIOB, 6 , 1); //1:Medium speed
```







------



