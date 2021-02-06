#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <list>
using namespace std;

#define UNVISITED -1

class Graph{
    int V;
    int sccCount;
    int id;
    int *low, *ids;
    bool *onStack;
    stack<int> st;
    list<int> *adj;
    void tarjansUtil(int u);
public:
    Graph(int V) : V(V), sccCount(0), id(0), low(new int[V]), ids(new int[V]),
                    onStack(new bool[V]), adj(new list<int>[V]) {}
    void addEdge(int u, int v);
    unordered_map<int, list<int>> tarjansSSC();
};

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
}

void Graph::tarjansUtil(int at){
    st.push(at);
    onStack[at] = true;
    ids[at] = low[at] = id++;

    for(auto &to:adj[at]){
        if(ids[to] == UNVISITED)    tarjansUtil(to);
        if(onStack[to])             low[at] = min(low[to], low[at]);        // keeping the minimal ids value amongs't its neighbours
    }

    if(low[at] == ids[at]){
        while(!st.empty()){
            int node = st.top();
            st.pop();

            onStack[node] = false;
            low[node] = ids[at];            // creating an scc component

            if(node == at) break;
        }
        sccCount++;
    }
}

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
        ans[low[i]].push_back(i);           // putting vertex with same low's value together

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

    return 0;
}
