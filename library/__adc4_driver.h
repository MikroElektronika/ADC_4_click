/*
    __adc4_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __adc4_driver.h
@brief    ADC_4 Driver
@mainpage ADC_4 Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   ADC4
@brief      ADC_4 Click Driver
@{

| Global Library Prefix | **ADC4** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Dec 2017.**      |
| Developer             | **MikroE Team**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _ADC4_H_
#define _ADC4_H_

/** 
 * @macro T_ADC4_P
 * @brief Driver Abstract type 
 */
#define T_ADC4_P    const uint8_t*

/** @defgroup ADC4_COMPILE Compilation Config */              /** @{ */

   #define   __ADC4_DRV_SPI__                                 /**<     @macro __ADC4_DRV_SPI__  @brief SPI driver selector */
//  #define   __ADC4_DRV_I2C__                                /**<     @macro __ADC4_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __ADC4_DRV_UART__                                /**<     @macro __ADC4_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup ADC4_REGS ADC 4 Registers */                             /** @{ */

extern uint8_t _ADC4_SIGN_BIT;

extern const uint32_t _ADC4_RESOLUTION;

extern const float _ADC4_VREF_4000MV;
extern const float _ADC4_VREF_2500MV;

extern const uint8_t _ADC4_STATUS_REG      ; /**< Status */
extern const uint8_t _ADC4_MODE_REG        ; /**< ADC Mode */
extern const uint8_t _ADC4_IFACE_MODE_REG  ; /**< Interface Mode */
extern const uint8_t _ADC4_CHECK_REG       ; /**< Register Check */
extern const uint8_t _ADC4_DATA_REG        ; /**< Data */
extern const uint8_t _ADC4_GPIO_CONFIG_REG ; /**< GPIO Configuration */
extern const uint8_t _ADC4_ID_REG          ; /**< ID */
extern const uint8_t _ADC4_SETUP_CONFIGURATION_REG;

extern const uint8_t _ADC4_CH_REG_BASE     ; /**< Group - Chanel Registers (0x10 - 0x1F) */
extern const uint8_t _ADC4_CON_REG_BASE    ; /**< Group - Setup Configuration (0x20 - 0x27) */
extern const uint8_t _ADC4_FILCON_REG_BASE ; /**< Group - Filter Configuration (0x28 - 0x2F) */
extern const uint8_t _ADC4_OFFSET_REG_BASE ; /**< Group - Offset Registers (0x30 - 0x37) */
extern const uint8_t _ADC4_GAIN_REG_BASE   ; /**< Group - Gain Registers (0x38 - 0x3F) */

                                                                       /** @} */
/** @defgroup ADC4_STATUS ADC 4 Status register values */              /** @{ */

extern const uint8_t _ADC4_STATUS_RDY       ;
extern const uint8_t _ADC4_STATUS_ERR       ;
extern const uint8_t _ADC4_STATUS_CRC_ERR   ;
extern const uint8_t _ADC4_STATUS_REG_ERR   ;
extern const uint8_t _ADC4_STATUS_CH_ACTIVE ;
                                                                       /** @} */
/** @defgroup ADC4_MODE ADC 4 Mode register values */                  /** @{ */

extern const uint16_t _ADC4_MODE_INT_REF_AND_SING_CYC_EN;
extern const uint16_t _ADC4_MODE_INT_REF_EN      ;
extern const uint16_t _ADC4_MODE_HIDE_RELAY_DIS  ;
extern const uint16_t _ADC4_MODE_SING_CYC_EN     ;
extern const uint16_t _ADC4_MODE_DELAY_0         ;
extern const uint16_t _ADC4_MODE_DELAY_4         ;
extern const uint16_t _ADC4_MODE_DELAY_16        ;
extern const uint16_t _ADC4_MODE_DELAY_40        ;
extern const uint16_t _ADC4_MODE_DELAY_100       ;
extern const uint16_t _ADC4_MODE_DELAY_200       ;
extern const uint16_t _ADC4_MODE_DELAY_500       ;
extern const uint16_t _ADC4_MODE_DELAY_1000      ;
extern const uint16_t _ADC4_MODE_CONTINUOUS      ;
extern const uint16_t _ADC4_MODE_SINGLE          ;
extern const uint16_t _ADC4_MODE_STBY            ;
extern const uint16_t _ADC4_MODE_POWER_DOWN      ;
extern const uint16_t _ADC4_MODE_INTERNAL_OFFSET ;
extern const uint16_t _ADC4_MODE_SYSTEM_OFFSET   ;
extern const uint16_t _ADC4_MODE_GAIN_OFFSET     ;
extern const uint16_t _ADC4_MODE_CLK_INTOSC      ;
extern const uint16_t _ADC4_MODE_CLK_INTOSC_XT2  ;
extern const uint16_t _ADC4_MODE_CLK_EXTOSC_XT2  ;
extern const uint16_t _ADC4_MODE_CLK_EXTOSC      ;
                                                                       /** @} */
