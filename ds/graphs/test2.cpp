#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int, int> iPair;

class DisjointSet{
public:
    int size, *rank, *parent;
    DisjointSet(int size) : size(size), rank(new int[size+1]),
                            parent(new int[size+1]) {}
    int find(int x);
    void Union(int x, int y);
};

int DisjointSet::find(int x){
    if(x != parent[x])
        parent[x] = find(parent[x]);
    return parent[x];
}

void DisjointSet::Union(int x, int y){
    x = find(x), y = find(y);

    if(rank[x] < rank[y]){
        parent[x] = y;
        rank[y] += rank[x];
    }
    else if(rank[x] >= rank[y]){
        parent[y] = x;
        rank[x] += rank[y];
    }
}

class Graph{
public:
    int V, E;
    vector<pair<int, iPair>> edges;
    Graph(int V, int E) : V(V), E(E) {}

    void addEdge(int u, int v, int w){
        edges.push_back({w, {u, v}});
    }

    int kruskalMST();
};

int Graph::kruskalMST(){
    int mstWt = 0;
    DisjointSet ds(V);

    sort(edges.begin(), edges.end());

    for(int i = 0; i <= V; i++){
        ds.rank[i] = 0;
        ds.parent[i] = i;
    }

    for(auto it:edges){
        int u = it.second.first;
        int v = it.second.second;
        int wt = it.first;

        int setU = ds.find(u);
        int setV = ds.find(v);

        if(setU != setV){
            mstWt += wt;
            cout << u << " - " << v << " : " << wt << endl;
            ds.Union(setU, setV);
        }
    }

    return mstWt;
}

// Driver function
int main(){
    int V = 9, E = 14;
    Graph g(V, E);

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

    cout << "Edges of MST are \n";
    int mst_wt = g.kruskalMST();

    cout << "\nWeight of MST is " << mst_wt;

    return 0;
}
