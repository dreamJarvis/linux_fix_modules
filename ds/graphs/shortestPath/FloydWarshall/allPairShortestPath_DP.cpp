/*
    Flyod Warshall
    https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/?ref=rp
*/
#include <iostream>
#include <climits>
using namespace std;

#define V 4
#define INF INT_MAX

void flyodWarshall(int graph[][V]){
    // the output matrix
    int dist[V][V];

    // intitialize the dp output, with the graph initial values
    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    /* initially we have the shortest distances, now k -> is the vertex w.r.t which we will account the
    distance ( from i -> j via k )
    */
    for(int k = 0; k < V; k++)
        for(int i = 0; i < V; i++)
            for(int j = 0; j < V; j++)
                if( dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]
                ){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }

    // print solution
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++)
            if(dist[i][j] == INF)   cout << "INF\t";
            else                    cout << dist[i][j] << "\t";
        cout << endl;
    }
}

// Driver function
int main(){
    int graph[V][V] = { {0,   5,   INF, 10},
                        {INF, 0,   3,   INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                    };

    flyodWarshall(graph);
    return 0;
}
