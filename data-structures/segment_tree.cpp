/*
classic segment tree implementation
Single index update and min query
*/
#include <bits/stdc++.h>
using namespace std;


class SegmentTree {
private: vector<int> segtree, a;
    int n;

    void build(int node, int left, int right) {
        if (left == right)
            segtree[node] = left;
        else {
            build(2*node, left, (left+right)/2);
            build(2*node + 1, (left+right) / 2 + 1, right);
            int p1 = segtree[2*node];
            int p2 = segtree[2*node+1];
            segtree[node] = (a[p1] <= a[p2]) ? p1 : p2;
        }
    }

    int query(int node, int left, int right, int ql, int qr) {
        if (left >= ql && right <= qr)
            return segtree[node];
        else if (right < ql || left > qr)
            return -1;
        int p1 = query(2*node, left, (left+right)/2, ql, qr);
        int p2 = query(2*node + 1, (left+right)/2 + 1, right, ql, qr);
        if (p1 == -1) return p2;
        if (p2 == -1) return p1;
        return (a[p1] <= a[p2]) ? p1 : p2;
    }

    int update(int node, int left, int right, int pos, int val) {
        if (left == right) {
            a[pos] = val;
            return segtree[node] = left;
        }
        if (pos > right || pos < left)
            return segtree[node];
        else {
            int p1 = update(2*node, left, (left+right)/2, pos, val);
            int p2 = update(2*node + 1, (left+right)/2 + 1, right, pos, val);
            return segtree[node] = (a[p1] <= a[p2]) ? p1 : p2;
        }
    }

public:
    SegmentTree(const vector<int>& _a) {
        a = _a;
        n = a.size();
        segtree.assign(4*n, 0);
        build(1, 0, n-1);
    }

    int query(int ql, int qr) {
        return query(1, 0, n-1, ql, qr);
    }

    int update(int pos, int val) {
        return update(1, 0, n-1, pos, val);
    }
};

int main() {
    // assuming n is at least 6
    
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    SegmentTree segtree(a);

    cout << segtree.query(1, 3) << "\n";
    cout << segtree.query(3, 5) << "\n";
    cout << segtree.query(0, 0) << "\n";
    cout << segtree.query(0, 1) << "\n";
    cout << segtree.query(0, 5) << "\n";

    segtree.update(5, 1000);

    cout << segtree.query(1, 3) << "\n";
    cout << segtree.query(3, 5) << "\n";
    cout << segtree.query(0, 0) << "\n";
    cout << segtree.query(0, 1) << "\n";
    cout << segtree.query(0, 5) << "\n";
}

/*
6
5 3 8 10 6 3

*/
