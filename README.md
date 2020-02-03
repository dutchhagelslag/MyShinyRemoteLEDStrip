# SetUp (hardware)
![](https://ae01.alicdn.com/kf/HTB1Ks1uH3mTBuNjy1Xbq6yMrVXaY.jpg)
1) Connect LED strip pind to the arduino accordingly
  - 10 to red, 9 to green, 5 to blue, 11 to white (chosen to take advantage of hardware pwn pins on arduino, pwn pins may differ based on arduino model and in which case the arduino will just use software pwn and it'll be fine)
2) Connect the d1 mini to the arduino via i2c pins.
- For the D1 mini 
  - SDA => D2
  - SCL => D1
  
 - For the arduino, it depends on the type you have so go to https://www.arduino.cc/en/reference/wire and figure out which are the SDA and SCL pins.

3) Connect LED Strip, D1 mini, and arduino to a power source, some LED strips are 5V others 12V, use a voltage regulator as needed.
  
  - The D1 mini can be powered through the Arduino and also the LED Strip but careful about current draw. Calculate what the arduino can handle based on LED strip length and arduino model.
  - More often than not the draw will be too much and you will want to serperate the flows.
  - If the LED strip is 12V, you will want MOSFETs to control the LED strip

  
# SetUp (software)
1) Download blynk app and make an account
2) Add verification code to i2c_D1mini.ino
3) Add the wifi's SSID and password to the script
4) Customize board to match with the corresponding virtual pins.

- ZERGBRA(recommended of RGB control) 
  - V1 -> red, 0 - 255 
  - V2 -> green, 0 - 255 
  - V3 -> blue, 0 - 255

- Button
  -V0 -> smooth transition on/off
  -V4 -> on/off

- Menu Setting (under construction)
  - V5
  
- Slider
  - V6 -> white, 0 - 255
