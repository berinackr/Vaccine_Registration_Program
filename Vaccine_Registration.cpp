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

void IDtest(user& user1) { //kayit icin kontrol

	char strID[5];//gecici ID
	int count = 0;

	fstream file("database.txt", ios::app | ios::in);//dosyayi okumak ve eklemek icin acar 

	if (file.is_open())//dosyanin acilip acilmadigini kontrol eder.
	{
		strcpy(strID, user1.ID);//girilen IDyi strIDye kopyalar

		while (1) {//sonsuz donguye girer
			count = 0;

			for (int i = 0; i < 2; i++)//ilk iki karakterin harf olup olmadigini kontrol eder
			{
				if (isalpha(strID[i]))
				{
					strID[i] = toupper(strID[i]);//kucuk harf ile giris yapildiysa onu buyuk harfe cevirir
					count++;
				}

			}
			for (int i = 2; i < 4; i++)//son iki karakterin rakam olup olmadigini kontrol eder
			{
				if (isdigit(strID[i]))
				{
					//strID[i] = toupper(strID[i]);
					count++;
				}

			}
			if (count != 4) {// strID yanlissa tekrar girilmesini ister

				cout << "Your ID is not true. ID must be HHRR. HH = character of alphabet, RR = digit" << endl;
				cout << "Please enter your ID again:";
				cin.getline(strID, 5);

			}
			else//ID dogruysa donguyu sonlandırır.
				break;
		}
		strcpy(user1.ID, strID);//dogru girilen strIDyi orjinal IDye kopyalar
		file << user1.ID << ' '; // ID'yi dosyaya ekler
	}
	else
	{
		cout << "File could not be opened." << endl;//dosya acilmadiysa uyarı mesajı olusturdum
	}

	file.close();
	system("cls");
}

void Register() { //kullanici kayit fonksiyonu

	system("cls");

	struct user newUser;
	char again;
	fstream file("database.txt", ios::app);//dosyayi eklemek icin acar

	do {

		cin.ignore();
		cout << "\t\t\t\tEnter your ID(4-digit): ";
		cin.getline(newUser.ID, 5);
		IDtest(newUser); //ID2yi kontrol eder
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
