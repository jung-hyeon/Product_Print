#include "PRODUCT_MENU.h"
#include<cstdlib>
#include <time.h>

namespace product {
	// Constructor & Destructor
	PRODUCT_MENU::PRODUCT_MENU() {
		this->pmenu.clear();
		this->show_menu_num = 0;
	}

	// pmenu ���� �����Ҵ�� ��ü ��� delete
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

	// �������� 20���� ��ǰ ������
	void PRODUCT_MENU::show_menu() {
		unsigned int total_menu_count = this->get_total_count(); // menu�� �� ����
		const int show_menu_num = this->show_menu_num; // ����� ������ menu�� ����
		int i, tmp;
		int* save = new int[show_menu_num];
		int count = 0;
		int isSame = 0;
		srand(time(0));

		//���� ����
		while (count < show_menu_num) {
			isSame = 0;
			tmp = rand() % (total_menu_count); //0���� total_menu_count-1 ���� ���
			for (int i = 0; i < count; i++) { //�ߺ��˻�
				if (tmp == save[i]) { //�ߺ��� ������
					isSame = 1;
					break;
				}
			}
			if (isSame == 0) { //�ߺ�����
				save[count] = tmp;
				count++;
			}
		}
		// �ߺ� ���̻�ǰ id�� �̸� show
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
			cout << "�������� �ʴ� ��ǰ�Դϴ�." << endl;
		}
	}

	bool PRODUCT_MENU::search_product(ProductId pid) {
		bool exist = false;
		// �ݺ��� ���� 
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
		// �ݺ��� ���� 
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
		cout << "���α׷� ����" << endl;
		cout << endl;
		cout << "�� " << this->get_total_count() << "���� ��ǰ�� �����մϴ�." << endl;
		while (true) {
			cout << "�޴��ǿ� ������ ��ǰ�� ������ �Է��ϼ���(�Է¿���: 10): ";
			cin >> show_menu_num;
			this->show_menu_num = stoul(show_menu_num, nullptr, 0);
			if (this->show_menu_num <= this->get_total_count()) break;
			cout << "�߸��� �Է��Դϴ�. �� ��ǰ�� �������� �۾ƾ� �մϴ�." << endl;
			cout << endl;
		}
		while (true) {
			string select;
			string search_id;
			cout << endl;
			cout << "�� " << this->get_total_count() << "���� ��ǰ�� �����մϴ�." << endl;
			cout << "�������� " << this->show_menu_num << "���� ��ǰ�� �����ݴϴ�." << endl;
			cout << "====================== menu ======================" << endl;
			this->show_menu();
			cout << "==================================================" << endl;
			cout << endl;
			cout << "1. ��ǰ ��ȸ            2. ���α׷� ����" << endl;
			cout << endl;
			while (true) {
				cout << "������ �Ͻðڽ��ϱ�?(�Է¿���: 1) ";
				cin >> select;
				if ((select == "1") or (select == "2")) break;
				cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���." << endl;
				cout << endl;
			}
			if (select == "1") {
				while (true) {
					cout << endl;
					cout << "�޴����� �����Ͽ� ��ȸ�� ��ǰ�� id�� �Է��ϼ���.(�Է¿���: ph1, 0 �Է½� ���ο� �޴��� ����) : ";
					cin >> search_id;
					if (search_id.compare("0") == 0) break;
					cout << endl;
					this->print_info(search_id);
				}
			}
			else if (select == "2") {
				cout << "���α׷��� �����մϴ�." << endl;
				break;
			}
		}
	}
}
