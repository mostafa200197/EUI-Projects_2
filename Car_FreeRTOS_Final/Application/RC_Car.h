#ifndef APPLICATION_RC_CAR_H_
#define APPLICATION_RC_CAR_H_

#include <stdint.h>
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "HAL/LCD/LCD.h"
#include "HAL/LDR/LDR.h"
#include "HAL/Motor/Motor.h"
#include "HAL/Temperature/Temperature.h"
#include "HAL/Ultrasonic/Ultrasonic.h"
#include "HAL/Buttons/Buttons.h"
#include "HAL/LED/LED.h"

#include <Application/LCD_Task.h>
#include <Application/LDR_Task.h>
#include <Application/Temperature_Task.h>
#include "Application/Ultrasonic_Task.h"

void Timer_Task(void *pvParameters_Timer);
void Car_Start(void *pvParameters_Car_Start);
void Car_Stop(void *pvParameters_Car_Stop);
void RC_CAR(void);

#endif /* APPLICATION_RC_CAR_H_ */
