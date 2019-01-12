#ifndef _Modus_H
#define _Modus_H

#include <WString.h>

#define modiAnalogLength 9

namespace Utils {

enum Modus {
	Uit = 0, HeteLucht = 1, BovenOnder = 2, Onder = 3, Boven = 4, Grill12 = 5, Grill22 = 6, HLBoven = 7, HLOnder = 8
};

/*class ModusHelper {
public:
	static Modus getByAnalog(int data);
	static String getString(Modus modus);
	static char getByte(Modus modus);
private:
	static constexpr int margin = 15;

	static constexpr int modiAnalog[modiAnalogLength] = { 1023, 950, 810, 690, 530, 380, 230, 90, 0 };
	static constexpr char* modiString[modiAnalogLength] = { "Uit", "Hete lucht", "Boven + Onder", "Onder", "Boven", "Grill 1/2", "Grill 2/2",
			"HL + Boven", "HL + Onder" };
	static constexpr uint8_t byteModi[modiAnalogLength] = { 0b00000000, // Alles uit
			//B10000101, // verlichting aan
			0b10001111,// hete lucht
			0b10110101, // boven + onder
			0b10100101, // onder
			0b10010101, // boven
			0b11000101, // grill 1/2
			0b11010101, // grill 2/2
			0b10011111, // Hete lucht + boven
			0b10101111  // Hete lucht + ondeer
			};
 };*/

namespace ModusHelper { // helper collection for Modi

namespace { // private

constexpr int margin = 15;

constexpr int modiAnalog[modiAnalogLength] = { 1023, 950, 810, 690, 530, 380, 230, 90, 0 };
const String modiString[modiAnalogLength] =
		{ "Uit", "Hete lucht", "Boven+Ond", "Onder", "Boven", "Grill 1/2", "Grill 2/2", "HL + Boven",
		"HL + Onder" };
constexpr uint8_t byteModi[modiAnalogLength] = { 0b00000000, // Alles uit
		//B10000101, // verlichting aan
		0b11110001,// hete lucht
		0b10101101, // boven + onder
		0b10100101, // onder
		0b10101001, // boven
		0b10100011, // grill 1/2
		0b10101011, // grill 2/2
		0b11111001, // Hete lucht + boven
		0b11110101  // Hete lucht + ondeer
		};

}
// public

Modus getByAnalog(int data);
String getString(Modus modus);
char getByte(Modus modus);

}
}

#endif
