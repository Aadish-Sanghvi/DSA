#include<iostream>
#include<unordered_map>
#include<stack>
#include<vector>
#include<list>
#include<queue>
#include <climits>
using namespace std;

// // Shortest path in undirected graph 
// vector<int> findShortestPath(vector<pair<int, int> > edges, int n, int s, int t){
//     //create adjacency list
//     unordered_map<int, list<int> > adj;
//     for(int i = 0; i < edges.size(); i++){
//         int u = edges[i].first;
//         int v = edges[i].second;

//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     // Do BFS
//     unordered_map<int, bool> visited;
//     unordered_map<int, int> parent;
//     queue<int> q;
//     q.push(s);
//     visited[s] = true;

//     while(!q.empty()){
//         int front = q.front();
//         q.pop();

//         for(auto i : adj[front]){
//             if(!visited[i]){
//                 visited[i] = true;
//                 parent[i] = front;
//                 q.push(i);
//             }
//         }
//     }
//     //prepare shortest path
//     vector<int> ans;
//     int currNode = t; //destination node
//     ans.push_back(currNode); // Push destination node into the path
//     while(currNode != s){
//         currNode = parent[currNode];
//         ans.push_back(currNode);
//     }
//     reverse(ans.begin(), ans.end()); // Reverse the path to start from source node
//     return ans;
// }

// int main(){
//     vector<pair<int, int> > edges;
//     edges.push_back(make_pair(1,2));
//     edges.push_back(make_pair(1,4));
//     edges.push_back(make_pair(1,3));
//     edges.push_back(make_pair(4,6));
//     edges.push_back(make_pair(2,5));
//     edges.push_back(make_pair(3,8));
//     edges.push_back(make_pair(5,8));
//     edges.push_back(make_pair(6,7));
//     edges.push_back(make_pair(7,8));

//     vector<int> shortest = findShortestPath(edges, 8, 1, 8);

//     for(int i = 0; i < shortest.size(); i++){
//         cout << shortest[i] << " ";
//     }
//     return 0;
// }



// //Shortest path in directed graph
class Graph{
    public:
    unordered_map<int, list<pair<int, int> > >adj;

    void addEdge(int u, int v, int weight){
        pair<int, int> p = make_pair(v, weight);
        adj[u].push_back(p);
    }

    void printAdj(){
        for(auto i : adj){
            cout << i.first <<" -> "; 
            for(auto j : i.second){
                cout << "(" << j.first << "," << j.second << ")" << ",";
            } cout << endl;
        }
    }

    void dfs(int node, unordered_map<int, bool> &vis, stack<int> &topo){
        vis[node] = true;

        for(auto neighbour : adj[node]){
            if(!vis[neighbour.first]){
                dfs(neighbour.first, vis, topo);
            }
        }
    }

    void getShortestPath(int src, vector<int> &dist, stack<int> &topo) {
        dist[src] = 0;

        while (!topo.empty()) {
            int top = topo.top();
            topo.pop();

            if (dist[top] != INT_MAX) {
                for (auto i : adj[top]) {
                    if (dist[top] + i.second < dist[i.first]) {
                        dist[i.first] = dist[top] + i.second;
                    }
                }
            }
        }
    }
};

int main(){
    Graph g;

    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);

    g.printAdj();

    unordered_map<int, bool> visited;
    stack<int> s; 
    int n = 6;
    for(int i = 0; i<n; i++){
        if(!visited[i]){
            g.dfs(i, visited, s);
        }
    }

    int src = 1;
    vector<int> dist(n);

    for(int i = 0; i < n; i++){
        dist[i] = INT_MAX;
    }

    g.getShortestPath(src, dist, s);

    cout << "The answer is: " << endl;
    for(int i = 0; i < dist.size(); i++){
        cout << dist[i] << " ";
    }cout << endl;

    return 0;
}