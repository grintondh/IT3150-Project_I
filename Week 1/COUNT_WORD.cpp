#include <bits/stdc++.h>
using namespace std;

string s;
int word_count = 0;

bool isLetter (char c) {
    return ((c != ' ') && (c != '\t') && (c != '\n'));
}
int main()
{
    while(getline(cin, s)) {
        s = ' ' + s;
        for (int i = 1; i < s.size(); i++)
            if (isLetter(s[i - 1]) == false && isLetter(s[i]) == true)
                word_count++;
    }
    cout << word_count;
}
