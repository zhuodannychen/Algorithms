/**
 * Motivation: Find the smallest circle that encloses a set of points
 * Complexity: O(N * constant_factor)
 */

#include <bits/stdc++.h>
using namespace std;

double x[1005], y[1005], X, Y, d, e;
double dist(double a, double b) {
	return a*a + b*b;
}

int main() {
    int n; cin >> n;
	for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
		X += x[i]; Y += y[i];
	}
	X /= n; Y /= n;
	double P = 0.1;
	for (int i = 0; i < 30000; i++) {
		int f = 0;
		d = dist(X - x[0], Y - y[0]);
		for (int j = 1; j < n; j++) {
			e = dist(X - x[j], Y - y[j]);
			if (d < e) { d = e; f = j; }
		}
		X += (x[f] - X)*P;
		Y += (y[f] - Y)*P;
		P *= 0.999;
	}
	printf("%.6f %.6f %.6f", X, Y, sqrt(d));
}
