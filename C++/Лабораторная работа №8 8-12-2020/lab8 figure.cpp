// lab8 figure.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.


#include <iostream>
using namespace std;
class Figure
{
public:
    virtual double CalcArea() const = 0;
    virtual void Show() const = 0;
    virtual ~Figure() {}
};
class Square : public Figure
{
    double a;
public:
    Square(double _a) : a(_a) {}
    ~Square() {}
    double CalcArea() const
    {
        return a * a;
    }
    void Show() const
    {
        cout << "Квадрат\n";
    }
};
class Circle : public Figure
{
    double r;
public:
    Circle(double _r) : r(_r) {}
    ~Circle() {}
    double CalcArea() const
    {
        return 3.14 * r * r;
    }
    void Show() const
    {
        cout << "Круг\n";
    }
};
class Rectangle : public Figure
{
    double a, b;
public:
    Rectangle(double _a, double _b) : a(_a), b(_b) {}
    ~Rectangle() {}
    double CalcArea() const
    {
        return a * b;
    }
    void Show() const
    {
        cout << "Прямоугольник\n";
    }
};
int main()
{
    setlocale(LC_ALL, "Russian");
    int a, b, c, d, h, s;
    Figure* figure[3];

    {
        cout << "-----Квадрат-----\n";
        cout << "Введите значение стороны квадрата, не равное нулю: ";
        cin >> a;
        cout << "Введите значение высоты, не равное нулю: ";
        cin >> h;
        figure[0] = new Square(a);
        figure[0]->Show();
        s = figure[0]->CalcArea();
        s = s * h;
        cout << "Площадь фигуры: " << figure[0]->CalcArea() << "\nОбъем обобщенного цилиндра: " << s;
        delete figure[0];
        cout << "\n";
        
        cout << "-----Круг-----\n";
        cout << "Введите значение радиуса, не равное нулю: ";
        cin >> b;
        cout << "Введите значение высоты, не равное нулю: ";
        cin >> h;
        figure[1] = new Circle(b);
        figure[1]->Show();
        s = figure[1]->CalcArea();
        s = s * h;
        cout << "Площадь фигуры: " << figure[1]->CalcArea() << "\nОбъем обобщенного цилиндра: " << s;
        delete figure[1];
        cout << "\n";
        
        cout << "-----Прямоугольник-----\n";
        cout << "Введите значение длины, не равное нулю: ";
        cin >> c;
        cout << "Введите значение ширины, не равное нулю: ";
        cin >> d;
        cout << "Введите значение высоты, не равное нулю: ";
        cin >> h;
        figure[2] = new Rectangle(c, d);
        figure[2]->Show();
        s = figure[2]->CalcArea();
        s = s * h;
        cout << "Площадь фигуры: " << figure[2]->CalcArea() << "\nОбъем обобщенного цилиндра: " << s;
        delete figure[2];
        cout << "\n";
       
    }
    return 0;
}