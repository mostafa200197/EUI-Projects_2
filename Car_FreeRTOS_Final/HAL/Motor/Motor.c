/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *       Author:  Adham EL-Serougy
 *         File:  Motor.c
 *        Layer:  HAL
 *       Module:  Motor
 *      Version:  1.00
 *
 *  Description:  Control and Initialize motors
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "HAL/Motor/Motor.h"
/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
 * \Syntax          : void Motor_Init(void)
 * \Description     : Initialize Motors
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : void
 * \Parameters (out): None
 * \Return value:   : void
 *******************************************************************************/

void Motor_Init(void)
{
    /* Enable GPIOA and GPIOE Clock */
    Enable_Peripheral_Clock(GPIOA_CLOCK_OFFSET);
    Enable_Peripheral_Clock(GPIOE_CLOCK_OFFSET);
    /* Configure PA4, PA5, PA6, PA7 as output pins and PE4, PE5 as PWM pins */
    GPIO_InitTypeDef Init = { 0U };
    Init.Pin = PA4 | PA5 | PA6 | PA7;
    Init.Pull = FLOATING;
    Init.Mode = Output;
    GPIO_Init(GPIOA, &Init);
    Init.Pin = PE4;
    Init.AF = On;
    Init.AF_Mode = 5U;
    Init.Mode = 0U;
    GPIO_Init(GPIOE, &Init);
    Init.Pin = PE5;
    GPIO_Init(GPIOE, &Init);
    /* Enable PWM1 Clock */
    Enable_Peripheral_Clock(PWM1_CLOCK_OFFSET);
    /* Configure PWM */
    PWM_InitTypeDef Init_PWM = { 0U };
    Init_PWM.Channel = PWM_Channel_2;
    Init_PWM.Channel_Action_Zero = PWM_DRIVE_LOW;
    Init_PWM.Channel_Action_CompADowm = PWM_DRIVE_HIGH;
    PWM_Init(PWM1, &Init_PWM);
    Init_PWM.Channel = PWM_Channel_3;
    Init_PWM.Channel_Action_CompADowm = PWM_DO_NOTHING;
    Init_PWM.Channel_Action_CompBDowm = PWM_DRIVE_HIGH;
    PWM_Init(PWM1, &Init_PWM);
    /* Right Side Motors Halt */
    GPIO_Write(GPIOA, PA4, Low);
    GPIO_Write(GPIOA, PA5, Low);
    /* Left Side Motors Halt */
    GPIO_Write(GPIOA, PA6, Low);
    GPIO_Write(GPIOA, PA7, Low);
    /* Set PWM Load Value For 100 Hz Operation */
    PWM_Set_Load(PWM1, PWM_Generator1, 2500U);
}

/******************************************************************************
 * \Syntax          : void Motor_Start(void)
 * \Description     : Start Motors
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : void
 * \Parameters (out): None
 * \Return value:   : void
 *******************************************************************************/

void Motor_Start(void)
{
    /* Set Direction of Motors to Front */
    Motor_Set_Direction(Motor_Right_Forward);
    Motor_Set_Direction(Motor_Left_Forward);
    /* Set Motor Speed to 65% */
    Motor_Set_Speed(80U, Right_Motors);
    Motor_Set_Speed(80U, Left_Motors);
    /* Start PWM Generators */
    PWM_Start(PWM1, PWM_Generator1);
    /* Enable PWM Output */
    PWM_Output_Enable(PWM1, PWM_Channel_2 | PWM_Channel_3);
}

/******************************************************************************
 * \Syntax          : void Motor_Set_Speed(uint16_t Speed, uint8_t Motors)
 * \Description     : Set Motor Speed
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Speed   Speed in percentage
 *                    Motors   which motor to change speed
 * \Parameters (out): None
 * \Return value:   : void
 *******************************************************************************/

void Motor_Set_Speed(uint16_t Speed, uint8_t Motors)
{
    Speed *= 25U;
    switch (Motors)
    {
    case Right_Motors:
        PWM_Set_Comp(PWM1, PWM_Channel_2, Speed);
        break;
    case Left_Motors:
        PWM_Set_Comp(PWM1, PWM_Channel_3, Speed);
        break;
    default:
        break;
    }
}

/******************************************************************************
 * \Syntax          : void Motor_Set_Direction(uint8_t Direction)
 * \Description     : Set Motor Direction
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Direction   Forward or Backward
 * \Parameters (out): None
 * \Return value:   : void
 *******************************************************************************/

void Motor_Set_Direction(uint8_t Direction)
{
    switch (Direction)
    {
    case Motor_Right_Reverse:
        GPIO_Write(GPIOA, PA4, Low);
        GPIO_Write(GPIOA, PA5, High);
        break;
    case Motor_Right_Forward:
        GPIO_Write(GPIOA, PA4, High);
        GPIO_Write(GPIOA, PA5, Low);
        break;
    case Motor_Left_Reverse:
        GPIO_Write(GPIOA, PA6, Low);
        GPIO_Write(GPIOA, PA7, High);
        break;
    case Motor_Left_Forward:
        GPIO_Write(GPIOA, PA6, High);
        GPIO_Write(GPIOA, PA7, Low);
        break;
    default:
        break;
    }
}

/******************************************************************************
 * \Syntax          : void Motor_Stop(void)
 * \Description     : Stop Motors
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : void
 * \Parameters (out): None
 * \Return value:   : void
 *******************************************************************************/

void Motor_Stop(void)
{
    /* Right Side Motors Halt */
    GPIO_Write(GPIOA, PA4, Low);
    GPIO_Write(GPIOA, PA5, Low);
    /* Left Side Motors Halt */
    GPIO_Write(GPIOA, PA6, Low);
    GPIO_Write(GPIOA, PA7, Low);
}
