#include "SYS.h"

extern uint8_t Mode;//ģʽ

extern float Servo_Angle_TurnMin;//ÿ�α仯�ĽǶ�
extern float Servo_Angle;
extern float Servo_Angle_Init;//����Ƕ�

extern uint8_t Motor_En;//���ʹ��

extern uint16_t Trace_Num_Now;//11111
extern uint16_t Trace_Num_Ago[10];

uint8_t TraceEn = 0; //����ѭ�� 0:�� 1:��
uint8_t KeyPointCount = 0; //�Ѵﵽ�ؼ��������
uint8_t MaxCount = -1; //���ؼ�������
uint8_t KeyPointEn = 0;  //�Ƿ�ʼ�������ߣ�0�ǲ���⣬1�Ǽ��

extern float pitch,roll,yaw;
extern float Yaw_Init;
extern float yaw_Error;
float Yaw_Set = 0;//�趨Ҫ�ߵķ���0��180����
float yaw_Error_Turn = 5.8;

float Angle_BAC_Init = 36.6;//�Խ�ֵac��ʼֵ������38.7
float Angle_BAC = 0;//�Խ�ֵacʵʱֵ
float Angle_BAC_Turn = 1.8;//�Խ�ֵac�ı仯��ÿ�ο�ʼ��Ӧ�����ͼ���
float Angle_BAC_Random[4] = {0,2.8,1.4,0};//

float Angle_ABD_Init = 39.0;//�Խ�ֵbd��ʼֵ������38.7
float Angle_ABD = 0;//�Խ�ֵbdʵʱֵ
float Angle_ABD_Turn = -0.2;//�Խ�ֵac�ı仯��ÿ�ο�ʼ��Ӧ�����ͼ���
float Angle_ABD_Random[4] = {0,0,0.0,0};//

float Servo_MaxAngle = 24;

//ͨ���Ҷȵ�ֵ���жϲ���������ĽǶȣ�
void Situation_Get(void)
{
    if(Motor_En == 0)return;

    KeyPointCheck();
    if (TraceEn)//����Ѳ��
	{
        Sit_Blcak_Move();
	}
    else //��������Ҫ��Ƕ���
    {
        Sit_Write_Move();
    }
	
}

//����־��λ�����ı��־λ
void KeyPointCheck(void)
{
    if(Sit_Blcak_Judge() || Sit_Write_Judge())//����
    {
        LightAndBeep();//����

        KeyPointCount++;//�����ı�־��������һ
        Sit_Stop();//����ͣ��ͣ

        //��λ���붨ʱ����������־�㣩
        Sit_Tim_Circle_Reset();
        
        if(Sit_Blcak_Judge())//�������
        {
            Sit_Blcak_Init();
        }
        else//�������
        {
            Sit_Write_Init();
        }
    }
    
}


//����Ƿ�ﵽ���������־λ������ͣ
void Sit_Stop(void)
{
    if (KeyPointCount >= MaxCount)
    {
        Motor_En = 0;
        TraceEn = 0;
    }
}


/*********************************************************************************/
//�·��ڰ������жϣ���ʼ����Ѳ�ߣ��򵼺���

uint8_t Sit_Blcak_Judge(void)
{
    if (TraceEn == 0) //�ڿհ���
    {
        if (Trace_Num_Now != 0 && Trace_Num_Ago[3] != 0 && Trace_Num_Ago[5] != 0)//�ڿհ�������������
        {
            return 1;
        }
    }
    return 0;
}

uint8_t Sit_Write_Judge(void)
{
    if (TraceEn == 1) //�ں�����
    {
        if (KeyPointEn && Trace_Num_Now == 0 && Trace_Num_Ago[3] == 0 && Trace_Num_Ago[5] == 0) //�ں��������ɼ�⣬������
        {
            return 1;
        }
    }
    return 0;
}


//��������ĳ�ʼ��
void Sit_Blcak_Init(void)
{
    TraceEn = 1;//������,ѭ������
}

//��������ĳ�ʼ��
void Sit_Write_Init(void)
{
    Yaw_Set_Change();//�趨�հ����ĽǶ�

    TraceEn = 0;//������,��ѭ��
}

