    #include <bits/stdc++.h>

    using namespace std;

    int a, b, c, ans = INT_MAX;
    int pre_step[905][905];

    void dfs(int jug_1, int jug_2, int step) {
        if (jug_1 == 0 && jug_2 == 0 && pre_step[0][0] == 0)
            return ;
        if (pre_step[jug_1][jug_2] != 0 && pre_step[jug_1][jug_2] <= step)
            return ;

        pre_step[jug_1][jug_2] = step;

        if (jug_1 == c || jug_2 == c) {
            ans = min(ans, step);
            return ;
        }

        dfs(a, jug_2, step + 1);
        dfs(jug_1, b, step + 1);
        dfs(0, jug_2, step + 1);
        dfs(jug_1, 0, step + 1);
        dfs(min(a, jug_1 + jug_2), max(0, jug_2 - (a - jug_1)), step + 1);
        dfs(max(0, jug_1 - (b - jug_2)), min(b, jug_1 + jug_2), step + 1);
    }

    int main() {
        cin >> a >> b >> c;
        pre_step[0][0] = 2;
        dfs(0, 0, 0);

        cout << ans << "\n";
    }
