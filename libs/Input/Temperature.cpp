/*
 * Temperature.cpp
 *
 *  Created on: 20 okt. 2018
 *      Author: clercky
 */

#include "Temperature.h"
#include <Arduino.h>
#include "../Display/IDisplay.h"

namespace Input {

// define pins
constexpr int CLK = 5;
constexpr int CSEL = 7;
constexpr int DBIT = 6;

void Temperature::init() {
	pinMode(CLK, OUTPUT);
	pinMode(CSEL, OUTPUT);
	pinMode(DBIT, INPUT);
}

int Temperature::spiRead() { // TODO: look at this in CDojo
	int value = 0;
	digitalWrite(CSEL, LOW);
	delay(2);
	digitalWrite(CSEL, HIGH);
	delay(220);
	digitalWrite(CSEL, LOW);
	digitalWrite(CLK, HIGH);
	delay(1);
	digitalWrite(CLK, LOW);

	for (int i = 14; i >= 0; i--) {
		digitalWrite(CLK, HIGH);
		value += digitalRead(DBIT) << i;
		digitalWrite(CLK, LOW);
	}
	if ((value & 0x04) == 0x04)
		return -1;
	return value >> 3;
}

int Temperature::readData() {
	int v = spiRead();
	float Ctemp = -1;
	if (v == -1) {
		Serial.println("Error: No temperature sensor\n");
	} else {

#ifdef DEBUG
		Serial.print("Raw Temp: ");
		Serial.println(v);
#endif
		Ctemp = v * 0.37 * 0.5;
#ifdef DEBUG
		Serial.print("Temp: ");
		Serial.println(Ctemp);
#endif
	}

	return Ctemp;
}

// TODO: will be subject for change
void Temperature::writeTemperatureToScreen(Display::IDisplay& lcd) {
	lcd.writeToScreen(readData(), 1);
}

}

