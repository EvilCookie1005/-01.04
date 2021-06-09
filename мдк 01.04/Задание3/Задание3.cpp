#include <iostream>
#include <ctime>
#include <iomanip>
#include <stdlib.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, R"(Rus)");
    int n, m;
    cout << "Введите колличество строк(n):";
    cin >> n;
    cout << "Введите колличество столбцов(m):";
    cin >> m;
    srand(time(0));
    int** a = new int* [n];
    for (int k = 0; k < n; k++)
        a[k] = new int[m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = (rand() % 10);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << a[i][j] << "   ";
        cout << endl;
    }

    for (int i = 0; i < n - 1; i++)
        for (int ii = i; ii < n; ii++)
            if (a[i][0] < a[ii][0])
                swap(a[i][0], a[ii][0]);
    cout << "Новая матрица a: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << " " << "\t";
        }
        cout << endl;
    }

}
