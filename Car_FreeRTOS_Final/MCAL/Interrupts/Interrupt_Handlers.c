#include "MCAL/Interrupts/Interrupt_Handlers.h"

void Default_GPIO_IRQ_Handler(uint32_t pin)
{
    while (1)
    {
    }
}

void GPIOA_IRQ_Handler(void)
{
    (*ptr_GPIO[0])(GPIOA->MIS);
    GPIOA->ICR |= GPIOA->MIS;
}

void GPIOB_IRQ_Handler(void)
{
    (*ptr_GPIO[1])(GPIOB->MIS);
    GPIOB->ICR |= GPIOB->MIS;
}

void GPIOC_IRQ_Handler(void)
{
    (*ptr_GPIO[2])(GPIOC->MIS);
    GPIOC->ICR |= GPIOC->MIS;
}

void GPIOD_IRQ_Handler(void)
{
    (*ptr_GPIO[3])(GPIOD->MIS);
    GPIOD->ICR |= GPIOD->MIS;
}

void GPIOE_IRQ_Handler(void)
{
    (*ptr_GPIO[4])(GPIOE->MIS);
    GPIOE->ICR |= GPIOE->MIS;
}

void GPIOF_IRQ_Handler(void)
{
    (*ptr_GPIO[5])(GPIOF->MIS);
    GPIOF->ICR |= GPIOF->MIS;
}

void Timer0_A_IRQ_Handler(void)
{
    (*ptr_Timer[0])();
    TIMER0->ICR |= TIMER0->MIS;
}

void Timer0_B_IRQ_Handler(void)
{
    (*ptr_Timer[1])();
    TIMER0->ICR |= TIMER0->MIS;
}

void Timer1_A_IRQ_Handler(void)
{
    (*ptr_Timer[2])();
    TIMER1->ICR |= TIMER1->MIS;
}

void Timer1_B_IRQ_Handler(void)
{
    (*ptr_Timer[3])();
    TIMER1->ICR |= TIMER1->MIS;
}

void Timer2_A_IRQ_Handler(void)
{
    (*ptr_Timer[4])();
    TIMER2->ICR |= TIMER2->MIS;
}

void Timer2_B_IRQ_Handler(void)
{
    (*ptr_Timer[5])();
    TIMER2->ICR |= TIMER2->MIS;
}

void Timer3_A_IRQ_Handler(void)
{
    (*ptr_Timer[6])();
    TIMER3->ICR |= TIMER3->MIS;
}

void Timer3_B_IRQ_Handler(void)
{
    (*ptr_Timer[7])();
    TIMER3->ICR |= TIMER3->MIS;
}

void Timer4_A_IRQ_Handler(void)
{
    (*ptr_Timer[8])();
    TIMER4->ICR |= TIMER4->MIS;
}

void Timer4_B_IRQ_Handler(void)
{
    (*ptr_Timer[9])();
    TIMER4->ICR |= TIMER4->MIS;
}

void Timer5_A_IRQ_Handler(void)
{
    (*ptr_Timer[10])();
    TIMER5->ICR |= TIMER5->MIS;
}

void Timer5_B_IRQ_Handler(void)
{
    (*ptr_Timer[11])();
    TIMER5->ICR |= TIMER5->MIS;
}

void wTimer0_A_IRQ_Handler(void)
{
    (*ptr_Timer[12])();
    WTIMER0->ICR |= WTIMER0->MIS;
}

void wTimer0_B_IRQ_Handler(void)
{
    (*ptr_Timer[13])();
    WTIMER0->ICR |= WTIMER0->MIS;
}

void wTimer1_A_IRQ_Handler(void)
{
    (*ptr_Timer[14])();
    WTIMER1->ICR |= WTIMER1->MIS;
}

void wTimer1_B_IRQ_Handler(void)
{
    (*ptr_Timer[15])();
    WTIMER1->ICR |= WTIMER1->MIS;
}

void wTimer2_A_IRQ_Handler(void)
{
    (*ptr_Timer[16])();
    WTIMER2->ICR |= WTIMER2->MIS;
}

void wTimer2_B_IRQ_Handler(void)
{
    (*ptr_Timer[17])();
    WTIMER2->ICR |= WTIMER2->MIS;
}

void wTimer3_A_IRQ_Handler(void)
{
    (*ptr_Timer[18])();
    WTIMER3->ICR |= WTIMER3->MIS;
}

void wTimer3_B_IRQ_Handler(void)
{
    (*ptr_Timer[19])();
    WTIMER3->ICR |= WTIMER3->MIS;
}

void wTimer4_A_IRQ_Handler(void)
{
    (*ptr_Timer[20])();
    WTIMER4->ICR |= WTIMER4->MIS;
}

void wTimer4_B_IRQ_Handler(void)
{
    (*ptr_Timer[21])();
    WTIMER4->ICR |= WTIMER4->MIS;
}

