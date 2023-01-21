#include "PRODUCT.h"

namespace product {
	// Constructor
	PRODUCT::PRODUCT() {
		pid = "";
		pname = "";
		pprice = 0;
	}

	// Destructor
	PRODUCT::~PRODUCT() {}

	// Public method

	void PRODUCT::type_print(ProductType ptype) const {
		switch (ptype) {
		case furniture: printf("furniture"); break;
		case grocery: printf("grocery"); break;
		case phone: printf("phone"); break;
		default: break;
		}
	}

	ProductName PRODUCT::get_name() {
		return this->pname;
	}

	ProductId PRODUCT::get_id() {
		return this->pid;
	}

	ProductPrice PRODUCT::get_price() {
		return this->pprice;
	}
}