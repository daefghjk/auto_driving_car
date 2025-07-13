/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G350X
#define CONFIG_MSPM0G3507

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)


#define CPUCLK_FREQ                                                     32000000



/* Defines for PWM_Motor */
#define PWM_Motor_INST                                                     TIMG7
#define PWM_Motor_INST_IRQHandler                               TIMG7_IRQHandler
#define PWM_Motor_INST_INT_IRQN                                 (TIMG7_INT_IRQn)
#define PWM_Motor_INST_CLK_FREQ                                         32000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_Motor_C0_PORT                                             GPIOA
#define GPIO_PWM_Motor_C0_PIN                                     DL_GPIO_PIN_28
#define GPIO_PWM_Motor_C0_IOMUX                                   (IOMUX_PINCM3)
#define GPIO_PWM_Motor_C0_IOMUX_FUNC                  IOMUX_PINCM3_PF_TIMG7_CCP0
#define GPIO_PWM_Motor_C0_IDX                                DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_Motor_C1_PORT                                             GPIOA
#define GPIO_PWM_Motor_C1_PIN                                     DL_GPIO_PIN_31
#define GPIO_PWM_Motor_C1_IOMUX                                   (IOMUX_PINCM6)
#define GPIO_PWM_Motor_C1_IOMUX_FUNC                  IOMUX_PINCM6_PF_TIMG7_CCP1
#define GPIO_PWM_Motor_C1_IDX                                DL_TIMER_CC_1_INDEX

/* Defines for PWM_Servo */
#define PWM_Servo_INST                                                     TIMA1
#define PWM_Servo_INST_IRQHandler                               TIMA1_IRQHandler
#define PWM_Servo_INST_INT_IRQN                                 (TIMA1_INT_IRQn)
#define PWM_Servo_INST_CLK_FREQ                                          1000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_Servo_C0_PORT                                             GPIOB
#define GPIO_PWM_Servo_C0_PIN                                      DL_GPIO_PIN_4
#define GPIO_PWM_Servo_C0_IOMUX                                  (IOMUX_PINCM17)
#define GPIO_PWM_Servo_C0_IOMUX_FUNC                 IOMUX_PINCM17_PF_TIMA1_CCP0
#define GPIO_PWM_Servo_C0_IDX                                DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_Servo_C1_PORT                                             GPIOB
#define GPIO_PWM_Servo_C1_PIN                                      DL_GPIO_PIN_1
#define GPIO_PWM_Servo_C1_IOMUX                                  (IOMUX_PINCM13)
#define GPIO_PWM_Servo_C1_IOMUX_FUNC                 IOMUX_PINCM13_PF_TIMA1_CCP1
#define GPIO_PWM_Servo_C1_IDX                                DL_TIMER_CC_1_INDEX



/* Defines for ctrl */
#define ctrl_INST                                                        (TIMG6)
#define ctrl_INST_IRQHandler                                    TIMG6_IRQHandler
#define ctrl_INST_INT_IRQN                                      (TIMG6_INT_IRQn)
#define ctrl_INST_LOAD_VALUE                                             (9999U)
/* Defines for circle */
#define circle_INST                                                      (TIMA0)
#define circle_INST_IRQHandler                                  TIMA0_IRQHandler
#define circle_INST_INT_IRQN                                    (TIMA0_INT_IRQn)
#define circle_INST_LOAD_VALUE                                          (46874U)




/* Defines for I2C_MPU6050 */
#define I2C_MPU6050_INST                                                    I2C1
#define I2C_MPU6050_INST_IRQHandler                              I2C1_IRQHandler
#define I2C_MPU6050_INST_INT_IRQN                                  I2C1_INT_IRQn
#define I2C_MPU6050_BUS_SPEED_HZ                                          100000
#define GPIO_I2C_MPU6050_SDA_PORT                                          GPIOB
#define GPIO_I2C_MPU6050_SDA_PIN                                   DL_GPIO_PIN_3
#define GPIO_I2C_MPU6050_IOMUX_SDA                               (IOMUX_PINCM16)
#define GPIO_I2C_MPU6050_IOMUX_SDA_FUNC                IOMUX_PINCM16_PF_I2C1_SDA
#define GPIO_I2C_MPU6050_SCL_PORT                                          GPIOB
#define GPIO_I2C_MPU6050_SCL_PIN                                   DL_GPIO_PIN_2
#define GPIO_I2C_MPU6050_IOMUX_SCL                               (IOMUX_PINCM15)
#define GPIO_I2C_MPU6050_IOMUX_SCL_FUNC                IOMUX_PINCM15_PF_I2C1_SCL



