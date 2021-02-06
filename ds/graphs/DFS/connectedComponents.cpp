/*
    Connected Components in an undirected graph
    https://www.geeksforgeeks.org/connected-components-in-an-undirected-graph/
*/
#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *adj;
public:
    Graph(int V){
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int v, int w);
    void connectedComponents();
    void fccUtil(int v, bool visited[], list<int> &cc);
    unordered_map<int, list<int>> findConnectedComponents();
};

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::fccUtil(int v, bool visited[], list<int> &cc){
    visited[v] = true;
    cc.push_back(v);

    for(auto i:adj[v]){
        if(!visited[i])
            fccUtil(i, visited, cc);
    }
}

unordered_map<int, list<int>> Graph::findConnectedComponents(){
    bool visited[V] = {false};
    unordered_map<int, list<int>> cc;

    for(int i = 0; i < V; i++){
        if(!visited[i]){
            list<int> ccTemp;
            fccUtil(i, visited, ccTemp);
            cc[i] = ccTemp;
        }
    }

    return cc;
}

void Graph::connectedComponents(){
    for(auto i:findConnectedComponents()){
        cout << i.first << " --> ";
        for(auto j:i.second){
            cout << j << ", ";
        }
        cout << "\n";
    }
}

// Driver function
int main(){
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 0);
    g.addEdge(1, 2);
    g.addEdge(2, 1);
    g.addEdge(3, 4);
    g.addEdge(4, 3);


    // display the connected components
    g.connectedComponents();

    return 0;
}
