/*
 * GPIO_A.c
 *
 *  Created on: Oct 14, 2023
 *      Author: DELL G5
 */

#include "GPIO_A.h"
#include "MCAL/register_map.h"

void Dio_init(void)
{
    SYSCTL->RCGCGPIO|=0X0F; //enable all GPIO clocks

    GPIOA->GPIOLOCK=0x4C4F434BUL; //unlock GPIOA
    GPIOA->GPIOCR|=0X0F; //Committing pins

    GPIOB->GPIOLOCK=0x4C4F434BUL; //unlock GPIOB
    GPIOB->GPIOCR|=0X0F; //Committing pins

    GPIOD->GPIOLOCK=0x4C4F434BUL; //unlock GPIOD
    GPIOD->GPIOCR|=0X0F; //Committing pins

    GPIOE->GPIOLOCK=0x4C4F434BUL; //unlock GPIOE
    GPIOE->GPIOCR|=0X0F; //Committing pins

    GPIOF->GPIOLOCK=0x4C4F434BUL; //unlock GPIOF
    GPIOF->GPIOCR|=0X0F; //Committing pins
}


void Dio_WriteChannel (Dio_ChannelType ChannelId,Dio_LevelType Level)
{

    uint8_t port = ChannelId / 8U;
    uint8_t pin = ChannelId % 8U;

    if(Level == STD_HIGH)
    {
        if(port == 0U)
        {
            GPIOA->GPIODATA[1<<pin]|=(Dio_ChannelType)(1<<pin);
        }
        else if(port == 1U)
        {
            GPIOB->GPIODATA[1<<pin]|=(Dio_ChannelType)(1<<pin);
        }
        else if(port == 2U)
        {
            GPIOD->GPIODATA[1<<pin]|=(Dio_ChannelType)(1<<pin);
        }
        else if(port == 3U)
        {
            GPIOE->GPIODATA[1<<pin]|=(Dio_ChannelType)(1<<pin);
        }
        else if(port == 4U)
        {
            GPIOF->GPIODATA[1<<pin]|=(Dio_ChannelType)(1<<pin);
        }
    }
    else if(Level == STD_LOW)
    {
        if(port == 0U)
        {
            GPIOA->GPIODATA[1<<pin]&=~(Dio_ChannelType)(1<<pin);
        }
        else if(port == 1U)
        {
            GPIOB->GPIODATA[1<<pin]&=~(Dio_ChannelType)(1<<pin);
        }
        else if(port == 2U)
        {
            GPIOD->GPIODATA[1<<pin]&=~(Dio_ChannelType)(1<<pin);
        }
        else if(port == 3U)
        {
            GPIOE->GPIODATA[1<<pin]&=~(Dio_ChannelType)(1<<pin);
        }
        else if(port == 4U)
        {
            GPIOF->GPIODATA[1<<pin]&=~(Dio_ChannelType)(1<<pin);
        }
    }
}

Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId)
{
    uint8_t port = ChannelId / 8U;
    uint8_t pin = ChannelId % 8U;
    Dio_LevelType result=0U;
    if(port == 0U)
    {
        result = GPIOA->GPIODATA[1<<pin]? STD_HIGH : STD_LOW;
    }
    else if(port == 1U)
    {
        result = GPIOB->GPIODATA[1<<pin]? STD_HIGH : STD_LOW;
    }
    else if(port == 2U)
    {
        result = GPIOD->GPIODATA[1<<pin]? STD_HIGH : STD_LOW;
    }
    else if(port == 3U)
    {
        result = GPIOE->GPIODATA[1<<pin]? STD_HIGH : STD_LOW;
    }
    else if(port == 4U)
    {
        result = GPIOF->GPIODATA[1<<pin]? STD_HIGH : STD_LOW;
    }
    return result;
}

Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId)
{
    Dio_PortLevelType result = 0U;

    if(PortId == 0U)
    {
        result = GPIOA->GPIODATA[255];
    }
    else if(PortId == 1U)
    {
        result = GPIOB->GPIODATA[255];
    }
    else if(PortId == 2U)
    {
        result = GPIOD->GPIODATA[255];
    }
    else if(PortId == 3U)
    {
        result = GPIOE->GPIODATA[255];
    }
    else if(PortId == 4U)
    {
        result = GPIOF->GPIODATA[255];
    }
    return result;
}

void Dio_WritePort (Dio_PortType PortId,Dio_PortLevelType Level)
{
    if(PortId == 0U)
    {
        GPIOA->GPIODATA[255] = Level;
    }
    else if(PortId == 1U)
    {
        GPIOB->GPIODATA[255] = Level;
    }
    else if(PortId == 2U)
    {
        GPIOD->GPIODATA[255] = Level;
    }
    else if(PortId == 3U)
    {
        GPIOE->GPIODATA[255] = Level;
    }
    else if(PortId == 4U)
    {
        GPIOF->GPIODATA[255] = Level;
    }
}

