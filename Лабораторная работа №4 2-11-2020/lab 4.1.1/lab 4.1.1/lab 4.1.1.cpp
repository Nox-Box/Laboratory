// lab 4.1.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;

//Функция проверки двух стеков на "палиндромность"
void check(stack<char>& firstStack, stack<char>& secondStack)
{
    //Пока оба стека не пусты
    while (!firstStack.empty() && !secondStack.empty())
    {
        //Если головы стеков не равны
        if (toupper(firstStack.top()) != toupper(secondStack.top()))
        {
            cout << "Строка не является палиндромом" << endl;
            return;
        }

        //Удаляем текущие первые элементы в стеках
        firstStack.pop();
        secondStack.pop();
    }

    cout << "Строка является палиндромом" << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    //Объявляем первый массив
    string str;

    //Читаем в него данные с консоли
    cin >> str;

    //Объявляем два стека
    stack<char> firstStack;
    stack<char> secondStack;

    //Заносим в первый - первую половину строки
    for (auto i = str.begin(); i != str.begin() + (str.end() - str.begin()) / 2; ++i)
        firstStack.push(*i);

    //Во второй - вторую, но с конца
    for (auto i = str.rbegin(); i != str.rbegin() + (str.rend() - str.rbegin()) / 2; ++i)
        secondStack.push(*i);

    //Проверяем оба стека (ОСТОРОЖНО! Эта функция портит стеки и после её вызова они окажутся пустыми)
    check(firstStack, secondStack);

}