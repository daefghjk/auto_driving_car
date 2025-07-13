#include "SYS.h"

extern uint16_t Trace_Num_Now;//11111
extern uint16_t Trace_Num_Ago[10];//11111
	
// /* Port definition for Pin Group GPIO_Grey */
// #define GPIO_Grey_PORT                                                   (GPIOB)

// /* Defines for PIN_Grey_0: GPIOB.8 with pinCMx 25 on package pin 60 */
// #define GPIO_Grey_PIN_Grey_0_PIN                                 (DL_GPIO_PIN_8)
// #define GPIO_Grey_PIN_Grey_0_IOMUX                               (IOMUX_PINCM25)
// /* Defines for PIN_Grey_1: GPIOB.7 with pinCMx 24 on package pin 59 */
// #define GPIO_Grey_PIN_Grey_1_PIN                                 (DL_GPIO_PIN_7)
// #define GPIO_Grey_PIN_Grey_1_IOMUX                               (IOMUX_PINCM24)
// /* Defines for PIN_Grey_2: GPIOB.6 with pinCMx 23 on package pin 58 */
// #define GPIO_Grey_PIN_Grey_2_PIN                                 (DL_GPIO_PIN_6)
// #define GPIO_Grey_PIN_Grey_2_IOMUX                               (IOMUX_PINCM23)
// /* Defines for PIN_Grey_3: GPIOB.0 with pinCMx 12 on package pin 47 */
// #define GPIO_Grey_PIN_Grey_3_PIN                                 (DL_GPIO_PIN_0)
// #define GPIO_Grey_PIN_Grey_3_IOMUX                               (IOMUX_PINCM12)
// /* Defines for PIN_Grey_4: GPIOB.16 with pinCMx 33 on package pin 4 */
// #define GPIO_Grey_PIN_Grey_4_PIN                                (DL_GPIO_PIN_16)
// #define GPIO_Grey_PIN_Grey_4_IOMUX                               (IOMUX_PINCM33)


//输出五位数，亮灯白色0，不亮黑色1
uint16_t Trace_Get(void)
{
	for(int i = 9; i != 0; i--)
	{
		Trace_Num_Ago[i] = Trace_Num_Ago[i - 1];
	}
	
	Trace_Num_Ago[0] = Trace_Num_Now;
	
	
	Trace_Num_Now = 0;
	Trace_Num_Now |= ((!DL_GPIO_readPins(GPIO_Grey_PIN_Grey_0_PORT, GPIO_Grey_PIN_Grey_0_PIN)) << 7);
	Trace_Num_Now |= ((!DL_GPIO_readPins(GPIO_Grey_PIN_Grey_1_PORT, GPIO_Grey_PIN_Grey_1_PIN)) << 6);
	Trace_Num_Now |= ((!DL_GPIO_readPins(GPIO_Grey_PIN_Grey_2_PORT, GPIO_Grey_PIN_Grey_2_PIN)) << 5);
	Trace_Num_Now |= ((!DL_GPIO_readPins(GPIO_Grey_PIN_Grey_3_PORT, GPIO_Grey_PIN_Grey_3_PIN)) << 4);
	Trace_Num_Now |= ((!DL_GPIO_readPins(GPIO_Grey_PIN_Grey_4_PORT, GPIO_Grey_PIN_Grey_4_PIN)) << 3);
    Trace_Num_Now |= ((!DL_GPIO_readPins(GPIO_Grey_PIN_Grey_5_PORT, GPIO_Grey_PIN_Grey_5_PIN)) << 2);
    Trace_Num_Now |= ((!DL_GPIO_readPins(GPIO_Grey_PIN_Grey_6_PORT, GPIO_Grey_PIN_Grey_6_PIN)) << 1);
    Trace_Num_Now |= ((!DL_GPIO_readPins(GPIO_Grey_PIN_Grey_7_PORT, GPIO_Grey_PIN_Grey_7_PIN)) << 0);
	
	return Trace_Num_Now;	//输出五位数，亮灯白色0，不亮黑色1
}
