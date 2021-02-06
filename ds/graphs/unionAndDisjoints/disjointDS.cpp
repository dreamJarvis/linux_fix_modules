/*
    Disjoint Set Data Structures
    https://www.geeksforgeeks.org/disjoint-set-data-structures/
    time complexity : O(E)
*/
#include <iostream>
using namespace std;

class DisjointSet{
    int *rank, *parent, n;
public:
    DisjointSet(int n){
        rank = new int[n];
        parent = new int[n];
        this->n = n;
        makeSet();
    }

    // create single item set's
    void makeSet(){
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    // find set of given item x
    // applying path compression
    int find(int x){
        /*finds the representative of the set
        to which x belongs to*/
        if(parent[x] != x){

            /*if x is not the parent of itself
            then x is not the representative of this set
            so we recusively call find() on its parent
            unitl we find the x == parent[x]*/
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // Do union of 2 sets represented by x and y
    void Union(int x, int y){
        // find current set's x and y
        int xSet = find(x);
        int ySet = find(y);

        // if they are in the same set
        if(xSet == ySet)    return;

        /*put smaller ranked item under bigger ranked item*/
        if(rank[xSet] < rank[ySet]){
            parent[xSet] = ySet;
            rank[ySet] += rank[xSet];
        }
        else if(rank[xSet] >= rank[ySet]){
            parent[ySet] = xSet;
            rank[xSet] += rank[ySet];
        }
    }
};

// Driver function
int main(){
    DisjointSet dis(5);
    dis.Union(0, 2);
    dis.Union(4, 2);
    dis.Union(3, 1);

    if(dis.find(4) == dis.find(0))  cout << "Yes\n";
    else                            cout << "No\n";

    if(dis.find(1) == dis.find(0))  cout << "Yes\n";
    else                            cout << "No\n";

    return 0;
}
