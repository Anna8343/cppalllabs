#include <iostream>
#include <ctime>
using namespace std;

struct Date {
    int year;
    int month;
    int day;
};

Date today(void) {
    time_t t = time(NULL);
    tm tl = *localtime(&t);
    Date d;
    d.year  = tl.tm_year + 1900;
    d.month = tl.tm_mon + 1;
    d.day   = tl.tm_mday;
    return d;
}

bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int monthLength(int month, int year) {
    int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (month == 2 && isLeap(year)) return 29;
    return days[month - 1];
}

long long toDays(Date d) {
    long long total = 0;
    for (int y = 1; y < d.year; y++) {
        total += isLeap(y) ? 366 : 365;
    }
    for (int m = 1; m < d.month; m++) {
        total += monthLength(m, d.year);
    }
    total += d.day;
    return total;
}

int main(void) {

    Date birthday = {2003, 8, 15};

    Date now = today();

    long long diff = toDays(now) - toDays(birthday);

    cout << "Поточна дата: "
         << now.year << "-" << now.month << "-" << now.day << endl;
    cout << "Дата народження: "
         << birthday.year << "-" << birthday.month << "-" << birthday.day << endl;
    cout << "Кількість днів від дня народження: " << diff << endl;

    return 0;
}