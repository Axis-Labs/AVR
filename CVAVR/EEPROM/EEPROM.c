
/* EEPROM Load and Store subroutines */
              /* Writing by Shneider*/

#pragma used+

void EEwrite(unsigned int Address, unsigned char Data)
{
/* Wait for completion of previous write */
while(EECR & (1<<EEPE))
;
/* Set up address and Data Registers */
EEAR = Address;
EEDR = Data;
/* Write logical one to EEMPE */
EECR |= (1<<EEMPE);
/* Start eeprom write by setting EEPE */
EECR |= (1<<EEPE);
}

unsigned char EEread(unsigned int Address)
{
/* Wait for completion of previous write */
while(EECR & (1<<EEPE))
;
/* Set up address register */
EEAR = Address;
/* Start eeprom read by writing EERE */
EECR |= (1<<EERE);
/* Return data from Data Register */
return EEDR;

}


void EEword_write(unsigned int addres, unsigned int word)
{
     
     EEwrite(addres, word>>8&0x00ff);
     EEwrite(addres+1,word&0x00ff);
     
}

unsigned int EEword_read(unsigned int addres)
{
      unsigned int buff;
      
    buff = EEread(addres);
    buff = buff<<8;    
    buff |= EEread(addres+1); 
    return buff;
    
    
}
#pragma used-
//=======================================================