/** @defgroup ADC4_IFACE ADC 4 Interface Mode register values */       /** @{ */

extern const uint16_t _ADC4_IFACE_MODE_ALTSYNC_EN ;
extern const uint16_t _ADC4_IFACE_MODE_IOSTREN_EN ;
extern const uint16_t _ADC4_IFACE_MODE_DOUTRES_EN ;
extern const uint16_t _ADC4_IFACE_MODE_CONTRD_EN  ;
extern const uint16_t _ADC4_IFACE_MODE_DATASTA_EN ;
extern const uint16_t _ADC4_IFACE_MODE_REGCHK_EN  ;
extern const uint16_t _ADC4_IFACE_MODE_CRC_DIS    ;
extern const uint16_t _ADC4_IFACE_MODE_CRC_RD_EN  ;
extern const uint16_t _ADC4_IFACE_MODE_CRC_RW_EN  ;
                                                                       /** @} */
/** @defgroup ADC4_CFG ADC 4 GPIO Configuration register values */     /** @{ */

extern const uint16_t _ADC4_CFG_PDSW          ;
extern const uint16_t _ADC4_CFG_OP_EN2_3      ;
extern const uint16_t _ADC4_CFG_MUX_IO        ;
extern const uint16_t _ADC4_CFG_SYNC_EN       ;
extern const uint16_t _ADC4_CFG_ERR_DISABLE   ;
extern const uint16_t _ADC4_CFG_ERR_INPUT     ;
extern const uint16_t _ADC4_CFG_ERR_OPENDRAIN ;
extern const uint16_t _ADC4_CFG_ERR_OUTPUT    ;
extern const uint16_t _ADC4_CFG_ERR_DAT       ;
                                                                       /** @} */
/** @defgroup ADC4_CH ADC 4 Channel Configuration register values */   /** @{ */

extern const uint16_t _ADC4_CH_EN            ;
extern const uint16_t _ADC4_CH_SETUP_0       ; 
extern const uint16_t _ADC4_CH_SETUP_1       ;
extern const uint16_t _ADC4_CH_SETUP_2       ;
extern const uint16_t _ADC4_CH_SETUP_3       ;
extern const uint16_t _ADC4_CH_SETUP_4       ;
extern const uint16_t _ADC4_CH_SETUP_5       ;
extern const uint16_t _ADC4_CH_SETUP_6       ;
extern const uint16_t _ADC4_CH_SETUP_7       ;
extern const uint16_t _ADC4_CH_AINPOS_0      ;      
extern const uint16_t _ADC4_CH_AINPOS_1      ;      
extern const uint16_t _ADC4_CH_AINPOS_2      ;      
extern const uint16_t _ADC4_CH_AINPOS_3      ;      
extern const uint16_t _ADC4_CH_AINPOS_4      ;      
extern const uint16_t _ADC4_CH_AINPOS_5      ;      
extern const uint16_t _ADC4_CH_AINPOS_6      ;      
extern const uint16_t _ADC4_CH_AINPOS_7      ;
extern const uint16_t _ADC4_CH_AINPOS_8      ;   
extern const uint16_t _ADC4_CH_AINPOS_9      ;   
extern const uint16_t _ADC4_CH_AINPOS_10     ;    
extern const uint16_t _ADC4_CH_AINPOS_11     ;    
extern const uint16_t _ADC4_CH_AINPOS_12     ;    
extern const uint16_t _ADC4_CH_AINPOS_13     ;    
extern const uint16_t _ADC4_CH_AINPOS_14     ;    
extern const uint16_t _ADC4_CH_AINPOS_15     ;    
extern const uint16_t _ADC4_CH_AINPOS_16     ;
extern const uint16_t _ADC4_CH_AINPOS_TEMP_P ;
extern const uint16_t _ADC4_CH_AINPOS_TEMP_N ;
extern const uint16_t _ADC4_CH_AINPOS_AV_P   ;
extern const uint16_t _ADC4_CH_AINPOS_AV_N   ;
extern const uint16_t _ADC4_CH_AINPOS_REF_P  ;
extern const uint16_t _ADC4_CH_AINPOS_REF_N  ;
extern const uint16_t _ADC4_CH_AINNEG_0      ;
extern const uint16_t _ADC4_CH_AINNEG_1      ;
extern const uint16_t _ADC4_CH_AINNEG_2      ;
extern const uint16_t _ADC4_CH_AINNEG_3      ;
extern const uint16_t _ADC4_CH_AINNEG_4      ;
extern const uint16_t _ADC4_CH_AINNEG_5      ;
extern const uint16_t _ADC4_CH_AINNEG_6      ;
extern const uint16_t _ADC4_CH_AINNEG_7      ;
extern const uint16_t _ADC4_CH_AINNEG_8      ;
extern const uint16_t _ADC4_CH_AINNEG_9      ;
extern const uint16_t _ADC4_CH_AINNEG_10     ;
extern const uint16_t _ADC4_CH_AINNEG_11     ;
extern const uint16_t _ADC4_CH_AINNEG_12     ;
extern const uint16_t _ADC4_CH_AINNEG_13     ;
extern const uint16_t _ADC4_CH_AINNEG_14     ;
extern const uint16_t _ADC4_CH_AINNEG_15     ;
extern const uint16_t _ADC4_CH_AINNEG_16     ;
extern const uint16_t _ADC4_CH_AINNEG_TEMP_P ;
extern const uint16_t _ADC4_CH_AINNEG_TEMP_N ;
extern const uint16_t _ADC4_CH_AINNEG_AV_P   ;
extern const uint16_t _ADC4_CH_AINNEG_AV_N   ;
extern const uint16_t _ADC4_CH_AINNEG_REF_P  ;
extern const uint16_t _ADC4_CH_AINNEG_REF_N  ;
                                                                       /** @} */
