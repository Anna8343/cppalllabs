#include <iostream>
using namespace std;

void increment(int &var) {
    var = var + 1;
}

void increment(int &var, int n) {
    var = var + n;
}

int main(void) {
    int var = 0;
    for(int i = 0; i < 10; i++)
        if(i % 2)
            increment(var);
        else
            increment(var, i);
    cout << var << endl;
    return 0;
}