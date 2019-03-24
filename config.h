/*
 * This is a configuration file for the "mqtt_esp8266" light.
 *
 * Change the settings below and save the file as "config.h"
 * You can then upload the code using the Arduino IDE.
 * 
 * Configuration (HA) : 
    light:
      platform: mqtt
      name: 'Office RGB light'
      state_topic: 'Bedroom/rgb1/light/status'
      command_topic: 'Bedroom/rgb1/light/switch'
      brightness_state_topic: 'Bedroom/rgb1/brightness/status'
      brightness_command_topic: 'Bedroom/rgb1/brightness/set'
      rgb_state_topic: 'Bedroom/rgb1/rgb/status'
      rgb_command_topic: 'Bedroom/rgb1/rgb/set'
      
      effect_state_topic: 'Bedroom/rgb1/effect/status'
      effect_command_topic: 'Bedroom/rgb1/effect/set'
      effect_list:
      - rainbow
      - colorloop

      availability_topic
      payload_available: 'Online'
      payload_not_available: 'Offline'
      
      brightness_scale: 100
      optimistic: false
 *
 *
 */

/************************** WIFI Information ***************************************/
#define ssid " " //type your WIFI information inside the quotes
#define password " "

/************************** MQTT Information ***************************************/
#define mqtt_server "192.168.1.XX" //enter your servers IP address
#define mqtt_port 1883 // Usually 1883
#define mqtt_username "mqtt"
#define mqtt_password "password"
#define client_ID "NodeMCU_Test_Code"

/*************************** MQTT TOPICS *******************************************/
#define topic_state "home/rgb1"       //**Receive** The MQTT topic subscribed to receive state updates.
#define topic_set "home/rgb1/set"     //**Publish** The MQTT topic to publish commands to change the light’s state.

// state
#define mqtt_state_topic "Bedroom/rgb1/light/status"
#define mqtt_command_topic "Bedroom/rgb1/light/switch"

// brightness
#define mqtt_brightness_state_topic "Bedroom/rgb1/brightness/status"
#define mqtt_brightness_command_topic "Bedroom/rgb1/brightness/set"

// colors (rgb)
#define mqtt_RGB_state_topic "Bedroom/rgb1/rgb/status"
#define mqtt_RGB_command_topic "Bedroom/rgb1/rgb/set"

// effects
#define mqtt_effect_state_topic "Bedroom/rgb1/effect/status"
#define mqtt_effect_command_topic "Bedroom/rgb1/effect/set"

// payloads by default (on/off)
#define light_ON "ON"
#define light_OFF "OFF"

/*************************** RGB LED pins *****************************************/
// For reference (pin mapping for ESP8266-12E):
// D0/GPIO16      = 16;
// D1/GPIO5       = 5;
// D2/GPIO4       = 4;
// D3/GPIO0       = 0;

// D4/GPIO2       = 2;

// D5/GPIO14      = 14;   This one green
// D6/GPIO12      = 12;   This one red
// D7/GPIO13      = 13;   This one blue
// D8/GPIO15      = 15;   this pulled to ground

// string of lights. Pins D5 - D8
#define WHITE_LED     15 //GPIO15 to ground
#define BLUE_LED      13 //GPIO13 to blue
#define RED_LED       12 //GPIO12 to red
#define GREEN_LED     14 //GPIO14 to green

/***************************** Effects *********************************************/
// Miscellaneous
// Default number of flashes if no value was given
#define flashing_length 2
// Number of seconds for one transition in colorfade mode
#define colorfade_slow 10
#define colorfade_fast 3

// Reverse the LED logic
// false: 0 (off) - 255 (bright)
// true: 255 (off) - 0 (bright)
#define inver_LED_logic true

// Enables Serial and print statements
#define Config_debug true
