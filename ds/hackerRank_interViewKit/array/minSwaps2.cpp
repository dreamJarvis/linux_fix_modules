// hackerRank : Minimum Swaps 2
#include <bits/stdc++.h>
using namespace std;

int minimumSwaps(vector<int> arr) {
    int n = arr.size();
    unordered_map<int, bool> visited;            // to detect cycle

    vector<int> temp(n+1, 0);
    for(int i=0; i < n; i++){
        temp[i+1] = arr[i];
    }

    int minSwaps = 0;
        for(int i = 1; i <= n; i++){
            int count = 0;
            if(temp[i] != i && !visited[i]){
                visited[i] = true;
                int j = i;
                while(j <= n && !visited[temp[j]]){
                    visited[temp[j]] = true;
                    count++;
                    j = temp[j];
                }

                minSwaps += count;
            }
        }
    return minSwaps;
}

// Driver function
int main(){
    // vector<int> arr({0, 2, 3, 4, 1, 6, 5});
    // vector<int> arr({0, 2, 3, 4, 5, 6, 1});
    // vector<int> arr({1, 3, 5, 2, 4, 6, 7});
    vector<int> arr({4, 3, 1, 2});


    cout << minimumSwaps(arr) << endl;

    return 0;
}
