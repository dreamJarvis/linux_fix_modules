/*
    Prim’s MST for Adjacency List Representation
    https://www.geeksforgeeks.org/prims-mst-for-adjacency-list-representation-greedy-algo-6/

    Time complexity : O(E*log(V))
*/
#include <iostream>
#include <list>
#include <vector>
#include <climits>

#include "../minHeap.h"     // a min heap library
/*
    (values are stored in {key:value} pair in the heap, and the heap is sorted according
    to the value's of key)
    minHeapify()    : to sort the heap in min order first
    isEmpty()       : to check if the heap is empty or not
    extractMin()    : extracts the smalles node from the heap (the top element)
    decreaseKey()   : decreases the key of a node, and heapifie's the heap
    isInMinHeap()   : return's true if that element is in min heap
*/

using namespace std;

#define INF INT_MAX

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
    MinHeap *minHeap = new MinHeap(V);

    /* initialize min heap with all vertices.
    key value of al vertices (except 0th vertex) is initially infinite
    */
    for(int v = 1; v < V; v++){
        parent[v] = -1;
        key[v] = INF;
        minHeap->array[v] = new MinHeapNode(v, key[v]);
        minHeap->pos[v] = v;
    }

    // make key value of 0th vertex as 0, so that it is extracted first
    key[0] = 0;
    minHeap->array[0] = new MinHeapNode(0, key[0]);     // pushing first node in the min-heap
    minHeap->pos[0] = 0;

    // initially size of min heap is equal to V
    minHeap->size = V;

    /*in the following loop, min heap contains all nodes not et added to MSt */
    while(!isEmpty(minHeap)){
        // extract the vertex with minimum key value
        MinHeapNode *minHeapNode = extractMin(minHeap);
        int u = minHeapNode->v;     // store the extracted vertex number

        // cout << u << endl;

        /*  go to all the neighbours of u, and update the distance stored in key,
            if an alternate shorter distance from u -> v exist
        */
        for(auto to:adj[u]){
            int v = to.first;
            int weight = to.second;

            // cout << u << " - " << v << " : " << weight << endl;

            if(isInMinHeap(minHeap, v) && weight < key[v]){
                key[v] = weight;
                parent[v] = u;
                decreaseKey(minHeap, v, key[v]);
            }
        }
    }

    printArr();
}

void Graph::printArr(){
    int totalCost = 0;
    cout << "Edge\t Weight\n";
    for(int v = 1; v < V; v++){
        cout << parent[v] << " - " << v << ":\t" << key[v] << endl;
        totalCost += key[v];
    }
    cout << totalCost << endl;
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
