#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));

    int n = 10;

    double* arr = new double[n];

    for (int i = 0; i < n; i++) {
        arr[i] = (rand() % 1000) / 1000.0 * 4.0 - 2.0;
    }

    cout << "Масив:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }

    int plus_count = 0;  
    int minus_count = 0; 

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            plus_count++;
        }
        else if (arr[i] < 0) {
            minus_count++;
        }
    }

    cout << "Додатних чисел: " << plus_count << endl;
    cout << "Від'ємних чисел: " << minus_count << endl;


    delete[] arr;

    return 0;
}