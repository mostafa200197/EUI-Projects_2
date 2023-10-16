#ifndef MCAL_GPIO_DRIVERS_GPIO_CTRL_H_
#define MCAL_GPIO_DRIVERS_GPIO_CTRL_H_

/* Includes */

#include <stdint.h>
#include <UTILS/std_typedefs.h>
#include <MCAL/GPIO_Drivers/GPIO.h>

/* Config Structs */

typedef struct
{
    uint32_t Pin;
    uint32_t Mode;
    uint32_t Pull;
    uint32_t AF;
    uint32_t AF_Mode;
    uint32_t Analog;
} GPIO_InitTypeDef;

/* Config Defines */

#define Input                           0U
#define Output                          1U

#define FLOATING                        0U
#define PULL_UP                         1U
#define PULL_DOWN                       2U

#define Low                             0U
#define High                            1U

/* Config Enums */



/* Function Prototypes */

void GPIO_Init(GPIO_RegDef_t *GPIOx, const GPIO_InitTypeDef *GPIO_Config);
void GPIO_Write(GPIO_RegDef_t *GPIOx, uint8_t Pin, uint8_t Mode);
void GPIO_Write_Pins(GPIO_RegDef_t *GPIOx, uint32_t Pins, uint8_t State);
void GPIO_Toggle(GPIO_RegDef_t *GPIOx, uint8_t Pins);
uint8_t GPIO_Read(GPIO_RegDef_t *GPIOx, uint8_t Pin);

#endif /* MCAL_GPIO_DRIVERS_GPIO_CTRL_H_ */
