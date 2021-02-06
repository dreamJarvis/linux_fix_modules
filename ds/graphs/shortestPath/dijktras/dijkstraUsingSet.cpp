/*
    Dijkstra’s shortest path algorithm using set in STL
    https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-set-in-stl/
*/
#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX

class Graph{
    int V;
    list<pair<int, int>> *adj;      // for edges with weight
public:
    Graph(int V) : V(V), adj(new list<pair<int, int>>[V]) {}    // initializing graph
    void addEdge(int u, int v, int w);
    void shortestPath(int s);
};

// for directed graph
void Graph::addEdge(int u, int v, int w){
    adj[u].push_back({v, w});
    // adj[v].push_back({u, w});    // for undirected graph
}

// shortest path from source to all vertices
// tc : O(E*log(V))
void Graph::shortestPath(int src){
    /* to store the distances from source to a particular vetex ,
    which inclues the chlid of previous processed node,
    we store in set to have access to the shortest path possible,
    and make it our next processing node */
    set<pair<int, int>> setds;
    vector<int> dist(V, INF);       // the distances are initializes as INF

    setds.insert({0, src});     // distance from src, till current node
    dist[src] = 0;              // the distane of src, from itself is 0

    // till all the elements have its shortest path in the dist[] array
    while(!setds.empty()){
        // first vertex is set in the minimum distance vertex, extract it from set
        pair<int, int> tmp = *(setds.begin());
        setds.erase(setds.begin());

        /* vertex label is stored as a second child element in pair,
        it has to be done this way, as we have to sort according to distances,
        and set sorts according to key, in an key-value pair */
        int u = tmp.second;     //  set : {weight, vertex}

        /* all the vetices attached to the current vertex , i.e. all the edges are stored ,\
        if they have distances smaller than already existing ones*/
        for(auto i:adj[u]){
            // adjacency list : {vertex, weight}
            int v = i.first;
            int weight = i.second;

            if(dist[v] > dist[u] + weight){
                /* if distane of v is not INF, then it must be in our set,
                so removing it and inserting again with updated less value
                NOTE : We extract only those vertices from set for which distane is finalized.
                So for them we would never reach them */
                if(dist[v] != INF)
                    setds.erase(setds.find({dist[v], v}));

                // updating distance of V
                dist[v] = dist[u] + weight;
                setds.insert({dist[v], v});
            }
        }
    }

    // print the distane array
    cout << "Vertex \tdistane from source\n";
    for(int i = 0; i < V; i++)
        cout << "  " << i << "\t\t" << dist[i] << endl;
}

// Driver function
int main(){
    // create the graph given in above fugure
    int V = 9;
    Graph g(V);

    //  making above shown graph
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

    g.shortestPath(0);

    return 0;
}
