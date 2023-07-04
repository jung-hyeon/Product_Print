#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h> // �޸� �Ҵ� �� �Ҵ� ������ �����ϴ� �Լ����� ���ǵǾ� ����.
#include "FURNITURE.h"
#include "GROCERY.h"
#include "PHONE.h"
#include "PRODUCT.h"
#include "PRODUCT_MENU.h"
#include "READ_FILE.h"
#include "SIZE.h"
#include "VOLUME.h"


using namespace product;
using namespace std;

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // �޸� ���� ���� ����

	READ_FILE read_file;
	PRODUCT_MENU product_menu;


	read_file.set_product_menu(&product_menu);

	// ���� �о �ش� ������ �������� ��ǰ ����
	read_file.Product_create(FileName::FURNITURE_process, "full_FURNITURE.csv");	      // FULL_DATA: full_FURNITURE.csv    TEST_DATA: test_FURNITURE.csv 
	read_file.Product_create(FileName::GROCERY_process, "full_GROCERY.csv");			  // FULL_DATA: full_GROCERY.csv	  TEST_DATA: test_GROCERY.csv  
	read_file.Product_create(FileName::PHONE_processe, "full_PHONE.csv");				  // FULL_DATA: full_PHONE.csv		  TEST_DATA: test_PHONE.csv  

	product_menu.run();

	return 0;
}