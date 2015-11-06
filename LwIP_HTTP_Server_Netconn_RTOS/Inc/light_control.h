#ifndef __LIGHTCONTROL_H
#define __LIGHTCONTROL_H
#include "stm32f7xx.h"                  // Device header
#include "stm32746g_discovery.h"        // Keil.STM32F746G-Discovery::Board Support:Drivers:Basic I/O
#include "stm32f7xx_hal.h"


void send_Message_Bin(short add[8], short data[8]);
void thread_control(void const * argument);

#endif