#include "TemperatureController.h"

namespace Input {

namespace Input {

void TemperatureController::init() {
	encoder->begin((INTE_ENABLE | LEDE_ENABLE | WRAP_DISABLE | DIRE_RIGHT | IPUP_ENABLE | RMOD_X1));
	encoder->writeCounter(0);
	encoder->writeMax(25); // Set maximum threshold + temperature * 10
	encoder->writeMin(0); // Set minimum threshold
	encoder->writeLEDA(0x00);
	encoder->writeLEDB(0x00);
	encoder->updateStatus();
}

void TemperatureController::printRawByte() {
	if (encoder->updateStatus()) {
		if (encoder->readStatus(E_PUSH)) {
			Serial.println("Encoder Pushed!");
		}
		if (encoder->readStatus(E_MAXVALUE)) {
			Serial.println("Encoder Max!");
		}
		if (encoder->readStatus(E_MINVALUE)) {
			Serial.println("Encoder Min!");
		}
		counter = encoder->readCounterByte(); //Read only the first byte of the counter register
		Serial.print("Encoder: ");
		Serial.println(counter, DEC);
		// reset for nex time
		encoder->writeLEDA(0x00);
		encoder->writeLEDB(0x00);
	}
}

int8_t TemperatureController::readData() {
	if (encoder->updateStatus()) {
		if (encoder->readStatus(E_PUSH)) {
			Serial.println("Encoder Pushed!");
		}
		if (encoder->readStatus(E_MAXVALUE)) {
			Serial.println("Encoder Max!");
		}
		if (encoder->readStatus(E_MINVALUE)) {
			Serial.println("Encoder Min!");
		}
		counter = static_cast<int>(encoder->readCounterByte());
		encoder->writeLEDA(0x00);
		encoder->writeLEDB(0x00);
		return counter; //Read only the first byte of the counter register

#ifdef DEBUG
		Serial.print("Encoder: ");
		Serial.println(counter, DEC);
#endif
	}
	return counter;
}

}


} /* namespace Input */
