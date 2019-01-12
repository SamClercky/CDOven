#ifndef _ModusController_H
#define _ModusController_H

#include <Wire.h>
#include "../../vendors/i2cEncoderLib.h"
#include "IInput.h"

// TODO: complete the class so we can read and not only initialize

namespace Input {

class ModusController: public Input::IInput<int8_t> {
public:
	ModusController() :
			encoder(new i2cEncoderLib(0x30)), counter(0), encoder_status(0) {
	}

	void init();
	void printRawByte();
	int8_t readData();

	virtual ~ModusController() {
		delete encoder;
	}

private:
	int8_t counter;
	uint8_t encoder_status;
	i2cEncoderLib *encoder;
};

}

#endif
