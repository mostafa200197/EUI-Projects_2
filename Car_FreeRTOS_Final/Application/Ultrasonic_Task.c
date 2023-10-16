#include "Application/Ultrasonic_Task.h"

/*Defines*/
#define MIN_DISTANCE 10U
#define SAFE_DISTANCE 30U
#define TURN_PERIOD 1000U
#define Period_Ultrasonic pdMS_TO_TICKS(10U)

void avoid_obstacles(void *pvParameters_Ultrasonic)
{
    uint8_t Ultrasonic_State = ULTRASONIC_IDLE;
    uint32_t Ultrasonic_Distance = 100U;
    Obstacle_Typedef Obstacle_Flag = No_Obstacle;
    uint8_t Ultrasonic_Turning_Counter = 0U;
    uint8_t Ultrasonic_Trigger_Counter = 1U;
    TickType_t xLastWakeTime_Ultrasonic;
    TaskHandle_t TASK_LDR = *((TaskHandle_t*) pvParameters_Ultrasonic);

    while (1)
    {
        xLastWakeTime_Ultrasonic = xTaskGetTickCount();
        Turn_On_LED(PURPLE_LED);
        Ultrasonic_State = Ultrasonic_Ready();
        switch (Ultrasonic_State)
        {
        case ULTRASONIC_IDLE:
            Trigger_Ultrasonic();
            break;
        case ULTRASONIC_BUSY:
            break;
        case ULTRASONIC_READY:
            if (Ultrasonic_Trigger_Counter == 6U)
            {
                Ultrasonic_Distance = Ultrasonic_Get_Distance();
                Ultrasonic_Trigger_Counter = 0U;
            }
            else
            {
            }
            break;
        default:
            break;
        }
        Ultrasonic_Trigger_Counter++;
        if (Ultrasonic_Distance <= MIN_DISTANCE)
        {
            vTaskSuspend(TASK_LDR);
            Motor_Set_Speed(0U, Right_Motors);
            Motor_Set_Speed(0U, Left_Motors);
            Motor_Set_Direction(Motor_Right_Reverse);
            Motor_Set_Direction(Motor_Left_Reverse);
            Motor_Set_Speed(70U, Right_Motors);
            Motor_Set_Speed(70U, Left_Motors);
            Obstacle_Flag = Obstacle;
        }
        else if ((Ultrasonic_Distance >= SAFE_DISTANCE)
                && (Obstacle_Flag == Obstacle))
        {
            Motor_Set_Speed(0U, Right_Motors);
            Motor_Set_Speed(0U, Left_Motors);
            Motor_Set_Direction(Motor_Right_Reverse);
            Motor_Set_Direction(Motor_Left_Forward);
            Motor_Set_Speed(70U, Right_Motors);
            Motor_Set_Speed(70U, Left_Motors);
            if (Ultrasonic_Turning_Counter == TURN_PERIOD / 10U)
            {
                Obstacle_Flag = No_Obstacle;
                Ultrasonic_Turning_Counter = 0U;
            }
            else
            {
                Ultrasonic_Turning_Counter++;
            }
        }
        else if (Obstacle_Flag == No_Obstacle)
        {
            vTaskResume(TASK_LDR);
        }
        else
        {
        }
        vTaskDelayUntil(&xLastWakeTime_Ultrasonic, Period_Ultrasonic);
    }
}
