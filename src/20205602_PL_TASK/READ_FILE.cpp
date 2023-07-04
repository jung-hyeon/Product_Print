#include "READ_FILE.h"

namespace product {

	// Constructor & Destructor
	READ_FILE::READ_FILE() {
		this->product_menu = NULL;
	}

	READ_FILE::~READ_FILE() {}

	// Public method
	void READ_FILE::set_product_menu(PRODUCT_MENU* product_menu) {
		this->product_menu = product_menu;
	}

	void READ_FILE::Product_create(FileName fname, string string_fname) {
		switch (fname) {
		case (FileName::FURNITURE_process):
			this->Furniture_create(string_fname);
			break;
		case (FileName::GROCERY_process):
			this->Grocery_create(string_fname);
			break;
		case (FileName::PHONE_processe):
			this->Phone_create(string_fname);
			break;
		}
	}

	void READ_FILE::Furniture_create(string fname) {
		string str_buf;
		ifstream fs;
		fs.open(fname, ios::in);
		// 첫 번째 행은 버리기
		getline(fs, str_buf);
		while (!fs.eof()) {
			getline(fs, str_buf);
			stringstream ss(str_buf);
			int count = 0;
			vector<string> tokens;
			string token;
			while (count < 8) {
				getline(ss, token, ',');
				tokens.push_back(token);
				count++;
			}
			// 마지막 9번째 열인 description에 ','가 섞여있어 count로 관리 
			// => 마지막 9번째 열은 ","로 파싱하지 않고 문자열의 맨 끝까지 추출
			getline(ss, token);
			// description 처리
			if (count == 8) {tokens.push_back(token);}

			// FURNITURE 객체 생성해서 pmenu에 추가
			FURNITURE* furniture = new FURNITURE;
			*furniture = FURNITURE(tokens);
			this->product_menu->add_menu(furniture);
		}
		fs.close();
	}

	void READ_FILE::Grocery_create(string fname) {
		string str_buf;
		ifstream fs;
		fs.open(fname, ios::in);
		// 첫 번째 행은 버리기
		getline(fs, str_buf);
		while (!fs.eof()) {
			getline(fs, str_buf);
			stringstream ss(str_buf);
			int count = 0;
			vector<string> tokens;
			string token;
			while (getline(ss, token, ',') && count < 6) {
				tokens.push_back(token);
				count++;
			}
			// 마지막 7번째 열인 description에 ','가 섞여있어 count로 관리 
			// => 마지막 7번째 열은 ","로 파싱하지 않고 문자열의 맨 끝까지 추출	
			getline(ss, token);
			// description 처리
			if (count == 6) { tokens.push_back(token); }

			// FURNITURE 객체 생성해서 pmenu에 추가
			GROCERY* grocery = new GROCERY;
			*grocery = GROCERY(tokens);
			this->product_menu->add_menu(grocery);
		}
		fs.close();
	}

	void READ_FILE::Phone_create(string fname) {
		string str_buf;
		ifstream fs;
		//int idx = static_cast<int>(fname);
		fs.open(fname, ios::in);
		// 첫 번째 행은 버리기
		getline(fs, str_buf);
		while (!fs.eof()) {
			getline(fs, str_buf);
			stringstream ss(str_buf);
			vector<string> tokens;
			string token;
			while (getline(ss, token, ',')) {
				tokens.push_back(token);
			}
			// FURNITURE 객체 생성해서 pmenu에 추가
			PHONE* phone = new PHONE;
			*phone = PHONE(tokens);
			this->product_menu->add_menu(phone);
		}
		fs.close();
	}
}
