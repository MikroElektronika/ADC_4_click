![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# ADC_4 Click

- **CIC Prefix**  : ADC4
- **Author**      : Nemanja Medakovic
- **Verison**     : 1.0.0
- **Date**        : Jan 2018

---


### Software Support

We provide a library for the ADC_4 Click on our [LibStock](https://libstock.mikroe.com/projects/view/2293/adc-4-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

Initializes and defines GPIO port driver and driver functions witch are realized for communication via SPI bus and for calculating and converting
analog voltage to digital voltage according by value of referent voltage. Check documentation for more details.

Key functions :

- ``` uint8_t adc4_writeReg( const uint8_t regAddress, uint8_t *value ) ``` - Function writes data in register determined by register address parametar of function.
- ``` uint8_t adc4_readReg( const uint8_t regAddress, uint8_t *value ) ``` - Function reads data from register determined by register address parametar of function.
- ``` void adc4_setConfig( const uint8_t regAddress, uint16_t value ) ``` - This function writes 16-bit value in configuration registers determined by register address parametar.
- ``` uint32_t adc4_getData(void) ``` - This function checks ready bit, is data ready or not, and returns 24-bit value from data register.
- ``` uint16_t adc4_getVoltage(const float refVoltage) ``` - This function returns 16-bit calculated and AD converted voltage value.

**Examples Description**

- System Initialization - Initializes GPIO pins (CS, INT), SPI module for communication
  with ADC 4 click and UART for data logging.
- Application Initialization - Initializes ADC 4 driver and setups working mode.
- Application Task - (code snippet) - Sequential read of voltage. Information about
  current voltage is logget to UART. Operation is repeated each second. Settings are set
  to calculate and convert input voltage with referent voltage 2.5V.


```.c

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

```

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2293/adc-4-click) page.

Other mikroE Libraries used in the example:

- Conversions
- C_String
- SPI
- UART

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
