_systemInit:
;Click_ADC_4_PIC32.c,35 :: 		void systemInit()
ADDIU	SP, SP, -16
SW	RA, 0(SP)
;Click_ADC_4_PIC32.c,37 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );
SW	R25, 4(SP)
SW	R26, 8(SP)
SW	R27, 12(SP)
MOVZ	R27, R0, R0
ORI	R26, R0, 2
MOVZ	R25, R0, R0
JAL	_mikrobus_gpioInit+0
NOP	
;Click_ADC_4_PIC32.c,38 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT );
ORI	R27, R0, 1
ORI	R26, R0, 7
MOVZ	R25, R0, R0
JAL	_mikrobus_gpioInit+0
NOP	
;Click_ADC_4_PIC32.c,39 :: 		mikrobus_spiInit( _MIKROBUS1, &_ADC4_SPI_CFG[0] );
LUI	R2, hi_addr(__ADC4_SPI_CFG+0)
ORI	R2, R2, lo_addr(__ADC4_SPI_CFG+0)
MOVZ	R26, R2, R0
MOVZ	R25, R0, R0
JAL	_mikrobus_spiInit+0
NOP	
;Click_ADC_4_PIC32.c,40 :: 		mikrobus_logInit( _MIKROBUS2, 9600 );
ORI	R26, R0, 9600
ORI	R25, R0, 1
JAL	_mikrobus_logInit+0
NOP	
;Click_ADC_4_PIC32.c,42 :: 		Delay_ms( 100 );
LUI	R24, 40
ORI	R24, R24, 45226
L_systemInit0:
ADDIU	R24, R24, -1
BNE	R24, R0, L_systemInit0
NOP	
;Click_ADC_4_PIC32.c,43 :: 		}
L_end_systemInit:
LW	R27, 12(SP)
LW	R26, 8(SP)
LW	R25, 4(SP)
LW	RA, 0(SP)
ADDIU	SP, SP, 16
JR	RA
NOP	
; end of _systemInit
_applicationInit:
;Click_ADC_4_PIC32.c,45 :: 		void applicationInit()
ADDIU	SP, SP, -16
SW	RA, 0(SP)
;Click_ADC_4_PIC32.c,47 :: 		adc4_spiDriverInit( (T_ADC4_P)&_MIKROBUS1_GPIO, (T_ADC4_P)&_MIKROBUS1_SPI );
SW	R25, 4(SP)
SW	R26, 8(SP)
SW	R27, 12(SP)
LUI	R26, hi_addr(__MIKROBUS1_SPI+0)
ORI	R26, R26, lo_addr(__MIKROBUS1_SPI+0)
LUI	R25, hi_addr(__MIKROBUS1_GPIO+0)
ORI	R25, R25, lo_addr(__MIKROBUS1_GPIO+0)
JAL	_adc4_spiDriverInit+0
NOP	
;Click_ADC_4_PIC32.c,49 :: 		adc4_setMode( _ADC4_DELAY_0us, _ADC4_CONTINUOS_CONVERSION_MODE, _ADC4_INTERNAL_OSCILLATOR );
ORI	R27, R0, __ADC4_INTERNAL_OSCILLATOR
ORI	R26, R0, __ADC4_CONTINUOS_CONVERSION_MODE
ORI	R25, R0, __ADC4_DELAY_0us
JAL	_adc4_setMode+0
NOP	
;Click_ADC_4_PIC32.c,50 :: 		adc4_setCRC( _ADC4_CRC_DISABLED );
ORI	R25, R0, __ADC4_CRC_DISABLED
JAL	_adc4_setCRC+0
NOP	
;Click_ADC_4_PIC32.c,51 :: 		adc4_setFilter( _ADC4_POSTF_20SPS_86dB_50ms, _ADC4_FILTER_SINC5_SINC1 );
ORI	R26, R0, __ADC4_FILTER_SINC5_SINC1
ORI	R25, R0, __ADC4_POSTF_20SPS_86dB_50ms
JAL	_adc4_setFilter+0
NOP	
;Click_ADC_4_PIC32.c,52 :: 		}
L_end_applicationInit:
LW	R27, 12(SP)
LW	R26, 8(SP)
LW	R25, 4(SP)
LW	RA, 0(SP)
ADDIU	SP, SP, 16
JR	RA
NOP	
; end of _applicationInit
_applicationTask:
;Click_ADC_4_PIC32.c,54 :: 		void applicationTask()
ADDIU	SP, SP, -16
SW	RA, 0(SP)
;Click_ADC_4_PIC32.c,56 :: 		adc4_setChanel( _ADC4_CH2_REG,_ADC4_AIN0,_ADC4_AIN3 );
SW	R25, 4(SP)
SW	R26, 8(SP)
SW	R27, 12(SP)
ORI	R27, R0, __ADC4_AIN3
ORI	R26, R0, __ADC4_AIN0
ORI	R25, R0, __ADC4_CH2_REG
JAL	_adc4_setChanel+0
NOP	
;Click_ADC_4_PIC32.c,57 :: 		voltage = adc4_getVoltage();
JAL	_adc4_getVoltage+0
NOP	
SH	R2, Offset(_voltage+0)(GP)
;Click_ADC_4_PIC32.c,59 :: 		WordToStr( voltage, txt );
LUI	R26, hi_addr(_txt+0)
ORI	R26, R26, lo_addr(_txt+0)
ANDI	R25, R2, 65535
JAL	_WordToStr+0
NOP	
;Click_ADC_4_PIC32.c,60 :: 		mikrobus_logWrite( "Current Voltage : ", _LOG_TEXT );
ORI	R26, R0, 1
LUI	R25, hi_addr(?lstr1_Click_ADC_4_PIC32+0)
ORI	R25, R25, lo_addr(?lstr1_Click_ADC_4_PIC32+0)
JAL	_mikrobus_logWrite+0
NOP	
;Click_ADC_4_PIC32.c,61 :: 		mikrobus_logWrite( txt, _LOG_TEXT );
ORI	R26, R0, 1
LUI	R25, hi_addr(_txt+0)
ORI	R25, R25, lo_addr(_txt+0)
JAL	_mikrobus_logWrite+0
NOP	
;Click_ADC_4_PIC32.c,62 :: 		mikrobus_logWrite( " mV", _LOG_LINE );
ORI	R26, R0, 2
LUI	R25, hi_addr(?lstr2_Click_ADC_4_PIC32+0)
ORI	R25, R25, lo_addr(?lstr2_Click_ADC_4_PIC32+0)
JAL	_mikrobus_logWrite+0
NOP	
;Click_ADC_4_PIC32.c,64 :: 		Delay_ms( 1000 );
LUI	R24, 406
ORI	R24, R24, 59050
L_applicationTask2:
ADDIU	R24, R24, -1
BNE	R24, R0, L_applicationTask2
NOP	
;Click_ADC_4_PIC32.c,65 :: 		}
L_end_applicationTask:
LW	R27, 12(SP)
LW	R26, 8(SP)
LW	R25, 4(SP)
LW	RA, 0(SP)
ADDIU	SP, SP, 16
JR	RA
NOP	
; end of _applicationTask
_main:
;Click_ADC_4_PIC32.c,67 :: 		void main()
;Click_ADC_4_PIC32.c,69 :: 		systemInit();
JAL	_systemInit+0
NOP	
;Click_ADC_4_PIC32.c,70 :: 		applicationInit();
JAL	_applicationInit+0
NOP	
;Click_ADC_4_PIC32.c,72 :: 		while (1)
L_main4:
;Click_ADC_4_PIC32.c,74 :: 		applicationTask();
JAL	_applicationTask+0
NOP	
;Click_ADC_4_PIC32.c,75 :: 		}
J	L_main4
NOP	
;Click_ADC_4_PIC32.c,76 :: 		}
L_end_main:
L__main_end_loop:
J	L__main_end_loop
NOP	
; end of _main
