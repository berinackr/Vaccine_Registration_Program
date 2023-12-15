#include<iostream>
#include<ctype.h>

using namespace std;

struct VaccineInformation { // aþý bilgilerinin structi
	string lastDate;
	char vaccineName;
	int doseNo;
} vac1 = { "01.06.2020" , NULL , 0 };

struct user { //kisisel bilgi structi
	char ID[5];
	string name;
	string surname;
	string city;
	int age;
	struct VaccineInformation vac;//asý bilgileri
}user1;


void main()
{
	int option = 0;

	while (option != 6)
	{
		cout << endl << " \t\t\t\t    # VACCINE REGISTRATION PROGRAM # " << endl << endl;
		cout << "\t\t\t\t(1) Register" << endl;
		cout << "\t\t\t\t(2) Display user registration" << endl;
		cout << "\t\t\t\t(3) Update user registration" << endl;
		cout << "\t\t\t\t(4) Create new vaccine registration" << endl;
		cout << "\t\t\t\t(5) Display all registrations" << endl;
		cout << "\t\t\t\t(6) EXIT" << endl << endl;

		cout << "\t\t\t\tPlease choose one option: "; // kullanicidan secenek ister
		cin >> option;

		switch (option)//istenilen secenege gore uygun islemi yapar
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		default://uygun olmayan bir tercihte kullaniciyi uyarir
			cout << "The choice you entered was not valid," << endl;
			cout << "Please enter a valid option." << endl;
			break;
		}

		system("cls");
	}
	system("pause");
}