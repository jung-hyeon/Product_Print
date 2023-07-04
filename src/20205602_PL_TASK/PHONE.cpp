#define _CRT_SECURE_NO_WARNINGS
#include "PHONE.h"

namespace product {
	// identifier
	const ProductType PHONE::ptype = ProductType::phone;

	// static property
	ProductIntId PHONE::ph_last_id = 0;

	// Constructor & Destructor
	PHONE::PHONE() {
		ph_lowest_price = 0;
		ph_highest_price = 0;
		ph_brand = "";
		ph_os = PhoneOS::Android;
		ph_popularity = 0;
		ph_size = SIZE();
		release_date; ////////초기화
		release_period;
	}

	PHONE::PHONE(InitialVlaues initial_values) {
		this->initialize_properties(initial_values);
	}

	PHONE::~PHONE() {}

	// Public pure virtual method
	void PHONE::info_print() const {
		cout << "======== product information ========" << endl;
		cout << "id: " << this->pid << endl;
		cout << "type: ";
		this->type_print(this->ptype);
		cout << endl;
		cout << "name: " << this->pname << endl;
		cout << "best price: " << this->pprice << endl;
		cout << "lowest price: " << this->ph_lowest_price << endl;
		cout << "highest price: " << this->ph_highest_price << endl;
		cout << "brand: " << this->ph_brand << endl;
		cout << "os: ";
		this->os_print();
		cout << endl;
		cout << "popularity: " << this->ph_popularity << endl;
		this->ph_size.info_print();
		cout << "release date: ";
		this->date_print(this->release_date);
		cout << endl;
		cout << "release period: 출시된 날로부터 ";
		this->date_print(this->release_period);
		cout << " 지났습니다." << endl;
		cout << "=======================================" << endl;
	}

	void PHONE::initialize_properties(InitialVlaues initial_values) {
		this->pid = this->set_pid();
		this->pname = this->set_pname(initial_values.at(0));
		this->pprice = this->set_pprice(initial_values.at(1));
		this->ph_lowest_price = this->set_ph_lowest_price(initial_values.at(2));
		this->ph_highest_price = this->set_ph_highest_price(initial_values.at(3));
		this->ph_brand = this->set_ph_brand(initial_values.at(4));
		this->ph_os = this->set_ph_os(initial_values.at(5));
		this->ph_popularity = this->set_ph_popularity(initial_values.at(6));
		this->ph_size = this->set_ph_size(initial_values.at(7), initial_values.at(8), initial_values.at(9));
		this->release_date = this->set_release_date(initial_values.at(10));
		this->release_period = this->set_release_period(initial_values.at(10));
	}

	ProductType PHONE::get_type() {
		return this->ptype;
	}

	void PHONE::show_short_info() {
		cout << "id: " << this->pid;
		cout << "   type: ";
		this->type_print(this->ptype);
		cout << "   name : " << this->pname << endl;
	}

	// Public method

	void PHONE::date_print(Date date) const {
		cout << date.tm_year << "년 " << date.tm_mon << "월";
	}

	void PHONE::os_print() const {
		switch (this->ph_os) {
			case Android: printf("Android"); break;
			case iOS: printf("iOS"); break;
			case OxygenOS: printf("OxygenOS"); break;
			case WindowsPhone: printf("WindowsPhone"); break;
			case EMUI: printf("EMUI"); break;
			case KAIOS: printf("KAIOS"); break;
			default: break;
			}
	}

	Date PHONE::calculate_release_period(Date release_date) {
		time_t timer;
		time(&timer);

		Date* now = localtime(&timer);
		Date* release_period = localtime(&timer);
		
		// 현재 시각 구하기
		now->tm_year += 1900;
		now->tm_mon += 1;

		// release_period 구하기
		release_period->tm_year = now->tm_year - release_date.tm_year;
		release_period->tm_mon = now->tm_mon - release_date.tm_mon;

		return *release_period;
	}

	// ph_id를 순차적으로 생성 (ex. ft1)
	ProductId PHONE::set_pid() {
		this->ph_last_id++;
		ProductId new_pid = "ph" + to_string(ph_last_id);
		return new_pid;
	}

	ProductName PHONE::set_pname(Value name) {
		return name;
	}

	ProductPrice PHONE::set_pprice(Value price) {
		return stoul(price, nullptr, 0);
	}

	ProductPrice PHONE::set_ph_lowest_price(Value price) {
		return stoul(price, nullptr, 0);
	}

	ProductPrice PHONE::set_ph_highest_price(Value price) {
		return stoul(price, nullptr, 0);
	}

	Brand PHONE::set_ph_brand(Value brand) {
		return brand;
	}

	PhoneOS PHONE::set_ph_os(Value os) {
		PhoneOS pos;
		if (os == "Android") pos = PhoneOS::Android;
		else if (os == "iOS") pos = PhoneOS::iOS;
		else if (os == "OxygenOS") pos = PhoneOS::OxygenOS;
		else if (os == "WindowsPhone") pos = PhoneOS::WindowsPhone;
		else if (os == "EMUI") pos = PhoneOS::EMUI;
		else if (os == "KAIOS") pos = PhoneOS::Android;

		return pos;
	}

	Popularity PHONE::set_ph_popularity(Value popularity) {
		return stoul(popularity, nullptr, 0);
	}

	SIZE PHONE::set_ph_size(Value screen_size, Value memory_size, Value battery_size) {
		Size iscreen_size = stoul(screen_size, nullptr, 0);
		Size imemory_size = stoul(memory_size, nullptr, 0);
		Size ibattery_size = stoul(battery_size, nullptr, 0);

		SIZE size = SIZE(iscreen_size, imemory_size, ibattery_size);
		return size;
	}


	Date PHONE::set_release_date(Value rdate) {
		/// rdate를 -기준으로 쪼개서 year, month 에 넣기
		istringstream ss(rdate);
		string subs1;
		vector<string> v;

		while (getline(ss, subs1, '-')) {
			v.push_back(subs1);
		}

		int release_year = stoul(v[1], nullptr, 0);
		int release_month = stoul(v[0], nullptr, 0);

		// release_stime 생성
		Date release_stime;
		release_stime.tm_year = release_year;
		release_stime.tm_mon = release_month;

		return release_stime;
	}

	Date PHONE::set_release_period(Value rdate) {
		Date release_date = this->set_release_date(rdate);
		return this->calculate_release_period(release_date);
	}
}