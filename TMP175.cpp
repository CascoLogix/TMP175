

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
