#include "headers/GardenManager.h"
#include <ctime>

int main()
{
	SetConsoleCP(1251);//русский ввод вывод
	SetConsoleOutputCP(1251);

	GardenManager manager;
	manager.Menu(MAIN);

	return 0;
}
