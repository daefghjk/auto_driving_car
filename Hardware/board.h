/*
 * 立创开发板�?�?件资料与相关扩展板软�?件资料官网全部开�?
 * 开发板官网：www.lckfb.com
 * 技�?�?持常驻�?�坛，任何技�?�?题�?�迎随时交流学习
 * 立创论坛：https://oshwhub.com/forum
 * 关注bilibili账号：【立创开发板】，掌握我们的最新动态！
 * 不靠卖板赚钱，以培养�?国工程师为己�?
 * Change Logs:
 * Date           Author       Notes
 * 2024-05-23     LCKFB     first version
 */
#ifndef	__BOARD_H__
#define __BOARD_H__

#include "ti_msp_dl_config.h"


void board_init(void);

void delay_us(unsigned long us);
void delay_ms(unsigned long ms);
void delay_1us(unsigned long __us);
void delay_1ms(unsigned long ms);


#endif
