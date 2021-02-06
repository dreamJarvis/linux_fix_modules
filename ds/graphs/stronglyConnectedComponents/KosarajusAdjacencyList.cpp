/*
    Strongly Connected Components
    https://www.geeksforgeeks.org/strongly-connected-components/
*/
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

// directed grah
class Graph{
    int V;
    unordered_map<int, vector<int>> adjList;
public:
    Graph(int V) : V(V) {}
    void addEdge(int u, int v);
    void printSCCs();
    void fillInOrder(int v, stack<int> &st, vector<bool> &visited);
    void dfsUtil(int v, vector<bool> &visited);
    Graph transpose();
};

void Graph::addEdge(int u, int v){
    adjList[u].push_back(v);
}

void Graph::fillInOrder(int v, stack<int> &st, vector<bool> &visited){
    visited[v] = true;

    for(auto &i:adjList[v]){
        if(!visited[i])
            fillInOrder(i, st, visited);
    }

    // push when all the adjacent nodes are visited
    st.push(v);
}

Graph Graph::transpose(){
    Graph gr(V);

    for(int i = 0; i < V; i++)
        for(auto &j:adjList[i])
            gr.adjList[j].push_back(i);

    return gr;
}

void Graph::dfsUtil(int u, vector<bool> &visited){
    cout << u << " ";
    visited[u] = true;

    for(auto &i:adjList[u])
        if(!visited[i])
            dfsUtil(i, visited);
}

void Graph::printSCCs(){
    vector<bool> visited(V, false);
    stack<int> st;

    // fill in order of nodes finishing time
    for(int i = 0; i < V; i++){
        if(!visited[i]){
            fillInOrder(i, st, visited);
        }
    }

    // creating transpose of the graph
    Graph gr = transpose();

    visited = vector<bool>(V, false);
    while(!st.empty()){
        int t = st.top();
        st.pop();

        // print SCCs, on the transposed graph
        if(!visited[t]){
            gr.dfsUtil(t, visited);
            cout << "\n";
        }
    }
}

// Driver function
int main(){
    // Create a graph given in the above diagram
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    cout << "SCC's of Graph 1 : \n";
    g.printSCCs();

    Graph g8(8);
    g8.addEdge(3, 7);
    g8.addEdge(3, 4);
    g8.addEdge(7, 3);
    g8.addEdge(7, 5);
    g8.addEdge(4, 5);
    g8.addEdge(5, 6);
    g8.addEdge(5, 0);
    g8.addEdge(6, 2);
    g8.addEdge(6, 4);
    g8.addEdge(6, 0);
    g8.addEdge(2, 0);
    g8.addEdge(0, 1);
    g8.addEdge(1, 2);

    cout << "\nSCC's of Graph 2 : \n";
    g8.printSCCs();


    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);

    cout << "\nSCC's of Graph 3 : \n";
    g1.printSCCs();

    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);

    cout << "\nSCC's of Graph 4 : \n";
    g2.printSCCs();

    Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);

    cout << "\nSCC's of Graph 5 : \n";
    g3.printSCCs();

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

    cout << "\nSCC's of Graph 6 : \n";
    g4.printSCCs();

    Graph g5(5);
    g5.addEdge(0,1);
    g5.addEdge(1,2);
    g5.addEdge(2,3);
    g5.addEdge(2,4);
    g5.addEdge(3,0);
    g5.addEdge(4,2);

    cout << "\nSCC's of Graph 7 : \n";
    g5.printSCCs();


    return 0;
}
