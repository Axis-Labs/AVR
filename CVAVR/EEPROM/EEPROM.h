// all prototypes functions for lib EEPROM V 1.4

void EEwrite(unsigned int Address, unsigned char Data) // write byte to memory array. 

unsigned char EEread(unsigned int Address) // read byte from memory.

void EEword_write(unsigned int addres, unsigned int word)  // write word from EEPROM memory (contains 2 field).

unsigned int EEword_read(unsigned int addres) // Reading two bytes serialy.

// for bugs mail to: axislabscode@gmail.com
