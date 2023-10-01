#include <bits/stdc++.h>
using namespace std;

int n, a;
int num_odd;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a % 2 == 1)
            num_odd++;
    }
    cout << num_odd << " " << n - num_odd;
}

