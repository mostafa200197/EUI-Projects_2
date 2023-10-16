/*
 * register_map.h
 *
 *  Created on: Sep 28, 2023
 *      Author: DELL G5
 */

#ifndef MCAL_REGISTER_MAP_H_
#define MCAL_REGISTER_MAP_H_

#include "stdint.h"


//typedef struct{
//    volatile uint32_t DID0; //Device Identification 0
//    volatile uint32_t DID1; //Device Identification 1
//    volatile uint32_t reserved[10];
//    volatile uint32_t PBORCTL;//Brown-Out Reset Control
//    volatile uint32_t reserved2[7];
//    volatile uint32_t RIS;//Raw Interrupt Status
//    volatile uint32_t IMC;//Interrupt Mask ControL
//    volatile uint32_t MISC;//Masked Interrupt Status and Clear
//    volatile uint32_t RESC;//Reset Cause
//    volatile uint32_t RCC;//Run-Mode Clock Configuration
//    volatile uint32_t reserved3[2];//
//    volatile uint32_t GPIOHBCTL;//GPIO High-Performance Bus ControL
//    volatile uint32_t RCC2;//Run-Mode Clock Configuration 2
//    volatile uint32_t reserved4[2];//
//    volatile uint32_t MOSCCTL;//Main Oscillator Control
//    volatile uint32_t RESERVED5[49];//
//    volatile uint32_t DSLPCLKCFG;//Deep Sleep Clock Configuration
//    volatile uint32_t RESERVED6;//
//    volatile uint32_t SYSPROP;//System Properties
//    volatile uint32_t PIOSCCAL;//Precision Internal Oscillator Calibration
//    volatile uint32_t PIOSCSTAT;//Precision Internal Oscillator Statistics
//    volatile uint32_t RESERVED7[2];//
//    volatile uint32_t PLLFREQ0;//PLL Frequency 0
//    volatile uint32_t PLLFREQ1;//PLL Frequency 1
//    volatile uint32_t PLLSTAT;//PLL Status
//    volatile uint32_t RESERVED8[7];//
//    volatile uint32_t SLPPWRCFG;//Sleep Power Configuration
//    volatile uint32_t DSLPPWRCFG;//Deep-Sleep Power Configuration
//    volatile uint32_t RESERVED9[9];//
//    volatile uint32_t LDOSPCTL;//LDO Sleep Power Control
//    volatile uint32_t LDOSPCAL;//LDO Sleep Power Calibration
//    volatile uint32_t LDODPCTL;//LDO Deep-Sleep Power Control
//    volatile uint32_t LDODPCAL;//LDO Deep-Sleep Power Calibration
//    volatile uint32_t RESERVED10[2];//
//    volatile uint32_t SDPMST;//Sleep / Deep-Sleep Power Mode Status
//    volatile uint32_t RESERVED11[76];//
//    volatile uint32_t PPWD;//Watchdog Timer Peripheral Present
//    volatile uint32_t PPTIMER;//16/32-Bit General-Purpose Timer Peripheral PresenT
//    volatile uint32_t PPGPIO;//16/32-Bit General-Purpose Timer Peripheral PresenT
//    volatile uint32_t PPDMA;//16/32-Bit General-Purpose Timer Peripheral PresenT
//
//
//};

#define system_control_Base  0x400FE000

