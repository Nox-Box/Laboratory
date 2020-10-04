#include <iostream>
#include <cmath>
#include <clocale>

using namespace std;

class Complex
{
private:
    double re;
    double im;
public:
    Complex(double r = 0, double i = 0) { re = r, im = i; }

    Complex operator+(const Complex&);
    Complex operator-(const Complex&);
    Complex operator*(const Complex&);
    Complex operator/(const Complex&);
    Complex operator==(const Complex&);
    Complex operator!=(const Complex&);
    float fabs(const Complex&);
    bool operator>(const Complex&);
    bool operator<(const Complex&);

    friend ostream& operator<<(ostream&, const Complex&);

    friend istream& operator>>(istream&, Complex&);
};

Complex Complex::operator+(const Complex& fp1)
{
    Complex t(*this);
    t.re += fp1.re;
    t.im += fp1.im;
    return t;
}

Complex Complex::operator-(const Complex& fp1)
{
    Complex t(*this);
    t.re -= fp1.re;
    t.im -= fp1.im;
    return t;
}

Complex Complex::operator*(const Complex& fp1)
{
    double i, j;
    i = re * fp1.re - im * fp1.im;
    j = re * fp1.im + fp1.re * im;
    Complex t(i, j);
    return t;
}

Complex Complex::operator/(const Complex& fp1)
{
    double k, i, j;
    k = fp1.re * fp1.re + fp1.im * fp1.im;
    i = (re * fp1.re + im * fp1.im) / k;
    j = (fp1.re * im - re * fp1.im) / k;
    Complex t(i, j);
    return t;
}

float Complex::fabs(const Complex& fp1)
{
    double i;
    i = sqrt(re * re + im * im);
    return i;
}

bool Complex::operator>(const Complex& fp1)
{
    Complex t(*this);
    if (fabs(fp1) > fabs(t))
        return 1;
    else return 0;
}

bool Complex::operator<(const Complex& fp1)
{
    Complex t(*this);
    if (fabs(fp1) < fabs(t))
        return 1;
    else return 0;
}
Complex Complex::operator==(const Complex& fp1)
{
    Complex t(*this);
    if (fabs(fp1) == fabs(t))
        return 1;
    else return 0;
    return 0;
}
Complex Complex::operator!=(const Complex& fp1)
{
    Complex t(*this);
    if (fabs(fp1) != fabs(t))
        return 1;
    else return 0;
}
ostream& operator<< (ostream& fo, const Complex& fp)
{
    if (fp.im == 0) fo << fp.re << " ";
    else if (fp.im < 0) fo << fp.re << "+i(" << fp.im << ")\n";
    else fo << fp.re << "+i" << fp.im << "\n";

    return fo;
}

istream& operator>>(istream& fi, Complex& fp)
{
    fi >> fp.re;
    fi >> fp.im;
    return fi;
}

int main()
{
    Complex x, y;
    setlocale(LC_ALL, "Rus");
    cout << "Введите действительную и мнимую части первого числа через пробел: ";
    cin >> x;
    cout << "Введите действительную и мнимую части второго числа через пробел: ";
    cin >> y;

    cout << "x = " << x;
    cout << "y = " << y << '\n';

    cout << "x + y = " << x + y;
    cout << "x - y = " << x - y;
    cout << "x * y = " << x * y;
    cout << "x / y = " << x / y;
    cout << "Модуль x и y " << x.fabs(x) << " " << y.fabs(y) << endl;
    if (x.fabs(x) != y.fabs(y))
        cout << x.fabs(x) << " != " << y.fabs(y) << endl;
    if (x.fabs(x) > y.fabs(y))
        cout << x.fabs(x) << " > " << y.fabs(y) << endl;
    if (x.fabs(x) < y.fabs(y))
        cout << x.fabs(x) << " < " << y.fabs(y) << endl;
    if (x.fabs(x) == y.fabs(y))
        cout << x.fabs(x) << " == " << y.fabs(y) << endl;
    system("pause");
    return 0;
}