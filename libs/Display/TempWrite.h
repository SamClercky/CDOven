#ifndef LIBS_DISPLAY_TEMPWRITE_H_
#define LIBS_DISPLAY_TEMPWRITE_H_

#include "IDisplay.h"
#include <Arduino.h>

namespace Display {

class TempWrite: IDisplay {
public:
	TempWrite(int tempPin) :
			_tempPin(tempPin) {
	}

	void writeToScreen(float x, int line = 0) {
#ifdef DEBUG
		Serial.println("ERROR: no writeToScreen(float, int) implementation in this context");
#endif
	}
	void writeToScreen(String x, int line = 0) {
#ifdef DEBUG
		Serial.println("ERROR: no writeToScreen(float, int) implementation in this context");
#endif
	}
	// write to relay
	void writeToScreen(bool isHeating);
	// should be called during loop()
	void refreshScreen();
	// should be called during setup()
	void initDisplay() {
		pinMode(_tempPin, OUTPUT);
	}
	virtual ~TempWrite() {
	}
private:
	int _tempPin;
	bool isHeating;
};

} /* namespace Input */

#endif /* LIBS_DISPLAY_TEMPWRITE_H_ */
