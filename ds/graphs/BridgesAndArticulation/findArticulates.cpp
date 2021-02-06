/*
    Articulation Points (or Cut Vertices) in a Graph
    https://www.geeksforgeeks.org/articulation-points-or-cut-vertices-in-a-graph/
*/
#include <iostream>
#include <utility>
#include <vector>
#include <list>
using namespace std;

class Graph {
    int V, id, rootNodeOutCommingEdgeCount;
    int *ids, *low;
    bool *visited, *isArticulationPoint;
    list<int> *adj;
    void articulateUtil(int root, int at, int parent);
public:
    Graph(int V) : V(V), id(0), rootNodeOutCommingEdgeCount(0), adj(new list<int>[V]) {}
    void addEdge(int u, int w);
    vector<int> articulation();
};

// un-directed graphs
void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph::articulateUtil(int root, int at, int parent){
    if(parent == root)  rootNodeOutCommingEdgeCount++;

    visited[at] = true;
    low[at] = ids[at] = id++;

    for(auto to:adj[at]){
        if(to == parent)    continue;
        if(!visited[to]){
            articulateUtil(root, to, at);

            low[at] = min(low[at], low[to]);

            /* for both the conditions :
                    i)  if there is an cycle
                    ii) if there is an edge
            */
            if(ids[at] <= low[to]){
                isArticulationPoint[at] = true;
            }
        }
        else{
            low[at] = min(low[at], ids[to]);
        }
    }
}

vector<int> Graph::articulation(){
    low = new int[V];
    ids = new int[V];
    visited = new bool[V];
    isArticulationPoint = new bool[V];

    for(int i = 0; i < V; i++){
        visited[i] = false;
        isArticulationPoint[i] = false;
    }

    for(int i = 0; i < V; i++){
        if(!visited[i]){
            rootNodeOutCommingEdgeCount = 0;
            articulateUtil(i, i, -1);
            isArticulationPoint[i] = (rootNodeOutCommingEdgeCount > 1);
        }
    }

    vector<int> articulationPoints;
    for(int i = 0; i < V; i++)
        if(isArticulationPoint[i])
            articulationPoints.push_back(i);

    return articulationPoints;
}

// Driver function
int main(){
    cout << "Bridges for graph 1 : \t" ;
    Graph g1(7);
    g1.addEdge(1, 0);
    g1.addEdge(1, 2);
    g1.addEdge(2, 0);
    g1.addEdge(1, 3);
    g1.addEdge(1, 4);
    g1.addEdge(1, 6);
    g1.addEdge(3, 5);
    g1.addEdge(4, 5);

    for(auto i:g1.articulation())
        cout << i<< ", ";
    cout << endl;

    cout << "Bridges for graph 2 : \t";
    Graph g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(2, 0);
    g2.addEdge(1, 2);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);

    for(auto i:g2.articulation())
        cout << i << ", ";
    cout << endl;

    cout << "Bridges for graph 3 : \t";
    Graph g3(5);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 3);
    g3.addEdge(3, 4);

    for(auto i:g3.articulation())
        cout << i << ", ";
    cout << endl;
    return 0;
}
