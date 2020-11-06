## Project Parts and Links

DC Power Connector Socket:
- https://www.amazon.com/gp/product/B07FVTJ2B4/ref=ppx_yo_dt_b_asin_title_o00_s01?ie=UTF8&psc=1
- Price: $6.68 , Quantity: 15 pieces
![alt text](https://github.com/wronched/RGB-LED-Common-Anode/blob/master/ReadMe_Pictures/Power-Socket.png)

Plastic Waterproof Boxes:
- https://www.amazon.com/gp/product/B07G8S6XLV/ref=ppx_yo_dt_b_asin_title_o00_s02?ie=UTF8&psc=1
- Price: $11.99 , Quantity: 10 pieces
![alt text](https://github.com/wronched/RGB-LED-Common-Anode/blob/master/ReadMe_Pictures/Plastic-Box.png)

RGB LED:
- https://www.amazon.com/gp/product/B01CDTEKAG/ref=ppx_yo_dt_b_asin_title_o04_s00?ie=UTF8&psc=1
- Price: $32.88 , Quantity: 60 LED @ 16.4ft
![alt text](https://github.com/wronched/RGB-LED-Common-Anode/blob/master/ReadMe_Pictures/RGB-LED.png)

ESP8266:
- https://www.amazon.com/gp/product/B07L8W9SP3/ref=ppx_yo_dt_b_asin_title_o05_s00?ie=UTF8&psc=1
- Price: $19.99 , Quantity: 4 pieces
![alt text](https://github.com/wronched/RGB-LED-Common-Anode/blob/master/ReadMe_Pictures/ESP8266.png)

Rocker Switch:
- https://www.amazon.com/gp/product/B07B2S5QYN/ref=ppx_yo_dt_b_asin_title_o04_s01?ie=UTF8&psc=1
- Price: $7.99 , Quantity: 20 pieces
![alt text](https://github.com/wronched/RGB-LED-Common-Anode/blob/master/ReadMe_Pictures/Rocker-Switch.png)

5V 15A AC to DC Power Supply Adapter:
- https://www.amazon.com/gp/product/B01LXN7MN3/ref=ppx_yo_dt_b_asin_title_o04_s00?ie=UTF8&psc=1
- Price: $25.99 , Quantity: 1 piece
![alt text](https://github.com/wronched/RGB-LED-Common-Anode/blob/master/ReadMe_Pictures/PSU.png)

USB SD Card reader:
- https://www.amazon.com/gp/product/B00OJ5WBUE/ref=ppx_yo_dt_b_asin_title_o08_s00?ie=UTF8&psc=1
- Price: $8.49 , Quantity: 1 piece
![alt text](https://github.com/wronched/RGB-LED-Common-Anode/blob/master/ReadMe_Pictures/SD-Reader.png)

32GB SD Card:
- https://www.amazon.com/gp/product/B06XWN9Q99/ref=ppx_yo_dt_b_asin_title_o08_s01?ie=UTF8&psc=1
- Price: $7.99 , Quantity: 1 piece
![alt text](https://github.com/wronched/RGB-LED-Common-Anode/blob/master/ReadMe_Pictures/SD-Card.png)

12V 8-23V Step Down to 5V/3A:
- https://www.amazon.com/gp/product/B00CXKBJI2/ref=ppx_yo_dt_b_asin_title_o09_s01?ie=UTF8&psc=1
- Price: $6.99 , Quantity: 1 piece
![alt text](https://github.com/wronched/RGB-LED-Common-Anode/blob/master/ReadMe_Pictures/Step-Down.png)

PCB Board Kit:
- https://www.amazon.com/gp/product/B07CK3RCKS/ref=ppx_yo_dt_b_asin_title_o01_s00?ie=UTF8&psc=1
- Price: $15.99 , Quantity: 1 piece (kit)
![alt text](https://github.com/wronched/RGB-LED-Common-Anode/blob/master/ReadMe_Pictures/Board-Kit.png)

Raspberry Pi 3 B+:
- https://www.amazon.com/gp/product/B07BC6WH7V/ref=ppx_yo_dt_b_asin_title_o02_s00?ie=UTF8&psc=1
- Price: $48.99 , Quantity: 1 piece (kit)
![alt text](https://github.com/wronched/RGB-LED-Common-Anode/blob/master/ReadMe_Pictures/Pi-3-B+.png)

Logic Level Converter:
- https://www.amazon.com/gp/product/B0148BLZGE/ref=ppx_yo_dt_b_asin_title_o04_s01?ie=UTF8&psc=1
- Price: $7.99 , Quantity: 5 piece
![alt text](https://github.com/wronched/RGB-LED-Common-Anode/blob/master/ReadMe_Pictures/logic-Level.png)

DC Power Jack:
- https://www.amazon.com/gp/product/B011YKCK5M/ref=ppx_yo_dt_b_asin_title_o04_s03?ie=UTF8&psc=1
- Price: $5.99 , Quantity: 5 piece (pairs)
![alt text](https://github.com/wronched/RGB-LED-Common-Anode/blob/master/ReadMe_Pictures/DC-Jack.png)



RGB LED Light Strip Connector:
- https://www.amazon.com/gp/product/B07DL76B6M/ref=ppx_yo_dt_b_asin_title_o09_s00?ie=UTF8&psc=1
- Price: $7.49 , Quantity: 8 piece
![alt text](https://github.com/wronched/RGB-LED-Common-Anode/blob/master/ReadMe_Pictures/Strip-Conn.png)

Right Angle Connector:
- https://www.amazon.com/gp/product/B01NASHQPO/ref=ppx_yo_dt_b_asin_title_o01_s00?ie=UTF8&psc=1
- Price: $11.88 , Quantity: 10 piece
![alt text](https://github.com/wronched/RGB-LED-Common-Anode/blob/master/ReadMe_Pictures/Right-Conn.png)


This project uses:
- REG LED -------------- 4 pins for Red,Green,Blue,[Voltage/Ground]
- ESP8266 -------------- Drives 4 pins and provides WIFI connection
- Raspberry Pi 3B ------ Creates MQTT server for WIFI to connect to
- Home Assistant ------- User interface to (on raspberry Pi) to talk to devices
------------------------------------------
As far as the project is concerned, im going to assume the reader understands how to:
- Develop hardware ---- Using the ESP8266 GPIO - i did include my design
- Set up wifi network --- This is your home network - all devices need to be connected to it
- Set up MQTT server -- doesn't have to be from raspberry pi BUT HA makes this very easy
- Set up Home Assistant (HA)
------------------------------------------
Therefore this project is really a repository for me to design and develop:
- folder for designs
- Arduino IDE Code
- readme to explain how code works
- also explain how each effect works

### Common Andode or Common Cathode
First off, one point that i missed when i bough me RGB LEDs is to determine if the LED strip is common Anode or common Cathode. This is relatively easy to find out, you just check to see if you have a +12V pin or a GND pin in addition to the other 2 pins [ Red, Green, Blue].
![alt text](https://github.com/wronched/RGB-LED-Common-Anode/blob/master/ReadMe_Pictures/rgb-led.png)
This is important because it tells you what LED value will turn on and off the LED. For instance:

| Common  | Terminal  | ON  | OFF |
| ------- |:---------:| ---:| ---:|
| Anode   | (+) 5V    | 0   | 255 |
| Cathode | (-) GND   | 255 | 0   |

### HA Configuration yaml file
Here is how i wrote my configuration yaml file for MQTT:
```
light:
      platform: mqtt
      name: 'Bedroom RGB light'
      state_topic: 'Bedroom/rgb1/light/status'
      command_topic: 'Bedroom/rgb1/light/switch'
      brightness_state_topic: 'Bedroom/rgb1/brightness/status'
      brightness_command_topic: 'Bedroom/rgb1/brightness/set'
      rgb_state_topic: 'Bedroom/rgb1/rgb/status'
      rgb_command_topic: 'Bedroom/rgb1/rgb/set'
      
      effect_state_topic: 'Bedroom/rgb1/effect/status'
      effect_command_topic: 'Bedroom/rgb1/effect/set'
      effect_list:
      - Solid
      - Random
      - Shift
      - Rainbow
      - Fade
      
      state_value_template: "{{ value_json.state }}"
      brightness_value_template: "{{ value_json.brightness }}"
      rgb_value_template: "{{ value_json.rgb | join(',') }}"
      qos: 0
      
      brightness_scale: 100
      optimistic: false

```
A few helpfull tips: for beginners, i had a lot of issues setting up all the topics for MQTT. Topics can be broken down into two types Command and State.  
- Command topics: When you revieve a message from the Host (Raspberry PI) this will come as a command topic  
- State topics: When you want to report (Publish) any changes to states then you will publish the state from device to Host  

An example of this is:
```
Host (HA/Raspberry pi): toggles a switch to turn 'ON' a LED  
Device (ESP8266/LED): recieves a command state from the Host over MQTT of 'command_state' with message 'ON'
Note: if i set my command_state in configuration yaml as 'EXAMPLE' the device will see 'EXAMPLE' with message 'ON'
i will also need to program command_state in ESP8266 as 'EXAMPLE' 

#define light_ON "ON"
#define light_OFF "OFF"
if (String(command_topic).equals(p_topic)) {            //if(EXAMPLE = EXAMPLE)
    // test if the payload is equal to "ON" or "OFF"
    if (message.equals(String(light_ON))) {             //if(message(ON) = ON)
      if (LED_state != true) {
        LED_state = true;                               //Turn LED ON
        setColor(LED_red, LED_green, LED_blue);         //Set LED to color values
        publishRGBState();                              //Publish the state so HA knows it did turn on
      }
```

## Test Github Code
-------------------------------------------
**This is bold text**
*This text is italicized*
~~This was mistaken text~~
**This text is _extremely_ important**
> quote text

------------------------------------------

Task List
- [x] Build the NodeMCU Board
- [ ] Configure the Raspberry Pi 3 B+
- [ ] Set up Home assistant on Raspberry Pi
- [ ] Develop code in Arduino IDE
- [x] Program NodeMCU sucessfully
- [ ] Push code to NodeMCU and test functionallity
- [ ] Develope Home ssistant code
- [ ] Test full functionallity [Phone -> home assistant -> raspberry pi -> nodeMCU -> lights]
- [ ] set up light strips
