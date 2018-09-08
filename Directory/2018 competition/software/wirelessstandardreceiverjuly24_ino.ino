/*                                          __                    
   ____ ___  ___  _____________  __________/ /_  __  ___________ _
  / __ `__ \/ _ \/ ___/ ___/ _ \/ ___/ ___/ __ \/ / / / ___/ __ `/
 / / / / / /  __/ /  / /__/  __/ /  (__  ) /_/ / /_/ / /  / /_/ / 
/_/ /_/ /_/\___/ /   \___/\/_// /  /____/_.___/\__,_/_/   \__, /  
   _________  / /_  ____  / /_(_)_________               /____/   
  / ___/ __ \/ __ \/ __ \/ __/ / ___/ ___/                        
 / /  / /_/ / /_/ / /_/ / /_/ / /__(__  )                         
/_/   \____/_.___/\____/\__/_/\___/____/ 

Victor Li '18, Maddie Rogers '17, Pat Madden '18
Mentored by Conner Caruso '16 and Dr. J 2017
Powered by nihilism, coffee, and some curiosity 
*/

// ---! Compatible with wirelessStandardSENDERJuly24  
// ---! for wireless communication between XBees      
// ---! Requires one XBee with USB shield (attached to PS4
// ---! controller), and one XBee receiver on chassis
// ---! default start is on wheelMode                

// ---! Code presented is heavily modifed from the example
// ---! sketch for the PS4 USB library - developed by Kristian Lauszus
// ---! For more information visit his blog: http://blog.tkjelectronics.dk/ 

// ---! I tried to write this as cleanly as I could, though
// ---!  if you have any questions I can be reached at patrickvincentmadden@gmail.com 

// ---! The untested, experimental part of this is the addition of jointMode control,
// ---!  which in theory will give the driver further accuracy in navigation
// ---!  although it will require extensive testing as I'm unsure how it'll work (july24)               !---
           
// SoftwareSerial to communicate with the XBee:
#include <SoftwareSerial.h>
// XBee's DOUT (TX) is connected to pin 2 (Arduino's Software RX)
// XBee's DIN (RX) is connected to pin 3 (Arduino's Software TX)
SoftwareSerial XBee(52, 3); // RX, TX

#include <Dynamixel.h>
#include <DynamixelConsole.h>
#include <DynamixelInterface.h>
#include <DynamixelMotor.h>

char myArray[100];
int i=0;
String str;
byte incoming=0;

int a = 0; //angle for motor position in jointMode
int angleIncrement = 2;

int invert = 1; //default set NO
bool inverted = false;

bool wheel;    

int speedSelect = 1; //intial set: speedA

int speedA = 750;
int speedB = 1000;
int speedC = 200;

DynamixelInterface &interface=*createSerialInterface(Serial2);
DynamixelMotor motor1(interface, 55);
DynamixelMotor motor2(interface, 61);
DynamixelMotor motor3(interface, 60);
DynamixelMotor motor4(interface, 58);

void setup() {
  XBee.begin(57600);
  //Serial.begin(57600);
  interface.begin(1000000);
  delay(10);
    motor1.jointMode();
    motor2.jointMode();
    motor3.jointMode();
    motor4.jointMode();
  delay(10);
    motor1.position(a);
    motor2.position(a);
    motor3.position(a);
    motor4.position(a);
  delay(10);
    motor1.wheelMode();
    motor2.wheelMode();
    motor3.wheelMode();
    motor4.wheelMode();
  delay(10);
    while (! Serial) {
    delay(1);
  }
}

//for jointMode
void jointNorth() {
    switch(invert)
    {
      case1:
        motor1.position(a);
        motor2.position(-a);
        motor3.position(a);
        motor4.position(-a);
      break;
      case2:
        motor1.position(-a);
        motor2.position(a);
        motor3.position(-a);
        motor4.position(a);      
      break;
    }
}
void jointSouth() {
    switch(invert)
    {
      case1:
        motor1.position(-a);
        motor2.position(a);
        motor3.position(-a);
        motor4.position(a);
      break;
      case2:
        motor1.position(a);
        motor2.position(-a);
        motor3.position(a);
        motor4.position(-a);      
      break;
    }
}
void jointRight() {
    motor1.position(a);
    motor2.position(a);
    motor3.position(a);
    motor4.position(a);
}
void jointLeft() {
    motor1.position(-a);
    motor2.position(-a);
    motor3.position(-a);
    motor4.position(-a);
}

