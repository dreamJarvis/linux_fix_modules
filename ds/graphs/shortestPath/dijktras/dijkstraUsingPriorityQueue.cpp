/*
    Dijkstra’s Shortest Path Algorithm using priority_queue of STL
    https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/?ref=rp
*/
#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX
typedef pair<int, int> iPair;       // iPair ==> integer pair

// graph :-> adjacency list representation
class Graph{
    int V;                      // no. of vertices
    list<iPair> *adj;           // for every vertex -> we stored it adjacent neighbour with the weight of their edges
public:
    Graph(int V) : V(V), adj(new list<iPair>[V]) {}     // initializing graph, with given vertices
    void addEdge(int u, int v, int w);
    void shortestPath(int s);
};

// adjacency list
void Graph::addEdge(int u, int v, int w){
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

// shortest Path from the source
// tc : O(E*log(V))
void Graph::shortestPath(int src){
    // the vextex with lowest distane is stored at the top
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;    // this is the syntax of min-heap
    vector<int> dist(V, INF);   // all the distances are initialized as INF

    pq.push({0, src});  // the distance of src from itself is 0
    dist[src] = 0;      // distane of source from itself

    // till priority queue becomes empty
    // there will come a time when the shortest distane to all the vertexes from the souce is found
    // and then the rest of the elements in the priority queue will simply pop off
    while(!pq.empty()){
        /* the top element is the one with the smallest distance.
        the second child contains the vertex with the diance from sources to that vertex in first child
        After recieving the vertex of the current smallest distane, we will delete it,
        as it now has been processed*/
        int u = pq.top().second;
        pq.pop();

        /*updating the distances off all the nodes available from this node*/
        for(auto i:adj[u]){
            int v = i.first;
            int weight = i.second;

            if(dist[v] > dist[u] + weight){
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // print shortest distance stored in dist[]
    cout << "Vertex \tDistance from Source\n";
    for(int i = 0; i < V; i++)
        cout << " " << i << "\t\t" << dist[i] << endl;
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
