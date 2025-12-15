#include <iostream>

using namespace std;

int main() {
    int x;
    double sum = 0;

    for (int i = 1; i <= 10; i++) {
        cout << "Enter number " << i << ": ";
        cin >> x;

        sum += x * x;
    }

    double average = sum / 10;

    cout << "Average of squares = " << average;

    return 0;
}
