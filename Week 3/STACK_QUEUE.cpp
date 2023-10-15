#include <bits/stdc++.h>

using namespace std;

int StrToInt(string s) {
    int num = 0, pow = 1;
    for (int i = s.size() - 1; i >= 0; i--) {
        num = int(s[i] - '0') * pow;
        pow *= 10;
    }

    return num;
}

queue <int> q;

main() {
    string s;
    while(getline(cin, s)) {
        if (s == "#")
            break;
        else if (s == "POP") {
            if (q.empty() == true) {
                cout << "NULL\n";
            } else {
                cout << q.front() << "\n";
                q.pop();
            }
        } else {
            string n = s.substr(5, s.size() - 5);
            q.push(StrToInt(n));
        }
    }
}
