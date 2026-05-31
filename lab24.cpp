#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Fraction {
public:
    Fraction(int numerator, int denominator);
    string toString();
    double toDouble();
    bool isGreaterThan(Fraction that);
    bool isLessThan(Fraction that);
    bool isEqual(Fraction that);

private:
    int numerator;
    int denominator;
    void reduce();
};

int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

Fraction::Fraction(int numerator, int denominator) {
    // Знак завжди у чисельнику
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
    this->numerator = numerator;
    this->denominator = denominator;
    reduce();
}

void Fraction::reduce() {
    if (numerator == 0) {
        denominator = 1;
        return;
    }
    int g = gcd(abs(numerator), abs(denominator));
    numerator /= g;
    denominator /= g;
}

string Fraction::toString() {

    bool negative = (numerator < 0);
    int absNum = abs(numerator);
    int absDen = denominator;

    string result = "";

    if (negative) result += "-";

    if (absNum >= absDen) {
        int whole = absNum / absDen;
        int rem   = absNum % absDen;
        result += to_string(whole);
        if (rem != 0) {
            result += " " + to_string(rem) + "/" + to_string(absDen);
        }
    } else {
        result += to_string(absNum) + "/" + to_string(absDen);
    }

    return result;
}

double Fraction::toDouble() {
    return (double)numerator / denominator;
}

bool Fraction::isGreaterThan(Fraction that) {
    return this->toDouble() > that.toDouble();
}

bool Fraction::isLessThan(Fraction that) {
    return this->toDouble() < that.toDouble();
}

bool Fraction::isEqual(Fraction that) {
    return this->toDouble() == that.toDouble();
}

int main() {
    int n1, d1, n2, d2;
    char slash;

    cin >> n1 >> slash >> d1;

    cin >> n2 >> slash >> d2;

    Fraction f1(n1, d1);
    Fraction f2(n2, d2);

    string sign;
    if (f1.isGreaterThan(f2))      sign = " > ";
    else if (f1.isLessThan(f2))    sign = " < ";
    else                            sign = " = ";

    cout << f1.toString() << sign << f2.toString() << endl;

    return 0;
}