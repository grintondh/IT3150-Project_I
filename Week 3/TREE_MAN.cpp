#include <bits/stdc++.h>
using namespace std;

int StrToInt (string n) {
    int number = 0;
    for (int i = 0; i < n.size(); i++)
        number = number * 10 + int(n[i] - '0');
    return number;
}

bool number_Used[100005];
vector<int> adj[100005];
int Root;

void dfs(int u, string problem) {
    if (problem == "PreOrder")
        cout << u << " ";
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        dfs(v, problem);

        if (problem == "InOrder" && i == 0)
            cout << u << " ";
    }

    if (problem == "PostOrder" || (problem == "InOrder" && adj[u].size() == 0))
        cout << u << " ";
}

int main() {
    string s;
    while (getline(cin, s)) {
        if (s == "*")
            break;

        if (s[0] == 'M') {
            string numStr = s.substr(9, s.size() - 9);
            int numInt = StrToInt(numStr);

            Root = numInt;
            number_Used[Root] = true;
        } else if (s[0] == 'I' && s[2] == 's') {
            int space_pos = 0;
            for (int i = 7; i < s.size(); i++)
                if (s[i] == ' ') {
                    space_pos = i;
                    break;
                }

            string numStr1 = s.substr(7, space_pos - 7);
            string numStr2 = s.substr(space_pos + 1, s.size() - space_pos - 1);

            int u = StrToInt(numStr1);
            int v = StrToInt(numStr2);

            if (number_Used[u] == true || number_Used[v] == false)
                continue;
            else {
                adj[v].push_back(u);
                number_Used[u] = true;
            }
        } else if (s[0] == 'P' && s[1] == 'r') {
            dfs(Root, "PreOrder");
            cout << "\n";
        } else if (s[0] == 'I' && s[2] == 'O') {
            dfs(Root, "InOrder");
            cout << "\n";
        } else if (s[0] == 'P' && s[1] == 'o') {
            dfs(Root, "PostOrder");
            cout << "\n";
        }
    }
}
