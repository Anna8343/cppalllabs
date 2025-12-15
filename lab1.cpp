#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a = 1;
    double b = 20.01;
    double y;
    double pi = 3.1415926535;

    y = cbrt( (0.719 / b) * ((b*b - a*a) / (a*a + b*b)) )
        + cos( log(b) * pi / 6 );

    cout << "y = " << y;

    return 0;
}
