#include <Arduino.h>
#include "libs/Display/lcd.h"
#include "libs/Input/ModusController.h"
#include "libs/Input/TemperatureController.h"
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
Input::TemperatureController tempc;
Manipulator::ModusManipulator mm(&lcd, &rc);
Manipulator::TemperatureManipulator tm(14);

void setup() {
	Serial.begin(9600);

	// start init
	lcd.initDisplay();
	mc.init();
	temp.init();
	tm.init();
	tempc.init();
}

void loop() {
	// refresh data and send to appropriate screen
	temp.writeTemperatureToScreen(lcd);
	//mm.printFromInt(static_cast<int>(mc.readData()));
	mm.printNewModus(Utils::Modus::HeteLucht); // needs to come before tm.setTemperature due hidden state!!!
	unsigned int temps = static_cast<unsigned int>(tempc.readData()) * 10;
	lcd.writeToScreen(temps, 0);
	tm.setSelectedTemp(temps);
	tm.setTemperatureOn(temp.readData());
	Serial.println("Test");

	// refresh screens
	rc.refreshScreen();
	lcd.refreshScreen();
}