typedef struct
{
    volatile uint32_t DID0; /* Device Identification 0 */
    volatile uint32_t DID1; /* Device Identification 1 */
    volatile uint32_t Reserved[10]; /* Reserved 1 */
    volatile uint32_t PBORCTL; /* Brown-Out Reset Control */
    volatile uint32_t Reserved2[7]; /* Reserved 2 */
    volatile uint32_t RIS; /* Raw Interrupt Status */
    volatile uint32_t IMC; /* Interrupt Mask Control  */
    volatile uint32_t MISC; /* Masked Interrupt Status and Clear */
    volatile uint32_t RESC; /* Reset Cause */
    volatile uint32_t RCC; /* Run-Mode Clock Configuration */
    volatile uint32_t Reserved3[2]; /* Reserved 3 */
    volatile uint32_t GPIOHCTL; /* GPIO High-Performance Bus Control */
    volatile uint32_t RCC2; /* Run-Mode Clock Configuration  */
    volatile uint32_t Reserved4[2]; /* Reserved 4 */
    volatile uint32_t MOSCCTL; /* Main Oscillator Control */
    volatile uint32_t Reserved5[49]; /* Reserved 5 */
    volatile uint32_t DSLPCLKCFG; /* Deep Sleep Clock Configuration */
    volatile uint32_t Reserved6; /* Reserved 6 */
    volatile uint32_t SYSPROP; /* System Properties */
    volatile uint32_t PIOSCCAL; /* Precision Internal Oscillator Calibration */
    volatile uint32_t PIOSCSTAT; /* Precision Internal Oscillator Statistics */
    volatile uint32_t Reserved7[2]; /* Reserved 7 */
    volatile uint32_t PLLFREQ0; /* PLL Frequency 0 */
    volatile uint32_t PLLFREQ1; /* PLL Frequency 1 */
    volatile uint32_t PLLSTAT; /* PLL Status */
    volatile uint32_t Reserved8[7]; /* Reserved 8 */
    volatile uint32_t SLPPWRCFG; /* Sleep Power Configuration */
    volatile uint32_t DSLPPWRCFG; /* Deep-Sleep Power Configuration */
    volatile uint32_t Reserved9[9]; /* Reserved 9 */
    volatile uint32_t LDOSPCTL; /* LDO Sleep Power Control */
    volatile uint32_t LDOSPCAL; /* LDO Sleep Power Calibration */
    volatile uint32_t LDODPCTL; /* LDO Deep-Sleep Power Control */
    volatile uint32_t LDODPCAL; /* LDO Deep-Sleep Power Calibration */
    volatile uint32_t Reserved10[2]; /* Reserved 10 */
    volatile uint32_t SDPMST; /* Sleep / Deep-Sleep Power Mode Status */
    volatile uint32_t Reserved11[76]; /* Reserved 11 */
    volatile uint32_t PPWD; /* Watchdog Timer Peripheral Present */
    volatile uint32_t PPTIMER; /* 16/32-Bit General-Purpose Timer Peripheral Present */
    volatile uint32_t PPGPIO; /* General-Purpose Input/Output Peripheral Present */
    volatile uint32_t PPDMA; /* Micro Direct Memory Access Peripheral Present */
    volatile uint32_t Reserved12; /* Reserved 12 */
    volatile uint32_t PPHIB; /* Hibernation Peripheral Present */
    volatile uint32_t PPUART; /* Universal Asynchronous Receiver/Transmitter Peripheral Present */
    volatile uint32_t PPSSI; /* Synchronous Serial Interface Peripheral Present */
    volatile uint32_t PPI2C; /* Inter-Integrated Circuit Peripheral Present */
    volatile uint32_t Reserved13; /* Reserved 13 */
    volatile uint32_t PPUSB; /* Universal Serial Bus Peripheral Present */
    volatile uint32_t Reserved14[2]; /* Reserved 14 */
    volatile uint32_t PPCAN; /* Controller Area Network Peripheral Present */
    volatile uint32_t PPADC; /* Analog-to-Digital Converter Peripheral Present */
    volatile uint32_t PPACMP; /* Analog Comparator Peripheral Present */
    volatile uint32_t PPPWM; /* Pulse Width Modulator Peripheral Present */
    volatile uint32_t PPQEI; /* Quadrature Encoder Interface Peripheral Present */
    volatile uint32_t Reserved15[4]; /* Reserved 15 */
    volatile uint32_t PPEEPROM; /* EEPROM Peripheral Present */
    volatile uint32_t PPWTIMER; /* 32/64-Bit Wide General-Purpose Timer Peripheral Present */
    volatile uint32_t Reserved16[104]; /* Reserved 16 */
    volatile uint32_t SRWD; /* Watchdog Timer Software Reset */
    volatile uint32_t SRTIMER; /* 16/32-Bit General-Purpose Timer Software Reset */
    volatile uint32_t SRGPIO; /* General-Purpose Input/Output Software Reset */
    volatile uint32_t SRDMA; /* Micro Direct Memory Access Software Reset */
    volatile uint32_t Reserved17; /* Reserved 17 */
    volatile uint32_t SRHIB; /* Hibernation Software Reset */
    volatile uint32_t SRUART; /* Universal Asynchronous Receiver/Transmitter Software Reset */
    volatile uint32_t SRSSI; /* Synchronous Serial Interface Software Reset */
    volatile uint32_t SRI2C; /* Inter-Integrated Circuit Software Reset */
    volatile uint32_t Reserved18; /* Reserved 18 */
    volatile uint32_t SRUSB; /* Universal Serial Bus Software Reset */
    volatile uint32_t Reserved19[2]; /* Reserved 19 */
    volatile uint32_t SRCAN; /* Controller Area Network Software Reset */
    volatile uint32_t SRADC; /* Analog-to-Digital Converter Software Reset */
    volatile uint32_t SRACMP; /* Analog Comparator Software Reset */
    volatile uint32_t SRPWM; /* Pulse Width Modulator Software Reset */
    volatile uint32_t SRQEI; /* Quadrature Encoder Interface Software Reset */
    volatile uint32_t Reserved20[4]; /* Reserved 20 */
    volatile uint32_t SREEPROM; /* EEPROM Software Reset */
    volatile uint32_t SRWTIMER; /* 32/64-Bit Wide General-Purpose Timer Software Reset */
    volatile uint32_t Reserved21[40]; /* Reserved 21 */
    volatile uint32_t RCGCWD; /* Watchdog Timer Run Mode Clock Gating Control */
    volatile uint32_t RCGCTIMER; /* 16/32-Bit General-Purpose Timer Run Mode Clock Gating Control */
    volatile uint32_t RCGCGPIO; /* General-Purpose Input/Output Run Mode Clock Gating Control */
    volatile uint32_t RCGCDMA; /* Micro Direct Memory Access Run Mode Clock Gating Control */
    volatile uint32_t Reserved22; /* Reserved 22 */
    volatile uint32_t RCGCHIB; /* Hibernation Run Mode Clock Gating Control */
    volatile uint32_t RCGCUART; /* Universal Asynchronous Receiver/Transmitter Run Mode Clock Gating Control */
    volatile uint32_t RCGCSSI; /* Synchronous Serial Interface Run Mode Clock Gating Control */
    volatile uint32_t RCGCI2C; /* Inter-Integrated Circuit Run Mode Clock Gating Control */
    volatile uint32_t Reserved23; /* Reserved 23 */
    volatile uint32_t RCGCUSB; /* Universal Serial Bus Run Mode Clock Gating Control */
    volatile uint32_t Reserved24[2]; /* Reserved 24 */
    volatile uint32_t RCGCCAN; /* Controller Area Network Run Mode Clock Gating Control */
    volatile uint32_t RCGCADC; /* Analog-to-Digital Converter Run Mode Clock Gating Control */
    volatile uint32_t RCGCACMP; /* Analog Comparator Run Mode Clock Gating Control */
    volatile uint32_t RCGCPWM; /* Pulse Width Modulator Run Mode Clock Gating Control */
    volatile uint32_t RCGCQEI; /* Quadrature Encoder Interface Run Mode Clock Gating Control */
    volatile uint32_t Reserved25[4]; /* Reserved 25 */
    volatile uint32_t RCGCEEPROM; /* EEPROM Run Mode Clock Gating Control */
    volatile uint32_t RCGCWTIMER; /* 32/64-Bit Wide General-Purpose Timer Run Mode Clock Gating Control */
    volatile uint32_t Reserved26[40]; /* Reserved 26 */
    volatile uint32_t SCGCWD; /* Watchdog Timer Sleep Mode Clock Gating Control */
    volatile uint32_t SCGCTIMER; /* 16/32-Bit General-Purpose Timer Sleep Mode Clock Gating Control */
    volatile uint32_t SCGCGPIO; /* General-Purpose Input/Output Sleep Mode Clock Gating Control */
    volatile uint32_t SCGCDMA; /* Micro Direct Memory Access Sleep Mode Clock Gating Control */
    volatile uint32_t Reserved27; /* Reserved 27 */
    volatile uint32_t SCGCHIB; /* Hibernation Sleep Mode Clock Gating Control */
    volatile uint32_t SCGCUART; /* Universal Asynchronous Receiver/Transmitter Sleep Mode Clock Gating Control */
    volatile uint32_t SCGCSSI; /* Synchronous Serial Interface Sleep Mode Clock Gating Control */
    volatile uint32_t SCGCI2C; /* Inter-Integrated Circuit Sleep Mode Clock Gating Control */
    volatile uint32_t Reserved28; /* Reserved 28 */
    volatile uint32_t SCGCUSB; /* Universal Serial Bus Sleep Mode Clock Gating Control */
    volatile uint32_t Reserved29[2]; /* Reserved 29 */
    volatile uint32_t SCGCCAN; /* Controller Area Network Sleep Mode Clock Gating Control */
    volatile uint32_t SCGCADC; /* Analog-to-Digital Converter Sleep Mode Clock Gating Control */
    volatile uint32_t SCGCACMP; /* Analog Comparator Sleep Mode Clock Gating Control */
    volatile uint32_t SCGCPWM; /* Pulse Width Modulator Sleep Mode Clock Gating Control */
    volatile uint32_t SCGCQEI; /* Quadrature Encoder Interface Sleep Mode Clock Gating Control */
    volatile uint32_t Reserved30[4]; /* Reserved 30 */
    volatile uint32_t SCGCEEPROM; /* EEPROM Sleep Mode Clock Gating Control */
    volatile uint32_t SCGCWTIMER; /* 32/64-Bit Wide General-Purpose Timer Sleep Mode Clock Gating Control */
    volatile uint32_t Reserved31[40]; /* Reserved 31 */
    volatile uint32_t DCGCWD; /* Watchdog Timer Deep-Sleep Mode Clock Gating Control */
    volatile uint32_t DCGCTIMER; /* 16/32-Bit General-Purpose Timer Deep-Sleep Mode Clock Gating Control */
    volatile uint32_t DCGCGPIO; /* General-Purpose Input/Output Deep-Sleep Mode Clock Gating Control */
    volatile uint32_t DCGCDMA; /* Micro Direct Memory Access Deep-Sleep Mode Clock Gating Control */
    volatile uint32_t Reserved32; /* Reserved 32 */
    volatile uint32_t DCGCHIB; /* Hibernation Deep-Sleep Mode Clock Gating Control */
    volatile uint32_t DCGCUART; /* Universal Asynchronous Receiver/Transmitter Deep-Sleep Mode Clock Gating Control */
    volatile uint32_t DCGCSSI; /* Synchronous Serial Interface Deep-Sleep Mode Clock Gating Control */
    volatile uint32_t DCGCI2C; /* Inter-Integrated Circuit Deep-Sleep Mode Clock Gating Control */
    volatile uint32_t Reserved33; /* Reserved 33 */
    volatile uint32_t DCGCUSB; /* Universal Serial Bus Deep-Sleep Mode Clock Gating Control */
    volatile uint32_t Reserved34[2]; /* Reserved 34 */
    volatile uint32_t DCGCCAN; /* Controller Area Network Deep-Sleep Mode Clock Gating Control */
    volatile uint32_t DCGCADC; /* Analog-to-Digital Converter Deep-Sleep Mode Clock Gating Control */
    volatile uint32_t DCGCACMP; /* Analog Comparator Deep-Sleep Mode Clock Gating Control */
    volatile uint32_t DCGCPWM; /* Pulse Width Modulator Deep-Sleep Mode Clock Gating Control */
    volatile uint32_t DCGCQEI; /* Quadrature Encoder Interface Deep-Sleep Mode Clock Gating Control */
    volatile uint32_t Reserved35[4]; /* Reserved 35 */
    volatile uint32_t DCGCEEPROM; /* EEPROM Deep-Sleep Mode Clock Gating Control */
    volatile uint32_t DCGCWTIMER; /* 32/64-Bit Wide General-Purpose Timer Deep-Sleep Mode Clock Gating Control */
    volatile uint32_t Reserved36[104]; /* Reserved 36 */
    volatile uint32_t PRWD; /* Watchdog Timer Peripheral Ready */
    volatile uint32_t PRTIMER; /* 16/32-Bit General-Purpose Timer Peripheral Ready */
    volatile uint32_t PRGPIO; /* General-Purpose Input/Output Peripheral Ready */
    volatile uint32_t PRDMA; /* Micro Direct Memory Access Peripheral Ready */
    volatile uint32_t Reserved37; /* Reserved 37 */
    volatile uint32_t PRHIB; /* Hibernation Peripheral Ready */
    volatile uint32_t PRUART; /* Universal Asynchronous Receiver/Transmitter Peripheral Ready */
    volatile uint32_t PRSSI; /* Synchronous Serial Interface Peripheral Ready */
    volatile uint32_t PRI2C; /* Inter-Integrated Circuit Peripheral Ready */
    volatile uint32_t Reserved38; /* Reserved 38 */
    volatile uint32_t PRUSB; /* Universal Serial Bus Peripheral Ready */
    volatile uint32_t Reserved39[2]; /* Reserved 39 */
    volatile uint32_t PRCAN; /* Controller Area Network Peripheral Ready */
    volatile uint32_t PRADC; /* Analog-to-Digital Converter Peripheral Ready */
    volatile uint32_t PRACMP; /* Analog Comparator Peripheral Ready */
    volatile uint32_t PRPWM; /* Pulse Width Modulator Peripheral Ready */
    volatile uint32_t PRQEI; /* Quadrature Encoder Interface Peripheral Ready */
    volatile uint32_t Reserved40[4]; /* Reserved 40 */
    volatile uint32_t PREEPROM; /* EEPROM Peripheral Ready */
    volatile uint32_t PRWTIMER; /* 32/64-Bit Wide General-Purpose Timer Peripheral Ready */
} SystemCtl_reg_mape;

