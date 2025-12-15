#include <iostream>

using namespace std;

int main() {
    int N;
    cout << "Enter a three-digit number: ";
    cin >> N;

    int sum = 0;

    int a = N / 100;        // hundreds
    int b = (N / 10) % 10; // tens
    int c = N % 10;        // units

    if (a > 2 && a % 2 != 0)
        sum += a;

    if (b > 2 && b % 2 != 0)
        sum += b;

    if (c > 2 && c % 2 != 0)
        sum += c;

    cout << "Sum = " << sum;

    return 0;
}
