#include "SIZE.h"

namespace product {

	// Constructor & Destructor
	SIZE::SIZE() {
		this->screen_size = 0;
		this->memory_size = 0;
		this->battery_size = 0;
	}

	SIZE::SIZE(Size screen_size, Size memory_size, Size battery_size) {
		this->screen_size = screen_size;
		this->memory_size = memory_size;
		this->battery_size = battery_size;
	}

	SIZE::~SIZE() {}

	// Public method
	void SIZE::info_print() const {
		cout << "screen_size: " << this->screen_size << endl;
		cout << "memory_size: " << this->memory_size << endl;
		cout << "battery_size: " << this->battery_size << endl;
	}
}