/** @defgroup ADC4_CON ADC 4 Setup Configuration register values */    /** @{ */

extern const uint16_t _ADC4_CON_UNIPOL      ;
extern const uint16_t _ADC4_CON_BIPOL       ;
extern const uint16_t _ADC4_CON_REFBUF_P_EN ;
extern const uint16_t _ADC4_CON_REFBUF_N_EN ;
extern const uint16_t _ADC4_CON_AINBUF_P_EN ;
extern const uint16_t _ADC4_CON_AINBUF_N_EN ;
extern const uint16_t _ADC4_CON_BURNOUT_EN  ;
extern const uint16_t _ADC4_CON_EXTREF      ;
extern const uint16_t _ADC4_CON_EXTREF_SUPP ;
extern const uint16_t _ADC4_CON_EXTREF_INT  ;
extern const uint16_t _ADC4_CON_EXTREF_AV   ;
                                                                       /** @} */
/** @defgroup ADC4_FILT ADC 4 Filter Configuration register values */  /** @{ */

extern const uint16_t _ADC4_FILCON_SINC_MAP0   ;
extern const uint16_t _ADC4_FILCON_ENHFILEN    ;
extern const uint16_t _ADC4_FILCON_ENHFIL_SET1 ;
extern const uint16_t _ADC4_FILCON_EHFFIL_SET2 ;
extern const uint16_t _ADC4_FILCON_ENHFIL_SET3 ;
extern const uint16_t _ADC4_FILCON_ENHFIL_SET4 ;
extern const uint16_t _ADC4_FILCON_ORD_SINC5   ;
extern const uint16_t _ADC4_FILCON_ORD_SINC3   ;
extern const uint16_t _ADC4_FILCON_ODR_250000  ;
extern const uint16_t _ADC4_FILCON_ODR_125000  ;
extern const uint16_t _ADC4_FILCON_ODR_62500   ;
extern const uint16_t _ADC4_FILCON_ODR_50000   ;
extern const uint16_t _ADC4_FILCON_ODR_31250   ;
extern const uint16_t _ADC4_FILCON_ODR_25000   ;
extern const uint16_t _ADC4_FILCON_ODR_15625   ;
extern const uint16_t _ADC4_FILCON_ODR_10000   ;
extern const uint16_t _ADC4_FILCON_ODR_5000    ;
extern const uint16_t _ADC4_FILCON_ODR_2500    ;
extern const uint16_t _ADC4_FILCON_ODR_1000    ;
extern const uint16_t _ADC4_FILCON_ODR_500     ;
extern const uint16_t _ADC4_FILCON_ODR_397_5   ;
extern const uint16_t _ADC4_FILCON_ODR_200     ;
extern const uint16_t _ADC4_FILCON_ODR_100     ;
extern const uint16_t _ADC4_FILCON_ODR_59_92   ;
extern const uint16_t _ADC4_FILCON_ODR_49_96   ;
extern const uint16_t _ADC4_FILCON_ODR_20      ;
extern const uint16_t _ADC4_FILCON_ODR_16_66   ;
extern const uint16_t _ADC4_FILCON_ODR_10      ;
extern const uint16_t _ADC4_FILCON_ODR_5       ;
                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup ADC4_INIT Driver Initialization */              /** @{ */

