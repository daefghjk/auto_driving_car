#include "SYS.h"


uint8_t Mode = 0;//ģʽ
uint8_t Mode_Set = 1;//ģʽ

uint8_t Mpu_En = 0;
float Yaw_Init;
float pitch=0,roll=0,yaw=0;

float Servo_Angle_TurnMin = 0.4;//ÿ�α仯�ĽǶ�
float Servo_Angle_Init = 87.5;//����Ƕ�
float Servo_Angle = 0;//����Ƕ�

float Motor_Speed = 0;//�ٶ�
float Motor_Set = 60;//ǿ���趨�ٶȣ����趨��-1����Ϊpidģʽ
uint8_t Motor_En = 0;//���ʹ��

//�Ҷȴ���������
uint16_t Trace_Num_Now = 31;//11111
uint16_t Trace_Num_Ago[10] = {31};


void System_Init(void)
{
    SYSCFG_DL_init();

    //10ms��ʱ�ж�
    NVIC_EnableIRQ(ctrl_INST_INT_IRQN);
    DL_TimerG_startCounter(ctrl_INST);

    // //500ms��ʱ�ж�
    // NVIC_EnableIRQ(ctrl_Encoder_INST_INT_IRQN);
    // DL_TimerG_startCounter(ctrl_Encoder_INST);


    OLED_Init();
    // UART_Init(UART0);
    Menu_Init();
    Servo_SetAngle(Servo_Angle_Init);
/*
    //6050��ʼ��
    {
        //��ʼ��
        board_init();
        Servo_SetAngle(Servo_Angle_Init);
        MPU6050_Init();

        //���ǵ�ɾ
        // Servo_SetAngle(70);


        OLED_ShowString(2, 1, "DMP loading...");
        while( mpu_dmp_init() )
        {
            delay_ms(200);
        }

        //������
        while ( mpu_dmp_get_data(&pitch,&roll,&yaw) != 0 );//�������Ϳ�����/
        Yaw_Init = yaw ;
        Mpu_En = 1;
        OLED_ShowString(2, 1, "                  ");
        OLED_ShowString(2, 1, "DMP OK");
        delay_ms(500);
        OLED_ShowString(2, 1, "                  ");
    }
*/
}