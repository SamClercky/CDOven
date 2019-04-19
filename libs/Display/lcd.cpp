#include "lcd.h"
#include <WString.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Arduino.h>

namespace Display {
LCD::~LCD() {
	delete display;
}

void LCD::writeToScreen(float x, int line) {
	writeToScreen(String(x), line);
}

void LCD::writeToScreen(String x, int line) {
	if (line == 0) {
		data[0] = x;
	} else if (line == 1) {
		data[1] = x;
	}
}

void LCD::refreshScreen() {
	display->setTextSize(2);
	display->setTextColor(WHITE);
	display->clearDisplay();

	for (int i = 0; i < dataLength; i++) {
		display->setCursor(0, i * lineHeight);
		display->println(data[i]);
	}

	display->display();
}
void LCD::initDisplay() {
	display->begin(SSD1306_SWITCHCAPVCC, 0x3C); // initialize with the I2C addr 0x3C (for the 128x32)
	display->drawPixel(10, 10, WHITE);
	display->display();
	display->clearDisplay();
}
}

