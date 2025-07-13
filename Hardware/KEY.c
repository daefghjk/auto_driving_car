#include "ti_msp_dl_config.h"
#include "Delay.h"

// /* Defines for PIN_KEY_S2: GPIOB.21 with pinCMx 49 on package pin 20 */
// #define GPIO_KEY_PIN_KEY_S2_PORT                                         (GPIOB)
// #define GPIO_KEY_PIN_KEY_S2_PIN                                 (DL_GPIO_PIN_21)
// #define GPIO_KEY_PIN_KEY_S2_IOMUX                                (IOMUX_PINCM49)


// /* Defines for PIN_Key_K1: GPIOA.15 with pinCMx 37 on package pin 8 */
// #define GPIO_KEY_PIN_Key_K1_PORT                                         (GPIOA)
// #define GPIO_KEY_PIN_Key_K1_PIN                                 (DL_GPIO_PIN_15)
// #define GPIO_KEY_PIN_Key_K1_IOMUX                                (IOMUX_PINCM37)

// /* Defines for PIN_Key_K2: GPIOA.17 with pinCMx 39 on package pin 10 */
// #define GPIO_KEY_PIN_Key_K2_PORT                                         (GPIOA)
// #define GPIO_KEY_PIN_Key_K2_PIN                                 (DL_GPIO_PIN_17)
// #define GPIO_KEY_PIN_Key_K2_IOMUX                                (IOMUX_PINCM39)

// /* Defines for PIN_Key_K3: GPIOA.24 with pinCMx 54 on package pin 25 */
// #define GPIO_KEY_PIN_Key_K3_PORT                                         (GPIOA)
// #define GPIO_KEY_PIN_Key_K3_PIN                                 (DL_GPIO_PIN_24)
// #define GPIO_KEY_PIN_Key_K3_IOMUX                                (IOMUX_PINCM54)

// /* Defines for PIN_Key_K4: GPIOB.18 with pinCMx 44 on package pin 15 */
// #define GPIO_KEY_PIN_Key_K4_PORT                                         (GPIOB)
// #define GPIO_KEY_PIN_Key_K4_PIN                                 (DL_GPIO_PIN_18)
// #define GPIO_KEY_PIN_Key_K4_IOMUX                                (IOMUX_PINCM44)

uint8_t Key_GetNum(void)//k1234为小车内容，s2为开发板上按键
{
	uint8_t KeyNum = 0;
	if (DL_GPIO_readPins(GPIO_KEY_PIN_Key_K1_PORT,GPIO_KEY_PIN_Key_K1_PIN) == 0)
	{
		Delay_ms(20);
		while(DL_GPIO_readPins(GPIO_KEY_PIN_Key_K1_PORT,GPIO_KEY_PIN_Key_K1_PIN) == 0);
		Delay_ms(20);
		KeyNum = 1;
		
	}
	if (DL_GPIO_readPins(GPIO_KEY_PIN_Key_K2_PORT,GPIO_KEY_PIN_Key_K2_PIN) == 0)
	{
		Delay_ms(20);
		while(DL_GPIO_readPins(GPIO_KEY_PIN_Key_K2_PORT,GPIO_KEY_PIN_Key_K2_PIN) == 0);
		Delay_ms(20);
		KeyNum = 2;
		
	}
	if (DL_GPIO_readPins(GPIO_KEY_PIN_Key_K3_PORT,GPIO_KEY_PIN_Key_K3_PIN) == 0)
	{
		Delay_ms(20);
		while(DL_GPIO_readPins(GPIO_KEY_PIN_Key_K3_PORT,GPIO_KEY_PIN_Key_K3_PIN) == 0);
		Delay_ms(20);
		KeyNum = 3;
		
	}
	if (DL_GPIO_readPins(GPIO_KEY_PIN_Key_K4_PORT,GPIO_KEY_PIN_Key_K4_PIN) == 0)
	{
		Delay_ms(20);
		while(DL_GPIO_readPins(GPIO_KEY_PIN_Key_K4_PORT,GPIO_KEY_PIN_Key_K4_PIN) == 0);
		Delay_ms(20);
		KeyNum = 4;
		
	}

	if (DL_GPIO_readPins(GPIO_KEY_PIN_KEY_S2_PORT,GPIO_KEY_PIN_KEY_S2_PIN) == 0)
	{
		Delay_ms(20);
		while(DL_GPIO_readPins(GPIO_KEY_PIN_KEY_S2_PORT,GPIO_KEY_PIN_KEY_S2_PIN) == 0);
		Delay_ms(20);
		KeyNum = 5;
		
	}
	
	return KeyNum;
}
