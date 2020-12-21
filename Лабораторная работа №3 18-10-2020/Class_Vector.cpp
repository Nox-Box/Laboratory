// Class_Vector.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#include <clocale>
#include <math.h>

using namespace std;

class Vector {
private:
	int size;
	double* x;

public:
Vector(double NSize = 0, double* Array = NULL) {
	size = abs(NSize);
	x = NULL;
	if (NSize != 0) {
		x = new double[size];
		for (int i = 0; i < size; i++)
			x[i] = Array[i];
	}
}

Vector(const Vector& vector) : x(vector.x), size(vector.size) {}

void ArrayResize(int NewSize) {
	double* Array = new double[NewSize];
	for (int i = 0; (i < size) && (i < NewSize); i++)
		Array[i] = x[i];

	size = NewSize;

	delete[]x;
	x = Array;
}

int Size() {
	return size;
}

void add(double value) {
	ArrayResize(size);
	x[size - 1] = value;
}

double Scolar(Vector vector) {
	return ((x[0] * vector.x[0]) + (x[1] * vector.x[1]));
}

double Angle(Vector vector) {

	return cos(Scolar(vector) / (LengthVector() * vector.LengthVector()));
}

double LengthVector() {
	double Summ = 0;
	for (int i = 0; i < size - 1; i++)
		Summ += abs(sqrt((x[i] * x[i]) + (x[i + 1] * x[i + 1])));
	return Summ;
}

friend istream& operator>> (istream& is, Vector& vector) {
	for (int i = 0; i < vector.size; i++) if (vector.x[i] == NULL && vector.x[i] != 0) {
		is >> vector.x[i];
		return is;
	}

	vector.ArrayResize(vector.size + 1);
	is >> vector.x[vector.size - 1];
	return is;

}

friend ostream& operator<<(ostream& out, const Vector& vector) {
	if (vector.size == 0) {
		out << "Этот массив пуст.\n" << endl;
		return out;
	}
	else {
		for (int i = 0; i < vector.size; i++) {
			out << i + 1 << ": " << vector.x[i] << endl;
		}

		return out;
	}
}

friend Vector operator+(const Vector& v1, const Vector& v2) {
	Vector vector;
	if (v1.size != v2.size) {
		cout << "Ошибка, векторы разного размера.\n";
		exit(0);
	}
	else {
		vector.ArrayResize(v1.size);
		for (int i = 0; i < vector.size; i++) vector.x[i] = v1.x[i] + v2.x[i];
	}
	return vector;
}

friend Vector operator-(const Vector& v1, const Vector& v2) {
	Vector vector;
	if (v1.size != v2.size) {
		cout << "Ошибка, векторы разного размера.\n";
		exit(0);
	}
	else {
		vector.ArrayResize(v1.size);
		for (int i = 0; i < vector.size; i++) vector.x[i] = v1.x[i] - v2.x[i];
	}
	return vector;
}

friend Vector operator*(const Vector& v1, const Vector& v2) {
	Vector vector;
	vector.ArrayResize(v1.size);
	for (int i = 0; i < v1.size; i++) vector.x[i] = v1.x[i] * v2.x[i];
	return vector;
}

friend Vector operator*(const Vector& v1, int a) {
	Vector vector;
	vector.ArrayResize(v1.size);
	for (int i = 0; i < v1.size; i++) vector.x[i] = v1.x[i] * a;
	return vector;
}

bool operator>(Vector& vector) {

	return LengthVector() > vector.LengthVector();
}

bool operator<(Vector& vector) {
	return LengthVector() < vector.LengthVector();
}

bool operator==(Vector& vector) {
	return LengthVector() == vector.LengthVector();
}

bool operator!=(Vector& vector) {
	return LengthVector() != vector.LengthVector();
}

double& operator[](int index) {
	if (size <= index || index <= 0) {
		cout << "Ошибка, нет переменной с этим индексом\n";
		exit(0);
	}
	else return x[index];
}

~Vector() {
}
};
int main() {
	setlocale(LC_ALL, "Russian");
	int k;
	double s[] = {1,2,3};
	Vector v1, v2;

	cout << "Введите три коориднаты первого вектора:\n";
	for (int i = 0; i < 3; i++) {
		
		cin >> v1;
	}
	cout << "Введите три коориднаты второго вектора :\n";
	for (int i = 0; i < 3; i++) {
	
		cin >> v2;
	}

	cout << "Vec1:\n" << v1 << "Vec2:\n" << v2;

	cout << "Сложение векторов:\n ";
	cout << v1 + v2;

	cout << "Вычитание векторов:\n ";
	cout << v1 - v2;

	cout << "Умножение векторов:\n ";
	cout << v1 * v2;

	cout << "Умножение вектора на число:";
	cout << "Введите число: ";
	cin >> k;
	cout << v1 * k;

	cout << "Cкалярное произведение векторов:";
	cout << v1.Scolar(v2) << endl;

	cout << "Угол: ";
	cout << v1.Angle(v2) << endl;

	cout << "Вектор 1 больше вектора 2: ";
	cout << (v1 > v2) << endl;

	cout << "Вектор 1 меньше вектора 2: ";
	cout << (v1 < v2) << endl;
	
	cout << "Равны: ";
	cout << (v1 == v2) << endl;

	cout << "Не равны: ";
	cout << (v1 != v2) << endl;
	return 0;
}