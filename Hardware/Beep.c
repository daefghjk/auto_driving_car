#include "SYS.h"

void LightAndBeep(void)
{
    DL_GPIO_clearPins(GPIO_Beep_PORT, GPIO_Beep_Beep_PIN);
    DL_GPIO_setPins(GPIO_LED_LIGHT_PORT, GPIO_LED_LIGHT_PIN);
    Delay_ms(100);
    DL_GPIO_setPins(GPIO_Beep_PORT, GPIO_Beep_Beep_PIN);
    DL_GPIO_clearPins(GPIO_LED_LIGHT_PORT, GPIO_LED_LIGHT_PIN);
}