//����������Ѳ�ߣ�Ҫ��
void Sit_Blcak_Move(void)
{
    if (Trace_Num_Now & 0x01)                  //0000 0001 ����
    {
        Servo_SetAngle(Servo_Angle_Init + Servo_MaxAngle);
        return;
    }
    
    if (Trace_Num_Now & 0x80)                  //1000 0000 ����
    {
        Servo_SetAngle(Servo_Angle_Init - Servo_MaxAngle);
        return;
    }
    if (Trace_Num_Now & 0x02)                  //0000 0010 ��
    {
        Servo_SetAngle(Servo_Angle_Init + Servo_MaxAngle);
        return;
    }

    if (Trace_Num_Now & 0x40)                  //0100 0000 ��
    {
        Servo_SetAngle(Servo_Angle_Init - Servo_MaxAngle);
        return;
    }

    if (Trace_Num_Now & 0x04)                  //0000 0100 ΢��
    {
        Servo_SetAngle(Servo_Angle_Init + 14);
        return;
    }

    if (Trace_Num_Now & 0x20)                  //0010 0000 ΢��
    {
        Servo_SetAngle(Servo_Angle_Init - 14);
        return;
    }

    if (Trace_Num_Now & 0x08)                  //0000 1000 ����
    {
        Servo_SetAngle(Servo_Angle_Init);
        return;
    }

    if (Trace_Num_Now & 0x10)                  //0001 0000 ����
    {
        Servo_SetAngle(Servo_Angle_Init);
        return;
    }
}

//���������������ض��Ƕ�Ҫ��pid���ߣ�
void Sit_Write_Move(void)
{
    float dyaw = Dyaw_Get();//�������󣬸�������
    if(dyaw > 24)dyaw = 24;
    if(dyaw < -24)dyaw = -24;
    Servo_SetAngle(Servo_Angle_Init + dyaw);
}

/*********************************************************************************/
//�·�6050��

//����mpu6050����
void Mpu_Get(void)
{
    while ( mpu_dmp_get_data(&pitch,&roll,&yaw) != 0 );
}

//��ʾƫת��,-180��180,yawset��xx�и���
float Dyaw_Get(void)
{
    float Dyaw =yaw - Yaw_Set;
    if(Dyaw > 180)Dyaw -= 360;
    if(Dyaw < -180)Dyaw += 360;
    return Dyaw;
}

//ͨ��mode��KeyPoint��ֵ�趨�����ǣ��ڰ�����ʼ�������
void Yaw_Set_Change(void)
{
    if(Mode == 0 && KeyPointCount %4 == 0)//ģʽ2��c��
    {
        Yaw_Set = 0;
        yaw_Error -= yaw_Error_Turn;
    }
    if(Mode == 0 && KeyPointCount %4 == 2)//ģʽ2��c��
    {
        Yaw_Set = 180;
        yaw_Error -= yaw_Error_Turn;
    }
    if(Mode == 2 && KeyPointCount == 2)//ģʽ2��c��
    {
        Yaw_Set = 180;
        yaw_Error -= yaw_Error_Turn;
    }
    if(Mode == 3 && KeyPointCount == 0)//ģʽ3��a��
    {
        Yaw_Set = -Angle_BAC;
        yaw_Error -= yaw_Error_Turn;
    }
    if(Mode == 3 && KeyPointCount == 2)//ģʽ3��b��
    {
        Yaw_Set = Angle_ABD - 180;
        yaw_Error += yaw_Error_Turn;
    }
    if(Mode == 4 && KeyPointCount % 4 == 0)//ģʽ4��a��
    {
        Angle_BAC += Angle_BAC_Random[KeyPointCount / 4];//ex:�ڶ�Ȧ��a������ʱ��kpc��4������������1
        Yaw_Set = -Angle_BAC;
        yaw_Error -= yaw_Error_Turn;
    }
    if(Mode == 4 && KeyPointCount % 4 == 2)//ģʽ4��b��
    {
        Angle_ABD += Angle_ABD_Random[KeyPointCount / 4];
        Yaw_Set = Angle_ABD - 180;
        yaw_Error += yaw_Error_Turn;
    }

}

/*********************************************************************************/
//�·�3s������־�� ��ʱ����

void circle_INST_IRQHandler(void)
{
    KeyPointEn = 1;
}

//���붨ʱ��
void Sit_Tim_Circle_Open(void)
{
    KeyPointEn = 0;

    DL_TimerA_setTimerCount(circle_INST, 0);
    NVIC_EnableIRQ(circle_INST_INT_IRQN);
    DL_TimerA_startCounter(circle_INST);
}

//���붨ʱ���ر�
void Sit_Tim_Circle_Close(void)
{
    KeyPointEn = 1;

    DL_TimerA_stopCounter(circle_INST);
    NVIC_DisableIRQ(circle_INST_INT_IRQN);
    DL_TimerA_setTimerCount(circle_INST, 0);
}

void Sit_Tim_Circle_Reset(void)
{
    Sit_Tim_Circle_Close();
    Sit_Tim_Circle_Open();
}