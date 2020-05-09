#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <fstream>

//menu_id
#define MAIN 9

using namespace std;
class Input;
class Plant;
class Race;
class Appointment;
enum class PlantFamily;
enum class PlantSpecies;

class GardenManager
{
private:
	//���������
	const string PlantRacesAddress = "data//races.txt";
	const string PlantsAddress = "data//plants.txt";

	//���� 
	Input* input; //��� ������ � ������
	string message; //��� ������ ���������

	//����� ������
	void ClearScreen(); //������� �������
	vector<string> Strtok(string input, char separator); //��� ���� ����� ������� ������ ��� ���������� �� �����
	bool ObjectExist(string name, string address); //�������� ������� ������� � ������

	//������ ����
	vector<string> GetMenu(int menu_id); //�������� ���� �� �����

	//������ ��������
	void CreatePlant(); //������� ��������
	string CreatePlantName();
	int GivePlantFamily();
	int GivePlantSpecie();
	void SetPlantRace(Plant* newPlant);
	Appointment CreateAppointment();
	int SetPlantCount();
	vector<PlantSpecies> SetCompatibles();
	void PrintPlants(vector<Plant>);


	//������ �����
	void AddingPlantsToRace(Race* newRace);
	void CreateRace(); //������� ���
	string CreateRaceName(); //������� ��� ����
	void PrintRaces(vector<Race>);

	//��������� � ������
	vector<Plant> SearchPlants();
	Plant GetPlant(string name, Race * owner);
	Plant CreatePlantFromFile(vector<string> values, Race * owner);
	void SavePlant(Plant newPlant);
	vector<Race> SearchRaces();
	Race GetRace(string name, Plant * owner);
	Race CreateRaceFromFile(vector<string>values, Plant* owner);
	void SaveRace(Race newRace);
public:
	//������������
	GardenManager(); // ����������� �� ���������( ��� ����������)

	//������ ����
	void Menu(); //�������� ����
};

