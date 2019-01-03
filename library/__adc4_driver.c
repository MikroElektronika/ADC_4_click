/*
    __adc4_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__adc4_driver.h"
#include "__adc4_hal.c"

/* ------------------------------------------------------------------- MACROS */

#define READ_OPERATION  0
#define WRITE_OPERATION 1

/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __ADC4_DRV_I2C__
static uint8_t _slaveAddress;
#endif

static float _vRef;
static uint16_t _wDog;
uint8_t _ADC4_SIGN_BIT;

const uint32_t _ADC4_RESOLUTION           = 8388607;

const float _ADC4_VREF_4000MV             = 4.096;
const float _ADC4_VREF_2500MV             = 2.5;

const uint8_t _ADC4_STATUS_REG            = 0x00;
const uint8_t _ADC4_MODE_REG              = 0x01;
const uint8_t _ADC4_IFACE_MODE_REG        = 0x02;
const uint8_t _ADC4_CHECK_REG             = 0x03;
const uint8_t _ADC4_DATA_REG              = 0x04;
const uint8_t _ADC4_GPIO_CONFIG_REG       = 0x06;
const uint8_t _ADC4_ID_REG                = 0x07;
const uint8_t _ADC4_SETUP_CONFIGURATION_REG = 0x20;

const uint8_t _ADC4_CH_REG_BASE           = 0x10;
const uint8_t _ADC4_CON_REG_BASE          = 0x20;
const uint8_t _ADC4_FILCON_REG_BASE       = 0x28;
const uint8_t _ADC4_OFFSET_REG_BASE       = 0x30;
const uint8_t _ADC4_GAIN_REG_BASE         = 0x38;

// STATUS
const uint8_t _ADC4_STATUS_RDY            = 0x80;
const uint8_t _ADC4_STATUS_ERR            = 0x40;
const uint8_t _ADC4_STATUS_CRC_ERR        = 0x20;
const uint8_t _ADC4_STATUS_REG_ERR        = 0x10;
const uint8_t _ADC4_STATUS_CH_ACTIVE      = 0x0F;

// MODE
const uint16_t _ADC4_MODE_INT_REF_AND_SING_CYC_EN    = 0xA000;
const uint16_t _ADC4_MODE_INT_REF_EN       = 0x8000;
const uint16_t _ADC4_MODE_HIDE_RELAY_DIS   = 0x4000;
const uint16_t _ADC4_MODE_SING_CYC_EN      = 0x2000;
const uint16_t _ADC4_MODE_DELAY_0          = 0x0000;
const uint16_t _ADC4_MODE_DELAY_4          = 0x0100;
const uint16_t _ADC4_MODE_DELAY_16         = 0x0200;
const uint16_t _ADC4_MODE_DELAY_40         = 0x0300;
const uint16_t _ADC4_MODE_DELAY_100        = 0x0400;
const uint16_t _ADC4_MODE_DELAY_200        = 0x0500;
const uint16_t _ADC4_MODE_DELAY_500        = 0x0600;
const uint16_t _ADC4_MODE_DELAY_1000       = 0x0700;
const uint16_t _ADC4_MODE_CONTINUOUS       = 0x0000;
const uint16_t _ADC4_MODE_SINGLE           = 0x0010;
const uint16_t _ADC4_MODE_STBY             = 0x0020;
const uint16_t _ADC4_MODE_POWER_DOWN       = 0x0030;
const uint16_t _ADC4_MODE_INTERNAL_OFFSET  = 0x0040;
const uint16_t _ADC4_MODE_SYSTEM_OFFSET    = 0x0060;
const uint16_t _ADC4_MODE_GAIN_OFFSET      = 0x0070;
const uint16_t _ADC4_MODE_CLK_INTOSC       = 0x0000;
const uint16_t _ADC4_MODE_CLK_INTOSC_XT2   = 0x0002;
const uint16_t _ADC4_MODE_CLK_EXTOSC_XT2   = 0x0004;
const uint16_t _ADC4_MODE_CLK_EXTOSC       = 0x0006;

