#ifndef _SPI_H
#define _SPI_H

#include "defines.h"

extern void SPI_Init(void);
extern uint32_t SPI_Read(void);
extern void SPI_Write(uint8_t Value);
extern void SPI_Error(void);

#endif

