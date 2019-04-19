/*
 * RelaisControl.h
 *
 *  Created on: 20 okt. 2018
 *      Author: clercky
 */

#ifndef LIBS_RELAISCONTROL_H_
#define LIBS_RELAISCONTROL_H_

#include "IDisplay.h"
#include <Arduino.h>
#include "../../vendors/PCF8574.h"

namespace Display {

class RelaisControl: IDisplay {
public:
	RelaisControl() :
			pcf_a0(0x38) {
	}

	void writeToScreen(float x, int line = 0) {
#ifdef DEBUG
		Serial.println("ERROR: no writeToScreen(float, int) implementation in this context");
#endif
	}
	void writeToScreen(String x, int line = 0) {
#ifdef DEBUG
		Serial.println("ERROR: no writeToScreen(float, int) implementation in this context");
#endif
	}
	// write to relay
	void writeToScreen(uint8_t modus);
	// should be called during loop()
	void refreshScreen();
	// should be called during setup()
	void initDisplay() {
#ifdef DEBUG
		Serial.println("ERROR: no initDisplay(void) implementation in this context");
#endif
	}

	bool hasPermissionToHeat();

	virtual ~RelaisControl();

private:
	void disableMasterPinSafeMode(int masterPin = -1) {
		if (masterPin != -1) {
			digitalWrite(masterPin, LOW);
		}
	}

	uint8_t relayStates = 0;
	unsigned long timeToWrite = 1; // de eerste keer moet er worden gescheven naar de solid state
	PCF8574 pcf_a0;
};

}

#endif /* LIBS_RELAISCONTROL_H_ */
