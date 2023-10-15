#include <bits/stdc++.h>
using namespace std;

map <string, int> family_name;
vector<int> adj[10005];

int input_stage, name_cnt;
int count_child[10005], count_generation[10005];

void dfs(int u) {
    if (count_child[u] > 0)
        return ;

    count_child[u] = 1;
    count_generation[u] = 1;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];

        dfs(v);
        count_child[u] += count_child[v];
        count_generation[u] = max(count_generation[u], count_generation[v] + 1);
    }
}

void BuildGraph() {
    for (int i = 0; i <= name_cnt; i++)
        dfs(i);
}

int main() {
    string s;
    while(getline(cin, s)) {
        if (s == "***") {
            input_stage++;

            if (input_stage == 2)
                break;
            else
                BuildGraph();
        } else if (input_stage == 0) {
            int space_pos = 0;
            for (int i = 0; i < s.size(); i++)
                if (s[i] == ' ') {
                    space_pos = i;
                    break;
                }

            string child = s.substr(0, space_pos);
            string parent = s.substr(space_pos + 1, s.size() - space_pos - 1);

            if (family_name.find(child) == family_name.end())
                family_name[child] = ++name_cnt;
            if (family_name.find(parent) == family_name.end())
                family_name[parent] = ++name_cnt;

            adj[family_name[parent]].push_back(family_name[child]);
        } else if (input_stage == 1) {
            int space_pos = 0;
            for (int i = 0; i < s.size(); i++)
                if (s[i] == ' ') {
                    space_pos = i;
                    break;
                }

            string name = s.substr(space_pos + 1, s.size() - space_pos - 1);

            if (s[0] == 'd')
                cout << count_child[family_name[name]] - 1 << "\n";
            else
                cout << count_generation[family_name[name]] - 1 << "\n";
        }
    }
}
