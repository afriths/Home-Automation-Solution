#include "ldr.h"
#include "Arduino.h"
#include "main.h"

void init_ldr(void)
{
   pinMode(GARDEN_LIGHT, OUTPUT);
   
}
void brightness_control(void)
{
  unsigned int ldr_val;
  // to read the values from LDR sensor connected to A0 pin 
  ldr_val = analogRead(LDR_SENSOR);

  // mapping 0 to 1023 to 255 to 0
  ldr_val = (1023 - ldr_val)/4;

  // To assign duty cycle to LED based LDR value
  analogWrite(GARDEN_LIGHT, ldr_val); 
  delay(100);  
}
