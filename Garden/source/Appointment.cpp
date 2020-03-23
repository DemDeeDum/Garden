#include "headers/Appointment.h"


Appointment::Appointment(bool is_oxygen_maker, bool has_therapeutic_benefit, bool has_food_value, bool has_aesthetic_value,
	bool is_endangered_specie, string additional_info)
	:
	is_oxygen_maker(is_oxygen_maker),
	has_therapeutic_benefit(has_therapeutic_benefit),
	has_food_value(has_food_value),
	has_aesthetic_value(has_aesthetic_value),
	is_endangered_specie(is_endangered_specie),
	additional_info(additional_info)
{}

Appointment::Appointment() 
	:
	is_oxygen_maker(false),
	has_therapeutic_benefit(false),
	has_food_value(false),
	has_aesthetic_value(false),
	is_endangered_specie(false),
	additional_info("some info")
{}
