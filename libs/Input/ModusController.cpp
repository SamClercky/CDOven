#include "ModusController.h"
#include "../Utils/modus.h"

namespace Input {

void ModusController::init() {
	encoder->begin(
			(INTE_ENABLE | LEDE_ENABLE | WRAP_DISABLE | DIRE_RIGHT | IPUP_ENABLE
					| RMOD_X1));
	encoder->writeCounter(0);
	encoder->writeMax((modiAnalogLength - 1) * 4); // Set maximum threshold
	encoder->writeMin(0); // Set minimum threshold
	encoder->writeLEDA(0x00);
	encoder->writeLEDB(0x00);
}

void ModusController::printRawByte() {
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
		counter = encoder->readCounterByte() / 5; //Read only the first byte of the counter register
		Serial.print("Encoder: ");
		Serial.println(counter, DEC);
	}
}

int8_t ModusController::readData() {
	if (encoder->updateStatus()) {
		if (encoder->readStatus(E_PUSH)) {
			Serial.println("Encoder Pushed!");
		}
		if (encoder->readStatus(E_MAXVALUE)) {
			Serial.println("Encoder Max!");
			delay(50);
		}
		if (encoder->readStatus(E_MINVALUE)) {
			Serial.println("Encoder Min!");
			delay(50);
		}
		counter = static_cast<int>(encoder->readCounterByte() / 4);
		return counter; //Read only the first byte of the counter register

#ifdef DEBUG
		Serial.print("Encoder: ");
		Serial.println(counter, DEC);
#endif
	}
	return counter;
}

}
