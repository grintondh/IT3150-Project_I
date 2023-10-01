#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
const long long MOD = 1000000007;

int n, k;
long long gt[MAXN];

// Calculate a^b
long long power(long long a, int b) {
    if (b == 0)
        return 1;
    else {
        long long X = power(a, b / 2);
        if (b % 2 == 0)
            return X * X % MOD;
        else
            return (X * X % MOD) * a % MOD;
    }
}

int main()
{
    cin >> k >> n;

    // nCk = n!/k!(n-k)!
    gt[0] = 1;
    for (int i = 1; i <= n; i++)
        gt[i] = (gt[i - 1] * i) % MOD;

    long long ans = (gt[n] * power(gt[k], MOD - 2) % MOD) * power(gt[n - k], MOD - 2) % MOD;
    cout << ans;
}

