#pragma once
#include <string>
#include <vector>
#include "PRODUCT.h"
using namespace std;

typedef vector<product::PRODUCT*> ProductMenu;

namespace product {
	class PRODUCT_MENU {
	private:
		ProductMenu pmenu;
		int show_menu_num; // random으로 보여줄 상품의 수

	public:
		// Constructor & Destructor
		PRODUCT_MENU();
		~PRODUCT_MENU();

		// Public method
		void add_menu(PRODUCT*);
		void show_menu();
		void print_info(ProductId);
		bool search_product(ProductId);
		PRODUCT* get_product(ProductId);
		unsigned int get_total_count();
		void run();
	};
}
