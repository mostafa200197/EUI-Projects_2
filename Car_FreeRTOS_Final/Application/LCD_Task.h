#ifndef APPLICATION_LCD_TASK_H_
#define APPLICATION_LCD_TASK_H_

/*********************************************************************************/
/*                                                                               */
/* !Layer           : Application Layer                                          */
/*                                                                               */
/* !Module          :  Free RTOS Task Module                                     */
/* !Description     : LCD display task header                                    */
/*                                                                               */
/* !File            : LCD_Task.h                                                 */
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


/**********************************************************************************
 ************************************* Includes ***********************************
 **********************************************************************************/
#include <stdint.h>
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "HAL/LCD/LCD.h"
#include "HAL/LDR/LDR.h"
#include "HAL/Motor/Motor.h"
#include "HAL/LED/LED.h"
#include "HAL/Temperature/Temperature.h"
/**********************************************************************************/



/*********************************************************************************
 ************************************* Defines ***********************************
 *********************************************************************************/
#define FOUR_DIGITS   1000U
#define THREE_DIGITS  100U
#define TWO_DIGITS    10U
#define Period_LCD pdMS_TO_TICKS(200U)
/*********************************************************************************/


/*********************************************************************************
 * display_state is a type enum that specify the LCD Print State
 * options:-
 * dis_LDR         : Print difference Intensity value
 * dis_Temperature : print temperature value
 * dis_Time        : print number of seconds
 **********************************************************************************/
typedef enum
{
    dis_LDR, dis_Temperature, dis_Time
} display_state;

/*********************************************************************************
 * rows is a type enum that specify the LCD row
 * options:-
 * row_1 : To select first Row
 * row_2 : To select first Row
 **********************************************************************************/
typedef enum
{
    row_1,row_2
} rows;

/*********************************************************************************
 * cols is a type enum that specify the LCD column
 * options:-
 * col_1 to col_16 : To select from first column to last column
 **********************************************************************************/
typedef enum
{
    col_1,col_2,col_3,col_4,
    col_5,col_6,col_7,col_8,
    col_9,col_10,col_11,col_12,
    col_13,col_14,col_15,col_16
} cols;

/*********************************************************************************
 *
 * QueueHandles is a struct that carry a three Queues Handles options for
 * Temperature, Time and Light Intensity to be sent to LCD task to print them
 *
 **********************************************************************************/
typedef struct
{

    QueueHandle_t LDRReadQueue_Handle;
    QueueHandle_t TemperatureReadQueue_Handle;
    QueueHandle_t TimeReadQueue_Handle;

} QueueHandles;

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
void lcd_display(void *pvParameters_LCD);

#endif /* APPLICATION_LCD_TASK_H_ */
