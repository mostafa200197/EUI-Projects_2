#include <Application/LDR_Task.h>

#define LDR_DIFFERENCE 500U
#define Period_LDR pdMS_TO_TICKS(100U)

void ldr_swing_car(void *pvParameters_LDR)
{
    TickType_t xLastWakeTime_LDR = xTaskGetTickCount();
    uint32_t LDR_Arr[2U] = { 100U, 10U };
    uint32_t Diff = 0U;
    QueueHandle_t Data_Handler = *((QueueHandle_t*) pvParameters_LDR);
    for (;;)
    {
        Turn_On_LED(CYAN_LED);
        if (LDR_Arr[0U] > LDR_Arr[1U])
        {
            Diff = LDR_Arr[0U] - LDR_Arr[1U];
            if (Diff > LDR_DIFFERENCE)
            {
                Motor_Set_Speed(0U, Right_Motors);
                Motor_Set_Speed(0U, Left_Motors);
                Motor_Set_Direction(Motor_Right_Reverse);
                Motor_Set_Direction(Motor_Left_Forward);
                Motor_Set_Speed(70U, Right_Motors);
                Motor_Set_Speed(70U, Left_Motors);
            }
            else
            {
                Motor_Set_Speed(0U, Right_Motors);
                Motor_Set_Speed(0U, Left_Motors);
                Motor_Set_Direction(Motor_Left_Forward);
                Motor_Set_Direction(Motor_Right_Forward);
                Motor_Set_Speed(70U, Right_Motors);
                Motor_Set_Speed(70U, Left_Motors);
            }
        }
        else
        {
            Diff = LDR_Arr[1U] - LDR_Arr[0U];
            {
                if (Diff > LDR_DIFFERENCE)
                {
                    Motor_Set_Speed(0U, Right_Motors);
                    Motor_Set_Speed(0U, Left_Motors);
                    Motor_Set_Direction(Motor_Right_Forward);
                    Motor_Set_Direction(Motor_Left_Reverse);
                    Motor_Set_Speed(70U, Right_Motors);
                    Motor_Set_Speed(70U, Left_Motors);
                }
                else
                {
                    Motor_Set_Speed(0U, Right_Motors);
                    Motor_Set_Speed(0U, Left_Motors);
                    Motor_Set_Direction(Motor_Left_Forward);
                    Motor_Set_Direction(Motor_Right_Forward);
                    Motor_Set_Speed(70U, Right_Motors);
                    Motor_Set_Speed(70U, Left_Motors);
                }
            }
        }
        /*Send Diff To Screen*/
        xQueueSend(Data_Handler, (void* ) &Diff, 0U);
        LDR_Read(LDR_Arr);
        vTaskDelayUntil(&xLastWakeTime_LDR, Period_LDR);
    }
}
