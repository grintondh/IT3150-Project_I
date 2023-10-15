#include <bits/stdc++.h>
using namespace std;

int n, M;
int a[12], fact[12];

void solve (int pos, int last_value, int sum_left) {
    if (pos != n && sum_left == 0)
        return ;
    else if (pos == n - 1) {
        a[pos] = sum_left;
        solve (pos + 1, sum_left, 0);
    } else if (pos == n) {
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << "\n";
        return ;
    } else {
        for (int i = 1; i <= sum_left; i++) {
            a[pos] = i;
            solve(pos + 1, i, sum_left - i);
        }
    }
}

int main() {
    cin >> n >> M;

    solve(0, 0, M);
}
