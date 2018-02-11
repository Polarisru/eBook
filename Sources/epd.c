#include "stm32l053xx.h"
#include "stm32l0xx_gpio.h"
#include "defines.h"
#include "epd.h"
#include "spi.h"

/**
  * @brief  Configures the EPD SPI interface.
  * @param  None
  * @retval None
  */
void EPD_IO_Init(void)
{
  GPIO_InitTypeDef  GPIO_InitStruct;

  /* EPD_CS_GPIO and EPD_DC_GPIO Periph clock enable */
  EPD_CS_GPIO_CLK_ENABLE();
  EPD_DC_GPIO_CLK_ENABLE();
  EPD_RESET_GPIO_CLK_ENABLE();
  EPD_BUSY_GPIO_CLK_ENABLE();
  EPD_PWR_GPIO_CLK_ENABLE();

  /* Configure EPD_CS_PIN pin: EPD Card CS pin */
  GPIO_InitStruct.Pin = EPD_CS_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
  GPIO_Init(EPD_CS_GPIO_PORT, &GPIO_InitStruct);

  /* Configure EPD_DC_PIN pin: EPD Card DC pin */
  GPIO_InitStruct.Pin = EPD_DC_PIN;
  GPIO_Init(EPD_DC_GPIO_PORT, &GPIO_InitStruct);

  /* Configure EPD_RESET_PIN pin */
  GPIO_InitStruct.Pin = EPD_RESET_PIN;
  GPIO_Init(EPD_PWR_GPIO_PORT, &GPIO_InitStruct);

  /* Configure EPD_RESET_PIN pin */
  GPIO_InitStruct.Pin = EPD_PWR_PIN;
  GPIO_Init(EPD_RESET_GPIO_PORT, &GPIO_InitStruct);

  /* Configure EPD_BUSY_PIN pin */
  GPIO_InitStruct.Pin = EPD_BUSY_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  GPIO_Init(EPD_BUSY_GPIO_PORT, &GPIO_InitStruct);

  /* Enbale Display */
  EPD_PWR_LOW();

  /* Set or Reset the control line */
  EPD_CS_LOW();
  EPD_CS_HIGH();

  /* EPD reset pin mamagement */
  EPD_RESET_HIGH();
  EPD_Delay(10);

  /* SPI Configuration */
  SPI_Init();
}

/**
  * @brief  Write register value.
  * @param  None
  * @retval None
  */
void EPD_IO_WriteData(uint16_t RegValue) 
{
  /* Reset EPD control line CS */
  EPD_CS_LOW();

  /* Set EPD data/command line DC to High */
  EPD_DC_HIGH();

  /* Send Data */
  SPI_Write(RegValue);

  /* Deselect: Chip Select high */
  EPD_CS_HIGH();
}

/**
  * @brief  Writes command to selected EPD register.
  * @param  Reg: Address of the selected register.
  * @retval None
  */
void EPD_IO_WriteReg(uint8_t Reg)
{
  /* Reset EPD control line CS */
  EPD_CS_LOW();
  
  /* Set EPD data/command line DC to Low */
  EPD_DC_LOW();

  /* Send Command */
  SPI_Write(Reg);

  /* Deselect: Chip Select high */
  EPD_CS_HIGH();
}

/**
  * @brief  Reads data from EPD data register.
  * @param  None
  * @retval Read data.
  */
uint16_t EPD_IO_ReadData(void)
{
  /* Reset EPD control line CS */
  EPD_CS_LOW();

  /* Deselect: Chip Select high */
  EPD_CS_HIGH();

  /* Send Data */
  return SPI_Read();
}

/**
  * @brief  Wait for loop in ms.
  * @param  Delay in ms.
  * @retval None
  */
void EPD_Delay(uint32_t Delay)
{
  HAL_Delay(Delay);
}
