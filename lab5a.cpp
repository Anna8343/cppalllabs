#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x, y;

    for (int i = 1; i <= 5; i++) {
        cout << "Enter x: ";
        cin >> x;

        y = pow(sin(x), 5) + fabs(5 * x - 1.5);

        cout << "y = " << y << endl;
    }

    return 0;
}
