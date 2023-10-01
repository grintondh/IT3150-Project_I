#include <bits/stdc++.h>
using namespace std;

int n;
string s;

void backtrack(int i) {
    if (i == n) {
        cout << s << "\n";
    } else {
        s[i] = '0';
        backtrack(i + 1);
        if (i == 0 || s[i - 1] != '1') {
            s[i] = '1';
            backtrack(i + 1);
        }
    }
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
        s += ' ';

    backtrack(0);
}

