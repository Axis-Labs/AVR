This library allows to use AT24C1024B, AT24C1024BW memory ic with AVR Family MCU's 
uses CVAVR C compiler v 2.04.4a and use i2c library. 
e.g #include <i2c.h>
    #include "AT24C1024.h"
    
    initalize peripheral
     ..
     
     Mem24_Write(0x01,0x02,1);

     ..
     var1 = Mem24_Read(0x01,1);
    
