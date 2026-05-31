#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Fraction {
    public:
        Fraction(int numerator, int denominator);
        string toString();
        double toDouble();
        
        Fraction plus(Fraction that);
        Fraction minus(Fraction that);
        Fraction times(Fraction that);
        Fraction by(Fraction that);

    private:
        int numerator;
        int denominator;
        void reduce();
};

Fraction::Fraction(int numerator, int denominator) {
    this -> numerator = numerator;
    this -> denominator = denominator;
    this -> reduce();
}

void Fraction::reduce() {
    if (denominator == 0) return;
    
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }

    int abs_num = abs(numerator);
    int abs_den = abs(denominator);
    
    while (abs_den != 0) {
        int temp = abs_den;
        abs_den = abs_num % abs_den;
        abs_num = temp;
    }
    
    int gcd = abs_num;

    numerator /= gcd;
    denominator /= gcd;
}

Fraction Fraction::plus(Fraction that) {
    int num = (this -> numerator * that.denominator) + (that.numerator * this -> denominator);
    int den = this -> denominator * that.denominator;
    
    return Fraction(num, den);
}

Fraction Fraction::minus(Fraction that) {
    int num = (this -> numerator * that.denominator) - (that.numerator * this -> denominator);
    int den = this -> denominator * that.denominator;
    
    return Fraction(num, den);
}

Fraction Fraction::times(Fraction that) {
    int num = this -> numerator * that.numerator;
    int den = this -> denominator * that.denominator;
    
    return Fraction(num, den);
}

Fraction Fraction::by(Fraction that) {
    int num = this -> numerator * that.denominator;
    int den = this -> denominator * that.numerator;
    
    return Fraction(num, den);
}

double Fraction::toDouble() {
    return (double)numerator / denominator;
}

string Fraction::toString() {
    if (numerator == 0) return "0";
    
    bool negative = numerator < 0;
    int numer = abs(numerator), denom = abs(denominator);
    int whole = numer / denom, remain = numer % denom;

    string res = (negative ? "-" : "");
    
    if (whole != 0) {
        res += to_string(whole);
        if (remain != 0) res += " " + to_string(remain) + "/" + to_string(denom);
    }
    else {
        res += to_string(remain) + "/" + to_string(denom);
    }
    
    return res;
}

void parseInput(int &n, int &d) {
    string input;
    
    if (getline(cin, input) && !input.empty()) {
        size_t pos = input.find('/');
        n = stoi(input.substr(0, pos));
        d = stoi(input.substr(pos + 1));
    }
}

int main(void) {
    int n1, d1, n2, d2;
    
    parseInput(n1, d1);
    parseInput(n2, d2);

    Fraction f1(n1, d1);
    Fraction f2(n2, d2);

    cout << f1.toString() << " + " << f2.toString() << " = " << f1.plus(f2).toString() << endl;
    cout << f1.toString() << " - " << f2.toString() << " = " << f1.minus(f2).toString() << endl;
    cout << f1.toString() << " * " << f2.toString() << " = " << f1.times(f2).toString() << endl;
    cout << f1.toString() << " / " << f2.toString() << " = " << f1.by(f2).toString() << endl;

    return 0;
}