#ifndef LIBS_INPUT_TEMPERATURECONTROLLER_H_
#define LIBS_INPUT_TEMPERATURECONTROLLER_H_

#include <Wire.h>
#include "../../vendors/i2cEncoderLib.h"
#include "IInput.h"

namespace Input {

class TemperatureController: public IInput<int8_t> {
public:
	TemperatureController() :
			encoder(new i2cEncoderLib(0x31)), counter(0), encoder_status(0) {
	}

	void init();
	void printRawByte();
	int8_t readData();

	virtual ~TemperatureController() {
		delete encoder;
	}

private:
	int8_t counter;
	uint8_t encoder_status;
	i2cEncoderLib *encoder;
};

} /* namespace Input */

#endif /* LIBS_INPUT_TEMPERATURECONTROLLER_H_ */
