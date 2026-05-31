#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string password;
    bool hasAL8 = false, hasUpper = false, hasLower = false, hasDigit = false, hasPunct = false;
    
    cout << "Enter your password: ";
    getline(cin, password);
    
    for (int i = 0; i < password.length(); i++) {
        if (password.length() >= 8) {
            hasAL8 = true;
        }
        if (isupper(password[i])) {
            hasUpper = true;
        }
        if (islower(password[i])) {
            hasLower = true;
        }
        if (isdigit(password[i])) {
            hasDigit = true;
        }
        if (ispunct(password[i])) {
            hasPunct = true;
        }
    }
        
    if (hasAL8 && hasUpper && hasLower && hasDigit && hasPunct) {
        cout << "The password is valid!";
    }
    if (!hasAL8) {
        cout << "The password must be at least 8 characters long." << endl;
    }
    if (!hasUpper) {
        cout << "The password must have at least one uppercase letter." << endl;
    }
    if (!hasLower) {
        cout << "The password must have at least one lowercase letter." << endl;
    }
    if (!hasDigit) {
        cout << "The password must have at least one digit." << endl;
    }
    if (!hasPunct) {
        cout << "The password must have at least one special character." << endl;
    }
}