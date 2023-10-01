#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;

int n, k, a[MAXN], sum, cnt;

int main()
{
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < k; i++)
        sum += a[i];

    if (sum % 2 == 0)
        cnt++;

    for (int i = k; i < n; i++) {
        sum += - a[i - k] + a[i];
        if (sum % 2 == 0)
            cnt++;
    }

    cout << cnt;
}
