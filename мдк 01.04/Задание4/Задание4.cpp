#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
#define N 5
int main()
{
    setlocale(LC_ALL, "Rus");
    int a[N][N], i, j, t, y, t1;
    cout << "Исходная матрица:" << endl;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            a[i][j] = rand() % 10;
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    for (i = 0; i < N; i++)
        for (j = 0; j <= i; j++)
        {
            t = j;
            for (y = j + 1; y <= i; y++)
                if (a[y][i - y] < a[t][i - t])
                    t = y;
            t1 = a[j][i - j]; a[j][i - j] = a[t][i - t]; a[t][i - t] = t1;
        }
    for (i = 1; i < N; i++)
        for (j = 0; j + i < N; j++)
        {
            t = j;
            for (y = j + 1; y + i < N; y++)
                if (a[i + t][N - 1 - t] > a[i + y][N - 1 - y])
                    t = y;
            t1 = a[i + j][N - 1 - j]; a[i + j][N - 1 - j] = a[i + t][N - 1 - t]; a[i + t][N - 1 - t] = t1;
        }
    cout << "Полученная матрица:" << endl;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}
