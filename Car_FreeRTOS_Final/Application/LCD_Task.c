#include "Application/LCD_Task.h"


/*********************************************************************************/
/*                                                                               */
/* !Layer           : Application Layer                                          */
/*                                                                               */
/* !Module          :  Free RTOS Task Module                                     */
/* !Description     : LCD display task implementation                            */
/*                                                                               */
/* !File            : LCD_Task.c                                                 */
/*                                                                               */
/* !Coding language : C                                                          */
/*                                                                               */
/* !Project         : Robot Car Project @EME - EUI                               */
/*                                                                               */
/* !Target          : TIVA-C TM4C123GH6PM                                        */
/*                                                                               */
/* !Compiler        : Code Composer Studio 8.3.1                                 */
/*                                                                               */
/*                                                                               */
/*********************************************************************************/
/* MODIFICATION LOG :                                                            */
/*********************************************************************************/
/*                                                                               */
/* !Designed by     : Ahmed ABDULAZEEM                      !Date : OCT 01, 2023 */
/* !Coded by        : Ahmed ABDULAZEEM                      !Date : OCT 01, 2023 */
/*                                                                               */
/* Ver 1.0    OCT 01, 2023     Initial release                                   */
/*********************************************************************************/






/**********************************************************************************************
 *  FUNCTION DESCRIPTION
 *  -------------------------------------------------------------------------------------------
 *  This task displays Temperature, Time and Light Intensity Difference.
 *
 *  PARAMETERS
 *  -------------------------------------------------------------------------------------------
 *  pvParameters_LCD is a pointer to structure that contains a three queue handlers for
 *  Time,Temperature and Time
 *
 *  RETURNS
 *  -------------------------------------------------------------------------------------------
 *  None
 **********************************************************************************************/
void lcd_display(void *pvParameters_LCD)
{
    QueueHandles *handles = (QueueHandles*) pvParameters_LCD;   /*handles is a pointer to struct that carries 3 queues handles*/
    /* Access the queue handles */

    QueueHandle_t LDRData_Handler = handles->LDRReadQueue_Handle;
    QueueHandle_t TemperatureData_Handler = handles->TemperatureReadQueue_Handle;
    QueueHandle_t timeData_Handler = handles->TimeReadQueue_Handle;

    display_state Loc_state = dis_LDR;              /*Variable to carry current state*/

    uint16_t Loc_u16TimerVal               = 0U;    /*Variable to carry Number of Seconds*/
    uint16_t Loc_u16TemperatureVal         = 0U;    /*Variable to carry Temperature*/
    uint16_t Loc_u16LDRVal                 = 0U;    /*Variable to carry Intensity*/
    uint16_t LOC_u16tempLDRReading         = 0U;    /*Variable to carry Number of Seconds Temporary*/
    uint16_t LOC_u16tempTemperatureReading = 0U;    /*Variable to carry Temperature Temporary*/
    uint16_t LOC_u16tempTimeReading        = 0U;    /*Variable to carry Intensity Temporary*/

    TickType_t xLastWakeTime_LCD;                   /*Variable to carry last Wake Time*/

    LCD_vidWriteString("Temp:");

    LCD_vidMoveCursor(row_1, col_9);                /*Go To row 1 , Col 9*/

    LCD_vidWriteString("LDR:");

    LCD_vidMoveCursor(row_2, col_1);                /*Go To row 2 , Col 1*/
    LCD_vidWriteString("Time:");

    for (;;)
    {
        xLastWakeTime_LCD = xTaskGetTickCount();                                /*Read current number of ticks*/
        Turn_On_LED(YELLOW_LED);                                                /*Turn on Led For debugging*/

        xQueueReceive(timeData_Handler, (void* )&LOC_u16tempTimeReading, 0U);   /*Read from Temperature Queue and print if changed*/
        if (LOC_u16tempTimeReading != Loc_u16TimerVal)                          /*if new value != old value print it else go blocking*/
        {
            Loc_u16TimerVal = LOC_u16tempTimeReading;
            Loc_state = dis_Time;                                               /*make state equals time*/
        }

        switch (Loc_state)
        {
            case dis_LDR:
                Loc_state = dis_Temperature;                                        /*move to next state for the next time*/
                xQueueReceive(LDRData_Handler, (void* )&LOC_u16tempLDRReading, 0U); /*Read from LDR Queue and print if changed*/
                if (LOC_u16tempLDRReading != Loc_u16LDRVal)                         /*if new value != old value print it else go blocking*/
                {
                    Loc_u16LDRVal = LOC_u16tempLDRReading;
                    LCD_vidMoveCursor(row_1, col_13);                               /*Go To row 1 , Col 13*/
                    LCD_vidWriteNumber(Loc_u16LDRVal);                              /*print LDR Difference Value*/

                    if (Loc_u16LDRVal < FOUR_DIGITS)                                /*if number less than 4 digit print space*/
                    {
                        LCD_vidWriteChar(' ');                                      /*Print space (Clear Location on screen)*/
                    }
                    if (Loc_u16LDRVal < THREE_DIGITS)                               /*if number less than 3 digit print space*/
                    {
                        LCD_vidWriteChar(' ');                                      /*Print space (Clear Location on screen)*/
                    }
                    if (Loc_u16LDRVal < TWO_DIGITS)                                 /*if number less than 2 digit print space*/
                    {
                        LCD_vidWriteChar(' ');                                      /*Print space (Clear Location on screen)*/
                    }
                }
                else
                {
                    /*DO nothing*/
                }
                break;

            case dis_Temperature:
                Loc_state = dis_LDR;                                        /*move to next state for the next time*/
                xQueueReceive(TemperatureData_Handler, (void* )&LOC_u16tempTemperatureReading, 0U); /*Read from Temperature Queue and print if changed*/
                if (LOC_u16tempTemperatureReading != Loc_u16TemperatureVal) /*if new value != old value print it else go blocking*/
                {
                    Loc_u16TemperatureVal = LOC_u16tempTemperatureReading;
                    LCD_vidMoveCursor(row_1, col_5);                        /*Go To row 1 , Col 5*/
                    LCD_vidWriteNumber(Loc_u16TemperatureVal);              /*Print Temperature Value*/
                }
                else
                {
                    /*Do Nothing*/
                }
                /*Read from LDR Queue and print if changed*/
                break;

            case dis_Time:
                Loc_state = dis_LDR;                    /*move to next state for the next time*/
                LCD_vidMoveCursor(row_2, col_8);
                LCD_vidWriteNumber(Loc_u16TimerVal);    /*Print number of seconds*/
                if (Loc_u16TimerVal < TWO_DIGITS)       /*if number less than 2 digit print space*/
                {
                    LCD_vidWriteChar(' ');              /*Print space (Clear Location on screen)*/
                }
                break;

            default:
                /*Do Nothing*/
                break;
        }
        vTaskDelayUntil(&xLastWakeTime_LCD, Period_LCD); /*make task periodic with period equals Period_LCD*/
    }
}
