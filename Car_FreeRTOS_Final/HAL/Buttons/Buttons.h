#ifndef HAL_BUTTONS_BUTTONS_H_
#define HAL_BUTTONS_BUTTONS_H_

#include <stdint.h>
#include "MCAL/MCAL.h"

typedef enum
{
    Stop, Start
}Buttons_State_Typedef;

void Buttons_Init(void);
Buttons_State_Typedef Get_Buttons_State(void);
void Set_Buttons_State(Buttons_State_Typedef New_State);
void Buttons_IRQ_Callback(uint32_t Pins);

#endif /* HAL_BUTTONS_BUTTONS_H_ */
