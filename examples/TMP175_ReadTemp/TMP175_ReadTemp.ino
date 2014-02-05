/** 
 *  TMP175_ReadTemp.ino
 *  
 *  This is a demonstration for reading from the Texas Instruments TMP175 
 *  I2C temperature measurement IC.   
 *
 *  Copyright (C) 2014  Clint Stevenson (CascoLogix http://cascologix.com)
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


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
