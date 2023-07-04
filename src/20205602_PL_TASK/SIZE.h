#pragma once
#include <iostream>
using namespace std;

typedef unsigned int Size;

namespace product {
	class SIZE {
	private:
		Size screen_size;
		Size memory_size;
		Size battery_size;

	public:
		// Constructor & Destructor
		SIZE();
		SIZE(Size, Size, Size);
		~SIZE();

		// Public method
		void info_print() const;
	};
}