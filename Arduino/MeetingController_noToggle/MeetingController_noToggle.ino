/*
  MeetingController - No Toggle
  created 25 Feb 2021
  by Hugh Elliott (hugh@thinkingbox.com)

  Original example code is in the public domain.
  http://www.arduino.cc/en/Tutorial/KeyboardMessage
*/

#include "Keyboard.h"

const int windowPin = 7;
const int mutePin = 6;
const int cameraPin = 5; 

int windowState = 0; 
int muteState = 0; 
int cameraState = 0; 
int prevWinState = 1;
int prevMuteState = 1;
int prevCamState = 1;

boolean windowToggle = false;
boolean muteToggle = false;
boolean cameraToggle = false;

void setup() {
  // make the pushButton pin an input:
  pinMode(windowPin, INPUT);
  pinMode(mutePin, INPUT);
  pinMode(cameraPin, INPUT);
  // initialize control over the keyboard:
  digitalWrite(windowPin,LOW);
  digitalWrite(mutePin,LOW);
  digitalWrite(cameraPin,LOW);
  //Keyboard.begin();
  Serial.begin(9600);
}
void loop() {
  windowState = digitalRead(windowPin);
  muteState = digitalRead(mutePin);
  cameraState = digitalRead(cameraPin);
  if(windowState == HIGH){
    windowToggle = true;
  }else{
    if(windowToggle == true){
      Keyboard.press(KEY_LEFT_GUI);
      delay(100);
      Keyboard.press('w');
      delay(100);
      Keyboard.releaseAll(); 
      windowToggle = false;
    }
  }
  if(muteState == HIGH){
    muteToggle = true;
  }else{
    if(muteToggle == true){
      Keyboard.press(KEY_LEFT_GUI);
      delay(100);
      Keyboard.press('d');
      delay(100);
      Keyboard.releaseAll();
      muteToggle = false;
    }
  }
  if(cameraState == HIGH){
    cameraToggle = true;
  }else{
    if(cameraToggle == true){
      Keyboard.press(KEY_LEFT_GUI);
      delay(100);
      Keyboard.press('e');
      delay(100);
      Keyboard.releaseAll();
      cameraToggle = false;
    }
  }
delay(250);
}
