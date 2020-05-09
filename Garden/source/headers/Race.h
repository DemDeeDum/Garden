#pragma once
#include <string>
#include <vector>
using namespace std;

//тип рода растений
enum class RaceType { POLYTYPE, OLIGOTYPIC, MONOTYPIC, EMPTY };

class Plant;

//род растений
class Race
{
private:
	//поля
	string name;
	RaceType type;
	vector<Plant*> plants;
	void TypeSetter();
public:
	//конструкторы
	Race(string name);
	Race();

	//геттеры
	string GetName();
	RaceType GetType();
	vector<Plant*> GetPlants();

	//сеттеры
	void SetName(string name);

	//изменения списка растений
	string AddPlant(Plant* plant);
	string RemovePlant(string plant_name);
};

