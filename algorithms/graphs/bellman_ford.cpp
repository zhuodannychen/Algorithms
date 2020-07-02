/**
 * Motivation: Find shortest path in a graph with negative weights.
 * Complexity: O(V*E)
 */

#include<bits/stdc++.h>
using namespace std;

#define INF 1000000010

vector<int> e[100005];
int n, m, dist[100005];

void bellman_ford(int start) {
    dist[start] = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < m; j++) {
            if (dist[e[j][0]] < INF)
                dist[e[j][1]] = min(dist[e[j][1]], dist[e[j][0]] + e[j][2]);
        }
    }
}

int main() {
    cin >> n >> m;
    memset(dist, INF, sizeof(dist));
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        --u; --v;
        e[i].push_back(u);
        e[i].push_back(v);
        e[i].push_back(w);
    }
    bellman_ford(0);
    for (int i = 0; i < n; i++) {
        cout << dist[i] << " ";
    }
}
