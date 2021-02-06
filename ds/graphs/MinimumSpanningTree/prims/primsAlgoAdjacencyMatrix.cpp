/*
    A C++ program for Prim's Minimum Spanning Tree (MST) algorithm.
    The program is for adjacency matrix representation of the graph
    Time complexity :  O(V^2)
*/
#include <iostream>
using namespace std;

#define V 5
#define INF 999999

/* A utility function to find the vertex with minimum key value,
from the set of vertices not yet included in MST
*/
int minKey(int key[], bool mstSet[]){
    int min = INF, vertex;
    for(int v = 0; v < V; v++)
        if(!mstSet[v] && key[v] < min){
            min = key[v];
            vertex = v;
        }

    return vertex;
}

// print the MST
void printMST(int parent[], int graph[V][V]){
    cout << " Edge\tWeight\n";
    for(int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << "\t  " << graph[i][parent[i]] << endl;
}

// to construct and print MST for a graph represented using adjacency matrix
void primMST(int graph[V][V]){
    int parent[V];          // array to store constructed MST
    int key[V];             // key values to pick min. weight edge in cut
    bool mstSet[V];         // to represent all keys as INFINITE

    // initialize all key as INFINITE
    for(int i = 0; i < V; i++){
        key[i] = INF;
        mstSet[i] = false;
    }

    /* always include first vertex in MST,
    make it 0, so that this vertex is always picked first*/
    key[0] = 0;
    parent[0] = -1;             // first node is always root of MST

    for(int count = 0; count < V; count++){
        /*pick the min key vertex from the set of vertices,
        not yet included in the setMST
        */
        int u = minKey(key, mstSet);

        mstSet[u] = true;   // add the picked vertex to the MST set

        /*
        update key value and parent index of the adjacent vertices of the picked vertex.
        Consider only those vertices which are not yet included in the MST
        */
        for(int v = 0; v < V; v++)
            if(graph[u][v] && !mstSet[v] && graph[u][v] < key[v]){
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }

    printMST(parent, graph);
}

// Driver function
int main(){
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);

    return 0;
}
