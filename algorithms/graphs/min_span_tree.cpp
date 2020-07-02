/**
 * Motivation: Solve the minimum spanning tree problem.
 * Complexity: O(ElogV)
 */

#include <bits/stdc++.h>
using namespace std;

// credits: Competitive Programming 3
class UnionFind {
private:
    vector<int> p, rank, setSize;
    int numSets;
public:
    UnionFind(int N) {
    setSize.assign(N, 1);
    numSets = N; rank.assign(N, 0);
    p.assign(N, 0);
    for (int i = 0; i < N; i++)
        p[i] = i;
    }
    int findSet(int i) {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j) { 
        if (!isSameSet(i, j)) {
            numSets--; 
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) {
                p[y] = x;
                setSize[x] += setSize[y];
            }
            else {
                p[x] = y;
                setSize[y] += setSize[x];
                if (rank[x] == rank[y])
                    rank[y]++;
            }
        }
    }
    int numDisjointSets() { return numSets; }
    int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

bool custom_sort(const vector<int>& v1, const vector<int>& v2) {
    if (v1[2] < v2[2])
        return 1;
    else
        return 0;
}

int main() {
    int n_vertices, n_edges; cin >> n_vertices >> n_edges;
    vector<vector<int>> edgelist;
    for (int i = 0; i < n_edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        vector<int> temp = {u, v, w};
        edgelist.push_back(temp);
    }
    sort(edgelist.begin(), edgelist.end(), custom_sort);

    // begin mst
    int min_cost = 0;
    UnionFind UF(n_vertices);

    for (int i = 0; i < edgelist.size(); i++) {
        int first = edgelist[i][0];
        int second = edgelist[i][1];
        int weight = edgelist[i][2];
        if (!UF.isSameSet(first, second)) {
            min_cost += weight;
            UF.unionSet(first, second);
        }
    }
    cout << min_cost << "\n";
}
