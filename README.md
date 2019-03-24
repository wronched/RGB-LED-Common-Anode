## RGB-LED-Common-Anode Project
This project uses:
- REG LED -------------- 4 pins for Red,Green,Blue,[Voltage/Ground]
- ESP8266 -------------- Drives 4 pins and provides WIFI connection
- Raspberry Pi 3B ------ Creates MQTT server for WIFI to connect to
- Home Assistant ------- User interface to (on raspberry Pi) to talk to devices

As far as the project is concerned, im going to assume the reader understands how to:
- Develop hardware ---- Using the ESP8266 GPIO - i did include my design
- Set up wifi network --- This is your home network - all devices need to be connected to it
- Set up MQTT server -- doesn't have to be from raspberry pi BUT HA makes this very easy
- Set up Home Assistant (HA)

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



Common Anode (+ terminal, typically 5V): ----- 0 = ON and 255 = OFF  
Common Anode (- terminal, typically GND): --- 255 = ON and 0 = OFF  

## Test Github Code
-------------------------------------------
**This is bold text**
*This text is italicized*
~~This was mistaken text~~
**This text is _extremely_ important**
> quote text

Some basic Git commands are:
```
git status
git add
git commit

```
------------------------------------------
Lists:
- RGB Color Selection
- Brightness
- Flash
- Fade
- Transitions
- Effects with Animation Speed
- Over-the-Air (OTA) Upload from the ArduinoIDE!
-------------------------------------------

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
