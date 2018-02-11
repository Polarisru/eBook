#include "spi.h"

/**
  * @brief  SPI Bus initialization
  * @param  None
  * @retval None
  */
void SPI_Init(void)
{
  if(HAL_SPI_GetState(&SpiHandle) == HAL_SPI_STATE_RESET)
  {
    /* SPI Config */
    SpiHandle.Instance = DISCOVERY_SPIx;
    
    /* On STM32L0538-DISCO, EPD ID cannot be read then keep a common configuration */
    /* for EPD (SPI_DIRECTION_2LINES) */
    /* Note: To read a register a EPD, SPI_DIRECTION_1LINE should be set */
    SpiHandle.Init.Mode               = SPI_MODE_MASTER;
    SpiHandle.Init.Direction          = SPI_DIRECTION_2LINES;
    SpiHandle.Init.BaudRatePrescaler  = SPI_BAUDRATEPRESCALER_8;
    SpiHandle.Init.DataSize           = SPI_DATASIZE_8BIT;
    SpiHandle.Init.CLKPhase           = SPI_PHASE_2EDGE;
    SpiHandle.Init.CLKPolarity        = SPI_POLARITY_HIGH;
    SpiHandle.Init.FirstBit           = SPI_FIRSTBIT_MSB;
    SpiHandle.Init.NSS                = SPI_NSS_SOFT;
    SpiHandle.Init.CRCCalculation     = SPI_CRCCALCULATION_DISABLED;
    SpiHandle.Init.CRCPolynomial      = 7;
    SpiHandle.Init.TIMode             = SPI_TIMODE_DISABLED;
    
    SPIx_MspInit(&SpiHandle);
    HAL_SPI_Init(&SpiHandle);
  }
}

/**
  * @brief  SPI Read 4 bytes from device.
  * @param  ReadSize Number of bytes to read (max 4 bytes)
  * @retval Value read on the SPI
  */
uint32_t SPI_Read(void)
{
  HAL_StatusTypeDef status = HAL_OK;
  uint32_t readvalue = 0;
  uint32_t writevalue = 0xFFFFFFFF;
  
  status = HAL_SPI_TransmitReceive(&SpiHandle, (uint8_t*) &writevalue, (uint8_t*) &readvalue, 1, SPIx_TIMEOUT_MAX);

  /* Check the communication status */
  if(status != HAL_OK)
  {
    /* Re-Initiaize the BUS */
    SPI_Error();
  }

  return readvalue;
}

/**
  * @brief  SPI Write a byte to device.
  * @param  Value: value to be written
  * @retval None
  */
void SPI_Write(uint8_t Value)
{
  HAL_StatusTypeDef status = HAL_OK;

  status = HAL_SPI_Transmit(&SpiHandle, (uint8_t*) &Value, 1, SPIx_TIMEOUT_MAX);

  /* Check the communication status */
  if(status != HAL_OK)
  {
    /* Re-Initiaize the BUS */
    SPI_Error();
  }
}

/**
  * @brief  SPI error treatment function.
  * @param  None
  * @retval None
  */
void SPI_Error(void)
{
  /* De-Initialize the SPI comunication BUS */
  SPI_DeInit(&SpiHandle);

  /* Re-Initiaize the SPI comunication BUS */
  SPI_Init();
}
