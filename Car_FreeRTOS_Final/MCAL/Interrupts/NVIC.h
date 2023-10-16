#ifndef MCAL_INTERRUPTS_NVIC_H_
#define MCAL_INTERRUPTS_NVIC_H_

/* Includes */

#include <stdint.h>
#include <UTILS/Register_Map.h>
#include <UTILS/std_typedefs.h>

void (*ptr_NVIC)(void);

/* Interrupt Numbers */

#define GPIOA_Int                       0U
#define GPIOB_Int                       1U
#define GPIOC_Int                       2U
#define GPIOD_Int                       3U
#define GPIOE_Int                       4U
#define UART0_Int                       5U
#define UART1_Int                       6U
#define SSI0_Int                        7U
#define I2C0_Int                        8U
#define PWM0_Fault_Int                  9U
#define PWM0_Generator0_Int             10U
#define PWM0_Generator1_Int             11U
#define PWM0_Generator2_Int             12U
#define QEI0_Int                        13U
#define ADC0_Sequence0_Int              14U
#define ADC0_Sequence1_Int              15U
#define ADC0_Sequence2_Int              16U
#define ADC0_Sequence3_Int              17U
#define Watchdog_Timers_0_1_Int         18U
#define Timer0_A_Int                    19U
#define Timer0_B_Int                    20U
#define Timer1_A_Int                    21U
#define Timer1_B_Int                    22U
#define Timer2_A_Int                    23U
#define Timer2_B_Int                    24U
#define Analog_Comparator0_Int          25U
#define Analog_Comparator1_Int          26U
#define System_Control_Int              28U
#define Flash_EEPROM_Int                29U
#define GPIOF_Int                       30U
#define UART2_Int                       33U
#define SSI1_Int                        34U
#define Timer3_A_Int                    35U
#define Timer3_B_Int                    36U
#define I2C1_Int                        37U
#define QEI1_Int                        38U
#define CAN0_Int                        39U
#define CAN1_Int                        40U
#define Hibernation_Int                 43U
#define USB_Int                         44U
#define PWM0_Generator3                 45U
#define uDMA_Software_Int               46U
#define uDMA_Error_Int                  47U
#define ADC1_Sequence0_Int              48U
#define ADC1_Sequence1_Int              49U
#define ADC1_Sequence2_Int              50U
#define ADC1_Sequence3_Int              51U
#define SSI2_Int                        57U
#define SSI3_Int                        58U
#define UART3_Int                       59U
#define UART4_Int                       60U
#define UART5_Int                       61U
#define UART6_Int                       62U
#define UART7_Int                       63U
#define I2C2_Int                        68U
#define I2C3_Int                        69U
#define Timer4_A_Int                    70U
#define Timer4_B_Int                    71U
#define Timer5_A_Int                    92U
#define Timer5_B_Int                    93U
#define WTimer0_A_Int                   94U
#define WTimer0_B_Int                   95U
#define WTimer1_A_Int                   96U
#define WTimer1_B_Int                   97U
#define WTimer2_A_Int                   98U
#define WTimer2_B_Int                   99U
#define WTimer3_A_Int                   100U
#define WTimer3_B_Int                   101U
#define WTimer4_A_Int                   102U
#define WTimer4_B_Int                   103U
#define WTimer5_A_Int                   104U
#define WTimer5_B_Int                   105U
#define System_Exception_Int            106U
#define PWM1_Generator0_Int             134U
#define PWM1_Generator1_Int             135U
#define PWM1_Generator2_Int             136U
#define PWM1_Generator3_Int             137U
#define PWM1_Fault_Int                  138U

/* Function Prototypes */

void NVIC_Enable(uint8_t Int);
void NVIC_Set_Priority(uint8_t Int, uint8_t Priority);
void Systick_Interrupt_Register(void (*pfnIntHandler)(void));

#endif /* MCAL_INTERRUPTS_NVIC_H_ */
