#include "Joystick.h"
#include <Wire.h>
#include <Joystick.h>


// Create Joystick
Joystick_ Joystick;

// Set to true to test "Auto Send" mode or false to test "Manual Send" mode.
//const bool testAutoSendMode = true;
const bool testAutoSendMode = false;


void setup() {



   Serial.begin(9600);
  Wire.begin();
  Joystick.begin();



 pinMode(0, INPUT_PULLUP);
 pinMode(1, INPUT_PULLUP);
 pinMode(2, INPUT_PULLUP);
 pinMode(3, INPUT_PULLUP);
 pinMode(4, INPUT_PULLUP);
 pinMode(5, INPUT_PULLUP);
 pinMode(6, INPUT_PULLUP);
 pinMode(7, INPUT_PULLUP);
 pinMode(8, INPUT_PULLUP);
 pinMode(9, INPUT_PULLUP);
 pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
}

const int pinToButtonMap = 0;
int lastButtonState[11] = {0,0,0,0,0,0,0,0,0,0,0};
void loop() {



for (int index = 0; index < 11; index++)
  {
    int currentButtonState = !digitalRead(index + pinToButtonMap);
    if (currentButtonState != lastButtonState[index])
    {
      Joystick.setButton(index, currentButtonState);
      lastButtonState[index] = currentButtonState;
    }
  }
  



  delay(10);


}
