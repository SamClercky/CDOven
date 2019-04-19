#ifndef LIBS_MANIPULATOR_TEMPERATUREMANIPULATOR_H_
#define LIBS_MANIPULATOR_TEMPERATUREMANIPULATOR_H_

#include "../Utils/modus.h"
#include "../Display/lcd.h"
#include "../Display/TempWrite.h"
#include "Arduino.h"

namespace Manipulator {

/**
 * TODO: delete commented code
 */
class TemperatureManipulator {
public:
	TemperatureManipulator(Display::TempWrite* tw) :
//			rc(rc)
			_tw(tw) {
	}

	void setSelectedTemp(unsigned int newTemp) {
		if (selectedTemp != newTemp && newTemp < 400) { // check of er een nieuwe update nodig is van de data en ga nooit over 400 graden C
			selectedTemp = newTemp;
			resetDtCycle(); // reset DtCycle
		}
	}

//	void setNewModus(Utils::Modus modus) {
//		if (modus != this->modus) {
//			this->modus = modus;
//		}
//	}

	void setTemperatureOn(int temp);

	void resetDtCycle() {
		currDtCycle = 0;
		activeDtCycle = 100;
	}

private:
//Display::RelaisControl* rc;
//Utils::Modus modus;
//	uint8_t masterPin;
	unsigned int selectedTemp = 0;
	Display::TempWrite* _tw;
	int currDtCycle = 0; // huidige voortgang in dtcycle
	int activeDtCycle = 100;
//	int activeDtCycle = 100; // % warmend
}
;

} /* namespace Manipulator */

#endif /* LIBS_MANIPULATOR_TEMPERATUREMANIPULATOR_H_ */
