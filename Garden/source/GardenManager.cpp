#include "headers/GardenManager.h"
#include "headers/Input.h"
#include "headers/Race.h"
#include "headers/Plant.h"

#define BACK 9

//������ ���� ���������� ����������
#define ADD_PLANT 1
#define CHANGE_PLANT 2
#define DELETE_PLANT 3

//������ ���� ���������� ���������
#define SELL_A_PLANT 1
#define SHOW_ALL_SALES 2
#define SHOW_WHOLE_PROFIT 3

//������ ���� ���������� ������ ��������
#define ADD_RACE 1
#define CHANGE_RACE 2
#define DELETE_RACE 3


//�����������
GardenManager::GardenManager()
    :
    input(new Input())
{}


//������ � ����
vector<string> GardenManager::GetMenu(int &menu_id)
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
        message = "������������ ���� � ����";
        menu_id = MAIN;
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
	while (true)
	{
        input->Clear();
        ClearScreen();
		cout << "\"������������ ���\"" << endl;
        for (auto item : GetMenu(menu_id))
            cout << item << endl;
        cout << (message.empty() ? "" : message + "\n");
        input->InputLine();
        if (!input->OnlyDigits() || input->GetInputSize() > 1)
        {
            message = "������������ ����!!";
            continue;
        }
        message.clear();
        if (!MakeChoice(atoi(input->GetInput().c_str()), menu_id))
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
        case ADD_PLANT:
            CreatePlant();
            break;
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
        case ADD_RACE:
            CreateRace();
            break;
        case BACK:
            menu_id = MAIN;
            break;
        }
        break;
    }
    return true;
}


//���� ���������� ����������
void GardenManager::CreatePlant()
{
    
}



//���� ���������� ������
void GardenManager::CreateRace()
{
    Race newRace;
    string message;
    while (true)
    {
        input->Clear();
        ClearScreen();
        cout << "\"������������ ���\"" << endl;
        cout << "�������� ���� ��������" << endl;
        cout << "��������� ����� - 9" << endl;
        cout << (message.empty()? "" : message + "\n");
        cout << "������� �������� ����: " << endl;

        input->InputLine();
        if (input->OnlyDigits() && atoi(input->GetInput().c_str()) == BACK)
            return;

        if (!input->OnlyLetters())
        {
            message = "�������� ������ ��������� ������ �����!";
            continue;
        }

        if (input->GetInputSize() < 3)
        {
            message = "�������� ������ �������� ��� ������� �� ���� ����!";
            continue;
        }

        if (RaceExist(input->GetInput()))
        {
            message = "��� � ����� ������ ��� �������";
            continue;
        }

        newRace.SetName(input->GetInput());
        break;
    }


    while (true)
    {
        input->Clear();
        ClearScreen();
        cout << "\"������������ ���\"" << endl;
        cout << "�������� ���� ��������" << endl;
        cout << "��������� ����� - 9" << endl;
        cout << (message.empty()? "" : message + "\n");
        cout << "�������� �������� � ���?" << endl;
        cout << "1 - ��\n";
        cout << "2 - ���\n";

        input->InputLine();

        if (!input->OnlyDigits() || input->GetInputSize() > 1)
        {
            message = "������������ ����";
            continue;
        }

        if (input->OnlyDigits() && atoi(input->GetInput().c_str()) == BACK)
            return;

        if (input->GetInput() == "1")
            AddingPlantsToRace(newRace);
        
        if (input->GetInput() == "2")
            break;
    }
    SaveRace(newRace);
}

bool GardenManager::RaceExist(string name)
{
    fstream file("data//races.txt", ios::app);
    string buf;
    if (file.is_open())
    {
        while (!file.eof())
        {
            getline(file, buf);
            if (!buf.empty())
                if (Strtok(buf, '$')[0] == name)
                    return true;
        }
    }

    return false;
}

void GardenManager::SaveRace(Race newRace)
{
    string plants = "";
    fstream file("data//races.txt", ios::app);
    for (auto plant : newRace.GetPlants())
        plants += plant->GetName() + '|';
    plants.pop_back();
    if (file.is_open())
        file << newRace.GetName() << '$' << plants << endl;
}

void GardenManager::AddingPlantsToRace(Race newRace)
{
    string message;
    while (true)
    {
        input->Clear();
        ClearScreen();
        cout << "\"������������ ���\"" << endl;
        cout << "�������� ���� ��������" << endl;
        cout << "��������� ����� - 9" << endl;
        cout << (message.empty()? "" : message + "\n");
        cout << "������� �������� ��� ����� �������� ��������: " << endl;
        input->InputLine();
    }
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

vector<string> GardenManager::Strtok(string input, char separator)
{
    vector<string> res;
    string buf;
    for (auto i : input)
    {
        if (i == separator)
        {
            if (!buf.empty())
            {
                res.push_back(buf);
                buf.clear();
            }
            continue;
        }
        buf.push_back(i);
    }
    if (!buf.empty())
        res.push_back(buf);
    return res;
}




