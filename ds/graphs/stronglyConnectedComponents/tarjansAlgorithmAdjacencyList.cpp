/*
    Tarjan’s Algorithm to find Strongly Connected Components
    https://www.geeksforgeeks.org/tarjan-algorithm-find-strongly-connected-components/
*/
#include <iostream>
#include <unordered_map>
#include <stack>
#include <list>
using namespace std;

#define UNVISITED -1

// TC : O(V+E)
class Graph{
    int V;                      // no of edges in the graph
    int sccCount;               // total no. of strongly connected components in the graph
    int id;                     // used to keep the count of graphs nodes
    int *ids, *low;             // stores each nodes id values and its low-link value
    bool *onStack;              // verifies which nodes can be visited from the current node
    stack<int> st;              // stacks that are visited by dfs
    list<int> *adj;             // adjacency list
    void tarjansUtil(int at);   // tarjan's algo DFS method
public:
    // constructor
    Graph(int V) :  V(V), sccCount(0), id(0), ids(new int[V]), low(new int[V]),
                    onStack(new bool[V]), adj(new list<int>[V]) {}
    void addEdge(int u, int v);                     // add's edge in the graph
    unordered_map<int, list<int>> tarjansSSC();     // tarjans algorithm
};

// directed nodes graph
void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
}

void Graph::tarjansUtil(int at){
    st.push(at);
    onStack[at] = true;
    ids[at] = low[at] = id++;

    // visit all the neighbours & min low-link on callback
    for(auto to:adj[at]){
        if(ids[to] == UNVISITED)    tarjansUtil(to);                        // DFS

        /*
        this line allows the propogation of low-link value within a
        strongly Connected component, by making sure that the low-link value
        is only accounted for when it comes from one of it's neighbours i.e.
        nodes in the cycle
        */
        if(onStack[to])             low[at] = min(low[at], low[to]);
    }

    /*  After having visited all the neighbours of 'at'
        if we're at the start of a SCC, empty the seen stack
        until we're back to the start of SCC.
    */
    if(ids[at] == low[at]){
        while(!st.empty()){
            int node = st.top();
            st.pop();

            /*
            this is imp, as when we are done with the current scc,
            we will mark it's components false,
            as we dont want the next scc's components to consider
            any one of the low-link's value of this components nodes

            also we are assigning the nodes of the same components,
            with same ids, so that it will be easier to locate them afterwards
            */
            onStack[node] = false;
            low[node] = ids[at];

            /*
            we empty it, till we find the start of SCC, i.e. the 'at' node,
            if we find the 'at' node in the stack before it get's empty,
            then there must a node in it, that will form a scc with its neighbours,
            so break the loop when we find the at node in the stack
            */
            if(node == at)  break;
        }
        sccCount++;             // increment the total scc count
    }
}

// main tarjan's function
unordered_map<int, list<int>> Graph::tarjansSSC(){
    for(int i = 0; i < V; i++){
        ids[i] = UNVISITED;
        onStack[i] = false;
    }

    for(int i = 0; i < V; i++)
        if(ids[i] == UNVISITED)
            tarjansUtil(i);

    unordered_map<int, list<int>> ans;
    for(int i = 0; i < V; i++)
        ans[low[i]].push_back(i);

    return ans;
}

// Driver function
int main(){
    cout << "SCCs in first graph \n";
    int V = 8;
    Graph g(V);
    g.addEdge(3, 7);
    g.addEdge(3, 4);
    g.addEdge(7, 3);
    g.addEdge(7, 5);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(5, 0);
    g.addEdge(6, 2);
    g.addEdge(6, 4);
    g.addEdge(6, 0);
    g.addEdge(2, 0);
    g.addEdge(0, 1);
    g.addEdge(1, 2);

    int k = 0;
    for(auto i:g.tarjansSSC()){
        cout << "SCC " << k << " : ";
        k++;
        for(auto j:i.second)
            cout << j << " ";
        cout << endl;
    }

    cout << "\nSCCs in second graph \n";
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);

     k = 0;
    for(auto i:g1.tarjansSSC()){
        cout << "SCC " << k << " : ";
        k++;
        for(auto j:i.second)
            cout << j << " ";
        cout << endl;
    }

    cout << "\nSCCs in third graph \n";
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);

     k = 0;
    for(auto i:g2.tarjansSSC()){
        cout << "SCC " << k << " : ";
        k++;
        for(auto j:i.second)
            cout << j << " ";
        cout << endl;
    }


    cout << "\nSCCs in fourth graph \n";
    Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);

     k = 0;
    for(auto i:g3.tarjansSSC()){
        cout << "SCC " << k << " : ";
        k++;
        for(auto j:i.second)
            cout << j << " ";
        cout << endl;
    }

    cout << "\nSCCs in fifth graph \n";
    Graph g4(11);
    g4.addEdge(0,1);g4.addEdge(0,3);
    g4.addEdge(1,2);g4.addEdge(1,4);
    g4.addEdge(2,0);g4.addEdge(2,6);
    g4.addEdge(3,2);
    g4.addEdge(4,5);g4.addEdge(4,6);
    g4.addEdge(5,6);g4.addEdge(5,7);g4.addEdge(5,8);g4.addEdge(5,9);
    g4.addEdge(6,4);
    g4.addEdge(7,9);
    g4.addEdge(8,9);
    g4.addEdge(9,8);

     k = 0;
    for(auto i:g4.tarjansSSC()){
        cout << "SCC " << k << " : ";
        k++;
        for(auto j:i.second)
            cout << j << " ";
        cout << endl;
    }

    cout << "\nSCCs in sixth graph \n";
    Graph g5(5);
    g5.addEdge(0,1);
    g5.addEdge(1,2);
    g5.addEdge(2,3);
    g5.addEdge(2,4);
    g5.addEdge(3,0);
    g5.addEdge(4,2);

    k = 0;
    for(auto i:g5.tarjansSSC()){
        cout << "SCC " << k << " : ";
        k++;
        for(auto j:i.second)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}
