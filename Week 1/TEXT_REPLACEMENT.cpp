#include <bits/stdc++.h>
using namespace std;

string s1, s2, t, ans;

int main()
{
    getline(cin, s1);
    getline(cin, s2);
    getline(cin, t);

    for (int i = 0; i < t.size(); i++) {
        if (i + s1.size() <= t.size() && t.substr(i, s1.size()) == s1) {
            ans += s2;
            i += s1.size() - 1;
        } else
            ans += t[i];
    }

    cout << ans;
}
