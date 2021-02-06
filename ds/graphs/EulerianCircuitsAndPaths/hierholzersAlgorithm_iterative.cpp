/*

*/
#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

class Graph{
    int V;                  // No. of vertices
    int edgeCount;
    int *in, *out;
    vector<int> circuit;
    stack<int> currPath;
    list<int> *adj;    // adjacency lists
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

    return ((endNodes == 0 && startNodes == 0) || (startNodes == 1 && endNodes == 1));
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
    currPath.push(at);
    while(!currPath.empty()){
        if(out[at]){
            currPath.push(at);
            int nextV = adj[at].back();

            out[at]--;
            adj[at].pop_back();

            at = nextV;
        }
        else{
            circuit.push_back(at);
            at = currPath.top();
            currPath.pop();
        }
    }
}

vector<int> Graph::findEulerianPath(){
    countInOutDegrees();             // count's the incomming and outgoing edges per node
    if(!graphHasEulerianPath())      // checks if the edge count/node satisfies the condition
        return vector<int>({});

    // find's the eulerian circuit/path
    dfs(findStartNode());

    return circuit;
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
    if(path.front() == path.back()){
        cout << "Graph is Eulerian Circuit : ";
        for(auto i:path)
            cout << i << " ";
        cout << endl;
    }
    else {
        cout << "Graph is Eulerian Path : ";
        for(auto i:path)
            cout << i << " ";
        cout << endl;
    }

    // Graph g2(5);
    // g2.addEdge(1, 0);
    // g2.addEdge(0, 2);
    // g2.addEdge(2, 1);
    // g2.addEdge(0, 3);
    // g2.addEdge(3, 4);
    // g2.addEdge(4, 0);
    // test(g2);
    //
    // Graph g3(5);
    // g3.addEdge(1, 0);
    // g3.addEdge(0, 2);
    // g3.addEdge(2, 1);
    // g3.addEdge(0, 3);
    // g3.addEdge(3, 4);
    // g3.addEdge(1, 3);
    // test(g3);
    //
    // // Let us create a graph with 3 vertices
    // // connected in the form of cycle
    // Graph g4(3);
    // g4.addEdge(0, 1);
    // g4.addEdge(1, 2);
    // g4.addEdge(2, 0);
    // test(g4);
    //
    // // Let us create a graph with all veritces
    // // with zero degree
    // Graph g5(3);
    // test(g5);

    return 0;
}
