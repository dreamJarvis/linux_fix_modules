// Directed Weighted graph
#include <bits/stdc++.h>
using namespace std;

// every vertiex, will have an list attaed to it, it will signify all the elements it is attached to
struct Node {
    int val, cost;
    Node *next;
};

// components of every edge, are its 2 vertices , i.e. its source and destination
// and in weighted graph, its weight
struct Edge{
    int src, dest, weight;
};

class Graph{
    Node *getAdjListNode(int value, int weight, Node *head){
        Node *newNode = new Node;
        newNode->val = value;
        newNode->cost = weight;

        newNode->next = head;

        return newNode;
    }

    int noOfVertex;

public:
    Node **head;

    Graph(Edge edges[], int noOfEdges, int noOfVertex){
        head = new Node*[noOfVertex]();
        this->noOfVertex = noOfVertex;

        for(int i = 0; i < noOfVertex; i++)  head[i] = nullptr;

        for(unsigned i = 0; i < noOfEdges; i++){
            int src = edges[i].src;
            int dest = edges[i].dest;
            int weight = edges[i].weight;

            Node *newNode = getAdjListNode(src, weight, head[src]);
            head[src] = newNode;
        }
    }

    ~Graph(){
        for(int i = 0; i < noOfVertex; i++) delete[] head[i];
        delete[] head;
    }
};

void printList(Node *ptr, int i){
    while(ptr != nullptr){
        cout << "(" << i << ", " << ptr->val << ", " << ptr->cost << ")";

        ptr = ptr->next;
    }
    cout << endl;
}

// driver function
int main(){
    Edge edges[]=
    {
        {0, 1, 6},  {1, 2, 7}, {2, 0, 5}, {2, 1, 4},
        {3, 2, 10}, {4, 5, 1}, {5, 4, 3}
    };

    int noOfVertex = 6;
    int noOfEdges = sizeof(edges)/sizeof(edges[0]);

    Graph graph(edges, noOfEdges, noOfVertex);

    for(int i = 0; i < noOfVertex; i++){
        printList(graph.head[i], i);
    }

    return 0;
}