//for wheelMode
void wheelForward() {
  switch(speedSelect) {
     case 1:
      //Serial.print("case 1");
      motor1.speed(speedA);
      motor2.speed(-speedA);
      motor3.speed(speedA);
      motor4.speed(-speedA);  
     break;
     case 2:
      //Serial.print("case 2");
      motor1.speed(speedB);
      motor2.speed(-speedB);
      motor3.speed(speedB);
      motor4.speed(-speedB);
     break;
     case 3:
      //Serial.print("case 3");
      motor1.speed(speedC);
      motor2.speed(-speedC);
      motor3.speed(speedC);
      motor4.speed(-speedC);
     break;
    }
}
void wheelBackward() {
  switch(speedSelect) {
     case 1:
     ///Serial.print("case 1");
      motor1.speed(-speedA);
      motor2.speed(speedA);
      motor3.speed(-speedA);
      motor4.speed(speedA);  
     break;
     case 2:
      //Serial.print("case 2");
      motor1.speed(-speedB);
      motor2.speed(speedB);
      motor3.speed(-speedB);
      motor4.speed(speedB);
     break;
     case 3:
      //Serial.print("case 3");
      motor1.speed(-speedC);
      motor2.speed(speedC);
      motor3.speed(-speedC);
      motor4.speed(speedC);
     break;
    }
}
void wheelRight() {
  switch(speedSelect) {
     case 1:
      //Serial.print("case 1");
      motor1.speed(speedA);
      motor2.speed(speedA);
      motor3.speed(speedA);
      motor4.speed(speedA);  
     break;
     case 2:
      //Serial.print("case 2");
      motor1.speed(speedB);
      motor2.speed(speedB);
      motor3.speed(speedB);
      motor4.speed(speedB);
     break;
     case 3:
      //Serial.print("case 3");
      motor1.speed(speedC);
      motor2.speed(speedC);
      motor3.speed(speedC);
      motor4.speed(speedC);
     break;
    }
}
void wheelLeft() {
  switch(speedSelect) {
     case 1:
     //Serial.print("case 1");
      motor1.speed(-speedA);
      motor2.speed(-speedA);
      motor3.speed(-speedA);
      motor4.speed(-speedA);  
     break;
     case 2:
      //Serial.print("case 2");
      motor1.speed(-speedB);
      motor2.speed(-speedB);
      motor3.speed(-speedB);
      motor4.speed(-speedB);
     break;
     case 3:
      //Serial.print("case 3");
      motor1.speed(-speedC);
      motor2.speed(-speedC);
      motor3.speed(-speedC);
      motor4.speed(-speedC);
     break;
    }
}

void wheelNorth() {
  switch(invert){
    case 1:
      wheelForward();  
    break;
    case 2:
      wheelBackward();  
    break;
    default:
    //empty
    break;
  }  
}
void wheelSouth() {
  switch(invert){
    case 1:
      wheelBackward();  
    break;
    case 2:
      wheelForward();  
    break;
    default:
    //empty
    break;
  }    
}

void loop() {
  if(XBee.available()) {
    incoming=XBee.read();
    
    //wheelMode
    if (incoming==1) { //north     
      wheelNorth();
    }
    if (incoming==2) { //wheelRight
      wheelRight();
    }
    if (incoming==3) { //wheelSouth
      wheelSouth();  
    }
    if (incoming==4) { //wheelLeft
      wheelLeft();
    }
    if (incoming==5) { //halt motors
      motor1.speed(0);
      motor2.speed(0);
      motor3.speed(0);
      motor4.speed(0);
      motor1.speed(0);
      motor2.speed(0);
      motor3.speed(0);
      motor4.speed(0);
      //Serial.println("");
    }
    if (incoming==7) { //speed select
      if(speedSelect==3)
      {
        speedSelect = 1;
        //Serial.print(speedSelect);
      }else
      {
        speedSelect++;
        //Serial.print(speedSelect);  
      }
    }

    //compatible with both modes
    if (incoming==6) { //invert up and down
      if(inverted)
      {
        invert = 1;
        inverted = false;
        //Serial.print("invert = ");
        //Serial.println(invert); 
      }else 
      {
        invert = 2;
        inverted = true;
        //Serial.print("invert = ");
        //Serial.println(invert);
      }
    } 
    if (incoming==8) { //switch jointMode and wheelMode (WARNING, may cause undesired movement if in region not available in jointMode, so test, test, test)
      
      if(wheel)
      {
        wheel = false;
        //Serial.println("jointMode enabled");
 
      }else 
      {
        wheel = true;
        //Serial.println("wheelMode enabled");
      }
    }     
 
    //jointMode
    if (incoming==11) { //jointNorth
      jointNorth();
    }
    if (incoming==12) { //jointRight
      jointRight();
    }
    if (incoming==13) { //jointSouth
      jointSouth();
    }
    if (incoming==14) { //jointLeft
      jointLeft();
    }
    if (incoming==9) {  //angle up
      a = (a + angleIncrement);
      //Serial.println(a);   
    }
    if (incoming==10) { //angle down
      a = (a - angleIncrement);
      //Serial.println(a);   
    }
  }
}
