#include "Application/RC_Car.h"

/* Defines */
#define Period_Car_Start pdMS_TO_TICKS(500U)
#define Period_Car_Stop pdMS_TO_TICKS(500U)
#define Period_Timer pdMS_TO_TICKS(1000U)
/* Create a structure to hold the queue handles */
QueueHandles handles;
/* Task Handles */
TaskHandle_t Task_LDR;
TaskHandle_t Task_Temperature;
TaskHandle_t Task_Ultrasonic;
TaskHandle_t Task_Timer;
TaskHandle_t Task_LCD;

static uint8_t Car_Timer = 0U;
static uint8_t Start_Flag = 0U;

void Timer_Task(void *pvParameters_Timer)
{
    TickType_t xLastWakeTime_Timer;
    QueueHandle_t Data_Handler = *((QueueHandle_t*) pvParameters_Timer);
    for (;;)
    {
        xLastWakeTime_Timer = xTaskGetTickCount();
        Turn_On_LED(NO_LED);
        Car_Timer++;
        xQueueSend(Data_Handler, (void* ) &Car_Timer, 0U);
        vTaskDelayUntil(&xLastWakeTime_Timer, Period_Timer);
    }
}

void Car_Start(void *pvParameters_Car_Start)
{
    TickType_t xLastWakeTime_Car_Start = xTaskGetTickCount();
    while (1)
    {
        Turn_On_LED(GREEN_LED);
        if ((Get_Buttons_State() == Start) && (Start_Flag == 0U))
        {
            Car_Timer = 0U;
            vTaskResume(Task_Timer);
            vTaskResume(Task_LDR);
            vTaskResume(Task_Temperature);
            vTaskResume(Task_Ultrasonic);
            vTaskResume(Task_LCD);
            Motor_Start();
            Start_Flag = 1U;
        }
        else
        {
            /* Do Nothing */
        }
        vTaskDelayUntil(&xLastWakeTime_Car_Start, Period_Car_Start);
    }
}

void Car_Stop(void *pvParameters_Car_Stop)
{
    TickType_t xLastWakeTime_Car_Stop = xTaskGetTickCount();
    while (1)
    {
        Turn_On_LED(WHITE_LED);
        if (((Get_Buttons_State() == Stop) || (Car_Timer > 60U))
                && (Start_Flag == 1U))
        {
            Car_Timer = 0U;
            vTaskSuspend(Task_Timer);
            vTaskSuspend(Task_LDR);
            vTaskSuspend(Task_Temperature);
            vTaskSuspend(Task_Ultrasonic);
            vTaskSuspend(Task_LCD);
            Motor_Stop();
            Start_Flag = 0U;
            Set_Buttons_State(Stop);
        }
        else
        {
            /* Do Nothing */
        }
        vTaskDelayUntil(&xLastWakeTime_Car_Stop, Period_Car_Stop);
    }
}

void RC_CAR(void)
{
    /* Hardware Initializations */
    LCD_vidInit();
    LDR_Init();
    Temperature_Init();
    Ultrasonic_Init();
    Buttons_Init();
    Motor_Init();
    LED_Init();
    /* Queue Initializations */
    handles.LDRReadQueue_Handle = xQueueCreate(1U, sizeof(uint32_t));
    handles.TemperatureReadQueue_Handle = xQueueCreate(1U, sizeof(uint8_t));
    handles.TimeReadQueue_Handle = xQueueCreate(1U, sizeof(uint8_t));
    /* Task Creations */
    xTaskCreate(&avoid_obstacles, "avoid", 300U, (void*) (&Task_LDR), 7U,
                &Task_Ultrasonic);
    xTaskCreate(&ldr_swing_car, "swing", 300U,
                (void*) (&handles.LDRReadQueue_Handle), 5U, &Task_LDR);
    xTaskCreate(&temperature_task, "temperature",
    configMINIMAL_STACK_SIZE,
                (void*) (&handles.TemperatureReadQueue_Handle), 1U,
                &Task_Temperature);
    xTaskCreate(&Timer_Task, "time", configMINIMAL_STACK_SIZE,
                (void*) (&handles.TimeReadQueue_Handle), 8U, &Task_Timer);
    xTaskCreate(&lcd_display, "display", 300U, (void*) (&handles), 10U,
                &Task_LCD);
    xTaskCreate(&Car_Start, "start", configMINIMAL_STACK_SIZE, NULL, 2U, NULL);
    xTaskCreate(&Car_Stop, "stop", configMINIMAL_STACK_SIZE, NULL, 2U, NULL);
    /* Suspend Tasks */
    vTaskSuspend(Task_Timer);
    vTaskSuspend(Task_LDR);
    vTaskSuspend(Task_Temperature);
    vTaskSuspend(Task_Ultrasonic);
    vTaskSuspend(Task_LCD);
    /* Start Scheduler */
    vTaskStartScheduler();
    /* Loop should never be reached */
    Turn_On_LED(RED_LED);
    while (1)
    {
    }
}
