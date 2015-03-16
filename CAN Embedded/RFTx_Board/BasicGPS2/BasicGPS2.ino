#include <TinyGPS++.h>

#include "SoftwareSerial.h"


SoftwareSerial mySerial(2,3); // RX, TX
//using 0 & 1 doesn't specifically require the serial header, builtin on Arduino
TinyGPS++ gps;


void setup() 
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);

  Serial.println("uBlox Neo 6M");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);

}

void loop() // run over and over
{

}