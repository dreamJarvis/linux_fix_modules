/*
    Shortest Path in Weighted Directed Acyclic Graph
    https://www.geeksforgeeks.org/shortest-path-for-directed-acyclic-graphs/
*/
#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX

/*
    graph is represented by adjacency list. Every node of adjaceney list contains vertex number of the
    vertex to which the edge connects. It also contains weight of the edge
*/
class AdjListNode{
    int v;
    int weight;
public:
    AdjListNode(int _v, int _w) : v(_v), weight(_w) {}
    int getV()          {    return v;   }
    int getWeight()     {   return weight;  }
};

// graph adjacency list representation
class Graph{
    int V;                          // no. of vertices
    list<AdjListNode> *adj;         // pointer to an array containing adjacency lists
    void topologicalSortingUtil(int v, bool visited[], stack<int> &Stack);  // gives topologically sorted path
public:
    Graph(int V) : V(V), adj(new list<AdjListNode>[V]) {}   // constructor
    void addEdge(int u, int v, int weight);                 // function to add an edge to graph
    vector<int> shortestPath(int s);                               // finds shortest apths from given source vertex
};

void Graph::addEdge(int u, int v, int weight){
    AdjListNode node(v, weight);
    adj[u].push_back(node);
}

// topologically sorting the graph
void Graph::topologicalSortingUtil(int v, bool visited[], stack<int> &Stack){
    visited[v] = true;

    for(auto i:adj[v])
        if(!visited[i.getV()])
            topologicalSortingUtil(i.getV(), visited, Stack);

    Stack.push(v);
}

vector<int> Graph::shortestPath(int s){
    stack<int> Stack;
    vector<int> dist(V, INF);            // initialize distances to all vertices as infinite and distance to source as 0

    bool visited[V] = {false};

    // to make sure each vertex is topologically sorted
    for(int i = 0; i < V; i++)
        if(!visited[i])
            topologicalSortingUtil(i, visited, Stack);


    dist[s] = 0;
    while(!Stack.empty()){
        // get the next vertex from the topological order
        int u = Stack.top();
        Stack.pop();

        if(dist[u] != INF){
            for(auto i:adj[u])
                if(dist[i.getV()] > dist[u] + i.getWeight())        // to store the min path
                    dist[i.getV()] = dist[u] + i.getWeight();
        }
    }

    // return the calculated shortest distances
    return dist;
}

// Driver function
int main(){
    Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    int s = 1;

    vector<int> res = g.shortestPath(s);
    for(auto i:res)
        if(i != INF)
            cout << i << " ";

    return 0;
}
