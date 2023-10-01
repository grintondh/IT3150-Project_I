#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10001;
const int max_bound = 1001;
const int min_bound = -1001;

int n, a[MAXN];
string s;
int find_max = min_bound, find_min = max_bound, sum = INT_MAX;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cin >> s;
    cin.ignore();

    while(getline(cin, s)) {
        if (s == "***")
            break;
        else {
            if (s == "find-max") {
                if (find_max == min_bound) {
                    for (int i = 0; i < n; i++)
                        find_max = max(find_max, a[i]);
                }

                cout << find_max << "\n";
            } else if (s == "find-min") {
                if (find_min == max_bound) {
                    for (int i = 0; i < n; i++)
                        find_min = min(find_min, a[i]);
                }

                cout << find_min << "\n";
            } else if (s == "sum") {
                if (sum == INT_MAX) {
                    sum = 0;
                    for (int i = 0; i < n; i++)
                        sum += a[i];
                }

                cout << sum << "\n";
            } else {
                int id_pos = 0, pos[2] = {0, 0};
                for (int i = 17; i < s.size(); i++)
                    if (s[i] == ' ')
                        id_pos++;
                    else
                        pos[id_pos] = pos[id_pos] * 10 + (int) (s[i] - '0');

                int max_ele = -1001;
                for (int i = pos[0] - 1; i < pos[1]; i++)
                    max_ele = max(max_ele, a[i]);

                cout << max_ele << "\n";
            }
        }
    }
}
