#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h> // 메모리 할당 및 할당 해제를 추적하는 함수들이 정의되어 있음.
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
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // 메모리 누수 점검 위함

	READ_FILE read_file;
	PRODUCT_MENU product_menu;


	read_file.set_product_menu(&product_menu);

	// 파일 읽어서 해당 정보를 바탕으로 상품 생성
	read_file.Product_create(FileName::FURNITURE_process, "full_FURNITURE.csv");	      // FULL_DATA: full_FURNITURE.csv    TEST_DATA: test_FURNITURE.csv 
	read_file.Product_create(FileName::GROCERY_process, "full_GROCERY.csv");			  // FULL_DATA: full_GROCERY.csv	  TEST_DATA: test_GROCERY.csv  
	read_file.Product_create(FileName::PHONE_processe, "full_PHONE.csv");				  // FULL_DATA: full_PHONE.csv		  TEST_DATA: test_PHONE.csv  

	product_menu.run();

	return 0;
}