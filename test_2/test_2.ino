#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ESP8266WebServer.h>
#include <WiFiClient.h>

#include <EEPROM.h>
#include <ArduinoJson.h>
#include <PubSubClient.h>
#include <ArduinoOTA.h>

#include "config.h"

/*********************************** RGB LED Defintions ********************************/
boolean LED_state = false;
uint8_t LED_brightness = 100;
String LED_effect = "Solid";
uint8_t LED_red = 0; //255
uint8_t LED_green = 0; //255
uint8_t LED_blue = 0; //255

String Fade = "FadeIn";

/********************************** TEMP TEST VALUES ***********************************/
const uint8_t lights[360]={
  0,   0,   0,   0,   0,   1,   1,   2, 
  2,   3,   4,   5,   6,   7,   8,   9, 
 11,  12,  13,  15,  17,  18,  20,  22, 
 24,  26,  28,  30,  32,  35,  37,  39, 
 42,  44,  47,  49,  52,  55,  58,  60, 
 63,  66,  69,  72,  75,  78,  81,  85, 
 88,  91,  94,  97, 101, 104, 107, 111, 
114, 117, 121, 124, 127, 131, 134, 137, 
141, 144, 147, 150, 154, 157, 160, 163, 
167, 170, 173, 176, 179, 182, 185, 188, 
191, 194, 197, 200, 202, 205, 208, 210, 
213, 215, 217, 220, 222, 224, 226, 229, 
231, 232, 234, 236, 238, 239, 241, 242, 
244, 245, 246, 248, 249, 250, 251, 251, 
252, 253, 253, 254, 254, 255, 255, 255, 
255, 255, 255, 255, 254, 254, 253, 253, 
252, 251, 251, 250, 249, 248, 246, 245, 
244, 242, 241, 239, 238, 236, 234, 232, 
231, 229, 226, 224, 222, 220, 217, 215, 
213, 210, 208, 205, 202, 200, 197, 194, 
191, 188, 185, 182, 179, 176, 173, 170, 
167, 163, 160, 157, 154, 150, 147, 144, 
141, 137, 134, 131, 127, 124, 121, 117, 
114, 111, 107, 104, 101,  97,  94,  91, 
 88,  85,  81,  78,  75,  72,  69,  66, 
 63,  60,  58,  55,  52,  49,  47,  44, 
 42,  39,  37,  35,  32,  30,  28,  26, 
 24,  22,  20,  18,  17,  15,  13,  12, 
 11,   9,   8,   7,   6,   5,   4,   3, 
  2,   2,   1,   1,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0,   0};

uint16_t color[3], nextColor[3];
long colorStep[3];
byte count, a0, a1, a2;

/*************************** INITIALIZE MESSGAE AND CLIENT *****************************/
const uint8_t BUFFER_SIZE = 20;
char msg[BUFFER_SIZE]; 

//const int BUFFER_SIZE = JSON_OBJECT_SIZE(10);

WiFiClient espClient;
PubSubClient client(espClient);

/********************************** START SETUP *****************************************/
void setup() {
  // start serial debug:
  if (Config_debug) {
    Serial.begin(115200);
    delay( 100 );
  }

  // Initialize the LED pins
  pinMode( WHITE_LED, OUTPUT );
  pinMode( BLUE_LED, OUTPUT );
  pinMode( RED_LED, OUTPUT );
  pinMode( GREEN_LED, OUTPUT );
  analogWriteRange(255);
  setColor(255, 255, 255);
  
  //start wifi and mqtt
  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);

}

/********************************** SETUP WIFI *****************************************/
void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("INFO: Connecting to ");
  Serial.println(ssid);
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("INFO: WiFi connected");
  Serial.println("INFO: IP address: ");
  Serial.print("INFO: ");
  Serial.println(WiFi.localIP());
}

/********************************** PUBLISH STATE ****************************************/
//Publishes the state (ON/OFF) of the RGB light strip
void publishRGBState() {  
  if (LED_state) {
    client.publish(mqtt_state_topic, light_ON, true);
  } else {
    client.publish(mqtt_state_topic, light_OFF, true);
  }
}

/********************************** PUBLISH RGB Colors ***********************************/
void publishRGBColor() {
  //Serial.println(msg, BUFFER_SIZE, "%d,%d,%d", LED_red, LED_green, LED_blue);
  client.publish(mqtt_RGB_state_topic, msg, true);
}

/********************************** PUBLISH BRIGHTNESS ***********************************/
void publishRGBBrightness() {
  //Serial.println(msg, BUFFER_SIZE, "%d", LED_brightness);
  client.publish(mqtt_brightness_state_topic, msg, true);
}

