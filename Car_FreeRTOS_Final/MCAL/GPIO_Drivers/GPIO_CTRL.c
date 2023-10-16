#include <MCAL/GPIO_Drivers/GPIO_CTRL.h>

/* Initializes GPIO */

void GPIO_Init(GPIO_RegDef_t *GPIOx, const GPIO_InitTypeDef *GPIO_Config)
{
    if (((uint32_t) &(*GPIOx) == 0x40006000UL) && ((GPIO_Config->Pin & 0x0FU) != 0U))
    {
        while (1U)
        {
        }

    }
    else if (((uint32_t) &(*GPIOx) == 0x40004000UL)
            && ((GPIO_Config->Pin & 0x07U) != 0U))
    {
        while (1U)
        {
        }

    }
    else
    {
        GPIOx->LOCK = 0x4C4F434BUL;
        GPIOx->CR |= GPIO_Config->Pin;
        if (GPIO_Config->Analog == On)
        {
            GPIOx->DEN &= GPIO_Config->Pin; /* Clear Digital Enable Pins for Analog use */
            GPIOx->AFSEL |= GPIO_Config->Pin; /* Enable Alt Function */
            GPIOx->AMSEL |= GPIO_Config->Pin; /* Enable Analog mode */
        }
        else
        {
            GPIOx->DIR |= GPIO_Config->Mode != 0U ? GPIO_Config->Pin : 0U;
            switch (GPIO_Config->Pull)
            {
            case FLOATING:
                GPIOx->PUR &= ~GPIO_Config->Pin;
                GPIOx->PDR &= ~GPIO_Config->Pin;
                break;
            case PULL_UP:
                GPIOx->PUR |= GPIO_Config->Pin;
                GPIOx->PDR &= ~GPIO_Config->Pin;
                break;
            case PULL_DOWN:
                GPIOx->PUR &= ~GPIO_Config->Pin;
                GPIOx->PDR |= GPIO_Config->Pin;
                break;
            default:
                break;
            }
            uint8_t pin_value;
            switch (GPIO_Config->Pin)
            {
            case 0x01U:
                pin_value = 0U;
                break;
            case 0x02U:
                pin_value = 1U;
                break;
            case 0x04U:
                pin_value = 2U;
                break;
            case 0x08U:
                pin_value = 3U;
                break;
            case 0x10U:
                pin_value = 4U;
                break;
            case 0x20U:
                pin_value = 5U;
                break;
            case 0x40U:
                pin_value = 6U;
                break;
            case 0x80U:
                pin_value = 7U;
                break;
            default:
                break;
            }
            if (GPIO_Config->AF)
            {
                GPIOx->AFSEL |= ((uint32_t) 1 << pin_value);
                GPIOx->PCTL |= (GPIO_Config->AF_Mode << (pin_value * 4U));
            }
            GPIOx->DEN |= GPIO_Config->Pin;
        }
    }
}

/* Writes to pins */

void GPIO_Write(GPIO_RegDef_t *GPIOx, uint8_t Pin, uint8_t Mode)
{
    GPIOx->DATA[Pin] = (uint32_t) Mode != 0U ? (uint32_t) Pin : 0U;
}

void GPIO_Write_Pins(GPIO_RegDef_t *GPIOx, uint32_t Pins, uint8_t State)
{
    GPIOx->DATA[Pins] = State;
}

/* Toggles Pins */

void GPIO_Toggle(GPIO_RegDef_t *GPIOx, uint8_t Pins)
{
    GPIOx->DATA[Pins] ^= Pins;
}

/* Reads Pins */

uint8_t GPIO_Read(GPIO_RegDef_t *GPIOx, uint8_t Pin)
{
    return (uint8_t) GPIOx->DATA[255];
}
