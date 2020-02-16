// lab1 8.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	setlocale(LC_ALL, "");

	int* arr; 
	int size; 
	int i;
	cout << "n = ";
	cin >> size;
	arr = new int[size]; 
	string path = "C:\\Users\\Stryker0\\Desktop\\Универ\\C++\\semestr2\\lab1 8.1\\lab1.txt";
	ifstream fin;
	fin.open(path);
	for (i = 0; i < size; i++)
	{
		fin >> arr[i];
	}
	if (!fin.is_open())
	{
		cout << "Ошибка открытия файла\n";
	}
	else
	{
		cout << "Файл открыт\n";
	}
	int temp;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < size; i++) {
		if (arr[i] < 0)
		cout << arr[i] << " ";
	}
	
}