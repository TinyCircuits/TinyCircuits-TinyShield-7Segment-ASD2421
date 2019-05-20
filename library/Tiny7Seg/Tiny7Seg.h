#ifndef Tiny7Seg_h
#define Tiny7Seg_h

#include <inttypes.h>

class Tiny7Seg {
public:
Tiny7Seg();
void init();
void off();
void write(uint8_t, uint8_t);
void writeInt(uint8_t,uint8_t);
void printInt(int);
void setDecPoints(uint8_t,uint8_t);
uint8_t lastWriteToReg[2];
uint8_t decPointState[2];
};
#endif