#ifndef __DELAY_H
#define __DELAY_H

#include "stm32f4xx.h"

void delayms(__IO uint32_t nTime);
void TimingDelay_Decrement(void);
void delayInit(void);
#endif
