#include<iostream>
#include<unordered_map>
#include<stack>
#include<vector>
#include<list>
using namespace std;

void topoSort(int node, unordered_map<int, bool> &visited, stack<int> &s, unordered_map<int, list<int> > &adj){
    visited[node] = true; // Changed initialization to true

    for(auto neighbour : adj[node]){
        if(!visited[neighbour]){
            topoSort(neighbour, visited, s, adj);
        }
    }
    s.push(node);
}

vector<int> topologicalSort(vector<pair<int, int> > &edges, int v, int e){
    //create adj list
    unordered_map<int, list<int> > adj(v); // Initialize the unordered_map with v

    for(int i = 0; i < e; i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    //call dfs topological sort util function for all comp.
    unordered_map<int, bool> visited;
    stack<int> s;

    for(int i = 0; i < v; i++){
        if(!visited[i]){
            topoSort(i, visited, s, adj);
        }
    }

    vector<int> ans;

    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

int main() {
    int v = 6; // Number of vertices
    int e = 5; // Number of edges

    vector<pair<int, int> > edges;
    edges.push_back(make_pair(0, 1));
    edges.push_back(make_pair(0, 2));
    edges.push_back(make_pair(1, 2));
    edges.push_back(make_pair(2, 3));
    edges.push_back(make_pair(3, 3));

    vector<int> sorted = topologicalSort(edges, v, e);

    // Output the sorted vertices
    cout << "Topological Sorting: ";
    for(int vertex : sorted) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}
