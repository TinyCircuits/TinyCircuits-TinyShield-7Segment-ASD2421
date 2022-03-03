/*
TinyDuino Accelerometer & 7Segment display Demo

This example code is in the public domain.

January 12, 2015 by Tony Batey

https://tiny-circuits.com/

*/

#include "Wire.h"
#include "BMA250.h"
#include "Tiny7Seg.h"

BMA250 accel;
Tiny7Seg seg;

void setup()
{
  Wire.begin();
  seg.init();                                              //This initializes the I/O expander on the 7 segment display
  accel.begin(BMA250_range_2g, BMA250_update_time_64ms);    //This sets up the BMA250 accelerometer
}

void loop()
{
  accel.read();                                          //This function gets new data from the accelerometer
  float angle = atan2(accel.Y, accel.X) * 180.0/PI;      //math to calculate the angle from the sensor readings
  angle = constrain(angle-90.0,-90.0,90.0);              //We only want angles from -90 to 90
  seg.printInt(abs(angle));                              //Then, we'll just display the absolute value
  delay(100);                                            //We'll make sure we're over the 64ms update time set on the BMA250
}
