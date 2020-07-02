/**
 * Motivation: Find shortest path for multiple sources.
 * Complexity: O(V^3)
 */

#include<bits/stdc++.h>
using namespace std;

#define INF 1000000010

int n, dist[305][305];

void floyd_warshall() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    floyd_warshall();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}

/*
Test Case:
4
0 5 10000 10
10000 0 3 10000
10000 10000 0 1
10000 10000 10000 0

*/
