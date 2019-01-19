#ifndef LIBS_MANIPULATOR_TEMPERATUREMANIPULATOR_H_
#define LIBS_MANIPULATOR_TEMPERATUREMANIPULATOR_H_

#include "../Utils/modus.h"
#include "../Display/lcd.h"
#include "Arduino.h"

namespace Manipulator {

/**
 * TODO: delete commented code
 */
class TemperatureManipulator {
public:
	TemperatureManipulator(uint8_t masterpin) :
			masterPin(masterpin)
//			rc(rc)
	{
	}
	void init() {
		pinMode(masterPin, OUTPUT);
	}

	void setSelectedTemp(uint8_t selectedPin) {
		selectedTemp = selectedPin;
}

//	void setNewModus(Utils::Modus modus) {
//		if (modus != this->modus) {
//			this->modus = modus;
//		}
//	}

	void setTemperatureOn(int temp);

private:
//Display::RelaisControl* rc;
//Utils::Modus modus;
	uint8_t masterPin;
uint8_t selectedTemp = 0;
}
;

} /* namespace Manipulator */

#endif /* LIBS_MANIPULATOR_TEMPERATUREMANIPULATOR_H_ */
