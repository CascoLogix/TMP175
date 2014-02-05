/** 
 *  TMP175.h
 *  
 *  This is a library for interfacing to the Texas Instruments TMP175 
 *  temperature measurement IC.  
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


#include <TMP175.h>
#include <Wire.h>


#define TMP175_I2C_ADDRESS 		(0x49)  /* I2C address for digital thermometer */


// Constructor
TMP175::TMP175()
{

}


// Initialize interfaces
void TMP175::begin()
{  
	Wire.begin();        					// Join I2C bus
	this->configTemperature();				// Configure the Temperature IC
}


void TMP175::configTemperature()				// Configure the temperature sensor IC
{
	// Setup configuration register 12-bit
	Wire.beginTransmission(TMP175_I2C_ADDRESS);    
	Wire.write(1);
	Wire.write(0b01100000);
	Wire.endTransmission();

	// Setup Digital THERMometer pointer register to 0
	Wire.beginTransmission(TMP175_I2C_ADDRESS);    
	Wire.write(0);
	Wire.endTransmission();
}


// Get temperature data
int16_t TMP175::getTemperature()
{
	static uint16_t rawTemp;
	static uint16_t sign;
	
    Wire.requestFrom(TMP175_I2C_ADDRESS, 2);
    rawTemp = Wire.read();
	rawTemp = rawTemp << 8;
    rawTemp = rawTemp | Wire.read();
	
	sign = rawTemp & 0x8000;				// Save the sign bit
	rawTemp = rawTemp & ~0x8000;			// Clear the sign bit
	rawTemp = rawTemp >> 4;					// Right-align the 12-bit data field
	rawTemp = rawTemp | sign;				// Restore the sign bit
	
	return rawTemp;
}


// Get temperature data
int32_t TMP175::getTempC()	
{
	static int32_t TempC;
	
	TempC = this->getTemperature();
	TempC = (TempC * 625);

	return TempC;
}


// Get temperature data
int32_t TMP175::getTempF()	
{
	static int32_t TempF;
	
	TempF = this->getTemperature();
	TempF = (TempF * 1125) + 320000;
	
	return TempF;
}


// Save a temp cal value
void TMP175::setTempCalOffset(int16_t)
{

}


// Restore the temp cal value
void TMP175::restoreTempCalOffset()
{

}
