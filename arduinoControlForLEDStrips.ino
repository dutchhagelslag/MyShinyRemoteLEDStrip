#include <Wire.h>

//port values {red,green,blue,white}
const int colorports[] = {10, 9, 5, 11};

int currentcolor[] = {0,0,0,0};

//first value of new color values is smooth where 1 = true, 0 = false
int newcolor[] = {0,0,0,0,0,0,0};

int counter = 0;

void UpdateLED(){

  if(newcolor[0] == 1){
    for(int i = 0; i <= 3; i++){
      while(currentcolor[i] != newcolor[i+1] ){
        if (currentcolor[i] < newcolor[i+1]){
          for(;currentcolor[i] < newcolor[i+1];currentcolor[i]++){
            analogWrite(colorports[i], currentcolor[i]);
            delay(10);
            }
          }
        else{
            for(;currentcolor[i] > newcolor[i+1];currentcolor[i]--){
              analogWrite(colorports[i], currentcolor[i]);
              delay(10);
             }
            }
          }
        }
      }
    
  else{
    for(int j = 0; j<=3; j++){
      currentcolor[j] = newcolor[j+1];
      analogWrite(colorports[j], currentcolor[j]);
      }
    } 
}

void receiveEvent(int howmany){
    counter = 0;
    for(int i=0; i<howmany; i++)
    {
      newcolor[i] = Wire.read();
    }
  
} 

void reset(){ //resets rgbw
    newcolor[0] =1;
    for(int i=1; i<5; i++)
      {
         newcolor[i] = 0;
      }
  }


//===patterns===

void rainbow(){
  switch(counter){
    case 0:
      reset();
      delay(50);
      counter++;
      break;
    
    case 1:
      if(currentcolor[0] == 254){
        counter++;
        }
      newcolor[1]++;
      break;
   
    case 2:
       if(currentcolor[1] == 254){
        counter++;
        }
       newcolor[1]--;       
       newcolor[2]++;
       break;
    
    case 3:
       if(currentcolor[2] == 254){
        counter++;
        }      
       newcolor[2]--;
       newcolor[3]++; 
       break;

    case 4:
      if(currentcolor[2] == 1){
        counter=2;
        }
      newcolor[3]--;
      newcolor[1]++;
      break;  
  }
   
  delay(250);
  }

//==============

void setup() {  
  pinMode(colorports[1], OUTPUT);  pinMode(colorports[2], OUTPUT);  
  pinMode(colorports[4], OUTPUT);  pinMode(colorports[3], OUTPUT);

  pinMode(A0,INPUT);
  
  Wire.begin(8);        // join i2c bus (address optional for master)

}

void loop() {

  Wire.onReceive(receiveEvent);

  switch(newcolor[5]){
    case 2://music smootth
      
      break;
    case 3://music harsh
      
      break;
    case 4://constant tempo
      
      break;
    case 5://rainbow
      rainbow();
      UpdateLED();
      break;
    case 6://random
      
      break;
    default:
      UpdateLED();  
    }
}
