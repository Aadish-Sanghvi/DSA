#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class graph{
    public:
    unordered_map<int, list<int> > adj;
    
    //direction = 0 -> undirected graph
    //direction = 1 -> directed graph

    void addEdge(int u, int v, bool direction){
        //create an edge from u to v
        adj[u].push_back(v);

        if(direction == 0){
            adj[v].push_back(u);
        }
    }

    // print graph 
    void printAdjList(){
        for(auto i:adj){
            cout << i.first << " -> ";
            for(auto j: i.second){
                cout << j << ", ";
            } 
            cout << endl;
        }
    }
};

int main(){
    int m,n;

    cout << "Enter the no. of Nodes: " << endl;
    cin >> n;
    
    cout << "Enter the no. of edges: " << endl;
    cin >> m;

    graph g;

    for(int i = 0; i < m; i++){
        cout << "Enter Nodes: ";
        int u, v;
        cin >> u >> v;
        //Undirected graph
        g.addEdge(u,v,0);

        cout << endl;
    }

    //print graph
    g.printAdjList();

    return 0;
}