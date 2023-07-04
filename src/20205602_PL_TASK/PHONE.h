#pragma once
#include "PRODUCT.h"
#include "SIZE.h"
#include <sstream>
#include <vector>
#include <time.h>

typedef enum { Android, iOS, OxygenOS, WindowsPhone, EMUI, KAIOS} PhoneOS;

namespace product {
	class PHONE : public PRODUCT {
	private:
		// identifier
		static const ProductType ptype;

		// 가장 마지막에 생성된 PHONE 객체의 ID번호
		static ProductIntId ph_last_id;

	protected:
		ProductPrice ph_lowest_price;
		ProductPrice ph_highest_price;
		Brand ph_brand;
		PhoneOS ph_os;
		Popularity ph_popularity;
		SIZE ph_size;
		Date release_date;
		Date release_period;

	public:
		// Constructor & Destructor
		PHONE();
		PHONE(InitialVlaues);
		virtual ~PHONE();

		// Public pure virtual method
		virtual void info_print() const;
		virtual void initialize_properties(InitialVlaues);
		virtual ProductType get_type();
		virtual void show_short_info();

		// Public method
		void date_print(Date) const;
		void os_print() const;
		Date calculate_release_period(Date);

		ProductId set_pid();
		ProductName set_pname(Value);
		ProductPrice set_pprice(Value);
		ProductPrice set_ph_lowest_price(Value);
		ProductPrice set_ph_highest_price(Value);
		Brand set_ph_brand(Value);
		PhoneOS set_ph_os(Value);
		Popularity set_ph_popularity(Value);
		SIZE set_ph_size(Value, Value, Value);
		Date set_release_date(Value);
		Date set_release_period(Value);
	};
}
