#include "PRODUCT_MENU.h"
#include<cstdlib>
#include <time.h>

namespace product {
	// Constructor & Destructor
	PRODUCT_MENU::PRODUCT_MENU() {
		this->pmenu.clear();
		this->show_menu_num = 0;
	}

	// pmenu 내의 동적할당된 객체 모두 delete
	PRODUCT_MENU::~PRODUCT_MENU() {
		ProductMenu::iterator iter = this->pmenu.begin();
		PRODUCT* product;

		for (iter = this->pmenu.begin(); iter != this->pmenu.end(); iter++) {
			product = *iter;
			delete(product);
		}
		this->pmenu.clear();
	}

	// Public method
	void PRODUCT_MENU::add_menu(PRODUCT* product) {
		this->pmenu.push_back(product);
	}

	// 랜덤으로 20개의 상품 보여줌
	void PRODUCT_MENU::show_menu() {
		unsigned int total_menu_count = this->get_total_count(); // menu의 총 개수
		const int show_menu_num = this->show_menu_num; // 출력해 보여줄 menu의 개수
		int i, tmp;
		int* save = new int[show_menu_num];
		int count = 0;
		int isSame = 0;
		srand(time(0));

		//숫자 추출
		while (count < show_menu_num) {
			isSame = 0;
			tmp = rand() % (total_menu_count); //0부터 total_menu_count-1 범위 출력
			for (int i = 0; i < count; i++) { //중복검사
				if (tmp == save[i]) { //중복이 있을때
					isSame = 1;
					break;
				}
			}
			if (isSame == 0) { //중복없음
				save[count] = tmp;
				count++;
			}
		}
		// 중복 없이상품 id와 이름 show
		for (int idx = 0; idx < show_menu_num; idx++) {
			this->pmenu.at(save[idx])->show_short_info();
		}

		delete[] save;
	}

	void PRODUCT_MENU::print_info(ProductId pid) {
		if (this->search_product(pid)) {
			this->get_product(pid)->info_print();
		}
		else {
			cout << "존재하지 않는 상품입니다." << endl;
		}
	}

	bool PRODUCT_MENU::search_product(ProductId pid) {
		bool exist = false;
		// 반복자 생성 
		ProductMenu::iterator iter = this->pmenu.begin();
		PRODUCT* product;

		for (iter = this->pmenu.begin(); iter != this->pmenu.end(); iter++)
		{
			product = *iter;
			if (product->get_id() == pid) {
				exist = true;
				break;
			}
		}
		return exist;
	}

	PRODUCT* PRODUCT_MENU::get_product(ProductId pid) {
		// 반복자 생성 
		ProductMenu::iterator iter = this->pmenu.begin();
		PRODUCT* product = NULL;

		for (iter = this->pmenu.begin(); iter != this->pmenu.end(); iter++)
		{
			product = *iter;
			if (product->get_id() == pid) {
				break;
			}
		}
		return product;
	}

	unsigned int PRODUCT_MENU::get_total_count() {
		return this->pmenu.size();
	}

	void PRODUCT_MENU::run() {
		string show_menu_num;
		cout << "프로그램 시작" << endl;
		cout << endl;
		cout << "총 " << this->get_total_count() << "개의 상품이 존재합니다." << endl;
		while (true) {
			cout << "메뉴판에 보여질 상품의 개수를 입력하세요(입력예시: 10): ";
			cin >> show_menu_num;
			this->show_menu_num = stoul(show_menu_num, nullptr, 0);
			if (this->show_menu_num <= this->get_total_count()) break;
			cout << "잘못된 입력입니다. 총 상품의 개수보다 작아야 합니다." << endl;
			cout << endl;
		}
		while (true) {
			string select;
			string search_id;
			cout << endl;
			cout << "총 " << this->get_total_count() << "개의 상품이 존재합니다." << endl;
			cout << "랜덤으로 " << this->show_menu_num << "개의 상품만 보여줍니다." << endl;
			cout << "====================== menu ======================" << endl;
			this->show_menu();
			cout << "==================================================" << endl;
			cout << endl;
			cout << "1. 상품 조회            2. 프로그램 종료" << endl;
			cout << endl;
			while (true) {
				cout << "무엇을 하시겠습니까?(입력예시: 1) ";
				cin >> select;
				if ((select == "1") or (select == "2")) break;
				cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;
				cout << endl;
			}
			if (select == "1") {
				while (true) {
					cout << endl;
					cout << "메뉴판을 참고하여 조회할 상품의 id를 입력하세요.(입력예시: ph1, 0 입력시 새로운 메뉴판 제공) : ";
					cin >> search_id;
					if (search_id.compare("0") == 0) break;
					cout << endl;
					this->print_info(search_id);
				}
			}
			else if (select == "2") {
				cout << "프로그램을 종료합니다." << endl;
				break;
			}
		}
	}
}
