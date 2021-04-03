#ifndef COMPTABLE_H
#define COMPTABLE_H

using namespace std;
#include "table.h"
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>

class CompTable : public Table {
public:
    CompTable()
        : Table()
    {
        std::cout << "CompTable::CompTable()\n";

        m_h = new int;
        m_material = new char[20];
    }

    CompTable(int t_size, char* t_color, int t_h, char* t_material)
        : Table(t_size, t_color)
    {
        std::cout << "CompTable::CompTable( int, char*, int, char* )\n";

        if (t_h > 0) {
            m_h = new int;
            *m_h = t_h;
        }
        else {
            cerr
                << "У комп. стола высота больше нуля, введена: "
                << t_h
                << ". Выход."
                << endl;

            std::exit(1);
        }
        m_material = new char[20];
        strcpy_s(m_material, strlen(t_material) + 1, t_material);
    }

    ~CompTable()
    {
        cout << "CompTable::~CompTable()\n";

        delete m_h;
        delete[] m_material;
    }

    virtual int calc_volume() override
    {
        return Table::calc_volume() + std::pow(*m_h, 3);
    }

    int calc_volume_ct()
    {
        return Table::calc_volume() + std::pow(*m_h, 3);
    }

    virtual void show() override
    {
        cout
            << "Компьютерный стол:"
            << "\n\tвысота: " << *m_h
            << "\n\tматериал: " << m_material
            << endl;
    }

private:
    int* m_h;
    char* m_material;
}; // class CompTable : public Table

#endif
#pragma once
