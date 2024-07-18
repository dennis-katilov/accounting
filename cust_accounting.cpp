//////////////////////////////
//    Katilov Dennis        //
//////////////////////////////

#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

//
// prototype of the functions
void searchByCity();
void searchById();
void searchByName();
void characteristics();

// struct of the klients
struct Klient
{
	string nameKlient;
	string lastNameKlient;
	string cityKlient;
	int personKod;
	string numberOfAgreement;

}; Klient klient;

// struct of the services
struct Service
{
	string serviceDescription;
	string serviceName;
	int serviceKod;
	float servicePrice;

}; Service service;

// This function is Main menu
int mainMenu()
{
	int numberOfmainMenu;
	cout << "MAIN MENU" << endl;
	cout << "----------------------------" << endl;
	cout << "1 - Add / Delete Data" << endl;
	cout << "2 - Show Data" << endl;
	cout << "3 - Charackeristics Of Data" << endl;
	cout << "9 - Exit" << endl;
	cout << "----------------------------" << endl;
	cin >> numberOfmainMenu;
	
	return numberOfmainMenu;
}

// This function is add klients
void addKlient()
{
	cout << "Add Klients" << endl;
	cout << "Enter Klients Person Code" << endl;
	cin >> klient.personKod;
	cout << "Klients name" << endl;
	cin >> klient.nameKlient;
	cout << "Enter Klients Last Name" << endl;
	cin >> klient.lastNameKlient;
	cout << "Enter Klients City" << endl;
	cin >> klient.cityKlient;
	cout << "Enter Service" << endl;
	cin >> klient.numberOfAgreement;
	cout << klient.personKod << " " << klient.nameKlient << " " << klient.lastNameKlient << " " << klient.cityKlient << " " << klient.numberOfAgreement << endl;
	
	// writing data to a file of klients
	ofstream fileOfKlient;
	fileOfKlient.open("klient.bin", ios::binary | ios::app);
	fileOfKlient << klient.personKod << " " << klient.nameKlient << " " << klient.lastNameKlient << " " << klient.cityKlient << " " << klient.numberOfAgreement << "\n";
	fileOfKlient.close();
}

// This function is add services
void addServices()
{
	cout << "Add Services" << endl;
	cout << "Enter Service Code" << endl;
	cin >> service.serviceKod;
	cout << "Enter Service Name" << endl;
	cin >> service.serviceName;
	cout << "Enter Service Price" << endl;
	cin >> service.servicePrice;
	cout << "Enter Service Description" << endl;
	cin >> service.serviceDescription;
	cout << service.serviceKod << " " << service.serviceName << " " << service.servicePrice << " " << service.serviceDescription << endl;
	
	// writing data to a file of service
	ofstream fileOfService;
	fileOfService.open("service.bin", ios::binary | ios::app);
	fileOfService << service.serviceKod << " " << service.serviceName << " " << service.servicePrice << " " << service.serviceDescription << "\n";
	fileOfService.close();
}

// This function is delete klients

void deleteKlient()
{
	vector <string> tmp;
	string n;
	int i = 0, KlientsIdToDel = 0, indxpos = 0;
	ifstream fileOfKlient("klient.bin"); 

	cout << " |	ID	" << " |	Name	" << " |	Last	" << " |	City	" << " |	Service	" << endl;
	cout << " -------------------------------------------------------------------------------" << endl;
	
	while (getline(fileOfKlient, n))
		tmp.push_back(n);
	for (unsigned int i = 0; i < tmp.size(); i++)
	{
		cout << " |" << tmp[i] << " |" << '\n';
	}

	cout << "Enter Klients ID " << endl;
	cin >> KlientsIdToDel;

	tmp.erase(tmp.begin(), tmp.begin() + 1);
	//tmp.erase(tmp.begin(), tmp.end() + 1);
	//int indx = find(tmp.begin(), tmp.begin(), numberKlientCodeToDel) - tmp.begin();
	//cout << indx;
	fileOfKlient.close();
	remove("klient.bin");
	
	for (auto it = tmp.begin(); it != tmp.end() - 1; it++)
	{
		++i;
		cout << " |" << *it << " ";
		if (i == 3)
		{
			cout << endl;
			cout << "--------------------------------------------" << endl;
			i = 0;
		}
		
		ofstream fileOfKlient("klient.bin");
		{
			if (!fileOfKlient)
			{
				cout << "������!" << "\n";
			}

			for (int i = 0; i < tmp.size(); i++)
				fileOfKlient << tmp.at(i) << endl;

			fileOfKlient.close();
		}
	}
}

