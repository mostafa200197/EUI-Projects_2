#include "HAL/LED/LED.h"

void LED_Init(void)
{
    GPIO_InitTypeDef Init = {0};
    Init.Pin = PF1|PF2|PF3;
    Init.Pull = FLOATING;
    Init.Mode = Output;
    GPIO_Init(GPIOF, &Init);
}

void Turn_On_LED(uint8_t LED)
{
    GPIO_Write_Pins(GPIOF, PF1|PF2|PF3, LED);
}
