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


#ifndef TMP175_h
#define TMP175_h


#include <stdint.h>


class TMP175 {
public:
	TMP175();								// Constructor
	
	// Temp sensor access methods
	void begin();							// Initialize interfaces
	void init();							// Configure the temperature sensor IC
	int16_t getTemperature();				// Get temperature data
	float getTemperature(uint8_t units);	// Get temperature data
	int32_t getTempC();						// Get temperature data
	int32_t getTempF();						// Get temperature data
	void setTempCalOffset(int16_t);			// Save a temp cal value
	
private:
	void restoreTempCalOffset();			// Restore the temp cal value
};
#endif // TMP175_h