/*
 * interrupts.c
 *
 *  Created on: Oct 1, 2023
 *      Author: DELL G5
 */

#include "interrupts.h"
void GPIO_INTERRUPT_ENABLE(gpio_reg_mape *GPIO,uint32_t PINS,uint32_t state,uint32_t edge,uint32_t level)
{
    GPIO->GPIOIM&=(~PINS); //clear interrupt mask



    if(state==levels)
    {
        GPIO->GPIOIS|=PINS; //configure interrupt sense for level trigger
    }
    else if(state==edges)
    {
        GPIO->GPIOIS&=(~PINS);//configure interrupt sense for edge trigger
        if(edge==both_levels)
        {
            GPIO->GPIOIBE|=PINS; //configure interrupt for both edges
        }
    }


    if(level==high)
    {
        GPIO->GPIOIEV|=PINS;   //high level or rising edge
    }
    else if(level==low)
    {
        GPIO->GPIOIEV&=(~PINS); //low level or falling edge
    }

    GPIO->GPIOICR|=PINS; //clear raw interrupt by setting this bit
    GPIO->GPIOIM|=PINS; //enable interrupt mask
}
