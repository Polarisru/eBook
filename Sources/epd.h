#ifndef _EPD_H
#define _EPD_H

#include "stm32l053xx.h"

/*################################ EPD #######################################*/ 
/**
  * @brief  EPD Control pin
  */
#define EPD_CS_PIN                              GPIO_PIN_15
#define EPD_CS_GPIO_PORT                        GPIOA
#define EPD_CS_GPIO_CLK_ENABLE()                __GPIOA_CLK_ENABLE()
#define EPD_CS_GPIO_CLK_DISABLE()               __GPIOA_CLK_DISABLE()

/**
  * @brief  EPD Command/data pin
  */
#define EPD_DC_PIN                              GPIO_PIN_11
#define EPD_DC_GPIO_PORT                        GPIOB
#define EPD_DC_GPIO_CLK_ENABLE()                __GPIOB_CLK_ENABLE()
#define EPD_DC_GPIO_CLK_DISABLE()               __GPIOB_CLK_DISABLE()

/**
  * @brief  EPD Reset pin
  */
#define EPD_RESET_PIN                           GPIO_PIN_2
#define EPD_RESET_GPIO_PORT                     GPIOB
#define EPD_RESET_GPIO_CLK_ENABLE()             __GPIOB_CLK_ENABLE()
#define EPD_RESET_GPIO_CLK_DISABLE()            __GPIOB_CLK_DISABLE()

/**
  * @brief  EPD Busy pin
  */
#define EPD_BUSY_PIN                            GPIO_PIN_8
#define EPD_BUSY_GPIO_PORT                      GPIOA
#define EPD_BUSY_GPIO_CLK_ENABLE()              __GPIOA_CLK_ENABLE()
#define EPD_BUSY_GPIO_CLK_DISABLE()             __GPIOA_CLK_DISABLE()

/**
  * @brief  EPD PWR pin
  */
#define EPD_PWR_PIN                             GPIO_PIN_10
#define EPD_PWR_GPIO_PORT                       GPIOB
#define EPD_PWR_GPIO_CLK_ENABLE()               __GPIOB_CLK_ENABLE()
#define EPD_PWR_GPIO_CLK_DISABLE()              __GPIOB_CLK_DISABLE()

/* Chip Select macro definition */
#define EPD_CS_LOW()            GPIO_WritePin(EPD_CS_GPIO_PORT, EPD_CS_PIN, GPIO_PIN_RESET)
#define EPD_CS_HIGH()           GPIO_WritePin(EPD_CS_GPIO_PORT, EPD_CS_PIN, GPIO_PIN_SET)

/* EPD Data/Command macro definition */
#define EPD_DC_LOW()            GPIO_WritePin(EPD_DC_GPIO_PORT, EPD_DC_PIN, GPIO_PIN_RESET)
#define EPD_DC_HIGH()           GPIO_WritePin(EPD_DC_GPIO_PORT, EPD_DC_PIN, GPIO_PIN_SET)

/* EPD Reset macro definition */
#define EPD_RESET_LOW()         GPIO_WritePin(EPD_RESET_GPIO_PORT, EPD_RESET_PIN, GPIO_PIN_RESET)
#define EPD_RESET_HIGH()        GPIO_WritePin(EPD_RESET_GPIO_PORT, EPD_RESET_PIN, GPIO_PIN_SET)

/* EPD PWR macro definition */
#define EPD_PWR_LOW()           GPIO_WritePin(EPD_PWR_GPIO_PORT, EPD_PWR_PIN, GPIO_PIN_RESET)
#define EPD_PWR_HIGH()          GPIO_WritePin(EPD_PWR_GPIO_PORT, EPD_PWR_PIN, GPIO_PIN_SET)

#endif