// IFACE MODE
const uint16_t _ADC4_IFACE_MODE_ALTSYNC_EN = 0x1000;
const uint16_t _ADC4_IFACE_MODE_IOSTREN_EN = 0x0800;
const uint16_t _ADC4_IFACE_MODE_DOUTRES_EN = 0x0100;
const uint16_t _ADC4_IFACE_MODE_CONTRD_EN  = 0x0080;
const uint16_t _ADC4_IFACE_MODE_DATASTA_EN = 0x0040;
const uint16_t _ADC4_IFACE_MODE_REGCHK_EN  = 0x0020;
const uint16_t _ADC4_IFACE_MODE_CRC_DIS    = 0x0000;
const uint16_t _ADC4_IFACE_MODE_CRC_RD_EN  = 0x0002;
const uint16_t _ADC4_IFACE_MODE_CRC_RW_EN  = 0x0004;

// CONFIG
const uint16_t _ADC4_CFG_PDSW              = 0x4000;
const uint16_t _ADC4_CFG_OP_EN2_3          = 0x2000;
const uint16_t _ADC4_CFG_MUX_IO            = 0x1000;
const uint16_t _ADC4_CFG_SYNC_EN           = 0x0800;
const uint16_t _ADC4_CFG_ERR_DISABLE       = 0x0000;
const uint16_t _ADC4_CFG_ERR_INPUT         = 0x0400;
const uint16_t _ADC4_CFG_ERR_OPENDRAIN     = 0x0200;
const uint16_t _ADC4_CFG_ERR_OUTPUT        = 0x0600;
const uint16_t _ADC4_CFG_ERR_DAT           = 0x0010;

