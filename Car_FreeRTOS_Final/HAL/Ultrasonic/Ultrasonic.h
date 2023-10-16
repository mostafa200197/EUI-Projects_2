#ifndef HAL_ULTRASONIC_ULTRASONIC_H_
#define HAL_ULTRASONIC_ULTRASONIC_H_

#include <stdint.h>
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "MCAL/MCAL.h"
#include "UTILS/Delay.h"

#define ULTRASONIC_IDLE                 0U
#define ULTRASONIC_BUSY                 1U
#define ULTRASONIC_READY                2U


void Ultrasonic_Init(void);
uint32_t Ultrasonic_Get_Distance(void);
void Ultrasonic_IRQ_Handler(void);
uint8_t Ultrasonic_Ready(void);
void Trigger_Ultrasonic(void);

#endif /* HAL_ULTRASONIC_ULTRASONIC_H_ */
