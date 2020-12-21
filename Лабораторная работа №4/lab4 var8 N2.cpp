#include <iostream>
using namespace std;
void rev_print(int n)
{
    if (n > 0)
    {
        cout << n - (n / 10) * 10;
        n /= 10;
        rev_print(n);
    }
    else
    {
        cout << '\n';
        return;
    }
}

int main()
{
    int k;
    cout << "Enter k: ";
    cin >> k;
    rev_print(k);
    return 0;
}