//CH REG
const uint16_t _ADC4_CH_EN                  = 0x8001;
const uint16_t _ADC4_CH_SETUP_0             = 0x0001 << 12;
const uint16_t _ADC4_CH_SETUP_1             = 0x0002 << 12;
const uint16_t _ADC4_CH_SETUP_2             = 0x0003 << 12;
const uint16_t _ADC4_CH_SETUP_3             = 0x0004 << 12;
const uint16_t _ADC4_CH_SETUP_4             = 0x0005 << 12;
const uint16_t _ADC4_CH_SETUP_5             = 0x0006 << 12;
const uint16_t _ADC4_CH_SETUP_6             = 0x0007 << 12;
const uint16_t _ADC4_CH_SETUP_7             = 0x0008 << 12;
const uint16_t _ADC4_CH_AINPOS_0            = 0x0000 << 5;      
const uint16_t _ADC4_CH_AINPOS_1            = 0x0001 << 5;      
const uint16_t _ADC4_CH_AINPOS_2            = 0x0002 << 5;      
const uint16_t _ADC4_CH_AINPOS_3            = 0x0003 << 5;      
const uint16_t _ADC4_CH_AINPOS_4            = 0x0004 << 5;      
const uint16_t _ADC4_CH_AINPOS_5            = 0x0005 << 5;      
const uint16_t _ADC4_CH_AINPOS_6            = 0x0006 << 5;      
const uint16_t _ADC4_CH_AINPOS_7            = 0x0007 << 5;
const uint16_t _ADC4_CH_AINPOS_8            = 0x0008 << 5;   
const uint16_t _ADC4_CH_AINPOS_9            = 0x0009 << 5;   
const uint16_t _ADC4_CH_AINPOS_10           = 0x000A << 5;    
const uint16_t _ADC4_CH_AINPOS_11           = 0x000B << 5;    
const uint16_t _ADC4_CH_AINPOS_12           = 0x000C << 5;    
const uint16_t _ADC4_CH_AINPOS_13           = 0x000D << 5;    
const uint16_t _ADC4_CH_AINPOS_14           = 0x000E << 5;    
const uint16_t _ADC4_CH_AINPOS_15           = 0x000F << 5;    
const uint16_t _ADC4_CH_AINPOS_16           = 0x0010 << 5;
const uint16_t _ADC4_CH_AINPOS_TEMP_P       = 0x0011 << 5;
const uint16_t _ADC4_CH_AINPOS_TEMP_N       = 0x0012 << 5;
const uint16_t _ADC4_CH_AINPOS_AV_P         = 0x0013 << 5;
const uint16_t _ADC4_CH_AINPOS_AV_N         = 0x0014 << 5;
const uint16_t _ADC4_CH_AINPOS_REF_P        = 0x0015 << 5;
const uint16_t _ADC4_CH_AINPOS_REF_N        = 0x0016 << 5;
const uint16_t _ADC4_CH_AINNEG_0            = 0x0000;
const uint16_t _ADC4_CH_AINNEG_1            = 0x0001;
const uint16_t _ADC4_CH_AINNEG_2            = 0x0002;
const uint16_t _ADC4_CH_AINNEG_3            = 0x0003;
const uint16_t _ADC4_CH_AINNEG_4            = 0x0004;
const uint16_t _ADC4_CH_AINNEG_5            = 0x0005;
const uint16_t _ADC4_CH_AINNEG_6            = 0x0006;
const uint16_t _ADC4_CH_AINNEG_7            = 0x0007;
const uint16_t _ADC4_CH_AINNEG_8            = 0x0008;
const uint16_t _ADC4_CH_AINNEG_9            = 0x0009;
const uint16_t _ADC4_CH_AINNEG_10           = 0x000A;
const uint16_t _ADC4_CH_AINNEG_11           = 0x000B;
const uint16_t _ADC4_CH_AINNEG_12           = 0x000C;
const uint16_t _ADC4_CH_AINNEG_13           = 0x000D;
const uint16_t _ADC4_CH_AINNEG_14           = 0x000E;
const uint16_t _ADC4_CH_AINNEG_15           = 0x000F;
const uint16_t _ADC4_CH_AINNEG_16           = 0x0010;
const uint16_t _ADC4_CH_AINNEG_TEMP_P       = 0x0011;
const uint16_t _ADC4_CH_AINNEG_TEMP_N       = 0x0012;
const uint16_t _ADC4_CH_AINNEG_AV_P         = 0x0013;
const uint16_t _ADC4_CH_AINNEG_AV_N         = 0x0014;
const uint16_t _ADC4_CH_AINNEG_REF_P        = 0x0015;
const uint16_t _ADC4_CH_AINNEG_REF_N        = 0x0016;

// CON
const uint16_t _ADC4_CON_UNIPOL             = 0x0000;
const uint16_t _ADC4_CON_BIPOL              = 0x0001 << 12;
const uint16_t _ADC4_CON_REFBUF_P_EN        = 0x0001 << 11;
const uint16_t _ADC4_CON_REFBUF_N_EN        = 0x0001 << 10;
const uint16_t _ADC4_CON_AINBUF_P_EN        = 0x0001 << 9;
const uint16_t _ADC4_CON_AINBUF_N_EN        = 0x0001 << 8;
const uint16_t _ADC4_CON_BURNOUT_EN         = 0x0001 << 7;
const uint16_t _ADC4_CON_EXTREF             = 0x0000;
const uint16_t _ADC4_CON_EXTREF_SUPP        = 0x0001 << 4;
const uint16_t _ADC4_CON_EXTREF_INT         = 0x0002 << 4;
const uint16_t _ADC4_CON_EXTREF_AV          = 0x0003 << 4;

