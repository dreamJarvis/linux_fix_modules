/*
    Longest Path in a Directed Acyclic Graph
    https://www.geeksforgeeks.org/find-longest-path-directed-acyclic-graph/
*/
#include <bits/stdc++.h>
using namespace std;

#define NINF INT_MIN

class AdjListNode{
    int v;
    int Weight;
public:
    AdjListNode(int _v, int _w) : v(_v), Weight(_w) {}
    int getV()      {   return v;   }
    int getWeight() {   return Weight;  }
};

class Graph{
    int V;
    list<AdjListNode> *adj;
public:
    Graph(int V) : V(V), adj(new list<AdjListNode>[V]) {}
    void addEdge(int u, int v, int weight);
    void topologicalSortingUtil(int v, bool visited[], stack<int> &Stack);
    vector<int> longestPath(int s);
};

void Graph::addEdge(int u, int v, int weight){
    AdjListNode node(v, weight);
    adj[u].push_back(node);
}

void Graph::topologicalSortingUtil(int v, bool visited[], stack<int> &Stack){
    visited[v] = true;

    for(auto i:adj[v])
        if(!visited[i.getV()])
            topologicalSortingUtil(i.getV(), visited, Stack);

    Stack.push(v);
}

// this is similar to shortest path, here we just update the value for the biggest value
vector<int> Graph::longestPath(int s){
    stack<int> Stack;
    vector<int> dist(V, NINF);
    bool visited[V] = {false};

    for(int i = 0; i < V; i++)
        if(!visited[i])
            topologicalSortingUtil(i, visited, Stack);

    dist[s] = 0;
    while(!Stack.empty()){
        int u = Stack.top();
        Stack.pop();

        if(dist[u] != NINF){
            for(auto i:adj[u]){
                // Relaxation
                if(dist[i.getV()] < dist[u] + i.getWeight())        // so fi the current value is smaller the update it
                    dist[i.getV()] = dist[u] + i.getWeight();
            }
        }
    }

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
    g.addEdge(3, 5, 1);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);


    int s = 1;

    vector<int> res = g.longestPath(s);
    for(auto i:res)
        if(i != NINF)
            cout << i << " ";

    return 0;
}
