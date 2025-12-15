#include <iostream>

using namespace std;

int main() {
    int bus;

    cout << "Enter bus number: ";
    cin >> bus;

    switch (bus) {
        case 1:
            cout << "Number of stops: 12";
            break;
        case 5:
            cout << "Number of stops: 18";
            break;
        case 7:
            cout << "Number of stops: 15";
            break;
        case 10:
            cout << "Number of stops: 20";
            break;
        default:
            cout << "Unknown bus number";
    }

    return 0;
}