//FILTER
const uint16_t _ADC4_FILCON_SINC_MAP0        = 0x8000;
const uint16_t _ADC4_FILCON_ENHFILEN         = 0x0001 << 11;
const uint16_t _ADC4_FILCON_ENHFIL_SET1      = 0x0002 << 8;
const uint16_t _ADC4_FILCON_EHFFIL_SET2      = 0x0003 << 8;
const uint16_t _ADC4_FILCON_ENHFIL_SET3      = 0x0005 << 8;
const uint16_t _ADC4_FILCON_ENHFIL_SET4      = 0x0006 << 8;
const uint16_t _ADC4_FILCON_ORD_SINC5        = 0x0000;
const uint16_t _ADC4_FILCON_ORD_SINC3        = 0x0003 << 5;
const uint16_t _ADC4_FILCON_ODR_250000       = 0x0000;
const uint16_t _ADC4_FILCON_ODR_125000       = 0x0001;
const uint16_t _ADC4_FILCON_ODR_62500        = 0x0002;
const uint16_t _ADC4_FILCON_ODR_50000        = 0x0003;
const uint16_t _ADC4_FILCON_ODR_31250        = 0x0004;
const uint16_t _ADC4_FILCON_ODR_25000        = 0x0005;
const uint16_t _ADC4_FILCON_ODR_15625        = 0x0006;
const uint16_t _ADC4_FILCON_ODR_10000        = 0x0007;
const uint16_t _ADC4_FILCON_ODR_5000         = 0x0008;
const uint16_t _ADC4_FILCON_ODR_2500         = 0x0009;
const uint16_t _ADC4_FILCON_ODR_1000         = 0x000A;
const uint16_t _ADC4_FILCON_ODR_500          = 0x000B;
const uint16_t _ADC4_FILCON_ODR_397_5        = 0x000C;
const uint16_t _ADC4_FILCON_ODR_200          = 0x000D;
const uint16_t _ADC4_FILCON_ODR_100          = 0x000E;
const uint16_t _ADC4_FILCON_ODR_59_92        = 0x000F;
const uint16_t _ADC4_FILCON_ODR_49_96        = 0x0010;
const uint16_t _ADC4_FILCON_ODR_20           = 0x0011;
const uint16_t _ADC4_FILCON_ODR_16_66        = 0x0012;
const uint16_t _ADC4_FILCON_ODR_10           = 0x0013;
const uint16_t _ADC4_FILCON_ODR_5            = 0x0014;

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */

uint8_t calcSize( const uint8_t regAddr );

/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */

uint8_t calcSize( const uint8_t regAddr, uint8_t rwOperation )
{
    switch( regAddr )
    {
        // Status
        case 0 :
        {
            // RO register
            if (READ_OPERATION == rwOperation)
            { 
                return 1; 
            }
            else
            {
                return 0;
            }
        }
        // Mode
        case 1 :
        {
            return 2; 
        }
        // Interface mode
        case 2 :
        {
            return 2; 
        }
        // Register Check
        case 3 :
        {
            // RO register
            if (READ_OPERATION == rwOperation)
            {
                return 3; 
            }
            else
            {
                return 0;
            }
        }
        // Data
        case 4 :
        {
            // RO register
            if (READ_OPERATION == rwOperation)
            {
                return 3; 
            }
            else
            {
                return 0;
            }
        }
        // Configuration
        case 6 :
        {
            return 2; 
        }
        // ID
        case 7 :
        {
            // RO register
            if (READ_OPERATION == rwOperation)
            {
                return 2; 
            }
            else
            {
                return 0;
            }
        }
        default :
        {
            // Channel
            if ((0x10 <= regAddr) && (0x1F >= regAddr))
            {
                return 2;
            }
            // Setup Config
            else if ((0x20 <= regAddr) && (0x27 >= regAddr))
            {
                return 2;
            }
            // Filter Config
            else if ((0x28 <= regAddr) && (0x2F >= regAddr))
            {
                return 2;
            }
            // Offset
            else if ((0x30 <= regAddr) && (0x37 >= regAddr))
            {
                return 3;
            }
            // Gain
            else if ((0x38 <= regAddr) && (0x3F >= regAddr))
            {
                return 3;
            }
            else 
            {
                return 0;
            }
        }
    }
}


