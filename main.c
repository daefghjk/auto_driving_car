#include "SYS.h"
//�Ѿ����Է����ˮƽ��ƽ�����ģʽ���ܶ�һ�Ρ��´�д��תpidʹ֮˳�����߲�����

extern uint8_t Mpu_En;
extern float yaw;
extern float Dyaw;
extern float Yaw_Init;
extern uint16_t Trace_Num_Now;

int main(void)
{ 
    System_Init();
    while(1)
    {
        //��ⰴ������±���
        Menu_Show();

        //����6050��yawΪȫ�ֱ���
        if(Mpu_En)
        {
            Mpu_Get();
        }
    }
}