#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b){
    return a[2] < b[2]; // Change to '>' for descending order
}

void makeSet(vector<int> &parent, vector<int> &rank, int n){
    for(int i = 0; i < n; i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int> &parent, int node){
    if(parent[node] == node){
        return node;
    }
    return parent[node] = findParent(parent, parent[node]);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank){
    u = findParent(parent, u);
    v = findParent(parent, v);

    if(rank[u] < rank[v]){
        parent[u] = v; // chote tree ko bade tree me laga do
    }
    else if(rank[v] < rank[u]){
        parent[v] = u; // chote tree ko bade tree me laga do
    }
    else{
        parent[v] = u;
        rank[u]++;
    }
}

void minSpanningTree(vector<vector<int> > &edges, int n){
    sort(edges.begin(), edges.end(), cmp); // Custom comparator function to sort based on the third column
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);

    int minWeight = 0;

    for(int i = 0; i < edges.size(); i++){
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int wt = edges[i][2];

        if(u != v){
            unionSet(u, v, parent, rank);
            minWeight += wt;
        }
    }

    cout << "The minimum weight of the graph is = " << minWeight << endl;

    return;
}

int main(){
    int nodes = 6;
    
    vector<vector<int> > edges;

    edges.push_back({0, 1, 2});
    edges.push_back({0, 3, 6});
    edges.push_back({1, 2, 3});
    edges.push_back({1, 4, 5});
    edges.push_back({1, 3, 8});
    edges.push_back({2, 4, 7});
    
    minSpanningTree(edges, nodes);
    
    return 0;
}