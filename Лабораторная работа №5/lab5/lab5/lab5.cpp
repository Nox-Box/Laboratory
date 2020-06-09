// lab5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct Busfleet //Структура Автобусного парка
{
	string F = "";
	string I = "";
	string O = "";
    string Bus="";//Номер автобуса
    string Route="";//Номер маршрута
    float time=0;//Продолжительность кругового маршрута
};
bool cmpDriver(const Busfleet& r1, const Busfleet& r2) //сравнение по Фамилии водителя
{
    return r1.F < r2.F;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	string x;
	Busfleet s;
	ifstream fin;
	fin.open("Busfleet.txt");
	int n(0);
	if (fin.is_open())
	{
		while (!fin.eof()) //узнаем, сколько автобусов всего
		{
			string s;
			getline(fin, s);
			n++;
		}
	}
	Busfleet* a = new Busfleet[n];
	fin.seekg(0, ios_base::beg);
	for (size_t i = 0; i < n; i++) //заносим данные в массив
	{
		getline(fin, x);
		istringstream iss(x);
		iss >> s.F >>s.I>>s.O>> s.Bus >> s.Route >> s.time;
		a[i] = s;
	}
	cout << "Информация о всех автобусах:\nВодитель-Автобус-Маршрут-Время:\n" << endl;
	for (size_t i = 0; i < n; i++)
	{

			cout << a[i].F << " "
				<< a[i].I << " "
				<< a[i].O << " "
				<< a[i].Bus << " "
				<< a[i].Route<< " "
				<< a[i].time << " " << endl;
		
	}
	cout << "\nИнформация о маршрутах на которых не работает водитель по фамилии Сидоров:\nВодитель-Автобус-Маршрут-Время:\n" << endl;
	for (size_t i = 0; i < n; i++)
	{
		if(a[i].F != "Сидоров")
		{
			cout << a[i].F << " "
				<< a[i].I << " "
				<< a[i].O << " "
				<< a[i].Bus << " "
				<< a[i].Route << " "
				<< a[i].time << " " << endl;
		}
	}
	cout << "\nИнформация о автобусах с маршрутами,продолжительностью меньше двух часов :\nВодитель-Автобус-Маршрут-Время:\n" << endl;
	for (size_t i = 0; i < n; i++)
	{
		sort(a, a + n, cmpDriver);
		if (a[i].time < 120)
		{
			cout 
				<< a[i].F << " "
				<< a[i].I << " "
				<< a[i].O << " "
				<< a[i].Bus << " "
				<< a[i].Route << " "
				<< a[i].time << " " << endl;
		}
	}
}
