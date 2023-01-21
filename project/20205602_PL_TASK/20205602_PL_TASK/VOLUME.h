#pragma once
#include <iostream>
using namespace std;

typedef unsigned int Volume;

namespace product {
	class VOLUME {
	private:
		Volume depth;
		Volume width;
		Volume height;
		Volume volume;

	public:
		// Constructor & Destructor
		VOLUME();
		VOLUME(Volume, Volume, Volume);
		~VOLUME();

		// Public method
		void info_print() const;
		unsigned int calculate_volume(Volume, Volume, Volume);
	};
}