#include <Wire.h>
#include "Tiny7Seg.h"

Tiny7Seg seg;

void setup()
{
  Wire.begin();
  seg.init();
  for(int i=5; i>0; i--){
    seg.printInt(i);
    delay(500);
  };
  for(int i=0; i<5; i++){
    seg.printInt(0);
    delay(100);
    seg.off();
    delay(100);
  };
}

void loop()
{
  seg.setDecPoints(1,0);
  delay(50);
  seg.setDecPoints(0,1);
  delay(50);
}