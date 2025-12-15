#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    float a = 2.3;
    float b = 2.3;
    float c = 2.123456;
    float d = 2.123456;
    float e = 2.123456;

    cout << a << endl;
    cout << fixed << setprecision(2) << b << endl;
    cout << setprecision(6) << c << endl;
    cout << setprecision(2) << d << endl;
    cout << (int)e << endl;

    return 0;
}
