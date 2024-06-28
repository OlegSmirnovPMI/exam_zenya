#include <iostream> // - Дана матрица mxn, повернуть её на 90 градусов
#include <stdio.h>
#include <stdlib.h>

#define razdel "---------------------------------------\n"

using namespace std;

int main() {
    FILE *f = fopen("Matrix.txt", "r"); // - Читаем Матрицу из Matrix.txt, где в начале должны быть указаны *строки* и *столбцы*
    if (f == NULL) {
        cout << "Cannot find Matrix.txt";
        return 0;
    }
    int m, n;
    fscanf(f, "%d", &n);
    fscanf(f, "%d", &m);
    cout << "Stroki: " << n << " Stolbci: " << m << endl << razdel;
    int mas[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fscanf(f, "%d", &mas[i][j]);
            cout << mas[i][j] << ' ';
        }
        cout << endl;
    }

    cout << razdel;
    int povorot = 1; // 1 - по часовой. 0 - против часовой.

    int b[m][n];
    if (povorot == 1) { // - По Часовой
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                b[i][j] = mas[n-j-1][i];
                cout << b[i][j] << ' ';
            }
        cout << endl;
        }
    }
    else if (povorot == 0) { // - Против Часовой
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                b[i][j] = mas[j][m-i-1];
                cout << b[i][j] << ' ';
            }
        cout << endl;
        }
    }


}
