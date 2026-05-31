#include <iostream>
#include <string>
using namespace std;

class Fraction {
public:
    Fraction(int numerator, int denominator) {
        // Normalize sign: keep sign in numerator only
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
        this->numerator = numerator;
        this->denominator = denominator;
    }

    string toString() {
        int num = numerator;
        int den = denominator;

        // Determine sign
        bool negative = num < 0;
        if (negative) num = -num;

        int whole = num / den;
        int remainder = num % den;

        string result = "";

        if (negative && (whole > 0 || remainder > 0))
            result += "-";

        if (remainder == 0) {
            // Whole number
            result += to_string(whole);
        } else if (whole == 0) {
            // Pure fraction
            result += to_string(num) + "/" + to_string(den);
        } else {
            // Mixed number
            result += to_string(whole) + " " + to_string(remainder) + "/" + to_string(den);
        }

        return result;
    }

    double toDouble() {
        return (double)numerator / denominator;
    }

private:
    int numerator;
    int denominator;
};

int main(void) {
    int num, den;
    char slash;

    cin >> num >> slash >> den;

    Fraction fraction(num, den);

    double val = fraction.toDouble();

    // Format decimal: show ".0" if whole number
    cout << fraction.toString() << " is ";
    if (val == (int)val)
        cout << val << ".0";
    else
        cout << val;
    cout << " in decimal" << endl;

    return 0;
}