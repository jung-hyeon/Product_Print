#pragma once
#include "PRODUCT.h"
#include "VOLUME.h"

namespace product {
	class FURNITURE : public PRODUCT {
	private:
		// identifier
		static ProductType ptype;

		// 가장 마지막에 생성된 FURNITURE 객체의 ID번호
		static ProductIntId ft_last_id;

	protected:
		Category ft_category;
		Designer ft_designer;
		Description ft_description;
		Sellable ft_sellable_online;
		VOLUME ft_volume;

	public:
		// Constructor & Destructor
		FURNITURE();
		FURNITURE(InitialVlaues);
		virtual ~FURNITURE();

		// Public pure virtual method
		virtual void info_print() const;
		virtual void initialize_properties(InitialVlaues);
		virtual ProductType get_type();
		virtual void show_short_info();

		// Public method
		void sellable_online_print() const;

		ProductId set_pid();
		ProductName set_pname(Value);
		ProductPrice set_pprice(Value);
		Category set_ft_category(Value);
		Designer set_ft_designer(Value);
		Sellable set_ft_sellable_online(Value);
		VOLUME set_ft_volume(Value, Value, Value);
		Description set_ft_description(Value);
	};
}