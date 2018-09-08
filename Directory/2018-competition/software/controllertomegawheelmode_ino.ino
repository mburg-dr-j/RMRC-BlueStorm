/*                                          __                    
   ____ ___  ___  _____________  __________/ /_  __  ___________ _
  / __ `__ \/ _ \/ ___/ ___/ _ \/ ___/ ___/ __ \/ / / / ___/ __ `/
 / / / / / /  __/ /  / /__/  __/ /  (__  ) /_/ / /_/ / /  / /_/ / 
/_/ /_/ /_/\___/ /   \___/\/_// /  /____/_.___/\__,_/_/   \__, /  
   _________  / /_  ____  / /_(_)_________               /____/   
  / ___/ __ \/ __ \/ __ \/ __/ / ___/ ___/                        
 / /  / /_/ / /_/ / /_/ / /_/ / /__(__  )                         
/_/   \____/_.___/\____/\__/_/\___/____/ 

Victor Li '18, Maddie Rogers '17, Pat Madden '18, 2017
Powered by nihilism, coffee, and some curiosity 
*/

//FOR USE WITH TETHER 

//---! XBee incompatible, use only with USB shield on mega  
//---! for direct communication between controller and mega (requires an arduino with USB shield and PS4 controller)

// ---! Code presented is heavily modifed from the example
// ---! sketch for the PS4 USB library - developed by Kristian Lauszus
// ---! For more information visit his blog: http://blog.tkjelectronics.dk/ 

// ---! I tried to write this as cleanly as I could, though
// ---!  if you have any questions I can be reached at patrickvincentmadden@gmail.com 

#include <PS4USB.h>
#include <usbhub.h>
#include <PS4Parser.h>

#include <Dynamixel.h>
#include <DynamixelConsole.h>
#include <DynamixelInterface.h>
#include <DynamixelMotor.h>

// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#include <SPI.h>
#endif

USB Usb;
PS4USB PS4(&Usb);

char myArray[100];
int i=0;
String str;
byte incoming=0;

int speedSelect = 1; //default set speedA -> speedB -> speedC -> speedA ...

int speedA = 750;
int speedB = 1000;
int speedC = 150;

int a = 0;
int b = 50; //hack value, turning right or left on very low speeds (like 150) lowers torque intolerably so this should help

int invert = 1; //default set NO
bool inverted = false;

DynamixelInterface &interface=*createSerialInterface(Serial);
DynamixelMotor motor1(interface, 55);
DynamixelMotor motor2(interface, 54);
DynamixelMotor motor3(interface, 60);
DynamixelMotor motor4(interface, 58);

void forward() {
  switch(speedSelect) {
     case 1:
      Serial.print("case 1");
      motor1.speed(speedA);
      motor2.speed(-speedA);
      motor3.speed(speedA);
      motor4.speed(-speedA);  
     break;
     case 2:
      Serial.print("case 2");
      motor1.speed(speedB);
      motor2.speed(-speedB);
      motor3.speed(speedB);
      motor4.speed(-speedB);
     break;
     case 3:
      Serial.print("case 3");
      motor1.speed(speedC);
      motor2.speed(-speedC);
      motor3.speed(speedC);
      motor4.speed(-speedC);
     break;
    }
}
void backward() {
  switch(speedSelect) {
     case 1:
     Serial.print("case 1");
      motor1.speed(-speedA);
      motor2.speed(speedA);
      motor3.speed(-speedA);
      motor4.speed(speedA);  
     break;
     case 2:
      Serial.print("case 2");
      motor1.speed(-speedB);
      motor2.speed(speedB);
      motor3.speed(-speedB);
      motor4.speed(speedB);
     break;
     case 3:
      Serial.print("case 3");
      motor1.speed(-speedC);
      motor2.speed(speedC);
      motor3.speed(-speedC);
      motor4.speed(speedC);
     break;
    }
}
void right() {
  switch(speedSelect) {
     case 1:
      Serial.print("case 1");
      motor1.speed(speedA);
      motor2.speed(speedA);
      motor3.speed(speedA);
      motor4.speed(speedA);  
     break;
     case 2:
      Serial.print("case 2");
      motor1.speed(speedB);
      motor2.speed(speedB);
      motor3.speed(speedB);
      motor4.speed(speedB);
     break;
     case 3:
      Serial.print("case 3");
      motor1.speed(speedC+b);
      motor2.speed(speedC+b);
      motor3.speed(speedC+b);
      motor4.speed(speedC+b);
     break;
    }
}
void left() {
  switch(speedSelect) {
     case 1:
     Serial.print("case 1");
      motor1.speed(-speedA);
      motor2.speed(-speedA);
      motor3.speed(-speedA);
      motor4.speed(-speedA);  
     break;
     case 2:
      Serial.print("case 2");
      motor1.speed(-speedB);
      motor2.speed(-speedB);
      motor3.speed(-speedB);
      motor4.speed(-speedB);
     break;
     case 3:
      Serial.print("case 3");
      motor1.speed(-speedC-b);
      motor2.speed(-speedC-b);
      motor3.speed(-speedC-b);
      motor4.speed(-speedC-b);
     break;
    }
}

