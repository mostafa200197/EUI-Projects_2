#ifndef MCAL_INTERRUPTS_INTERRUPT_HANDLERS_H_
#define MCAL_INTERRUPTS_INTERRUPT_HANDLERS_H_

/* Includes */

#include <stdint.h>
#include <UTILS/Register_Map.h>
#include <MCAL/Interrupts/NVIC.h>

/* Interrupt Handler Prototypes */

void Default_GPIO_IRQ_Handler(uint32_t pin);
void GPIOA_IRQ_Handler(void);
void GPIOB_IRQ_Handler(void);
void GPIOC_IRQ_Handler(void);
void GPIOD_IRQ_Handler(void);
void GPIOE_IRQ_Handler(void);
void GPIOF_IRQ_Handler(void);
void Timer0_A_IRQ_Handler(void);
void Timer0_B_IRQ_Handler(void);
void Timer1_A_IRQ_Handler(void);
void Timer1_B_IRQ_Handler(void);
void Timer2_A_IRQ_Handler(void);
void Timer2_B_IRQ_Handler(void);
void Timer3_A_IRQ_Handler(void);
void Timer3_B_IRQ_Handler(void);
void Timer4_A_IRQ_Handler(void);
void Timer4_B_IRQ_Handler(void);
void Timer5_A_IRQ_Handler(void);
void Timer5_B_IRQ_Handler(void);
void wTimer0_A_IRQ_Handler(void);
void wTimer0_B_IRQ_Handler(void);
void wTimer1_A_IRQ_Handler(void);
void wTimer1_B_IRQ_Handler(void);
void wTimer2_A_IRQ_Handler(void);
void wTimer2_B_IRQ_Handler(void);
void wTimer3_A_IRQ_Handler(void);
void wTimer3_B_IRQ_Handler(void);
void wTimer4_A_IRQ_Handler(void);
void wTimer4_B_IRQ_Handler(void);
void wTimer5_A_IRQ_Handler(void);
void wTimer5_B_IRQ_Handler(void);
void ADC0_Sequencer0_IRQ_Handler(void);
void ADC0_Sequencer1_IRQ_Handler(void);
void ADC0_Sequencer2_IRQ_Handler(void);
void ADC0_Sequencer3_IRQ_Handler(void);
void ADC1_Sequencer0_IRQ_Handler(void);
void ADC1_Sequencer1_IRQ_Handler(void);
void ADC1_Sequencer2_IRQ_Handler(void);
void ADC1_Sequencer3_IRQ_Handler(void);
void UART0_IRQ_Handler(void);
void UART1_IRQ_Handler(void);
void UART2_IRQ_Handler(void);
void UART3_IRQ_Handler(void);
void UART4_IRQ_Handler(void);
void UART5_IRQ_Handler(void);
void UART6_IRQ_Handler(void);
void UART7_IRQ_Handler(void);
void SSI0_IRQ_Handler(void);
void SSI1_IRQ_Handler(void);
void SSI2_IRQ_Handler(void);
void SSI3_IRQ_Handler(void);
void I2C0_IRQ_Handler(void);
void I2C1_IRQ_Handler(void);
void I2C2_IRQ_Handler(void);
void I2C3_IRQ_Handler(void);
void PWM0_Generator0_IRQ_Handler(void);
void PWM0_Generator1_IRQ_Handler(void);
void PWM0_Generator2_IRQ_Handler(void);
void PWM0_Generator3_IRQ_Handler(void);
void PWM0_Fault_IRQ_Handler(void);
void PWM1_Generator0_IRQ_Handler(void);
void PWM1_Generator1_IRQ_Handler(void);
void PWM1_Generator2_IRQ_Handler(void);
void PWM1_Generator3_IRQ_Handler(void);
void PWM1_Fault_IRQ_Handler(void);
void SysTick_IRQ_Handler(void);

/* Callback Function Pointers */

extern void (*ptr_GPIO[6])(uint32_t pin);
extern void (*ptr_Timer[24])(void);
extern void (*ptr_ADC[8])(void);

#endif /* MCAL_INTERRUPTS_INTERRUPT_HANDLERS_H_ */
