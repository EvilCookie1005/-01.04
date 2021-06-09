#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    setlocale(0, "");
    srand(time(NULL));
    int rows, cols;
    rows = 0;
    cols = rows;
    double sum = 0, k = 0;
    cout << "Введите размер квадратной матрицы: \t"; cin >> rows;
    cols = rows;
    int** arr = new int* [rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 100 - 50;
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = i + 1; j < cols; j++) {
            if (arr[i][j] > 0) {
                sum += arr[i][j];
                k++;
            }
        }
    }
    sum /= k;
    cout << "Среднее арифметическое положительных элементов: " << sum << endl;
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}