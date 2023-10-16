#include "MCAL/Interrupts/NVIC.h"

void NVIC_Enable(uint8_t Int){
    uint8_t EN_Num = Int / 32U;
    uint8_t Int_Num = Int % 32U;
    switch (EN_Num) {
        case 0U:
            NVIC->EN0 |= ((uint32_t)1<<Int_Num);
            break;
        case 1U:
            NVIC->EN1 |= ((uint32_t)1<<Int_Num);
            break;
        case 2U:
            NVIC->EN2 |= ((uint32_t)1<<Int_Num);
            break;
        case 3U:
            NVIC->EN3 |= ((uint32_t)1<<Int_Num);
            break;
        case 4U:
            NVIC->EN4 |= ((uint32_t)1<<Int_Num);
            break;
        default:
            break;
    }
}

void NVIC_Set_Priority(uint8_t Int, uint8_t Priority){

}

void Systick_Interrupt_Register(void (*pfnIntHandler)(void))
{
    ptr_NVIC = pfnIntHandler;
}
