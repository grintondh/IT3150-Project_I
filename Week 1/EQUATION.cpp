#include <bits/stdc++.h>
using namespace std;

double a, b, c;

int main() {
    cin >> a >> b >> c;

    double delta = b * b - 4 * a * c;

    if (delta < 0) {
        cout << "NO SOLUTION";
    } else {
        if (delta == 0)
            cout << setprecision(2) << fixed << -b / (2 * a);
        else {
            double x1 = (-b - sqrt(delta)) / (2 * a);
            double x2 = (-b + sqrt(delta)) / (2 * a);
            cout << setprecision(2) << fixed << x1 << " " << x2;
        }
    }
}
