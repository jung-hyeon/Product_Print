#include "FURNITURE.h"
//#include <vector>

namespace product {
	// identifier
	ProductType FURNITURE::ptype = ProductType::furniture;

	// static property
	ProductIntId FURNITURE::ft_last_id = 0;

	// Constructor & Destructor
	FURNITURE::FURNITURE(){
		ft_category = "";
		ft_designer = "";
		ft_description = "";
		ft_sellable_online = true;
		ft_volume = VOLUME();
	}

	FURNITURE::FURNITURE(InitialVlaues initial_values) {
		this->initialize_properties(initial_values);
	}

	FURNITURE::~FURNITURE() {}

	// Public pure virtual method
	void FURNITURE::info_print() const {
		cout << "======== product information ========" << endl;
		cout << "id: " << this->pid << endl;
		cout << "type: ";
		this->type_print(this->ptype);
		cout << endl;
		cout << "name: " << this->pname << endl;
		cout << "price: " << this->pprice << endl;
		cout << "category: " << this->ft_category << endl;
		cout << "designer: " << this->ft_designer << endl;
		cout << "sellable_online: ";
		this->sellable_online_print();
		cout << endl;
		this->ft_volume.info_print();
		cout << "description: " << this->ft_description << endl;
		cout << "=======================================" << endl;
		}

	void FURNITURE::initialize_properties(InitialVlaues initial_values) {
		this->pid = this->set_pid();
 		this->pname = this->set_pname(initial_values.at(0));
		this->pprice = this->set_pprice(initial_values.at(1));
		this->ft_category = this->set_ft_category(initial_values.at(2));
		this->ft_designer = this->set_ft_designer(initial_values.at(3));
		this->ft_sellable_online = this->set_ft_sellable_online(initial_values.at(4));
		this->ft_volume = this->set_ft_volume(initial_values.at(5), initial_values.at(6), initial_values.at(7));
		this->ft_description = this->set_ft_description(initial_values.at(8));
	}

	ProductType FURNITURE::get_type() {
		return this->ptype;
	}

	void FURNITURE::show_short_info() {
		cout << "id: " << this->pid;
		cout << "   type: ";
		this->type_print(this->ptype);
		cout << "   name : " << this->pname << endl;
	}

	// Public method
	void FURNITURE::sellable_online_print() const {
		if (this->ft_sellable_online) cout << "TRUE";
		else  cout << "FALSE";
	}

	
	// ft_id를 순차적으로 생성 (ex. ft1)
	ProductId FURNITURE::set_pid() {
		this->ft_last_id++;
		ProductId new_pid = "ft" + to_string(ft_last_id);
		return new_pid;
	}

	ProductName FURNITURE::set_pname(Value name) {
		return name;
	}

	ProductPrice FURNITURE::set_pprice(Value price) {
		return stoul(price, nullptr, 0);
	}

	Category FURNITURE::set_ft_category(Value category) {
		return category;
	}

	Designer FURNITURE::set_ft_designer(Value designer) {
		return designer;
	}

	Sellable FURNITURE::set_ft_sellable_online(Value sellable) {
		Sellable result = true;
		if (sellable == "True") {
			result = true;
		}
		else if (sellable == "False") {
			result = false;
		}
		return result;
	}

	VOLUME FURNITURE::set_ft_volume(Value depth, Value width, Value height) {
		Volume idepth = stoul(depth, nullptr, 0);
		Volume iwidth = stoul(width, nullptr, 0);
		Volume iheight = stoul(height, nullptr, 0);

		VOLUME volume = VOLUME(idepth, iwidth, iheight);
		return volume;
	}

	// descdription 문자열 처리 
	Description FURNITURE::set_ft_description(Value description) {
		// 문자열 앞쪽에 공백 있으면 제거
		description.erase(0, description.find_first_not_of(' '));

		// 문자열 가장 앞에 '"'있으면 제거 후, 뒤의 공백있으면 제거
		if (description.front() == '\"') {
			description.erase(description.begin());
			description.erase(0, description.find_first_not_of(' '));
		}
		// 문자열 가장 뒤에 '"'있으면 제거 후, 앞의 공백있으면 제거
		if (description.back() == '\"') {
			description.pop_back();
			size_t last = description.find_last_of(',');

			// ","기준으로 문자열 분리 후, 공백 제거 한 뒤 다시 합치기
			string str1 = description.substr(0, last + 1);
			string str2 = description.substr(last + 1, description.back());
			str2.erase(remove(str2.begin(), str2.end(), ' '), str2.end());

			description = str1 + str2;
		}
		description.shrink_to_fit();

		return description;
	}
}