/**
 * Sanguinololu board pin assignments
 */

#if !defined(__AVR_ATmega644P__) && !defined(__AVR_ATmega1284P__)
  #error Oops!  Make sure you have 'Sanguino' selected from the 'Tools -> Boards' menu.
#endif



#define KEY1  27
#define LED1  10

#define KEY2  28
#define LED2  11

#define KEY3  29
#define LED3  16

#define KEY4  30
#define LED4  17



/*
#define PRINT_START_PIN    30        //开始打印键
#define PRINT_LED          17

#define Z_HOME_PIN           29
#define HOME_LED           16

#define FEED_PIN           28
#define FEED_LED           11

#define RETRACT_PIN        27
#define RETRACT_LED        10 */

#define PRINT_START_PIN    27        //开始打印键
#define PRINT_LED          10

#define Z_HOME_PIN         30
#define HOME_LED           17

#define FEED_PIN           28
#define FEED_LED           11

#define RETRACT_PIN        29
#define RETRACT_LED        16





#define X_STEP_PIN         15
#define X_DIR_PIN          21
#define X_STOP_PIN         18

#define Y_STEP_PIN         22
#define Y_DIR_PIN          23
#define Y_STOP_PIN         19

#define Z_STEP_PIN          3
#define Z_DIR_PIN           2
#define Z_STOP_PIN         20

#define E0_STEP_PIN         1
#define E0_DIR_PIN          0

#define FAN0_PIN            4

#define FAN_PIN            4

#if MB(AZTEEG_X1) || MB(STB_11) || MB(MELZI)
  #define FAN_PIN           4 // Works for Panelolu2 too
  #if MB(MELZI)
    #define LED_PIN        27 // On some broken versions of the Sanguino libraries the pin definitions are wrong, so LED_PIN needs to be 28. But you should upgrade your Sanguino libraries! See #368.
  #elif MB(STB_11)
    #define LCD_PIN_BL     17 // LCD backlight LED
  #endif
#endif

#if ENABLED(Z_PROBE_SLED)
  #define SLED_PIN         -1
#endif

#define PS_ON_PIN          -1
#define KILL_PIN           -1

#define HEATER_0_PIN       13 // (extruder)
#define HEATER_1_PIN       -1
#define HEATER_2_PIN       -1

#if ENABLED(SANGUINOLOLU_V_1_2)

  #define HEATER_BED_PIN   12 // (bed)
  #define X_ENABLE_PIN     14
  #define Y_ENABLE_PIN     14
  #define Z_ENABLE_PIN     26
  #define E0_ENABLE_PIN    14

  #if ENABLED(LCD_I2C_PANELOLU2)
    #define FAN_PIN         4 // Uses Transistor1 (PWM) on Panelolu2's Sanguino Adapter Board to drive the fan
  #endif

#else

  #define HEATER_BED_PIN   14  // (bed)
  #define X_ENABLE_PIN     -1
  #define Y_ENABLE_PIN     -1
  #define Z_ENABLE_PIN     -1
  #define E0_ENABLE_PIN    -1

#endif

#define TEMP_0_PIN          7   // MUST USE ANALOG INPUT NUMBERING NOT DIGITAL OUTPUT NUMBERING!!!!!!!!! (pin 33 extruder)
#define TEMP_1_PIN         -1
#define TEMP_2_PIN         -1
#define TEMP_BED_PIN        6   // MUST USE ANALOG INPUT NUMBERING NOT DIGITAL OUTPUT NUMBERING!!!!!!!!! (pin 34 bed)
#define SDPOWER            -1
#define SDSS               31

/**
 * On some broken versions of the Sanguino libraries the pin definitions are wrong,
 * which then needs SDSS as pin 24. But you should upgrade your Sanguino libraries! See #368.
 */
//#define SDSS               24

#if ENABLED(ULTRA_LCD) && ENABLED(NEWPANEL)

  // No buzzer installed
  #define BEEPER_PIN 30

  // LCD Pins
  #if ENABLED(DOGLCD)

    #if ENABLED(U8GLIB_ST7920) //SPI GLCD 12864 ST7920 ( like [www.digole.com] ) For Melzi V2.0

      #if MB(MELZI) // Melzi board
        #define LCD_PINS_RS     30 //CS chip select /SS chip slave select
        #define LCD_PINS_ENABLE 29 //SID (MOSI)
        #define LCD_PINS_D4     17 //SCK (CLK) clock
        #define BEEPER_PIN      27 // Pin 27 is taken by LED_PIN, but Melzi LED does nothing with Marlin so this can be used for BEEPER_PIN. You can use this pin with M42 instead of BEEPER_PIN.
      #else         // Sanguinololu 1.3
        #define LCD_PINS_RS      4
        #define LCD_PINS_ENABLE 17
        #define LCD_PINS_D4     30
        #define LCD_PINS_D5     29
        #define LCD_PINS_D6     28
        #define LCD_PINS_D7     27
      #endif

    #else // DOGM SPI LCD Support

      #define DOGLCD_A0         27
      #define DOGLCD_CS         29
      #define LCD_CONTRAST       1

    #endif

    // Uncomment screen orientation
    #define LCD_SCREEN_ROT_0
    //#define LCD_SCREEN_ROT_90
    //#define LCD_SCREEN_ROT_180
    //#define LCD_SCREEN_ROT_270

  #else // !DOGLCD - Standard Hitachi LCD controller

    #define LCD_PINS_RS          4
    #define LCD_PINS_ENABLE     17
    #define LCD_PINS_D4         30
    #define LCD_PINS_D5         29
    #define LCD_PINS_D6         28
    #define LCD_PINS_D7         27

  #endif // !DOGLCD

  //The encoder and click button
 // #define BTN_EN1               10
  #define BTN_EN2               11
  #if ENABLED(LCD_I2C_PANELOLU2)
    #if MB(MELZI)
      #define BTN_ENC           29
      #define LCD_SDSS          30 // Panelolu2 SD card reader rather than the Melzi
    #else
      #define BTN_ENC           30
    #endif
  #else
    #define BTN_ENC             28
    //#define LCD_SDSS            28 // Smart Controller SD card reader rather than the Melzi
  #endif //Panelolu2

  #define SD_DETECT_PIN         -1

#elif ENABLED(MAKRPANEL)

  #define BEEPER_PIN            29

  // Pins for DOGM SPI LCD Support
  #define DOGLCD_A0             30
  #define DOGLCD_CS             17
  #define LCD_PIN_BL            28 // backlight LED on PA3
  // GLCD features
  #define LCD_CONTRAST           1
  // Uncomment screen orientation
  #define LCD_SCREEN_ROT_0
  //#define LCD_SCREEN_ROT_90
  //#define LCD_SCREEN_ROT_180
  //#define LCD_SCREEN_ROT_270
  //The encoder and click button
  #define BTN_EN1               11
//  #define BTN_EN2               10
  #define BTN_ENC               16

  #define SD_DETECT_PIN         -1

#endif // MAKRPANEL

// #if FAN_PIN == 12 || FAN_PIN ==13
//#define FAN_SOFT_PWM
// #endif
