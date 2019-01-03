#line 1 "E:/git/click-boards/ADC_4_click/SW/example/c/PIC32/Click_ADC_4_PIC32.c"
#line 1 "e:/git/click-boards/adc_4_click/sw/example/c/pic32/click_adc_4_types.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for pic32/include/stdint.h"




typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int int32_t;
typedef signed long long int64_t;


typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long int uint32_t;
typedef unsigned long long uint64_t;


typedef signed char int_least8_t;
typedef signed int int_least16_t;
typedef signed long int int_least32_t;
typedef signed long long int_least64_t;


typedef unsigned char uint_least8_t;
typedef unsigned int uint_least16_t;
typedef unsigned long int uint_least32_t;
typedef unsigned long long uint_least64_t;



typedef signed long int int_fast8_t;
typedef signed long int int_fast16_t;
typedef signed long int int_fast32_t;
typedef signed long long int_fast64_t;


typedef unsigned long int uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long long uint_fast64_t;


typedef signed long int intptr_t;
typedef unsigned long int uintptr_t;


typedef signed long long intmax_t;
typedef unsigned long long uintmax_t;
#line 1 "e:/git/click-boards/adc_4_click/sw/example/c/pic32/click_adc_4_config.h"
#line 1 "e:/git/click-boards/adc_4_click/sw/example/c/pic32/click_adc_4_types.h"
#line 4 "e:/git/click-boards/adc_4_click/sw/example/c/pic32/click_adc_4_config.h"
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
#line 1 "e:/git/click-boards/adc_4_click/sw/library/__adc4_driver.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for pic32/include/stdint.h"
#line 57 "e:/git/click-boards/adc_4_click/sw/library/__adc4_driver.h"
extern const uint8_t _ADC4_DELAY_0us;
extern const uint8_t _ADC4_DELAY_4us;
extern const uint8_t _ADC4_DELAY_16us;
extern const uint8_t _ADC4_DELAY_40us;
extern const uint8_t _ADC4_DELAY_100us;
extern const uint8_t _ADC4_DELAY_200us;
extern const uint8_t _ADC4_DELAY_500us;
extern const uint8_t _ADC4_DELAY_1ms;



extern const uint8_t _ADC4_CONTINUOS_CONVERSION_MODE;
extern const uint8_t _ADC4_SINGLE_CONVERSION_MODE;
extern const uint8_t _ADC4_STANDBY_MODE;
extern const uint8_t _ADC4_POWER_DOWE_MODE;
extern const uint8_t _ADC4_INTERNAL_OFFSET_MODE;
extern const uint8_t _ADC4_SYSTEM_OFFSET_MODE;
extern const uint8_t _ADC4_SYSTEM_GAIN_MODE;



extern const uint8_t _ADC4_INTERNAL_OSCILLATOR;
extern const uint8_t _ADC4_INTERNAL_OSCILLATOR_XTAL2_CLKIO;
extern const uint8_t _ADC4_EXTERNAL_CLOCK_XTAL2_CLKIO;
extern const uint8_t _ADC4_EXTERNAL_CLOCK_XTAL1_XTAL2_CLKIO;




extern const uint8_t _ADC4_CRC_DISABLED;
extern const uint8_t _ADC4_CRC_READ;
extern const uint8_t _ADC4_CRC_READ_WRITE;



extern const uint8_t _ADC4_POSTF_27SPS_47dB_36ms;
extern const uint8_t _ADC4_POSTF_25SPS_62dB_40ms;
extern const uint8_t _ADC4_POSTF_20SPS_86dB_50ms;
extern const uint8_t _ADC4_POSTF_16SPS_92dB_60ms;




extern const uint8_t _ADC4_FILTER_SINC5_SINC1;
extern const uint8_t _ADC4_FILTER_SINC3;




extern const uint8_t _ADC4_CH0_REG;
extern const uint8_t _ADC4_CH1_REG;
extern const uint8_t _ADC4_CH2_REG;
extern const uint8_t _ADC4_CH3_REG;
extern const uint8_t _ADC4_CH4_REG;
extern const uint8_t _ADC4_CH5_REG;
extern const uint8_t _ADC4_CH6_REG;
extern const uint8_t _ADC4_CH7_REG;
extern const uint8_t _ADC4_CH8_REG;
extern const uint8_t _ADC4_CH9_REG;
extern const uint8_t _ADC4_CH10_REG;
extern const uint8_t _ADC4_CH11_REG;
extern const uint8_t _ADC4_CH12_REG;
extern const uint8_t _ADC4_CH13_REG;
extern const uint8_t _ADC4_CH14_REG;
extern const uint8_t _ADC4_CH15_REG;



