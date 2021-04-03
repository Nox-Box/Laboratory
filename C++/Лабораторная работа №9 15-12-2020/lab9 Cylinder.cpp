// lab9 Cylinder.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
constexpr double PI = 3.141592;
constexpr double HEIGHT = 18;

class IFigure {
public:
    virtual ~IFigure() {};

    virtual IFigure* copy() const = 0;

    virtual double calc_area() const = 0;
    virtual double calc_perimeter() const = 0;

    virtual void show() const = 0;
};




class Circle : virtual public IFigure {
public:
    Circle()
    {
        m_radius = new double;
        *m_radius = 0;
    }

    explicit Circle(const double t_radius)
    {
        m_radius = new double;
        *m_radius = t_radius;
    }

    Circle operator=(const Circle& t_circle)
    {
        if (this != &t_circle) {
            m_radius = new double;
            *m_radius = *(t_circle.m_radius);
        }

        return *this;
    }

    Circle(const Circle& t_circle)
    {
        m_radius = new double;
        *m_radius = *(t_circle.m_radius);
    }

    virtual ~Circle() override
    {
        delete m_radius;
    }

    virtual Circle* copy() const override
    {
        return new Circle(*this);
    }

    virtual double calc_area() const override
    {
        return PI * (*m_radius) * (*m_radius);
    }

    virtual double calc_perimeter() const override
    {
        return 2 * PI * (*m_radius);
    }

    virtual void show() const override
    {
        std::cout
            << "КРУГ"
            << "\nРадиус:\t\t" << (*m_radius)
            << "\nДиаметр:\t" << (*m_radius) * 2
            << "\nДлина:\t\t" << calc_perimeter()
            << "\nПлощадь:\t" << calc_area()
            << std::endl;
    }

private:
    double* m_radius;
};

class Parallelogram : virtual public IFigure {
public:
    Parallelogram()
    {
        m_base_length = new double;
        *m_base_length = 0;

        m_side_length = new double;
        *m_side_length = 0;

        m_height = new double;
        *m_height = 0;
    }

    explicit Parallelogram(const double t_side)
    {
        m_base_length = new double;
        *m_base_length = t_side;

        m_side_length = new double;
        *m_side_length = t_side;

        m_height = new double;
        *m_height = t_side;
    }

    explicit Parallelogram(
        const double t_base_length,
        const double t_side_length,
        const double t_height
    ) {
        m_base_length = new double;
        *m_base_length = t_base_length;

        m_side_length = new double;
        *m_side_length = t_side_length;

        m_height = new double;
        *m_height = t_height;
    }

    Parallelogram operator=(const Parallelogram& t_parallelogram)
    {
        if (this != &t_parallelogram) {
            m_base_length = new double;
            *m_base_length = *(t_parallelogram.m_base_length);

            m_side_length = new double;
            *m_side_length = *(t_parallelogram.m_side_length);

            m_height = new double;
            *m_height = *(t_parallelogram.m_height);
        }

        return *this;
    }

    Parallelogram(const Parallelogram& t_parallelogram)
    {
        m_base_length = new double;
        *m_base_length = *(t_parallelogram.m_base_length);

        m_side_length = new double;
        *m_side_length = *(t_parallelogram.m_side_length);

        m_height = new double;
        *m_height = *(t_parallelogram.m_height);
    }

    virtual ~Parallelogram() override
    {
        delete m_base_length;
        delete m_side_length;
        delete m_height;
    }

    virtual Parallelogram* copy() const override
    {
        return new Parallelogram(*this);
    }

    virtual double calc_area() const override
    {
        return (*m_base_length) * (*m_height);
    }

    virtual double calc_perimeter() const override
    {
        return 2 * ((*m_base_length) + (*m_side_length));
    }

    virtual void show() const override
    {
        std::cout
            << "ПАРАЛЛЕЛОГРАММ"
            << "\nДлина основания:\t" << (*m_base_length)
            << "\nВысота:\t\t\t" << (*m_height)
            << "\nПериметр:\t\t" << calc_perimeter()
            << "\nПлощадь:\t\t" << calc_area()
            << std::endl;
    }

private:
    double* m_base_length;
    double* m_side_length;
    double* m_height;
};

class Rectangle : virtual public IFigure {
public:
    Rectangle()
    {
        m_length = new double;
        *m_length = 0;

        m_width = new double;
        *m_width = 0;
    }

