#include <iostream>
#include <locale>
#include <cmath>
using namespace std;

typedef struct Complex {
    double Re;
    double Im;
} z;

z summation(z z1, z z2) {
    z summ;
    summ.Re = z1.Re + z2.Re;
    summ.Im = z1.Im + z2.Im;
    return summ;
}

z multiply(z z1, z z2) {
    z mult;
    mult.Re = (z1.Re * z2.Re) - (z1.Im * z2.Im);
    mult.Im = (z1.Im * z2.Re) + (z2.Im * z1.Re);
    return mult;
}


int main() {
    setlocale(LC_ALL, "Russian");
    z com1, com2;
    cout << "Введите a и b для первого комплексного числа" << endl;
    cin >> com1.Re;
    cin >> com1.Im;
    cout << "Первое комплексное число: " << com1.Re << " + (" << com1.Im << ")i" << endl;
    cout << "Введите a и b для первого комплексного числа" << endl;
    cin >> com2.Re;
    cin >> com2.Im;
    cout << "Второе комплексное число: " << com2.Re << " + (" << com2.Im << ")i" << endl;
    z summ = summation(com1, com2);
    z mult = multiply(com1, com2);
    cout << "Сумма этих чисел = " << summ.Re << " + (" << summ.Im << ")i" << endl;
    cout << "Произведение этих чисел = " << mult.Re << " + (" << mult.Im << ")i" << endl;
    return 0;
}