#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));

    int rows = 3;
    int cols = 3;

    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 20 + 1;
        }
    }

    cout << "Matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Main diagonal: ";
    for (int i = 0; i < rows; i++) {
        cout << matrix[i][i] << " ";
    }
    cout << endl;

    cout << "Side diagonal: ";
    for (int i = 0; i < rows; i++) {
        cout << matrix[i][cols - 1 - i] << " ";
    }
    cout << endl << endl;

    int even = 0;
    int odd = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] % 2 == 0) {
                even++;
            } else {
                odd++;
            }
        }
    }

    cout << "Even elements: " << even << endl;
    cout << "Odd elements: " << odd << endl;

    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}