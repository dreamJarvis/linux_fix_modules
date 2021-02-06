/*
    Kruskal’s Minimum Spanning Tree using STL in C++
    https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-using-stl-in-c/?ref=rp
    Time complexity : O(Elog(E))
*/

// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

typedef pair<int, int> iPair;

// to represent Disjoint sets
struct DisjointSets{
    int *parent, *rnk;
    int n;

    // constructor
    DisjointSets(int n){
        this->n = n;
        parent = new int[n+1];
        rnk = new int[n+1];

        // initially, all the vertices are in different set's and rank 0
        for(int i = 0; i <= n; i++){
            rnk[i] = 0;
            parent[i] = i;      // every element is a parent of itself
        }
    }

    // find parent of a node 'u' (path compression)
    int find(int u){
        /*make the parent of a nodes in the path from u-->parent[u] point to parent[u]*/
        if(u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    // union by rank
    void merge(int x, int y){
        x = find(x), y = find(y);

        /*make tree with smaller rank a sub-tree of other tree*/
        if(rnk[x] > rnk[y])
            parent[y] = x;
        else
            parent[x] = y;

        if(rnk[x] == rnk[y])
            rnk[y]++;
    }
};

struct Graph{
    int V, E;
    vector<pair<int, iPair>> edges;

    Graph(int V, int E) : V(V), E(E) {}
    void addEdge(int u, int v, int w){
        edges.push_back({w, {u, v}});
    }

    // to find MST
    int kruskalMST();
};


// to find the MST, and total cost of the path taken
int Graph::kruskalMST(){
    int mstWt = 0;                      // total cost of the path
    sort(edges.begin(), edges.end());   // sort's the edges int increasing order of weight's

    // create Disjoint sets
    DisjointSets ds(V);

    // iterate through all sorted edges
    for(auto it:edges){
        int u = it.second.first;            // src
        int v = it.second.second;           // dest
        int wt = it.first;                  // weight

        int setU = ds.find(u);
        int setV = ds.find(v);

        /*check if the seleced edge is creating a cycle or not
        (cycle is created if u and v belong to same set)*/
        if(setU != setV){
            cout << u << " - " << v  << " : " << wt << endl;
            mstWt += wt;                // update MST weight
            ds.merge(setU, setV);       // merge 2 sets
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
