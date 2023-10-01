#include <bits/stdc++.h>
using namespace std;

const int EDGE = 9;

int n, a[EDGE][EDGE];
int ans_cnt;
bool used[EDGE][EDGE][EDGE];

void backtrack(int i, int j) {
    if (i == EDGE) {
        ans_cnt++;
    } else {
        for (int x = 0; x < EDGE; x++)
            used[i][j][x] = false;

        for (int x = 0; x < j; x++)
            if (a[i][x] != 0)
                used[i][j][a[i][x] - 1] = true;

        for (int x = 0; x < i; x++)
            if (a[x][j] != 0)
                used[i][j][a[x][j] - 1] = true;

        for (int x = i / 3 * 3; x < (i / 3 + 1) * 3; x++)
            for (int y = j / 3 * 3; y < (j / 3 + 1) * 3; y++) {
                if (x == i && y == j)
                    continue;

                if (a[x][y] != 0)
                    used[i][j][a[x][y] - 1] = true;
            }

        if (a[i][j] != 0) {
            if (used[i][j][a[i][j] - 1] == true)
                return ;
            else {
                if (j == EDGE - 1)
                    backtrack(i + 1, 0);
                else
                    backtrack(i, j + 1);
            }
        } else {
            for (int x = 0; x < EDGE; x++)
                if (used[i][j][x] == false) {
                    used[i][j][x] = true;
                    a[i][j] = x + 1;

                    if (j == EDGE - 1)
                        backtrack(i + 1, 0);
                    else
                        backtrack(i, j + 1);

                    a[i][j] = 0;
                    used[i][j][x] = false;
                }
        }
    }
}

int main()
{
    for (int i = 0; i < EDGE; i++)
        for (int j = 0; j < EDGE; j++)
            cin >> a[i][j];

    backtrack(0, 0);

    cout << ans_cnt;
}
