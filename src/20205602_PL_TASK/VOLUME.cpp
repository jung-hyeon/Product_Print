#include "VOLUME.h"

namespace product {
	// Constructor & Destructor
	VOLUME::VOLUME() {
		this->depth = 0;
		this->width = 0;
		this->height = 0;
		this->volume = 0;
	}

	VOLUME::VOLUME(Volume idepth, Volume iwidth, Volume iheight) {
		this->depth = idepth;
		this->width = iwidth;
		this->height = iheight;
		this->volume = this->calculate_volume(idepth, iwidth, iheight);
	}

	VOLUME::~VOLUME() {}

	// Public method
	void VOLUME::info_print() const {
		cout << "depth: " << this->depth << endl;
		cout << "width: " << this->width << endl;
		cout << "height: " << this->height << endl;
		cout << "volume: " << this->volume << endl;
	}
	Volume VOLUME::calculate_volume(Volume idepth, Volume iwidth, Volume iheight) {
		return idepth * iwidth * iheight;
	}
}