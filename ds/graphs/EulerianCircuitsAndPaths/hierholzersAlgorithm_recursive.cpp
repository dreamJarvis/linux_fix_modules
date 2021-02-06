/*
    https://www.youtube.com/watch?v=8MpoO2zA2l4
    Eulerian Path/Circuit algorithm (Hierholzer's algorithm) | Graph Theory
*/
#include <iostream>
#include <iterator>
#include <vector>
#include <list>
using namespace std;

// tc : O(E)
class Graph{
    int V;                  // No. of vertices
    int edgeCount;
    int *in, *out;
    vector<int> path;
    list<int> *adj;         // adjacency lists
public:
    Graph(int V) : V(V), in(new int[V]), out(new int[V]), adj(new list<int>[V]) {}
    void addEdge(int u, int v);
    vector<int> findEulerianPath();
    void countInOutDegrees();
    bool graphHasEulerianPath();
    int findStartNode();
    void dfs(int at);
};

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph::countInOutDegrees(){
    edgeCount = 0;
    for(int i = 0; i < V; i++){
        in[i] = 0;
        out[i] = 0;
    }

    for(int from = 0; from < V; from++){
        for(auto to:adj[from]){
            out[from]++;
            in[to]++;
            edgeCount++;
        }
    }
}

bool Graph::graphHasEulerianPath(){
    if(edgeCount == 0)  return false;
    int startNodes = 0, endNodes = 0;
    for(int i = 0; i < V; i++){
        if(abs(out[i]-in[i]) > 1)   return false;
        else if(out[i]-in[i] == 1)  startNodes++;
        else if(in[i]-out[i] == 1)  endNodes++;
    }

    return ((endNodes == 0 && startNodes == 0) ||
            (startNodes == 1 && endNodes == 1)
    );
}

int Graph::findStartNode(){
    int start = 0;
    for(int i = 0; i < V; i++){
        if(out[i]-in[i] == 1)   return i;
        if(out[i] > 0)  start = i;
    }

    return start;
}

void Graph::dfs(int at){
    while(out[at]>0){
        auto next = adj[at].begin();
        advance(next, --out[at]);
        dfs(*next);
    }

    path.push_back(at);
}

vector<int> Graph::findEulerianPath(){
    countInOutDegrees();
    if(!graphHasEulerianPath()) return vector<int>({});
    dfs(findStartNode());

    return path;
}

// Driver function
int main(){
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);

    vector<int> path = g1.findEulerianPath();
    if(path.size() > 0 && path.front() == path.back()){
        cout << "Graph is Eulerian Circuit : ";
        for(auto i:path)
            cout << i << " ";
        cout << endl;
    }
    else if(path.size() > 0){
        cout << "Graph is Eulerian Path : ";
        for(auto i:path)
            cout << i << " ";
        cout << endl;
    }

    Graph g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);
    g2.addEdge(4, 0);

    path = g2.findEulerianPath();
    if(path.size() > 0 && path.front() == path.back()){
        cout << "Graph is Eulerian Circuit : ";
        for(auto i:path)
            cout << i << " ";
        cout << endl;
    }
    else if(path.size() > 0){
        cout << "Graph is Eulerian Path : ";
        for(auto i:path)
            cout << i << " ";
        cout << endl;
    }

    Graph g3(5);
    g3.addEdge(1, 0);
    g3.addEdge(0, 2);
    g3.addEdge(2, 1);
    g3.addEdge(0, 3);
    g3.addEdge(3, 4);
    g3.addEdge(1, 3);

    path = g3.findEulerianPath();
    if(path.size() > 0 && path.front() == path.back()){
        cout << "Graph is Eulerian Circuit : ";
        for(auto i:path)
            cout << i << " ";
        cout << endl;
    }
    else if(path.size() > 0){
        cout << "Graph is Eulerian Path : ";
        for(auto i:path)
            cout << i << " ";
        cout << endl;
    }

    // Let us create a graph with 3 vertices
    // connected in the form of cycle
    Graph g4(3);
    g4.addEdge(0, 1);
    g4.addEdge(1, 2);
    g4.addEdge(2, 0);

    path = g4.findEulerianPath();
    if(path.size() > 0 && path.front() == path.back()){
        cout << "Graph is Eulerian Circuit : ";
        for(auto i:path)
            cout << i << " ";
        cout << endl;
    }
    else if(path.size() > 0){
        cout << "Graph is Eulerian Path : ";
        for(auto i:path)
            cout << i << " ";
        cout << endl;
    }

    // Let us create a graph with all veritces
    // with zero degree
    Graph g5(3);
    path = g5.findEulerianPath();
    if(path.size() > 0 && path.front() == path.back()){
        cout << "Graph is Eulerian Circuit : ";
        for(auto i:path)
            cout << i << " ";
        cout << endl;
    }
    else if(path.size() > 0) {
        cout << "Graph is Eulerian Path : ";
        for(auto i:path)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}
