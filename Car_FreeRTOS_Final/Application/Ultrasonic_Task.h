#ifndef APPLICATION_ULTRASONIC_TASK_H_
#define APPLICATION_ULTRASONIC_TASK_H_

#include <stdint.h>
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "HAL/Ultrasonic/Ultrasonic.h"
#include "HAL/Motor/Motor.h"
#include "HAL/LED/LED.h"

typedef enum{
    No_Obstacle, Obstacle
}Obstacle_Typedef;

extern TaskHandle_t Task_LDR;

void avoid_obstacles(void *pvParameters_Ultrasonic);

#endif /* APPLICATION_ULTRASONIC_TASK_H_ */
