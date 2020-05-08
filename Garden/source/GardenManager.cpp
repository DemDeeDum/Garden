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
    Plant newPlant;
    try
    {
        newPlant.SetName(CreatePlantName());
        newPlant.SetFamily(PlantFamily(GivePlantFamily()));
        newPlant.SetSpecie(PlantSpecies(GivePlantSpecie()));
        newPlant.SetRace(SetPlantRace());
    }
    catch (...)
    {
        return;
    }

    SavePlant(newPlant);
}

string GardenManager::CreatePlantName()
{
    while (true)
    {
        input->Clear();
        ClearScreen();
        cout << "\"������������ ���\"" << endl;
        cout << "�������� ��������" << endl;
        cout << "����� � ���� - 9" << endl;
        cout << (message.empty() ? "" : message + "\n");
        message.clear();
        cout << "������� �������� ��������: " << endl;

        input->InputLine();
        if (input->OnlyDigits() && atoi(input->GetInput().c_str()) == BACK)
            throw "Back";

        if (input->GetInputSize() < 2)
        {
            message = "�������� ������ �������� ��� ������� �� ���� ����!";
            continue;
        }


        if (ObjectExist(input->GetInput(), this->PlantsAddress))
        {
            message = "�������� � ����� ������ ��� �������";
            continue;
        }

        return (input->GetInput());
    }
}

int GardenManager::GivePlantFamily()
{
    while (true)
    {
        input->Clear();
        ClearScreen();
        cout << "\"������������ ���\"" << endl;
        cout << "�������� ��������" << endl;
        cout << "����� � ���� - 9" << endl;
        cout << (message.empty() ? "" : message + "\n");
        message.clear();
        cout << "�������� ��������� ��������: " << endl;

        for (int i = 0; i <= (int)PlantFamily::BLUEGRASS; i++)
            cout << i + 1 << ") " << Plant::GetFamilyStringValue(PlantFamily(i)) << endl;

        input->InputLine();
        if (input->OnlyDigits() && atoi(input->GetInput().c_str()) == BACK)
            throw("Back");

        if (!input->OnlyDigits())
        {
            message = "������������ ����!";
            continue;
        }

        try 
        {
            return (int)Plant::GetFamilyEnumValue(atoi(input->GetInput().c_str()));
        }
        catch (...)
        {
            message = "������� �������� �������� ���!";
        }
    }
}

int GardenManager::GivePlantSpecie()
{
    while (true)
    {
        input->Clear();
        ClearScreen();
        cout << "\"������������ ���\"" << endl;
        cout << "�������� ��������" << endl;
        cout << "����� � ���� - 9" << endl;
        cout << (message.empty() ? "" : message + "\n");
        message.clear();
        cout << "�������� ��� ��������: " << endl;

        for (int i = 0; i <= (int)PlantSpecies::FLOWERY; i++)
            cout << i + 1 << ") " << Plant::GetSpecieStringValue(PlantSpecies(i)) << endl;

        input->InputLine();
        if (input->OnlyDigits() && atoi(input->GetInput().c_str()) == BACK)
            throw("Back");

        if (!input->OnlyDigits())
        {
            message = "������������ ����!";
            continue;
        }

        try
        {
            return (int)Plant::GetSpecieEnumValue(atoi(input->GetInput().c_str()));
        }
        catch (...)
        {
            message = "������� �������� �������� ���!";
        }
    }
}

Race* GardenManager::SetPlantRace()
{
    while (true)
    {
        input->Clear();
        ClearScreen();
        cout << "\"������������ ���\"" << endl;
        cout << "�������� ��������" << endl;
        cout << "����� � ���� - 9" << endl;
        cout << (message.empty() ? "" : message + "\n");
        message.clear();
        cout << "�������� ��� ��������?\n�� - 1\n��� - 2 " << endl;

        input->InputLine();
        if (input->OnlyDigits() && atoi(input->GetInput().c_str()) == BACK)
            throw("Back");

        if (!input->OnlyDigits())
        {
            message = "������������ ����!";
            continue;
        }

        int val = atoi(input->GetInput().c_str());
        if(val == 1)
            break;
        else if(val == 2)
            return nullptr;
        else
        {
            message = "������������ �������� �����";
            continue;
        }
    }

    while (true)
    {
        auto races = SearchRaces();
        input->Clear();
        ClearScreen();
        cout << "\"������������ ���\"" << endl;
        cout << "�������� ��������" << endl;
        cout << "����� � ���� - 9" << endl;
        cout << (message.empty() ? "" : message + "\n");
        message.clear();
        cout << "������� �������������� ����\n�������� ���� �� ���" << endl;

        for (int i = 0; i < races.size(); i++)
            cout << i << ") " << races[i].GetName() << endl;

        input->InputLine();
        if (input->OnlyDigits() && atoi(input->GetInput().c_str()) == BACK)
            throw("Back");

        if (!input->OnlyDigits())
        {
            message = "������������ ����!";
            continue;
        }

        try
        {
            return new Race(move(races[atoi(input->GetInput().c_str())]));
        }
        catch(...)
        {
            message = "������������ �������� �����";
            continue;
        }
    }
}

