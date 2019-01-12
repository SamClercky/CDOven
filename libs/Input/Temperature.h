/*
 * Temperature.h
 *
 *  Created on: 20 okt. 2018
 *      Author: clercky
 */

#ifndef LIBS_TEMPERATURE_H_
#define LIBS_TEMPERATURE_H_

#include "../Display/IDisplay.h"
#include "IInput.h"

namespace Input {
class Temperature: public Input::IInput<int> {
public:
	// setup()
	void init();
	// if return -1 => no value read
	int readData();
	void writeTemperatureToScreen(Display::IDisplay& lcd);

private:
	int spiRead();

};
}

#endif /* LIBS_TEMPERATURE_H_ */
