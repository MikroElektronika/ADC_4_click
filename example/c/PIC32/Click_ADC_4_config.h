#include "Click_ADC_4_types.h"

const uint32_t _ADC4_SPI_CFG[ 7 ] = 
{ 
        _SPI_MASTER, 
        _SPI_8_BIT, 
        80, 
        _SPI_SS_DISABLE, 
        _SPI_DATA_SAMPLE_MIDDLE, 
        _SPI_CLK_IDLE_HIGH,
        _SPI_ACTIVE_2_IDLE
};