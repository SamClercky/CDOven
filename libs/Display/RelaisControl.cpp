/*
 * RelaisControl.cpp
 *
 *  Created on: 20 okt. 2018
 *      Author: clercky
 */

#include "RelaisControl.h"

namespace Display {

void RelaisControl::writeToScreen(uint8_t modus) {
	relayStates = modus;
}

void RelaisControl::refreshScreen() {
	pcf_a0.write8(relayStates);
}

RelaisControl::~RelaisControl() {
	// nothing to do
}

}

