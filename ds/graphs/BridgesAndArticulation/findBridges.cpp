/*
    Bridges in a graph
    https://www.geeksforgeeks.org/bridge-in-a-graph/
*/
#include <iostream>
#include <vector>
#include <utility>
#include <list>
using namespace std;

#define NIL -1

class Graph {
    int V, id;                  // No. of vertices
    bool *visited;              // keeps the count of visited nodes
    int *low, *ids;             // keeps the ids(id of each node), low(lowest reachable id from each node), id(univeral id count)
    list<int> *adj;             // a dynamic array of adjacency lists
    void bridgeUtil(int at, int parent, vector<pair<int, int>> &bridges);
public:
    Graph(int V) : V(V), id(0), adj(new list<int>[V]) {}
    void addEdge(int v, int w);     // to add an edge
    vector<pair<int, int>> bridge();
};

// un-directed graph
void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}

/*
    perform Depth first search (DFS) to find bridges.
    at = current node, parent = previous node.
*/
void Graph::bridgeUtil(int at, int parent, vector<pair<int, int>> &bridges){
    visited[at] = true;
    low[at] =  ids[at] = ++id;          // assinging initial value to low's and id's

    for(auto to:adj[at]){
        if(to == parent)  continue;
        if(!visited[to]){
            bridgeUtil(to, at, bridges);

            // if the current low value is less the it's child then replace it
            low[at] = min(low[at], low[to]);

            if(ids[at] < low[to]){
                bridges.push_back({at, to});
            }
        }
        else {
            low[at] = min(low[at], ids[to]);
        }
    }
}

vector<pair<int, int>> Graph::bridge(){
    low = new int[V];
    ids = new int[V];
    visited = new bool[V];

    for(int i = 0; i < V; i++)  visited[i] = false;

    vector<pair<int, int>> bridges;
    for(int i = 0; i < V; i++){
        if(!visited[i])
            bridgeUtil(i, -1, bridges);
    }

    return bridges;
}

// Driver function
int main(){
    cout << "Bridges for this graph 1 : \n" ;
    Graph g1(7);
    g1.addEdge(1, 0);
    g1.addEdge(1, 2);
    g1.addEdge(2, 0);
    g1.addEdge(1, 3);
    g1.addEdge(1, 4);
    g1.addEdge(1, 6);
    g1.addEdge(3, 5);
    g1.addEdge(4, 5);

    for(auto i:g1.bridge())
        cout << i.first << " - " << i.second << endl;
    cout << endl;

    cout << "Bridges for graph 2 : \n";
    Graph g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(2, 0);
    g2.addEdge(1, 2);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);

    for(auto i:g2.bridge())
        cout << i.first << " - " << i.second << endl;
    cout << endl;

    cout << "Bridges for graph 3 : \n";
    Graph g3(5);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 3);
    g3.addEdge(3, 4);

    for(auto i:g3.bridge())
        cout << i.first << " - " << i.second << endl;
    cout << endl;

    return 0;
}
