#include <bits/stdc++.h>
using namespace std;

double cal_price(int* used_level, int* price_level, int num_level, int n) {
    int total_price = 0, now_level = 0;

    while(n > used_level[now_level]) {
        if (now_level + 1 == num_level || n < used_level[now_level + 1])
            total_price += (n - used_level[now_level]) * price_level[now_level];
        else
            total_price += (used_level[now_level + 1] - used_level[now_level]) * price_level[now_level];
        now_level++;

        if (now_level == num_level)
            break;
    }

    return double(total_price) * 1.1;
}

int old_used_level[6] = {0, 50, 100, 200, 300, 400};
int old_price_level[6] = {1728, 1786, 2074, 2612, 2919, 3015};

int new_used_level[5] = {0, 100, 200, 400, 700};
int new_price_level[5] = {1728, 2074, 2612, 3111, 3457};

int n;
double old_price, new_price;

int main() {
    cin >> n;

    old_price = cal_price(old_used_level, old_price_level, 6, n);
    new_price = cal_price(new_used_level, new_price_level, 5, n);

    cout << setprecision(2) << fixed << new_price - old_price;
}