void wTimer5_A_IRQ_Handler(void)
{
    (*ptr_Timer[22])();
    WTIMER5->ICR |= WTIMER5->MIS;
}

void wTimer5_B_IRQ_Handler(void)
{
    (*ptr_Timer[23])();
    WTIMER5->ICR |= WTIMER5->MIS;
}

void ADC0_Sequencer0_IRQ_Handler(void)
{
    (*ptr_ADC[0])();
    ADC0->ISC |= ADC0->ISC;
}

void ADC0_Sequencer1_IRQ_Handler(void)
{
    (*ptr_ADC[1])();
    ADC0->ISC |= ADC0->ISC;
}

void ADC0_Sequencer2_IRQ_Handler(void)
{
    (*ptr_ADC[2])();
    ADC0->ISC |= ADC0->ISC;
}

void ADC0_Sequencer3_IRQ_Handler(void)
{
    (*ptr_ADC[3])();
    ADC0->ISC |= ADC0->ISC;
}

void ADC1_Sequencer0_IRQ_Handler(void)
{
    (*ptr_ADC[4])();
    ADC1->ISC |= ADC1->ISC;
}

void ADC1_Sequencer1_IRQ_Handler(void)
{
    (*ptr_ADC[5])();
    ADC1->ISC |= ADC1->ISC;
}

void ADC1_Sequencer2_IRQ_Handler(void)
{
    (*ptr_ADC[6])();
    ADC1->ISC |= ADC1->ISC;
}

void ADC1_Sequencer3_IRQ_Handler(void)
{
    (*ptr_ADC[7])();
    ADC1->ISC |= ADC1->ISC;
}

void UART0_IRQ_Handler(void)
{
    UART0->ICR |= UART0->MIS;
}

void UART1_IRQ_Handler(void)
{
    UART1->ICR |= UART1->MIS;
}

void UART2_IRQ_Handler(void)
{
    UART2->ICR |= UART2->MIS;
}

void UART3_IRQ_Handler(void)
{
    UART3->ICR |= UART3->MIS;
}

void UART4_IRQ_Handler(void)
{
    UART4->ICR |= UART4->MIS;
}

void UART5_IRQ_Handler(void)
{
    UART5->ICR |= UART5->MIS;
}

void UART6_IRQ_Handler(void)
{
    UART6->ICR |= UART6->MIS;
}

void UART7_IRQ_Handler(void)
{
    UART7->ICR |= UART7->MIS;
}

void SSI0_IRQ_Handler(void)
{
    SSI0->ICR |= SSI0->MIS;
}

void SSI1_IRQ_Handler(void)
{
    SSI1->ICR |= SSI1->MIS;
}

void SSI2_IRQ_Handler(void)
{
    SSI2->ICR |= SSI2->MIS;
}

void SSI3_IRQ_Handler(void)
{
    SSI3->ICR |= SSI3->MIS;
}

void I2C0_IRQ_Handler(void)
{
    I2C0->MICR |= I2C0->MMIS;
    I2C0->SICR |= I2C0->SMIS;
}

void I2C1_IRQ_Handler(void)
{
    I2C1->MICR |= I2C1->MMIS;
    I2C1->SICR |= I2C1->SMIS;
}

void I2C2_IRQ_Handler(void)
{
    I2C2->MICR |= I2C2->MMIS;
    I2C2->SICR |= I2C2->SMIS;
}

void I2C3_IRQ_Handler(void)
{
    I2C3->MICR |= I2C3->MMIS;
    I2C3->SICR |= I2C3->SMIS;
}

void PWM0_Generator0_IRQ_Handler(void)
{
    PWM0->_0_ISC |= PWM0->_0_ISC;
}

void PWM0_Generator1_IRQ_Handler(void)
{
    PWM0->_1_ISC |= PWM0->_1_ISC;
}

void PWM0_Generator2_IRQ_Handler(void)
{
    PWM0->_2_ISC |= PWM0->_2_ISC;
}

void PWM0_Generator3_IRQ_Handler(void)
{
    PWM0->_3_ISC |= PWM0->_3_ISC;
}

void PWM0_Fault_IRQ_Handler(void)
{
    PWM0->ISC |= PWM0->ISC;
}

void PWM1_Generator0_IRQ_Handler(void)
{
    PWM1->_0_ISC |= PWM1->_0_ISC;
}

void PWM1_Generator1_IRQ_Handler(void)
{
    PWM1->_1_ISC |= PWM1->_1_ISC;
}

void PWM1_Generator2_IRQ_Handler(void)
{
    PWM1->_2_ISC |= PWM1->_2_ISC;
}

void PWM1_Generator3_IRQ_Handler(void)
{
    PWM1->_3_ISC |= PWM1->_3_ISC;
}

void PWM1_Fault_IRQ_Handler(void)
{
    PWM1->ISC |= PWM1->ISC;
}

void SysTick_IRQ_Handler(void)
{
    (*ptr_NVIC)();
}
