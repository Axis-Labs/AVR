//==========================================================
// AT24C1024 FUNCTION LIBRARY V 1.00
// Written by Shneider
//==========================================================  


#define DEVICE_ADDR 0xA4
#include "AT24C1024.c"

#pragma used+

void Mem24_Write(unsigned int addr, unsigned char data, unsigned char page); // Write byte to memory. e.g Mem24_Write(0x01,0x02,0)
unsigned char Mem24_Read(unsigned int addr, unsigned char page); // Read byte from memory.  e.g Mem24_Read(0x01,0)

#pragma used-

