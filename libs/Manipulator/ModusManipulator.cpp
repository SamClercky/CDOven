/*
 * ModusManipulator.cpp
 *
 *  Created on: 16 nov. 2018
 *      Author: clercky
 */

#include "ModusManipulator.h"

namespace Manipulator {

ModusManipulator::ModusManipulator(Display::LCD* lcd, Display::RelaisControl* rc) :
		lcd(lcd), rc(rc) {
	// TODO Auto-generated constructor stub

}

ModusManipulator::~ModusManipulator() {
	// TODO Auto-generated destructor stub
}

void ModusManipulator::printNewModus(Utils::Modus modus, int masterPin) {
//	disableMasterPinSafeMode(masterPin);
	lcd->writeToScreen(Utils::ModusHelper::getString(modus), 0);
	rc->writeToScreen(static_cast<uint8_t>(Utils::ModusHelper::getByte(modus)));
}

void ModusManipulator::printFromInt(int data, int masterPin, int bleInput) {
	int modus = (bleInput != -1) ? bleInput : data;
	printNewModus(static_cast<Utils::Modus>(modus), masterPin);
}

} /* namespace Manipulator */
