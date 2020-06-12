/**
 * Motivation: Convex Hull Monotone Chain Algorithm
 * Complexity: O(NlogN)
 * Note: From Geeksforgeeks
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct point { 
    ll x, y; 
    bool operator <(point p) const { 
        if (x == p.x) return y < p.y;
        return x < p.x; 
    } 
}; 

ll cross_product(point a, point b, point c) {
    return (b.x-a.x) * (c.y-a.y) - (b.y-a.y) * (c.x-a.x);
}

vector<point> ConvexHull(vector<point>& p) {
    int n = p.size();
    int cnt = 0;
    vector<point> hull(2*n);
    sort(p.begin(), p.end());

    for(int i = 0; i < n; i++) {
        while (cnt > 1 and cross_product(hull[cnt-2], hull[cnt-1], p[i]) <= 0)
            --cnt;
        hull[cnt++] = p[i];
    }

    for(int i = n-2, j = cnt+1; i >= 0; i--) {
        while (cnt >= j and cross_product(hull[cnt - 2], hull[cnt - 1], p[i]) <= 0)
            --cnt;
        hull[cnt++] = p[i];
    }

    hull.resize(cnt - 1);
    return hull;
}

int main() {
    int n; cin >> n;
    vector<point> points(n);
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        points.push_back({x, y});
    }
    
    vector<point> res = ConvexHull(points);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i].x << " " << res[i].y << "\n";
    }
}
/*
Sample Input
7
0 0
0 8
5 8
8 8
8 0
4 5
3 6

Sample Output:
0 0
8 0
8 8
0 8
*/
