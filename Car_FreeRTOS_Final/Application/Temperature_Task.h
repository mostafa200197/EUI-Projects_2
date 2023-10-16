#ifndef APPLICATION_TEMPERATURE_TASK_H_
#define APPLICATION_TEMPERATURE_TASK_H_

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

void temperature_task(void *pvParameters_Temperature);

#endif /* APPLICATION_TEMPERATURE_TASK_H_ */
