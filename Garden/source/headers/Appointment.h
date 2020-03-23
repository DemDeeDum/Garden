#pragma once
#include <string>
using namespace std;

//предназначение растения
struct Appointment
{
	//поля
	bool is_oxygen_maker;  //хорошо фильтрует воздух
	bool has_therapeutic_benefit;  //используется в медицине
	bool has_food_value;  //использует как еда
	bool has_aesthetic_value;  //имеет эстетическую ценность
	bool is_endangered_specie;  //исчезающий вид
	string additional_info;  //дополнительная информация

	//конструкторы
	Appointment(bool is_oxygen_maker, bool has_therapeutic_benefit, bool has_food_value, bool has_aesthetic_value,
		bool is_endangered_specie, string additional_info);
	Appointment();
};

