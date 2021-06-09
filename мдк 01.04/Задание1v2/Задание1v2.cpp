#include <iostream>
#include <ctime>
//#include <iomanip>
#include <cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    int n, m;
    cout << "Введите колличество строк(n):";
    cin >> n;
    cout << "Введите колличество столбцов(m):";
    cin >> m;
    cin.get(); 

    srand((unsigned)time(0));
    int** a = new int* [n];
    int* minval = new int[n];
    for (int k = 0; k < n; k++)
        a[k] = new int[m];
   
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = rand() % 100;
   
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << a[i][j] << "   ";
        cout << endl;
    }
  
    for (int i = 0; i != n; ++i)
    {
        minval[i] = a[i][0];
        for (int j = 1; j != m; ++j)
            if (minval[i] > a[i][j])
                minval[i] = a[i][j];
        cout << "Строка №" << i + 1 << ": минимальный элемент = "
            << minval[i] << endl;
    }

    for (int i = 0; i != n; ++i)
    {
        for (int j = 0; j != m; ++j)
            a[i][j] *= minval[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << a[i][j] << "   ";
        cout << endl;
    }
 
    for (int k = 0; k < n; k++)
        delete[] a[k];
    delete[] a;
    delete[] minval;

    cin.get();

    return 0;
}
