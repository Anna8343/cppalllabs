#include <iostream>
#include <stdexcept>
using namespace std;

int main(void) {
    int a = 0, b = 0, c = 0;
    cin >> a >> b;

    try {
        if (b == 0) {
            throw runtime_error("Your input is not valid, you can't divide by zero.");
        }
        
        c = a / b;
        cout << c << endl;
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

    return 0;
}