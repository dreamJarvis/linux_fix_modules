/*
    Kruskal’s Minimum Spanning Tree Algorithm
    https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/?ref=rp
    Time complexity : O(Elog(E))
*/
#include <bits/stdc++.h>
using namespace std;

// ------------------------------------  Graph -----------------------------------//
// to represent weighted edge in graph
class Edge{
public:
    int src, dest, weight;
};

// to represent a connected, undirected, and weighted graph
class Graph{
public:
    int V, E;   // v -> No. of vertices, E -> No. of edges
    /*graph is represented as array of edges. since the graph is undirected,
    the edge from (src -> dest) is also edge from (dest -> src)
    Both are counted as 1 edge
    */
    Edge *edge;
};

// graph with V vertices and E edges
Graph *createGraph(int V, int E){
    Graph *graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

// ----------------------------------- Union-find -------------------------------- //
// to represent a subset for union-find
class subset{
public:
    int parent;
    int rank;
};

/* a utility function to find set of an element i (using path compression technique)*/
int find(subset subsets[], int i){
    // find root and make root as parent of i (path compression)
    if(subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

// union of 2 set's x & y (uses Union by rank)
void Union(subset subsets[], int x, int y){
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    // attch smaller rank tree under root of high rank tree
    if(subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if(subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;

    /* else if rank are same, then make one as root
    and increment it's rank */
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// ------------------------------ kruskal algo ---------------------------------//
int myComp(const void *a, const void *b){
    Edge *a1 = (Edge*)a;
    Edge *b1 = (Edge*)b;
    return a1->weight > b1->weight;
}

void kruskalMST(Graph *graph){
    int V = graph->V;
    Edge result[V];     // stores the resultant MST
    int e = 0;          // an index variable for result
    int i = 0;          // an index variable for sorted edges

    /*step 1:
    sort all the edges in non-decreasing order of their weight
    if we are not allowed to change the given Graph,
    we can create a copy of array of integers
    */
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);

    subset *subsets = new subset[V];    // creating V subsets

    // creating V subsets with single elements
    for(int v = 0; v < V; v++){
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // number of edges to be taken is equal to V-1
    while(e < V - 1 && i < graph->E){
        /*step 2:
        pick the smallest edge. And increment the index or next iteration
        */
        Edge nextEdge = graph->edge[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        /*if including this edge doesn't cause cycle,
        include it in the result and increment the index
        of result for next edge*/
        if(x != y){
            result[e++] = nextEdge;
            Union(subsets, x, y);
        }
        // else discard the nextEdge
    }

    // MST
    cout << "Folwwing are the edges in the constructed MST\n";
    for(int i = 0; i < e; i++)
        cout << result[i].src << " -- " << result[i].dest << " == " << result[i].weight << endl;
    return ;
}


// Driver code
int main(){
    /* Let us create following weighted graph
            10
        0--------1
        | \ |
    6| 5\ |15
        | \ |
        2--------3
            4 */
    int V = 4; // Number of vertices in graph
    int E = 5; // Number of edges in graph
    Graph* graph = createGraph(V, E);


    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;

    // add edge 0-2
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;

    // add edge 0-3
    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;

    // add edge 1-3
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;

    // add edge 2-3
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;

    kruskalMST(graph);

    return 0;
}
