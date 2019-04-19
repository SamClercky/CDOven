#include "SevenSegmend.h"
#include <Arduino.h>

namespace Display {

void SevenSegmend::writeToScreen(unsigned int x, int line) {
	if (x <= 999) {
		if (line == 0) {
			data[0] = x;
		} else if (line == 1) {
			data[1] = x;
		}
	}
}

void SevenSegmend::refreshScreen() {
	for (int i = 0; i < 2; i++) {
		int data = this->data[i];
//		Serial.println(data);

		int h = data / 100;
//		Serial.print("h: ");
//		Serial.println(h);
		data = data - h * 100;
		int d = data / 10;
//		Serial.print("d: ");
//		Serial.println(d);
		data = data - d * 10;
		int e = data;
//		Serial.print("e: ");
//		Serial.println(e);

		lc->setDigit(0, 0 + i * 5, static_cast<byte>(e), false);
		lc->setDigit(0, 1 + i * 5, static_cast<byte>(d), false);
		lc->setDigit(0, 2 + i * 5, static_cast<byte>(h), false);
		//lc->setChar(0, 3 + i * 4, 'C', false); //(0, 0 + i * 4, static_cast<byte>('c'), false);
	}
}

void SevenSegmend::initDisplay() {
	lc->shutdown(0, false);
	lc->setIntensity(0, 6);
	lc->clearDisplay(0);
}

SevenSegmend::~SevenSegmend() {
	delete lc;
}

} /* namespace Display */
