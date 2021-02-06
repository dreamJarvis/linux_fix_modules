/*
    Bellman Ford Algorithm (Simple Implementation)
    https://www.geeksforgeeks.org/bellman-ford-algorithm-simple-implementation/
*/
// #include <bits/stdc++.h>
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

#define INF INT_MAX
#define NINF INT_MIN

// wrong
void shortestpath(int src, vector<vector<int>> &matrix){
    int N = matrix.size();
    vector<int> dist(N, INF);
    vector<int> prev(N, 0);

    dist[src] = 0;
    for(int k = 0; k < N-1; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(dist[i] != INF && matrix[i][j] && dist[j] > (dist[i] + matrix[i][j])%INF ){
                    dist[j] = dist[i] + matrix[i][j];
                    prev[j] = i;
                }
            }
        }
    }

    // to check if -ve cycles exist or not
    for(int k = 0; k < N-1; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                // if dist[i] == NINF && matrix[i][j] < 0 , then dist[i] + matrix[i][j] gives unspecific behaviour
                if(dist[i] == NINF && matrix[i][j] < 0){
                    dist[j] = NINF;
                    prev[j] = -1;
                }
                else if(matrix[i][j] && dist[j] > (dist[i] + matrix[i][j])){
                    dist[j] = NINF;
                    prev[j] = -1;
                }
            }
        }
    }

    for(int i = 0; i < N; i++)
        if(i != src)
            cout << src << " - " << i << "\t" << dist[i] << endl;
    return ;
}

// Driver function
int main(){
    int V = 8;
    vector<vector<int>> matrix(V, vector<int>(V, 0));
    matrix[0][1] = 1;
    matrix[1][2] = 1;
    matrix[2][4] = 1;
    matrix[4][3] = -3;
    matrix[3][2] = 1;
    matrix[1][5] = 4;
    matrix[1][6] = 4;
    matrix[5][6] = 5;
    matrix[6][7] = 4;
    matrix[5][7] = 3;

    shortestpath(0, matrix);

    return 0;
}
