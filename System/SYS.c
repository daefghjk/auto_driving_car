#include "SYS.h"


uint8_t Mode = 0;//模式
uint8_t Mode_Set = 1;//模式

uint8_t Mpu_En = 0;
float Yaw_Init;
float pitch=0,roll=0,yaw=0;

float Servo_Angle_TurnMin = 0.4;//每次变化的角度
float Servo_Angle_Init = 87.5;//舵机角度
float Servo_Angle = 0;//舵机角度

float Motor_Speed = 0;//速度
float Motor_Set = 60;//强制设定速度，不设定（-1）即为pid模式
uint8_t Motor_En = 0;//电机使能

//灰度传感器数据
uint16_t Trace_Num_Now = 31;//11111
uint16_t Trace_Num_Ago[10] = {31};


void System_Init(void)
{
    SYSCFG_DL_init();

    //10ms定时中断
    NVIC_EnableIRQ(ctrl_INST_INT_IRQN);
    DL_TimerG_startCounter(ctrl_INST);

    // //500ms定时中断
    // NVIC_EnableIRQ(ctrl_Encoder_INST_INT_IRQN);
    // DL_TimerG_startCounter(ctrl_Encoder_INST);


    OLED_Init();
    // UART_Init(UART0);
    Menu_Init();
    Servo_SetAngle(Servo_Angle_Init);
/*
    //6050初始化
    {
        //初始化
        board_init();
        Servo_SetAngle(Servo_Angle_Init);
        MPU6050_Init();

        //这句记得删
        // Servo_SetAngle(70);


        OLED_ShowString(2, 1, "DMP loading...");
        while( mpu_dmp_init() )
        {
            delay_ms(200);
        }

        //读数据
        while ( mpu_dmp_get_data(&pitch,&roll,&yaw) != 0 );//读不到就卡在这/
        Yaw_Init = yaw ;
        Mpu_En = 1;
        OLED_ShowString(2, 1, "                  ");
        OLED_ShowString(2, 1, "DMP OK");
        delay_ms(500);
        OLED_ShowString(2, 1, "                  ");
    }
*/
}