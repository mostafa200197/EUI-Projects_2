#ifndef APPLICATION_LDR_TASK_H_
#define APPLICATION_LDR_TASK_H_

#include <stdint.h>
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "HAL/LDR/LDR.h"
#include "HAL/LED/LED.h"
#include "HAL/Motor/Motor.h"

void ldr_swing_car(void *pvParameters_LDR);

#endif /* APPLICATION_LDR_TASK_H_ */
