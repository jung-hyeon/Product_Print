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
		// ù ��° ���� ������
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
			// ������ 9��° ���� description�� ','�� �����־� count�� ���� 
			// => ������ 9��° ���� ","�� �Ľ����� �ʰ� ���ڿ��� �� ������ ����
			getline(ss, token);
			// description ó��
			if (count == 8) {tokens.push_back(token);}

			// FURNITURE ��ü �����ؼ� pmenu�� �߰�
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
		// ù ��° ���� ������
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
			// ������ 7��° ���� description�� ','�� �����־� count�� ���� 
			// => ������ 7��° ���� ","�� �Ľ����� �ʰ� ���ڿ��� �� ������ ����	
			getline(ss, token);
			// description ó��
			if (count == 6) { tokens.push_back(token); }

			// FURNITURE ��ü �����ؼ� pmenu�� �߰�
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
		// ù ��° ���� ������
		getline(fs, str_buf);
		while (!fs.eof()) {
			getline(fs, str_buf);
			stringstream ss(str_buf);
			vector<string> tokens;
			string token;
			while (getline(ss, token, ',')) {
				tokens.push_back(token);
			}
			// FURNITURE ��ü �����ؼ� pmenu�� �߰�
			PHONE* phone = new PHONE;
			*phone = PHONE(tokens);
			this->product_menu->add_menu(phone);
		}
		fs.close();
	}
}
