#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    unordered_map<int, vector<int>> list;
public:
    Graph(int V) : V(V){}
    void addEdge(int u, int v);
    void bfs();
};

void Graph::addEdge(int u, int v){
    list[u].push_back(v);
}

// t : O(V+E)
void Graph::bfs(){
    vector<bool> visited(V, false);
    queue<int> q;

    for(int i = 0; i < V; i++){
        if(!visited[i]){
            q.push(i);

            while(!q.empty()){
                int temp = q.front();

                if(!visited[temp]){
                    visited[temp] = true;
                    cout << temp << " ";
                }

                q.pop();

                for(auto &j:list[temp])
                    if(!visited[j])
                        q.push(j);
            }

            cout << "\n";
        }
    }
}

int main(){
    Graph g(4);
    g.addEdge(0, 2);
    g.addEdge(2, 0);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.bfs();

    return 0;
}
