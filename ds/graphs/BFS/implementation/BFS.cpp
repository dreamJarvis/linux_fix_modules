#include <bits/stdc++.h>
using namespace std;

// For connected and disconnected graphs
class Graph {
    int V;
    list<int> *adj;
public:
    Graph(int V) : V(V), adj(new list<int>[V]) {}   // constructor
    void addEdge(int v, int w);
    void display();
    void BFS();
};

void Graph::display(){
    for(int i = 1; i < V; i++){
        cout << i << " --> ";
        for(auto j:adj[i])
            cout << j << " ";
        cout << endl;
    }
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

// tc : O(v + E)
void Graph::BFS(){
    bool visited[V] = {false};
    queue<int> q;

    for(int i = 1; i < V; i++){
        if(!visited[i]){
            q.push(i);
            while(!q.empty()){
                int temp = q.front();

                if(!visited[temp]){
                    visited[temp] = true;
                    cout << temp << " ";
                }

                q.pop();

                for(auto j:adj[temp]){
                    if(!visited[j]){
                        q.push(j);
                    }
                }
            }
            cout << "\n";
        }
    }
}

// Driver function
int main(){
    Graph g(10);
    g.addEdge(1, 5);
    g.addEdge(1, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 1);
    g.addEdge(5, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 2);
    g.addEdge(3, 1);
    g.addEdge(4, 3);
    g.addEdge(3, 4);
    g.addEdge(5, 4);
    g.addEdge(4, 5);
    g.addEdge(6, 7);
    g.addEdge(7, 6);
    g.addEdge(7, 9);
    g.addEdge(7, 8);
    g.addEdge(9, 7);
    g.addEdge(9, 8);
    g.addEdge(8, 9);
    g.addEdge(8, 7);

    g.BFS();

    return 0;
}
