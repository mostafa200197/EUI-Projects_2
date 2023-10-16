#ifndef MCAL_GPIO_DRIVERS_GPIO_INTERRUPTS_H_
#define MCAL_GPIO_DRIVERS_GPIO_INTERRUPTS_H_

/* Includes */

#include <stdint.h>
#include <MCAL/GPIO_Drivers/GPIO.h>
#include <UTILS/std_typedefs.h>

/* Interrupt Structs */

typedef struct
{
    uint32_t Pin;
    uint32_t Sense;
    uint32_t Trigger;
} GPIO_Init_InterruptTypeDef;

/* Interrupt Defines */

#define Edge                            0U
#define Level                           1U
#define Falling_Edge_GPIO               0U
#define Rising_Edge_GPIO                1U
#define Both_GPIO                       2U
#define Low_Level_GPIO                  0U
#define High_Level_GPIO                 1U

/* Function Prototypes */

void GPIO_Int_Register(uint8_t Port, void (*pfnIntHandler)(uint32_t Pin));
void GPIO_Interrupt_Init(GPIO_RegDef_t *GPIOx,
                         const GPIO_Init_InterruptTypeDef *GPIO_Int_Config);

#endif /* MCAL_GPIO_DRIVERS_GPIO_INTERRUPTS_H_ */
