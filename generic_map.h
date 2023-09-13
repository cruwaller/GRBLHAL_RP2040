/*
  generic_map.h - driver code for RP2040 ARM processors

  Part of grblHAL

  Copyright (c) 2021-2023 Terje Io
  Copyright (c) 2021 Volksolive

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

#if TRINAMIC_ENABLE
#error Trinamic plugin not supported!
#endif

#if 1 < N_ABC_MOTORS
#error "Axis configuration is not supported!"
#endif

// Define step pulse output pins.
#define STEP_PORT               GPIO_PIO  // N_AXIS pin PIO SM
#define STEP_PINS_BASE          2         // N_AXIS number of consecutive pins are used by PIO

// Define step direction output pins.
#define DIRECTION_PORT          GPIO_OUTPUT
#define X_DIRECTION_PIN         6
#define Y_DIRECTION_PIN         7
#define Z_DIRECTION_PIN         8
#define DIRECTION_OUTMODE       GPIO_SHIFT5

// Define stepper driver enable/disable output pin.
#define ENABLE_PORT             GPIO_OUTPUT
#define STEPPERS_ENABLE_PIN     14

// Define homing/hard limit switch input pins.
#define LIMIT_PORT              GPIO_IN  // Not used!
#define X_LIMIT_PIN             10
#define Y_LIMIT_PIN             11
#define Z_LIMIT_PIN             12
#define LIMIT_INMODE            GPIO_MAP

// Define spindle enable and spindle direction output pins.
#define SPINDLE_PORT            GPIO_OUTPUT
#define SPINDLE_ENABLE_PIN      26
#define SPINDLE_DIRECTION_PIN   27

// Define spindle PWM output pin.
#define SPINDLE_PWM_PORT        GPIO_OUTPUT
#define SPINDLE_PWM_PIN         28

// Define flood and mist coolant enable output pins.
#define COOLANT_PORT            GPIO_OUTPUT
//#define COOLANT_FLOOD_PIN       16
#define COOLANT_MIST_PIN        22

// Define user-control controls (cycle start, reset, feed hold) input pins.
//#define RESET_PIN               20
#define FEED_HOLD_PIN           21
//#define CYCLE_START_PIN         22
#if SAFETY_DOOR_ENABLE
#define SAFETY_DOOR_PIN         21
#endif

// Define probe switch input pin.
#define PROBE_PIN               15


#define SD_CS_PIN           17
#define SPI_PORT            0
#define SPI_SCK_PIN         18
#define SPI_MOSI_PIN        19
#define SPI_MISO_PIN        16


// Define ganged Y axis pins
#if N_ABC_MOTORS > 0
  #define M3_AVAILABLE

  //#define M3_STEP_PIN         0 // Not referenced by driver code
  #define M3_DIRECTION_PIN    9 // Not referenced by driver code
  #define M3_LIMIT_PIN        13
  //#define M3_ENABLE_PIN       0 // Not referenced by driver code
#endif

#define STEP_PULSE_LATENCY 4.0f
