#ifndef _CLOCK_H
#define _CLOCK_H

#include "defines.h"

/* Time-out values */
#define HSI_TIMEOUT_VALUE          ((uint32_t)100)  /* 100 ms */
#define PLL_TIMEOUT_VALUE          ((uint32_t)100)  /* 100 ms */
#define CLOCKSWITCH_TIMEOUT_VALUE  ((uint32_t)5000) /* 5 s    */

#define ERROR_NONE        0x00

#define ERROR_HSI_TIMEOUT 0x04
#define ERROR_PLL_TIMEOUT 0x05
#define ERROR_CLKSWITCH_TIMEOUT 0x06

#endif
