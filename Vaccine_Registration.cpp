#include<iostream>
#include<ctype.h>
#include<string>
#include<fstream>//dosya islemleri icin

using namespace std;

struct VaccineInformation { // ası bilgilerinin structi
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
	struct VaccineInformation vac;//ası bilgileri
}user1;

void Register() { //kullanici kayit fonksiyonu

	system("cls");

	struct user newUser;
	char again;
	fstream file("database.txt", ios::app);//dosyayi eklemek icin acar

	do {

		cin.ignore();
		cout << "\t\t\t\tEnter your ID(4-digit): ";
		cin.getline(newUser.ID, 5);
		//IDtest(newUser); //ID2yi kontrol eder
		cout << "\t\t\t\tEnter your ID(4-digit): " << newUser.ID << endl;



		cout << "\t\t\t\tEnter your name: ";
		cin >> newUser.name;
		newUser.name[0] = toupper(newUser.name[0]);  // stringin ilk karakterini buyutur
		file << newUser.name << ' ';

		cout << "\t\t\t\tEnter your surname: ";
		cin >> newUser.surname;
		newUser.surname[0] = toupper(newUser.surname[0]);
		file << newUser.surname << ' ';

		cout << "\t\t\t\tEnter your age: ";
		cin >> newUser.age;
		file << newUser.age << ' ';

		cout << "\t\t\t\tEnter your city: ";
		cin >> newUser.city;
		newUser.city[0] = toupper(newUser.city[0]);
		file << newUser.city << ' ';

		newUser.vac = vac1;
		file << newUser.vac.lastDate << ' ' << newUser.vac.doseNo << ' ' << newUser.vac.vaccineName; // kayıtta ilk asi bilgilerini ekler
		file << endl;
		user1 = newUser;

		cout << "\n\t\t\t\tDo you want to enter another record?" << endl; // yeni kayıt için kullaniciya sorar
		cout << "\t\t\t\tY or N?";
		cin >> again;

		system("cls");
	} while (toupper(again) == 'Y');
	file.close();
}

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
			Register();
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
