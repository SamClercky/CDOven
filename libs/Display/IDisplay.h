/*
 * IDisplay.h
 *
 *  Created on: 8 nov. 2018
 *      Author: clercky
 */

#ifndef LIBS_IDISPLAY_H_
#define LIBS_IDISPLAY_H_

#include <WString.h>

namespace Display {
class IDisplay { // @suppress("Class has a virtual method and non-virtual destructor")
public:
	// Call this to write to screen
	virtual void writeToScreen(float x, int line = 0) = 0;
	virtual void writeToScreen(String x, int line = 0) = 0;
	// should be called during loop()
	virtual void refreshScreen() = 0;
	// should be called during setup()
	virtual void initDisplay();
};
}

#endif /* LIBS_IDISPLAY_H_ */
