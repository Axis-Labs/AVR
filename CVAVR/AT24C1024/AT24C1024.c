// main code of library v 1.00     
// Written by Shneider

#pragma used+
unsigned char data;

void Mem24_Write(unsigned int addr,unsigned char data, unsigned char page)
{
 i2c_start();
 i2c_write(DEVICE_ADDR|(page<<7));
 i2c_write(addr>>8);
 i2c_write(addr&0xFF);
 i2c_write(data);
 i2c_stop();
}

unsigned char Mem24_Read(unsigned int addr,unsigned char page)
{
i2c_start();
i2c_write(DEVICE_ADDR|(page<<7));
i2c_write(addr>>8);
i2c_write(addr&0xFF);
i2c_start();
i2c_write((DEVICE_ADDR|(page<<7))+1);
data = i2c_read(0);
i2c_stop();
return data;
}
#pragma used-
