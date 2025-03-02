#include<iostream>
#include<set>
#include<vector>
#include<list>
#include<unordered_map>
using namespace std;

void dfs(int node, int parent, int timer, vector<int> &disc, vector<int> &low, vector<vector<int> > &result, unordered_map<int, list<int> > &adj, unordered_map<int, bool> &vis){
    vis[node] = true;
    disc[node] = low[node] = timer;
    
    for(auto nbr:adj[node]){
        if(nbr == parent){
            continue;
        }
        if(!vis[nbr]){
            dfs(nbr, node, timer, disc, low, result, adj, vis);
            low[node] = min(low[node],low[nbr]);

            //check edge is bridge or not.
            if(low[nbr] > disc[node]){
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }
        else{
            //back edge case
            low[node] = min(low[node], disc[nbr]);
        }
    }
    return;
}

vector<vector<int> > findBridge(vector<pair<int, int> > &edges, int v, int e){
    // adj list
    unordered_map<int, list<int> > adj;
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(v, -1); 
    vector<int> low(v, -1); 
    int parent = -1;
    unordered_map<int, bool> vis;
    vector<vector<int> > result;

    //dfs
    for(int i = 0; i<v; i++){
        if(!vis[i]){
            dfs(i, parent, timer, disc, low, result, adj, vis);
        }
    }

    return result;
}

int main(){
    int vertex = 5;
    int edge = 6;

    vector<pair<int, int> > edges;
    edges.push_back(make_pair(0,1));
    edges.push_back(make_pair(0,3));
    edges.push_back(make_pair(1,2));
    edges.push_back(make_pair(1,4));
    edges.push_back(make_pair(2,5));
    edges.push_back(make_pair(3,4));
    
    findBridge(edges, vertex, edge);
    
    vector<vector<int> > result = findBridge(edges, vertex, edge);

    cout << "Bridges in the graph:" << endl;
    for (const auto& edge : result) {
        cout << edge[0] << " - " << edge[1] << endl;
    }
    
    return 0;
}