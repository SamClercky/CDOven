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

namespace Manipulator {

class ModusManipulator {
public:
	ModusManipulator(Display::LCD* lcd, Display::RelaisControl* rc);
	virtual ~ModusManipulator();

	void printNewModus(Utils::Modus modus);
	void printFromInt(int data);

private:
	Display::LCD* lcd;
	Display::RelaisControl* rc;
};

} /* namespace Manipulator */

#endif /* LIBS_MANIPULATOR_MODUSMANIPULATOR_H_ */
