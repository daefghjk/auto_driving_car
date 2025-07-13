#include "SYS.h"                  // Device header

uint16_t Encoder_Left_Count = 0;
uint16_t Encoder_Right_Count = 0;

uint16_t Encoder_Left_Pop(void)
{
	uint16_t temp = Encoder_Left_Count;
	Encoder_Left_Count = 0;
	return temp;
}


uint16_t Encoder_Right_Pop(void)
{
	uint16_t temp = Encoder_Right_Count;
	Encoder_Right_Count = 0;
	return temp;
}



// void GROUP1_IQRHandler(void)//�ⲿ�ж�ִ�к���
// {
//     uint32_t gpioB = DL_GPIO_getEnabledInterruptStatus(GPIO_Grey_PORT,GPIO_Motor_EXTI_M1_exti_PIN|GPIO_Motor_EXTI_M2_exti_PIN);

//     if((gpioB & GPIO_Motor_EXTI_M1_exti_PIN) == GPIO_Motor_EXTI_M1_exti_PIN)//�����ж�
//     {
// 		Encoder_Left_Count ++;
//         DL_GPIO_clearInterruptStatus(GPIO_Grey_PORT, GPIO_Motor_EXTI_M1_exti_PIN);
//     }
//     if((gpioB & GPIO_Motor_EXTI_M2_exti_PIN) == GPIO_Motor_EXTI_M2_exti_PIN)//�ҵ���ж�
//     {
// 		Encoder_Right_Count ++;
//         DL_GPIO_clearInterruptStatus(GPIO_Grey_PORT, GPIO_Motor_EXTI_M2_exti_PIN);
//     }
// }
