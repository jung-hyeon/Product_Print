#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

typedef vector<string> InitialVlaues;
typedef string Value;

typedef string ProductId;
typedef unsigned int ProductIntId;
typedef string ProductName;
typedef unsigned int ProductPrice;
typedef enum { furniture, grocery, phone } ProductType;

typedef string Category;
typedef string Designer;
typedef bool Sellable;
typedef string Brand;
typedef string Description;
typedef string Quantity;
typedef unsigned int Popularity;
typedef double DiscountRate;
typedef struct tm Date;

namespace product {
	class PRODUCT {
	protected:
		ProductId pid;
		ProductName pname;
		ProductPrice pprice;
		ProductType ptype;

	public:
		// Constructor & Destructor
		PRODUCT();
		virtual ~PRODUCT();

		// Public method
		void type_print(ProductType) const;
		ProductName get_name();
		ProductId get_id();
		ProductPrice get_price();

		// Public pure virtual method
		virtual ProductType get_type() = 0;
		virtual void info_print() const = 0;
		virtual void initialize_properties(InitialVlaues) = 0;
		virtual void show_short_info() = 0;
	};
}