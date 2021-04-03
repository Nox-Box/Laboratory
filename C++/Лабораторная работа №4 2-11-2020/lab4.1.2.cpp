// lab4.1.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool is_correct(const string&);

int main()
{
    setlocale(LC_ALL, "Russian");
    string str;
    cout << "Эти скобки сбалансированны ?\n";
    cin >> str;

    cout << (is_correct(str) ? "Да" : "Нет") << endl;
}

bool is_correct(const string& str)
{
    stack< char > stack;

    for (int i = 0; i < (int)str.length(); ++i)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            stack.push(str[i]);
        }
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            if
                (
                    stack.empty()
                    || ((str[i] == ')') ^ (stack.top() == '('))
                    || ((str[i] == '}') ^ (stack.top() == '{'))
                    || ((str[i] == ']') ^ (stack.top() == '['))
                    )
            {
                return false;
            }

            stack.pop();
        }
    }

    return stack.empty();
}