extern const uint8_t _ADC4_AIN0;
extern const uint8_t _ADC4_AIN1;
extern const uint8_t _ADC4_AIN2;
extern const uint8_t _ADC4_AIN3;
extern const uint8_t _ADC4_AIN4;
extern const uint8_t _ADC4_AIN5;
extern const uint8_t _ADC4_AIN6;
extern const uint8_t _ADC4_AIN7;
extern const uint8_t _ADC4_AIN8;
extern const uint8_t _ADC4_AIN9;
extern const uint8_t _ADC4_AIN10;
extern const uint8_t _ADC4_AIN11;
extern const uint8_t _ADC4_AIN12;
extern const uint8_t _ADC4_AIN13;
extern const uint8_t _ADC4_AIN14;
extern const uint8_t _ADC4_AIN15;
#line 150 "e:/git/click-boards/adc_4_click/sw/library/__adc4_driver.h"
void adc4_spiDriverInit( const uint8_t*  gpioObj,  const uint8_t*  spiObj);
#line 168 "e:/git/click-boards/adc_4_click/sw/library/__adc4_driver.h"
void adc4_writeReg( uint8_t regAddr, uint8_t *value, uint8_t nBytes );
#line 177 "e:/git/click-boards/adc_4_click/sw/library/__adc4_driver.h"
void adc4_readReg( uint8_t regAddr, uint8_t *value, uint8_t nBytes );
#line 185 "e:/git/click-boards/adc_4_click/sw/library/__adc4_driver.h"
uint16_t adc4_getID();
#line 193 "e:/git/click-boards/adc_4_click/sw/library/__adc4_driver.h"
uint16_t adc4_getVoltage();
#line 200 "e:/git/click-boards/adc_4_click/sw/library/__adc4_driver.h"
uint16_t adc4_getData();

uint32_t adc4_getRegCheck();
#line 215 "e:/git/click-boards/adc_4_click/sw/library/__adc4_driver.h"
void adc4_setChanel( uint8_t chanel, uint8_t posBus, uint8_t negBus );
#line 229 "e:/git/click-boards/adc_4_click/sw/library/__adc4_driver.h"
void adc4_setMode( uint8_t delay, uint8_t mode, uint8_t oscillator );
#line 238 "e:/git/click-boards/adc_4_click/sw/library/__adc4_driver.h"
void adc4_setCRC( uint8_t crc );
#line 246 "e:/git/click-boards/adc_4_click/sw/library/__adc4_driver.h"
void adc4_setFilter( uint8_t postFilter, uint8_t filter );
#line 253 "e:/git/click-boards/adc_4_click/sw/library/__adc4_driver.h"
uint8_t adc4_statusReg();
#line 32 "E:/git/click-boards/ADC_4_click/SW/example/c/PIC32/Click_ADC_4_PIC32.c"
uint16_t voltage;
uint8_t txt[ 50 ];

void systemInit()
{
 mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );
 mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT );
 mikrobus_spiInit( _MIKROBUS1, &_ADC4_SPI_CFG[0] );
 mikrobus_logInit( _MIKROBUS2, 9600 );

 Delay_ms( 100 );
}

void applicationInit()
{
 adc4_spiDriverInit( ( const uint8_t* )&_MIKROBUS1_GPIO, ( const uint8_t* )&_MIKROBUS1_SPI );

 adc4_setMode( _ADC4_DELAY_0us, _ADC4_CONTINUOS_CONVERSION_MODE, _ADC4_INTERNAL_OSCILLATOR );
 adc4_setCRC( _ADC4_CRC_DISABLED );
 adc4_setFilter( _ADC4_POSTF_20SPS_86dB_50ms, _ADC4_FILTER_SINC5_SINC1 );
}

void applicationTask()
{
 adc4_setChanel( _ADC4_CH2_REG,_ADC4_AIN0,_ADC4_AIN3 );
 voltage = adc4_getVoltage();

 WordToStr( voltage, txt );
 mikrobus_logWrite( "Current Voltage : ", _LOG_TEXT );
 mikrobus_logWrite( txt, _LOG_TEXT );
 mikrobus_logWrite( " mV", _LOG_LINE );

 Delay_ms( 1000 );
}

void main()
{
 systemInit();
 applicationInit();

 while (1)
 {
 applicationTask();
 }
}
