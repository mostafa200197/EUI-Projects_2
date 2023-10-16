#include "main.h"

uint8_t main(void)
{
    Configure_Clock(16U, RCC_USE_PWM|RCC_PWMDIV_64);
    RC_CAR();
    return 1U;
}
