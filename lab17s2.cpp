#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

bool isPrime(int num) {
for (int i=2;i<num;i++) {
    if ( num%i == 0 ) { return false; }
}
return true;
}

//ЗАПУСК ПРОГРАМИ
int main(void){

for(int i = 0; i<=21; i++) {
if(isPrime(i)) {
    cout << i <<" ";
}
}

}