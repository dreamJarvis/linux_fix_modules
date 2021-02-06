/*
    to find single source shortest path using bellman ford : edge list
    https://www.geeksforgeeks.org/bellman-ford-algorithm-simple-implementation/
*/
#include <iostream>
#include <climits>
#include <vector>
using namespace std;


#define INF INT_MAX
#define NINF INT_MIN

/*
    finds shortest path and also detects -ve cycle
    row graph[i] --> i'th with 3 values u, v, weight

    tc : O(V*E)
*/
void bellmanFord(int graph[][3], int V, int E, int src){
    vector<int> dest(V, INF);
    dest[src] = 0;

    // O(V*E)
    /* relax all edges |V| -1 times.
    A simple shortest path from src to all the other vertices, vertex can have at-most |V| - 1 edges
    we iterate v-1 times to make sure that we go over all the vertices in the given graph
     */
    for(int i = 0; i < V-1; i++){           // going over all the vertices
        for(int j = 0; j < E; j++){         // going over all the edges
            int u = graph[j][0];
            int v = graph[j][1];
            int weight = graph[j][2];

            if(dest[v] > dest[u] + weight){
                dest[v] = dest[u] + weight;
            }
        }
    }

    // O(V*E)
    /*check for -ve weighted cycles. The above step guarentees shortest distances if graph doesn't
    contain -ve weight cycle. If we get a shorter path, then there is a cycle*/
    for(int i = 0; i < V-1; i++){
        for(int j = 0; j < E; j++){
            int u = graph[j][0];
            int v = graph[j][1];
            int weight = graph[j][2];

            if(dest[v] > dest[u] + weight){
                dest[v] = NINF;
            }
        }
    }

    cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << "\t\t" << dest[i] << endl;
}

// Driver function
int main(){
    int V = 5;
    int E = 8;

    int graph[][3] = {
        {0, 1, -1}, {0, 2, 4},
        {1, 2, 3}, {1, 3, 2},
        {1, 4, 2}, {3, 2, 5},
        {3, 1, 1}, {4, 3, -3}
    };

    bellmanFord(graph, V, E, 0);

    return 0;
}
