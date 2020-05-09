#include "headers/Plant.h"
#include "headers/Race.h"

//статик методы
void Plant::SetCount(int new_count)
{
	if (new_count > 0)
		count = new_count;
}

int Plant::GetCount()
{
	return count;
}

void Plant::IncCount()
{
	count++;
}

void Plant::DecCount()
{
	if (count > 0)
		count--;
}

//конструкторы
Plant::Plant(PlantFamily _family, PlantSpecies _specie, string _name, Appointment _appointment, Race* _race
	, vector<PlantSpecies> _compatible)
	: 
	family(_family),
	specie(_specie),
	name(_name),
	appointment(_appointment),
	compatible_species(vector<PlantSpecies>(_compatible)),
	race(_race)
{}

Plant::Plant()
{}

//сеттеры
void Plant::SetRace(Race* _race)
{
	race = _race;
}

void Plant::SetAppointment(Appointment _appointment)
{
	appointment = _appointment;
}

void Plant::SetFamily(PlantFamily _family)
{
	family = _family;
}

void Plant::SetSpecie(PlantSpecies _specie)
{
	specie = _specie;
}

void Plant::SetName(string _name)
{
	if (_name != "")
		name = _name;
}

void Plant::SetCompatible(vector<PlantSpecies> _compatible_species)
{
	compatible_species = _compatible_species;
}

//геттеры
Race* Plant::GetRace()
{
	return race;
}

Appointment Plant::GetAppointment()
{
	return appointment;
}

PlantFamily Plant::GetFamily()
{
	return family;
}

PlantSpecies Plant::GetSpecie()
{
	return specie;
}

string Plant::GetName()
{
	return name;
}

vector<PlantSpecies>& Plant::GetCompatible()
{
	return compatible_species;
}


string Plant::GetFamilyStringValue(PlantFamily enumValue)
{
	switch (enumValue)
	{
	case PlantFamily::CRUCIFEROUS:
		return "Крестоцветные";
	case PlantFamily::ROSACEOUS:
		return "Розоцветные";
	case PlantFamily::NIGHTSHADE:
		return "Пасленовые";
	case PlantFamily::PAPILIONACEOUS:
		return "Мотыльковые";
	case PlantFamily::BLUEGRASS:
		return "Мятликовые";
	default:
		break;
	}
}

PlantFamily Plant::GetFamilyEnumValue(int intValue)
{
	switch (intValue)
	{
	case 1:
		return PlantFamily::CRUCIFEROUS;
	case 2:
		return PlantFamily::ROSACEOUS;
	case 3:
		return PlantFamily::NIGHTSHADE;
	case 4:
		return PlantFamily::PAPILIONACEOUS;
	case 5:
		return PlantFamily::BLUEGRASS;
	default:
		break;
	}
	throw("Такого семейства не существует");
}

string Plant::GetSpecieStringValue(PlantSpecies enumValue)
{
	switch (enumValue)
	{
	case PlantSpecies::SEAWEED:
		return "Водоросли";
	case PlantSpecies::MOSS:
		return "Мхи";
	case PlantSpecies::FERN:
		return "Папоротники";
	case PlantSpecies::CONIFER:
		return "Хвойные";
	case PlantSpecies::FLOWERY:
		return "Цветочные";
	default:
		break;
	}
}

PlantSpecies Plant::GetSpecieEnumValue(int intValue)
{
	switch (intValue)
	{
	case 1:
		return PlantSpecies::SEAWEED;
	case 2:
		return PlantSpecies::MOSS;
	case 3:
		return PlantSpecies::FERN;
	case 4:
		return PlantSpecies::CONIFER;
	case 5:
		return PlantSpecies::FLOWERY;
	default:
		break;
	}
	throw("Такого вида не существует");
}