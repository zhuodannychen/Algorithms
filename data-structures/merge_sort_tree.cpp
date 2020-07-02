/**
 * Merge Sort Tree
 * Motivation: to find the number of elements smaller than val given a range from l to r.
 * Complexity: build O(NlogN), query O(logN)
 */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
#define all(v) v.begin(), v.end()

int n, arr[MAXN];
vector<int> tree[4*MAXN];

void build(int node, int left, int right) {
    if (left == right) {
        tree[node].push_back(arr[left]);
        return;
    }
    int mid = (left + right) / 2;
    build(2*node, left, mid);
    build(2*node+1, mid+1, right);

    merge(all(tree[2*node]), all(tree[2*node+1]), back_inserter(tree[node]));
}

int query(int node, int left, int right, int ql, int qr, int val) {
    if (ql > right || left > qr) return 0;
    if (ql <= left && right <= qr)
        return lower_bound(all(tree[node]), val) - tree[node].begin();
    int mid = (left + right) / 2;
    return query(2*node, left, mid, ql, qr, val) + query(2*node+1, mid+1, right, ql, qr, val);
}


int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    build(1, 0, n-1);
    cout << query(1, 0, n-1, 2, 4, 4) << "\n";
    cout << query(1, 0, n-1, 2, 4, 5) << "\n";
    cout << query(1, 0, n-1, 0, 4, 10) << "\n";
}
