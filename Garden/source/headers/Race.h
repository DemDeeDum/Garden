#pragma once
#include <string>
#include <vector>
using namespace std;

//��� ���� ��������
enum class RaceType { POLYTYPE, OLIGOTYPIC, MONOTYPIC, EMPTY };

class Plant;

//��� ��������
class Race
{
private:
	//����
	string name;
	RaceType type;
	vector<Plant*> plants;
	void type_setter();
public:
	//������������
	Race(string name);
	Race();

	//�������
	string GetName();
	RaceType GetType();
	vector<Plant*> GetPlants();

	//�������
	void SetName(string name);

	//��������� ������ ��������
	string add_plant(Plant* plant);
	string remove_plant(string plant_name);
};

