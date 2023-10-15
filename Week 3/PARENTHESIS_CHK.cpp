#include <bits/stdc++.h>

using namespace std;

string s;
char open[3] = {'(', '[', '{'};
char close[3] = {')', ']', '}'};
int par[3];

int main() {
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < 3; j++)
            if (s[i] == open[j])
                par[j]++;

        for (int j = 0; j < 3; j++)
            if (s[i] == close[j]) {
                par[j]--;
                if (par[j] < 0) {
                    cout << "0";
                    return 0;
                }
            }
    }

    for (int i = 0; i < 3; i++)
        if (par[i] != 0) {
            cout << "0";
            return 0;
        }

    cout << "1";
}
