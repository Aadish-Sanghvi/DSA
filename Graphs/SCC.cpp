// Srtongly Connected Components in a graph 
// Kosaraju's Algorithm

#include<iostream>
#include<vector>
#include<list>
#include<stack>
#include<unordered_map>
using namespace std;

void dfs(int node, unordered_map<int, bool> &vis, stack<int> &st, unordered_map<int, list<int> > &adj){
    vis[node] = true;;
    for(auto nbr : adj[node]){
        if(!vis[nbr]){
            dfs(nbr, vis, st, adj);
        }
    }
    st.push(node);
}

void revDfs(int node, unordered_map<int, bool> &vis, stack<int> &st,  unordered_map<int, list<int> > &transpose){
    vis[node] = true;

    for(auto nbr : transpose[node]){
        if(!vis[nbr]){
            dfs(nbr, vis, st, transpose);
        }
    }
}

int StrongltConnectedComponents(vector<vector<int> > &edges, int vertex){
    //adj
    unordered_map<int, list<int> > adj;
    for(int i = 0; i < vertex; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // Step - 1 --> Topological Sort 
    stack<int> st;
    unordered_map<int, bool> vis;
    for(int i = 0; i < vertex; i++){
        if(!vis[i]){
            dfs(i, vis, st, adj);
        }
    }

    // Step - 2 --> Create a transpose graph
    unordered_map<int, list<int> > transpose;
    for(int i = 0; i < vertex; i++){
        vis[i] = 0; // when calling dfs in above step it gets updated 
        for(auto nbr : adj[i]){
            transpose[nbr].push_back(i);
        }
    }

    // Step - 3 --> dfs call on the basis of above ordering
    int count = 0;
    while(!st.empty()){
        int top = st.top();
        st.pop();
        if(!vis[top]){
            count++; 
            revDfs(top, vis, st, transpose);
        }
    }
    return count;
}

int main(){
    int vertex = 5;
    vector<vector<int> > edges = {{0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}};

    cout << "The number of SCC present in graph is: " << StrongltConnectedComponents(edges, vertex) << endl;

    return 0;
}