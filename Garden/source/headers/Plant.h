#pragma once
#include <string>
#include <vector>
#include "Appointment.h"
using namespace std;


//���� ��������
enum class PlantSpecies { SEAWEED, MOSS, FERN, CONIFER, FLOWERY };
//��������� ��������
enum class PlantFamily{ CRUCIFEROUS, ROSACEOUS, NIGHTSHADE, PAPILIONACEOUS, BLUEGRASS };

class Race;

//��������
class Plant
{
private:
	//����
	int count;
	PlantFamily family;
	PlantSpecies specie;
	string name;
	Race* race; //��������� �� ���
	Appointment appointment; //�������������� ��������� ��� ������� ��������
	vector<PlantSpecies> compatible_species; //���� � �������� �������� ����������
public:
	//������ � ���������� ��������
	int GetCount();
	void DecCount();
	void IncCount();
	void SetCount(int count);
	

	static string GetFamilyStringValue(PlantFamily enumValue);
	static PlantFamily GetFamilyEnumValue(int stringValue);
	static string GetSpecieStringValue(PlantSpecies enumValue);
	static PlantSpecies GetSpecieEnumValue(int stringValue);

	//������������
	Plant(PlantFamily _family, PlantSpecies _specie, string _name, Appointment _appointment, Race* race
		, vector<PlantSpecies> compatible);

	Plant();

	//�������
	void SetRace(Race* _race);
	void SetAppointment(Appointment _appointment);
	void SetFamily(PlantFamily _family);
	void SetSpecie(PlantSpecies _specie);
	void SetName(string _name);

	//�������
	Race* GetRace();
	Appointment GetAppointment();
	PlantFamily GetFamily();
	PlantSpecies GetSpecie();
	string GetName();
	vector<PlantSpecies>& GetCompatible();
};



