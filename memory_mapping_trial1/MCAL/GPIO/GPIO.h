/*
 * GPIO.h
 *
 *  Created on: Sep 28, 2023
 *      Author: DELL G5
 */

#ifndef MCAL_GPIO_GPIO_H_
#define MCAL_GPIO_GPIO_H_

#include <MCAL/register_map.h>
#include "stdint.h"

#define PIN0 0X01U
#define PIN1 0X02U
#define PIN2 0X04U
#define PIN3 0X08U
#define PIN4 0X10U
#define PIN5 0X20U
#define PIN6 0X40U
#define PIN7 0X80U
#define ALL_PINS 0XFFU

#define GPIOA_CLK 0x01
#define GPIOB_CLK 0x02
#define GPIOC_CLK 0x04
#define GPIOD_CLK 0x08
#define GPIOE_CLK 0x10
#define GPIOF_CLK 0x20

#define input 0
#define output 1

#define digital 1
#define analog 0

#define high 1
#define low 0




void GPIO_INIT(gpio_reg_mape *GPIO,uint32_t PINS,uint32_t dir);
void GPIO_DIGITAL_ANALOG(gpio_reg_mape *GPIO,uint32_t PINS,uint32_t OUT);
void GPIO_PULLUP(gpio_reg_mape *GPIO,uint32_t PINS);
void GPIO_CLK_EN(uint32_t gpio);

void GPIO_WRITE(gpio_reg_mape *GPIO,uint32_t PINS,uint8_t value);


#endif /* MCAL_GPIO_GPIO_H_ */
