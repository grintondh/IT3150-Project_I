#include <bits/stdc++.h>
using namespace std;

void CheckHourFormat(string s) {
    // string length
    if (s.size() != 8) {
        cout << "INCORRECT";
        return ;
    }

    // check AA:BB:CC format
    for (int i = 0; i < s.size(); i++) {
        if (i == 2 || i == 5) {
            if (s[i] != ':') {
                cout << "INCORRECT";
                return ;
            }
        } else if (s[i] < '0' || '9' < s[i]) {
            cout << "INCORRECT";
            return ;
        }
    }
    // check HH-MM-SS format
    int sd = (int)(s[6] - '0') * 10 + (int)(s[7] - '0');
    int mn = (int)(s[3] - '0') * 10 + (int)(s[4] - '0');
    int hr = (int)(s[0] - '0') * 10 + (int)(s[1] - '0');

    if (sd < 0 || sd > 59 || mn < 0 || mn > 59 || hr < 0 || hr > 23) {
        cout << "INCORRECT";
        return ;
    }

    s[2] = ' ', s[5] = ' ';
    cout << hr * 3600 + mn * 60 + sd;
    return ;
}

string s;

int main() {
    getline(cin, s);
    CheckHourFormat(s);
}

