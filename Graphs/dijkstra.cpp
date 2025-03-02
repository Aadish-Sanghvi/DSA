#include<iostream>
#include<unordered_map>
#include<stack>
#include<vector>
#include<list>
#include<set>
#include <climits>
using namespace std;

vector<int> dijkstra(vector<vector<int> > &vec, int vertices, int edges, int source){
    //create adj list
    unordered_map<int, list<pair<int, int> > > adj;
    for(int i = 0; i < edges; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    //creating dist array with infinite values
    vector<int> dist(vertices);
    for(int i = 0; i < vertices; i++){
        dist[i] = INT_MAX;
    }

    //creating set on basis of dist, node
    set<pair<int, int> > st;
    dist[source] = 0;
    st.insert(make_pair(0, source));

    while(!st.empty()){
        //fetch top record
        auto top = *(st.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        //clear top data
        st.erase(st.begin());

        for(auto neighbour : adj[topNode]){
            if(nodeDistance + neighbour.second < dist[neighbour.first]){
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));

                //if record found, erase it
                if(record != st.end())
                    st.erase(record);

                //distance update
                dist[neighbour.first] = nodeDistance + neighbour.second;
                //record push in set
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }
return dist;
}

int main() {
    int vertices = 5;
    int edges = 7;
    int source = 0;

    vector<vector<int> > vec;
    vec.push_back({0, 1, 5});
    vec.push_back({0, 2, 8});
    vec.push_back({1, 2, 9});
    vec.push_back({1, 3, 2});
    vec.push_back({2, 3, 6});

    vector<int> shortestDistances = dijkstra(vec, vertices, edges, source);

    cout << "Shortest distances from source " << source << ":\n";
    for (int i = 0; i < vertices; i++) {
        cout << "Vertex " << i << ": " << shortestDistances[i] << endl;
    }

    return 0;
}