#include <bits/stdc++.h>
using namespace std;

int StrToInt(string n) {
    int number = 0;
    for (int i = 0; i < n.size(); i++)
        number = number * 10 + int(n[i] - '0');
    return number;
}

const int MAXN = 600005;

int NextBigger[MAXN], NextLower[MAXN], Value[MAXN];
int CountUsed = 0;

void InsertBST (int id, int key_value) {
    if (Value[id] == key_value)
        return ;
    else if (Value[id] == 0) {
        Value[id] = key_value;
        return ;
    } else if (key_value > Value[id]) {
        if (NextBigger[id] == 0)
            NextBigger[id] = ++CountUsed;
        InsertBST(NextBigger[id], key_value);
    } else if (key_value < Value[id]) {
        if (NextLower[id] == 0)
            NextLower[id] = ++CountUsed;
        InsertBST(NextLower[id], key_value);
    }

    return ;
}

void TravelBST_PreOrder (int id) {
    if (Value[id] == 0)
        return ;
    else {
        cout << Value[id] << " ";
        if (NextLower[id] != 0)
            TravelBST_PreOrder(NextLower[id]);
        if (NextBigger[id] != 0)
            TravelBST_PreOrder(NextBigger[id]);
    }
}

string s;

int main() {
    while(getline(cin, s)) {
        if (s == "#")
            break;
        string keyKStr = s.substr(7, s.size() - 7);
        int keyKInt = StrToInt(keyKStr);

        InsertBST(0, keyKInt);
    }

    TravelBST_PreOrder(0);
}
