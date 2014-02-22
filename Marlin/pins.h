#ifndef PINS_H
#define PINS_H

#define X_MS1_PIN -1
#define X_MS2_PIN -1
#define Y_MS1_PIN -1
#define Y_MS2_PIN -1
#define Z_MS1_PIN -1
#define Z_MS2_PIN -1
#define E0_MS1_PIN -1
#define E0_MS2_PIN -1
#define E1_MS1_PIN -1
#define E1_MS2_PIN -1
#define DIGIPOTSS_PIN -1

#define KNOWN_BOARD 1
/*****************************************************************
* MAKEiT pin assignment
******************************************************************/

#ifndef __AVR_ATmega2560__
 #error Oops!  Make sure you have 'Arduino Mega' selected from the 'Tools -> Boards' menu.
#endif 

 #define LARGE_FLASH true  
 
#define X_STEP_PIN 33  //57
#define X_DIR_PIN 34 //56      
#define X_MAX_PIN -1      
#define X_MIN_PIN 16 //13    
#define X_ENABLE_PIN 32 //58  

#define Y_STEP_PIN 36 //54 
#define Y_DIR_PIN 37 //53     
#define Y_MIN_PIN -1     
#define Y_MAX_PIN 22 //78  
#define Y_ENABLE_PIN 35 //55  

#define Z_STEP_PIN 41  //51
#define Z_DIR_PIN 38 //50     
#define Z_MAX_PIN -1      
#define Z_MIN_PIN 24 //76
#define Z_ENABLE_PIN 40  //52

#define Z2_STEP_PIN        19  //45
#define Z2_DIR_PIN         42  //42
#define Z2_MAX_PIN         -1      
#define Z2_MIN_PIN         23 //77
#define Z2_ENABLE_PIN      18  //46

#define HEATER_BED_PIN     49  //35
#define TEMP_BED_PIN       15  //82

#define HEATER_0_PIN       12  //25
#define TEMP_0_PIN          5 //92

#define HEATER_1_PIN       13 //26
#define TEMP_1_PIN          6 //91

#define HEATER_2_PIN       -1 //10 23
#define TEMP_2_PIN         -1 //8  89

#define HEATER_3_PIN       -1 //11 24
#define TEMP_3_PIN         -1 //7  90

#define E0_STEP_PIN        44  //40
#define E0_DIR_PIN         45  //39
#define E0_ENABLE_PIN      43  //41

#define E1_STEP_PIN        47  //37
#define E1_DIR_PIN         48  //36
#define E1_ENABLE_PIN      46  //38

#define SDPOWER            -1
#define SDSS               53  //19
#define LED_PIN            -1
#define FAN_PIN            7  //16
#define PS_ON_PIN          -1
#define KILL_PIN           -1
#define SUICIDE_PIN        68  //83 PIN that has to be turned on right after start, to keep power flowing.

  //arduino pin witch triggers an piezzo beeper
    #define BEEPER 27  //73   

    #define LCD_PINS_RS     26  //74
    #define LCD_PINS_ENABLE 25  //75
    #define LCD_PINS_D4     14  //64
    #define LCD_PINS_D5     39  //70
    #define LCD_PINS_D6     29  //71
    #define LCD_PINS_D7     28  //72
    
    //buttons are directly attached
    #define BTN_EN1         30  //60
    #define BTN_EN2         15  //63
    #define BTN_ENC         31  //59
    
    #define SDCARDDETECT     3  //7


#ifndef KNOWN_BOARD
#error Unknown MOTHERBOARD value in configuration.h
#endif

//List of pins which to ignore when asked to change by gcode, 0 and 1 are RX and TX, do not mess with those!
#define _E0_PINS E0_STEP_PIN, E0_DIR_PIN, E0_ENABLE_PIN, HEATER_0_PIN,
#if EXTRUDERS > 1
  #define _E1_PINS E1_STEP_PIN, E1_DIR_PIN, E1_ENABLE_PIN, HEATER_1_PIN,
#else
  #define _E1_PINS
#endif
#if EXTRUDERS > 2
  #define _E2_PINS E2_STEP_PIN, E2_DIR_PIN, E2_ENABLE_PIN, HEATER_2_PIN,
#else
  #define _E2_PINS
#endif

#ifdef X_STOP_PIN
  #if X_HOME_DIR < 0
    #define X_MIN_PIN X_STOP_PIN
    #define X_MAX_PIN -1
  #else
    #define X_MIN_PIN -1
    #define X_MAX_PIN X_STOP_PIN
  #endif
#endif

#ifdef Y_STOP_PIN
  #if Y_HOME_DIR < 0
    #define Y_MIN_PIN Y_STOP_PIN
    #define Y_MAX_PIN -1
  #else
    #define Y_MIN_PIN -1
    #define Y_MAX_PIN Y_STOP_PIN
  #endif
#endif

#ifdef Z_STOP_PIN
  #if Z_HOME_DIR < 0
    #define Z_MIN_PIN Z_STOP_PIN
    #define Z_MAX_PIN -1
  #else
    #define Z_MIN_PIN -1
    #define Z_MAX_PIN Z_STOP_PIN
  #endif
#endif

#ifdef DISABLE_MAX_ENDSTOPS
#define X_MAX_PIN          -1
#define Y_MAX_PIN          -1
#define Z_MAX_PIN          -1
#endif

#ifdef DISABLE_MIN_ENDSTOPS
#define X_MIN_PIN          -1
#define Y_MIN_PIN          -1
#define Z_MIN_PIN          -1
#endif

#define SENSITIVE_PINS {0, 1, X_STEP_PIN, X_DIR_PIN, X_ENABLE_PIN, X_MIN_PIN, X_MAX_PIN, Y_STEP_PIN, Y_DIR_PIN, Y_ENABLE_PIN, Y_MIN_PIN, Y_MAX_PIN, Z_STEP_PIN, Z_DIR_PIN, Z_ENABLE_PIN, Z_MIN_PIN, Z_MAX_PIN, PS_ON_PIN, \
                        HEATER_BED_PIN, FAN_PIN,                  \
                        _E0_PINS _E1_PINS _E2_PINS             \
                        analogInputToDigitalPin(TEMP_0_PIN), analogInputToDigitalPin(TEMP_1_PIN), analogInputToDigitalPin(TEMP_2_PIN), analogInputToDigitalPin(TEMP_BED_PIN) }
#endif

