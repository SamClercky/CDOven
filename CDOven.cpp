#include <Arduino.h>
#include "libs/Display/lcd.h"
#include "libs/Input/ModusController.h"
#include "libs/Manipulator/ModusManipulator.h"
#include "libs/Input/Temperature.h"
#include "libs/Display/RelaisControl.h"
#include "libs/Manipulator/TemperatureManipulator.h"

#define DEBUG 1

// declare classes
Display::LCD lcd;
Display::RelaisControl rc;
Input::ModusController mc;
Input::Temperature temp;
Manipulator::ModusManipulator mm(&lcd, &rc);
Manipulator::TemperatureManipulator tm(14);

void setup() {
	Serial.begin(9600);

	// start init
	lcd.initDisplay();
	mc.init();
	temp.init();
	tm.init();
}

void loop() {
	// refresh data and send to appropriate screen
	temp.writeTemperatureToScreen(lcd);
	mm.printFromInt(static_cast<int>(mc.readData()));
	tm.setTemperatureOn(temp.readData());
	Serial.println("Test");

	// refresh screens
	rc.refreshScreen();
	lcd.refreshScreen();
}
