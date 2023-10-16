#include <UTILS/Delay.h>

#ifdef Hardware_Delay

/* Delay in milliseconds */

void Delay_ms(uint32_t delay)
{
    NVIC->STRELEAD = (delay * Freq_Factor_Milli) - 1U;
    NVIC->STCURRENT = 0xFFU;
    NVIC->STCTRL = 0x01U;
    while ((NVIC->STCTRL & ((uint32_t) 1 << 16U)) == 0U)
    {
    }
    NVIC->STCURRENT = 0xFFU;
    NVIC->STCTRL = 0U;
}

/* Delay in microseconds */

void Delay_us(uint32_t delay)
{
    NVIC->STRELEAD = (delay * Freq_Factor_Micro) - 1U;
    NVIC->STCURRENT = 0xFFU;
    NVIC->STCTRL = 0x01U;
    while ((NVIC->STCTRL & ((uint32_t) 1 << 16U)) == 0U)
    {
    }
    NVIC->STCURRENT = 0xFFU;
    NVIC->STCTRL = 0U;
}

#endif

#ifdef Software_Delay

/* Delay in millisecond */

void Delay_ms(uint32_t delay)
{
    delay *= 762UL;
    uint32_t ms_Index;
    for(ms_Index = delay; ms_Index > 0UL; ms_Index--)
    {
    }
}

/* Delay in microsecond not accurate */

void Delay_us(uint32_t delay)
{
    uint32_t us_Index;
    for(us_Index = delay; us_Index > 0UL; us_Index--)
    {
    }
}

#endif
