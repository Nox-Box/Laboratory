#include <iostream>
#include <cmath>

using namespace std;

class Complex         // класс "Комплексное число"
{
private:
    double re, im;      // действительная и мнимая части

public:
    // конструкторы 

    Complex()
    {
    };

    Complex(double r)
    {
        re = r;
        im = 0;
    }

    Complex(double r, double i)
    {
        re = r;
        im = i;
    }

    Complex(const Complex& c)   // конструктор копирования
    {
        re = c.re;
        im = c.im;
    }

    // деструктор
    ~Complex()
    {
    }

    // остальные функции
 
    // оператор сложения
    Complex operator + (const Complex& c)
    {
        return Complex(re + c.re, im + c.im);
    }

    // оператор умножения
    Complex operator * (const Complex& c)
    {
        return Complex(re * c.re - im * c.im, re * c.im + im * c.re);
    }

    // укажем дружественные операторы, которым мы разрешаем доступ
    // к личным (private) данным
    friend ostream& operator<< (ostream&, const Complex&);
    friend istream& operator>> (istream&, Complex&);

};

// перегрузка оператора <<
ostream& operator<< (ostream& out, const Complex& c)
{
    out << "(" << c.re << ", " << c.im << ")";
    return out;
}

// перегрузка оператора >>
istream& operator>> (istream& in, Complex& c)
{
    in >> c.re >> c.im;
    return in;
}

int
main()
{
    Complex a(8, 3);
    Complex b(6, -7);

    cout << "a = " << a << "; b =" << b << endl;

    Complex c = a + b;
    cout << a + b << endl;
    cout << a * b << endl;

    return 0;

}