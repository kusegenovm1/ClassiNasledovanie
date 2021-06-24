#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>

using namespace std;

class Harbinger
{
private:
	string h_name;
	int h_age;
	string CatchPhrase;
public:
	Harbinger(string h_name = "hh", int h_age = 18, string phrase = "abcd")
	{
		this->h_name = h_name;
		this->h_age = h_age;
		CatchPhrase = phrase;
	}
	string getName() const { return h_name; }// геттер для h_name
	void setName(string name) { h_name = name; } // сеттер для h_name
	int getAge() const { return h_age; }  //геттер для h_age
	void setAge(int age) { h_age = age; }  // сеттер для h_age
	string getPhrase() const { return CatchPhrase; }// геттер для CatchPhrase
	void setPhrase(string Phrase) { CatchPhrase = Phrase; } // сеттер для CatchPhrase
};

//создание 2 класса 
class Phophet : public Harbinger {
private:
	string MagnumOpus[3];
	string ph_name;
	int ph_age;
	string ph_call;
public:
	Phophet(string h_name = "qwe", int h_age = 25, string phrase = "wer", string ph_name = "ert", string ph_call = "rty", string MOValue = "tyu", int ph_age = 20)
		: Harbinger(h_name, h_age, phrase) {
		this->ph_name = ph_name;
		this->ph_call = ph_call;
		this->ph_age = ph_age;
		for (int i = 0; i < 3; i++)
		{
			MagnumOpus[i] = MOValue;
		}
	}
	string* getMagnumOpus() { return MagnumOpus; } //геттер для MagnumOpus
	void setMagnumOpus() {   //сеттер для MagnumOpus
		cout << "Vvedite massiv magnumOpus" << endl;
		for (int i = 0; i < 3; i++)
		{
			cout << "Vvedite " << i << " element: ";
			do {
				cin >> MagnumOpus[i];
				if (MagnumOpus[i].length() > 25)
				{
					cout << "Stroka dlinnaya, povtorite: ";
				}
			} while (MagnumOpus[i].length() > 25);
		}
		setPhCall();
	}
	string getPhName() { return ph_name; } //геттер для ph_name
	void setPhName(string _phName) { ph_name = _phName; } //сеттер для ph_name

	int getPhAge() { return ph_age; }  //геттер для ph_age
	void setAge(int _PhAge) { ph_age = _PhAge; }  // сеттер для ph_age

	string getPhCall() { return ph_call; } //геттер для ph_call
	void setPhCall() {    //сеттер для ph_call	
		string longestString = MagnumOpus[0];
		for (int i = 1; i < 3; i++)
		{
			if (MagnumOpus[i].length() > longestString.length())
			{
				longestString = MagnumOpus[i];
			}
		}
		ph_call = longestString;
	}

};
//создание 3 класса
class DeusEx : public Phophet
{
private:
	string gd_name;
	int gd_year;

public:
	// К-р по умолчанию
	DeusEx(string h_name = "aaa", int h_age = 24, string phrase = "bbb", string ph_name = "ccc", string ph_call = "ddd", string defaltMagnumOpusElementValue = "eee", int ph_age = 25, string gd_name = "fff")
		// Наследуем конструктор из Prophet
		: Phophet(h_name, h_age, phrase, ph_name, ph_call, defaltMagnumOpusElementValue, ph_age) {
		this->gd_name = gd_name;
		srand(time(0));
		gd_year = rand() % 10000; 		// Рандом от 0 до 9999
	}

	// Геттеры
	string Get_gd_name() { return gd_name; }  //геттер для gd_name
	int Get_gd_year() { return gd_year; }     //геттер для gd_year

	// Метод, использующий унаследованные методы для вывода информации
	void ShowInfo() {
		setName("Predvestnik");
		setAge(100000);
		setPhrase("pridet Prorok");
		setPhName("Prorok");
		setMagnumOpus();

		cout << getName() << " в возрасте " << getAge() << " говорил, что " << getPhrase() << ".\n";
		int count = 0;
		for (int i = 0; i < 3; i++)
		{
			// Поиск  пророчеств. Главное пророчество - самый длинный элемент массива MagnumOpus. Остальные - первое и второе пророчества
			if (getMagnumOpus()[i] == getPhCall())
			{
				continue;
			}
			else
			{
				count++;
				if (count == 1)
				{
					cout << "pervoe ";
				}
				else if (count == 2)
				{
					cout << "vtoroe ";
				}
				cout << "пророчество: " << getMagnumOpus()[i] << "\n";
			}
		}
		cout << "Glavnoe prorochestvo: " << getPhCall() << ".\n";
		cout << "Tak govoril " << getPhName() << ".\n\n";
		cout << "V god " << gd_year << " prishel " << gd_name << ", kotorogo predrekali" << getName() << " и " << getPhName() << ".\n\n";
	}
};

//создание 4 класса
class Believer : private DeusEx
{
private:
	string bv_name;
	int bv_age;

public:
	Believer(string bv_name, int bv_age) //конструктор
	{
		this->bv_name = bv_name;
		this->bv_age = bv_age;
	}

	// Геттеры
	string Get_bv_name() { return bv_name; }   //геттер для bv_name
	int Get_bv_age() { return bv_age; }        //геттер для bv_age

	// Сеттеры
	void SetBelieverName(string bv_name) { this->bv_name = bv_name; }  //сеттер для bv_name
	void SetBelieverAge(int bv_age) { this->bv_age = bv_age; } //сеттер для bv_age

	// Метод, использующий унаследованные методы для вывода информации
	void ShowMessage() {
		cout << "Veruyushi " << bv_name << " molitsya " << Get_gd_name() << " imenem " << getPhName() << "\n\n";
	}
};

int main()
{
	setlocale(LC_ALL, "ru");

	Phophet prophet;
	DeusEx god;
	Believer believer("Батя", 30);

	prophet.setMagnumOpus();
	cout << "ph_call: " << prophet.getPhCall() << "\n\n";
	god.ShowInfo();
	believer.ShowMessage();

	system("pause");
	return 0;
}