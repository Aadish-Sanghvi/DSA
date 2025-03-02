#include<iostream>
#include<vector>
using namespace std;

int bellmanFrod(int n, int m, int scr, int dest, vector<vector<int> > &edges){
    vector<int> dist(n+1, 1e9);
    dist[scr] = 0;

    for(int i = 1; i <= n; i++){
        //traverse on edge list
        for(int j = 0; j < m; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if(dist[u] != 1e9 && ((dist[u] + w) < dist[v])){
                dist[v] = dist[u] + w;
            }
        }
    }

    // check for -ve cycle 
    bool flag = 0;
    for(int i = 1; i <= n; i++){
        //traverse on edge list
        for(int j = 0; j < m; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if(dist[u] != 1e9 && ((dist[u] + w) < dist[v])){
                flag = 1;
            }
        }
    }
    
    if(flag == 0){
        return dist[dest];
    }
    
    return -1;
}

int main(){
    //int vertex = 5;
    //vector<vector<int> > edges = {{1, 2, 6}, {1, 3, 5}, {3, 2, -2}, {2, 4, -1}, {4, 3, -2}, {3, 5, 1}, {5, 4, 3}};
    
    int vertex = 3;
    vector<vector<int> > edges = {{1, 2, 2}, {1, 3, 2}, {2, 3, -1}};

    int src = 1;
    int dest = 3; 

    int shortestDistance = bellmanFrod(vertex, edges.size(), src, dest, edges);

    if(shortestDistance == -1){
        cout << "Negative cycle detected!" << endl;
    } else {
        cout << "The shortest distance from " << src << " to " << dest << " is: " << shortestDistance << endl;
    }

    return 0;
}