/*
 * RelaisControl.cpp
 *
 *  Created on: 20 okt. 2018
 *      Author: clercky
 */

#include "RelaisControl.h"
#include "../Utils/modus.h"
#include <Arduino.h>

namespace Display {

void RelaisControl::writeToScreen(uint8_t modus) {
	if (relayStates != modus) { // als er een nieuwe modus is gedetecteerd
		relayStates = modus; // sla de nieuwe modus op
		timeToWrite = millis() + 2000; // wacht 5s
	}
}

void RelaisControl::refreshScreen() {
	if (timeToWrite != 0 && timeToWrite <= millis()) { // schrijf alleen pas nadat er 5s zijn verstreken na nieuwe modus
		disableMasterPinSafeMode();
		for (int i = 0; i < 20000; i++)
			; // wait a bit
		pcf_a0.write8(relayStates);
		for (int i = 0; i < 20000; i++)
			; // wait a bit
		timeToWrite = 0; // reset de tijd
	}
}

/**
 * Geeft true als er mag verwarmt worden en false als hij uit staat
 */
bool RelaisControl::hasPermissionToHeat() {
	return !(relayStates == static_cast<uint8_t>(~Utils::ModusHelper::byteModi[0]));
}

RelaisControl::~RelaisControl() {
	// nothing to do
}

}

