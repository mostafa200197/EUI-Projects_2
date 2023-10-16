#ifndef MAIN_H_
#define MAIN_H_

#include <stdint.h>
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "Application/RC_Car.h"
#include "MCAL/System_Control_Drivers/System_Control.h"

uint8_t main(void);

#endif /* MAIN_H_ */
