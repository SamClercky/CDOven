#ifndef LIBS_DISPLAY_SEVENSEGMEND_H_
#define LIBS_DISPLAY_SEVENSEGMEND_H_

#include "IDisplay.h"
#include <LedControl.h>

namespace Display {

class SevenSegmend: IDisplay {
public:
	SevenSegmend() :
			lc(new LedControl(9, 8, 4, 1)) {
	}
	void writeToScreen(unsigned int x, int line = 0);
	void writeToScreen(String x, int line = 0) {
	}
	// should be called during loop()
	void refreshScreen();
	// should be called during setup()
	void initDisplay();

	virtual ~SevenSegmend();
private:
	LedControl *lc;
	unsigned int data[2] = { 0, 0 };
};

} /* namespace Display */

#endif /* LIBS_DISPLAY_SEVENSEGMEND_H_ */
