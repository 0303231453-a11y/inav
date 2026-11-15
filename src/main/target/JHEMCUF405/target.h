/*
 * This file is part of INAV.
 *
 * INAV is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * INAV is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with INAV.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define TARGET_BOARD_IDENTIFIER "JH45"
#define USBD_PRODUCT_STRING     "JHEMCUF405"

// LED0 / BEEPER: PC14 / PC13 deu ghi FREE trong bang chan nen tat di.
// Bang chan ghi BEEPER o PA11/PA12 nhung day la chan USB (D-/D+), KHONG gan duoc.
// Neu board co coi/LED that, bo comment va sua dung chan:
//#define LED0                    PC14
//#define BEEPER                  PC13
//#define BEEPER_INVERTED

// *************** SPI2 Gyro & ACC (MPU6500) + Baro ***
// SPI2: SCK = PB13, MISO = PC2 (co tro 1k xuong GND), MOSI = PC3
// Gyro MPU6500: CS = PB12
// Baro: CS = PC1
#define USE_SPI
#define USE_SPI_DEVICE_2
#define SPI2_SCK_PIN            PB13
#define SPI2_MISO_PIN           PC2
#define SPI2_MOSI_PIN           PC3

#define USE_IMU_MPU6500
#define IMU_MPU6500_ALIGN       CW0_DEG   // sai huong thi doi trong Configurator (tab Configuration)
#define MPU6500_CS_PIN          PB12
#define MPU6500_SPI_BUS         BUS_SPI2

// Khong co chan ngat (INT) cho gyro trong bang chan
#define USE_EXTI

// *************** I2C2 /Baro/Mag ********************
#define USE_I2C
#define USE_I2C_DEVICE_2
#define I2C2_SCL                PB10
#define I2C2_SDA                PB11

#define USE_BARO
#define BARO_I2C_BUS            BUS_I2C2
#define USE_BARO_BMP280
#define USE_BARO_MS5611
#define USE_BARO_BMP085
#define USE_BARO_DPS310
#define USE_BARO_SPL06
// Baro SPI (neu baro that gan SPI2 / CS = PC1)
#define BMP280_SPI_BUS          BUS_SPI2
#define BMP280_CS_PIN           PC1
#define MS5611_SPI_BUS          BUS_SPI2
#define MS5611_CS_PIN           PC1

#define USE_MAG
#define MAG_I2C_BUS             BUS_I2C2
#define USE_MAG_ALL

#define USE_RANGEFINDER
#define USE_RANGEFINDER_HCSR04_I2C
#define RANGEFINDER_I2C_BUS     BUS_I2C2
#define PITOT_I2C_BUS           BUS_I2C2
#define TEMPERATURE_I2C_BUS     BUS_I2C2

// *************** OSD *******************************
// Bang chan chi ghi "OSD OUT" o PB9, khong co SPI cho MAX7456 nen bo MAX7456.
// OSD qua MSP DisplayPort van dung duoc.
#define USE_OSD

// *************** SD card (SDIO) *******************
// PC8..PC12 + PD2 la bo chan SDIO (ghi "FLASH" trong bang chan)
#define USE_SDCARD
#define USE_SDCARD_SDIO
#define SDCARD_SDIO_DEVICE      SDIODEV_1
#define SDCARD_SDIO_4BIT
#define ENABLE_BLACKBOX_LOGGING_ON_SDCARD_BY_DEFAULT

// *************** UART *****************************
// PA11/PA12 la USB, khong gan chuc nang khac.
// VBUS sensing (PA8) bo di vi bang chan ghi PA8 FREE.
#define USB_IO
#define USE_VCP

#define USE_UART1
#define UART1_TX_PIN            PB6
#define UART1_RX_PIN            PB7

#define USE_UART2
#define UART2_TX_PIN            PA2
#define UART2_RX_PIN            PA3

#define USE_UART4
#define UART4_TX_PIN            PA0
#define UART4_RX_PIN            PA1

#define SERIAL_PORT_COUNT       4

#define DEFAULT_RX_TYPE         RX_TYPE_SERIAL
#define SERIALRX_PROVIDER       SERIALRX_SBUS
#define SERIALRX_UART           SERIAL_PORT_USART2

// *************** ADC ***************************
// GIA DINH: "SERIAL CH1/CH2" o PC4/PC5 la ADC (PC4 = ADC12_IN14, PC5 = ADC12_IN15)
#define USE_ADC
#define ADC_INSTANCE                ADC1
#define ADC1_DMA_STREAM             DMA2_Stream0
#define ADC_CHANNEL_1_PIN           PC4
#define ADC_CHANNEL_2_PIN           PC5
#define VBAT_ADC_CHANNEL            ADC_CHN_1
#define CURRENT_METER_ADC_CHANNEL   ADC_CHN_2

// ***************  OTHERS *************************
#define DEFAULT_FEATURES        (FEATURE_TX_PROF_SEL | FEATURE_CURRENT_METER | FEATURE_VBAT | FEATURE_TELEMETRY | FEATURE_SOFTSERIAL)
#define CURRENT_METER_SCALE     250

#define USE_DSHOT
#define USE_ESC_SENSOR

#define USE_SERIAL_4WAY_BLHELI_INTERFACE

#define TARGET_IO_PORTA         0xffff
#define TARGET_IO_PORTB         0xffff
#define TARGET_IO_PORTC         0xffff
#define TARGET_IO_PORTD         0xffff

#define MAX_PWM_OUTPUT_PORTS    4
