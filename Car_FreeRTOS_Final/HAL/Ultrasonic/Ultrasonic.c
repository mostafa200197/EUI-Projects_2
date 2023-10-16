#include "HAL/Ultrasonic/Ultrasonic.h"

static uint32_t Ultrasonic_Distance = 0U;
static uint8_t Ultrasonic_Flag = 0U;
static uint8_t Ultrasonic_Ready_Flag = ULTRASONIC_IDLE;
static uint32_t Ultrasonic_Rising_Edge = 0U;
static uint32_t Ultrasonic_Falling_Edge = 0U;

void Ultrasonic_Init(void)
{
    /* Initialize GPIO Clock */
    Enable_Peripheral_Clock(GPIOD_CLOCK_OFFSET);
    Enable_Peripheral_Clock(GPIOE_CLOCK_OFFSET);
    /* Init Trigger Pin */
    GPIO_InitTypeDef Pin_Init = { 0U };
    Pin_Init.Pin = PE0;
    Pin_Init.Pull = PULL_DOWN;
    Pin_Init.Mode = Output;
    GPIO_Init(GPIOE, &Pin_Init);
    /* Init Echo Pin */
    Pin_Init.Pin = PD6;
    Pin_Init.Pull = FLOATING;
    Pin_Init.AF = On;
    Pin_Init.AF_Mode = 7U;
    GPIO_Init(GPIOD, &Pin_Init);
    /* Initialize Timer Clock */
    Enable_Peripheral_Clock(WTIMER5_CLOCK_OFFSET);
    /* Init WTimer5 */
    Timer_InitTypeDef Tim_Init = { 0U };
    Tim_Init.Config = Individual;
    Tim_Init.Mode = Capture;
    Tim_Init.Count_Mode = Down;
    Tim_Init.Prescalar = 0U;
    Tim_Init.Edge_Mode = Edge_Time;
    Tim_Init.Timer = TimerA;
    Tim_Init.Load = 0xFFFFFFFFU;
    Tim_Init.Trigger = Both_Timer;
    Timer_Init(WTIMER5, &Tim_Init);
    /* Init WTimer5 Interrupt */
    Timer_Interrupt_Register(WTimer_5, TimerA, &Ultrasonic_IRQ_Handler);
    Timer_Init_InterruptTypedef Int_Init = { 0U };
    Int_Init.Capture_Event = On;
    Int_Init.Timer = TimerA;
    Timer_Interrupt_Init(WTIMER5, &Int_Init);
    NVIC_Enable(WTimer5_A_Int);
}

void Trigger_Ultrasonic(void)
{
    Ultrasonic_Flag = 0U;
    Ultrasonic_Rising_Edge = 0U;
    Ultrasonic_Falling_Edge = 0U;
    Ultrasonic_Ready_Flag = ULTRASONIC_BUSY;
    Timer_SetLoad(WTIMER5, TimerA, 0xFFFFFFFFU);
    GPIO_Write(GPIOE, PE0, High);
    Delay_us(200U);
    GPIO_Write(GPIOE, PE0, Low);
}

uint8_t Ultrasonic_Ready(void)
{
    return Ultrasonic_Ready_Flag;
}

uint32_t Ultrasonic_Get_Distance(void)
{
    Ultrasonic_Ready_Flag = ULTRASONIC_IDLE;
    return Ultrasonic_Distance;
}

void Ultrasonic_IRQ_Handler(void)
{
    uint32_t Period;
    switch (Ultrasonic_Flag)
    {
    case 0U:
        Ultrasonic_Rising_Edge = Timer_GetCount(WTIMER5, TimerA);
        Ultrasonic_Flag = 1U;
        break;
    case 1U:
        Ultrasonic_Falling_Edge = Timer_GetCount(WTIMER5, TimerA);
        Period = (Ultrasonic_Rising_Edge - Ultrasonic_Falling_Edge)
                / 16U;
        Ultrasonic_Distance = ((uint32_t)(34U * Period)) / 2000U;
        Ultrasonic_Ready_Flag = ULTRASONIC_READY;
        break;
    default:
        break;
    }
}
