#include <MCAL/Timer_Drivers/Timer.h>

void (*ptr_Timer[24])(void);

void Timer_Init(Timer_RegDef_t *Timerx, const Timer_InitTypeDef *Timer_Config)
{
    Timerx->CFG = Timer_Config->Config;
    switch ((uint32_t) Timer_Config->Config)
    {
    case Individual:
        switch (Timer_Config->Timer)
        {
        case TimerA:
            Timerx->TAMR |= (Timer_Config->Mode | (Timer_Config->Count_Mode << 4U)
                    | (Timer_Config->Edge_Mode << 2U) | (Timer_Config->PWM << 3U));
            Timerx->TAILR = Timer_Config->Load;
            Timerx->TAPR = Timer_Config->Prescalar;
            Timerx->CTL |= ((Timer_Config->Polarity << 6U)
                    | (Timer_Config->Trigger << 2U));
            Timerx->CTL |= ((uint32_t) 1 << 0U);
            break;
        case TimerB:
            Timerx->TBMR |= (Timer_Config->Mode | (Timer_Config->Count_Mode << 4U)
                    | (Timer_Config->Edge_Mode << 2U) | (Timer_Config->PWM << 3U));
            Timerx->TBILR = Timer_Config->Load;
            Timerx->TBPR = Timer_Config->Prescalar;
            Timerx->CTL |= ((Timer_Config->Polarity << 14U)
                    | (Timer_Config->Trigger << 10U));
            Timerx->CTL |= ((uint32_t) 1 << 8U);
            break;
        default:
            break;
        }
        break;
    case Concatenated:
        break;
    default:
        break;
    }
}

void Timer_Interrupt_Init(Timer_RegDef_t *Timerx,
                          const Timer_Init_InterruptTypedef *Timer_Int_Config)
{
    switch (Timer_Int_Config->Timer)
    {
    case TimerA:
        Timerx->IMR |= ((Timer_Int_Config->Time_Out << 0U)
                | (Timer_Int_Config->Capture_Match << 1U)
                | (Timer_Int_Config->Capture_Event << 2U)
                | (Timer_Int_Config->Match << 4U));
        Timerx->TAMR |= ((Timer_Int_Config->PWM << 9U)
                | (Timer_Int_Config->Match << 5U));
        break;
    case TimerB:
        Timerx->IMR |= ((Timer_Int_Config->Time_Out << 8U)
                | (Timer_Int_Config->Capture_Match << 9U)
                | (Timer_Int_Config->Capture_Event << 10U)
                | (Timer_Int_Config->Match << 11U));
        Timerx->TBMR |= ((Timer_Int_Config->PWM << 9U)
                | (Timer_Int_Config->Match << 5U));
        break;
    default:
        break;
    }
}

void Timer_SetMatch(Timer_RegDef_t *Timerx, uint8_t Timer, uint32_t Match)
{
    switch (Timer)
    {
    case TimerA:
        Timerx->TAMATCHR = Match;
        break;
    case TimerB:
        Timerx->TBMATCHR = Match;
        break;
    default:
        break;
    }
}

uint32_t Timer_GetMatch(const Timer_RegDef_t *Timerx, uint8_t Timer)
{
    uint32_t val = 0U;
    switch (Timer)
    {
    case TimerA:
        val = Timerx->TAMATCHR;
        break;
    case TimerB:
        val = Timerx->TBMATCHR;
        break;
    default:
        break;
    }
    return val;
}

void Timer_SetLoad(Timer_RegDef_t *Timerx, uint8_t Timer, uint32_t Load)
{
    switch (Timer)
    {
    case TimerA:
        Timerx->TAILR = Load;
        break;
    case TimerB:
        Timerx->TBILR = Load;
        break;
    default:
        break;
    }
}

uint32_t Timer_GetCount(const Timer_RegDef_t *Timerx, uint8_t Timer)
{
    uint32_t val = 0U;
    switch (Timer)
    {
    case TimerA:
        val = Timerx->TAR;
        break;
    case TimerB:
        val = Timerx->TBR;
        break;
    default:
        break;
    }
    return val;
}

void Timer_Interrupt_Register(uint8_t Timer, uint8_t SubTimer,
                              void (*pfnIntHandler)(void))
{
    uint8_t Handler = (Timer * 2U) + SubTimer;
    ptr_Timer[Handler] = pfnIntHandler;
}
