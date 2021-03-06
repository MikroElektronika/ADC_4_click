/*
Example for ADC_4 Click

    Date          : Dec 2017.
    Author        : MikroE Team

Test configuration dsPIC :
    
    MCU                : P33FJ256GP710A
    Dev. Board         : EasyPIC Fusion v7
    dsPIC Compiler ver : v7.0.1.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes GPIO pins (CS, INT), SPI module for communication
  with ADC 4 click and UART for data logging.
- Application Initialization - Initializes ADC 4 driver and setups working mode.
- Application Task - (code snippet) - Sequential read of voltage. Information about
  current voltage is logget to UART. Operation is repeated each second. Settings are set
  to calculate and convert input voltage with internal referent voltage 2.5V.

*/

#include "Click_ADC_4_types.h"
#include "Click_ADC_4_config.h"

uint16_t voltage;
char text[ 100 ] = { 0 };

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT );
    mikrobus_spiInit( _MIKROBUS1, &_ADC4_SPI_CFG[0] );
    mikrobus_logInit( _LOG_USBUART_A, 9600 );

    Delay_ms( 100 );
}

void applicationInit()
{
    adc4_spiDriverInit( (T_ADC4_P)&_MIKROBUS1_GPIO, (T_ADC4_P)&_MIKROBUS1_SPI );
    
    Delay_ms( 100 );

    adc4_setConfig( _ADC4_CH_REG_BASE, _ADC4_CH_EN);
    adc4_setConfig( _ADC4_MODE_REG, _ADC4_MODE_INT_REF_AND_SING_CYC_EN );
    adc4_setConfig( _ADC4_IFACE_MODE_REG, _ADC4_IFACE_MODE_CRC_DIS );
    adc4_setConfig( _ADC4_GPIO_CONFIG_REG, _ADC4_CFG_SYNC_EN );
    adc4_setConfig( _ADC4_SETUP_CONFIGURATION_REG, 0x1320);
    
    voltage = 0;
}

void applicationTask()
{
    voltage = adc4_getVoltage(_ADC4_VREF_2500MV);

    if(_ADC4_SIGN_BIT == 1)
    {
        IntToStr( voltage, text );
        mikrobus_logWrite( "Current Voltage : ", _LOG_TEXT );
        mikrobus_logWrite( text, _LOG_TEXT );
        mikrobus_logWrite( " mV", _LOG_LINE );
    }else
    {
        IntToStr( voltage, text );
        mikrobus_logWrite( "Current Voltage : -", _LOG_TEXT );
        mikrobus_logWrite( text, _LOG_TEXT );
        mikrobus_logWrite( " mV", _LOG_LINE );
    }

    Delay_ms( 1000 );
}

void main()
{
    systemInit();
    applicationInit();

    while(1)
    {
        applicationTask();
    }
}
