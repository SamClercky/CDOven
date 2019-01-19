#include "TemperatureManipulator.h"
#include "../Utils/modus.h"
#include "Arduino.h"

namespace Manipulator {

void TemperatureManipulator::setTemperatureOn(int temp) {
	// wait for 2s
	if (2000 > millis()) {
		digitalWrite(masterPin, LOW);
		return;
	}

	if (temp >= selectedTemp) {
		digitalWrite(masterPin, LOW);
	} else {
		digitalWrite(masterPin, HIGH);
	}
}

} /* namespace Manipulator */
