/*
 * GPIO.c
 *
 *  Created on: Sep 28, 2023
 *      Author: DELL G5
 */


#include <MCAL/GPIO/GPIO.h>

#include "tm4c123.h"
uint32_t x;
/*************************************************************************************/
/* function to initialize the GPIO direction, unlocking and committing the specified pins*/
/*************************************************************************************/
void GPIO_CLK_EN(uint32_t gpio)
{
    SYSCTL->RCGCGPIO|=gpio;
}


void GPIO_INIT(gpio_reg_mape *GPIO,uint32_t PINS,uint32_t dir)
{

    GPIO->GPIOLOCK=0x4C4F434BUL; //unlock GPIO
    GPIO->GPIOCR|=PINS; //Committing pins


    if(dir==input)
    {
        GPIO->GPIODIR&=(~PINS);
    }
    else if(dir==output)
    {
        GPIO->GPIODIR|=PINS;
    }

}

/*************************************************************************************/
/* function for digital / analog pins selection*/
/*************************************************************************************/
void GPIO_DIGITAL_ANALOG(gpio_reg_mape *GPIO,uint32_t PINS,uint32_t OUT)
{
    if(OUT==digital)
    {
        GPIO->GPIODEN|=PINS;
    }
    else if(OUT==analog)
    {
        GPIO->GPIODEN&=(~PINS);
    }

}

/*************************************************************************************/
/* function for enabling pullup resisotr mode for pins*/
/*************************************************************************************/
void GPIO_PULLUP(gpio_reg_mape *GPIO,uint32_t PINS)
{
    GPIO->GPIOPUR|=PINS;
}

void GPIO_WRITE(gpio_reg_mape *GPIO,uint32_t PINS,uint8_t value)
{
    if(value==high)
    {
        GPIO->GPIODATA[PINS]|=(uint32_t)PINS;
    }
    else if(value==low)
    {
        GPIO->GPIODATA[PINS]&=(~(uint32_t)PINS);
    }
}



