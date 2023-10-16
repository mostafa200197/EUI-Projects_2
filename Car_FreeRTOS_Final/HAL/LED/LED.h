#ifndef HAL_LED_LED_H_
#define HAL_LED_LED_H_

#include <stdint.h>
#include "MCAL/MCAL.h"

#define RED_LED PF1
#define BLUE_LED PF2
#define GREEN_LED PF3
#define CYAN_LED BLUE_LED|GREEN_LED
#define PURPLE_LED RED_LED|BLUE_LED
#define YELLOW_LED RED_LED|GREEN_LED
#define WHITE_LED RED_LED|GREEN_LED|BLUE_LED
#define NO_LED 0U

void LED_Init(void);
void Turn_On_LED(uint8_t LED);

#endif /* HAL_LED_LED_H_ */
