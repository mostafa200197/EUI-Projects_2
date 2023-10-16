/******************************************************************************
**
** Startup code for use with TI's Code Composer Studio.
**
** Copyright (c) 2011-2014 Texas Instruments Incorporated.  All rights reserved.
** Software License Agreement
**
** Software License Agreement
**
** Texas Instruments (TI) is supplying this software for use solely and
** exclusively on TI's microcontroller products. The software is owned by
** TI and/or its suppliers, and is protected under applicable copyright
** laws. You may not combine this software with "viral" open-source
** software in order to form a larger program.
**
** THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
** NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
** NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
** CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
** DAMAGES, FOR ANY REASON WHATSOEVER.
**
******************************************************************************/

#include <stdint.h>
#include <MCAL/Interrupts/Interrupt_Handlers.h>

/******************************************************************************
**
** Forward declaration of the default fault handlers.
**
******************************************************************************/
void ResetISR(void);
static void NmiSR(void);
static void FaultISR(void);
static void IntDefaultHandler(void);

/*****************************************************************************
**
** External declaration for the reset handler that is to be called when the
** processor is started
**
******************************************************************************/
extern void _c_int00(void);
/******************************************************************************
**
** Linker variable that marks the top of the stack.
**
******************************************************************************/
extern uint32_t __STACK_TOP;

