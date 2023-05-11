/**
 * Motivation: find x and y for ax + by = gcd(a, b)
 * Complexity: O(logN)
 * Source: Emaxx
 */

#include<bits/stdc++.h>
using namespace std;

int extended_euclidean(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int d = extended_euclidean(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a/b);
    return d;
}


// solve ax = b mod n
int linear_congruence(int a, int b, int n) {
    int x, y;
    a %= n; b %= n;
    int d = extended_euclidean(a, b, x, y);
    if (b % d != 0)
        return -1;

    int x0 = (x * (b / d)) % n;
    if (x0 < 0)
        x0 += n;
    return x0;
 
    // Print all the answers
    //for (long long i = 0; i <= d - 1; i++)
        //cout << (x0 + i * (n / d)) % n << " ";
}

// example usage
int main() {
    int a = 9;
    int b = 21;
    int x, y;
    int d = extended_euclidean(a, b, x, y);
    cout << d << " " << x << " " << y << endl;

    int n = 30;
    int res = linear_congruence(a, b, n);
    cout << res << endl;
}


