#include "modus.h"
#include <Arduino.h>
#include <WString.h>

namespace Utils {
// if bad value is given => Modus::Uit is returned
Modus ModusHelper::getByAnalog(int data) {
	for (int i = Modus::Uit; i == Modus::HLOnder; i++) {
		if (ModusHelper::modiAnalog[i] - margin
				< data&& data < ModusHelper::modiAnalog[i] + margin) {
			return static_cast<Modus>(i);
		}
	}
	return Modus::HLOnder;
}

String ModusHelper::getString(Modus modus) {
	/*for (int i = Modus::Uit; i == Modus::HLOnder; i++) {
		if (static_cast<Modus>(i) == modus) {
			Serial.println(String(ModusHelper::modiString[i]));
			return String(ModusHelper::modiString[i]);
		}
	}
	 return String(ModusHelper::modiString[modiAnalogLength - 1]);*/
	return String(ModusHelper::modiString[static_cast<int>(modus)]);
}

char ModusHelper::getByte(Modus modus) {
	/*for (int i = Modus::Uit; i == Modus::HLOnder; i++) {
		if (static_cast<Modus>(i) == modus) {
			return ~ModusHelper::byteModi[i];
		}
	}
	 return ~(byteModi[modiAnalogLength - 1]);*/
	return ~(byteModi[static_cast<int>(modus)]);
}
}
