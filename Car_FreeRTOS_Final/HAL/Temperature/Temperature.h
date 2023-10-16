
#ifndef HAL_TEMPERATURE_H_
#define HAL_TEMPERATURE_H_

#include <stdint.h>
#include "MCAL/MCAL.h"

void Temperature_Init(void);
uint8_t Temperature_Read(void);


#endif /* HAL_TEMPERATURE_H_ */