#define SYSCTL ((SystemCtl_reg_mape*)system_control_Base)


/******************************************** GPIO Base Definition ***************************************************/
#define GPIOA_BASE 0x40004000UL
#define GPIOB_BASE 0x40005000UL
#define GPIOC_BASE 0x40006000UL
#define GPIOD_BASE 0x40007000UL
#define GPIOE_BASE 0x40024000UL
#define GPIOF_BASE 0x40025000UL

/******************************************** STRUCT TO POINT AT BASE ADDRESES GPIO ***************************************************/
typedef struct{
    volatile uint32_t GPIODATA[256]; //GPIO data register
    volatile uint32_t GPIODIR; //GPIO direction register
    volatile uint32_t GPIOIS; //GPIO Interrupt Sense
    volatile uint32_t GPIOIBE; //GPIO interrupt both edges
    volatile uint32_t GPIOIEV; //GPIO Interrupt Event
    volatile uint32_t GPIOIM; //GPIO interrupt mask
    volatile uint32_t GPIORIS; //GPIO raw interrupt status
    volatile uint32_t GPIOMIS; //GPIO masked interrupt status states
    volatile uint32_t GPIOICR; //GPIO interrupt clear
    volatile uint32_t GPIOAFSEL; //gpio alternate function setting
    volatile uint32_t rserved[55]; /* reserved 1  still under investigation*/
    volatile uint32_t GPIODR2R;  //GPIO 2-mA Drive Select
    volatile uint32_t GPIODR4R; //GPIO 4-mA Drive Select
    volatile uint32_t GPIODR8R; //GPIO 8-mA Drive Select
    volatile uint32_t GPIOODR; //GPIO Open Drain Select
    volatile uint32_t GPIOPUR; //GPIO Open Drain Select
    volatile uint32_t GPIOPDR; //GPIOPDR
    volatile uint32_t GPIOSLR; //GPIO Slew Rate Control Select
    volatile uint32_t GPIODEN; //GPIO Digital Enable
    volatile uint32_t GPIOLOCK; //GPIO LOCK
    volatile uint32_t GPIOCR; //GPIO commit
    volatile uint32_t GPIOAMSEL; //GPIO analog mode select
    volatile uint32_t GPIOPCTL ; //GPIO Port Control
    volatile uint32_t GPIOADCCTL;//GPIO ADC Control
    volatile uint32_t GPIODMACTL;//GPIO DMA Control
    volatile uint32_t reserved2[678]; /* reserved 2  still under investigation ###*/
    volatile uint32_t GPIOPeriphID4; //GPIO Peripheral Identification 4
    volatile uint32_t GPIOPeriphID5 ;//GPIO Peripheral Identification 5
    volatile uint32_t GPIOPeriphID6 ;//GPIO Peripheral Identification 6
    volatile uint32_t GPIOPeriphID7 ;//GPIO Peripheral Identification 7
    volatile uint32_t GPIOPeriphID0 ;//GPIO Peripheral Identification 0
    volatile uint32_t GPIOPeriphID1 ;//GPIO Peripheral Identification 1
    volatile uint32_t GPIOPeriphID2 ;//GPIO Peripheral Identification 2
    volatile uint32_t GPIOPeriphID3 ;//GPIO Peripheral Identification 3
} gpio_reg_mape;
/******************************************** pointer to structs of type gpio_reg_mape pointing at the base addreses***************************************************/
#define GPIOA ((gpio_reg_mape*)GPIOA_BASE)
#define GPIOB ((gpio_reg_mape*)GPIOB_BASE)
#define GPIOC ((gpio_reg_mape*)GPIOC_BASE)
#define GPIOD ((gpio_reg_mape*)GPIOD_BASE)
#define GPIOE ((gpio_reg_mape*)GPIOE_BASE)
#define GPIOF ((gpio_reg_mape*)GPIOF_BASE)






#endif /* MCAL_REGISTER_MAP_H_ */
