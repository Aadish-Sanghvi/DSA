#include<iostream>
#include<queue>
#include<unordered_map>
#include<list>
using namespace std;

void prepareAdjList(unordered_map<int, list<int> > &adjList, vector <pair<int, int> > &edges){
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

void dfs(unordered_map<int, list<int> > &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node){
    ans.push_back(node);
    visited[node] = true;

    // har connected nodes ke liye recursive call 
    for(auto i: adjList[node]){
        if(!visited[i]){
            dfs(adjList,visited, ans, i);
        }
    }
}

vector<int> DFS(int vertex, vector <pair<int, int> > &edges){
    unordered_map<int, list<int> > adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;

    prepareAdjList(adjList, edges);

    for(int i = 0; i < vertex; i++){
        if(!visited[i]){
            dfs(adjList, visited, ans, i);
        }
    }
    return ans;
}

int main() {
    vector<pair<int, int> > edges;
    edges.push_back(make_pair(0, 2));
    edges.push_back(make_pair(2, 1));
    edges.push_back(make_pair(2, 4));
    edges.push_back(make_pair(1, 3));
    edges.push_back(make_pair(4, 3));

    int vertex = 5; 

    vector<int> ans = DFS(vertex, edges);

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}