/******************************************************************************
**
** External declarations for the interrupt handlers used by the application.
**
*******************************************************************************
** To be added by user */
extern void xPortPendSVHandler(void);
extern void vPortSVCHandler(void);
extern void xPortSysTickHandler(void);
/******************************************************************************
**
** The vector table.  Note that the proper constructs must be placed on this to
** ensure that it ends up at physical address 0x0000.0000 or at the start of
** the program if located at a start address other than 0.
**
******************************************************************************/
#pragma DATA_SECTION(g_pfnVectors, ".intvecs")
void (* const g_pfnVectors[])(void) =
{
    (void (*)(void))((uint32_t)&__STACK_TOP),
                                        /* The initial stack pointer */
    &ResetISR,                          /* The reset handler */
    &NmiSR,                             /* The NMI handler */
    &FaultISR,                          /* The hard fault handler */
    &IntDefaultHandler,                 /* The MPU fault handler */
    &IntDefaultHandler,                 /* The bus fault handler */
    &IntDefaultHandler,                 /* The usage fault handler */
    0,                                  /* Reserved */
    0,                                  /* Reserved */
    0,                                  /* Reserved */
    0,                                  /* Reserved */
    &vPortSVCHandler,                   /* SVCall handler */
    &IntDefaultHandler,                 /* Debug monitor handler */
    0,                                  /* Reserved */
    &xPortPendSVHandler,                /* The PendSV handler */
    &xPortSysTickHandler,               /* The SysTick handler */
    &GPIOA_IRQ_Handler,                 /* GPIO Port A */
    &GPIOB_IRQ_Handler,                 /* GPIO Port B */
    &GPIOC_IRQ_Handler,                 /* GPIO Port C */
    &GPIOD_IRQ_Handler,                 /* GPIO Port D */
    &GPIOE_IRQ_Handler,                 /* GPIO Port E */
    &UART0_IRQ_Handler,                 /* UART0 Rx and Tx */
    &UART1_IRQ_Handler,                 /* UART1 Rx and Tx */
    &SSI0_IRQ_Handler,                  /* SSI0 Rx and Tx */
    &I2C0_IRQ_Handler,                  /* I2C0 Master and Slave */
    &PWM0_Fault_IRQ_Handler,            /* PWM Fault */
    &PWM0_Generator0_IRQ_Handler,       /* PWM Generator 0 */
    &PWM0_Generator1_IRQ_Handler,       /* PWM Generator 1 */
    &PWM0_Generator2_IRQ_Handler,       /* PWM Generator 2 */
    &IntDefaultHandler,                 /* Quadrature Encoder 0 */
    &ADC0_Sequencer0_IRQ_Handler,       /* ADC0 Sequence 0 */
    &ADC0_Sequencer1_IRQ_Handler,       /* ADC0 Sequence 1 */
    &ADC0_Sequencer2_IRQ_Handler,       /* ADC0 Sequence 2 */
    &ADC0_Sequencer3_IRQ_Handler,       /* ADC0 Sequence 3 */
    &IntDefaultHandler,                 /* Watchdog timer */
    &Timer0_A_IRQ_Handler,              /* Timer 0 subtimer A */
    &Timer0_B_IRQ_Handler,              /* Timer 0 subtimer B */
    &Timer1_A_IRQ_Handler,              /* Timer 1 subtimer A */
    &Timer1_B_IRQ_Handler,              /* Timer 1 subtimer B */
    &Timer2_A_IRQ_Handler,              /* Timer 2 subtimer A */
    &Timer2_B_IRQ_Handler,              /* Timer 2 subtimer B */
    &IntDefaultHandler,                 /* Analog Comparator 0 */
    &IntDefaultHandler,                 /* Analog Comparator 1 */
    &IntDefaultHandler,                 /* Analog Comparator 2 */
    &IntDefaultHandler,                 /* System Control (PLL, OSC, BO) */
    &IntDefaultHandler,                 /* FLASH Control */
    &GPIOF_IRQ_Handler,                 /* GPIO Port F */
    &IntDefaultHandler,                 /* GPIO Port G */
    &IntDefaultHandler,                 /* GPIO Port H */
    &UART2_IRQ_Handler,                 /* UART2 Rx and Tx */
    &SSI1_IRQ_Handler,                  /* SSI1 Rx and Tx */
    &Timer3_A_IRQ_Handler,              /* Timer 3 subtimer A */
    &Timer3_B_IRQ_Handler,              /* Timer 3 subtimer B */
    &I2C1_IRQ_Handler,                  /* I2C1 Master and Slave */
    &IntDefaultHandler,                 /* Quadrature Encoder 1 */
    &IntDefaultHandler,                 /* CAN0 */
    &IntDefaultHandler,                 /* CAN1 */
    0,                                  /* Reserved */
    0,                                  /* Reserved */
    &IntDefaultHandler,                 /* Hibernate */
    &IntDefaultHandler,                 /* USB0 */
    &PWM0_Generator3_IRQ_Handler,       /* PWM Generator 3 */
    &IntDefaultHandler,                 /* uDMA Software Transfer */
    &IntDefaultHandler,                 /* uDMA Error */
    &ADC1_Sequencer0_IRQ_Handler,       /* ADC1 Sequence 0 */
    &ADC1_Sequencer1_IRQ_Handler,       /* ADC1 Sequence 1 */
    &ADC1_Sequencer2_IRQ_Handler,       /* ADC1 Sequence 2 */
    &ADC1_Sequencer3_IRQ_Handler,       /* ADC1 Sequence 3 */
    0,                                  /* Reserved */
    0,                                  /* Reserved */
    &IntDefaultHandler,                 /* GPIO Port J */
    &IntDefaultHandler,                 /* GPIO Port K */
    &IntDefaultHandler,                 /* GPIO Port L */
    &SSI2_IRQ_Handler,                  /* SSI2 Rx and Tx */
    &SSI3_IRQ_Handler,                  /* SSI3 Rx and Tx */
    &UART3_IRQ_Handler,                 /* UART3 Rx and Tx */
    &UART4_IRQ_Handler,                 /* UART4 Rx and Tx */
    &UART5_IRQ_Handler,                 /* UART5 Rx and Tx */
    &UART6_IRQ_Handler,                 /* UART6 Rx and Tx */
    &UART7_IRQ_Handler,                 /* UART7 Rx and Tx */
    0,                                  /* Reserved */
    0,                                  /* Reserved */
    0,                                  /* Reserved */
    0,                                  /* Reserved */
    &I2C2_IRQ_Handler,                  /* I2C2 Master and Slave */
    &I2C3_IRQ_Handler,                  /* I2C3 Master and Slave */
    &Timer4_A_IRQ_Handler,              /* Timer 4 subtimer A */
    &Timer4_B_IRQ_Handler,              /* Timer 4 subtimer B */
    0,                                  /* Reserved */
    0,                                  /* Reserved */
    0,                                  /* Reserved */
    0,                                  /* Reserved */
    0,                                  /* Reserved */
    0,                                  /* Reserved */
    0,                                  /* Reserved */
    0,                                  /* Reserved */
    0,                                  /* Reserved */
    0,                                  /* Reserved */
    0,                                  /* Reserved */
    0,                                  /* Reserved */
    0,                                  /* Reserved */
    0,                                  /* Reserved */
    0,                                  /* Reserved */
    0,                                  /* Reserved */
    0,                                  /* Reserved */
    0,                                  /* Reserved */
    0,                                  /* Reserved */
    0,                                  /* Reserved */
    &Timer5_A_IRQ_Handler,              /* Timer 5 subtimer A */
    &Timer5_B_IRQ_Handler,              /* Timer 5 subtimer B */
    &wTimer0_A_IRQ_Handler,             /* Wide Timer 0 subtimer A */
    &wTimer0_B_IRQ_Handler,             /* Wide Timer 0 subtimer B */
    &wTimer1_A_IRQ_Handler,             /* Wide Timer 1 subtimer A */
    &wTimer1_B_IRQ_Handler,             /* Wide Timer 1 subtimer B */
    &wTimer2_A_IRQ_Handler,             /* Wide Timer 2 subtimer A */
    &wTimer2_B_IRQ_Handler,             /* Wide Timer 2 subtimer B */
    &wTimer3_A_IRQ_Handler,             /* Wide Timer 3 subtimer A */
    &wTimer3_B_IRQ_Handler,             /* Wide Timer 3 subtimer B */
    &wTimer4_A_IRQ_Handler,             /* Wide Timer 4 subtimer A */
    &wTimer4_B_IRQ_Handler,             /* Wide Timer 4 subtimer B */
    &wTimer5_A_IRQ_Handler,             /* Wide Timer 5 subtimer A */
    &wTimer5_B_IRQ_Handler,             /* Wide Timer 5 subtimer B */
    &IntDefaultHandler,                 /* FPU */
    0,                                  /* Reserved */
    0,                                  /* Reserved */
    &IntDefaultHandler,                 /* I2C4 Master and Slave */
    &IntDefaultHandler,                 /* I2C5 Master and Slave */
    &IntDefaultHandler,                 /* GPIO Port M */
    &IntDefaultHandler,                 /* GPIO Port N */
    &IntDefaultHandler,                 /* Quadrature Encoder 2 */
    0,                                  /* Reserved */
    0,                                  /* Reserved */
    &IntDefaultHandler,                 /* GPIO Port P (Summary or P0) */
    &IntDefaultHandler,                 /* GPIO Port P1 */
    &IntDefaultHandler,                 /* GPIO Port P2 */
    &IntDefaultHandler,                 /* GPIO Port P3 */
    &IntDefaultHandler,                 /* GPIO Port P4 */
    &IntDefaultHandler,                 /* GPIO Port P5 */
    &IntDefaultHandler,                 /* GPIO Port P6 */
    &IntDefaultHandler,                 /* GPIO Port P7 */
    &IntDefaultHandler,                 /* GPIO Port Q (Summary or Q0) */
    &IntDefaultHandler,                 /* GPIO Port Q1 */
    &IntDefaultHandler,                 /* GPIO Port Q2 */
    &IntDefaultHandler,                 /* GPIO Port Q3 */
    &IntDefaultHandler,                 /* GPIO Port Q4 */
    &IntDefaultHandler,                 /* GPIO Port Q5 */
    &IntDefaultHandler,                 /* GPIO Port Q6 */
    &IntDefaultHandler,                 /* GPIO Port Q7 */
    &IntDefaultHandler,                 /* GPIO Port R */
    &IntDefaultHandler,                 /* GPIO Port S */
    &PWM1_Generator0_IRQ_Handler,       /* PWM 1 Generator 0 */
    &PWM1_Generator1_IRQ_Handler,       /* PWM 1 Generator 1 */
    &PWM1_Generator2_IRQ_Handler,       /* PWM 1 Generator 2 */
    &PWM1_Generator3_IRQ_Handler,       /* PWM 1 Generator 3 */
    &PWM1_Fault_IRQ_Handler             /* PWM 1 Fault */
};

