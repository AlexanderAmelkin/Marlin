/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
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

/**
 * GTM32Pro pin assignments
 */

#ifndef __STM32F1__
  #error "Oops! You must be compiling for STM32."
#endif

#define BOARD_NAME "GTM32PRO"

//
// GTM32Pro uses JTAG pins as GPIO to drive axis Y and Z steppers
//
#define DISABLE_JTAG

// Enable EEPROM Emulation for this board as it doesn't have EEPROM
#define FLASH_EEPROM_EMULATION
#define E2END 0xFFF // EEPROM end address (4kB), required for persistent_store_flash.cpp

//
// SD Card
//

// Override the settings provided by STM32F1 HAL
// (why does it define these at all?)
#undef SS_PIN
#undef SCK_PIN
#undef MOSI_PIN
#undef MISO_PIN

#ifdef REPRAP_DISCOUNT_SMART_CONTROLLER
  // The card on J2 FRC connector (LCD2004 Control Panel)
  #define SS_PIN             PC11
  #define SCK_PIN            PC12
  #define MOSI_PIN           PD2
  #define MISO_PIN           PC8
  #define SD_DETECT_PIN      PC7
#else
  // GTM32Pro also has a microSD card connector on the bottom
  #define SS_PIN             PA4
  #define SCK_PIN            PA5
  #define MOSI_PIN           PA7
  #define MISO_PIN           PA6
  // This connector doesn't have a card detect pin connected anywhere
  #define SD_DETECT_PIN      -1
#endif

// Not using LCD_SDSS for SD Card on LCD panel because it uses
// different pins than the bottom microSD connector and such a mode
// with two SD cards on different pins is not supported in Marlin
// as of 2018/05/28. Hence, only a single card can be used and thus
// only SDSS is set here.
#define SDSS               SS_PIN

//
// Limit Switches
//
#define X_MIN_PIN          PE5 // Pins 15,17 of ENDSTOPS connector
#define X_MAX_PIN          PE4 // Pins 16,18 of ENDSTOPS connector
#define Y_MIN_PIN          PE3 // Pins 9,11 of ENDSTOPS connector
#define Y_MAX_PIN          PE2 // Pins 10,12 of ENDSTOPS connector
#define Z_MIN_PIN          PE1 // Pins 3,5 of ENDSTOPS connector
#define Z_MAX_PIN          PE0 // Pins 4,6 of ENDSTOPS connector

//
// Steppers
//
#define X_ENABLE_PIN       PA8
#define X_STEP_PIN         PC6
#define X_DIR_PIN          PD13

#define Y_ENABLE_PIN       PA15
#define Y_STEP_PIN         PA12
#define Y_DIR_PIN          PA11

#define Z_ENABLE_PIN       PB3
#define Z_STEP_PIN         PD6
#define Z_DIR_PIN          PD3

#define E0_ENABLE_PIN      PC15
#define E0_STEP_PIN        PC14
#define E0_DIR_PIN         PC13

#define E1_ENABLE_PIN      PA1
#define E1_STEP_PIN        PA0
#define E1_DIR_PIN         PB6

#define E2_ENABLE_PIN      PC4
#define E2_STEP_PIN        PB2
#define E2_DIR_PIN         PB11

//
// Temperature Sensors
//
#define TEMP_0_PIN         PC2   // Analog Input (HOTEND0 thermistor)
#define TEMP_1_PIN         PC1   // Analog Input (HOTEND1 thermistor)
#define TEMP_2_PIN         PC0   // Analog Input (HOTEND2 thermistor)
#define TEMP_BED_PIN       PC3   // Analog Input (BED thermistor)

//
// Heaters
//
#define HEATER_0_PIN       PB0   // HOTEND0 MOSFET
#define HEATER_1_PIN       PB5   // HOTEND1 MOSFET
#define HEATER_2_PIN       PB4   // HOTEND2 MOSFET
#define HEATER_BED_PIN     PB1   // BED MOSFET

//
// Fans
//
#define E0_AUTO_FAN_PIN    PB9   // Extruder 0 Fan
#define FAN0_PIN           PB8   // Extruder 1 Fan, works as part fan 0
#define FAN1_PIN           PB7   // Extruder 2 Fan, works as part fan 1

//
// Buzzer/Speaker
//
#define BEEPER_PIN         PE12  // Buzzer on J2 FRC connector

//
// Rotary Encoder on J2 FRC connector
//
#define BTN_EN1            PE8
#define BTN_EN2            PE9
#define BTN_ENC            PE13

#ifdef REPRAP_DISCOUNT_SMART_CONTROLLER
  //
  // LCD display on J2 FRC
  // Geeetech's LCD2004A Control Panel is very much like
  // RepRapDiscount Smart Controller
  //
  #define LCD_PINS_RS        PE6
  #define LCD_PINS_ENABLE    PE14
  #define LCD_PINS_D4        PD8
  #define LCD_PINS_D5        PD9
  #define LCD_PINS_D6        PD10
  #define LCD_PINS_D7        PE15
#else
  //
  // Anoter option that GTM32Pro support is a serial port LCD Display
  //
  // Such LCDs aren't supported by Marlin though as of 2018/05/28
  //#define LCD_UART_TX        PD8
  //#define LCD_UART_RX        PD9
#endif

//
// Misc. Functions
//
#define LED_PIN            PD12
