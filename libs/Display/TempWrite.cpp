#include "TempWrite.h"
#include <Arduino.h>

namespace Display {

void TempWrite::writeToScreen(bool isHeating) {
	this->isHeating = isHeating;
}

void TempWrite::refreshScreen() {
	if (isHeating) {
		digitalWrite(_tempPin, HIGH);
	} else {
		digitalWrite(_tempPin, LOW);
	}
}

} /* namespace Input */
