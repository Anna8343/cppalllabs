#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string values, templ;
    
    cout << "Enter your values: ";
    getline(cin, values);
    
    cout << "Set the template: ";
    getline(cin, templ);
    
    string names[100], vals[100];
    stringstream ss(values);
    string pair;
    
    int count = 0;
    while (getline(ss, pair, ',')) {
        int pos = pair.find('=');
        if (pos != string::npos) {
            names[count] = pair.substr(0, pos);
            vals[count] = pair.substr(pos + 1);
            count++;
        }
    }
    
    string result = "";
    for (int i = 0; i < templ.size(); i++) {
        if (templ[i] == '[') {
            int end = templ.find(']', i);
            
            if (end != string::npos) {
                string key = templ.substr(i + 1, end - i - 1);
                string value = "[" + key + "]";
                
                for (int j = 0; j < count; j++) {
                    if (names[j] == key) {
                        value = vals[j];
                        break;
                    }
                }
                
                result += value;
                i = end;
            }
            else {
                result += templ[i];
            }
        }
        else {
            result += templ[i];
        }
    }
    cout << result << endl;
}