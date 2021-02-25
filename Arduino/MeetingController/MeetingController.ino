/*
  MeetingController
  created 01 Feb 2021
  by Hugh Elliott (hugh@thinkingbox.com)

  Original example code is in the public domain.
  http://www.arduino.cc/en/Tutorial/KeyboardMessage
*/

#include "Keyboard.h"

const int windowPin = 7;
const int mutePin = 6;
const int cameraPin = 5; 
const int zoomIndPin = 11;
const int meetIndPin = 10; 
const int zoomPin = 9;
//const int meetPin = 8;

int windowState = 0; 
int muteState = 0; 
int cameraState = 0; 
int prevWinState = 1;
int prevMuteState = 1;
int prevCamState = 1;
int zoomState = 0; 
int meetState = 0; 
int prevZoomState = 1;
//int prevMeetState = 1;

boolean windowToggle = false;
boolean muteToggle = false;
boolean cameraToggle = false;

void setup() {
  // make the pushButton pin an input:
  pinMode(windowPin, INPUT);
  pinMode(mutePin, INPUT);
  pinMode(cameraPin, INPUT);
  pinMode(zoomIndPin, OUTPUT);
  pinMode(meetIndPin, OUTPUT);
  // initialize control over the keyboard:
  digitalWrite(windowPin,LOW);
  digitalWrite(mutePin,LOW);
  digitalWrite(cameraPin,LOW);
  //digitalWrite(zoomPin,LOW);
  //digitalWrite(meetPin,LOW);
  //Keyboard.begin();
  Serial.begin(9600);
    digitalWrite(zoomIndPin,digitalRead(zoomPin));
    //digitalWrite(meetIndPin,digitalRead(meetPin));
}
void loop() {
  windowState = digitalRead(windowPin);
  muteState = digitalRead(mutePin);
  cameraState = digitalRead(cameraPin);
  zoomState = digitalRead(zoomPin);
  //meetState = digitalRead(meetPin);
  
  digitalWrite(zoomIndPin,zoomState);
  digitalWrite(meetIndPin,!zoomState);
  if(windowState == HIGH){
    windowToggle = true;
  }else{
    if(windowToggle == true){
      Keyboard.press(KEY_LEFT_GUI);
      delay(100);
      Keyboard.press('w');
      delay(100);
      if(zoomState == HIGH){
      Keyboard.releaseAll(); 
        delay(1000);
        Keyboard.press(KEY_RETURN);
        delay(100);
      }
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
      if(zoomState == HIGH){
        Keyboard.press(KEY_LEFT_SHIFT);
        delay(100);
        Keyboard.press('a');
      }else{
      Keyboard.press('d');
      }
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
      if(zoomState == HIGH){
        Keyboard.press(KEY_LEFT_SHIFT);
        delay(100);
        Keyboard.press('v');
      }else{
      Keyboard.press('e');
      }
      delay(100);
      Keyboard.releaseAll();
      cameraToggle = false;
    }
  }
delay(250);
}
