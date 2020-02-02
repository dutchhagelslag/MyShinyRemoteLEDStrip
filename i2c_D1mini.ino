#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Wire.h>

const char auth[] = ""; // auth key for blynk
const char ssid[] = ""; // ssid of wifi
const char pass[] = ""; //password of wifi

//first value of new color values is smooth where 1 = true, 0 = false, then RGBW. pattern, bpm
int newcolor[] = {0,0,0,0,0,1,0};
bool changed = false;

void reset(){
    for(int i =0; i<6; i++)
      {
         newcolor[i] = 0;
      }
}

void setup() {
  Blynk.begin(auth, ssid, pass);
  Wire.begin(); // join i2c bus (address optional for master)
}
  
void loop() {
  Blynk.run();
  
  
  if(changed){
    Wire.beginTransmission(8); // transmit to device #8
    delay(10);
    for (int i = 0; i<7; i++){
      Wire.write(newcolor[i]);
      }
    Wire.endTransmission(); 
    changed = false;
   }
}

BLYNK_WRITE(V0) {newcolor[0] = param.asInt(); changed = true;}

BLYNK_WRITE(V1) {newcolor[1] = param.asInt(); changed = true; newcolor[5] = 1;}
BLYNK_WRITE(V2) {newcolor[2] = param.asInt(); changed = true; newcolor[5] = 1;}
BLYNK_WRITE(V3) {newcolor[3] = param.asInt(); changed = true; newcolor[5] = 1;}

BLYNK_WRITE(V4) {if(param.asInt() == 0){reset();changed = true;}}
BLYNK_WRITE(V5) {newcolor[5] = param.asInt(); changed = true;}
BLYNK_WRITE(V6) {newcolor[4] = param.asInt(); changed = true;}
BLYNK_WRITE(V7) {newcolor[6] = param.asInt(); changed = true;}
