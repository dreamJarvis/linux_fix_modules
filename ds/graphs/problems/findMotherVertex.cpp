#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Graph{
    int V;
    unordered_map<int, vector<int>> adjList;
public:
    Graph(int V) : V(V) {}
    void addEdge(int u, int v);
    void dfsUtil(int u, vector<bool> &visited);
    int findMotherVerted();
};

void Graph::addEdge(int u, int v){
    adjList[u].push_back(v);
}

void Graph::dfsUtil(int u, vector<bool> &visited){
    visited[u] = true;

    for(auto &i:adjList[u])
        if(!visited[i])
            dfsUtil(i, visited);
}

int Graph::findMotherVerted(){
    vector<bool> visited(V, false);

    int v = 0;
    for(int i = 0; i < V; i++){
        if(!visited[i]){
            dfsUtil(i, visited);
            v = i;
        }
    }

    visited = vector<bool> (V, false);
    dfsUtil(v, visited);
    for(int i = 0; i < V; i++){
        if(!visited[i])
            return -1;
    }

    return v;
}

// Driver function
int main(){
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(4, 1);
    g.addEdge(6, 4);
    g.addEdge(5, 6);
    g.addEdge(5, 2);
    g.addEdge(6, 0);

    cout << "A mother vertex is " << g.findMotherVerted();

    return 0;
}
