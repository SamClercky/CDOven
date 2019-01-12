#ifndef _LCD_H
#define _LCD_H

#include <WString.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "LedControl.h"
#include "IDisplay.h"

// control includes
#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

namespace Display {

constexpr int OLED_RESET = 4;
constexpr int dataLength = 2;
constexpr int lineHeight = 18;

class LCD: public IDisplay {
public:
	LCD() :
			display(new Adafruit_SSD1306(OLED_RESET)), lc(
					new LedControl(9, 8, 4, 1)) {
	}
	;
	// Call this to write to screen
	void writeToScreen(float x, int line = 0);
	void writeToScreen(String x, int line = 0);
	// should be called during loop()
	void refreshScreen();
	// should be called during setup()
	void initDisplay();
	virtual ~LCD();

private:
	String data[2] = { "", "" };
	Adafruit_SSD1306 *display;
	LedControl *lc;
};
}

#endif
