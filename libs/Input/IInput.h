/*
 * IInput.h
 *
 *  Created on: 8 nov. 2018
 *      Author: clercky
 */

#ifndef LIBS_INPUT_IINPUT_H_
#define LIBS_INPUT_IINPUT_H_

namespace Input {

template<class T>
class IInput { // @suppress("Class has a virtual method and non-virtual destructor")
public:
	void refreshData() {
		newData = readData();
	}
	bool isNewData() {
		if (prevData != newData) {
			prevData = newData;
			return true;
		} else {
			return false;
		}
	}
	virtual T readData(); // needs to be overriden
protected:
	T newData = 0;
	T prevData = 0;
};

} /* namespace Input */

#endif /* LIBS_INPUT_IINPUT_H_ */
