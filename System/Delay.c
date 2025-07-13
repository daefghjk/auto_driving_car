#include "ti_msp_dl_config.h"
#include "Delay.h"

void Delay_s(int s)
{
    while (s--)
        delay_cycles(CPUCLK_FREQ);
}

void Delay_ms(int ms)
{
    while (ms--)
        delay_cycles(CPUCLK_FREQ / 1000);
}

void Delay_us(int us)
{
    while (us--)
        delay_cycles(CPUCLK_FREQ / 1000000);
}
