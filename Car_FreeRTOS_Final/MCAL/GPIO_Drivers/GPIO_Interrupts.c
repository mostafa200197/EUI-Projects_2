#include <MCAL/GPIO_Drivers/GPIO_Interrupts.h>

void (*ptr_GPIO[6])(uint32_t Pin);

void GPIO_Interrupt_Init(GPIO_RegDef_t *GPIOx,
                         const GPIO_Init_InterruptTypeDef *GPIO_Int_Config)
{
    GPIOx->IM &= ~GPIO_Int_Config->Pin;
    GPIOx->IS &= ~GPIO_Int_Config->Pin;
    GPIOx->IBE &= ~GPIO_Int_Config->Pin;
    GPIOx->IEV &= ~GPIO_Int_Config->Pin;
    GPIOx->IS |= GPIO_Int_Config->Sense != 0U ? GPIO_Int_Config->Pin : 0UL;
    if ((GPIO_Int_Config->Trigger == Both_GPIO) && (GPIO_Int_Config->Sense == Edge))
    {
        GPIOx->IBE |= GPIO_Int_Config->Pin;
    }
    else
    {
        GPIOx->IEV |= GPIO_Int_Config->Trigger != 0U ? GPIO_Int_Config->Pin : 0U;
    }
    GPIOx->IM |= GPIO_Int_Config->Pin;
}

void GPIO_Int_Register(uint8_t Port, void (*pfnIntHandler)(uint32_t Pin))
{
    ptr_GPIO[Port] = pfnIntHandler;
}
