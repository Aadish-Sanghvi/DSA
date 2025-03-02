#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <climits>
using namespace std;

vector<pair<pair<int, int>, int> > calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int> >& g) {
    // Create adjacency list
    unordered_map<int, list<pair<int, int> > > adj;

    for (int i = 0; i < m; i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> key(n + 1, INT_MAX);
    vector<bool> mst(n + 1, false);
    vector<int> parent(n + 1, -1);

    // Algorithm
    key[1] = 0;
    parent[1] = -1;
    for (int i = 1; i < n; i++) {
        int mini = INT_MAX;
        int u;

        for (int v = 1; v <= n; v++) {
            if (!mst[v] && key[v] < mini) {
                u = v;
                mini = key[v];
            }
        }

        mst[u] = true;

        for (auto it : adj[u]) {
            int v = it.first;
            int w = it.second;
            if (!mst[v] && w < key[v]) {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int, int>, int> > ans;
    for (int i = 2; i <= n; i++) {
        ans.push_back(make_pair(make_pair(parent[i], i), key[i]));
    }

    return ans;
}

int main() {
    int n = 5;
    int m = 6;

    vector<pair<pair<int, int>, int> > g;
    g.push_back(make_pair(make_pair(0, 1), 2));
    g.push_back(make_pair(make_pair(0, 3), 6));
    g.push_back(make_pair(make_pair(1, 2), 3));
    g.push_back(make_pair(make_pair(1, 4), 5));
    g.push_back(make_pair(make_pair(1, 3), 8));
    g.push_back(make_pair(make_pair(2, 4), 7));

    vector<pair<pair<int, int>, int> > ans = calculatePrimsMST(n, m, g);

    cout << "Edges of Minimum Spanning Tree:" << endl;
    for (auto edge : ans) {
        cout << edge.first.first << " - " << edge.first.second << " : " << edge.second << endl;
    }

    return 0;
}
