#include<iostream>
#include<string>//getline icin
#include<fstream>//dosya islemleri icin
#include<ctype.h>
#include<conio.h>//_getch icin

using namespace std;

struct VaccineInformation { // aşı bilgilerinin structi
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

void ID(char test[]) {//islemler icin kontrol
	char strID[5];//gecici ID
	int count = 0;

	strcpy(strID, test);//girilen IDyi strIDye kopyalar
	cin.ignore();
	while (1) {//sonsuz donguye girer
		count = 0;
		for (int i = 0; i < 2; i++)//ilk iki karakterin harf olup olmadigini kontrol eder
		{
			if (isalpha(strID[i]))
			{
				strID[i] = toupper(strID[i]);
				count++;
			}

		}
		for (int i = 2; i < 4; i++)//son iki karakterin rakam olup olmadigini kontrol eder
		{
			if (isdigit(strID[i]))
			{
				strID[i] = toupper(strID[i]);
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
	strcpy(test, strID);//dogru girilen strIDyi orjinal IDye kopyalar
	system("cls");
}

void Register() { //kullanici kayit fonksiyonu

	system("cls");

	struct user newUser;
	char again;
	fstream file("database.txt", ios::app);//dosyayi eklemek icin acar

	do {

		cin.ignore();
		cout << "\t\t\t\tEnter your ID: ";
		cin.getline(newUser.ID, 5);
		IDtest(newUser); //ID2yi kontrol eder
		cout << "\t\t\t\tEnter your ID: " << newUser.ID << endl;

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

void viewRegistation() { //istenilen kullanici bilgisini goruntuleyen fonksiyon

	fstream file("database.txt", ios::in);

	if (file.is_open())
	{
		char test[5];
		int flag = 0;
		system("cls");


		cout << "\t\t\tPlease, enter ID of user which you want to display:";
		cin >> test;
		ID(test);


		//file.seekg(-1L, ios::cur);//alt satırın wn daşından başlaması icin bu satırı yazdım
		file >> user1.ID >> user1.name >> user1.surname >> user1.age >> user1.city >> user1.vac.lastDate >> user1.vac.doseNo >> user1.vac.vaccineName;

		while (!file.eof())//dosyanın acik olup olmadigini kontrol eder
		{
			if (strcmp(test, user1.ID) == 0)
			{

				cout << "\t\t\t\t\t___ USER'S PERSONAL INFORMATION ___ " << endl;
				cout << "\t\t\t\tID: " << user1.ID << endl;
				cout << "\t\t\t\tName: " << user1.name << endl;
				cout << "\t\t\t\tSurname: " << user1.surname << endl;
				cout << "\t\t\t\tAge: " << user1.age << endl;
				cout << "\t\t\t\tCity: " << user1.city << endl;
				cout << "\t\t\t\t\t___ USER'S VACCINE INFORMATION ___ " << endl;
				cout << "\t\t\t\tLast vaccination date: " << user1.vac.lastDate << endl;
				cout << "\t\t\t\tVaccine name: " << user1.vac.vaccineName << endl;
				cout << "\t\t\t\tVaccine dose no: " << user1.vac.doseNo << endl;
				flag++; // kullanıcının dosyada oldugunu kontrolu icin
				break;
			}

			file >> user1.ID >> user1.name >> user1.surname >> user1.age >> user1.city >> user1.vac.lastDate >> user1.vac.doseNo >> user1.vac.vaccineName;
		}
		if (flag == 0)
		{
			cout << endl << "\t\t\t\tThis ID is not registered." << endl; // kullanıcı yoksa bilgilendirir
		}
		_getch();
		file.close();
	}
	else
	{
		cout << "File could not be opened." << endl;
	}
}

void updateData()
{
	int flag = 0;
	fstream file, new_file;
	file.open("database.txt", ios::in | ios::out);

	if (file.is_open())
	{
		char test[5];

		system("cls");

		cout << "\t\t\tPlease, enter ID of user which you want to display:";
		cin >> test;
		ID(test);

		new_file.open("Record.txt", ios::app | ios::out); //dosyayı eklemek icin acar

		file >> user1.ID >> user1.name >> user1.surname >> user1.age >> user1.city >> user1.vac.lastDate >> user1.vac.doseNo >> user1.vac.vaccineName;
		while (!file.eof())
		{
			if (strcmp(test, user1.ID) == 0) // yeni bilgileri kullanicidan alir
			{
				cout << endl << "\t\t\tRegistered ID: " << user1.ID << endl;
				cout << "\t\t\tEnter new ID: ";
				cin.getline(user1.ID, 5);
				IDtest(user1);
				new_file << user1.ID << ' ';

				cout << endl << "\t\t\tRegistered name: " << user1.name << endl;
				cout << "\t\t\tEnter new name: ";
				cin >> user1.name;
				user1.name[0] = toupper(user1.name[0]);
				new_file << user1.name << ' ';

				cout << endl << "\t\t\tRegistered surname: " << user1.surname << endl;
				cout << "\t\t\tEnter your surname: ";
				cin >> user1.surname;
				user1.surname[0] = toupper(user1.surname[0]);
				new_file << user1.surname << ' ';

				cout << endl << "\t\t\tRegistered age: " << user1.age << endl;
				cout << "\t\t\tEnter your age: ";
				cin >> user1.age;
				new_file << user1.age << ' ';

				cout << endl << "\t\t\tRegistered city: " << user1.city << endl;
				cout << "\t\t\tEnter your city: ";
				cin >> user1.city;
				user1.city[0] = toupper(user1.city[0]);
				new_file << user1.city << ' ';

				new_file << user1.vac.lastDate << " ";
				new_file << user1.vac.doseNo << " ";
				new_file << user1.vac.vaccineName;
				new_file << endl;
				flag++;
			}
			else //istenilen ID degilse onun bilgilerini yeni dosyaya kaydeder
			{
				new_file << user1.ID << " " << user1.name << " " << user1.surname << " " << user1.age << " " << user1.city << " " << user1.vac.lastDate << " " << user1.vac.doseNo << " " << user1.vac.vaccineName;
				new_file << endl;
			}

			file >> user1.ID >> user1.name >> user1.surname >> user1.age >> user1.city >> user1.vac.lastDate >> user1.vac.doseNo >> user1.vac.vaccineName;
		}
		if (flag == 0)
		{
			cout << endl << "\t\t\t\This ID is not registered." << endl;
		}
		_getch();

		new_file.close();
		file.close();
		remove("database.txt");
		rename("Record.txt", "database.txt");
	}
	else
	{
		cout << "File could not be opened." << endl;
	}
}

void allRegistrations() { //tum kullanici kayitlarini yazdiran fonksiyon
	fstream file("database.txt", ios::in);

	if (file.is_open())
	{
		string line;

		system("cls");

		cout << " \t\t\t\t    # All Vaccine Registrations #" << endl;
		while (getline(file, line)) {//dosyayi satir satir okur

			cout << "\t\t\t\t" << line << endl;

		}

		_getch();
		file.close();
	}
	else
	{
		cout << "File could not be opened." << endl;
	}
	system("cls");
}

bool AgeControl() //18 yasindan buyuk olup olmadıgını kontrol eder
{
	if (user1.age < 18) // kucukse kullaniciya uyari mesaji yazar
	{
		cout << "\n\t\t\tPerson under the age of 18 cannot register for vaccination!" << endl;
		return 0;
	}
	else
		return 1;
}
bool VaccineDoseControl()//dose sayisini kontrol eden fonksiyon
{
	if (user1.vac.doseNo == 2)//Dose sayisi 2 ise kullanıcıya uyari mesaji yazar.
	{
		cout << "\n\t\t\tYou have reached the maximum vaccine dose level.\n You can't vaccinate any more." << endl;
		return 0;
	}
	else
		return 1;
}
bool VaccineTypeControl(char vaccineType) //Asi türünü kontrol eden fonksiyon
{
	if (user1.vac.vaccineName != NULL)
	{
		if (user1.vac.vaccineName != toupper(vaccineType))// farkli asi yapmak istediginde uyari mesaji yazar.
		{
			cout << "\n\t\t\tYou cannot have this vaccine.\nRequest registration of the type of your previous vaccination" << endl;
			return 0;
		}
		else
			return 1;
	}
	else
		return 1;
}
bool DateControl() // son asi tarihini kontrol eden fonksiyon
{
	int year, month, day;
	int year1, month1, day1;
	int total;

	//kayitli gun ay yil string bilgilerini alir ve integera cevirir
	day1 = stoi(user1.vac.lastDate.substr(0, 2));
	month1 = stoi(user1.vac.lastDate.substr(3, 2));
	year1 = stoi(user1.vac.lastDate.substr(6, 4));

	//sistem saatinden gun ay yil bilgilerini alir
	time_t now = time(0);

	tm* ltm = localtime(&now);

	year = 1900 + ltm->tm_year;
	month = 1 + ltm->tm_mon;
	day = ltm->tm_mday;

	total = (day - day1) + (month - month1) * 30 + (year - year1) * 365; //arasindaki gun farkini bulur

	if (total >= 30)//gun farki 30dan fazla ise yeni tarih bilgilerini ekler
	{
		if (day < 10)
			user1.vac.lastDate = '0' + to_string(day) + '.';
		else
			user1.vac.lastDate = to_string(day) + '.';
		if (month < 10)
			user1.vac.lastDate += '0' + to_string(month) + '.';
		else
			user1.vac.lastDate += to_string(month) + '.';

		user1.vac.lastDate += to_string(year);
		return 1;
	}
	else//30 gunden az ise kullaniciya uyarı mesaji yazar 
	{
		cout << "\n\t\t\tYou have been vaccinated within the last month." << endl;
		return 0;
	}
}

void VaccineRegistration()//asi kayidi olusturma fonksiyonu
{
	char VaccineType;
	char test[5];
	int flag = 0;

	fstream file, new_file;
	file.open("database.txt", ios::in); //dosyayi okumak icin acar

	system("cls");

	if (file.is_open())//dosyanin acilip acilmadigini kontrol eder
	{

		system("cls");
		cout << "\t\t\tPlease, enter ID for vaccine registration: "; //kullanicidan kayit olusturulacak ID istenilir
		cin >> test;
		ID(test);

		new_file.open("Record.txt", ios::app | ios::out); // yeni dosya acilir

		file >> user1.ID >> user1.name >> user1.surname >> user1.age >> user1.city >> user1.vac.lastDate >> user1.vac.doseNo >> user1.vac.vaccineName;
		while (!file.eof())
		{
			if (strcmp(test, user1.ID) == 0)
			{
				new_file << user1.ID << " " << user1.name << " " << user1.surname << " " << user1.age << " " << user1.city;
				if (AgeControl() == 1 && VaccineDoseControl() == 1 && DateControl() == 1) // asi kayit sartlari kontrol edilir
				{
					cout << "\t\t\tThere are 2 types of vaccines, please choose one of them" << endl; // asi turu kullanicidan istenilir
					cout << "\t\t\tX or Y ? ";
					cin >> VaccineType;
					cout << endl;

					do { // asi turu dogru olana kadar kullanıcıdan deger ister
						if (VaccineTypeControl(VaccineType) == 0)
							VaccineType = NULL;
						while (toupper(VaccineType) != 'X' && toupper(VaccineType) != 'Y' || tolower(VaccineType) != 'x' && tolower(VaccineType) != 'y')
						{
							cout << endl << "\t\t\tERROR! Please choose one of X and Y: ";
							cin >> VaccineType;
						}
					} while (VaccineTypeControl(VaccineType) == 0);

					//kayit olusturulunca dose sayisi ve turu kullanici bilgilerine atanir
					user1.vac.doseNo++;
					user1.vac.vaccineName = toupper(VaccineType);
					cout << "\t\t\tVaccine registration successfully created!";
				}
				else
				{
					cout << "\n\t\t\tYour vaccination registration could not be created." << endl;
				}
				//tum asi bilgileri yeni dosyaya kaydedilir
				new_file << " " << user1.vac.lastDate;
				new_file << " " << user1.vac.doseNo;
				new_file << " " << user1.vac.vaccineName;
				new_file << endl;
				flag++;

			}
			else
			{
				new_file << user1.ID << " " << user1.name << " " << user1.surname << " " << user1.age << " " << user1.city << " " << user1.vac.lastDate << " " << user1.vac.doseNo << " " << user1.vac.vaccineName;
				new_file << endl;
			}

			file >> user1.ID >> user1.name >> user1.surname >> user1.age >> user1.city >> user1.vac.lastDate >> user1.vac.doseNo >> user1.vac.vaccineName;
		}
		if (flag == 0)
		{
			cout << endl << "\n\t\t\tThis ID is not registered." << endl;
		}
		_getch();

		new_file.close();
		file.close();
		remove("database.txt");//eski dosya silinir
		rename("Record.txt", "database.txt"); //yeni dosyanin ismi degistirilir
	}
	else
	{
		cout << "File could not be opened." << endl;
	}
}

void main()
{
	int option = 0;

	allRegistrations(); // program baslangıcında kayitli kullanici varsa ekrana yazdirir

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
			viewRegistation();
			break;
		case 3:
			updateData();
			break;
		case 4:
			VaccineRegistration();
			break;
		case 5:
			allRegistrations();
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
