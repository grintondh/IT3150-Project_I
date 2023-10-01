#include <bits/stdc++.h>
using namespace std;

const int MAXN = 22;

int n, a[MAXN];
bool used[MAXN];

void backtrack(int i) {
    if (i == n) {
        for (int j = 0; j < n; j++)
            cout << a[j] << " ";
        cout << "\n";
    } else {
        for (int j = 0; j < n; j++)
            if (used[j] == false) {
                used[j] = true;
                a[i] = j + 1;

                backtrack(i + 1);

                used[j] = false;
            }
    }
}

int main()
{
    cin >> n;
    backtrack(0);
}

