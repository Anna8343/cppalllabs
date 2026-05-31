#include <iostream>
using namespace std;

int Task = 1;

//ФУНКЦІЇ ДЛЯ ЗАВДАНЬ
bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Спосіб 1 - switch
int monthLength(int year, int month) {
    int YearToMonth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    switch(month) {
        case 1:  return YearToMonth[1];
        case 2:  if (isLeap(year)) { return 29; } else { return YearToMonth[2]; }
        case 3:  return YearToMonth[3];
        case 4:  return YearToMonth[4];
        case 5:  return YearToMonth[5];
        case 6:  return YearToMonth[6];
        case 7:  return YearToMonth[7];
        case 8:  return YearToMonth[8];
        case 9:  return YearToMonth[9];
        case 10: return YearToMonth[10];
        case 11: return YearToMonth[11];
        case 12: return YearToMonth[12];
    }
    return 0;
}

// Спосіб 2 - масив
int monthLengthVector(int year, int month) {
    int days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (month == 2 && isLeap(year)) return 29;
    return days[month];
}

//ЗАПУСК ПРОГРАМИ
int main(void) {
    //ЗАВДАННЯ 1
    if (Task == 1) {
        for(int yr = 1995; yr < 2017; yr++)
            cout << yr << " -> " << isLeap(yr) << "\n";
        cout << "\n";
        int extra;
        cin >> extra;
        cout << isLeap(extra);
    }
    //ЗАВДАННЯ 2
    if (Task == 2) {
        cout << "Switch:" << endl;
        for(int yr = 2000; yr < 2002; yr++) {
            for(int mo = 1; mo <= 12; mo++)
                cout << monthLength(yr, mo) << " ";
            cout << endl;
        }
        cout << "Масив:" << endl;
        for(int yr = 2000; yr < 2002; yr++) {
            for(int mo = 1; mo <= 12; mo++)
                cout << monthLengthVector(yr, mo) << " ";
            cout << endl;
        }
    }
}