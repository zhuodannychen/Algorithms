#include <bits/stdc++.h>
using namespace std;

const int MaxNodes = 200005;
const int alphabet = 26;
int trie[MaxNodes][alphabet], cnt[MaxNodes];
int sz = 1;

struct Trie {
    void insert(string str) {
        int u = 0;
        for (char c : str) {
            if (!trie[u][c-'A'])
                trie[u][c-'A'] = sz++;
            u = trie[u][c-'A'];
        }
        ++cnt[u];
    }

    bool search (string str) {
        int u = 0;
        for (char c : str) {
            if (!trie[u][c-'A'])
                return false;
            u = trie[u][c-'A'];
        }
        return cnt[u] > 0;
    }
};

int main() {
    Trie trie;
    string strs[] = {"ALICE", "BOB", "CHARLIE", "DANNY", "ELSIE"};
    string output[] = {"NO", "YES"};

    for (int i = 0; i < 5; i++)
        trie.insert(strs[i]);

    cout << output[trie.search("BOB")] << "\n";
    cout << output[trie.search("DANIEL")] << "\n";
    cout << output[trie.search("DANN")] << "\n";
}
