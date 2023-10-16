#include <MCAL/System_Control_Drivers/System_Control.h>

void Configure_Clock(uint8_t Clock_Freq, uint32_t PWM_Config)
{
    SYSCTL->RCC &= ~((uint32_t) 1UL << 22); /* Clear USESYSDIV bit */
    SYSCTL->RCC &= ~((uint32_t) 0xFUL << 6); /* Clear XTAL bits */
    SYSCTL->RCC |= ((uint32_t) 0x15UL << 6); /* XTAL 16 MHz */
    SYSCTL->RCC &= ~((uint32_t) 1UL << 0); /* Enable MOSC */
    while ((SYSCTL->RIS & ((uint32_t) 1U << 8)) == 0U)
    {
    } /* Wait for MOSC to stabilize */
    SYSCTL->MISC |= ((uint32_t) 1UL << 8); /* Clear flag */
    SYSCTL->RCC2 |= ((uint32_t) 1UL << 31); /* Set USERCC2 bit */
    SYSCTL->RCC2 |= ((uint32_t) 1UL << 11); /* Set BYPASS2 bit */
    SYSCTL->RCC2 &= ~((uint32_t) 3UL << 4); /* Use MOSC as source */
    SYSCTL->RCC2 &= ~((uint32_t) 0x3FUL << 23); /* Clear SYSDIV2 bits */
    SYSCTL->RCC2 |= ((uint32_t) 1UL << 30); /* PLL 400 MHz */
    SYSCTL->RCC2 &= ~((uint32_t) 1UL << 13); /* Power up PLL */
    uint32_t divisor = 400U / Clock_Freq; /* Calculate divisor */
    while ((divisor < 3U) || (divisor > 128U))
    {
    } /* If divisor less than 3 or larger then 128 then infinite loop */
    SYSCTL->RCC2 |= ((uint32_t) ((divisor - 1UL) / 2UL) << 23); /* Set divisor in SYSDIV2 */
    SYSCTL->RCC2 &= ~((uint32_t) 1U << 22); /* Clear SYSDIV2LSB */
    SYSCTL->RCC2 |= ((uint32_t) ((divisor ^ 0x01UL) & 0x1UL) << 22); /* Set SYSDIV2LSB if divisor is even */
    SYSCTL->RCC |= ((uint32_t) 1UL << 22); /* Set USESYSDIV bit */
    while ((SYSCTL->RIS & ((uint32_t)1UL << 6)) == 0U)
    {
    } /* Wait for PLL to stabilize */
    SYSCTL->MISC |= ((uint32_t) 1UL << 6); /* Clear flag */
    SYSCTL->RCC2 &= ~((uint32_t) 1UL << 11); /* Clear BYPASS2 bit */
    if ((PWM_Config & RCC_USE_PWM) == RCC_USE_PWM)
    {
        SYSCTL->RCC |= RCC_USE_PWM;
        SYSCTL->RCC &= ~((uint32_t)RCC_PWMDIV_64);
        SYSCTL->RCC |= (PWM_Config & (~((uint32_t)RCC_USE_PWM)));
    }
    else
    {
    }
}

void Enable_Peripheral_Clock(uint32_t Peripheral)
{
    (*((volatile uint32_t*) (SYSCTL_BASE_ADDRESS + RCGC_OFFSET_START
            + ((Peripheral & 0xFFFFUL) >> 8U)))) |= ((uint32_t) 1U
            << (0xFFUL & Peripheral)); /* Enable Peripheral clock */
    while (((*((volatile uint32_t*) (SYSCTL_BASE_ADDRESS + PR_OFFSET_START
            + ((Peripheral & 0xFFFFUL) >> 8U)))) |= ((uint32_t) 1U
            << (0xFFUL & Peripheral))) == 0U)
    {
    } /* Wait for Peripheral clock */
}
