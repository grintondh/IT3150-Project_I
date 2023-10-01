#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10001;

int n, a, sum;

int main()
{
    cin >> n;
    while(n--) {
        cin >> a;
        sum += a;
    }
    cout << sum;
}
