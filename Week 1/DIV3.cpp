#include <bits/stdc++.h>
using namespace std;

int n, s;

int main()
{
    cin >> s;
    n = s;
    while (n < 1000) {
        if (n >= 100)
            cout << n << " ";
        n += s;
    }
}