void deleteServices()
{

}

// This function is menu selection add / delete
void add()
{
	int numberOfAdd;
	cout << "ADD / DELETE MENU" << endl;
	cout << "-------------------------" << endl;
	cout << "1 - Add Klients" << endl;
	cout << "2 - Add Services" << endl;
	cout << "3 - Delete Klients" << endl;
	cout << "4 - Delete Services" << endl;
	cout << "0 - Main Menu" << endl;
	cout << "-------------------------" << endl;
	cin >> numberOfAdd;

	switch (numberOfAdd)
	{
	case 1:
		addKlient();
		break;
	case 2:
		addServices();
		break;
	case 3:
		deleteKlient();
		break;
	case 4:
		deleteServices();
		break;
	case 0:
		system("cls");
		mainMenu();
		break;
	default:
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid Input... Try Again" << endl;
		break;
	}
}

// This function is search of klient menu
void searchOfKlientMenu()
{
	int numberOfSearchOfKlientMenu = NULL;
	cout << "Search Of Klients" << endl;
	cout << "-------------------------------------" << endl;
	cout << "1 - Search By ID" << endl;
	cout << "2 - Search By Name" << endl;
	cout << "3 - Search By City" << endl;
	cout << "0 - Main Menu" << endl;
	cout << "-------------------------------------" << endl;
	cin >> numberOfSearchOfKlientMenu;

	switch (numberOfSearchOfKlientMenu)
	{
	case 1:
		cout << "Enter Klients ID" << endl;
		searchById();
		break;
	case 2:
		cout << "Enter Name" << endl;
		searchByName();
		break;
	case 3:
		cout << "Enter City" << endl;
		searchByCity();
		break;
	case 0:
		system("cls");
		mainMenu();
		break;
	default:
		cout << "Invalid Input... Try Again";
		break;
	}
}

// This function is search of kliens by id
void searchById()
{
	string needed;
	ifstream fileOfKlient("klient.bin");
	string line;
	int i, found = 0;
	cin >> needed;

	while (getline(fileOfKlient, line))
	{
		if (line.substr(0, line.find(' ')) == needed)
		{
			found++;
			cout << line << endl;
		}
	}
	cout << "Found : " << found << " ID " << needed << endl;

	fileOfKlient.close();
	system("pause");
}

// This function is search of kliens by name
void searchByName()
{
	string needed;
	ifstream fileOfKlient("klient.bin");
	string line;
	int i, found = 0;
	cin >> needed;

	while (getline(fileOfKlient, line))
	{
		if (line.find(needed) != string::npos)
		{
			found++;
			cout << line << endl;
		}
	}
	cout << "Found : " << found << " names " << needed << endl;

	fileOfKlient.close();
	system("pause");
}

// This function is search of kliens by city
void searchByCity()
{
	string needed;
	ifstream fileOfKlient("klient.bin");
	string line;
	int i, found = 0;
	cin >> needed;

	while (getline(fileOfKlient, line))
	{
		if (line.find(needed) != string::npos)
		{
			found++;
			cout << line << endl;
		}
	}
	cout << "Found : " << found << " cities " << needed << endl;

	fileOfKlient.close();
	system("pause");
}

