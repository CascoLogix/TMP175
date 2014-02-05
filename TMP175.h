

#ifndef TMP175_h
#define TMP175_h


#include <stdint.h>


class TMP175 {
public:
	TMP175();								// Constructor
	
	// Temp sensor access methods
	void begin();							// Initialize interfaces
	int16_t getTemperature();				// Get temperature data
	float getTemperature(uint8_t units);	// Get temperature data
	int32_t getTempC();						// Get temperature data
	int32_t getTempF();						// Get temperature data
	void setTempCalOffset(int16_t);	// Save a temp cal value
		
private:
	void configTemperature();				// Configure the temperature sensor IC
	void restoreTempCalOffset();			// Restore the temp cal value
};
#endif // TMP175_h