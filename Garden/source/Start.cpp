#include "headers/GardenManager.h"
#include "headers/Input.h"
#include <ctime>

int main()
{
	SetConsoleCP(1251);//русский ввод вывод
	SetConsoleOutputCP(1251);

	CreateDirectory(L"data", NULL);

	GardenManager manager;
	manager.Menu();
	return 0;
}
