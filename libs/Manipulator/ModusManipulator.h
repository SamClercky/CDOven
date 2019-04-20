/*
 * ModusManipulator.h
 *
 *  Created on: 16 nov. 2018
 *      Author: clercky
 */

#ifndef LIBS_MANIPULATOR_MODUSMANIPULATOR_H_
#define LIBS_MANIPULATOR_MODUSMANIPULATOR_H_

#include "../Utils/modus.h"
#include "../Display/lcd.h"
#include "../Display/RelaisControl.h"
#include <Arduino.h>

namespace Manipulator {

class ModusManipulator {
public:
	ModusManipulator(Display::LCD* lcd, Display::RelaisControl* rc);
	virtual ~ModusManipulator();

	void printNewModus(Utils::Modus modus, int masterPin = -1);
	void printFromInt(int data, int masterPin = -1, int bleInput = -1);
//	void disableMasterPinSafeMode(int masterPin = -1) {
//		if (masterPin != -1) {
//			digitalWrite(masterPin, LOW);
//		}
//	}

private:
	Display::LCD* lcd;
	Display::RelaisControl* rc;
};

} /* namespace Manipulator */

#endif /* LIBS_MANIPULATOR_MODUSMANIPULATOR_H_ */
