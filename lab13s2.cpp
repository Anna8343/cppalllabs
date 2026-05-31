#include <iostream> //13лр
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    const int N = 4;

    int mas[N][N];
    int *p;

    srand(time(0));

    p = &mas[0][0];
    for (int i = 0; i < N * N; i++) {
        *(p + i) = rand() % 21 - 10;
    }

    cout << "Array:" << endl;
    p = &mas[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << *(p + i * N + j) << "\t";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Main diagonal: ";
    p = &mas[0][0];
    for (int i = 0; i < N; i++) {
        cout << *(p + i * N + i) << " ";
    }
    cout << endl;

    cout << "Side diagonal: ";
    p = &mas[0][0];
    for (int i = 0; i < N; i++) {
        cout << *(p + i * N + (N - 1 - i)) << " ";
    }
    cout << endl;
    cout << endl;

    int parni = 0;
    int neparni = 0;

    p = &mas[0][0];
    for (int i = 0; i < N * N; i++) {
        if (*(p + i) % 2 == 0) {
            parni++;
        } else {
            neparni++;
        }
    }

    cout << "Even elements: " << parni << endl;
    cout << "Odd elements: " << neparni << endl;

    return 0;
}