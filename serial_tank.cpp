#include "serial_tank.h"
#include "Arduino.h"
#include "main.h"

unsigned int volume_value;
unsigned char valueh, valuel;

void init_serial_tank(void) 
{

/*tobegin the serial communication between serial tank and arduino board*/
    Serial.begin(19200);
    Serial.write(0xFF); //sincroniza comunicação
    Serial.write(0xFF);
    Serial.write(0xFF);   
}

unsigned int volume(void)
{
  /* To read the volume of water */
  Serial.write(VOLUME);
  /* wait for data */
  while(!Serial.available());
  /*reading higher byte*/
  valueh = Serial.read();
  while(!Serial.available());
  /*reading lower byte*/
  valuel = Serial.read();
  /* Combining Higher byte and lower byte */
  volume_value = valueh << 8 | valuel; 
  /*return volume of the water*/
  return volume_value;  
}
void enable_inlet(void)
{
  Serial.write(INLET_VALVE);
  Serial.write(ENABLE);
}  
void disable_inlet(void)
{
  Serial.write(INLET_VALVE);
  Serial.write(DISABLE);
}  
void enable_outlet(void)
{
  Serial.write(OUTLET_VALVE);
  Serial.write(ENABLE);
    
}
void disable_outlet(void)
{  
  Serial.write(OUTLET_VALVE);
  Serial.write(DISABLE);
    
}