/* Port definition for Pin Group GPIO_Beep */
#define GPIO_Beep_PORT                                                   (GPIOA)

/* Defines for Beep: GPIOA.12 with pinCMx 34 on package pin 5 */
#define GPIO_Beep_Beep_PIN                                      (DL_GPIO_PIN_12)
#define GPIO_Beep_Beep_IOMUX                                     (IOMUX_PINCM34)
/* Defines for PIN_LED_1: GPIOB.22 with pinCMx 50 on package pin 21 */
#define GPIO_LED_PIN_LED_1_PORT                                          (GPIOB)
#define GPIO_LED_PIN_LED_1_PIN                                  (DL_GPIO_PIN_22)
#define GPIO_LED_PIN_LED_1_IOMUX                                 (IOMUX_PINCM50)
/* Defines for PIN_LED_2: GPIOB.26 with pinCMx 57 on package pin 28 */
#define GPIO_LED_PIN_LED_2_PORT                                          (GPIOB)
#define GPIO_LED_PIN_LED_2_PIN                                  (DL_GPIO_PIN_26)
#define GPIO_LED_PIN_LED_2_IOMUX                                 (IOMUX_PINCM57)
/* Defines for PIN_LED_3: GPIOB.27 with pinCMx 58 on package pin 29 */
#define GPIO_LED_PIN_LED_3_PORT                                          (GPIOB)
#define GPIO_LED_PIN_LED_3_PIN                                  (DL_GPIO_PIN_27)
#define GPIO_LED_PIN_LED_3_IOMUX                                 (IOMUX_PINCM58)
/* Defines for LIGHT: GPIOA.13 with pinCMx 35 on package pin 6 */
#define GPIO_LED_LIGHT_PORT                                              (GPIOA)
#define GPIO_LED_LIGHT_PIN                                      (DL_GPIO_PIN_13)
#define GPIO_LED_LIGHT_IOMUX                                     (IOMUX_PINCM35)
/* Defines for PIN_KEY_S2: GPIOB.21 with pinCMx 49 on package pin 20 */
#define GPIO_KEY_PIN_KEY_S2_PORT                                         (GPIOB)
#define GPIO_KEY_PIN_KEY_S2_PIN                                 (DL_GPIO_PIN_21)
#define GPIO_KEY_PIN_KEY_S2_IOMUX                                (IOMUX_PINCM49)
/* Defines for PIN_Key_K1: GPIOA.15 with pinCMx 37 on package pin 8 */
#define GPIO_KEY_PIN_Key_K1_PORT                                         (GPIOA)
#define GPIO_KEY_PIN_Key_K1_PIN                                 (DL_GPIO_PIN_15)
#define GPIO_KEY_PIN_Key_K1_IOMUX                                (IOMUX_PINCM37)
/* Defines for PIN_Key_K2: GPIOA.17 with pinCMx 39 on package pin 10 */
#define GPIO_KEY_PIN_Key_K2_PORT                                         (GPIOA)
#define GPIO_KEY_PIN_Key_K2_PIN                                 (DL_GPIO_PIN_17)
#define GPIO_KEY_PIN_Key_K2_IOMUX                                (IOMUX_PINCM39)
/* Defines for PIN_Key_K3: GPIOA.24 with pinCMx 54 on package pin 25 */
#define GPIO_KEY_PIN_Key_K3_PORT                                         (GPIOA)
#define GPIO_KEY_PIN_Key_K3_PIN                                 (DL_GPIO_PIN_24)
#define GPIO_KEY_PIN_Key_K3_IOMUX                                (IOMUX_PINCM54)
/* Defines for PIN_Key_K4: GPIOB.18 with pinCMx 44 on package pin 15 */
#define GPIO_KEY_PIN_Key_K4_PORT                                         (GPIOB)
#define GPIO_KEY_PIN_Key_K4_PIN                                 (DL_GPIO_PIN_18)
#define GPIO_KEY_PIN_Key_K4_IOMUX                                (IOMUX_PINCM44)
/* Port definition for Pin Group GPIO_Motor_EXTI */
#define GPIO_Motor_EXTI_PORT                                             (GPIOB)

