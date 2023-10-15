#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key_value = 0;
    Node* next;
};

struct Linked_list {
    Node* HEAD = new Node();

    void Add_Before(int key_value, int compared_value) {
        Node *current = HEAD;

        while (current != NULL) {
            if (current->next != NULL && current->next->key_value == compared_value) {
                Node* nxt = new Node();

                nxt->key_value = key_value;
                nxt->next = current->next;
                current->next = nxt;
                break;
            } else {
                current = current->next;
            }
        }
    }

    void Add_After(int key_value, int compared_value) {
        Node* current = HEAD;
        while (current != NULL) {
            if (current->key_value == compared_value) {
                Node* nxt = new Node();

                nxt->key_value = key_value;
                nxt->next = current->next;
                current->next = nxt;
                break;
            } else
                current = current->next;
        }
    }

    int Add_Last(int key_value, int check_value = -1) {
        Node* current = HEAD;
        while (current != NULL) {
            if (current->key_value == key_value)
                return -1;
            if (current->next == NULL && check_value == -1) {
                Node* nxt = new Node();

                nxt->key_value = key_value;
                nxt->next = current->next;
                current->next = nxt;
                break;
            } else
                current = current->next;
        }

        return 0;
    }

    void Remove_Element(int compared_value) {
        Node* current = HEAD;
        while (current != NULL) {
            if (current->next != NULL && current->next->key_value == compared_value) {
                current->next = current->next->next;
                break;
            } else
                current = current->next;
        }
    }

    void Reverse_List() {
        if (HEAD->next == NULL)
            return ;
        Node *current = HEAD->next, *prev = NULL, *nxt;

        while (current != NULL) {
            nxt = current->next;
            current->next = prev;
            prev = current;
            current = nxt;
        }

        current = prev;
        HEAD->next = current;
    }

    void Print() {
        Node* current = HEAD;
        while(current->next != NULL) {
            current = current->next;
            cout << current->key_value << " ";
        }
    }
};

int n, a[1005];
string s;
Linked_list ls;

int StrToInt(string n) {
    int number = 0;
    for (int i = 0; i < n.size(); i++)
        number = number * 10 + int(n[i] - '0');
    return number;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ls.Add_After(a[i], a[i - 1]);
    }

    string s;
    cin.ignore();
    while(getline(cin, s)) {
        if (s == "#")
            break;
        else {
            if (s[3] == 'f') {
                string keyStr = s.substr(9, s.size() - 9);
                int keyInt = StrToInt(keyStr);

                if (ls.Add_Last(keyInt, 0) == 0)
                    ls.Add_After(keyInt, 0);
            } else if (s[3] == 'l') {
                string keyStr = s.substr(8, s.size() - 8);
                int keyInt = StrToInt(keyStr);
                ls.Add_Last(keyInt);
            } else if (s[3] == 'b') {
                int spacePos = 0;
                for (int i = 10; i < s.size(); i++)
                    if (s[i] == ' ') {
                        spacePos = i;
                        break;
                    }

                string keyStr1 = s.substr(10, spacePos - 10);
                string keyStr2 = s.substr(spacePos + 1, s.size() - spacePos - 1);

                int keyInt1 = StrToInt(keyStr1);
                int keyInt2 = StrToInt(keyStr2);

                ls.Add_Before(keyInt1, keyInt2);
            } else if (s[3] == 'a') {
                int spacePos = 0;
                for (int i = 9; i < s.size(); i++)
                    if (s[i] == ' ') {
                        spacePos = i;
                        break;
                    }

                string keyStr1 = s.substr(9, spacePos - 9);
                string keyStr2 = s.substr(spacePos + 1, s.size() - spacePos - 1);

                int keyInt1 = StrToInt(keyStr1);
                int keyInt2 = StrToInt(keyStr2);

                if (ls.Add_Last(keyInt1, 0) == 0)
                    ls.Add_After(keyInt1, keyInt2);
            } else if (s[3] == 'o') {
                string keyStr = s.substr(7, s.size() - 7);
                int keyInt = StrToInt(keyStr);
                ls.Remove_Element(keyInt);
            } else if (s[3] == 'e')
                ls.Reverse_List();
        }
    }

    ls.Print();
}
