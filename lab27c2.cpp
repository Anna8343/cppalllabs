#include <iostream>
#include <stdexcept>
using namespace std;

float internaldiv(float arg1, float arg2) {
    return arg1 / arg2;
}

float div(float arg1, float arg2) {
    if (arg2 == 0.0f) {
        throw invalid_argument("Your input is not valid. You can't divide by zero.");
    }
    
    return internaldiv(arg1, arg2);
}

int main(void) {
    float a, b;
    
    while (cin >> a >> b) {
        try {
            float r = div(a, b);
            cout << r << endl;
        } 
        catch (const invalid_argument& e) {
            cout << "Are you kidding me?\n" << e.what() << endl;
        }
    }
    
    return 0;
}