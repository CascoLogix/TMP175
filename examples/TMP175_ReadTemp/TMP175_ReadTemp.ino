

#include <Wire.h>
#include <TMP175.h>


TMP175 TMP175;


int32_t tempData;


void setup()
{
  Serial.begin(9600);
  TMP175.begin();
}


void loop()
{
  Serial.print("Deg C: ");
  tempData = TMP175.getTempC();
  Serial.print(tempData / 10000);
  Serial.print(".");
  Serial.print(tempData % 10000);
  
  tempData = TMP175.getTempF();
  Serial.print(" | Deg F: ");
  Serial.print(tempData / 10000);
  Serial.print(".");
  Serial.println(tempData % 10000);
  
  delay(1000);
}
