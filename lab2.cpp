#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x, a, b, c, y;

    cout << "Enter x, a, b, c: ";
    cin >> x >> a >> b >> c;

    if (b < 5) {
        y = pow(4 - x, a * b);
    } else {
        y = 0.25 + b * c;
    }

    cout << "y = " << y;

    return 0;
}
