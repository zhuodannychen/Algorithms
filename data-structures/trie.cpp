#include <bits/stdc++.h>
using namespace std;

const int MaxNodes = 200005;
const int alphabet = 26;
int sz, trie[MaxNodes][alphabet], cnt[MaxNodes];

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

bool startsWith (string str) {
    int u = 0;
    for (char c : str) {
        if (!trie[u][c-'A'])
            return false;
        u = trie[u][c-'A'];
    }
    return cnt[u] != -1;
}

int main() {
    memset(trie, 0, sizeof(trie[0])*sz);
	memset(cnt, 0, 4*sz);
    sz = 1;

    string strs[] = {"ALICE", "BOB", "CHARLIE", "DANNY", "ELSIE"};
    string output[] = {"NO", "YES"};

    for (int i = 0; i < 5; i++)
        insert(strs[i]);

    cout << output[search("BOB")] << "\n";
    cout << output[search("DANIEL")] << "\n";
    cout << output[search("DANN")] << "\n";
    cout << output[startsWith("CHAR")] << "\n";
}