    explicit Rectangle(const double t_side)
    {
        m_length = new double;
        *m_length = t_side;

        m_width = new double;
        *m_width = t_side;
    }

    explicit Rectangle(const double t_side1, const double t_side2)
    {
        m_length = new double;
        m_width = new double;

        if (t_side1 > t_side2) {
            *m_length = t_side1;
            *m_width = t_side2;
        }
        else {
            *m_length = t_side2;
            *m_width = t_side1;
        }
    }

    Rectangle operator=(const Rectangle& t_rectangle)
    {
        if (this != &t_rectangle) {
            m_length = new double;
            *m_length = *(t_rectangle.m_length);

            m_width = new double;
            *m_width = *(t_rectangle.m_width);
        }

        return *this;
    }

    Rectangle(const Rectangle& t_rectangle)
    {
        m_length = new double;
        *m_length = *(t_rectangle.m_length);

        m_width = new double;
        *m_width = *(t_rectangle.m_width);
    }

    virtual ~Rectangle() override
    {
        delete m_length;
        delete m_width;
    }

    virtual Rectangle* copy() const override
    {
        return new Rectangle(*this);
    }

    virtual double calc_area() const override
    {
        return (*m_length) * (*m_width);
    }

    virtual double calc_perimeter() const override
    {
        return 2 * ((*m_length) + (*m_width));
    }

    virtual void show() const override
    {
        std::cout
            << "ПРЯМОУГОЛЬНИК"
            << "\nДлина:\t\t" << (*m_length)
            << "\nШирина:\t\t" << (*m_width)
            << "\nПериметр:\t" << calc_perimeter()
            << "\nПлощадь:\t" << calc_area()
            << std::endl;
    }

private:
    double* m_length;
    double* m_width;
};

class Cylinder {
public:
    Cylinder()
    {
        m_base = nullptr;

        m_height = new double;
        *m_height = 0;
    }

    Cylinder(IFigure* t_base, const double t_height)
    {
        m_base = t_base->copy();

        m_height = new double;
        *m_height = t_height;
    }

    Cylinder operator=(const Cylinder& t_cylinder)
    {
        if (this != &t_cylinder) {
            m_base = t_cylinder.m_base->copy();

            m_height = new double;
            *m_height = *(t_cylinder.m_height);
        }

        return *this;
    }

    Cylinder(const Cylinder& t_cylinder)
    {
        m_base = t_cylinder.m_base->copy();

        m_height = new double;
        *m_height = *(t_cylinder.m_height);
    }

    ~Cylinder()
    {
        delete m_base;
        delete m_height;
    }

    double calc_area()
    {
        return 2 * m_base->calc_area() + (*m_height) * m_base->calc_perimeter();
    }

    double calc_volume()
    {
        return m_base->calc_area() * (*m_height);
    }

    void show()
    {
        std::cout
            << "ЦИЛИНДР:"
            << "\nПлощадь:\t" << calc_area()
            << "\nОбъём:\t\t" << calc_volume()
            << std::endl;
    }

private:
    IFigure* m_base;
    double* m_height;
};

int main()
{
    setlocale(LC_ALL, "Russian");
    IFigure* chosen_figure;
    int a,b;

    cout
        << "Выберите фигуру:"
        << "\n1. Окружность"
        << "\n2. Прямоугольник"
        << "\n3. Параллелограмм"
        << "\nВыбор: ";

    int choice = 0;
    cin >> choice;

    if (choice == 1) {
        cout << '\n';
        cout << "Введите радиус:";
        cin >> a;
        chosen_figure = new Circle(a);
    }
    else if (choice == 2) {
        cout << '\n';
        cout << "Введите длину:";
        cin >> a;
        cout << "Введите ширину:";
        cin >> b;
        chosen_figure = new Rectangle(b, a);
    }
    else if (choice == 3) {
        cout << '\n';
        cout << "Введите длину основания:";
        cin >> a;
        cout << "Введите боковую сторону:";
        cin >> b;
       
        chosen_figure = new Parallelogram(a, b, HEIGHT);
    }
    else {
        return 0;
    }

    chosen_figure->show();

    cout << '\n';

    Cylinder* cylinder = new Cylinder(chosen_figure, HEIGHT);

    cylinder->show();

    delete chosen_figure;
    chosen_figure = nullptr;

    delete cylinder;
    cylinder = nullptr;

    return 0;
}