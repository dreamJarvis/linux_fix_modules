/*
    Topological sort
    https://www.geeksforgeeks.org/topological-sorting/

    tc : O(V + E)
    sc : O(V), stack
*/
#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    list<int> *adj;
public:
    Graph(int V) : V(V), adj(new list<int>[V]) {}
    void addEdge(int v, int w);
    void dfsUtil(int v, bool visited[], stack<int> &ts);
    stack<int> topologicalSorting();
};

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::dfsUtil(int v, bool visited[], stack<int> &ts){
    visited[v] = true;

    for(auto i:adj[v])
        if(!visited[i])
            dfsUtil(i, visited, ts);

    // pushing the elements at end into stack
    ts.push(v);
}

stack<int> Graph::topologicalSorting(){
    bool visited[V] = {false};
    stack<int> ts;

    for(int i = 0; i < V; i++){
        if(!visited[i]){
            dfsUtil(i, visited, ts);
        }
    }

    return ts;
}

// Driver function
int main(){
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(3, 1);
    g.addEdge(2, 3);

    stack<int> s = g.topologicalSorting();
    while(!s.empty()){
        cout << s.top() << " ";
        ts.push_back(s.top());
        s.pop();
    }
    cout << endl;

    
    // Graph g(13);
	// char ch = 'A';
	// g.addEdge('A'-ch, 'D'-ch);
	// g.addEdge('B'-ch, 'D'-ch);
	// g.addEdge('C'-ch, 'A'-ch);
	// g.addEdge('C'-ch, 'B'-ch);
	// g.addEdge('D'-ch, 'H'-ch);
	// g.addEdge('D'-ch, 'G'-ch);
	// g.addEdge('E'-ch, 'A'-ch);
	// g.addEdge('E'-ch, 'D'-ch);
	// g.addEdge('E'-ch, 'F'-ch);
	// g.addEdge('F'-ch, 'K'-ch);
	// g.addEdge('F'-ch, 'J'-ch);
	// g.addEdge('G'-ch, 'I'-ch);
	// g.addEdge('H'-ch, 'J'-ch);
	// g.addEdge('H'-ch, 'I'-ch);
	// g.addEdge('I'-ch, 'L'-ch);
	// g.addEdge('J'-ch, 'L'-ch);
	// g.addEdge('J'-ch, 'M'-ch);
	// g.addEdge('K'-ch, 'J'-ch);

    // cout << "topological sorting : ";
    // stack<int> s = g.topologicalSorting();
    // while(!s.empty()){
    //     cout << (char)(ch+s.top()) << " ";
    //     s.pop();
    // }
    // cout << endl;

    return 0;
}