/********************************** PUBLISH BRIGHTNESS ***********************************/
void publishRGBEffect() {
  //Serial.println(msg, BUFFER_SIZE, "%d", LED_effect);
  client.publish(mqtt_effect_state_topic, msg, true);
}

/********************************** RECONNECT CLIENT *****************************************/
void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("INFO: Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect(client_ID, mqtt_username, mqtt_password)) {
      Serial.println("INFO: connected");
      // Once connected, publish an announcement...
      // publish the initial values
      publishRGBState();
      publishRGBBrightness();
      publishRGBColor();
      publishRGBEffect();
      
      // ... and resubscribe
      client.subscribe(mqtt_command_topic);
      client.subscribe(mqtt_brightness_command_topic);
      client.subscribe(mqtt_RGB_command_topic);
      client.subscribe(mqtt_effect_command_topic);
      
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

/********************************** SETCOLOR *****************************************/
// function called to adapt the brightness and the color of the led
void setColor(uint8_t p_red, uint8_t p_green, uint8_t p_blue) {
  // convert the brightness in % (0-100%) into a digital value (0-255)
  uint8_t brightness = map(LED_brightness, 0, 100, 255, 0);

  analogWrite(RED_LED, map(p_red, 0, 255, 255, brightness));
  analogWrite(GREEN_LED, map(p_green, 0, 255, 255, brightness));
  analogWrite(BLUE_LED, map(p_blue, 0, 255, 255, brightness));
}

/********************************** START CALLBACK *****************************************/
/*
   Function called when a MQTT message has arrived
   @param p_topic   The topic of the MQTT message
   @param p_payload The payload of the MQTT message
   @param p_length  The length of the payload
*/
// function called when a MQTT message arrived
void callback(char* p_topic, byte* p_payload, unsigned int p_length) {
    
  // concat the payload into a string
  String message;
  for (uint8_t i = 0; i < p_length; i++) {
    message.concat((char)p_payload[i]);
  }
  message[p_length] = '\0';
  Serial.print("MQTT: Message arrived: [");
  Serial.print(p_topic);
  Serial.print("] Message = [");
  Serial.print(message);              //[CW] got the message and print it
  Serial.println("] ");

  /*if (!processJson(message, p_topic)) {          //[CW] if processJson(message) returns false then this is true
    return;
  }*/

         /***** if its the mqtt_command_topic - Turn ON/OFF ******/
  if (String(mqtt_command_topic).equals(p_topic)) {
    // test if the payload is equal to "ON" or "OFF"
    if (message.equals(String(light_ON))) {
      if (LED_state != true) {
        LED_state = true;
        setColor(LED_red, LED_green, LED_blue);
        publishRGBState();
      }
    } else if (message.equals(String(light_OFF))) {
      if (LED_state != false) {
        LED_state = false;
        setColor(0, 0, 0);
        publishRGBState();
      }
    }
         /***** if its the mqtt_brightness_command_topic - change brightness ******/
  } else if (String(mqtt_brightness_command_topic).equals(p_topic)) {
    uint8_t brightness = message.toInt();
    if (brightness < 0 || brightness > 100) {
      return;                                               //make sure brightness sent is between 0 and 100
    } else {
      LED_brightness = brightness;
      setColor(LED_red, LED_green, LED_blue);
      publishRGBBrightness();
    }
         /***** if its the mqtt_RGB_command_topic - change RGB ******/
  } else if (String(mqtt_RGB_command_topic).equals(p_topic)) {
    uint8_t firstIndex = message.indexOf(',');              //Get position of first comma
    uint8_t lastIndex = message.lastIndexOf(',');           //Get position of second comma
    
    uint8_t rgb_red = message.substring(0, firstIndex).toInt();
    if (rgb_red < 0 || rgb_red > 255) {
      return;                                               //Make sure RGB LED sent is between 0 and 255
    } else {
      LED_red = rgb_red;
    }
    
    uint8_t rgb_green = message.substring(firstIndex + 1, lastIndex).toInt();
    if (rgb_green < 0 || rgb_green > 255) {
      return;                                               //Make sure RGB LED sent is between 0 and 255
    } else {
      LED_green = rgb_green;
    }
    
    uint8_t rgb_blue = message.substring(lastIndex + 1).toInt();
    if (rgb_blue < 0 || rgb_blue > 255) {
      return;                                               //Make sure RGB LED sent is between 0 and 255
    } else {
      LED_blue = rgb_blue;
    }
    
    setColor(LED_red, LED_green, LED_blue);
    LED_effect = "Solid";
    publishRGBColor();

         /***** if its the mqtt_RGB_command_topic - set effect ******/
  } else if (String(mqtt_effect_command_topic).equals(p_topic)) {

        /***** SET SOLID EFFECT ******/
    if (message.equals("Solid")) {
      LED_effect = "Solid";
      setColor(LED_red, LED_green, LED_blue);
      publishRGBEffect();
    
         /***** SET RANDOM EFFECT ******/
    } else if (message.equals("Random")) {
      LED_effect = "Random";
      publishRGBEffect();

         /***** SET SHIFT EFFECT ******/
    } else if (message.equals("Shift")) {
      LED_effect = "Shift";
      publishRGBEffect();
      
        /***** SET RAINBOW EFFECT ******/
    } else if (message.equals("Rainbow")) {
      LED_effect = "Rainbow";
      publishRGBEffect();

        /***** SET FADE EFFECT ******/
    } else if (message.equals("Fade")) {
      LED_effect = "Fade";
      publishRGBEffect();
    }
    
  }

 

}
/********************************** [TEST] SET NEXT COLOR *****************************************/
void setNextColor()
{
  nextColor[count]=random(256)<<8;
  a0=random(1);
  a1=((!a0)+count+1)%3;
  a0=(count+a0+1)%3;
  nextColor[a0]=(255-nextColor[count])<<8;
  nextColor[a1]=0;
}

/********************************** [TEST] RUN EFFECTS *****************************************/
void runEffects()
{
  if (LED_effect.equals("Solid")) {
    return;
    
        /***** RAINBOW EFFECT ******/
    } else if (LED_effect.equals("Rainbow")) {
      unsigned int rgbColour[3];

      // Start off with red.
      rgbColour[0] = 255;
      rgbColour[1] = 0;
      rgbColour[2] = 0;

      // Choose the colours to increment and decrement.
      for (int decColour = 0; decColour < 3; decColour += 1) {
        int incColour = decColour == 2 ? 0 : decColour + 1;

        // cross-fade the two colours.
        for(int i = 0; i < 255; i += 1) {
          rgbColour[decColour] -= 1;
          rgbColour[incColour] += 1;
      
        setColor(rgbColour[0], rgbColour[1], rgbColour[2]);
        delay(5);
        }
      }
      publishRGBEffect();

         /***** SHIFT EFFECT ******/
    } else if (LED_effect.equals("Shift")) {
      setNextColor();
      for (byte k=0; k<3; k++) colorStep[k]=((long)nextColor[k] - color[k])/100;
      for (byte k=0; k<100;k++) {
        for (byte i=0; i<3; i++) color[i]+=colorStep[i];
        setColor(color[0]>>8, color[1]>>8, color[2]>>8);
        delay(10);
      } for (byte k=0; k<3; k++) color[k] = nextColor[k];
      setColor(color[0]>>8, color[1]>>8, color[2]>>8);
      delay(500);
      count+=random(15);
      count%=3;
      delay(5);
      publishRGBEffect();
        
         /***** RANDOM EFFECT ******/
    } else if (LED_effect.equals("Random")) {
      a0=random(240); 
      a1=random(1);
      a1=(count+a1+1)%3;
      a2=((!a1)+count+1)%3;
        
        color[count]=lights[a0];
        color[a1]=lights[(a0+100)%240];
        color[a2]=0;
        
      setColor(color[0], color[1], color[2]);
      count++;
      count%=3;
      delay(100);
      publishRGBEffect();

    } else if (LED_effect.equals("Fade")) {
      uint8_t brightness = LED_brightness;
      if (brightness < 0 || brightness > 100) {
        return;                                               //make sure brightness sent is between 0 and 100
      } else if (Fade.equals("FadeIn")) {
        for (byte b=LED_brightness; b<100;b++) {
        LED_brightness = b;
        setColor(LED_red, LED_green, LED_blue);
        delay(15);
        }
        Fade = "FadeOut";
      } else if (Fade.equals("FadeOut")) {
        for (byte b=LED_brightness; b>0;b--) {
        LED_brightness = b;
        setColor(LED_red, LED_green, LED_blue);
        delay(15);
        } 
        Fade = "FadeIn";
      }

      publishRGBBrightness();
      publishRGBEffect();

    }
}

/********************************** START MAIN LOOP *****************************************/
void loop() {

         /***** RECONNECT TO CLIENT IF DISCONNECTED ******/
  if (!client.connected()) {
    reconnect();
  }

         /***** RECONNECT TO WIFI IF DISCONNECTED ******/
  if (WiFi.status() != WL_CONNECTED) {
    delay(1);
    Serial.print("WIFI Disconnected. Attempting reconnection.");
    setup_wifi();
    return;
  }

  runEffects();  

  client.loop();   //not sure what this is for...
}
