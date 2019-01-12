#include "TemperatureManipulator.h"
#include "../Utils/modus.h"
#include "Arduino.h"

namespace Manipulator {

void TemperatureManipulator::setTemperatureOn(int temp) {
	if (temp >= 26) {
		digitalWrite(masterPin, LOW);
	} else {
		digitalWrite(masterPin, HIGH);
	}
}

} /* namespace Manipulator */
