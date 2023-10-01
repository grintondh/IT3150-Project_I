#include <bits/stdc++.h>
using namespace std;

char LowerToUpper(char c) {
    if ('a' <= c && c <= 'z')
        return (char) (c + 'A' - 'a');
    else
        return c;
}

string s;

int main() {
    while(getline(cin, s)) {
        for (int i = 0; i < s.size(); i++)
            s[i] = LowerToUpper(s[i]);
        cout << s << "\n";
    }
}

