#ifndef HAL_LDR_H_
#define HAL_LDR_H_

#include <stdint.h>
#include "MCAL/MCAL.h"

void LDR_Init(void);
void LDR_Read(uint32_t *arr);

#endif /* HAL_LDR_H_ */