// This function is show all kliens
void readAllUsers()
{
	vector <string> tmp;
	string n;
	int i = 0, j = 0 ; 
	ifstream fileOfKlient("klient.bin");

	while (!fileOfKlient.eof())
	{
		fileOfKlient >> n;
		tmp.push_back(n);
	}
	cout << " |	ID	" << " |	Name	" << " |	Last	" << " |	City	" << " |	Service 	"  << endl;
	cout << " -------------------------------------------------------------------------------" << endl;
	
		for (auto it = tmp.begin(); it != tmp.end() - 1; it++)
		{
			++i;
			cout << " |	" << *it << "	";
			if (i == 5)
			{
				cout << endl;
				cout << " -------------------------------------------------------------------------------" << endl;
				i = 0;
			}
			
		}
	
	
	fileOfKlient.close();
}

// This function is show all services
void readAllServices()
{
	vector <string> tmp;
	string n;
	int i = 0;
	ifstream fileOfService("service.bin");
	while (!fileOfService.eof())
	{
		fileOfService >> n;
		tmp.push_back(n);
	}
	cout << " |	 Code	" << " |	Title	" << " |	Price	" << " |	Description	" << endl;
	cout << " ----------------------------------------------------------------------" << endl;

	for (auto it = tmp.begin(); it != tmp.end() - 1; it++)
	{
		++i;
		cout << " |	" << *it << "	";
		if (i == 4)
		{
			cout << endl;
			cout << " ----------------------------------------------------------------------" << endl;
			i = 0;
		}
	}
	fileOfService.close();
	cout << endl;
	cout << endl;
}

// This function is show data menu
void showDataMenu() 
{
	int numberOfShowDataMenu = NULL;
	cout << "SHOW DATA MENU" << endl;
	cout << "-----------------------" << endl;
	cout << "1 - Show All Klients" << endl;
	cout << "2 - Show All Services" << endl;
	cout << "3 - Search Klients" << endl;
	cout << "0 - Main Menu" << endl;
	cout << "-----------------------" << endl;
	cin >> numberOfShowDataMenu;
	
		switch (numberOfShowDataMenu)
		{
		case 1:
			system("cls");
			readAllUsers();
			break;
		case 2:
			system("cls");
			readAllServices();
			break;
		case 3:
			system("cls");
			searchOfKlientMenu();
			break;
		case 0:
			system("cls");
			mainMenu();
			break;
		default:
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input... Try Again";
			break;
		}	
}

// This function is show characteristics
void characteristics()
{
	// amount of the klients
	ifstream fileOfKlient("klient.bin");
	int found = 0;

	while (fileOfKlient.ignore(numeric_limits<streamsize>::max(), '\n'))
	{
		if (!fileOfKlient.eof()) // if at the end of the last line '\ n', otherwise you do not need
			found++;
	}
	cout << "Found : " << found << " klients " << endl;

	fileOfKlient.close();

	// characteristics of services
	string servicesTv = "tv";
	string servicesNet = "net";
	ifstream fileOfService("service.bin");
	string line;
	int foundServicesNet = 0, foundServicesTv = 0;

	while (getline(fileOfService, line))
	{
		if (line.find(servicesTv) != string::npos )
		{
			foundServicesTv++;
		}
		if (line.find(servicesNet) != string::npos)
		{
			foundServicesNet++;
		}
	}
	cout << " - " << foundServicesTv << " TV services " << endl;
	cout << " - " << foundServicesNet << " NET services " << endl;

	fileOfService.close();

	system("pause");
	system("cls");
}

// This is main function
int main()
{
	while (true)
	{
		switch (mainMenu())
		{
		case 1:
			system("cls");
			add();
			break;
		case 2:
			system("cls");
			showDataMenu();
			break;
		case 3:
			system("cls");
			characteristics();
			break;
		case 9:
			system("cls");
			exit(0);
			break;
		case 0:
			system("cls");
			mainMenu();
			break;
		default:
			// if users input is NOT a digit or number not in range, clear "cin"
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input... Input must be ONLY a DIGIT...Try Again please" << endl;
			mainMenu();
			break;
		}
		//getch();
	}
	return 0;
}

