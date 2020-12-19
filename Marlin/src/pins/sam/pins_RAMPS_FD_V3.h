/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * RAMPS-FD
 *
 * Use 4k7 thermistor tables
 */

#if NOT_TARGET(__SAM3X8E__)
  #error "Oops! Select 'Arduino Due' in 'Tools > Board.'"
#endif

#ifndef BOARD_INFO_NAME
  #define BOARD_INFO_NAME "RAMPS-FD v3"
#endif

//
//EEPROM
//
#define I2C_EEPROM
#define E2END 0xFFFF // 64K in a 24C512
#define MARLIN_EEPROM_SIZE 512

//Marius 21.03.2020
#ifndef TMC_SW_MOSI
  #define TMC_SW_MOSI 51
#endif

#ifndef TMC_SW_MISO
  #define TMC_SW_MISO 50
#endif

#ifndef TMC_SW_SCK
  #define TMC_SW_SCK 52
#endif
//Marius 21.03.2020

#ifndef PS_ON_PIN
  #define PS_ON_PIN        53
#endif
/*
#ifndef FILWIDTH_PIN
  #define FILWIDTH_PIN      5   // Analog Input on AUX2
#endif
*/
//
// Servos
//
#define SERVO0_PIN          7
#define SERVO1_PIN          6
#define SERVO2_PIN          5
#define SERVO3_PIN          3

//
// Limit Switches
//
#define X_MIN_PIN          22
#define X_MAX_PIN          30
#define Y_MIN_PIN          24
#define Y_MAX_PIN          38
#define Z_MIN_PIN          26
#define Z_MAX_PIN          34

//
// Steppers
//
#define X_STEP_PIN         63
#define X_DIR_PIN          62
#define X_ENABLE_PIN       48
#ifndef X_CS_PIN
  #define X_CS_PIN         69 //Marius 21.03.2020
#endif

#define Y_STEP_PIN         65
#define Y_DIR_PIN          64
#define Y_ENABLE_PIN       46
#ifndef Y_CS_PIN
  #define Y_CS_PIN         61 //Marius 21.03.2020
#endif

#define Z_STEP_PIN         67
#define Z_DIR_PIN          66
#define Z_ENABLE_PIN       44
#ifndef Z_CS_PIN
  #define Z_CS_PIN         60 //Marius 21.03.2020
#endif

#define E0_STEP_PIN        36
#define E0_DIR_PIN         28
#define E0_ENABLE_PIN      42
#ifndef E0_CS_PIN
  #define E0_CS_PIN        58 //Marius 21.03.2020
#endif

#define E1_STEP_PIN        43
#define E1_DIR_PIN         41
#define E1_ENABLE_PIN      39
#ifndef E1_CS_PIN
  #define E1_CS_PIN        59 //Marius 21.03.2020
#endif

#define Z2_STEP_PIN        43
#define Z2_DIR_PIN         41
#define Z2_ENABLE_PIN      39
#ifndef Z2_CS_PIN
  #define Z2_CS_PIN        59 //Marius 21.03.2020
#endif

#define E2_STEP_PIN        32
#define E2_DIR_PIN         47
#define E2_ENABLE_PIN      45
#ifndef E2_CS_PIN
  #define E2_CS_PIN        68 //Marius 21.03.2020
#endif

//
// Temperature Sensors
//
#define TEMP_0_PIN          2   // Analog Input
#define TEMP_1_PIN          3   // Analog Input
#define TEMP_2_PIN          1   // Analog Input
#define TEMP_BED_PIN        0   // Analog Input

//
// Heaters / Fans
//
#define HEATER_0_PIN        9
#define HEATER_1_PIN       10
#define HEATER_2_PIN       11
#define HEATER_BED_PIN      8

#ifndef FAN_PIN
  #define FAN_PIN          2  //Marius 21.03.2020
#endif

//
// Misc. Functions
//
#define SDSS                4
#define LED_PIN            13

//
// LCD / Controller
//Use RAMPS FD LCD Adapter V1.0 or later
//
//#if HAS_SPI_LCD

#if ANY(RADDS_DISPLAY, REPRAP_DISCOUNT_SMART_CONTROLLER, REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER)
    #define BEEPER_PIN      37
    #define LCD_PINS_D4     27
    #define LCD_PINS_D5     14
    #define LCD_PINS_D6     25
    #define LCD_PINS_D7     15
    #define SD_DETECT_PIN   49 
    #define LCD_PINS_RS     23
    #define LCD_PINS_ENABLE 29
#endif
//#endif

#if HAS_TMC220x
  /**
   * TMC2208/TMC2209 stepper drivers
   *
   * Hardware serial communication ports.
   * If undefined software serial is used according to the pins below
   */
  //#define X_HARDWARE_SERIAL  Serial1
  //#define X2_HARDWARE_SERIAL Serial1
  //#define Y_HARDWARE_SERIAL  Serial1
  //#define Y2_HARDWARE_SERIAL Serial1
  #define Z_HARDWARE_SERIAL  Serial1
  #define Z2_HARDWARE_SERIAL Serial2
  //#define E0_HARDWARE_SERIAL Serial2
  //#define E1_HARDWARE_SERIAL Serial2
  //#define E2_HARDWARE_SERIAL Serial2
  //#define E3_HARDWARE_SERIAL Serial1
  //#define E4_HARDWARE_SERIAL Serial1
#endif