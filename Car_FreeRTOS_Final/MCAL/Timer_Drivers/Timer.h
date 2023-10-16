#ifndef MCAL_TIMER_DRIVERS_TIMER_H_
#define MCAL_TIMER_DRIVERS_TIMER_H_

/* Include */

#include <stdint.h>
#include <UTILS/Register_Map.h>
#include <UTILS/std_typedefs.h>

/* Timer Structs */

typedef struct
{
    uint32_t Load;
    uint32_t Prescalar;
    uint32_t Config;
    uint32_t Timer;
    uint32_t PWM;
    uint32_t Trigger;
    uint32_t Polarity;
    uint32_t Mode;
    uint32_t Count_Mode;
    uint32_t Edge_Mode;
} Timer_InitTypeDef;

typedef struct
{
    uint32_t Timer;
    uint32_t Time_Out;
    uint32_t Capture_Match;
    uint32_t Capture_Event;
    uint32_t Match;
    uint32_t PWM;
} Timer_Init_InterruptTypedef;

/* Defines */

#define Timer_0                         0U
#define Timer_1                         1U
#define Timer_2                         2U
#define Timer_3                         3U
#define Timer_4                         4U
#define Timer_5                         5U
#define WTimer_0                        6U
#define WTimer_1                        7U
#define WTimer_2                        8U
#define WTimer_3                        9U
#define WTimer_4                        10U
#define WTimer_5                        11U

#define TimerA                          0U
#define TimerB                          1U

#define Non_Inverted                    0U
#define Inverted                        1U

#define Concatenated                    0U
#define Individual                      4U

#define One_Shot                        1U
#define Periodic                        2U
#define Capture                         3U

#define Edge_Count                      0U
#define Edge_Time                       1U

#define Down                            0U
#define Up                              1U

#define Rising_Edge_Timer               0U
#define Falling_Edge_Timer              1U
#define Both_Timer                      3U

/* Function Prototypes */

void Timer_Init(Timer_RegDef_t *Timerx, const Timer_InitTypeDef *Timer_Config);
void Timer_Interrupt_Init(Timer_RegDef_t *Timerx,
                          const Timer_Init_InterruptTypedef *Timer_Int_Config);
void Timer_SetMatch(Timer_RegDef_t *Timerx, uint8_t Timer, uint32_t Match);
uint32_t Timer_GetMatch(const Timer_RegDef_t *Timerx, uint8_t Timer);
void Timer_SetLoad(Timer_RegDef_t *Timerx, uint8_t Timer, uint32_t Load);
uint32_t Timer_GetCount(const Timer_RegDef_t *Timerx, uint8_t Timer);
void Timer_Interrupt_Register(uint8_t Timer, uint8_t SubTimer,
                              void (*pfnIntHandler)(void));

#endif /* MCAL_TIMER_DRIVERS_TIMER_H_ */
