#ifndef UTILS_DELAY_H_
#define UTILS_DELAY_H_

/* Includes */

#include <stdint.h>
#include <UTILS/std_typedefs.h>
#include <UTILS/Register_Map.h>

/* Frequency Factors */

#define Freq_Factor_Milli               4000U
#define Freq_Factor_Micro               4U

/* Checks */

/* #define Hardware_Delay Uses SysTick Timer */
#define Software_Delay

/* Function Prototypes */

void Delay_ms(uint32_t delay);
void Delay_us(uint32_t delay);

#endif /* UTILS_DELAY_H_ */
