#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;

    float x = 1.0f / a;
    float y = 1.0f / b;

    float epsilon = 0.000001;

    if (fabs(x - y) < epsilon) {
        cout << "Results are equal (by 0.000001 epsilon)";
    } else {
        cout << "Results are not equal (by 0.000001 epsilon)";
    }

    return 0;
}
