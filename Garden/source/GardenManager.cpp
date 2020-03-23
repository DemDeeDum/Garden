#include "headers/GardenManager.h"

#define BACK 9

//������ � ����
vector<string> GardenManager::GetMenu(int menu_id)
{
    string address;
    vector<string> menu_items;
    switch (menu_id)
    {

    case RACES:
        address = "menus//plant_race_menu.txt";
        break;
    case PLANTS:
        address = "menus//plants_menu.txt";
        break;
    case SALES:
        address = "menus//sales_menu.txt";
        break;
    default:
        menu_items.push_back("������������ ���� � ����");
    case MAIN:
        address = "menus//main_menu.txt";
        break;
    }

    fstream file(address);

    if (file.is_open())
    {
        string buf;
        while (!file.eof())
        {
            getline(file, buf);
            menu_items.push_back(buf);
        }
    }
    else
        return vector<string>({ "�� ������ ���� ����" });
    return menu_items;
}

void GardenManager::Menu(int menu_id)
{
    string choice;
	while (true)
	{
        ClearScreen();
		cout << "\"������������ ���\"" << endl;
        for (auto item : GetMenu(menu_id))
            cout << item << endl;
		cin.ignore(cin.rdbuf()->in_avail()); //��������� ���������� ����� ������ � ��������� �� ������ cin
		getline(cin, choice);
        if (!MakeChoice(atoi(choice.c_str()), menu_id))
            return;
	}
}

bool GardenManager::MakeChoice(int choice, int& menu_id)
{
    switch (menu_id)
    {
    case MAIN:
        if (choice == BACK)
            return false;
        menu_id = choice;
        break;
    case PLANTS:
        switch (choice)
        {
        case BACK:
            menu_id = MAIN;
            break;
        }
        break;
    case SALES:
        switch (choice)
        {
        case BACK:
            menu_id = MAIN;
            break;
        }
        break;
    case RACES:
        switch (choice)
        {
        case BACK:
            menu_id = MAIN;
            break;
        }
        break;
    }
    return true;
}

//������� �������
void GardenManager::ClearScreen() //� ���������
{
    HANDLE                     hStdOut;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD                      count;
    DWORD                      cellCount;
    COORD                      homeCoords = { 0, 0 };

    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdOut == INVALID_HANDLE_VALUE) return;

    /* Get the number of cells in the current buffer */
    if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
    cellCount = csbi.dwSize.X * csbi.dwSize.Y;

    /* Fill the entire buffer with spaces */
    if (!FillConsoleOutputCharacter(
        hStdOut,
        (TCHAR)' ',
        cellCount,
        homeCoords,
        &count
    )) return;

    /* Fill the entire buffer with the current colors and attributes */
    if (!FillConsoleOutputAttribute(
        hStdOut,
        csbi.wAttributes,
        cellCount,
        homeCoords,
        &count
    )) return;

    /* Move the cursor home */
    SetConsoleCursorPosition(hStdOut, homeCoords);
}



