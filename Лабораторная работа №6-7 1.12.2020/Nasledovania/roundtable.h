#ifndef ROUNDTABLE_H
#define ROUNDTABLE_H

#include "table.h"
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

class RoundTable : public Table {
public:
    RoundTable()
        : Table()
    {
        cout << "RoundTable::RoundTable()\n";
        m_radius = 1.0;
    }

    RoundTable(int t_size, char* t_color, double t_radius)
        : Table(t_size, t_color)
    {
        cout << "RoundTable::RoundTable( int, char*, double )\n";

        if (t_radius > 0.0) {
            m_radius = t_radius;
        }
        else {
            cerr
                << "Радиус круглого стола должен быть больше нуля, введено: "
                << t_radius
                << endl;

            exit(1);
        }
    }

    ~RoundTable()
    {
        cout << "RoundTable::~RoundTable()\n";
    }

    int calc_volume_rt()
    {
        return calc_volume() + 3.14 * pow(m_radius, 2);
    }

    virtual int calc_volume() override
    {
        return Table::calc_volume() + 3.14 * pow(m_radius, 2);
    }

    virtual void show() override
    {
        cout
            << "Круглый стол:"
            << "\n\tрадиус: " << m_radius
            << endl;
    }

private:
    double m_radius;
}; // class RoundTable : public Table

#endif