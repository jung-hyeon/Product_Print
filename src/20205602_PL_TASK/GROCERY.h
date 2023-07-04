#pragma once
#include "PRODUCT.h"

namespace product {
	class GROCERY : public PRODUCT {
	private:
		// identifier
		static ProductType ptype;

		// 가장 마지막에 생성된 GROCERY 객체의 ID번호
		static ProductIntId gr_last_id;

	protected:
		ProductPrice gr_discounted_price;
		DiscountRate gr_discount_rate;
		Category gr_category;
		Brand gr_brand;
		Quantity gr_quantity;
		Description gr_description;

	public:
		// Constructor & Destructor
		GROCERY();
		GROCERY(InitialVlaues);
		virtual ~GROCERY();

		// Public pure virtual method
		virtual void info_print() const;
		virtual void initialize_properties(InitialVlaues);
		virtual ProductType get_type();
		virtual void show_short_info();

		// Public method
		DiscountRate calculate_gr_discount_rate(Value, Value);

		ProductId set_pid();
		ProductName set_pname(Value);
		ProductPrice set_pprice(Value);
		ProductPrice set_gr_discounted_price(Value);
		DiscountRate set_gr_discount_rate(Value, Value);
		Category set_gr_category(Value);
		Brand set_gr_brand(Value);
		Quantity set_gr_quantity(Value);
		Description set_gr_description(Value);
	};
}