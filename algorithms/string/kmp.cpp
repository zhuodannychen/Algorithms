/**
 * Motivation: find number of occurences of a pattern in a string
 * Complexity: O(N)
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> find_prefix(string pat) {
    int n = pat.size();
    vector<int> prefix(n);

    int k = 0;
    for (int i = 1; i < n; i++) {
        if (k > 0 && pat[i] != pat[k])
            k = prefix[k-1];
        if (pat[i] == pat[k])
            prefix[i] = ++k;
        else
            prefix[i] = k;
    }
    return prefix;
}

int KMP(string& str, string pat) {
    int n = str.size();
    int m = pat.size();
    vector<int> prefix = find_prefix(pat);

    int occurences = 0;
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (k > 0 && pat[k] != str[i])
            k = prefix[k-1];
        if (pat[k] == str[i])
            ++k;
        if (k == m) {
            ++occurences;
            k = prefix[k-1];
            // find exact index
            // cout << i - m + 1 << "\n";
        }
    }
    return occurences;
}

int main() {
    string s, p; cin >> s >> p;
    int ans = KMP(s, p);
    cout << ans << "\n";
}
