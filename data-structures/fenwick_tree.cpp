/**
 * Motivation: Implement fenwick tree for point update.
 * Complexity: build O(NlogN), rsq O(logN), update O(logN)
 */

#include <bits/stdc++.h>
using namespace std;

class FenwickTree{
private:
    int n;
    vector<int> ft;
public:
    FenwickTree(int n) {
        this->n = n;
        ft.assign(n, 0);
    }
    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            update(i, a[i]);
    }

    int rsq(int r) {
        int sum = 0;
        for (; r >= 0; r = (r&(r+1)) - 1)
            sum += ft[r];
        return sum;
    }

    int rsq(int l, int r) {
        return rsq(r) - rsq(l-1);
    }

    void update(int idx, int val) {
        for (; idx < n; idx = idx | (idx + 1))
            ft[idx] += val;
    }
};

int main() {
    // assuming n is at least 4
    int n; cin >> n;
    vector<int> a(n);
    FenwickTree ft(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ft.update(i, a[i]);
    } 

    cout << ft.rsq(1, 1) << "\n";
    cout << ft.rsq(1, 2) << "\n";
    cout << ft.rsq(2, 3) << "\n";
    cout << ft.rsq(0, 3) << "\n";

    ft.update(2, 1000);

    cout << ft.rsq(1, 1) << "\n";
    cout << ft.rsq(1, 2) << "\n";
    cout << ft.rsq(2, 3) << "\n";
    cout << ft.rsq(0, 3) << "\n";
}