#ifdef   __ADC4_DRV_SPI__
void adc4_spiDriverInit(T_ADC4_P gpioObj, T_ADC4_P spiObj);
#endif
#ifdef   __ADC4_DRV_I2C__
void adc4_i2cDriverInit(T_ADC4_P gpioObj, T_ADC4_P i2cObj, uint8_t slave);
#endif
#ifdef   __ADC4_DRV_UART__
void adc4_uartDriverInit(T_ADC4_P gpioObj, T_ADC4_P uartObj);
#endif
                                                                       /** @} */
/** @defgroup ADC4_FUNC Driver Functions */                   /** @{ */

/**
 * @brief Generic Write Function
 *
 * @param[in] regAddress        register address
 * @param[in] value             pointer to input data
 *
 * @return nBytes - number of bytes to be written
 *
 * Function writes data in register determined by register address parametar of function.
 */
uint8_t adc4_writeReg( const uint8_t regAddress, uint8_t *value );

/**
 * @brief Generic Write Function
 *
 * @param[in] regAddress        register address
 * @param[out] value            pointer when output data will be storaged
 *
 * @return nBytes - number of bytes to be read
 *
 * Function reads data from register determined by register address parametar of function.
 */
uint8_t adc4_readReg( const uint8_t regAddress, uint8_t *value );

/**
 * @brief Reset function
 *
 * This function reset ADC 4 click.
 */
void adc4_reset(void);

/**
 * @brief Error check function
 *
 * @return state of INT pin
 *
 * This function returns value of INT (ERROR) pin witch is controlled by ERR_DAT bit in the GPIOCON register.
 */
uint8_t adc4_getErrPin(void);

/**
 * @brief Get configuration function
 *
 * @param[in] regAddress        register address
 * @param[out] value            pointer when output data will be storaged
 *
 * This function writes value of configuration registers in storage determined by pointer value.
 */
void adc4_getConfig( const uint8_t regAddress, uint16_t *value );

/**
 * @brief Set configuration function
 *
 * @param[in] regAddress        register address
 * @param[in] value             16-bit value to be written
 *
 * This function writes 16-bit value in configuration registers determined by register address parametar.
 */
void adc4_setConfig( const uint8_t regAddress, uint16_t value );

/**
 * @brief Get data function
 *
 * @return 24-bit data from register
 *
 * This function checks ready bit, is data ready or not, and returns 24-bit value from data register.
 */
uint32_t adc4_getData(void);

/**
 * @brief Get voltage function
 *
 * @param[in] refVoltage      Referent voltage for ADC conversion
 *
 * @return calculated 16-bit ADC voltage value
 *
 * This function returns 16-bit calculated and AD converted voltage value.
 */
uint16_t adc4_getVoltage(const float refVoltage);
                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_ADC_4_STM.c
    @example Click_ADC_4_TIVA.c
    @example Click_ADC_4_CEC.c
    @example Click_ADC_4_KINETIS.c
    @example Click_ADC_4_MSP.c
    @example Click_ADC_4_PIC.c
    @example Click_ADC_4_PIC32.c
    @example Click_ADC_4_DSPIC.c
    @example Click_ADC_4_AVR.c
    @example Click_ADC_4_FT90x.c
    @example Click_ADC_4_STM.mbas
    @example Click_ADC_4_TIVA.mbas
    @example Click_ADC_4_CEC.mbas
    @example Click_ADC_4_KINETIS.mbas
    @example Click_ADC_4_MSP.mbas
    @example Click_ADC_4_PIC.mbas
    @example Click_ADC_4_PIC32.mbas
    @example Click_ADC_4_DSPIC.mbas
    @example Click_ADC_4_AVR.mbas
    @example Click_ADC_4_FT90x.mbas
    @example Click_ADC_4_STM.mpas
    @example Click_ADC_4_TIVA.mpas
    @example Click_ADC_4_CEC.mpas
    @example Click_ADC_4_KINETIS.mpas
    @example Click_ADC_4_MSP.mpas
    @example Click_ADC_4_PIC.mpas
    @example Click_ADC_4_PIC32.mpas
    @example Click_ADC_4_DSPIC.mpas
    @example Click_ADC_4_AVR.mpas
    @example Click_ADC_4_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __adc4_driver.h

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