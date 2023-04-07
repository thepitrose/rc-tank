#include <Wire.h>
#include <Servo.h>

String  strLup = String("lup");
String  strLdown = String("ldown");
String  strLstop = String("lstop");

String  strRup = String("rup");
String  strRdown = String("rdown");
String  strRstop = String("rstop");


String  strDDup = String("dbup");
String  stDDdown = String("dbdown");
String  strLurd = String("lurd");
String  strLdru = String("ldru");
String  strDDstop = String("ddstop");


String  strStop = String("stopme");
String  strIrShot = String("irShot");
String  setshieldON = String("setshieldON");
String  setshieldOFF = String("setshieldOFF");

String strInput= String("");
#include "TMRpcm.h"
#include "SPI.h"

Servo myservo;


int DRIVE_RForward = A1;
int DRIVE_RBack = A0;

int DRIVE_LForward = A2;
int DRIVE_LBack = A3;



const int IRledPin =  13;


int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

TMRpcm tmrpcm;


void setup() {
 Wire.begin(8);                /* join i2c bus with address 8 */
 Wire.onReceive(receiveEvent); /* register receive event */
 Wire.onRequest(requestEvent); /* register request event */

 pinMode(IRledPin, OUTPUT);
 
  pinMode(DRIVE_LForward, OUTPUT);
  pinMode(DRIVE_LBack, OUTPUT); 
  digitalWrite(DRIVE_LForward, LOW);
  digitalWrite(DRIVE_LBack, LOW);

  pinMode(DRIVE_RForward, OUTPUT);
  pinMode(DRIVE_RBack, OUTPUT); 
  digitalWrite(DRIVE_RForward, LOW);
  digitalWrite(DRIVE_RBack, LOW);

  

   myservo.attach(A7);

 Serial.begin(9600);           /* start serial for debug */
}

void loop() {
 delay(100);
}

// function that executes whenever data is received from master
void receiveEvent(int howMany) {
 while (0 <Wire.available()) {
      char c = Wire.read();      /* receive byte as a character */
    strInput+=c;           /* print the character */
  }

  //////////////////////////////////////////
 
  if(strLup.equals(strInput)) {

    Lforward();
  }

  if(strLdown.equals(strInput)) {

    Lback();
  }
  
  if(strLstop.equals(strInput)) {

    Lstop();
  }

  ////////////////////////////////////

  if(strRup.equals(strInput)) {

    Rforward();
  }

  
  if(strRdown.equals(strInput)) {

    Rback();
  }

  if(strRstop.equals(strInput)) {

    Rstop();
  }

  ////////////////////////////////////

   if(strIrShot.equals(strInput)) {

    IrShot();
  }

    if(setshieldON.equals(strInput)) {

    shieldON();
  }

   if(setshieldOFF.equals(strInput)) {

    shieldOFF();
  }

  ///////////////

    if(strDDup.equals(strInput)) {

    goDDup();
  }

    if(stDDdown.equals(strInput)) {

    goDDdown();
  }

    if(strLurd.equals(strInput)) {

    goLurd();
  }

    if(strLdru.equals(strInput)) {

    goLdru();
  }

    if(strDDstop.equals(strInput)) {

    goDDstop();
  }


  strInput= String("");
}




void Lforward()
{

 digitalWrite(DRIVE_LBack, LOW);
 digitalWrite(DRIVE_LForward, HIGH);
 
}

void Lback()
{


 digitalWrite(DRIVE_LForward, LOW);
 digitalWrite(DRIVE_LBack, HIGH);


    
}

void Lstop()
{

 digitalWrite(DRIVE_LForward, LOW);
 digitalWrite(DRIVE_LBack, LOW);
 
}


void Rforward()
{
      digitalWrite(DRIVE_RBack, LOW);
      digitalWrite(DRIVE_RForward, HIGH);
}

void Rback()
{
 digitalWrite(DRIVE_RForward, LOW);
 digitalWrite(DRIVE_RBack, HIGH);
}

void Rstop()
{
 digitalWrite(DRIVE_RForward, LOW);
 digitalWrite(DRIVE_RBack, LOW);

}
///////////////////////////////////////


void goDDup()
{

 digitalWrite(DRIVE_RBack, LOW);
 digitalWrite(DRIVE_RForward, HIGH);

 digitalWrite(DRIVE_LBack, LOW);
 digitalWrite(DRIVE_LForward, HIGH);
 
}


void goDDdown()
{
  
 digitalWrite(DRIVE_RForward, LOW);
 digitalWrite(DRIVE_RBack,HIGH );

 digitalWrite(DRIVE_LForward, LOW);
 digitalWrite(DRIVE_LBack, HIGH);
}


void goLurd()
{
   digitalWrite(DRIVE_LBack, LOW);
 digitalWrite(DRIVE_LForward, HIGH);

  digitalWrite(DRIVE_RForward, LOW);
 digitalWrite(DRIVE_RBack,HIGH );

}


void goLdru()
{
  
 digitalWrite(DRIVE_LForward, LOW);
 digitalWrite(DRIVE_LBack, HIGH);

 digitalWrite(DRIVE_RBack, LOW);
 digitalWrite(DRIVE_RForward, HIGH);
}

void goDDstop()
{
  
 digitalWrite(DRIVE_LForward, LOW);
 digitalWrite(DRIVE_LBack, LOW);


 digitalWrite(DRIVE_RForward, LOW);
 digitalWrite(DRIVE_RBack, LOW);
}


///////////////////////////////////////////

void IrShot()
{

  digitalWrite(IRledPin, HIGH);
   delay(1000);
   digitalWrite(IRledPin, LOW);
}


void shieldON()
{
    Serial.print("IP : ");

  myservo.write(180);                  // sets the servo position according to the scaled value
  

}

void shieldOFF()
{
  myservo.write(0);                  // sets the servo position according to the scaled value
  //delay(15);  
}

void requestEvent() {
 Wire.write("Hello NodeMCU");  /*send string on request */
}
