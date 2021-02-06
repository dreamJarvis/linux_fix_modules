/*
    Disjoint Set (Or Union-Find) | Set 1 (Detect Cycle in an Undirected Graph)
    https://www.geeksforgeeks.org/union-find/
    time complexity : O(E)
*/
#include <iostream>
#include <list>
using namespace std;

// ===================== Disjoint set ================== //
class DisjointSet{
public:
    int size, *rank, *parent;
    DisjointSet(int size) : size(size), rank(new int[size+1]),
                            parent(new int[size+1]) {}
    int find(int x);
    void Union(int x, int y);
};

// find's the representative of the set (using path compression)
int DisjointSet::find(int x){
    if(x != parent[x])
        parent[x] = find(parent[x]);
    return parent[x];
}

// union of 2 set's
void DisjointSet::Union(int x, int y){
    int xSet = find(x);
    int ySet = find(y);

    if(xSet == ySet)    return ;

    if(rank[xSet] < rank[ySet]){
        parent[xSet] = ySet;
        rank[ySet] += rank[xSet];
    }
    else if(rank[xSet] >= rank[ySet]){
        parent[ySet] = xSet;
        rank[xSet] += rank[ySet];
    }
}

// ======================= Graph ====================== //
class Graph{
    int V;
    list<int> *adj;
public:
    Graph(int V) : V(V), adj(new list<int>[V]) {}
    void addEdge(int u, int v);
    bool detectCycle();
};

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
}

// detect Cycle in the graph
bool Graph::detectCycle(){
    DisjointSet ds(V);
    for(int i = 0; i <= V; i++){
        ds.rank[i] = 0;
        ds.parent[i] = i;
    }

    for(int i = 0; i < V; i++){
        int x = ds.find(i);
        for(auto j:adj[i]){
            int y = ds.find(j);
            if(x == y)  return true;
            ds.Union(x, y);
        }
    }

    return  false;
}

// Driver function
int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(3, 2);

    if(g.detectCycle())
        cout << "graph contian's cycle" << endl;
    else
        cout << "graph doesn't contain cycle" << endl;

    return 0;
}