/******************************************************************************
**
** This is the code that gets called when the processor first starts execution
** following a reset event.  Only the absolutely necessary set is performed,
** after which the application supplied entry() routine is called.  Any fancy
** actions (such as making decisions based on the reset cause register, and
** resetting the bits in that register) are left solely in the hands of the
** application.
**
******************************************************************************/
void
ResetISR(void)
{
    /*
    ** Jump to the CCS C initialization routine.  This will enable the
    ** floating-point unit as well, so that does not need to be done here.
    */
    __asm("    .global _c_int00\n"
          "    b.w     _c_int00");
}

/******************************************************************************
**
** This is the code that gets called when the processor receives a NMI.  This
** simply enters an infinite loop, preserving the system state for examination
** by a debugger.
**
******************************************************************************/
static void
NmiSR(void)
{
    /*
    ** Enter an infinite loop.
    */
    while(1)
    {
    }
}

/******************************************************************************
**
** This is the code that gets called when the processor receives a fault
** interrupt.  This simply enters an infinite loop, preserving the system state
** for examination by a debugger.
**
******************************************************************************/
static void
FaultISR(void)
{
    /*
    ** Enter an infinite loop.
    */
    while(1)
    {
    }
}

/******************************************************************************
**
** This is the code that gets called when the processor receives an unexpected
** interrupt.  This simply enters an infinite loop, preserving the system state
** for examination by a debugger.
**
******************************************************************************/
static void
IntDefaultHandler(void)
{
    /*
    ** Go into an infinite loop.
    */
    while(1)
    {
    }
}