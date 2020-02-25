
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    setlocale(LC_ALL, "");
	int* arr;
	int C = 0,K;
	string O;
	string path = "C:\\Users\\Stryker0\\Desktop\\Универ\\C++\\Semestr2\\lab1\\lab 1 8.1 demo\\lab1.txt";
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
	{
		cout << "Ошибка открытия файла\n";
	}
	else
	{
		cout << "Файл открыт\n";
	}
	while (!fin.eof())
	{
		O = " ";
		fin >> O;
		C++;
	}
	fin.close();
	fin.open(path);
	arr = new int[C];
	for (int i = 0; i < C; i++)
	{
		fin >> K;
		arr[i] = K;
	}
	fin.close();
	int temp;
	for (int i = 0; i < C - 1; i++) {
		for (int j = 0; j < C - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < C; i++) {
		if (arr[i] < 0)
			cout << arr[i] << "\n ";
	}

}