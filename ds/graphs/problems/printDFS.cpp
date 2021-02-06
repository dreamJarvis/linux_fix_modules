#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    unordered_map<int, vector<int>> adjList;
public:
    Graph(int V) : V(V) {}
    void dfsUtil(int , vector<bool> &);
    void dfs();
    void addEdge(int u, int v);
};

void Graph::addEdge(int u, int v){
    adjList[u].push_back(v);
}

void Graph::dfsUtil(int u, vector<bool> &visited){
    cout << u << " ";
    visited[u] = true;

    for(auto &v:adjList[u]){
        if(!visited[v])
            dfsUtil(v, visited);
    }
}

void Graph::dfs(){
    vector<bool> visited(V, false);

    for(int i = 0; i < V; i++){
        if(!visited[i]){
            dfsUtil(i, visited);
            cout << endl;
        }
    }
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

    g.dfs();

    return 0;
}
