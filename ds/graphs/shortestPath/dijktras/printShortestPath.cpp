/*
    Printing Paths in Dijkstra’s Shortest Path Algorithm in directed weighted graph
    https://www.geeksforgeeks.org/printing-paths-dijkstras-shortest-path-algorithm/
*/
#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX                 // defines infinity
typedef pair<int, int> iPair;       // representing variables as pair

// directed weighted graph, with no -ve cycles
class Graph{
    int V;
    list<iPair> *adj;
public:
    Graph(int V) : V(V), adj(new list<iPair>[V]) {}
    void addEdge(int u, int v, int weight);
    void shortestPath(int src);
};

void Graph::addEdge(int u, int v, int weight){
    adj[u].push_back({v, weight});
    // adj[v].push_back({u, weight});   // for un-directed graph
}

void Graph::shortestPath(int src){
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    vector<int> dist(V, INF);
    vector<string> paths(V, "-1");

    // defining source
    pq.push({0, src});
    dist[src] = 0;

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        for(auto i:adj[u]){
            int v = i.first;
            int weight = i.second;

            if(dist[v] > dist[u] + weight){
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});

                /* kyuki source ko define kra nhi h hmne, aor kyuki sare distances source se shru ho rhe h,
                toh path[u] == "-1", will work only when u == souce, because after it, as all the other
                distances are build upon source, .'. paths[u] == "-1", will only be used once
                */
                if(paths[u] == "-1")
                    paths[v] = to_string(u);
                else
                    paths[v] = paths[u] + "->" + to_string(u);
            }
        }
    }

    // printing the distances
    for(int i = 0; i < V; i++)
        if(i != src)
            cout << i << " --> " << paths[i] << endl;
    cout << endl;
}

// Driver function
int main(){
    // // create the graph given in above fugure
    // int V = 9;
    // Graph g(V);
    //
    // //  making above shown graph
    // g.addEdge(0, 1, 4);
    // g.addEdge(0, 7, 8);
    // g.addEdge(1, 2, 8);
    // g.addEdge(1, 7, 11);
    // g.addEdge(2, 3, 7);
    // g.addEdge(2, 8, 2);
    // g.addEdge(2, 5, 4);
    // g.addEdge(3, 4, 9);
    // g.addEdge(3, 5, 14);
    // g.addEdge(4, 5, 10);
    // g.addEdge(5, 6, 2);
    // g.addEdge(6, 7, 1);
    // g.addEdge(6, 8, 6);
    // g.addEdge(7, 8, 7);
    //
    // g.shortestPath(0);

    int V = 5;
    Graph g(V);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 3, 5);
    g.addEdge(3, 4, 3);

    g.shortestPath(0);

    return 0;
}
