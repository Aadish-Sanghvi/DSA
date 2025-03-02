#include<iostream>
#include<queue>
#include<unordered_map>
#include<list>
using namespace std;

// // Through BFS traversal
// bool isCycleBFS(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int> > &adj){
//     unordered_map<int, int> parent;

//     parent[src] = -1;
//     visited[src] = 1;
//     queue<int> q;
//     q.push(src);

//     while(!q.empty()){
//         int front = q.front();
//         q.pop();

//         for(auto neighbour : adj[front]){
//             if(visited[neighbour] == true && neighbour != parent[front]){
//                 return true;
//             }
//             else if(!visited[neighbour]){
//                 q.push(neighbour);
//                 visited[neighbour] = 1;
//                 parent[neighbour] = front;
//             }
//         }
//     }
//     return false;
// }

// string cycleDetectionBFS(vector <pair<int, int> > &edges, int n){
//     //create adj list
//     unordered_map<int, list<int> > adj;
//     for(int i = 0; i < edges.size(); i++){
//         int u = edges[i].first;
//         int v = edges[i].second;

//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     //to handel disconnecteed components
//     unordered_map<int, bool> visited;
//     for(int i = 0; i < n; i++){
//         if(!visited[i]){
//             bool ans = isCycleBFS(i, visited, adj);
//             if(ans == 1){
//                 return "Cycle Detected";
//             }
//         }
//     }
//     return "No Cycle Detected";
// }

// int main(){
//     vector<pair<int, int> > edges;
//     edges.push_back(make_pair(1, 2));
//     edges.push_back(make_pair(2, 3));
//     edges.push_back(make_pair(1, 3));

//     int n = 3;
//     cout << cycleDetectionBFS(edges, n);

//     return 0;
// }



// // Through DFS traversal
bool isCycleDFS(int node, int parent, unordered_map<int, bool> &visited, unordered_map<int, list<int> > &adj){
    visited[node] = true;

    for(auto neighbour : adj[node]){
        if(!visited[neighbour]){
            bool cycleDetected = isCycleDFS(neighbour, node, visited, adj);
            if(cycleDetected)
            return true;
        }
        else if(neighbour != parent){
            //cycle present
            return true;
        }
    }
    return false;
}

string cycleDetectionDFS(vector <pair<int, int> > &edges, int n){
    //create adj list
    unordered_map<int, list<int> > adj;
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //to handel disconnecteed components
    unordered_map<int, bool> visited;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            bool ans = isCycleDFS(i, -1, visited, adj);
            if(ans == 1){
                return "Cycle Detected";
            }
        }
    }
    return "No Cycle Detected";
}

int main(){
    vector<pair<int, int> > edges;
    edges.push_back(make_pair(1, 2));
    edges.push_back(make_pair(2, 3));
    edges.push_back(make_pair(1, 3));

    int n = 3;
    cout << cycleDetectionDFS(edges, n);

    return 0;
}