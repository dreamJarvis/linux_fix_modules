/*
    Prim’s MST for Adjacency List Representation
    https://www.geeksforgeeks.org/prims-mst-for-adjacency-list-representation-greedy-algo-6/

    Time complexity : O(E*log(V))
*/
#include <iostream>
#include <utility>
#include <climits>
#include <vector>
#include <queue>
#include <list>

using namespace std;

#define INF INT_MAX
typedef pair<int, int> iPair;

class Graph{
    int V;
    int *parent, *key;
    list<pair<int,int>> *adj;       // adjacency list with weights
public:
    Graph(int V) :  V(V), parent(new int[V]), key(new int[V]),
                    adj(new list<pair<int, int>>[V]) {}

    void addEdge(int u, int v, int w);
    void primMST();     // apply's prims algo to find MST
    void printArr();
};

// un-directed graph
void Graph::addEdge(int u, int v, int w){
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

void Graph::primMST(){
    /*
        this is the min-heap where we store {key:value} pairs,
        key -> weight, value -> node
        now at the top, we get the node with the least distance

        But we have to make sure that we do not include nodes already in the MST,
        or we will end up revisiting them again, and maybe form a cycle,
        but we don't want to do this, as MST is an acyclic graph
    */
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    bool inMST[V] = {false};

    /* initialize min heap with all vertices.
    key value of al vertices (except 0th vertex) is initially infinite
    */
    for(int v = 1; v < V; v++){
        parent[v] = -1;
        key[v] = INF;
    }

    // make key value of 0th vertex as 0, so that it is extracted first
    int src = 0;
    key[0] = 0;
    pq.push({0, src});    // pushing first node in the min-heap

    /*in the following loop, min heap contains all nodes not et added to MSt */
    while(!pq.empty()){
        int u = pq.top().second;
        inMST[u] = true;
        pq.pop();

        // cout << u << endl;

        /*  go to all the neighbours of u, and update the distance stored in key,
            if an alternate shorter distance from u -> v exist
        */
        for(auto to:adj[u]){
            int v = to.first;
            int weight = to.second;

            if(!inMST[v] && weight < key[v]){
                key[v] = weight;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    printArr();
}

// print the MST
void Graph::printArr(){
    int totalCost = 0;
    cout << "Edge\t Weight\n";
    for(int v = 1; v < V; v++){
        cout << parent[v] << " - " << v << "\t  " << key[v] << endl;
        totalCost += key[v];
    }
    cout << "\nTotal Cost : " << totalCost << endl;
}

int main(){
    Graph g(9);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.primMST();

    return 0;
}
