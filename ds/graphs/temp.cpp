#include <iostream>
#include <climits>
#include <vector>
using namespace std;

#define INF INT_MAX
#define NINF INT_MIN

void bellmanFord(int graph[][3], int V, int E, int src){
    vector<int> dist(V, INF);
    dist[src] = 0;

    for(int i = 0; i < V-1; i++){
        for(int j = 0; j < E; j++){
            int u = graph[j][0];
            int v = graph[j][1];
            int weight = graph[j][2];

            if(dist[v] > dist[u] + weight){
                dist[v] = dist[u] + weight;
            }
        }
    }

    for(int i = 0; i < V-1; i++){
        for(int j = 0; j < E; j++){
            int u = graph[j][0];
            int v = graph[j][1];
            int weight = graph[j][2];

            if(dist[v] > dist[u] + weight){
                dist[v] = NINF;
            }
        }
    }

    for(int i = 0; i < V; i++){
        cout << i << "\t" << dist[i] << endl;
    }
}

// Driver function
int main(){
    int V = 5;
    int E = 8;

    // edge list
    int graph[][3] = {
        {0, 1, -1}, {0, 2, 4},
        {1, 2, 3}, {1, 3, 2},
        {1, 4, 2}, {3, 2, 5},
        {3, 1, 1}, {4, 3, -3}
    };

    bellmanFord(graph, V, E, 0);

    return 0;
}
