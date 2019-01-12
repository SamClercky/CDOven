#ifndef LIBS_MANIPULATOR_TEMPERATUREMANIPULATOR_H_
#define LIBS_MANIPULATOR_TEMPERATUREMANIPULATOR_H_

#include "../Display/RelaisControl.h"
#include "../Utils/modus.h"
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
}
;

} /* namespace Manipulator */

#endif /* LIBS_MANIPULATOR_TEMPERATUREMANIPULATOR_H_ */
