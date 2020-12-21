#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;

const int NUM = 5;        // количество ферзей
const int BOARD_SIZE = 8; // размер поля
using Board = bool[BOARD_SIZE][BOARD_SIZE];

void PrintBoard(const Board brd)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
            cout << (brd[i][j] ? 'X' : ' ');
        cout << endl;
    }
}

bool BeatAll(const int arr[NUM])
{
    Board board = {};
    // проставляем на поле места, которые бьют наши ферзи
    for (int i = 0; i < NUM; i++)
    {
        const int xCoord = arr[i] / BOARD_SIZE, yCoord = arr[i] % BOARD_SIZE;
        // горизонталь
        for (int j = 0; j < BOARD_SIZE; j++)
            board[xCoord][j] = true;
        // вертикаль
        for (int j = 0; j < BOARD_SIZE; j++)
            board[j][yCoord] = true;
        // главная диагональ
        for (int j = xCoord, k = yCoord; j >= 0 && k >= 0; j--, k--)
            board[j][k] = true;
        for (int j = xCoord + 1, k = yCoord + 1; j < BOARD_SIZE && k < BOARD_SIZE; j++, k++)
            board[j][k] = true;
        // побочная диагональ
        for (int j = xCoord, k = yCoord; j >= 0 && k < BOARD_SIZE; j--, k++)
            board[j][k] = true;
        for (int j = xCoord + 1, k = yCoord - 1; j < BOARD_SIZE && k >= 0; j++, k--)
            board[j][k] = true;
    }

    // for test
    //PrintBoard(board);

    // проверяем доску
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            if (!board[i][j]) // поле осталось незаполненным
                return false;
    return true;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    // массив хранит значения от 0 до 63 (номер строки * BOARD_SIZE + номер столбца)
    int arr[NUM], counter = 0;
    // заполняем начальными значениями
    for (int i = 0; i < NUM; i++)
        arr[i] = i;
    // перебор всех комбинаций
    do
    {
        if (is_sorted(arr, arr + NUM) && BeatAll(arr))
        {
            for (int j = 0; j < NUM; j++)
            {
                cout << '(' << arr[j] / BOARD_SIZE << ", " << arr[j] % BOARD_SIZE << ") ";
                //cout << arr[j] << " ";
            }
            cout << endl;
            counter++;
        }
        arr[NUM - 1]++;
        for (int j = NUM - 1; j >= 1; j--)
            if (arr[j] == BOARD_SIZE * BOARD_SIZE)
            {
                arr[j - 1]++;
                arr[j] = arr[j - 1] - 1;
            }
    } while (arr[0] != BOARD_SIZE * BOARD_SIZE);

    cout << "\nРешений: " << counter << endl;
    ofstream fp("C:\\Users\\Stryker0\\Desktop\\Универ\\C++\\Semestr2\\lab2\\hard2 test\\result.txt");
    fp << counter;
    fp.close();
}