void GardenManager::SavePlant(Plant newPlant)
{
    /*ofstream file(this->PlantsAddress, ios::app);
    if (file.is_open())
        file << newPlant.GetName() << '$';

    file << endl;*/
    this->message = "�������� " + newPlant.GetName() + " ������� �������!";
    this->message = newPlant.GetName() + " " + Plant::GetFamilyStringValue(newPlant.GetFamily()) +
        " " + Plant::GetSpecieStringValue(newPlant.GetSpecie()) + " " +
        (newPlant.GetRace() == nullptr ? "None race" : newPlant.GetRace()->GetName());
}


//���� ���������� ������
void GardenManager::CreateRace()
{
    Race newRace;

    try
    {
        newRace.SetName(CreateRaceName());
    }
    catch (...)
    {
        return;
    }
 
    while (true)
    {
        input->Clear();
        ClearScreen();
        cout << "\"������������ ���\"" << endl;
        cout << "�������� ���� ��������" << endl;
        cout << "����� � ���� - 9" << endl;
        cout << (message.empty()? "" : message + "\n");
        message.clear();
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

string GardenManager::CreateRaceName()
{
    while (true)
    {
        input->Clear();
        ClearScreen();
        cout << "\"������������ ���\"" << endl;
        cout << "�������� ���� ��������" << endl;
        cout << "����� � ���� - 9" << endl;
        cout << (message.empty() ? "" : message + "\n");
        message.clear();
        cout << "������� �������� ����: " << endl;

        input->InputLine();
        if (input->OnlyDigits() && atoi(input->GetInput().c_str()) == BACK)
            throw "Back";

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

        if (ObjectExist(input->GetInput(), this->PlantRacesAddress))
        {
            message = "��� � ����� ������ ��� �������";
            continue;
        }

        return input->GetInput();
    }

}

void GardenManager::SaveRace(Race newRace)
{
    string plants = "";
    ofstream file(this->PlantRacesAddress, ios::app);
    if (file.is_open())
        file << newRace.GetName() << '$';

    if (newRace.GetPlants().size() != 0)
    {
        for (auto plant : newRace.GetPlants())
            plants += plant->GetName() + '|';
        plants.pop_back();
        file << plants;
    }
    file << endl;
    this->message = "��� " + newRace.GetName() + " ������� ������!";
}

void GardenManager::AddingPlantsToRace(Race newRace)
{
   /* while (true)
    {
        input->Clear();
        ClearScreen();
        cout << "\"������������ ���\"" << endl;
        cout << "�������� ���� ��������" << endl;
        cout << "��������� ����� - 9" << endl;
        cout << (message.empty()? "" : message + "\n");
        cout << "������� �������� ��� ����� �������� ��������: " << endl;
        input->InputLine();
    }*/
}


//����� ������
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

bool GardenManager::ObjectExist(string name, string address)
{
    ifstream file(address);
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


//������ ��������� �� ������
vector<Plant> GardenManager::SearchPlants()
{
    input->Clear();
    ClearScreen();
    cout << "\"������������ ���\"" << endl;
    cout << "����� �������� � ����" << endl;
    cout << "����� � ���� - 9" << endl;
    cout << (message.empty() ? "" : message + "\n");
    cout << "������� ��� ��� ����� ����� ��������" << endl;

    input->InputLine();

    input->InputLine();
    if (input->OnlyDigits() && atoi(input->GetInput().c_str()) == BACK)
        throw "Back";

}

Plant GardenManager::GetPlant(string name)
{
    return Plant();
}

vector<Race> GardenManager::SearchRaces()
{
    while (true)
    {
        input->Clear();
        ClearScreen();
        cout << "\"������������ ���\"" << endl;
        cout << "����� ����� ��������" << endl;
        cout << "����� � ���� - 9" << endl;
        cout << (message.empty() ? "" : message + "\n");
        cout << "������� ��� ��� ����� ����� ����" << endl;

        input->InputLine();

        if (input->OnlyDigits() && atoi(input->GetInput().c_str()) == BACK)
            throw "Back";

        if (!input->OnlyLetters())
        {
            message = "��� ���� ����� ��������� ������ �����";
            continue;
        }

        string buf;
        vector<Race> res;
        ifstream file(this->PlantRacesAddress);
        if (file.is_open())
        {
            while (!file.eof())
            {
                getline(file, buf);
                if (!buf.empty())
                {
                    try
                    {
                        auto race = Strtok(buf, '$');
                        //*find(race[0].begin(), race[0].end(), input->GetInput().c_str());
                        res.push_back(CreateRaceFromFile(race));
                    }
                    catch (...)
                    {
                    }
                }
            }
        }
        return res;
    }
}

Race GardenManager::GetRace(string name)
{
    string buf;
    ifstream file(this->PlantRacesAddress);
    if (file.is_open())
    {
        while (!file.eof())
        {
            getline(file, buf);
            auto race = Strtok(buf, '$');
            if (race[0] == name)
                return CreateRaceFromFile(race);
        }
    }
}

Race GardenManager::CreateRaceFromFile(vector<string> values)
{
    return Race(values[0]);
}