void north() {
  switch(invert){
    case 1:
      forward();  
    break;
    case 2:
      backward();  
    break;
    default:
    //empty
    break;
  }  
}
void south() {
  switch(invert){
    case 1:
      backward();  
    break;
    case 2:
      forward();  
    break;
    default:
    //empty
    break;
  }    
}
// changes made here, if issues switch back to original
void east() {
  switch(invert){
    case 1:
      right();  
    break;
    case 2:
      right(); // left();
    break;
    default:
    //empty
    break;
  }   
}
void west() {
  switch(invert){
    case 1:
      left();  
    break;
    case 2:
      left(); // right();
    break;
    default:
    //empty
    break;
  }   
}
// end changes made

void setup() {
  Serial.begin(57600);
  interface.begin(1000000);
#if !defined(__MIPSEL__)
  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
#endif
  if (Usb.Init() == -1) {
    //Serial.print(F("\r\nOSC did not start"));
    while (1); // Halt
  }
  delay(100);
    motor1.jointMode();
    motor2.jointMode();
    motor3.jointMode();
    motor4.jointMode();
  delay(100);
    while (! Serial) {
    delay(1);
  }
    motor1.position(a);
    motor2.position(a);
    motor3.position(a);
    motor4.position(a);
  delay(100);
    motor1.wheelMode();
    motor2.wheelMode();
    motor3.wheelMode();
    motor4.wheelMode();
  delay(100);
    while (! Serial) {
    delay(1);
  }
}

void loop() {
  Usb.Task();
  if (PS4.connected()) {
    if (PS4.getButtonClick(UP)) {
      Serial.println("hit");        
      north();
    }
    if (PS4.getButtonClick(RIGHT)) {
      Serial.println("hit");
      east();
    }
    if (PS4.getButtonClick(DOWN)) {
      Serial.println("hit");
      south();  
    }
    if (PS4.getButtonClick(LEFT)) {
      Serial.println("hit");
      west();
    }
    if (PS4.getButtonClick(CROSS)) {
      Serial.println("hit");
      motor1.speed(0);
      motor2.speed(0);
      motor3.speed(0);
      motor4.speed(0);
      motor1.speed(0);
      motor2.speed(0);
      motor3.speed(0);
      motor4.speed(0);
    }
    if (PS4.getButtonClick(SQUARE)) {
      Serial.println("hit");
      if(inverted)
      {
        invert = 1;
        inverted = false;
        Serial.print("invert = ");
        Serial.println(invert); 
      }else 
      {
        invert = 2;
        inverted = true;
        Serial.print("invert = ");
        Serial.println(invert);
      }
    }
    if (PS4.getButtonClick(TRIANGLE)) {
      Serial.println("hit");
      if(speedSelect==3)
      {
        speedSelect = 1;
        Serial.print(speedSelect);
      }else
      {
        speedSelect++;
        Serial.print(speedSelect);  
      }
    }
//    if (PS4.getButtonClick(CIRCLE) {

//    }
  }
}
