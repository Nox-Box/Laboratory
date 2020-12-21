// Nasledovania.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "table.h"
#include "comptable.h"
#include "roundtable.h"
 
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
 
const double get_table_cost( Table* table )
{
    return table->calc_volume() *15;

    // 15 - стоимость единицы объёма
}
 
int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Наследование\n\n";
    char brown[] = "коричневый";
    Table* table = new Table(10, brown );
    table->show();
    table->calc_volume();
 
    delete table;
    table = nullptr;
 
    cout << endl;
    char white[] = "белый";
    char DSP[] = "ДСП";
    CompTable* ctable = new CompTable( 10, white, 2, DSP );
    ctable->show();
    ctable->calc_volume_ct();
 
    delete ctable;
    ctable = nullptr;
 
    cout << endl;
    char black[] = "чёрный";
    RoundTable* rtable = new RoundTable( 12,black, 10 );
    rtable->show();
    rtable->calc_volume_rt();
 
    delete rtable;
    rtable = nullptr;
 
    cout << endl << "Полиморфизм\n\n";
 
    Table* random_table;
 
    cout
        << "Выберите стол:"
        << "\n1. Обычный стол"
        << "\n2. Компьютерный стол"
        << "\n3. Круглый стол"
        << "\nВыбор: ";
 
    int choice = 0;
    cin >> choice;
 
    if ( choice == 1 ) {
        cout << '\n';
        random_table = new Table( 10, brown );
    }
    else if (choice == 2) {
        cout << '\n';
        char wood[] = "дерево";
        random_table = new CompTable(10, white, 10, wood);
    }
    else if ( choice == 3 ) {
        cout << '\n';
        random_table = new RoundTable( 10, black, 15.5 );
    }
    else {
        return 0;
    }
 
    random_table->show();
 
    cout << "\nЦена стола: " << get_table_cost( random_table ) << endl;
 
    delete random_table;
    random_table = nullptr;
 
    return 0;
}
