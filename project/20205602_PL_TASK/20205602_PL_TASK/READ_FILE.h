#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <iostream>
#include "PRODUCT_MENU.h"
#include "FURNITURE.h"
#include "GROCERY.h"
#include "PHONE.h"
#include "PRODUCT.h"

using namespace std;
enum class FileName {
	FURNITURE_process,
	GROCERY_process,
	PHONE_processe
};

namespace product {
	class READ_FILE {
	private:
		PRODUCT_MENU* product_menu;

		void Furniture_create(string);
		void Grocery_create(string);
		void Phone_create(string);

	public:
		// Constructor & Destructor
		READ_FILE();
		~READ_FILE();

		// Public method
		void set_product_menu(PRODUCT_MENU*);

		void Product_create(FileName, string);
	};
}