/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __ADC4_DRV_SPI__

void adc4_spiDriverInit(T_ADC4_P gpioObj, T_ADC4_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    hal_gpio_csSet(1);
    Delay_10us();
    
    _wDog = 100;
}

#endif
#ifdef   __ADC4_DRV_I2C__

void adc4_i2cDriverInit(T_ADC4_P gpioObj, T_ADC4_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __ADC4_DRV_UART__

void adc4_uartDriverInit(T_ADC4_P gpioObj, T_ADC4_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif

/* ----------------------------------------------------------- IMPLEMENTATION */

uint8_t adc4_writeReg( const uint8_t regAddress, uint8_t *value )
{
    uint8_t tmp    = regAddress & 0xBF;
    uint8_t nBytes = calcSize( regAddress, WRITE_OPERATION );

    if (0 != nBytes)
    {
        hal_gpio_csSet(0); 
        hal_spiWrite( &tmp, 1 );
        hal_spiWrite( value, nBytes );
        hal_gpio_csSet(1);
        Delay_10us();
    }

    return nBytes;
}

uint8_t adc4_readReg( const uint8_t regAddress, uint8_t *value )
{
    uint8_t tmp    = regAddress | 0x40;
    uint8_t nBytes = calcSize( regAddress, READ_OPERATION );

    if (0 != nBytes)
    {
        hal_gpio_csSet(0);
        hal_spiWrite( &tmp, 1 );
        hal_spiRead( value, nBytes );
        hal_gpio_csSet(1);
        Delay_10us();
    }

    return nBytes;
}

void adc4_reset(void)
{
    uint8_t tmp[8] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };

    hal_gpio_csSet(0);
    hal_spiWrite( tmp, 8 );
    hal_gpio_csSet(1);
}

uint8_t adc4_getErrPin(void)
{
    return hal_gpio_intGet();
}

void adc4_getConfig( const uint8_t regAddress, uint16_t *value )
{
    uint8_t tmp[2] = {0};

    if (2 == calcSize( regAddress, READ_OPERATION))
    {
        adc4_readReg( regAddress, tmp );
    }
}

void adc4_setConfig( const uint8_t regAddress, uint16_t value )
{
    uint8_t tmp[2] = {0};

    tmp[0] = value >> 8;
    tmp[1] = value & 0x00FF;

    if (2 == calcSize( regAddress, WRITE_OPERATION))
    {
        adc4_writeReg( regAddress, tmp );
    }
}

uint32_t adc4_getData(void)
{
    uint16_t cnt = 0;
    uint8_t  rdy = 0;
    uint32_t value = 0;
    uint8_t  tmp[ 3 ] = { 0 };

// Wait RDY - Polling - !!! Blocking !!!

    while (adc4_readReg( _ADC4_STATUS_REG, &rdy ))
    {
        if (0 == (rdy & _ADC4_STATUS_RDY))
        {
            break;
        }

        if (cnt++ >= _wDog)
        {
            return 0;
        }
    }

    adc4_readReg( _ADC4_DATA_REG, tmp );

    value = tmp[ 0 ];
    value <<= 8;
    value |= tmp[ 1 ];
    value <<= 8;
    value |= tmp[ 2 ];
    
    _ADC4_SIGN_BIT = (value & 0x00800000) >> 23;
    
    if(_ADC4_SIGN_BIT == 1)
    {
        return (value & 0x007FFFFF);
    }else
    {
        value = ~value;
        value &= 0x007FFFFF;
        return value;
    }
}

uint16_t adc4_getVoltage(const float refVoltage)
{
    uint32_t raw = 0;
    float res = 0;
    uint16_t retVal = 0;
      
    raw = adc4_getData();

    res = raw * refVoltage;
    res /= _ADC4_RESOLUTION;
    res *= 1000;
    
    retVal = res;

    return retVal;
}


/* -------------------------------------------------------------------------- */
/*
  __adc4_driver.c

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */