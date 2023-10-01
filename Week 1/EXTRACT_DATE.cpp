#include <bits/stdc++.h>
using namespace std;

void CheckDateFormat(string s) {
    // string length
    if (s.size() != 10) {
        cout << "INCORRECT";
        return ;
    }

    // check AAAA-BB-CC format
    for (int i = 0; i < s.size(); i++) {
        if (i == 4 || i == 7) {
            if (s[i] != '-') {
                cout << "INCORRECT";
                return ;
            }
        } else if (s[i] < '0' || '9' < s[i]) {
            cout << "INCORRECT";
            return ;
        }
    }
    // check YYYY-MM-DD format
    int date = (int)(s[8] - '0') * 10 + (int)(s[9] - '0');
    int month = (int)(s[5] - '0') * 10 + (int)(s[6] - '0');
    int year = (int)(s[0] - '0') * 1000 + (int)(s[1] - '0') * 100 + (int)(s[2] - '0') * 10 + (int)(s[3] - '0');;

    if (month <= 0 || month > 12) {
        cout << "INCORRECT";
        return ;
    }

    int max_date[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (date <= 0 || date > max_date[month - 1]) {
        cout << "INCORRECT";
        return ;
    }

    if (month == 2) {
        if ((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0)) {
            if (date != 29) {
                cout << "INCORRECT";
                return ;
            }
        } else if (date == 29) {
            cout << "INCORRECT";
            return ;
        }
    }

    s[4] = ' ', s[7] = ' ';
    cout << year << " " << month << " " << date;
    return ;
}

string s;

int main() {
    getline(cin, s);
    CheckDateFormat(s);
}