/* Defines for M1_exti: GPIOB.20 with pinCMx 48 on package pin 19 */
// pins affected by this interrupt request:["M1_exti","M2_exti"]
#define GPIO_Motor_EXTI_INT_IRQN                                (GPIOB_INT_IRQn)
#define GPIO_Motor_EXTI_INT_IIDX                (DL_INTERRUPT_GROUP1_IIDX_GPIOB)
#define GPIO_Motor_EXTI_M1_exti_IIDX                        (DL_GPIO_IIDX_DIO20)
#define GPIO_Motor_EXTI_M1_exti_PIN                             (DL_GPIO_PIN_20)
#define GPIO_Motor_EXTI_M1_exti_IOMUX                            (IOMUX_PINCM48)
/* Defines for M2_exti: GPIOB.13 with pinCMx 30 on package pin 1 */
#define GPIO_Motor_EXTI_M2_exti_IIDX                        (DL_GPIO_IIDX_DIO13)
#define GPIO_Motor_EXTI_M2_exti_PIN                             (DL_GPIO_PIN_13)
#define GPIO_Motor_EXTI_M2_exti_IOMUX                            (IOMUX_PINCM30)
/* Defines for PIN_Grey_0: GPIOB.16 with pinCMx 33 on package pin 4 */
#define GPIO_Grey_PIN_Grey_0_PORT                                        (GPIOB)
#define GPIO_Grey_PIN_Grey_0_PIN                                (DL_GPIO_PIN_16)
#define GPIO_Grey_PIN_Grey_0_IOMUX                               (IOMUX_PINCM33)
/* Defines for PIN_Grey_1: GPIOB.0 with pinCMx 12 on package pin 47 */
#define GPIO_Grey_PIN_Grey_1_PORT                                        (GPIOB)
#define GPIO_Grey_PIN_Grey_1_PIN                                 (DL_GPIO_PIN_0)
#define GPIO_Grey_PIN_Grey_1_IOMUX                               (IOMUX_PINCM12)
/* Defines for PIN_Grey_2: GPIOB.6 with pinCMx 23 on package pin 58 */
#define GPIO_Grey_PIN_Grey_2_PORT                                        (GPIOB)
#define GPIO_Grey_PIN_Grey_2_PIN                                 (DL_GPIO_PIN_6)
#define GPIO_Grey_PIN_Grey_2_IOMUX                               (IOMUX_PINCM23)
/* Defines for PIN_Grey_3: GPIOB.7 with pinCMx 24 on package pin 59 */
#define GPIO_Grey_PIN_Grey_3_PORT                                        (GPIOB)
#define GPIO_Grey_PIN_Grey_3_PIN                                 (DL_GPIO_PIN_7)
#define GPIO_Grey_PIN_Grey_3_IOMUX                               (IOMUX_PINCM24)
/* Defines for PIN_Grey_4: GPIOB.8 with pinCMx 25 on package pin 60 */
#define GPIO_Grey_PIN_Grey_4_PORT                                        (GPIOB)
#define GPIO_Grey_PIN_Grey_4_PIN                                 (DL_GPIO_PIN_8)
#define GPIO_Grey_PIN_Grey_4_IOMUX                               (IOMUX_PINCM25)
/* Defines for PIN_Grey_5: GPIOB.19 with pinCMx 45 on package pin 16 */
#define GPIO_Grey_PIN_Grey_5_PORT                                        (GPIOB)
#define GPIO_Grey_PIN_Grey_5_PIN                                (DL_GPIO_PIN_19)
#define GPIO_Grey_PIN_Grey_5_IOMUX                               (IOMUX_PINCM45)
/* Defines for PIN_Grey_6: GPIOA.16 with pinCMx 38 on package pin 9 */
#define GPIO_Grey_PIN_Grey_6_PORT                                        (GPIOA)
#define GPIO_Grey_PIN_Grey_6_PIN                                (DL_GPIO_PIN_16)
#define GPIO_Grey_PIN_Grey_6_IOMUX                               (IOMUX_PINCM38)
/* Defines for PIN_Grey_7: GPIOB.12 with pinCMx 29 on package pin 64 */
#define GPIO_Grey_PIN_Grey_7_PORT                                        (GPIOB)
#define GPIO_Grey_PIN_Grey_7_PIN                                (DL_GPIO_PIN_12)
#define GPIO_Grey_PIN_Grey_7_IOMUX                               (IOMUX_PINCM29)
/* Port definition for Pin Group GPIO_Encoder */
#define GPIO_Encoder_PORT                                                (GPIOB)

