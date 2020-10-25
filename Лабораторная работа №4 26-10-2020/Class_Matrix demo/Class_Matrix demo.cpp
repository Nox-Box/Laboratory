// Class_Matrix demo.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Matrix.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int k;
	double s[] = { 1,2,3 };
	Vector v1;


	cout << "Введите три коориднаты вектора:\n";
	for (int i = 0; i < 3; i++) {

		cin >> v1;
	}

	Matrix m1(3, 3), m2;
	
	m2.setSize(3, 3);

	cout << "Введите 9 чисел первой матрицы через пробел:\n ";
	cin >> m1;
	cout << "Введите 9 чисел второй матрицы через пробел:\n ";
	cin >> m2;


	cout << "Mat1:\n" << m1 << "Mat2:\n" << m2;

	cout << "Сумма матриц: ";
	cout << m1 + m2;

	cout << "Умножение матрицы на число: ";
	cin >> k;
	cout << m1 * k;

	cout << "Произведение матриц: ";
	cout << m1 * m2;

	cout << "Умножение матрицы на вектор:\n ";
	cout << m1 * v1;


}



