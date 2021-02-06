/*
    Finding shortest path between any two nodes using Floyd Warshall Algorithm
    https://www.geeksforgeeks.org/finding-shortest-path-between-any-two-nodes-using-floyd-warshall-algorithm/?ref=rp
*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define MAXN 100                 // max size of array
const int INF = 1e7;             // infinite value
int dis[MAXN][MAXN];             // shortest distance from all nodes to every node
int Next[MAXN][MAXN];            // the next point

// initializing the distance and the next array
void intitialize(int V, vector<vector<int>> &graph){
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            dis[i][j] = graph[i][j];

            if(graph[i][j] == INF)  Next[i][j] = -1;    // no edge btw node
            else                    Next[i][j] = j;
        }
    }
}

// constructing the shortest path btw u --> v
vector<int> constructPath(int u, int v){
    /* if there's no path btw node u and v, simply return an empty array */
    if(Next[u][v] == -1)    return {};

    // storing the path
    vector<int> path = {u};
    while(u != v){
        u = Next[u][v];
        path.push_back(u);
    }

    return path;
}

// applying floyd-Warshall to find the shortest path btw all nodes
void floydWarshall(int V){
    for(int k = 0; k < V; k++)
        for(int i = 0; i < V; i++)
            for(int j = 0; j < V; j++)
                if( dis[i][k] != INF && dis[k][j] != INF &&
                    dis[i][j] > dis[i][k] + dis[k][j] )
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                    Next[i][j] = Next[i][k];         // next node, which will give the shortest path
                }
}

// print the shortest path
void printPath(vector<int> &path){
    int n = path.size();
    for(int i = 0; i < n-1; i++)
        cout << path[i] << " -> ";
    cout << path[n-1] << endl;
}

// Driver function
int main(){
    int V = 4;
    vector<vector<int> > graph{
        { 0, 3, INF, 7 },
        { 8, 0, 2, INF },
        { 5, INF, 0, 1 },
        { 2, INF, INF, 0 }
    };

    intitialize(V, graph);

    floydWarshall(V);
    vector<int> path;

    cout << "shortest path 1->3 : ";
    path = constructPath(1, 3);
    printPath(path);

    cout << "shortest path 0->2 : ";
    path = constructPath(0, 2);
    printPath(path);

    cout << "shortest path 3->2 : ";
    path = constructPath(3, 2);
    printPath(path);

    return 0;
}
