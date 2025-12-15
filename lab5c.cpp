#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double a, b, h;
    double x, y;

    cout << "Enter a, b and h: ";
    cin >> a >> b >> h;

    x = a;

    cout << "-------------------" << endl;
    cout << "|   X   |    Y    |" << endl;
    cout << "-------------------" << endl;

    while (x <= b) {
        if (x < 0) {
            cout << "x is outside the domain of definition" << endl;
            break;
        }

        y = pow(x, 0.25) - 8 * sin(x);

        cout << "| " << setw(5) << x << " | " << setw(7) << y << " |" << endl;

        x += h;
    }

    cout << "-------------------" << endl;

    return 0;
}
