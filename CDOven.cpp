//#include <Arduino.h>
//#include "libs/Input/ModusController.h"
//#include "libs/Input/TemperatureController.h"
//#include "libs/Input/Temperature.h"
//#include "libs/Manipulator/ModusManipulator.h"
//#include "libs/Manipulator/TemperatureManipulator.h"
////#include "libs/Bluetooth/BLEManager.h"
//#include "libs/Display/lcd.h"
//#include "libs/Display/RelaisControl.h"
//#include "libs/Display/TempWrite.h"
//#include "libs/Display/SevenSegmend.h"
//
//#define DEBUG 1
//
//// declare classes
//Display::LCD lcd;
//Display::RelaisControl rc;
//Display::TempWrite tw(14);
//Display::SevenSegmend ss;
//Input::ModusController mc;
//Input::Temperature temp;
//Input::TemperatureController tempc;
//Manipulator::ModusManipulator mm(&lcd, &rc);
//Manipulator::TemperatureManipulator tm(&tw);
////BLE::BLEManager blem = BLE::BLEManager();
//
//void setup() {
//	Serial.begin(9600);
//
//	// start init
//	lcd.initDisplay();
//	tw.initDisplay();
//	ss.initDisplay();
//	mc.init();
//	temp.init();
//	tempc.init();
//}
//
//void loop() {
//	// check Serial
//	String cmds = Serial.readString() + ";";
//
//	// serialize ble and override everything else
//	// init ble
//	int bleModus = -1;
//	int bleTemps = -1;
//	// get cmds
//	while (cmds.indexOf(';') != -1) {
//		String cmd = cmds.substring(0, cmds.indexOf(':'));
//		int value = cmds.substring(cmds.indexOf(':') + 1, cmds.indexOf(';')).toInt();
//		if (cmd == "setTemp") {
//			bleTemps = value;
//		} else if (cmd == "setModus") {
//			bleModus = value;
//		}
//		cmds = cmds.substring(cmds.indexOf(';') + 1);
//		Serial.println(bleTemps);
//		Serial.println(bleModus);
//	}
//
//	// refresh data and send to appropriate screen
//	temp.writeTemperatureToScreen(ss);
//	mm.printFromInt(static_cast<int>(mc.readData()), bleModus);
//	//mm.printNewModus(Utils::Modus::HeteLucht); // needs to come before tm.setTemperature due hidden state!!!
//	unsigned int temps;
//	if (rc.hasPermissionToHeat()) { // kijk of de oven aan staat
//		temps = (bleTemps != -1) ? bleTemps : static_cast<unsigned int>(tempc.readData()) * 5; // gewenste temperatuur uitlezen
//	} else { // zet hem anders automatisch uit
//		temps = 0;
//	}
//
//	//blem.refreshScreen();
//
//	ss.writeToScreen(temps, 0); // Gewenste temperatuur schrijven naar sevensegment
//	tm.setSelectedTemp(temps); // Schrijf nieuwe gewenste temperatuur weg
//	tm.setTemperatureOn(temp.readData()); // Geef de huidige temperatuur
//
//	// refresh screens
//	tw.refreshScreen();
//	rc.refreshScreen();
//	lcd.refreshScreen();
//	ss.refreshScreen();
//
//	//Serial.println("End loop");
//}
