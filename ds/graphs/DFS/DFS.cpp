/*
    Depth First Search or DFS for a Graph
*/
#include <bits/stdc++.h>
using namespace std;


//** This only works for connected graphs
// class Graph{
//     int V;                  // no. of vertives
//     list<int> *adj;         // pointer to an array containing adjacency lists
//     void DFSUtil(int v, bool visited[]);    // recursive function used by DFS
//
// public:
//      // constructor
//     Graph(int V){
//         this->V = V;
//         adj = new list<int>[V];
//     }
//
//     void addEdge(int v, int w);         // function to add an edge
//     void DFS(int v);                    // DFS traversal of vertices reachable from v
// };
//
// void Graph::addEdge(int v, int w){
//     adj[v].push_back(w);                // add w to v's list
// }
//
// void Graph::DFSUtil(int v, bool visited[]){
//     visited[v] = true;          //  mark the current node as visited and print it
//     cout << v << " ";
//
//     // recur for all its connected vertices
//     for(auto i:adj[v])
//         if(!visited[i])
//             DFSUtil(i, visited);
// }
//
// void Graph::DFS(int v){
//     bool *visited = new bool[V];         // mark all the vertices as not visited
//     for(int i = 0; i < V; i++)
//         visited[i] = false;
//
//     // call the recursive helper function to print DFS traversal
//     DFSUtil(v, visited);
// }

// For connected and disconnected graphs
class Graph{
    int V;
    list<int> *adj;
    void DFSUtil(int v, bool visited[]);
public:
    Graph(int V) : V(V), adj(new list<int>[V]) {}       // constructor
    void addEdge(int v, int w);                         // to add edges to the graph
    void DFS();                                         // traverse the graph
};

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::DFSUtil(int v, bool visited[]){
    visited[v] = true;
    cout << v << " ";

    for(auto i:adj[v]){
        if(!visited[i]){
            DFSUtil(i, visited);
        }
    }
}

// tc : O(V+E)
void Graph::DFS(){
    bool visited[V] = {false};

    for(int i = 0; i < V; i++)
        if(!visited[i])
            DFSUtil(i, visited);
}

// Driver function
int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "DFS traversal : \n";
    g.DFS();

    return 0;
}
