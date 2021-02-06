/*
    Dijkstra’s Shortest Path Algorithm using priority_queue of STL
    https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/?ref=rp
*/
#include <bits/stdc++.h>
using namespace std;

// ========================= Graph section ============================ //
// a structure to represent a node in adjacency list
struct AdjListNode {
    int dest;
    int weight;
    AdjListNode *next;
    AdjListNode(int dest, int weight) : dest(dest), weight(weight), next(nullptr) {}
};

// a structure to represent an adjacency list
struct AdjList{
    AdjListNode *head;
};

// a structure to represent a graph. A graph is an array of adjacency lists
struct Graph{
    int V;              // size of array will be V
    AdjList* array;
    Graph(int V) : V(V), array(new AdjList[V]) {}
};

// function to create a new adjacency list node
AdjListNode* newAdjListNode(int dest, int weight){
    AdjListNode* newNode = new AdjListNode(dest, weight);
    return newNode;
}

// create a graph of V vertices
Graph *createGraph(int V){
    Graph *graph = new Graph(V);

    // evry adjacency list array will start with it's head at null
    for(int i = 0; i < V; i++)
        graph->array[i].head = nullptr;

    return graph;
}

// add an edge to an undorected grph
void addEdge(Graph *graph, int src, int dest, int weight){
    AdjListNode *newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // if graph is un-directed, add an edge from dest to src also
    // newNode = newAdjListNode(src, weight);
    // newNode->next = graph->array[dest].head;
    // graph->array[dest].head = newNode;
}

// ==================== Heap section ===================== //
// structure to represent a min-heap node
struct MinHeapNode{
    int v;
    int dist;
    MinHeapNode(int v, int dist) : v(v), dist(dist) {}
};

// structure to represent a min heap
struct MinHeap{
    int size;                   // number of heap nodes present currently
    int capacity;               // capacity of min heap
    int *pos;                   // this is needed for decreaseKey()
    MinHeapNode **array;            // ptr to ptr
    MinHeap(int capacity) : size(0), capacity(capacity),
                            pos(new int[capacity]), array(new MinHeapNode*[capacity]) {}
};

// to create a min heap node
MinHeapNode* newMinHeapNode(int v, int dist){
    MinHeapNode *minHeapNode = new MinHeapNode(v, dist);
    return minHeapNode;
}

// to create a min heap
MinHeap *createMinHeap(int capacity){
    MinHeap *minHeap = new MinHeap(capacity);
    return minHeap;
}

// to swap 2 nodes
void swapMinHeapNode(MinHeapNode** a, MinHeapNode ** b){
    MinHeapNode *t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(MinHeap *minHeap, int idx){
    int smallest, left, right;
    smallest = idx;
    left = 2*idx + 1;
    right = 2*idx + 2;

    if(left < minHeap->size && minHeap->array[left]->dist < minHeap->array[smallest]->dist)
        smallest = left;

    if(right < minHeap->size && minHeap->array[right]->dist < minHeap->array[smallest]->dist)
        smallest = right;

    if(smallest != idx){
        // nodes to be swapped in min heap
        MinHeapNode *smallestNode = minHeap->array[smallest];
        MinHeapNode *idxNode = minHeap->array[idx];

        // swap positions in the pos array, which keep the records, of which array is where in the array
        minHeap->pos[smallestNode->v] = idx;
        minHeap->pos[idxNode->v] = smallest;

        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// if heap is empty or not
int isEmpty(MinHeap *minHeap){
    return minHeap->size == 0;
}

MinHeapNode *extractMin(MinHeap *minHeap){
    if(isEmpty(minHeap))    return nullptr;

    // extract the top node
    MinHeapNode *root = minHeap->array[0];

    MinHeapNode *lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;

    // update positions of last node
    minHeap->pos[root->v] = minHeap->size - 1;
    minHeap->pos[lastNode->v] = 0;

    // reduce head size and heapify root
    --minHeap->size;
    minHeapify(minHeap, 0);

    return root;
}

/* function to decrease dist value of a given vertex v.
This function uses pos[] of min heap toget the current index of node on min heap
*/
void decreaseKey(MinHeap *minHeap, int v, int dist){
    int i = minHeap->pos[v];        //  get the index of v in heap array
    minHeap->array[i]->dist = dist; // update the distance form the source node

    /* Travel up while the complete tree is not heapified
    if the dist of the current node in the heap, is less than its parent , move up the tree
    This is a O(log(n)) loop
    */
    while(i && minHeap->array[i]->dist < minHeap->array[(i-1)/2]->dist){
        // swap the nodes with it's parent, and store their position in the pos[]
        minHeap->pos[minHeap->array[i]->v] = (i-1)/2;
        minHeap->pos[minHeap->array[(i-1)/2]->v] = i;

        // swapping the nodes
        swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i-1)/2]);

        // mode to the parent index
        i = (i-1)/2;
    }
}

// to check if the given vertex is in the min heap
bool isInMinHeap(MinHeap *minHeap, int v){
    if(minHeap->pos[v] < minHeap->size)
        return true;
    return false;
}

// print the distance array
void printArr(int dist[], int n){
    cout << "Vertex Distance from source\n";
    for(int i = 0; i < n; i++)
        cout << i << "\t" << dist[i] << endl;
}

/* calculates distances of shortest paths from src to all vertices.
tc:  O(E*log(V)),  E -> edges, V -> vertex
*/
void dijkstra(Graph *graph, int src){
    int V = graph->V;   // get the numbers of vertices in graph
    int dist[V];        // dist values used to pick min weight's edge in cut

    // representing the graph in min heap
    MinHeap *minHeap = createMinHeap(V);

    // initialize min heap with all vertices. dist value of all vertices
    for(int v = 0; v < V; v++){
        dist[v] = INT_MAX;
        minHeap->array[v] = newMinHeapNode(v, dist[v]);
        minHeap->pos[v] = v;
    }

    // make dist value of src vertex as 0, so that it is extracted first
    minHeap->array[src] = newMinHeapNode(src, dist[src]);
    minHeap->pos[src] = src;
    dist[src] = 0;
    decreaseKey(minHeap, src, dist[src]);

    minHeap->size = V;  // initially size if min heap is equal to V

    // in the following loop, min heap contains all nodes whose shprtest distance is not finisjde yet
    while(!isEmpty(minHeap)){
        MinHeapNode *newMinHeapNode = extractMin(minHeap);
        int u = newMinHeapNode->v;     // store the extracted vertex

        AdjListNode *pCrawl = graph->array[u].head;
        while(pCrawl != nullptr){
            int v = pCrawl->dest;

            /* if shortest distance to v is not finalized yet,
            and distance to v through u is less than its previously calculated distance*/
            if( isInMinHeap(minHeap, v) && dist[u] != INT_MAX &&
                pCrawl->weight + dist[u] < dist[v] ){
                dist[v] = dist[u] + pCrawl->weight;

                // update distance value in min heap also
                decreaseKey(minHeap, v, dist[v]);
            }

            pCrawl = pCrawl->next;
        }
    }

    printArr(dist, V);
}

// Driver function
int main(){
    // create the graph given in above fugure
    int V = 9;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 7, 8);
    addEdge(graph, 1, 2, 8);
    addEdge(graph, 1, 7, 11);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 8, 2);
    addEdge(graph, 2, 5, 4);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 3, 5, 14);
    addEdge(graph, 4, 5, 10);
    addEdge(graph, 5, 6, 2);
    addEdge(graph, 6, 7, 1);
    addEdge(graph, 6, 8, 6);
    addEdge(graph, 7, 8, 7);

    dijkstra(graph, 0);

    return 0;
}