/* Defines for PIN_Encoder1: GPIOB.15 with pinCMx 32 on package pin 3 */
#define GPIO_Encoder_PIN_Encoder1_PIN                           (DL_GPIO_PIN_15)
#define GPIO_Encoder_PIN_Encoder1_IOMUX                          (IOMUX_PINCM32)
/* Defines for PIN_Encoder2: GPIOB.17 with pinCMx 43 on package pin 14 */
#define GPIO_Encoder_PIN_Encoder2_PIN                           (DL_GPIO_PIN_17)
#define GPIO_Encoder_PIN_Encoder2_IOMUX                          (IOMUX_PINCM43)
/* Defines for PIN_Motor1_1: GPIOA.8 with pinCMx 19 on package pin 54 */
#define GPIO_Motor_PIN_Motor1_1_PORT                                     (GPIOA)
#define GPIO_Motor_PIN_Motor1_1_PIN                              (DL_GPIO_PIN_8)
#define GPIO_Motor_PIN_Motor1_1_IOMUX                            (IOMUX_PINCM19)
/* Defines for PIN_Motor1_2: GPIOA.26 with pinCMx 59 on package pin 30 */
#define GPIO_Motor_PIN_Motor1_2_PORT                                     (GPIOA)
#define GPIO_Motor_PIN_Motor1_2_PIN                             (DL_GPIO_PIN_26)
#define GPIO_Motor_PIN_Motor1_2_IOMUX                            (IOMUX_PINCM59)
/* Defines for PIN_Motor2_1: GPIOB.24 with pinCMx 52 on package pin 23 */
#define GPIO_Motor_PIN_Motor2_1_PORT                                     (GPIOB)
#define GPIO_Motor_PIN_Motor2_1_PIN                             (DL_GPIO_PIN_24)
#define GPIO_Motor_PIN_Motor2_1_IOMUX                            (IOMUX_PINCM52)
/* Defines for PIN_Motor2_2: GPIOB.9 with pinCMx 26 on package pin 61 */
#define GPIO_Motor_PIN_Motor2_2_PORT                                     (GPIOB)
#define GPIO_Motor_PIN_Motor2_2_PIN                              (DL_GPIO_PIN_9)
#define GPIO_Motor_PIN_Motor2_2_IOMUX                            (IOMUX_PINCM26)
/* Port definition for Pin Group GPIO_OLED */
#define GPIO_OLED_PORT                                                   (GPIOA)

/* Defines for OLED_SDA: GPIOA.25 with pinCMx 55 on package pin 26 */
#define GPIO_OLED_OLED_SDA_PIN                                  (DL_GPIO_PIN_25)
#define GPIO_OLED_OLED_SDA_IOMUX                                 (IOMUX_PINCM55)
/* Defines for OLED_SCL: GPIOA.9 with pinCMx 20 on package pin 55 */
#define GPIO_OLED_OLED_SCL_PIN                                   (DL_GPIO_PIN_9)
#define GPIO_OLED_OLED_SCL_IOMUX                                 (IOMUX_PINCM20)

/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_PWM_Motor_init(void);
void SYSCFG_DL_PWM_Servo_init(void);
void SYSCFG_DL_ctrl_init(void);
void SYSCFG_DL_circle_init(void);
void SYSCFG_DL_I2C_MPU6050_init(void);


bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
