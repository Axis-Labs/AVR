// Peripheral init V 1.00

#define tiny2313.h
unsigned int UBRR_value;
void core_init(void)
{
// Crystal Oscillator division factor: 1
#pragma optsize-
CLKPR=0x80;
CLKPR=0x00;
#ifdef _OPTIMIZE_SIZE_
#pragma optsize+
#endif
}

void UART_init(unsigned long baudrate)
{
 #ifdef mega168.h
 UBRR_value = (F_CORE/(16*baudrate))-1;
 UCSR0A = 0x00;
 UCSR0B = 0x18;
 UCSR0C = 0x06;
 UBRR0H = UBRR_value>>8;
 UBRR0L = UBRR_value&0xFF;
 #endif  
 
 #ifdef tiny2313.h
 UBRR_value = (F_CORE/(16*baudrate))-1;
 UCSRA = 0x00;
 UCSRB = 0x18;
 UCSRC = 0x06;
 UBRRH = UBRR_value>>8;
 UBRRL = UBRR_value&0xFF; 
 #endif
}

/* EEPROM Load and Store subroutines */
              /* Writing by Shneider*/

#pragma used+

void EEwrite(unsigned int Address, unsigned char Data)
{
/* Wait for completion of previous write */
while(EECR & (1<<EEPE));
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

// #define VREF_TYPE 0x00 // uncomment For External voltage reference.
// #define VREF_TYPE 0x03 // uncomment For Internal Voltage reference.
// #define VREF_TYPE 0x01 // uncomment For Analog supply voltage reference. 
  



void ADC_init(void)
{
  ADMUX = VREF_TYPE & 0xFF;

}
#pragma used-
//=======================================================