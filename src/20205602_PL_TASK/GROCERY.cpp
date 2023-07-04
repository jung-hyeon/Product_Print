#include "GROCERY.h"
#include <sstream>

namespace product {
	// identifier
	ProductType GROCERY::ptype = ProductType::grocery;

	// static property
	ProductIntId GROCERY::gr_last_id = 0;

		// Constructor & Destructor
	GROCERY::GROCERY() {
		gr_discounted_price = 0;
		gr_category = "";
		gr_brand = "";
		gr_quantity = "";
		gr_description = "";
	}

	GROCERY::GROCERY(InitialVlaues initial_values) {
		this->initialize_properties(initial_values);
	}

	GROCERY::~GROCERY() {}

	// Public pure virtual method
	void GROCERY::info_print() const {
		cout << "======== product information ========" << endl;
		cout << "id: " << this->pid << endl;
		cout << "type: ";
		this->type_print(this->ptype);
		cout << endl;
		cout << "name: " << this->pname << endl;
		cout << "price: " << this->pprice << endl;
		cout << "discounted price: " << this->gr_discounted_price << endl;
		cout << "discount rate: " << this->gr_discount_rate << "%" << endl;
		cout << "category: " << this->gr_category << endl;
		cout << "brand: " << this->gr_brand << endl;
		cout << "quantity: " << this->gr_quantity << endl;
		cout << "description: " << this->gr_description << endl;
		cout << "=======================================" << endl;
	}

	void GROCERY::initialize_properties(InitialVlaues initial_values) {
		this->pid = this->set_pid();
		this->pname = this->set_pname(initial_values.at(0));
		this->pprice = this->set_pprice(initial_values.at(1));
		this->gr_discounted_price = this->set_gr_discounted_price(initial_values.at(2));
		this->gr_discount_rate = this->set_gr_discount_rate(initial_values.at(1), initial_values.at(2));
		this->gr_category = this->set_gr_category(initial_values.at(3));
		this->gr_brand = this->set_gr_brand(initial_values.at(4));
		this->gr_quantity = this->set_gr_quantity(initial_values.at(5));
		this->gr_description = this->set_gr_description(initial_values.at(6));
	}

	ProductType GROCERY::get_type() {
		return this->ptype;
	}

	void GROCERY::show_short_info() {
		cout << "id: " << this->pid;
		cout << "   type: ";
		this->type_print(this->ptype);
		cout << "   name : " << this->pname << endl;
	}

	// Public method

	DiscountRate GROCERY::calculate_gr_discount_rate(Value price, Value discounted_price) {
		ProductPrice iprice = stoul(price, nullptr, 0);
		ProductPrice idiscounted_price = stoul(discounted_price, nullptr, 0);
		double result = (double)(iprice - idiscounted_price) / iprice * 100;
		result = round(result * 100) / 100;
		return  result;
	}

	ProductId GROCERY::set_pid() {
		this->gr_last_id++;
		ProductId new_pid = "gr" + to_string(gr_last_id);
		return new_pid;
	}

	ProductName GROCERY::set_pname(Value name) {
		return name;
	}

	ProductPrice GROCERY::set_pprice(Value price) {
		return stoul(price, nullptr, 0);
	}

	ProductPrice GROCERY::set_gr_discounted_price(Value discounted_price) {
		return stoul(discounted_price, nullptr, 0);
	}

	DiscountRate GROCERY::set_gr_discount_rate(Value price, Value discounted_price) {
		return this->calculate_gr_discount_rate(price, discounted_price);
	}

	Category GROCERY::set_gr_category(Value category) {
		return category;
	}

	Brand GROCERY::set_gr_brand(Value brand) {
		return brand;
	}

	Quantity GROCERY::set_gr_quantity(Value quantity) {
		return quantity;
	}

	// descdription 문자열 처리 
	Description GROCERY::set_gr_description(Value description) {
		if (description.front() == ' ') {
			description.erase(0, description.find_first_not_of(' '));
		}
		description.shrink_to_fit();

		return description;
	}
}