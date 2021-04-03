#ifndef TABLE_H
#define TABLE_H

#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

class Table {
public:
    Table()
    {
        cout << "Table::Table()\n";

        m_size = new int;
        m_color = new char[10];
    }

    Table(int t_size, char* t_color)
    {
        cout << "Table::Table( int, char* )\n";

        if (t_size > 0) {
            m_size = new int;
            *m_size = t_size;
        }
        else {
            cerr
                << "� ����� ������ ������ ����, �������: "
                << t_size
                << ". �����."
                << endl;

            exit(1);
        }

        char* color = new char;
        m_color = new char[20];
        strcpy_s(m_color, strlen(t_color) + 1, t_color);
    }

    Table(int t_size)
    {
        cout << "Table::Table( int )\n";

        if (t_size > 0) {
            m_size = new int;
            *m_size = t_size;
        }
        else {
            std::cerr
                << "� ����� ������ ������ ����, �������: "
                << t_size
                << ". �����."
                << endl;

            exit(1);
        }

        m_color = new char[10];
    }

    virtual ~Table()
    {
        cout << "Table::~Table()\n";

        delete m_size;
        delete[] m_color;
    }

    virtual void show()
    {
        cout
            << "������� ����:"
            << "\n\t������: " << *m_size
            << "\n\t����: " << m_color
            << endl;
    }

    virtual int calc_volume()
    {
        return pow(*m_size, 3);
    }

private:
    int* m_size;
    char* m_color;
}; // class Table

#endif