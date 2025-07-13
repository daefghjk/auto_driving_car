#include "SYS.h"
//已经可以封箱的水平，平均五次模式四跑丢一次。下次写旋转pid使之顺滑出线不抖动

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
        //检测按键与更新变量
        Menu_Show();

        //更新6050，yaw为全局变量
        if(Mpu_En)
        {
            Mpu_Get();
        }
    }
}