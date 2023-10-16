#ifndef MCAL_SYSTEM_CONTROL_DRIVERS_SYSTEM_CONTROL_H_
#define MCAL_SYSTEM_CONTROL_DRIVERS_SYSTEM_CONTROL_H_

/* Includes */

#include <stdint.h>
#include <UTILS/Register_Map.h>

/* Defines */

/* PWMDIV Defines */

#define NO_PWM                          0U
#define RCC_USE_PWM                     0x00010000UL /* USEPWMDIV */
#define RCC_PWMDIV_2                    0x00000000UL /* PWMDIV /2 */
#define RCC_PWMDIV_4                    0x00002000UL /* PWMDIV /4 */
#define RCC_PWMDIV_8                    0x00004000UL /* PWMDIV /8 */
#define RCC_PWMDIV_16                   0x00006000UL /* PWMDIV /16 */
#define RCC_PWMDIV_32                   0x00008000UL /* PWMDIV /32 */
#define RCC_PWMDIV_64                   0x0000E000UL /* PWMDIV /64 */

/* Peripheral Clock Defines */

#define RCGC_OFFSET_START               0x600UL /* Offset of RCGC registers */
#define PR_OFFSET_START                 0xA00UL /* Offset of PR registers */

#define ADC0_CLOCK_OFFSET               0xF0003800UL  /* ADC 0 */
#define ADC1_CLOCK_OFFSET               0xF0003801UL  /* ADC 1 */

#define GPIOA_CLOCK_OFFSET              0xF0000800UL  /* GPIO A */
#define GPIOB_CLOCK_OFFSET              0xF0000801UL  /* GPIO B */
#define GPIOC_CLOCK_OFFSET              0xF0000802UL  /* GPIO C */
#define GPIOD_CLOCK_OFFSET              0xF0000803UL  /* GPIO D */
#define GPIOE_CLOCK_OFFSET              0xF0000804UL  /* GPIO E */
#define GPIOF_CLOCK_OFFSET              0xF0000805UL  /* GPIO F */

#define TIMER0_CLOCK_OFFSET             0xF0000400UL  /* Timer 0 */
#define TIMER1_CLOCK_OFFSET             0xF0000401UL  /* Timer 1 */
#define TIMER2_CLOCK_OFFSET             0xF0000402UL  /* Timer 2 */
#define TIMER3_CLOCK_OFFSET             0xF0000403UL  /* Timer 3 */
#define TIMER4_CLOCK_OFFSET             0xF0000404UL  /* Timer 4 */
#define TIMER5_CLOCK_OFFSET             0xF0000405UL  /* Timer 5 */

#define WTIMER0_CLOCK_OFFSET            0xF0005C00UL  /* Wide Timer 0 */
#define WTIMER1_CLOCK_OFFSET            0xF0005C01UL  /* Wide Timer 1 */
#define WTIMER2_CLOCK_OFFSET            0xF0005C02UL  /* Wide Timer 2 */
#define WTIMER3_CLOCK_OFFSET            0xF0005C03UL  /* Wide Timer 3 */
#define WTIMER4_CLOCK_OFFSET            0xF0005C04UL  /* Wide Timer 4 */
#define WTIMER5_CLOCK_OFFSET            0xF0005C05UL  /* Wide Timer 5 */

#define PWM0_CLOCK_OFFSET               0xF0004000UL  /* PWM0 */
#define PWM1_CLOCK_OFFSET               0xF0004001UL  /* PWM1 */

/* Function Prototypes */

void Configure_Clock(uint8_t Clock_Freq, uint32_t PWM_Config);
void Enable_Peripheral_Clock(uint32_t Peripheral);

#endif /* MCAL_SYSTEM_CONTROL_DRIVERS_SYSTEM_CONTROL_H_ */
