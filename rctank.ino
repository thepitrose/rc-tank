#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
ESP8266WebServer server;
#include <Wire.h>

uint8_t pin_led = 16;
char* ssid = "home3";
char* password = "036345563";


static IPAddress ip(192, 168, 14, 201); // static IP used for browser access: http://IPaddress
static IPAddress gateway(192, 168, 14, 1);
static IPAddress subnet(255, 255, 255, 0);

const int IRledPin =  D4;
const int laserPin =  D0;
const int laserDetectorPin =  D5;
const int IRDetectorPin =  D6;

const char *webpage = 
#include "web.h"
;



void setup()
{
  WiFi.config(ip, gateway, subnet); 
   Wire.begin(D1, D2); /* join i2c bus with SDA=D1 and SCL=D2 of NodeMCU */


  pinMode(IRledPin, OUTPUT);
  pinMode(IRDetectorPin,INPUT);
  
  pinMode(laserPin,OUTPUT);
  pinMode(laserDetectorPin,INPUT);
  
  pinMode(pin_led, OUTPUT);
  WiFi.begin(ssid,password);
  Serial.begin(115200);
  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/",[](){server.send_P(200,"text/html", webpage);});
  
  server.on("/ledstate",toggleLED);
  
  server.on("/ldown",ldown);
  server.on("/lup",lup);
  server.on("/lstop",lstop);
   
  server.on("/rdown",rdown);
  server.on("/rup",rup);
  server.on("/rstop",rstop);

  server.on("/dubleup",dbup);
  server.on("/dbdown",dbdown);
  server.on("/lurd",lurd);
  server.on("/ldru",ldru);
  server.on("/ddstop",ddstop);

  server.on("/laserShot",laserShot);
  server.on("/laserShotNOT",laserShotNOT);
  
  server.on("/irShot",irShot);
  server.on("/irShotNOT",irShotNOT);
  
  server.on("/shieldON",shieldISon);
  server.on("/shieldOFF",shieldISoff);
  server.begin();

  
}

void loop()
{
  
  
  server.handleClient();
  delay(100);
 

  if (digitalRead(laserDetectorPin)==0)
  {
     Serial.println("laser DOOM");
 
  }

   if (digitalRead(IRDetectorPin)==0)
  {
     Serial.println("IR DOOM");
 
  }
}

void toggleLED()
{
  digitalWrite(pin_led,!digitalRead(pin_led));
  server.send(0);
}

void ldown()
{

   Wire.beginTransmission(8); /* begin with device address 8 */
   Wire.write("ldown");  /* sends hello string */
   Wire.endTransmission();    /* stop transmitting */
   server.send(0);
 
}


void lup()
{
 Wire.beginTransmission(8); /* begin with device address 8 */
 Wire.write("lup");  /* sends hello string */
 Wire.endTransmission();    /* stop transmitting */
 server.send(0);
}

void lstop()
{
 Wire.beginTransmission(8); /* begin with device address 8 */
 Wire.write("lstop");  /* sends hello string */
 Wire.endTransmission();    /* stop transmitting */
 server.send(0);
}


void rdown()
{
   Wire.beginTransmission(8); /* begin with device address 8 */
   Wire.write("rdown");  /* sends hello string */
   Wire.endTransmission();    /* stop transmitting */
   server.send(0);
 
}


void rup()
{
 Wire.beginTransmission(8); /* begin with device address 8 */
 Wire.write("rup");  /* sends hello string */
 Wire.endTransmission();    /* stop transmitting */
 server.send(0);

}

void rstop()
{
  
 Wire.beginTransmission(8); /* begin with device address 8 */
 Wire.write("rstop");  /* sends hello string */
 Wire.endTransmission();    /* stop transmitting */
 server.send(0);
}

////////////////////////////////////////////////
void dbup()
{
  //Serial.println("dbup");

 Wire.beginTransmission(8); /* begin with device address 8 */
 Wire.write("dbup");  /* sends hello string */
 Wire.endTransmission();    /* stop transmitting */
 server.send(0);
}

void dbdown()
{
    Serial.println("dbdown");
 Wire.beginTransmission(8); /* begin with device address 8 */
 Wire.write("dbdown");  /* sends hello string */
 Wire.endTransmission();    /* stop transmitting */
 server.send(0);
}

void lurd()
{
  
 Wire.beginTransmission(8); /* begin with device address 8 */
 Wire.write("lurd");  /* sends hello string */
 Wire.endTransmission();    /* stop transmitting */
 server.send(0);
}

void ldru()
{
  
 Wire.beginTransmission(8); /* begin with device address 8 */
 Wire.write("ldru");  /* sends hello string */
 Wire.endTransmission();    /* stop transmitting */
 server.send(0);
}

void ddstop()
{
  
 Wire.beginTransmission(8); /* begin with device address 8 */
 Wire.write("ddstop");  /* sends hello string */
 Wire.endTransmission();    /* stop transmitting */
 server.send(0);
}

/////////////////////////////////////////////////////



void shieldISon()
{
   Wire.beginTransmission(8); /* begin with device address 8 */
 Wire.write("setshieldON");  /* sends hello string */
 Wire.endTransmission();    /* stop transmitting */
 server.send(0);
}

void shieldISoff()
{
   Wire.beginTransmission(8); /* begin with device address 8 */
 Wire.write("setshieldOFF");  /* sends hello string */
 Wire.endTransmission();    /* stop transmitting */
 server.send(0);
}

void irShot()
{
 Serial.println("IRpow");
 digitalWrite(laserPin, HIGH);

}

void irShotNOT()
{
  digitalWrite(laserPin, LOW);
}



void laserShot()
{
  Serial.println("laserShot");
  digitalWrite(laserPin,HIGH);
}

void laserShotNOT()
{
   Serial.println("laserShotNOT");

  digitalWrite(laserPin,LOW);

}
