#include "TemperatureManipulator.h"
#include "../Utils/modus.h"
#include "Arduino.h"

namespace Manipulator {

void TemperatureManipulator::setTemperatureOn(int temp) {
	// wait for 2s before warming up
	if (2000 > millis()) {
//		digitalWrite(masterPin, LOW);
		_tw->writeToScreen(false);
		return;
	}
	// start of actual heating proces
	if (temp >= selectedTemp) {
//		digitalWrite(masterPin, LOW);
		_tw->writeToScreen(false);
	} else {
//		digitalWrite(masterPin, HIGH);
//		_tw->writeToScreen(true);

// detect activeDtCycle
		if (currDtCycle == 0) { // set activeDtCycle only at the beginning of cycle
			activeDtCycle = 100; // % warmend
			int dtRatio = selectedTemp - temp; // dtRatio nooit negatief
			if (dtRatio <= 10 && dtRatio >= 0) {
				activeDtCycle = dtRatio * 10; // to %
			} else {
				activeDtCycle = 100; // if out of scope ==> heating
			}
		}

		if (currDtCycle <= activeDtCycle) {
			// blijf aan
			_tw->writeToScreen(true);
		} else {
			// ga uit
			_tw->writeToScreen(false);
		}

		// update currDtCycle
		if (currDtCycle >= 100) {
			currDtCycle = 0;
		} else {
			currDtCycle++;
		}
	}
}

} /* namespace Manipulator */
