#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <fstream>

//menu_id
#define MAIN 9
#define PLANTS 1
#define SALES 2
#define RACES 3

using namespace std;
class GardenManager
{
private:
	void ClearScreen();
	bool MakeChoice(int choice, int& menu_id);
	vector<string> GetMenu(int menu_id);
public:
	void Menu(int menu_id);
};

