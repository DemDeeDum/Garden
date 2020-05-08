#pragma once
#include <string>
#include <vector>
#include "Appointment.h"
using namespace std;


//виды растений
enum class PlantSpecies { SEAWEED, MOSS, FERN, CONIFER, FLOWERY };
//семейства растений
enum class PlantFamily{ CRUCIFEROUS, ROSACEOUS, NIGHTSHADE, PAPILIONACEOUS, BLUEGRASS };

class Race;

//растение
class Plant
{
private:
	//поля
	int count;
	PlantFamily family;
	PlantSpecies specie;
	string name;
	Race* race; //указатель на род
	Appointment appointment; //предназначение уникально для каждого растения
	vector<PlantSpecies> compatible_species; //виды с которыми растение совместимо
public:
	//работа с количество растений
	int GetCount();
	void DecCount();
	void IncCount();
	void SetCount(int count);
	

	static string GetFamilyStringValue(PlantFamily enumValue);
	static PlantFamily GetFamilyEnumValue(int stringValue);
	static string GetSpecieStringValue(PlantSpecies enumValue);
	static PlantSpecies GetSpecieEnumValue(int stringValue);

	//конструкторы
	Plant(PlantFamily _family, PlantSpecies _specie, string _name, Appointment _appointment, Race* race
		, vector<PlantSpecies> compatible);

	Plant();

	//сеттеры
	void SetRace(Race* _race);
	void SetAppointment(Appointment _appointment);
	void SetFamily(PlantFamily _family);
	void SetSpecie(PlantSpecies _specie);
	void SetName(string _name);

	//геттеры
	Race* GetRace();
	Appointment GetAppointment();
	PlantFamily GetFamily();
	PlantSpecies GetSpecie();
	string GetName();
	vector<PlantSpecies>& GetCompatible();
};



