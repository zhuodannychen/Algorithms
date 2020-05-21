#include<bits/stdc++.h>
using namespace std;

#define INF 1000000010
vector<pair<int, int>> adj[10005];
int dist[10005];

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({start, 0});
    dist[start] = 0;
    while (!pq.empty()) {
        int node = pq.top().first;
        pq.pop();
        for (auto e : adj[node]) {
            int v = e.first;
            int w = e.second;
            if (dist[node] + w < dist[v]) {
                dist[v] = dist[node] + w;
                pq.push({v, dist[v]});
            }
        }
    }
}

int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        --u; -- v;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    memset(dist, INF, sizeof(dist));
    int start = 1;
    int end = 3;
    dijkstra(start-1);
    cout << dist[end-1] << "\n";
    for (int i = 0; i < n; i++) 
        cout << dist[i] << " ";
}

/*
Test Case:
5 7
1 2 6
2 3 5
3 5 5
2 5 2
2 4 2
4 5 1
1 4 1

*/
