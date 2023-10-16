#include "HAL/Buttons/Buttons.h"

Buttons_State_Typedef Button_State = Stop;

void Buttons_Init(void)
{
    /* Enable GPIOF Clock */
    Enable_Peripheral_Clock(GPIOF_CLOCK_OFFSET);
    /* Initialize PF0 and PF4 as inputs */
    GPIO_InitTypeDef Init = { 0U };
    Init.Pin = PF0 | PF4;
    Init.Pull = PULL_UP;
    Init.Mode = Input;
    GPIO_Init(GPIOF, &Init);
    /* Setup interrupts from PF0 and PF4 */
    GPIO_Init_InterruptTypeDef Int_Init = { 0U };
    Int_Init.Pin = PF0 | PF4;
    Int_Init.Sense = Edge;
    Int_Init.Trigger = Falling_Edge_GPIO;
    GPIO_Int_Register(PortF, &Buttons_IRQ_Callback);
    GPIO_Interrupt_Init(GPIOF, &Int_Init);
    NVIC_Enable(GPIOF_Int);
}

Buttons_State_Typedef Get_Buttons_State(void)
{
    return Button_State;
}

void Set_Buttons_State(Buttons_State_Typedef New_State)
{
    Button_State = New_State;
}

void Buttons_IRQ_Callback(uint32_t Pins)
{
    const static uint32_t Pin_Arr[2] = { PF0, PF4 };
    static uint8_t index;
    if ((Pins == Pin_Arr[0]) && (Button_State == Stop))
    {
        index = 0U;
    }
    else if ((Pins == Pin_Arr[1]) && (Button_State == Stop))
    {
        index = 1U;
    }
    else
    {
    }
    if (((Pin_Arr[index] == Pins) && (Button_State == Stop))
            || ((Pin_Arr[index] != Pins) && (Button_State == Start)))
    {
        switch (Button_State)
        {
        case Start:
            Button_State = Stop;
            break;
        case Stop:
            Button_State = Start;
            break;
        default:
            break;
        }
    }
    else
    {
    }
}
